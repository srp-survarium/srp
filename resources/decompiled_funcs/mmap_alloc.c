int *__usercall mmap_alloc@<eax>(unsigned int nb@<eax>, malloc_state *m)
{
  unsigned int v2; // ecx
  unsigned int v3; // edi
  char *v4; // eax
  int v5; // edx
  int *v6; // esi
  int v7; // ecx
  unsigned int footprint; // eax

  v2 = ~(mparams.granularity - 1);
  v3 = v2 & (mparams.granularity + nb + 30);
  if ( v3 <= nb )
    return 0;
  v4 = (char *)mmap(v2 & (mparams.granularity + nb + 30));
  if ( v4 == (char *)-1 )
    return 0;
  v5 = (unsigned __int8)v4 & 7;
  if ( ((unsigned __int8)v4 & 7) != 0 )
    v5 = -v5 & 7;
  v6 = (int *)&v4[v5];
  v7 = v3 - v5 - 16;
  *v6 = v5 | 1;
  v6[1] = v7 | 2;
  *(int *)((char *)v6 + v7 + 4) = 7;
  *(int *)((char *)v6 + v7 + 8) = 0;
  if ( v4 < m->least_addr )
    m->least_addr = v4;
  m->footprint += v3;
  footprint = m->footprint;
  if ( footprint > m->max_footprint )
    m->max_footprint = footprint;
  return v6 + 2;
}
