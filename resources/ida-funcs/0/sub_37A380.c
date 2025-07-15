void __cdecl sub_37A380(int a1, int a2, char **a3, int *a4)
{
  int v4; // ebx
  int i; // esi
  char *v6; // eax
  char *v7; // edi
  char *j; // ecx
  char v9; // dl
  _BYTE *v10; // eax

  v4 = *a4;
  for ( i = 0; i < *(_DWORD *)(a1 + 276); i += 2 )
  {
    v6 = *(char **)(v4 + 4 * i);
    v7 = *a3;
    for ( j = &v6[*(_DWORD *)(a1 + 92)]; v6 < j; ++v7 )
    {
      v9 = *v7;
      *v6 = *v7;
      v10 = v6 + 1;
      *v10 = v9;
      v6 = v10 + 1;
    }
    jcopy_sample_rows(v4, i, v4, i + 1, 1, *(_DWORD *)(a1 + 92));
    ++a3;
  }
}
