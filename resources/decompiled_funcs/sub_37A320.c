char *__cdecl sub_37A320(int a1, int a2, int a3, char *a4)
{
  char *result; // eax
  int v5; // ebp
  char **v6; // edi
  int v7; // edx
  char *v8; // esi
  unsigned int v9; // ecx
  char v10; // dl
  _BYTE *v11; // eax
  int v12; // [esp+1Ch] [ebp+10h]

  result = a4;
  v5 = 0;
  v6 = *(char ***)a4;
  if ( *(int *)(a1 + 276) > 0 )
  {
    v7 = a3 - (_DWORD)v6;
    v12 = a3 - (_DWORD)v6;
    do
    {
      result = *v6;
      v8 = *(char **)((char *)v6 + v7);
      v9 = (unsigned int)&(*v6)[*(_DWORD *)(a1 + 92)];
      if ( (unsigned int)*v6 < v9 )
      {
        do
        {
          v10 = *v8;
          *result = *v8;
          v11 = result + 1;
          *v11 = v10;
          result = v11 + 1;
          ++v8;
        }
        while ( (unsigned int)result < v9 );
        v7 = v12;
      }
      ++v5;
      ++v6;
    }
    while ( v5 < *(_DWORD *)(a1 + 276) );
  }
  return result;
}
