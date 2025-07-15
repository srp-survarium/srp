int __usercall sub_47FDA0@<eax>(int a1@<edi>, int a2, char *a3)
{
  _DWORD *v3; // eax
  int v4; // ecx
  char *v5; // esi
  int v6; // esi
  int v7; // edx
  char v8; // cl
  char *v9; // edx

  v3 = *(_DWORD **)a2;
  v4 = *(_DWORD *)(*(_DWORD *)a2 + 20);
  if ( v4 <= 0 || v4 > v3[29] )
  {
    v6 = v3[30];
    if ( !v6 )
      goto LABEL_9;
    v7 = v3[31];
    if ( v4 < v7 || v4 > v3[32] )
      goto LABEL_9;
    v5 = *(char **)(v6 + 4 * (v4 - v7));
  }
  else
  {
    v5 = *(char **)(v3[28] + 4 * v4);
  }
  if ( !v5 )
  {
LABEL_9:
    v3[6] = v4;
    v5 = *(char **)v3[28];
  }
  v8 = *v5;
  v9 = v5;
  if ( !*v5 )
    return sprintf(a1, (int)v5, a3, v5, v3[6], v3[7], v3[8], v3[9], v3[10], v3[11], v3[12], v3[13]);
  while ( 1 )
  {
    ++v9;
    if ( v8 == 37 )
      break;
    v8 = *v9;
    if ( !*v9 )
      return sprintf(a1, (int)v5, a3, v5, v3[6], v3[7], v3[8], v3[9], v3[10], v3[11], v3[12], v3[13]);
  }
  if ( *v9 == 115 )
    return sprintf(a1, (int)v5, a3, v5, v3 + 6);
  else
    return sprintf(a1, (int)v5, a3, v5, v3[6], v3[7], v3[8], v3[9], v3[10], v3[11], v3[12], v3[13]);
}
