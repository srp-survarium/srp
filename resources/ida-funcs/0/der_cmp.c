int __cdecl der_cmp(unsigned __int8 **a, unsigned __int8 **b)
{
  unsigned __int8 *v2; // ebx
  unsigned __int8 *v3; // edi
  unsigned __int8 *v4; // esi
  unsigned __int8 *v5; // ecx
  unsigned __int8 *v6; // edx
  int v7; // eax
  int result; // eax

  v2 = b[1];
  v3 = a[1];
  v4 = v3;
  if ( (int)v3 >= (int)v2 )
    v4 = b[1];
  v5 = *b;
  v6 = *a;
  if ( (unsigned int)v4 < 4 )
  {
LABEL_6:
    if ( !v4 )
      goto LABEL_15;
  }
  else
  {
    while ( *(_DWORD *)v6 == *(_DWORD *)v5 )
    {
      v4 -= 4;
      v5 += 4;
      v6 += 4;
      if ( (unsigned int)v4 < 4 )
        goto LABEL_6;
    }
  }
  v7 = *v6 - *v5;
  if ( v7 )
    goto LABEL_14;
  if ( (unsigned int)v4 <= 1 )
    goto LABEL_15;
  v7 = v6[1] - v5[1];
  if ( v7 )
    goto LABEL_14;
  if ( (unsigned int)v4 <= 2 )
    goto LABEL_15;
  v7 = v6[2] - v5[2];
  if ( v7 )
  {
LABEL_14:
    result = (v7 >> 31) | 1;
    goto LABEL_16;
  }
  if ( (unsigned int)v4 > 3 )
  {
    v7 = v6[3] - v5[3];
    goto LABEL_14;
  }
LABEL_15:
  result = 0;
LABEL_16:
  if ( !result )
    return v3 - v2;
  return result;
}
