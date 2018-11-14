#include<stdio.h>



int search(char* heuhaufen, char* nadel, int len1, int len2)
{
  for(int i=0;i<=len1-len2+1;i++)
    {
    int zeichen=0;
    for(int j=0;j<=len2-1;j++)
      {
      if(heuhaufen[i+j]==nadel[j]) zeichen++;
      if(zeichen==len2) return i;
      if(heuhaufen[i+j]!=nadel[j])zeichen=0;
      }
    }
  return -1;
}
int main()
{
  char* str1="informatiger";
  char* str2="tiger";
  printf("Ausgabe: %d", search(str1,str2,12,5));
  return 0;
}