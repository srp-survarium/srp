char *__usercall internal_memalign@<eax>(unsigned int alignment@<ecx>, unsigned int bytes@<eax>, malloc_state *m)
{
  unsigned int v3; // edi
  unsigned int i; // ecx
  char *v6; // eax
  char *v7; // esi
  char *v8; // ecx
  int v9; // edi
  unsigned int v10; // eax
  unsigned int v11; // eax
  unsigned int v12; // edi
  char *v13; // eax
  char *v14; // edi
  char *mem; // [esp+8h] [ebp-8h]
  unsigned int v16; // [esp+Ch] [ebp-4h]

  v3 = alignment;
  if ( alignment > 8 )
  {
    if ( alignment < 0x10 )
      v3 = 16;
    if ( ((v3 - 1) & v3) != 0 )
    {
      for ( i = 16; i < v3; i *= 2 )
        ;
      v3 = i;
    }
    if ( bytes < -64 - v3
      && (bytes >= 0xB ? (v16 = (bytes + 11) & 0xFFFFFFF8) : (v16 = 16),
          m != &gm_ ? (v6 = vostok_mspace_malloc(m, v16 + v3 + 12)) : (v6 = dlmalloc(v16 + v3 + 12)),
          v6) )
    {
      mem = 0;
      v7 = v6 - 8;
      if ( (unsigned int)v6 % v3 )
      {
        v8 = (char *)((-v3 & (unsigned int)&v6[v3 - 1]) - 8);
        if ( (unsigned int)(v8 - v7) < 0x10 )
          v8 += v3;
        v9 = v8 - v7;
        v10 = (*((_DWORD *)v7 + 1) & 0xFFFFFFF8) - (v8 - v7);
        if ( (*((_DWORD *)v7 + 1) & 1) != 0 || (*(_DWORD *)v7 & 1) == 0 )
        {
          *((_DWORD *)v8 + 1) = v10 | *((_DWORD *)v8 + 1) & 1 | 2;
          *(_DWORD *)&v8[v10 + 4] |= 1u;
          *((_DWORD *)v7 + 1) = v9 | *((_DWORD *)v7 + 1) & 1 | 2;
          *((_DWORD *)v8 + 1) |= 1u;
          mem = v7 + 8;
        }
        else
        {
          *(_DWORD *)v8 = v9 + *(_DWORD *)v7;
          *((_DWORD *)v8 + 1) = v10 | 2;
        }
        v7 = v8;
      }
      if ( (*((_DWORD *)v7 + 1) & 1) == 0 && (*v7 & 1) != 0 || (v11 = *((_DWORD *)v7 + 1) & 0xFFFFFFF8, v11 <= v16 + 16) )
      {
        v14 = 0;
      }
      else
      {
        *((_DWORD *)v7 + 1) = v16 | *((_DWORD *)v7 + 1) & 1 | 2;
        v12 = v11 - v16;
        v13 = &v7[v16];
        *((_DWORD *)v13 + 1) |= 1u;
        *((_DWORD *)v13 + 1) = v12 | *(_DWORD *)&v7[v16 + 4] & 1 | 2;
        *(_DWORD *)&v7[v16 + 4 + v12] |= 1u;
        v14 = &v7[v16 + 8];
      }
      if ( mem )
      {
        if ( m == &gm_ )
          dlfree(mem);
        else
          vostok_mspace_free(mem, m);
      }
      if ( v14 )
      {
        if ( m == &gm_ )
          dlfree(v14);
        else
          vostok_mspace_free(v14, m);
      }
      return v7 + 8;
    }
    else
    {
      return 0;
    }
  }
  else if ( m == &gm_ )
  {
    return dlmalloc(bytes);
  }
  else
  {
    return vostok_mspace_malloc(m, bytes);
  }
}
