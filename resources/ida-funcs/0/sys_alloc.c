int *__usercall sys_alloc@<eax>(malloc_state *m@<eax>, unsigned int nb)
{
  int *result; // eax
  unsigned int v4; // eax
  unsigned int v5; // ebp
  char *v6; // edi
  unsigned int footprint; // eax
  malloc_chunk *v8; // ecx
  malloc_segment *p_seg; // ecx
  malloc_segment *v10; // eax
  unsigned int topsize; // eax
  malloc_chunk *top; // ecx
  unsigned int v13; // eax
  unsigned int sflags; // eax
  unsigned int size; // eax
  unsigned int v16; // ecx
  char *base; // ecx

  init_mparams();
  if ( (m->mflags & 1) == 0 || nb < mparams.mmap_threshold || (result = mmap_alloc(nb, m)) == 0 )
  {
    v4 = ~(mparams.granularity - 1);
    v5 = v4 & (mparams.granularity + nb + 40);
    if ( v5 > nb )
    {
      v6 = (char *)mmap(v4 & (mparams.granularity + nb + 40));
      if ( v6 != (char *)-1 )
      {
        m->footprint += v5;
        footprint = m->footprint;
        if ( footprint > m->max_footprint )
          m->max_footprint = footprint;
        if ( m->top )
        {
          p_seg = &m->seg;
          if ( m == (malloc_state *)-444 )
            goto LABEL_15;
          while ( v6 != &p_seg->base[p_seg->size] )
          {
            p_seg = p_seg->next;
            if ( !p_seg )
              goto LABEL_15;
          }
          sflags = p_seg->sflags;
          if ( (sflags & 8) != 0
            || (sflags & 1) == 0
            || m->top < (malloc_chunk *)p_seg->base
            || (size = p_seg->size, m->top >= (malloc_chunk *)&p_seg->base[size]) )
          {
LABEL_15:
            if ( v6 < m->least_addr )
              m->least_addr = v6;
            v10 = &m->seg;
            if ( m != (malloc_state *)-444 )
            {
              while ( v10->base != &v6[v5] )
              {
                v10 = v10->next;
                if ( !v10 )
                  goto LABEL_20;
              }
              v16 = v10->sflags;
              if ( (v16 & 8) == 0 && (v16 & 1) != 0 )
              {
                base = v10->base;
                v10->size += v5;
                v10->base = v6;
                return (int *)prepend_alloc(v6, nb, (malloc_tree_chunk *)m, base);
              }
            }
LABEL_20:
            add_segment(m, v6, v5, 1u);
          }
          else
          {
            p_seg->size = v5 + size;
            init_top(m, m->top, v5 + m->topsize);
          }
        }
        else
        {
          m->magic = mparams.magic;
          m->least_addr = v6;
          m->seg.base = v6;
          m->seg.size = v5;
          m->seg.sflags = 1;
          m->release_checks = 255;
          init_bins(m);
          if ( m == &gm_ )
          {
            init_top(m, (malloc_chunk *)v6, v5 - 40);
          }
          else
          {
            v8 = (malloc_chunk *)((char *)m + ((int)m[-1].out_of_memory_parameter & 0xFFFFFFF8) - 8);
            init_top(m, v8, v6 - (char *)v8 + v5 - 40);
          }
        }
        topsize = m->topsize;
        if ( nb < topsize )
        {
          top = m->top;
          v13 = topsize - nb;
          m->topsize = v13;
          m->top = (malloc_chunk *)((char *)top + nb);
          *(unsigned int *)((char *)&top->head + nb) = v13 | 1;
          top->head = nb | 3;
          return (int *)&top->fd;
        }
      }
    }
    return 0;
  }
  return result;
}
