malloc_state *__cdecl init_user_mstate(char *tbase, unsigned int tsize)
{
  char *v2; // edi
  malloc_state *v3; // esi
  unsigned int magic; // ecx
  char *v5; // ecx
  int v6; // edi
  malloc_chunk *v7; // ecx

  v2 = &tbase[((unsigned __int8)tbase & 7) != 0 ? -((unsigned __int8)tbase & 7) & 7 : 0];
  v3 = (malloc_state *)(v2 + 8);
  memset((int)(v2 + 8), 0, 0x1E0u);
  magic = mparams.magic;
  *((_DWORD *)v2 + 1) = 483;
  *((_DWORD *)v2 + 11) = magic;
  *((_DWORD *)v2 + 119) = 0;
  *((_DWORD *)v2 + 120) = 0;
  *((_DWORD *)v2 + 117) = 0;
  *((_DWORD *)v2 + 118) = 0;
  *((_DWORD *)v2 + 112) = mparams.default_mflags | 4;
  *((_DWORD *)v2 + 6) = tbase;
  *((_DWORD *)v2 + 113) = tbase;
  *((_DWORD *)v2 + 111) = tsize;
  *((_DWORD *)v2 + 110) = tsize;
  *((_DWORD *)v2 + 114) = tsize;
  *((_DWORD *)v2 + 10) = 255;
  v5 = v2 + 48;
  v6 = 32;
  do
  {
    --v6;
    *((_DWORD *)v5 + 3) = v5;
    *((_DWORD *)v5 + 2) = v5;
    v5 += 8;
  }
  while ( v6 );
  v7 = (malloc_chunk *)((char *)v3 + ((int)v3[-1].out_of_memory_parameter & 0xFFFFFFF8) - 8);
  init_top(v3, v7, tbase - (char *)v7 + tsize - 40);
  return v3;
}
