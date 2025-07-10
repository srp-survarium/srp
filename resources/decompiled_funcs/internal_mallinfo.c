mallinfo *__usercall internal_mallinfo@<eax>(mallinfo *a1@<eax>, malloc_state *result)
{
  malloc_state *v2; // edx
  unsigned int top; // esi
  unsigned int topsize; // edi
  malloc_segment *p_seg; // ebx
  unsigned int v6; // esi
  unsigned int v7; // ebp
  unsigned int base; // edi
  int v9; // ecx
  unsigned int v10; // edx
  int v11; // esi
  unsigned int footprint; // ecx
  unsigned int max_footprint; // edx
  malloc_segment *s; // [esp+4h] [ebp-18h]
  unsigned int mfree; // [esp+8h] [ebp-14h]
  unsigned int nfree; // [esp+Ch] [ebp-10h]
  unsigned int v17; // [esp+10h] [ebp-Ch]
  unsigned int v18; // [esp+14h] [ebp-8h]

  v2 = result;
  top = (unsigned int)result->top;
  a1->arena = 0;
  a1->ordblks = 0;
  a1->smblks = 0;
  a1->hblks = 0;
  a1->hblkhd = 0;
  a1->usmblks = 0;
  a1->fsmblks = 0;
  a1->uordblks = 0;
  a1->fordblks = 0;
  a1->keepcost = 0;
  v18 = top;
  if ( top )
  {
    topsize = result->topsize;
    p_seg = &result->seg;
    v6 = topsize + 40;
    nfree = 1;
    mfree = topsize + 40;
    v7 = topsize + 40;
    s = &result->seg;
    if ( result != (malloc_state *)-444 )
    {
      do
      {
        base = (unsigned int)p_seg->base;
        v9 = (int)p_seg->base & 7;
        if ( v9 )
          v9 = -v9 & 7;
        v10 = base + v9;
        if ( base + v9 >= base )
        {
          v17 = base + p_seg->size;
          do
          {
            if ( v10 >= v17 )
              break;
            if ( v10 == v18 )
              break;
            v11 = *(_DWORD *)(v10 + 4);
            if ( v11 == 7 )
              break;
            v7 += v11 & 0xFFFFFFF8;
            if ( (v11 & 2) == 0 )
            {
              mfree += v11 & 0xFFFFFFF8;
              ++nfree;
            }
            p_seg = s;
            v10 += v11 & 0xFFFFFFF8;
          }
          while ( v10 >= base );
        }
        p_seg = p_seg->next;
        s = p_seg;
      }
      while ( p_seg );
      v6 = mfree;
      v2 = result;
      topsize = result->topsize;
    }
    a1->ordblks = nfree;
    footprint = v2->footprint;
    max_footprint = v2->max_footprint;
    a1->keepcost = topsize;
    a1->arena = v7;
    a1->hblkhd = footprint - v7;
    a1->usmblks = max_footprint;
    a1->uordblks = footprint - v6;
    a1->fordblks = v6;
  }
  return a1;
}
