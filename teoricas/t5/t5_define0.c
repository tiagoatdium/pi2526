// Instruções de utilização:
// - correr o commando: gcc -E t5_define0.c
// e verificar o output, concretamente:
// - relacionar o conteúdo deste ficheiro
//   com o visualizado no terminal 

// Nota: pode consultar o manual de gcc através do comando:
// - man gcc
// 
// pode encontrar a seguinte explicação para a opção -E:
// - "-E  Stop after the preprocessing stage; do not run
//    the compiler proper.  The output is in the form of
//    preprocessed source code, which is sent to the
//    standard output."


// De seguida, encontra algumas definições de macros.
// O "preprocessador" realiza uma substituição simples. Por exemplo:
//   N  -> 3
//   M  -> (N*N)  -> (3*3)
//   P  -> (M+1)  -> ((3*3)+1)
// 
// As expressões não são simplificadas: o pré-processamento não realiza
// nenhuma operação aritmética. É boa prática incluir parênteses sempre
// que a macro contenha, por exemplo, expressões aritméticas.
 
#define N 3
#define M (N*N)
#define P (M+1)

int ultimo(int a[N])
{
	return a[N-1];
}

int main(void)
{
	int a = P;
	return a;
}
