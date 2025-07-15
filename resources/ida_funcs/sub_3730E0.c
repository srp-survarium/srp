int __cdecl sub_3730E0(int a1, char *string)
{
  _DWORD *v2; // eax
  int v3; // ecx
  const char *v4; // esi
  int v5; // esi
  int v6; // edx
  char v7; // cl
  char *v8; // edx

  v2 = *(_DWORD **)a1;
  v3 = *(_DWORD *)(*(_DWORD *)a1 + 20);
  if ( v3 <= 0 || v3 > v2[29] )
  {
    v5 = v2[30];
    if ( !v5 )
      goto LABEL_9;
    v6 = v2[31];
    if ( v3 < v6 || v3 > v2[32] )
      goto LABEL_9;
    v4 = *(const char **)(v5 + 4 * (v3 - v6));
  }
  else
  {
    v4 = *(const char **)(v2[28] + 4 * v3);
  }
  if ( !v4 )
  {
LABEL_9:
    v2[6] = v3;
    v4 = *(const char **)v2[28];
  }
  v7 = *v4;
  v8 = (char *)v4;
  if ( !*v4 )
    return sprintf(string, v4, v2[6], v2[7], v2[8], v2[9], v2[10], v2[11], v2[12], v2[13]);
  while ( 1 )
  {
    ++v8;
    if ( v7 == 37 )
      break;
    v7 = *v8;
    if ( !*v8 )
      return sprintf(string, v4, v2[6], v2[7], v2[8], v2[9], v2[10], v2[11], v2[12], v2[13]);
  }
  if ( *v8 == 115 )
    return sprintf(string, v4, v2 + 6);
  else
    return sprintf(string, v4, v2[6], v2[7], v2[8], v2[9], v2[10], v2[11], v2[12], v2[13]);
}
