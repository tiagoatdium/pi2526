#include <stdio.h>

// devolve 1 se o caractere for uma letra, 0 caso contrário
int is_letter(char c)
{
  return (c >= 'a' && c <= 'z') ||
         (c >= 'A' && c <= 'Z');
}

// calcula o comprimento da string
size_t string_length(char s[])
{
  size_t i = 0;

  while(s[i] != '\0')
  { i++; }

  return i;
}


// compara duas strings em n posições
// - devolve 1 se forem iguais, 0 caso contrário
int compare_strings(char s1[], char s2[], size_t n)
{
  size_t i;

  for(i=0; i<n; i++)
  { if(s1[i] != s2[i])
    { return 0; }
  }
  return 1;
}


// inverte uma (parte da) string, começando em start,
// com tamanho len
void reverse_string(char s[], size_t start, size_t len)
{
  size_t left = start;
  size_t right = start + len - 1;
  char temp;

  while(left < right)
  {
    temp = s[left];
    s[left] = s[right];
    s[right] = temp;

    left++;
    right--;
  }
}


// verifica se a palavra encontrada está isolada
//   isto é, se antes e depois não há letras
int is_whole_word(char sentence[], size_t start, size_t word_len, size_t sentence_len)
{
  int before_ok;
  int after_ok;

  // verifica se antes é OK
  if (start == 0) // se estamos no início é OK
  {  before_ok = 1; }
  else // senão, verificar se o char anterior (start-1) é letra e negar
  { before_ok = !is_letter(sentence[start - 1]); }

  // verifica se depois é OK
  if (start + word_len >= sentence_len) // se estamos no fim (ou para lá do fim, é OK)
  { after_ok = 1; }
  else // senão, verificar se é letra e negar
  { after_ok = !is_letter(sentence[start + word_len]); }

  // para ser uma palavra, ambos (antes e depois) tem de ser OK
  return before_ok && after_ok;
}


// procura todas as ocorrências da palavra como palavra completa
// e inverte essas ocorrências

// @pre: sentence_len >= word_len
void process_string(char sentence[], char word[], size_t sentence_len, size_t word_len)
{
  size_t i;

  for(i = 0; i <= sentence_len - word_len; i++)
  {
    // pergunta: é preciso colocar o == 1? ou é desncessário? porquê?
    if (compare_strings(&sentence[i], word, word_len) == 1 &&
        is_whole_word(sentence, i, word_len, sentence_len) == 1
       )
    {
      reverse_string(sentence, i, word_len);
      i += word_len - 1;
    }
  }
}

#define MAX 256

int main()
{
  char sentence[MAX];
  char word[MAX];

  printf("Digite uma frase: ");
  fgets(sentence, MAX, stdin);

  printf("Digite uma palavra: ");
  fgets(word, MAX, stdin);

  int sentence_len = string_length(sentence);
  if (sentence_len > 0 && sentence[sentence_len - 1] == '\n')
  {
    sentence[sentence_len - 1] = '\0';
    sentence_len--;
  }

  int word_len = string_length(word);
  if (word_len > 0 && word[word_len - 1] == '\n')
  {
    word[word_len - 1] = '\0';
    word_len--;
  }

  process_string(sentence, word, sentence_len, word_len);

  printf("\nResultado: %s\n", sentence);

  return 0;
}
