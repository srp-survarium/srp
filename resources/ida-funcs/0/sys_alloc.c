char *__usercall sys_alloc@<eax>(malloc_state *m@<eax>, unsigned int nb)
{
  unsigned int v3; // ebx
  char *result; // eax
  unsigned int v6; // eax
  unsigned int v7; // edi
  char *v8; // ecx
  unsigned int footprint; // eax
  malloc_chunk **smallbins; // eax
  bool v11; // zf
  unsigned int v12; // eax
  malloc_segment *p_seg; // edx
  unsigned int sflags; // eax
  unsigned int size; // eax
  malloc_segment *v16; // eax
  unsigned int v17; // edx
  char *base; // edx
  unsigned int topsize; // eax
  malloc_chunk *top; // ecx
  unsigned int v21; // eax
  int v22; // [esp+8h] [ebp-4h]

  v3 = nb;
  init_mparams();
  if ( (m->mflags & 1) == 0 || nb < mparams.mmap_threshold || (result = (char *)mmap_alloc(m)) == 0 )
  {
    v6 = ~(mparams.granularity - 1);
    v7 = v6 & (mparams.granularity + nb + 40);
    if ( v7 <= nb )
      return 0;
    v8 = (char *)mmap(v6 & (mparams.granularity + nb + 40));
    if ( v8 == (char *)-1 )
      return 0;
    m->footprint += v7;
    footprint = m->footprint;
    if ( footprint > m->max_footprint )
      m->max_footprint = footprint;
    if ( m->top )
    {
      p_seg = &m->seg;
      if ( m != (malloc_state *)-444 )
      {
        do
        {
          if ( v8 == &p_seg->base[p_seg->size] )
            break;
          p_seg = p_seg->next;
        }
        while ( p_seg );
        if ( p_seg )
        {
          sflags = p_seg->sflags;
          if ( (sflags & 8) == 0 && (sflags & 1) != 0 )
          {
            if ( m->top >= (malloc_chunk *)p_seg->base )
            {
              size = p_seg->size;
              if ( m->top < (malloc_chunk *)&p_seg->base[size] )
              {
                p_seg->size = v7 + size;
                init_top(m, m->top, v7 + m->topsize);
                v3 = nb;
                goto LABEL_35;
              }
            }
            v3 = nb;
          }
        }
      }
      if ( v8 < m->least_addr )
        m->least_addr = v8;
      v16 = &m->seg;
      if ( m != (malloc_state *)-444 )
      {
        do
        {
          if ( v16->base == &v8[v7] )
            break;
          v16 = v16->next;
        }
        while ( v16 );
        if ( v16 )
        {
          v17 = v16->sflags;
          if ( (v17 & 8) == 0 && (v17 & 1) != 0 )
          {
            base = v16->base;
            v16->size += v7;
            v16->base = v8;
            return prepend_alloc(m, v3, v8, base);
          }
        }
      }
      add_segment(m, (malloc_chunk *)v8, v7, 1u);
    }
    else
    {
      m->magic = mparams.magic;
      m->least_addr = v8;
      m->seg.base = v8;
      m->seg.size = v7;
      m->seg.sflags = 1;
      m->release_checks = 255;
      smallbins = m->smallbins;
      v22 = 32;
      do
      {
        v11 = v22-- == 1;
        smallbins[3] = (malloc_chunk *)smallbins;
        smallbins[2] = (malloc_chunk *)smallbins;
        smallbins += 2;
      }
      while ( !v11 );
      if ( m == &gm_ )
      {
        v12 = v7 - 40;
      }
      else
      {
        v12 = v8 - ((char *)m + ((int)m[-1].out_of_memory_parameter & 0xFFFFFFF8) - 8) + v7 - 40;
        v8 = (char *)m + ((int)m[-1].out_of_memory_parameter & 0xFFFFFFF8) - 8;
      }
      init_top(m, (malloc_chunk *)v8, v12);
    }
LABEL_35:
    topsize = m->topsize;
    if ( v3 < topsize )
    {
      top = m->top;
      v21 = topsize - v3;
      m->topsize = v21;
      m->top = (malloc_chunk *)((char *)top + v3);
      *(unsigned int *)((char *)&top->head + v3) = v21 | 1;
      top->head = v3 | 3;
      return (char *)&top->fd;
    }
    return 0;
  }
  return result;
}
