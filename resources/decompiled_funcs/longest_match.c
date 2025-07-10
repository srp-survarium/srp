unsigned int __usercall longest_match@<eax>(internal_state *s@<edi>, unsigned int cur_match@<eax>)
{
  unsigned int dummy; // edx
  unsigned int v3; // ebp
  int v4; // esi
  _BYTE *v5; // ecx
  _BYTE *v6; // esi
  _BYTE *v7; // edx
  char v8; // bl
  _BYTE *v9; // edx
  _BYTE *v10; // ecx
  _BYTE *v11; // edx
  char v12; // bl
  _BYTE *v13; // edx
  char v14; // bl
  _BYTE *v15; // edx
  char v16; // bl
  _BYTE *v17; // edx
  char v18; // bl
  _BYTE *v19; // edx
  char v20; // bl
  _BYTE *v21; // edx
  char v22; // bl
  _BYTE *v23; // edx
  char v24; // bl
  _BYTE *v25; // edx
  char v26; // bl
  int v27; // edx
  unsigned int result; // eax
  unsigned __int8 scan_end1; // [esp+Eh] [ebp-12h]
  unsigned __int8 scan_end; // [esp+Fh] [ebp-11h]
  unsigned int chain_length; // [esp+10h] [ebp-10h]
  int nice_match; // [esp+14h] [ebp-Ch]
  unsigned int limit; // [esp+18h] [ebp-8h]

  dummy = s[27].dummy;
  v3 = s[30].dummy;
  chain_length = s[31].dummy;
  nice_match = s[36].dummy;
  v4 = s[11].dummy;
  v5 = (_BYTE *)(dummy + s[14].dummy);
  if ( dummy <= v4 - 262 )
    limit = 0;
  else
    limit = dummy - v4 + 262;
  scan_end1 = v5[v3 - 1];
  v6 = v5 + 258;
  scan_end = v5[v3];
  if ( v3 >= s[35].dummy )
    chain_length >>= 2;
  if ( (unsigned int)nice_match > s[29].dummy )
    nice_match = s[29].dummy;
  do
  {
    v7 = (_BYTE *)(cur_match + s[14].dummy);
    if ( v7[v3] == scan_end && v7[v3 - 1] == scan_end1 && *v7 == *v5 )
    {
      v8 = v7[1];
      v9 = v7 + 1;
      if ( v8 == v5[1] )
      {
        v10 = v5 + 2;
        v11 = v9 + 1;
        do
        {
          v12 = *++v10;
          v13 = v11 + 1;
          if ( v12 != *v13 )
            break;
          v14 = *++v10;
          v15 = v13 + 1;
          if ( v14 != *v15 )
            break;
          v16 = *++v10;
          v17 = v15 + 1;
          if ( v16 != *v17 )
            break;
          v18 = *++v10;
          v19 = v17 + 1;
          if ( v18 != *v19 )
            break;
          v20 = *++v10;
          v21 = v19 + 1;
          if ( v20 != *v21 )
            break;
          v22 = *++v10;
          v23 = v21 + 1;
          if ( v22 != *v23 )
            break;
          v24 = *++v10;
          v25 = v23 + 1;
          if ( v24 != *v25 )
            break;
          v26 = *++v10;
          v11 = v25 + 1;
          if ( v26 != *v11 )
            break;
        }
        while ( v10 < v6 );
        v27 = v10 - v6 + 258;
        v5 = v6 - 258;
        if ( v27 > (int)v3 )
        {
          s[28].dummy = cur_match;
          v3 = v27;
          if ( v27 >= nice_match )
            break;
          scan_end1 = v5[v27 - 1];
          scan_end = v5[v27];
        }
      }
    }
    cur_match = *(unsigned __int16 *)(s[16].dummy + 2 * (cur_match & s[13].dummy));
    if ( cur_match <= limit )
      break;
    --chain_length;
  }
  while ( chain_length );
  result = s[29].dummy;
  if ( v3 <= result )
    return v3;
  return result;
}
