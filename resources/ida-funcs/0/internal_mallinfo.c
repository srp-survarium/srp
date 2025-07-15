mallinfo *__usercall internal_mallinfo@<eax>(malloc_state *m@<edx>, mallinfo *result@<eax>)
{
  unsigned int topsize; // esi
  unsigned int v3; // edi
  malloc_segment *p_seg; // ecx
  char *base; // esi
  int v6; // edi
  malloc_chunk *v7; // edi
  unsigned int head; // esi
  unsigned int v9; // esi
  unsigned int footprint; // ecx
  unsigned int max_footprint; // edx
  unsigned int v12; // [esp+10h] [ebp-10h]
  unsigned int v13; // [esp+14h] [ebp-Ch]
  unsigned int v14; // [esp+18h] [ebp-8h]
  unsigned int v15; // [esp+1Ch] [ebp-4h]

  result->arena = 0;
  result->ordblks = 0;
  result->smblks = 0;
  result->hblks = 0;
  result->hblkhd = 0;
  result->usmblks = 0;
  result->fsmblks = 0;
  result->uordblks = 0;
  result->fordblks = 0;
  result->keepcost = 0;
  if ( m->top )
  {
    topsize = m->topsize;
    v3 = topsize + 40;
    p_seg = &m->seg;
    v13 = 1;
    v14 = topsize + 40;
    v15 = topsize + 40;
    if ( m != (malloc_state *)-444 )
    {
      do
      {
        base = p_seg->base;
        v6 = (int)p_seg->base & 7;
        if ( v6 )
          v6 = -v6 & 7;
        v7 = (malloc_chunk *)&base[v6];
        if ( v7 >= (malloc_chunk *)base )
        {
          v12 = (unsigned int)&base[p_seg->size];
          do
          {
            if ( (unsigned int)v7 >= v12 )
              break;
            if ( v7 == m->top )
              break;
            head = v7->head;
            if ( head == 7 )
              break;
            v9 = head & 0xFFFFFFF8;
            v15 += v9;
            if ( (v7->head & 2) == 0 )
            {
              v14 += v9;
              ++v13;
            }
            v7 = (malloc_chunk *)((char *)v7 + (v7->head & 0xFFFFFFF8));
          }
          while ( (char *)v7 >= p_seg->base );
        }
        p_seg = p_seg->next;
      }
      while ( p_seg );
      v3 = v14;
      topsize = m->topsize;
    }
    result->arena = v15;
    result->ordblks = v13;
    footprint = m->footprint;
    max_footprint = m->max_footprint;
    result->fordblks = v3;
    result->keepcost = topsize;
    result->hblkhd = footprint - v15;
    result->usmblks = max_footprint;
    result->uordblks = footprint - v3;
  }
  return result;
}
