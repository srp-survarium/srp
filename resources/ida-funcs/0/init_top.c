void __usercall init_top(malloc_state *m@<esi>, malloc_chunk *p@<ecx>, unsigned int psize@<eax>)
{
  int v4; // eax
  unsigned int v5; // edi
  malloc_chunk *v6; // ecx
  unsigned int trim_threshold; // eax

  v4 = ((unsigned __int8)p & 7) != 0 ? -((unsigned __int8)p & 7) & 7 : 0;
  v5 = psize - v4;
  v6 = (malloc_chunk *)((char *)p + v4);
  m->topsize = v5;
  m->top = v6;
  v6->head = v5 | 1;
  trim_threshold = mparams.trim_threshold;
  *(unsigned int *)((char *)&v6->head + v5) = 40;
  m->trim_check = trim_threshold;
}
