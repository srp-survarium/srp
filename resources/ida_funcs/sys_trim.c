BOOL __usercall sys_trim@<eax>(malloc_state *m@<eax>, unsigned int pad@<ecx>)
{
  char *top; // ebx
  unsigned int v4; // edx
  unsigned int topsize; // eax
  unsigned int v6; // ecx
  unsigned int v7; // edi
  malloc_segment *v8; // ebx
  unsigned int sflags; // eax
  unsigned int size; // ebp
  unsigned int v11; // edx
  malloc_chunk *v12; // ecx
  unsigned int released; // [esp+8h] [ebp-4h]

  top = (char *)m->top;
  v4 = 0;
  released = 0;
  if ( top )
  {
    topsize = m->topsize;
    v6 = pad + 40;
    if ( topsize > v6 )
    {
      v7 = mparams.granularity * ((topsize - v6 + mparams.granularity - 1) / mparams.granularity - 1);
      v8 = segment_holding(m, top);
      sflags = v8->sflags;
      if ( (sflags & 8) == 0 && (sflags & 1) != 0 )
      {
        size = v8->size;
        if ( size >= v7 && !has_segment_link(m, v8) && !munmap((virtual_alloc_arena *)v7, &v8->base[size - v7], v7) )
        {
          released = v7;
          if ( v7 )
          {
            v8->size -= v7;
            v11 = m->topsize;
            v12 = m->top;
            m->footprint -= v7;
            init_top(m, v12, v11 - v7);
          }
        }
      }
    }
    v4 = release_unused_segments(m) + released;
    if ( !v4 && m->topsize > m->trim_check )
      m->trim_check = -1;
  }
  return v4 != 0;
}
