int __cdecl deflate_fast(internal_state *s, int flush)
{
  unsigned int v2; // ebx
  unsigned int dummy; // eax
  int v4; // edx
  int v5; // edi
  int v6; // eax
  int v7; // ecx
  unsigned int v8; // eax
  int v9; // ecx
  unsigned __int8 v10; // al
  __int16 v11; // cx
  unsigned __int16 v12; // cx
  int v13; // eax
  unsigned int v14; // eax
  BOOL v15; // ecx
  BOOL v16; // edi
  int v17; // edx
  int v18; // ecx
  int v19; // eax
  int v20; // ebx
  int v21; // edx
  unsigned __int8 *v23; // edx
  int v24; // ecx
  int v25; // eax
  unsigned __int8 v26; // al
  BOOL v27; // ecx
  int v28; // ecx
  char *v29; // eax
  int *v30; // edi
  int v31; // eax
  unsigned int v32; // ebp
  int v33; // eax
  _DWORD *v34; // edi
  int v36; // ecx
  char *v37; // eax
  int v38; // eax

  v2 = 0;
  while ( 1 )
  {
    dummy = s[29].dummy;
    if ( dummy < 0x106 )
    {
      fill_window(s);
      dummy = s[29].dummy;
      if ( dummy < 0x106 && !flush )
        return 0;
      if ( !dummy )
        break;
    }
    if ( dummy >= 3 )
    {
      v4 = s[27].dummy;
      v5 = s[13].dummy;
      v6 = s[21].dummy & (*(unsigned __int8 *)(s[14].dummy + v4 + 2) ^ (s[18].dummy << s[22].dummy));
      v7 = s[17].dummy;
      s[18].dummy = v6;
      *(_WORD *)(s[16].dummy + 2 * (v4 & v5)) = *(_WORD *)(v7 + 2 * v6);
      v2 = *(unsigned __int16 *)(s[16].dummy + 2 * (s[13].dummy & s[27].dummy));
      *(_WORD *)(s[17].dummy + 2 * s[18].dummy) = s[27].dummy;
    }
    if ( v2 )
    {
      v8 = s[27].dummy - v2;
      if ( v8 <= s[11].dummy - 262 )
      {
        v9 = s[34].dummy;
        if ( v9 != 2 )
        {
          if ( v9 == 3 )
          {
            if ( v8 == 1 )
              s[24].dummy = longest_match_fast(s, v2);
          }
          else
          {
            s[24].dummy = longest_match(s, v2);
          }
        }
      }
    }
    if ( s[24].dummy < 3u )
    {
      v26 = *(_BYTE *)(s[27].dummy + s[14].dummy);
      *(_WORD *)(s[1449].dummy + 2 * s[1448].dummy) = 0;
      *(_BYTE *)(s[1446].dummy + s[1448].dummy++) = v26;
      ++LOWORD(s[v26 + 37].dummy);
      v27 = s[1448].dummy == s[1447].dummy - 1;
      --s[29].dummy;
      v16 = v27;
    }
    else
    {
      v10 = s[24].dummy;
      v11 = LOWORD(s[27].dummy) - LOWORD(s[28].dummy);
      *(_WORD *)(s[1449].dummy + 2 * s[1448].dummy) = v11;
      v10 -= 3;
      *(_BYTE *)(s[1446].dummy + s[1448].dummy++) = v10;
      ++LOWORD(s[_length_code[v10] + 294].dummy);
      v12 = v11 - 1;
      if ( v12 >= 0x100u )
        v13 = (unsigned __int8)byte_7332C8[v12 >> 7];
      else
        v13 = _dist_code[v12];
      ++LOWORD(s[v13 + 610].dummy);
      v14 = s[24].dummy;
      v15 = s[1448].dummy == s[1447].dummy - 1;
      s[29].dummy -= v14;
      v16 = v15;
      if ( v14 > s[32].dummy || s[29].dummy < 3u )
      {
        s[27].dummy += v14;
        v23 = (unsigned __int8 *)(s[27].dummy + s[14].dummy);
        v24 = s[22].dummy;
        s[24].dummy = 0;
        v25 = *v23;
        s[18].dummy = v25;
        s[18].dummy = s[21].dummy & (v23[1] ^ (v25 << v24));
        goto LABEL_28;
      }
      s[24].dummy = v14 - 1;
      do
      {
        v17 = ++s[27].dummy;
        v18 = s[17].dummy;
        v19 = s[21].dummy & ((s[18].dummy << s[22].dummy) ^ *(unsigned __int8 *)(v17 + s[14].dummy + 2));
        v20 = v17 & s[13].dummy;
        v21 = s[16].dummy;
        s[18].dummy = v19;
        *(_WORD *)(v21 + 2 * v20) = *(_WORD *)(v18 + 2 * v19);
        v2 = *(unsigned __int16 *)(s[16].dummy + 2 * (s[13].dummy & s[27].dummy));
        *(_WORD *)(s[17].dummy + 2 * s[18].dummy) = s[27].dummy;
      }
      while ( s[24].dummy-- != 1 );
    }
    ++s[27].dummy;
LABEL_28:
    if ( v16 )
    {
      v28 = s[23].dummy;
      if ( v28 < 0 )
        v29 = 0;
      else
        v29 = (char *)(v28 + s[14].dummy);
      _tr_flush_block(s, v29, s[27].dummy - v28, 0);
      v30 = (int *)s->dummy;
      s[23].dummy = s[27].dummy;
      v31 = v30[7];
      v32 = *(_DWORD *)(v31 + 20);
      if ( v32 > v30[4] )
        v32 = v30[4];
      if ( v32 )
      {
        memcpy(v30[3], *(const __m128i **)(v31 + 16), v32);
        v33 = v30[7];
        v30[3] += v32;
        *(_DWORD *)(v33 + 16) += v32;
        v30[5] += v32;
        v30[4] -= v32;
        *(_DWORD *)(v30[7] + 20) -= v32;
        v34 = (_DWORD *)v30[7];
        if ( !v34[5] )
          v34[4] = v34[2];
      }
      if ( !*(_DWORD *)(s->dummy + 16) )
        return 0;
    }
  }
  v36 = s[23].dummy;
  if ( v36 < 0 )
    v37 = 0;
  else
    v37 = (char *)(v36 + s[14].dummy);
  _tr_flush_block(s, v37, s[27].dummy - v36, flush == 4);
  s[23].dummy = s[27].dummy;
  flush_pending((z_stream_s *)s->dummy);
  v38 = 0;
  if ( !*(_DWORD *)(s->dummy + 16) )
    return flush != 4 ? 0 : 2;
  LOBYTE(v38) = flush == 4;
  return 2 * v38 + 1;
}
