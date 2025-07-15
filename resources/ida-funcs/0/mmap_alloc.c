int *__cdecl mmap_alloc(malloc_state *m)
{
  unsigned int nb; // ecx
  unsigned int v2; // eax
  unsigned int v3; // edi
  char *v4; // eax
  int v5; // ecx
  int *v6; // esi
  char *v7; // ecx
  unsigned int footprint; // eax

  v2 = ~(mparams.granularity - 1);
  v3 = v2 & (mparams.granularity + nb + 30);
  if ( v3 <= nb )
    return 0;
  v4 = (char *)mmap(v2 & (mparams.granularity + nb + 30));
  if ( v4 == (char *)-1 )
    return 0;
  v5 = ((unsigned __int8)v4 & 7) != 0 ? -((unsigned __int8)v4 & 7) & 7 : 0;
  v6 = (int *)&v4[v5];
  *v6 = v5 | 1;
  v6[1] = (v3 - v5 - 16) | 2;
  v7 = &v4[v3 - 16];
  *((_DWORD *)v7 + 2) = 0;
  *((_DWORD *)v7 + 1) = 7;
  if ( v4 < m->least_addr )
    m->least_addr = v4;
  m->footprint += v3;
  footprint = m->footprint;
  if ( footprint > m->max_footprint )
    m->max_footprint = footprint;
  return v6 + 2;
}
