void __usercall init_top(malloc_state *m@<esi>, malloc_chunk *p@<ecx>, unsigned int psize@<edx>)
{
  int v3; // eax
  malloc_chunk *v4; // ecx
  unsigned int v5; // edx

  v3 = (unsigned __int8)p & 7;
  if ( ((unsigned __int8)p & 7) != 0 )
    v3 = -v3 & 7;
  v4 = (malloc_chunk *)((char *)p + v3);
  v5 = psize - v3;
  m->top = v4;
  m->topsize = v5;
  v4->head = v5 | 1;
  *(unsigned int *)((char *)&v4->head + v5) = 40;
  m->trim_check = mparams.trim_threshold;
}
