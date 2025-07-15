BOOL __cdecl sys_trim(malloc_state *m, unsigned int pad)
{
  char *top; // esi
  unsigned int topsize; // eax
  unsigned int v5; // edi
  malloc_segment *v6; // eax
  unsigned int sflags; // ecx
  unsigned int size; // ecx
  char *base; // eax
  malloc_segment *p_seg; // edx
  unsigned int v11; // eax
  malloc_chunk *v12; // ecx
  malloc_segment *v14; // [esp+8h] [ebp-4h]
  malloc_state *ma; // [esp+14h] [ebp+8h]
  unsigned int v16; // [esp+18h] [ebp+Ch]

  ma = 0;
  top = (char *)m->top;
  if ( top )
  {
    v16 = pad + 40;
    topsize = m->topsize;
    if ( topsize > v16 )
    {
      v5 = mparams.granularity * ((topsize - v16 + mparams.granularity - 1) / mparams.granularity - 1);
      v6 = segment_holding(m, top);
      sflags = v6->sflags;
      v14 = v6;
      if ( (sflags & 8) == 0 && (sflags & 1) != 0 )
      {
        size = v6->size;
        if ( size >= v5 )
        {
          base = v6->base;
          p_seg = &m->seg;
          while ( p_seg < (malloc_segment *)base || p_seg >= (malloc_segment *)&base[size] )
          {
            p_seg = p_seg->next;
            if ( !p_seg )
            {
              if ( !munmap(&base[size - v5], v5, (virtual_alloc_arena *)(size - v5)) )
              {
                ma = (malloc_state *)v5;
                if ( v5 )
                {
                  v14->size -= v5;
                  v11 = m->topsize;
                  v12 = m->top;
                  m->footprint -= v5;
                  init_top(m, v12, v11 - v5);
                }
              }
              break;
            }
          }
        }
      }
    }
    ma = (malloc_state *)((char *)ma + release_unused_segments(m));
    if ( !ma && m->topsize > m->trim_check )
      m->trim_check = -1;
  }
  return ma != 0;
}
