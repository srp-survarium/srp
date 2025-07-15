int __usercall select_best_region@<eax>(
        vostok::buffer_vector<vostok::memory::platform::region> *resource_arenas@<eax>,
        unsigned __int64 largest_but_two,
        unsigned __int64 largest_but_one,
        unsigned __int64 largest,
        unsigned __int64 allocation_granularity)
{
  vostok::memory::platform::region *m_begin; // ecx
  unsigned int v6; // ebx
  unsigned int v7; // ebp
  unsigned int v8; // esi
  vostok::memory::platform::region *v9; // eax
  unsigned int v10; // edx
  unsigned int size_high; // ebx
  unsigned int size; // edi
  unsigned int v13; // ecx
  unsigned __int64 v14; // rax
  double v15; // st6
  double v16; // rt1
  double v17; // st6
  unsigned __int64 share; // [esp+10h] [ebp-14h]
  float sharea; // [esp+10h] [ebp-14h]
  float largest_but_twoa; // [esp+28h] [ebp+4h]

  m_begin = resource_arenas->m_begin;
  v6 = HIDWORD(largest_but_one);
  v7 = largest_but_one;
  v8 = HIDWORD(largest);
  v9 = resource_arenas->m_end - 1;
  if ( largest < largest_but_one )
  {
    v10 = largest;
    v8 = HIDWORD(largest_but_one);
    LODWORD(largest) = largest_but_one;
    v7 = v10;
    HIDWORD(largest_but_one) = HIDWORD(largest);
    v6 = HIDWORD(largest);
  }
  if ( __PAIR64__(v6, v7) < largest_but_two )
  {
    HIDWORD(largest_but_one) = HIDWORD(largest_but_two);
    v7 = largest_but_two;
  }
  size_high = HIDWORD(v9->size);
  size = m_begin->size;
  v13 = HIDWORD(m_begin->size);
  LODWORD(share) = v9->size;
  v14 = v9->size + __PAIR64__(v13, size);
  HIDWORD(share) = size_high;
  if ( (v8 < (__PAIR64__(v13, share) + __PAIR64__(size_high, size)) >> 32
     || v8 <= (__PAIR64__(v13, share) + __PAIR64__(size_high, size)) >> 32 && (unsigned int)largest < (unsigned int)v14)
    && (v8 < size_high
     || v8 <= size_high && (unsigned int)largest < (unsigned int)share
     || HIDWORD(largest_but_one) < v13
     || HIDWORD(largest_but_one) <= v13 && v7 < size) )
  {
    v15 = (double)__PAIR64__(HIDWORD(largest_but_one), v7);
    if ( (double)__PAIR64__(v8, largest) * ((double)__PAIR64__(v13, size) / (double)v14) < v15 )
    {
      v16 = v15;
      v17 = (double)__PAIR64__(v13, size) / (double)share;
      v14 = vostok::math::align_up<unsigned __int64>((unsigned __int64)(v16 * v17), allocation_granularity);
      if ( v14 <= __PAIR64__(v8, largest) )
      {
        LODWORD(v14) = v7 + v14;
      }
      else
      {
        sharea = v17;
        largest_but_twoa = (float)__PAIR64__(v8, largest);
        return __PAIR64__(v8, largest)
             + vostok::math::align_up<unsigned __int64>(
                 (unsigned __int64)(largest_but_twoa * sharea),
                 allocation_granularity);
      }
    }
    else
    {
      LODWORD(v14) = largest;
    }
  }
  return v14;
}
