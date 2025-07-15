void __usercall fill_window(internal_state *s@<esi>)
{
  unsigned int dummy; // ebp
  unsigned int v2; // eax
  unsigned int v3; // edi
  int v4; // edx
  int v5; // eax
  _WORD *v6; // ecx
  unsigned int v7; // eax
  __int16 v8; // ax
  unsigned int v9; // edx
  _WORD *v10; // ecx
  unsigned int v11; // eax
  __int16 v12; // ax
  int v13; // edi
  int v14; // eax
  unsigned int v15; // ebx
  int v16; // edx
  int v17; // ecx
  unsigned int v18; // eax
  unsigned int v19; // edi
  int v20; // ecx
  unsigned __int8 *v21; // edx
  int v22; // eax
  unsigned int more; // [esp+Ch] [ebp-8h]
  int v24; // [esp+10h] [ebp-4h]

  dummy = s[11].dummy;
  do
  {
    v2 = s[27].dummy;
    v3 = s[15].dummy - s[29].dummy - v2;
    more = v3;
    if ( v2 >= s[11].dummy + dummy - 262 )
    {
      memcpy(s[14].dummy, (const __m128i *)(s[14].dummy + dummy), dummy);
      v4 = s[19].dummy;
      v5 = s[17].dummy;
      s[28].dummy -= dummy;
      s[27].dummy -= dummy;
      s[23].dummy -= dummy;
      v6 = (_WORD *)(v5 + 2 * v4);
      do
      {
        v7 = (unsigned __int16)*--v6;
        if ( v7 < dummy )
          v8 = 0;
        else
          v8 = v7 - dummy;
        --v4;
        *v6 = v8;
      }
      while ( v4 );
      v9 = dummy;
      v10 = (_WORD *)(s[16].dummy + 2 * dummy);
      do
      {
        v11 = (unsigned __int16)*--v10;
        if ( v11 < dummy )
          v12 = 0;
        else
          v12 = v11 - dummy;
        --v9;
        *v10 = v12;
      }
      while ( v9 );
      more = dummy + v3;
    }
    v13 = s->dummy;
    if ( !*(_DWORD *)(s->dummy + 4) )
      break;
    v14 = s[14].dummy + s[27].dummy + s[29].dummy;
    v15 = *(_DWORD *)(v13 + 4);
    if ( v15 > more )
      v15 = more;
    v24 = s[14].dummy + s[27].dummy + s[29].dummy;
    if ( !v15 )
      goto LABEL_24;
    v16 = *(_DWORD *)(v13 + 28);
    *(_DWORD *)(v13 + 4) -= v15;
    v17 = *(_DWORD *)(v16 + 24);
    if ( v17 == 1 )
    {
      v18 = adler32(*(_DWORD *)(v13 + 48), *(const unsigned __int8 **)v13, v15);
LABEL_22:
      *(_DWORD *)(v13 + 48) = v18;
      v14 = v24;
      goto LABEL_23;
    }
    if ( v17 == 2 )
    {
      v18 = crc32(*(_DWORD *)(v13 + 48), *(const unsigned __int8 **)v13, v15);
      goto LABEL_22;
    }
LABEL_23:
    memcpy(v14, *(const __m128i **)v13, v15);
    *(_DWORD *)v13 += v15;
    *(_DWORD *)(v13 + 8) += v15;
LABEL_24:
    s[29].dummy += v15;
    v19 = s[29].dummy;
    if ( v19 >= 3 )
    {
      v20 = s[22].dummy;
      v21 = (unsigned __int8 *)(s[14].dummy + s[27].dummy);
      v22 = *v21;
      s[18].dummy = v22;
      s[18].dummy = s[21].dummy & (v21[1] ^ (v22 << v20));
    }
  }
  while ( v19 < 0x106 && *(_DWORD *)(s->dummy + 4) );
}
