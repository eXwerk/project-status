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
		static const char *phase[] = {"Unbekannt",
				"Ideenphase",
				"Planungsphase",
				"Antragsphase",
				"Bestellphase",
				"Enwticklungs-/Bauphase 00%-25%",
				"Enwticklungs-/Bauphase 26%-50%",
				"Enwticklungs-/Bauphase 51%-75%",
				"Enwticklungs-/Bauphase 76%-99%",
				"Fertig :-)"};
		
		fp = fopen("projects.list", "r");
		if (fp == NULL)
				exit(EXIT_FAILURE);
		
		printf ("<!DOCTYPE HTML>\n");
		printf ("<html>\n");
		printf ("\t<head>\n");
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
				printf ("\t\t\t\t<div class=\"project-progress-name\">%s</div>\n", phase[ atoi (token) ]);				
				token = strtok (NULL, ";");
				printf ("\t\t\t\t<div class=\"project-contact\">%s</div>\n", token);
				printf ("\t\t\t</div>\n");
		}
		
		free(line);

		printf ("\t\t</section>\n");
		printf ("\t</body>\n");
		printf ("</html>\n");

		exit(EXIT_SUCCESS);
}
