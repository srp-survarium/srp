unsigned __int8 *__cdecl internal_realloc(malloc_state *m, unsigned __int8 *oldmem, unsigned int bytes)
{
  int v4; // ecx
  unsigned __int8 *v5; // esi
  unsigned int v6; // eax
  unsigned __int8 *v7; // edx
  unsigned int v8; // edi
  int v9; // ecx
  unsigned int v10; // edx
  unsigned __int8 *v11; // eax
  unsigned int topsize; // edx
  unsigned int v13; // eax
  unsigned __int8 *v14; // edx
  char *v15; // eax
  unsigned int v16; // eax
  int v17; // [esp-8h] [ebp-1Ch]
  unsigned int v18; // [esp+8h] [ebp-Ch]
  char *mem; // [esp+Ch] [ebp-8h]
  unsigned __int8 *dst; // [esp+10h] [ebp-4h]
  unsigned __int8 *dsta; // [esp+10h] [ebp-4h]

  if ( bytes >= 0xFFFFFFC0 )
    return 0;
  mem = 0;
  v4 = *((_DWORD *)oldmem - 1);
  v5 = oldmem - 8;
  v6 = v4 & 0xFFFFFFF8;
  v18 = v4 & 0xFFFFFFF8;
  v7 = &oldmem[(v4 & 0xFFFFFFF8) - 8];
  if ( (char *)(oldmem - 8) < m->least_addr || (v4 & 2) == 0 || v5 >= v7 || (v7[4] & 1) == 0 )
    abort();
  if ( bytes >= 0xB )
    v8 = (bytes + 11) & 0xFFFFFFF8;
  else
    v8 = 16;
  v9 = v4 & 1;
  if ( !v9 && (*v5 & 1) != 0 )
  {
    if ( (v8 & 0xFFFFFFF8) < 0x100 )
      goto LABEL_29;
    if ( v6 < v8 + 4 || v6 - v8 > 2 * mparams.granularity )
    {
      dst = 0;
      goto LABEL_23;
    }
    goto LABEL_22;
  }
  if ( v6 < v8 )
  {
    if ( v7 != (unsigned __int8 *)m->top )
      goto LABEL_29;
    topsize = m->topsize;
    if ( topsize + v6 <= v8 )
      goto LABEL_29;
    *((_DWORD *)v5 + 1) = v8 | v9 | 2;
    v13 = v6 + topsize - v8;
    v14 = &v5[v8];
    *((_DWORD *)v14 + 1) |= 1u;
    *((_DWORD *)v14 + 1) = v13 | 1;
    m->top = (malloc_chunk *)&v5[v8];
    m->topsize = v13;
LABEL_22:
    dst = oldmem - 8;
    goto LABEL_23;
  }
  v10 = v6 - v8;
  dst = oldmem - 8;
  if ( v6 - v8 >= 0x10 )
  {
    *((_DWORD *)v5 + 1) = v8 | v9 | 2;
    v11 = &v5[v8];
    *((_DWORD *)v11 + 1) |= 1u;
    *((_DWORD *)v11 + 1) = v10 | *(_DWORD *)&v5[v8 + 4] & 1 | 2;
    *(_DWORD *)&v5[v8 + 4 + v10] |= 1u;
    mem = (char *)&oldmem[v8];
  }
LABEL_23:
  if ( dst )
  {
    if ( mem )
    {
      if ( m == &gm_ )
        dlfree(mem);
      else
        vostok_mspace_free(mem, m);
    }
    return dst + 8;
  }
LABEL_29:
  if ( m == &gm_ )
    v15 = dlmalloc(bytes);
  else
    v15 = vostok_mspace_malloc(m, bytes);
  dsta = (unsigned __int8 *)v15;
  if ( v15 )
  {
    if ( (v5[4] & 1) != 0 || (*v5 & 1) == 0 )
      v17 = 4;
    else
      v17 = 8;
    v16 = v18 - v17;
    if ( v18 - v17 >= bytes )
      v16 = bytes;
    memcpy(dsta, oldmem, v16);
    if ( m == &gm_ )
      dlfree((char *)oldmem);
    else
      vostok_mspace_free((char *)oldmem, m);
  }
  return dsta;
}
