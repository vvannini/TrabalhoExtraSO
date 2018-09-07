// Trabalho Extra de Sistemas Operacionais
// Veronica Vannini
// 8517369


#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include <string.h>

int main()
{
    //variaveis de tempo
    clock_t t;
    double time_mkdir, time_rmdir, time_rename;
    
    //arquivo de resultado 
    FILE *res;
    
    //variaveis auxiliares
    int i = 0, r_mkdir;
    char path[5] = { }, number[5] = { }, new_path[5] = { };
	
    res = fopen("Result.txt", "w+");
    fprintf(res, "****************************************************\n");
    fprintf(res, "*    MKDIR    *       RMDIR      *      RENAME     *\n");
    fprintf(res, "****************************************************\n");

    //Respetição dos 10 testes
    for(i = 0; i<10; i++)
    {
        //Configurando o nome do diretorio a ser manipulado
        strcpy(path, "./");
        printf("\n%s", path);
        sprintf(number, "%d", i);
        puts(number);
        strcat(path, number);
        strcpy(new_path, path);
        strcat(new_path, number); 
        
        
        // Criando o Diretorio
        t = clock();
        mkdir(path, 0700);
        t = clock() - t;
        time_mkdir = ((double)t)/CLOCKS_PER_SEC;
        
        // Renomeando o Diretorio
        t = clock();
        rename(path, new_path);
        t = clock() - t;
        time_rename = ((double)t)/CLOCKS_PER_SEC;
        
        
        // Excluindo o Diretorio
        t = clock();
        rmdir(new_path);
        t = clock() - t;
        time_rmdir = ((double)t)/CLOCKS_PER_SEC;
        
        
        fprintf(res, "* %f     *   %f      *   %f      *\n", time_mkdir, time_rmdir, time_rename);

    }
    
    fprintf(res, "****************************************************\n");
	
	fclose(res);
	return 0;
}
