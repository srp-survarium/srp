int __usercall asn1_get_length@<eax>(const unsigned __int8 **pp@<ebx>, int *inf@<ecx>, int max@<edx>, unsigned int *rl)
{
  int v4; // eax
  unsigned int v5; // esi
  int v6; // edi
  char v8; // dl
  unsigned int v9; // ecx
  const unsigned __int8 *v10; // eax
  int v11; // edx
  int v12; // edi
  int v13; // edx

  v4 = (int)*pp;
  v5 = 0;
  v6 = max - 1;
  if ( max < 1 )
    return 0;
  if ( *(_BYTE *)v4 == 0x80 )
  {
    *inf = 1;
    *pp = (const unsigned __int8 *)(v4 + 1);
    *rl = 0;
    return 1;
  }
  else
  {
    *inf = 0;
    v8 = *(_BYTE *)v4 & 0x80;
    v9 = *(_BYTE *)v4 & 0x7F;
    v10 = (const unsigned __int8 *)(v4 + 1);
    if ( v8 )
    {
      if ( v9 > 4 )
        return 0;
      v11 = v6;
      v12 = v6 - 1;
      if ( !v11 )
        return 0;
      if ( v9 )
      {
        while ( 1 )
        {
          v5 = *v10 | (v5 << 8);
          v13 = v12;
          --v9;
          ++v10;
          --v12;
          if ( !v13 )
            return 0;
          if ( !v9 )
            goto LABEL_13;
        }
      }
    }
    else
    {
      v5 = v9;
LABEL_13:
      if ( v5 > 0x7FFFFFFF )
        return 0;
    }
    *pp = v10;
    *rl = v5;
    return 1;
  }
}
