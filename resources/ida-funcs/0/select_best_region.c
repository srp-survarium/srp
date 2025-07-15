unsigned __int64 __usercall select_best_region@<edx:eax>(
        vostok::buffer_vector<vostok::memory::platform::region> *resource_arenas@<eax>,
        unsigned __int64 largest_but_two,
        unsigned __int64 largest_but_one,
        unsigned __int64 largest,
        unsigned __int64 allocation_granularity)
{
  vostok::memory::platform::region *m_begin; // edx
  unsigned int v6; // esi
  vostok::memory::platform::region *v7; // eax
  unsigned int v8; // ecx
  unsigned int size_high; // edi
  unsigned int size; // ecx
  unsigned int v11; // ebx
  unsigned int v12; // esi
  unsigned __int64 result; // rax
  unsigned __int64 v14; // rax
  float v15; // [esp+24h] [ebp-4h]
  float v16; // [esp+34h] [ebp+Ch]

  m_begin = resource_arenas->m_begin;
  v6 = HIDWORD(largest);
  v7 = resource_arenas->m_end - 1;
  if ( HIDWORD(largest) <= HIDWORD(largest_but_one) )
  {
    v8 = largest;
    if ( HIDWORD(largest) < HIDWORD(largest_but_one) || (unsigned int)largest < (unsigned int)largest_but_one )
    {
      largest = largest_but_one;
      largest_but_one = __PAIR64__(v6, v8);
    }
  }
  if ( largest_but_one < largest_but_two )
    largest_but_one = largest_but_two;
  size_high = HIDWORD(v7->size);
  size = m_begin->size;
  v11 = v7->size;
  v12 = HIDWORD(m_begin->size);
  result = v7->size + m_begin->size;
  if ( largest < result && (largest < __PAIR64__(size_high, v11) || largest_but_one < __PAIR64__(v12, size)) )
  {
    v16 = (float)largest;
    if ( (double)__PAIR64__(v12, size) / (double)result * v16 < (double)largest_but_one )
    {
      v15 = (double)__PAIR64__(v12, size) / (double)__PAIR64__(size_high, v11);
      v14 = vostok::math::align_up<unsigned __int64>(
              (unsigned __int64)((double)largest_but_one * v15),
              allocation_granularity);
      if ( v14 <= largest )
        return largest_but_one + v14;
      else
        return largest + vostok::math::align_up<unsigned __int64>((unsigned __int64)(v16 * v15), allocation_granularity);
    }
    else
    {
      return largest;
    }
  }
  return result;
}
