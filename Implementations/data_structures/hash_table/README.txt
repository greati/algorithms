Natal, novembro/2015

# Identificação #
	
	* Instituição: Universidade Federal do Rio Grande do Norte (UFRN)
	* Disciplinais: Linguagem de Programação 1 e Estruturas de Dados Básicas 1

	* Aluno:       Vinícius Campos Tinoco Ribeiro
	* Matrícula:   2014025284

	* Aluno:       Vitor Rodrigues Greati
	* Matrícula:   2015034967

# Introdução #
Este projeto tem o objetivo de implementar uma Hash Table genérica,
apresentando também uma aplicação simulando contas bancárias.

# Estrutura #

O projeto está sub-dividido em 4 pastas:
	
	* bin: Possui os executáveis do projeto
	* documentation: Possui toda a documentação do projeto com doxygen
	* include: Possui os arquivos de cabeçalho da classes.
	* src: Possui o arquivo de implementação dos métodos das classes do projeto e do driver utilizado. 

# Guia de utilização(MODO TEXTO) - Linux #
	
	1 - Descompactar o projeto na pasta de preferência
	1 - Abra o terminal
	2 - Desloque-se até pasta do projeto, HashTable.
	3 - Digite os seguintes comandos de compilação: 
		g++ -std=c++11 -I include src/drive.cpp -o bin/<nome do executável>
		O driver disponível é:
			- drive.cpp : simulações de contas bancárias
	4 - Para executar, basta ./bin/<nome do executável>

# Resultado no valgrind(MODO TEXTO) #

O projeto passou no valgrind sem vazamento de memória, segundo o log:

==4249==
==4249== HEAP SUMMARY:
==4249== in use at exit: 0 bytes in 0 blocks
==4249== total heap usage: 26 allocs, 26 frees, 1,705 bytes allocated
==4249==
==4249== All heap blocks were freed -- no leaks are possible
==4249==
==4249== For counts of detected and suppressed errors, rerun with: -v
==4249== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
