int __cdecl deflate(z_stream_s *strm, unsigned int flush)
{
  internal_state *state; // esi
  int dummy; // eax
  int v6; // edx
  _DWORD *v7; // eax
  int v8; // ebp
  int v9; // eax
  char v10; // al
  int v11; // eax
  char v12; // al
  int v13; // eax
  unsigned int v14; // ecx
  int v15; // ebp
  int v16; // eax
  unsigned int v17; // ecx
  internal_state *v18; // eax
  internal_state *v19; // eax
  int v20; // eax
  unsigned int v21; // ecx
  unsigned int v22; // eax
  unsigned int v23; // eax
  unsigned int v24; // edx
  unsigned int v25; // eax
  int v26; // ecx
  int v27; // ebx
  unsigned int v28; // eax
  unsigned int v29; // edx
  unsigned int v30; // eax
  int v31; // ecx
  int v32; // ebx
  unsigned int v33; // eax
  int v34; // eax
  int v35; // ebx
  int v36; // eax
  block_state v37; // eax
  int v38; // eax
  internal_state *v39; // eax
  int v40; // eax
  int old_flush; // [esp+Ch] [ebp+4h]

  if ( !strm )
    return -2;
  state = strm->state;
  if ( !state || flush > 4 )
    return -2;
  if ( !strm->next_out || !strm->next_in && strm->avail_in || (dummy = state[1].dummy, dummy == 666) && flush != 4 )
  {
    strm->msg = (char *)z_errmsg[4];
    return -2;
  }
  if ( !strm->avail_out )
  {
    strm->msg = (char *)z_errmsg[7];
    return -5;
  }
  v6 = state[10].dummy;
  state->dummy = (int)strm;
  old_flush = v6;
  state[10].dummy = flush;
  if ( dummy == 42 )
  {
    if ( state[6].dummy == 2 )
    {
      strm->adler = crc32(0, 0, 0);
      *(_BYTE *)(state[2].dummy + state[5].dummy++) = 31;
      *(_BYTE *)(state[5].dummy + state[2].dummy) = -117;
      *(_BYTE *)(++state[5].dummy + state[2].dummy) = 8;
      ++state[5].dummy;
      v7 = (_DWORD *)state[7].dummy;
      v8 = state[5].dummy;
      if ( v7 )
      {
        *(_BYTE *)(state[2].dummy + v8) = (*v7 != 0)
                                        + (v7[4] != 0 ? 4 : 0)
                                        + (v7[7] != 0 ? 8 : 0)
                                        + (v7[11] != 0 ? 2 : 0)
                                        + (v7[9] != 0 ? 0x10 : 0);
        *(_BYTE *)(++state[5].dummy + state[2].dummy) = *(_BYTE *)(state[7].dummy + 4);
        *(_BYTE *)(++state[5].dummy + state[2].dummy) = *(_BYTE *)(state[7].dummy + 5);
        *(_BYTE *)(++state[5].dummy + state[2].dummy) = *(_BYTE *)(state[7].dummy + 6);
        *(_BYTE *)(++state[5].dummy + state[2].dummy) = *(_BYTE *)(state[7].dummy + 7);
        ++state[5].dummy;
        v11 = state[33].dummy;
        if ( v11 == 9 )
        {
          v12 = 2;
        }
        else if ( state[34].dummy >= 2 || v11 < 2 )
        {
          v12 = 4;
        }
        else
        {
          v12 = 0;
        }
        *(_BYTE *)(state[5].dummy + state[2].dummy) = v12;
        *(_BYTE *)(++state[5].dummy + state[2].dummy) = *(_BYTE *)(state[7].dummy + 12);
        ++state[5].dummy;
        v13 = state[7].dummy;
        v14 = state[5].dummy;
        if ( *(_DWORD *)(v13 + 16) )
        {
          *(_BYTE *)(v14 + state[2].dummy) = *(_BYTE *)(v13 + 20);
          *(_BYTE *)(++state[5].dummy + state[2].dummy) = *(_BYTE *)(state[7].dummy + 21);
          v14 = ++state[5].dummy;
        }
        if ( *(_DWORD *)(state[7].dummy + 44) )
          strm->adler = crc32(strm->adler, (const unsigned __int8 *)state[2].dummy, v14);
        state[8].dummy = 0;
        state[1].dummy = 69;
      }
      else
      {
        *(_BYTE *)(state[2].dummy + v8) = 0;
        *(_BYTE *)(++state[5].dummy + state[2].dummy) = 0;
        *(_BYTE *)(++state[5].dummy + state[2].dummy) = 0;
        *(_BYTE *)(++state[5].dummy + state[2].dummy) = 0;
        *(_BYTE *)(++state[5].dummy + state[2].dummy) = 0;
        ++state[5].dummy;
        v9 = state[33].dummy;
        if ( v9 == 9 )
        {
          v10 = 2;
        }
        else if ( state[34].dummy >= 2 || v9 < 2 )
        {
          v10 = 4;
        }
        else
        {
          v10 = 0;
        }
        *(_BYTE *)(state[5].dummy + state[2].dummy) = v10;
        *(_BYTE *)(++state[5].dummy + state[2].dummy) = 11;
        ++state[5].dummy;
        state[1].dummy = 113;
      }
    }
    else
    {
      if ( state[34].dummy >= 2 || (v15 = state[33].dummy, v15 < 2) )
      {
        v16 = 0;
      }
      else if ( v15 >= 6 )
      {
        v16 = (v15 != 6) + 2;
      }
      else
      {
        v16 = 1;
      }
      v17 = (v16 << 6) | (((state[12].dummy - 8) << 12) + 2048);
      if ( state[27].dummy )
        v17 |= 0x20u;
      state[1].dummy = 113;
      putShortMSB(state, 31 * (v17 / 0x1F + 1));
      if ( state[27].dummy )
      {
        putShortMSB(v18, HIWORD(strm->adler));
        putShortMSB(v19, strm->adler);
      }
      strm->adler = adler32(0, 0, 0);
    }
  }
  if ( state[1].dummy == 69 )
  {
    v20 = state[7].dummy;
    if ( !*(_DWORD *)(v20 + 16) )
    {
LABEL_57:
      state[1].dummy = 73;
      goto LABEL_58;
    }
    v21 = state[5].dummy;
    if ( state[8].dummy < (unsigned int)*(unsigned __int16 *)(v20 + 20) )
    {
      do
      {
        v22 = state[5].dummy;
        if ( v22 == state[3].dummy )
        {
          if ( *(_DWORD *)(state[7].dummy + 44) && v22 > v21 )
            strm->adler = crc32(strm->adler, (const unsigned __int8 *)(v21 + state[2].dummy), v22 - v21);
          flush_pending(strm);
          v22 = state[5].dummy;
          v21 = v22;
          if ( v22 == state[3].dummy )
            break;
        }
        *(_BYTE *)(v22 + state[2].dummy) = *(_BYTE *)(*(_DWORD *)(state[7].dummy + 16) + state[8].dummy);
        ++state[5].dummy;
        ++state[8].dummy;
      }
      while ( state[8].dummy < (unsigned int)*(unsigned __int16 *)(state[7].dummy + 20) );
    }
    if ( *(_DWORD *)(state[7].dummy + 44) )
    {
      v23 = state[5].dummy;
      if ( v23 > v21 )
        strm->adler = crc32(strm->adler, (const unsigned __int8 *)(v21 + state[2].dummy), v23 - v21);
    }
    if ( state[8].dummy == *(_DWORD *)(state[7].dummy + 20) )
    {
      state[8].dummy = 0;
      goto LABEL_57;
    }
  }
LABEL_58:
  if ( state[1].dummy == 73 )
  {
    if ( !*(_DWORD *)(state[7].dummy + 28) )
    {
LABEL_74:
      state[1].dummy = 91;
      goto LABEL_75;
    }
    v24 = state[5].dummy;
    while ( 1 )
    {
      v25 = state[5].dummy;
      if ( v25 == state[3].dummy )
      {
        if ( *(_DWORD *)(state[7].dummy + 44) && v25 > v24 )
          strm->adler = crc32(strm->adler, (const unsigned __int8 *)(v24 + state[2].dummy), v25 - v24);
        flush_pending(strm);
        v25 = state[5].dummy;
        v24 = v25;
        if ( v25 == state[3].dummy )
          break;
      }
      v26 = state[8].dummy;
      v27 = *(unsigned __int8 *)(*(_DWORD *)(state[7].dummy + 28) + v26);
      state[8].dummy = v26 + 1;
      *(_BYTE *)(v25 + state[2].dummy) = v27;
      ++state[5].dummy;
      if ( !v27 )
        goto LABEL_69;
    }
    v27 = 1;
LABEL_69:
    if ( *(_DWORD *)(state[7].dummy + 44) )
    {
      v28 = state[5].dummy;
      if ( v28 > v24 )
        strm->adler = crc32(strm->adler, (const unsigned __int8 *)(v24 + state[2].dummy), v28 - v24);
    }
    if ( !v27 )
    {
      state[8].dummy = 0;
      goto LABEL_74;
    }
  }
LABEL_75:
  if ( state[1].dummy == 91 )
  {
    if ( !*(_DWORD *)(state[7].dummy + 36) )
      goto LABEL_90;
    v29 = state[5].dummy;
    while ( 1 )
    {
      v30 = state[5].dummy;
      if ( v30 == state[3].dummy )
      {
        if ( *(_DWORD *)(state[7].dummy + 44) && v30 > v29 )
          strm->adler = crc32(strm->adler, (const unsigned __int8 *)(v29 + state[2].dummy), v30 - v29);
        flush_pending(strm);
        v30 = state[5].dummy;
        v29 = v30;
        if ( v30 == state[3].dummy )
          break;
      }
      v31 = state[8].dummy;
      v32 = *(unsigned __int8 *)(*(_DWORD *)(state[7].dummy + 36) + v31);
      state[8].dummy = v31 + 1;
      *(_BYTE *)(v30 + state[2].dummy) = v32;
      ++state[5].dummy;
      if ( !v32 )
        goto LABEL_86;
    }
    v32 = 1;
LABEL_86:
    if ( *(_DWORD *)(state[7].dummy + 44) )
    {
      v33 = state[5].dummy;
      if ( v33 > v29 )
        strm->adler = crc32(strm->adler, (const unsigned __int8 *)(v29 + state[2].dummy), v33 - v29);
    }
    if ( !v32 )
LABEL_90:
      state[1].dummy = 103;
  }
  if ( state[1].dummy == 103 )
  {
    if ( !*(_DWORD *)(state[7].dummy + 44) )
    {
LABEL_97:
      state[1].dummy = 113;
      goto LABEL_98;
    }
    if ( (unsigned int)(state[5].dummy + 2) > state[3].dummy )
      flush_pending(strm);
    v34 = state[5].dummy;
    if ( (unsigned int)(v34 + 2) <= state[3].dummy )
    {
      *(_BYTE *)(v34 + state[2].dummy) = strm->adler;
      *(_BYTE *)(++state[5].dummy + state[2].dummy) = BYTE1(strm->adler);
      ++state[5].dummy;
      strm->adler = crc32(0, 0, 0);
      goto LABEL_97;
    }
  }
LABEL_98:
  if ( state[5].dummy )
  {
    flush_pending(strm);
    if ( !strm->avail_out )
    {
LABEL_100:
      state[10].dummy = -1;
      return 0;
    }
    v35 = flush;
  }
  else
  {
    v35 = flush;
    if ( !strm->avail_in && (int)flush <= old_flush && flush != 4 )
    {
      strm->msg = (char *)z_errmsg[7];
      return -5;
    }
  }
  v36 = state[1].dummy;
  if ( v36 == 666 )
  {
    if ( strm->avail_in )
    {
      strm->msg = (char *)z_errmsg[7];
      return -5;
    }
LABEL_111:
    if ( !state[29].dummy && (!v35 || v36 == 666) )
      goto LABEL_125;
    goto LABEL_114;
  }
  if ( !strm->avail_in )
    goto LABEL_111;
LABEL_114:
  v37 = configuration_table[state[33].dummy].func(state, v35);
  if ( v37 == finish_started || v37 == finish_done )
    state[1].dummy = 666;
  if ( v37 == need_more || v37 == finish_started )
  {
    if ( strm->avail_out )
      return 0;
    state[10].dummy = -1;
    return 0;
  }
  if ( v37 == block_done )
  {
    if ( v35 == 1 )
    {
      _tr_align(state);
    }
    else
    {
      _tr_stored_block(state, 0, 0, 0);
      if ( v35 == 3 )
      {
        *(_WORD *)(state[17].dummy + 2 * state[19].dummy - 2) = 0;
        memset(state[17].dummy, 0, 2 * state[19].dummy - 2);
      }
    }
    flush_pending(strm);
    if ( !strm->avail_out )
      goto LABEL_100;
  }
LABEL_125:
  if ( v35 != 4 )
    return 0;
  v38 = state[6].dummy;
  if ( v38 <= 0 )
    return 1;
  if ( v38 == 2 )
  {
    *(_BYTE *)(state[2].dummy + state[5].dummy++) = strm->adler;
    *(_BYTE *)(state[5].dummy + state[2].dummy) = BYTE1(strm->adler);
    *(_BYTE *)(++state[5].dummy + state[2].dummy) = BYTE2(strm->adler);
    *(_BYTE *)(++state[5].dummy + state[2].dummy) = HIBYTE(strm->adler);
    *(_BYTE *)(++state[5].dummy + state[2].dummy) = strm->total_in;
    *(_BYTE *)(++state[5].dummy + state[2].dummy) = BYTE1(strm->total_in);
    *(_BYTE *)(++state[5].dummy + state[2].dummy) = BYTE2(strm->total_in);
    *(_BYTE *)(++state[5].dummy + state[2].dummy) = HIBYTE(strm->total_in);
    ++state[5].dummy;
  }
  else
  {
    putShortMSB(state, HIWORD(strm->adler));
    putShortMSB(v39, strm->adler);
  }
  flush_pending(strm);
  v40 = state[6].dummy;
  if ( v40 > 0 )
    state[6].dummy = -v40;
  return state[5].dummy == 0;
}
