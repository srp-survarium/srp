int __cdecl deflate_stored(internal_state *s, int flush)
{
  unsigned int dummy; // eax
  bool v3; // zf
  int v4; // ecx
  unsigned int v5; // edx
  unsigned int v6; // eax
  char *v7; // edx
  int v8; // edi
  int v9; // eax
  unsigned int v10; // ebx
  int v11; // eax
  _DWORD *v12; // edi
  int v13; // edx
  unsigned int v14; // ecx
  char *v15; // eax
  int v16; // edi
  int v17; // eax
  unsigned int v18; // ebx
  int v19; // eax
  _DWORD *v20; // edi
  int v22; // ecx
  char *v23; // eax
  int v24; // eax
  int max_block_size; // [esp+Ch] [ebp-4h]

  max_block_size = 0xFFFF;
  if ( (unsigned int)(s[3].dummy - 5) < 0xFFFF )
    max_block_size = s[3].dummy - 5;
  while ( 1 )
  {
    dummy = s[29].dummy;
    if ( dummy <= 1 )
    {
      fill_window(s);
      dummy = s[29].dummy;
      if ( !dummy )
        break;
    }
    v3 = dummy + s[27].dummy == 0;
    s[27].dummy += dummy;
    v4 = s[23].dummy;
    v5 = s[27].dummy;
    s[29].dummy = 0;
    v6 = v4 + max_block_size;
    if ( !v3 && v5 < v6 )
      goto LABEL_36;
    s[29].dummy = v5 - v6;
    s[27].dummy = v6;
    if ( v4 < 0 )
      v7 = 0;
    else
      v7 = (char *)(v4 + s[14].dummy);
    _tr_flush_block(s, v7, max_block_size, 0);
    v8 = s->dummy;
    s[23].dummy = s[27].dummy;
    v9 = *(_DWORD *)(v8 + 28);
    v10 = *(_DWORD *)(v9 + 20);
    if ( v10 > *(_DWORD *)(v8 + 16) )
      v10 = *(_DWORD *)(v8 + 16);
    if ( v10 )
    {
      memcpy(*(unsigned __int8 **)(v8 + 12), *(unsigned __int8 **)(v9 + 16), v10);
      v11 = *(_DWORD *)(v8 + 28);
      *(_DWORD *)(v8 + 12) += v10;
      *(_DWORD *)(v11 + 16) += v10;
      *(_DWORD *)(v8 + 20) += v10;
      *(_DWORD *)(v8 + 16) -= v10;
      *(_DWORD *)(*(_DWORD *)(v8 + 28) + 20) -= v10;
      v12 = *(_DWORD **)(v8 + 28);
      if ( !v12[5] )
        v12[4] = v12[2];
    }
    if ( *(_DWORD *)(s->dummy + 16) )
    {
LABEL_36:
      v13 = s[23].dummy;
      v14 = s[27].dummy - v13;
      if ( v14 < s[11].dummy - 262 )
        continue;
      if ( v13 < 0 )
        v15 = 0;
      else
        v15 = (char *)(v13 + s[14].dummy);
      _tr_flush_block(s, v15, v14, 0);
      v16 = s->dummy;
      s[23].dummy = s[27].dummy;
      v17 = *(_DWORD *)(v16 + 28);
      v18 = *(_DWORD *)(v17 + 20);
      if ( v18 > *(_DWORD *)(v16 + 16) )
        v18 = *(_DWORD *)(v16 + 16);
      if ( v18 )
      {
        memcpy(*(unsigned __int8 **)(v16 + 12), *(unsigned __int8 **)(v17 + 16), v18);
        v19 = *(_DWORD *)(v16 + 28);
        *(_DWORD *)(v16 + 12) += v18;
        *(_DWORD *)(v19 + 16) += v18;
        *(_DWORD *)(v16 + 20) += v18;
        *(_DWORD *)(v16 + 16) -= v18;
        *(_DWORD *)(*(_DWORD *)(v16 + 28) + 20) -= v18;
        v20 = *(_DWORD **)(v16 + 28);
        if ( !v20[5] )
          v20[4] = v20[2];
      }
      if ( *(_DWORD *)(s->dummy + 16) )
        continue;
    }
    return 0;
  }
  if ( !flush )
    return 0;
  v22 = s[23].dummy;
  if ( v22 < 0 )
    v23 = 0;
  else
    v23 = (char *)(v22 + s[14].dummy);
  _tr_flush_block(s, v23, s[27].dummy - v22, flush == 4);
  s[23].dummy = s[27].dummy;
  flush_pending((z_stream_s *)s->dummy);
  v24 = 0;
  if ( !*(_DWORD *)(s->dummy + 16) )
    return flush != 4 ? 0 : 2;
  LOBYTE(v24) = flush == 4;
  return 2 * v24 + 1;
}
