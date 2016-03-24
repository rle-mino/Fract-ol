/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 03:40:56 by rle-mino          #+#    #+#             */
/*   Updated: 2016/03/24 03:44:53 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OpenCL/opencl.h"

#include <stdlib.h>
#include <stdio.h>
#include "OpenCL/opencl.h"

#define QTE_DONNEES 20

int main (int argc, const char * argv[])
{
	// Variables pour la Plateforme de travail
	cl_platform_id plateformeID;
	cl_uint qtePlateformes;
	cl_int codeErreur;
	// Variables pour les périphériques contenant des unités de calcul
	cl_device_id TOUS_peripheriqueID;
	cl_uint TOUS_qtePeripheriques;
	// Variables pour les contextes de travail
	cl_context contexte;
	cl_context_properties proprietes[3];
	// Variable pour les files d'exécution des commandes
	cl_command_queue file_execution;
	// Variable pour la fonction à paralléliser
	cl_program programme;
	const char *maFonctionTripleBoucle = {
		"__kernel void tripleBoucle(__global int *output)\n"
			"{\n"
			" int i = get_global_id(0);\n"
			" int j = get_global_id(1);\n"
			" int k = get_global_id(2);\n"
			" output += i * j * k;"
			"}\n"
	};
	// Variable pour le noyau qui exécutera
	// le programme contenant la fonction parallèle.
	cl_kernel noyau;
	// Variables qui contiendront les données.
	int* outputData;
	cl_mem output_buffer;
	// Initialisation des variables de données
	outputData = (int*)malloc(sizeof(int));
	*outputData = 0;
	// --------------------------------------------------------------------
	// ----------------- Fin de la section des variables ------------------
	// -------------------------------------------------------------------- 
	// Création de la plateforme de travail
	codeErreur = clGetPlatformIDs(1, &plateformeID, &qtePlateformes);
	// Rechercher les PÉRIPHÉRIQUES dans le système, tout type confondu.
	codeErreur = clGetDeviceIDs(plateformeID,
			CL_DEVICE_TYPE_GPU,
			1,
			&TOUS_peripheriqueID,
			&TOUS_qtePeripheriques);
	// Création du contexte de travail
	proprietes[0] = (cl_context_properties) CL_CONTEXT_PLATFORM;
	proprietes[1] = (cl_context_properties) plateformeID;
	proprietes[2] = 0;
	contexte = clCreateContext(proprietes,
			TOUS_qtePeripheriques,
			&TOUS_peripheriqueID,
			NULL,
			NULL,
			&codeErreur);
	// Création de la file d'exécution pour le CPU
	file_execution = clCreateCommandQueue(contexte,
			TOUS_peripheriqueID,
			0,
			&codeErreur);
	// Construire le programme avec la fonction auCarre pour le CPU
	programme = clCreateProgramWithSource(contexte,
			1,
			(const char**)&maFonctionTripleBoucle,
			NULL,
			&codeErreur);
	// Compilation du programme
	codeErreur = clBuildProgram(programme,
			TOUS_qtePeripheriques,
			&TOUS_peripheriqueID,
			NULL,
			NULL,
			NULL);
	if (codeErreur != CL_SUCCESS) {
		// Si erreur de compilation, alors... Affichage du LOG de compilation
		char logErreurs[4096];
		size_t longueur_Log;
		clGetProgramBuildInfo(programme,
				TOUS_peripheriqueID,
				CL_PROGRAM_BUILD_LOG,
				sizeof(logErreurs),
				logErreurs,
				&longueur_Log);
		printf("\n[IMPRESSION DU JOURNAL DE COMPILATION]\n\n");
		printf("%s\n\n", logErreurs);
		printf("[FIN DU JOURNAL]\n\n"); 
		return 1;
	}
	// Association des variables de données avec le tampon d'échange
	output_buffer = clCreateBuffer(contexte,
			CL_MEM_WRITE_ONLY | CL_MEM_COPY_HOST_PTR,
			sizeof(int) * QTE_DONNEES,
			outputData,
			&codeErreur);
	// Construire le noyau
	noyau = clCreateKernel(programme, "tripleBoucle", &codeErreur);
	// Associer les tampons d'échanges avec
	// les arguments des fonctions à paralléliser
	codeErreur = clSetKernelArg(noyau,
			1,
			sizeof(output_buffer),
			&output_buffer);
	// Mettre le noyau dans la file d'execution
	size_t dimensions_globales[] = { QTE_DONNEES, 0, 0 };
	codeErreur = clEnqueueNDRangeKernel(file_execution,
			noyau,
			1,
			NULL,
			dimensions_globales,
			NULL,
			0,
			NULL,
			NULL);
	// Récupération des résultats dans le tampon
	clEnqueueReadBuffer(file_execution,
			output_buffer,
			CL_TRUE,
			0,
			sizeof(int) * QTE_DONNEES,
			outputData,
			0,
			NULL,
			NULL);
	// Affichage des résultats
	printf("\n\n\n >>>>> Affichage des resultats <<<<<");
	printf("\n\nContenu de la variable --outputData--\n");
	printf("Fonction --tripleBouble--\n");
	for (int i = 0; i < QTE_DONNEES; i++) {
		printf("%d; ", *outputData);
	} 
	// Libération des ressources
	free(outputData);
	clReleaseMemObject(output_buffer);
	clReleaseProgram(programme);
	clReleaseKernel(noyau);
	clReleaseCommandQueue(file_execution);
	clReleaseContext(contexte);
	return 0;
} 
