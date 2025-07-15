malloc_state *__usercall init_user_mstate@<eax>(char *tbase@<eax>, unsigned int tsize)
{
  int v3; // eax
  int v4; // ebp
  char *v5; // esi
  unsigned int default_mflags; // ecx
  unsigned int magic; // eax
  char *v8; // eax
  int v9; // ecx
  char *v10; // edx
  unsigned int v11; // edi
  int v12; // ecx
  char *v13; // edx
  unsigned int v14; // eax

  v3 = (unsigned __int8)tbase & 7;
  if ( v3 )
    v4 = -v3 & 7;
  else
    v4 = 0;
  v5 = &tbase[v4 + 8];
  memset((int)v5, 0, 0x1E0u);
  default_mflags = mparams.default_mflags;
  magic = mparams.magic;
  *(_DWORD *)&tbase[v4 + 4] = 483;
  *((_DWORD *)v5 + 9) = magic;
  *((_DWORD *)v5 + 110) = default_mflags | 4;
  *((_DWORD *)v5 + 4) = tbase;
  *((_DWORD *)v5 + 111) = tbase;
  *((_DWORD *)v5 + 109) = tsize;
  *((_DWORD *)v5 + 108) = tsize;
  *((_DWORD *)v5 + 112) = tsize;
  *((_DWORD *)v5 + 8) = 255;
  *((_DWORD *)v5 + 117) = 0;
  *((_DWORD *)v5 + 118) = 0;
  *((_DWORD *)v5 + 115) = 0;
  *((_DWORD *)v5 + 116) = 0;
  v8 = &tbase[v4 + 48];
  v9 = 32;
  do
  {
    *((_DWORD *)v8 + 3) = v8;
    *((_DWORD *)v8 + 2) = v8;
    v8 += 8;
    --v9;
  }
  while ( v9 );
  v10 = &tbase[v4 + (*(_DWORD *)&tbase[v4 + 4] & 0xFFFFFFF8)];
  v11 = -((*(_DWORD *)&tbase[v4 + 4] & 0xFFFFFFF8) + v4);
  v12 = ((*(v5 - 4) & 0xF8) + (_BYTE)v5 - 8) & 7;
  if ( (((*(v5 - 4) & 0xF8) + (_BYTE)v5 - 8) & 7) != 0 )
    v12 = -v12 & 7;
  v13 = &v10[v12];
  v14 = v11 + tsize - 40 - v12;
  *((_DWORD *)v5 + 6) = v13;
  *((_DWORD *)v5 + 3) = v14;
  *((_DWORD *)v13 + 1) = v14 | 1;
  *(_DWORD *)&v13[v14 + 4] = 40;
  *((_DWORD *)v5 + 7) = mparams.trim_threshold;
  return (malloc_state *)v5;
}
