int __cdecl deflate_slow(internal_state *s, int flush)
{
  unsigned int dummy; // eax
  int v3; // edx
  int v4; // edi
  int v5; // eax
  int v6; // ecx
  unsigned int v7; // ecx
  unsigned int v8; // eax
  int v9; // ecx
  unsigned int matched; // eax
  unsigned int v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // edi
  unsigned __int8 v14; // al
  __int16 v15; // cx
  unsigned __int16 v16; // cx
  int v17; // eax
  int v18; // eax
  BOOL v19; // ebx
  unsigned int v20; // edx
  int v21; // ebp
  int v22; // ecx
  int v23; // edx
  int v24; // eax
  int v25; // ecx
  int v26; // eax
  int v27; // edx
  char *v28; // ecx
  int *v29; // edi
  int v30; // eax
  unsigned int v31; // ebx
  int v32; // eax
  _DWORD *v33; // edi
  bool v34; // zf
  unsigned __int8 v36; // al
  int v37; // ecx
  char *v38; // eax
  int *v39; // edi
  int v40; // eax
  unsigned int v41; // ebx
  int v42; // eax
  _DWORD *v43; // edi
  int v44; // ecx
  unsigned __int8 v45; // al
  int v46; // ecx
  char *v47; // eax
  int v48; // eax
  unsigned int hash_head; // [esp+10h] [ebp-4h]

  hash_head = 0;
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
      v3 = s[27].dummy;
      v4 = s[13].dummy;
      v5 = s[21].dummy & (*(unsigned __int8 *)(s[14].dummy + v3 + 2) ^ (s[18].dummy << s[22].dummy));
      v6 = s[17].dummy;
      s[18].dummy = v5;
      *(_WORD *)(s[16].dummy + 2 * (v3 & v4)) = *(_WORD *)(v6 + 2 * v5);
      hash_head = *(unsigned __int16 *)(s[16].dummy + 2 * (s[13].dummy & s[27].dummy));
      *(_WORD *)(s[17].dummy + 2 * s[18].dummy) = s[27].dummy;
    }
    v7 = s[24].dummy;
    s[25].dummy = s[28].dummy;
    s[30].dummy = v7;
    s[24].dummy = 2;
    if ( !hash_head )
      goto LABEL_23;
    if ( v7 >= s[32].dummy )
      goto LABEL_23;
    v8 = s[27].dummy - hash_head;
    if ( v8 > s[11].dummy - 262 )
      goto LABEL_23;
    v9 = s[34].dummy;
    if ( v9 != 2 )
    {
      if ( v9 != 3 )
      {
        matched = longest_match(s, hash_head);
LABEL_17:
        s[24].dummy = matched;
        goto LABEL_18;
      }
      if ( v8 == 1 )
      {
        matched = longest_match_fast(s, hash_head);
        goto LABEL_17;
      }
    }
LABEL_18:
    v11 = s[24].dummy;
    if ( v11 <= 5 && (s[34].dummy == 1 || v11 == 3 && (unsigned int)(s[27].dummy - s[28].dummy) > 0x1000) )
      s[24].dummy = 2;
LABEL_23:
    v12 = s[30].dummy;
    if ( v12 < 3 || s[24].dummy > v12 )
    {
      if ( s[26].dummy )
      {
        v36 = *(_BYTE *)(s[27].dummy + s[14].dummy - 1);
        *(_WORD *)(s[1449].dummy + 2 * s[1448].dummy) = 0;
        *(_BYTE *)(s[1446].dummy + s[1448].dummy++) = v36;
        ++LOWORD(s[v36 + 37].dummy);
        if ( s[1448].dummy == s[1447].dummy - 1 )
        {
          v37 = s[23].dummy;
          if ( v37 < 0 )
            v38 = 0;
          else
            v38 = (char *)(v37 + s[14].dummy);
          _tr_flush_block(s, v38, s[27].dummy - v37, 0);
          v39 = (int *)s->dummy;
          s[23].dummy = s[27].dummy;
          v40 = v39[7];
          v41 = *(_DWORD *)(v40 + 20);
          if ( v41 > v39[4] )
            v41 = v39[4];
          if ( v41 )
          {
            memcpy(v39[3], *(const __m128i **)(v40 + 16), v41);
            v42 = v39[7];
            v39[3] += v41;
            *(_DWORD *)(v42 + 16) += v41;
            v39[5] += v41;
            v39[4] -= v41;
            *(_DWORD *)(v39[7] + 20) -= v41;
            v43 = (_DWORD *)v39[7];
            if ( !v43[5] )
              v43[4] = v43[2];
          }
        }
        v44 = s->dummy;
        ++s[27].dummy;
        --s[29].dummy;
        v34 = *(_DWORD *)(v44 + 16) == 0;
        goto LABEL_42;
      }
      ++s[27].dummy;
      --s[29].dummy;
      s[26].dummy = 1;
    }
    else
    {
      v13 = s[27].dummy + s[29].dummy - 3;
      v14 = s[30].dummy;
      v15 = LOWORD(s[27].dummy) - LOWORD(s[25].dummy) - 1;
      *(_WORD *)(s[1449].dummy + 2 * s[1448].dummy) = v15;
      v14 -= 3;
      *(_BYTE *)(s[1446].dummy + s[1448].dummy++) = v14;
      ++LOWORD(s[_length_code[v14] + 294].dummy);
      v16 = v15 - 1;
      if ( v16 >= 0x100u )
        v17 = (unsigned __int8)byte_7332C8[v16 >> 7];
      else
        v17 = _dist_code[v16];
      ++LOWORD(s[v17 + 610].dummy);
      v18 = s[30].dummy;
      v19 = s[1448].dummy == s[1447].dummy - 1;
      s[29].dummy += 1 - v18;
      s[30].dummy = v18 - 2;
      do
      {
        v20 = ++s[27].dummy;
        if ( v20 <= v13 )
        {
          v21 = s[16].dummy;
          v22 = *(unsigned __int8 *)(s[14].dummy + v20 + 2);
          v23 = s[13].dummy & v20;
          v24 = s[21].dummy & (v22 ^ (s[18].dummy << s[22].dummy));
          v25 = s[17].dummy;
          s[18].dummy = v24;
          *(_WORD *)(v21 + 2 * v23) = *(_WORD *)(v25 + 2 * v24);
          hash_head = *(unsigned __int16 *)(s[16].dummy + 2 * (s[13].dummy & s[27].dummy));
          *(_WORD *)(s[17].dummy + 2 * s[18].dummy) = s[27].dummy;
        }
        v34 = s[30].dummy-- == 1;
      }
      while ( !v34 );
      v26 = ++s[27].dummy;
      s[26].dummy = 0;
      s[24].dummy = 2;
      if ( v19 )
      {
        v27 = s[23].dummy;
        if ( v27 < 0 )
          v28 = 0;
        else
          v28 = (char *)(v27 + s[14].dummy);
        _tr_flush_block(s, v28, v26 - v27, 0);
        v29 = (int *)s->dummy;
        s[23].dummy = s[27].dummy;
        v30 = v29[7];
        v31 = *(_DWORD *)(v30 + 20);
        if ( v31 > v29[4] )
          v31 = v29[4];
        if ( v31 )
        {
          memcpy(v29[3], *(const __m128i **)(v30 + 16), v31);
          v32 = v29[7];
          v29[3] += v31;
          *(_DWORD *)(v32 + 16) += v31;
          v29[5] += v31;
          v29[4] -= v31;
          *(_DWORD *)(v29[7] + 20) -= v31;
          v33 = (_DWORD *)v29[7];
          if ( !v33[5] )
            v33[4] = v33[2];
        }
        v34 = *(_DWORD *)(s->dummy + 16) == 0;
LABEL_42:
        if ( v34 )
          return 0;
      }
    }
  }
  if ( s[26].dummy )
  {
    v45 = *(_BYTE *)(s[27].dummy + s[14].dummy - 1);
    *(_WORD *)(s[1449].dummy + 2 * s[1448].dummy) = 0;
    *(_BYTE *)(s[1446].dummy + s[1448].dummy++) = v45;
    ++LOWORD(s[v45 + 37].dummy);
    s[26].dummy = 0;
  }
  v46 = s[23].dummy;
  if ( v46 < 0 )
    v47 = 0;
  else
    v47 = (char *)(v46 + s[14].dummy);
  _tr_flush_block(s, v47, s[27].dummy - v46, flush == 4);
  s[23].dummy = s[27].dummy;
  flush_pending((z_stream_s *)s->dummy);
  v48 = 0;
  if ( !*(_DWORD *)(s->dummy + 16) )
    return flush != 4 ? 0 : 2;
  LOBYTE(v48) = flush == 4;
  return 2 * v48 + 1;
}
