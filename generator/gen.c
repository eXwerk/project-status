#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main(void)
{
		FILE *fp;
		char *line = NULL;
		char *token;
		size_t len = 0;
		ssize_t read;
		
		fp = fopen("projects.list", "r");
		if (fp == NULL)
				exit(EXIT_FAILURE);
		
		printf ("<!DOCTYPE HTML>\n");
		printf ("\t<html>\n");
		printf ("\t\t<meta charset=\"utf-8\" />\n");
		printf ("\t\t<title>eXwerk Projektstati</title>\n");
		printf ("\t\t<link rel=\"stylesheet\" href=\"css/screen.css\" type=\"text/css\" />\n");
		printf ("\t</head>\n");
		printf ("\t<body>\n");
		printf ("\t\t<section id=\"projects\">\n");
		printf ("\t\t\t<div id=\"header\">\n");
		printf ("\t\t\t\t<div class=\"header-element\">Projekt</div>\n");
		printf ("\t\t\t\t<div class=\"header-element\">Fortschritt</div>\n");
		printf ("\t\t\t\t<div class=\"header-element\">Phase</div>\n");
		printf ("\t\t\t\t<div class=\"header-element\">Kontakt</div>\n");
		printf ("\t\t\t</div>\n");

		while ((read = getline(&line, &len, fp)) != -1)
		{
				printf ("\t\t\t<div class=\"project\">\n");
				token = strtok (line, ";");
				printf ("\t\t\t\t<div class=\"project-name\">%s</div>\n", token);
				token = strtok (NULL, ";");
				printf ("\t\t\t\t<progress value=\"%s\" max=\"9\"></progress>\n", token);
				printf ("\t\t\t\t<div class=\"project-progress-name\"></div>\n");				
				token = strtok (NULL, ";");
				printf ("\t\t\t\t<div class=\"project-contact\">%s</div>\n", token);
				printf ("\t\t\t</div>\n");
		}
		
		free(line);

		printf ("\t\t%s", "</section>\n");
		printf ("\t%s", "</body>\n");
		printf ("%s", "</html>\n");

		exit(EXIT_SUCCESS);
}
