vostok::fixed_vector<int,4096> *__usercall vostok::uninitialized_reference<vostok::fixed_vector<int,4096>>::operator->@<eax>(
        vostok::uninitialized_reference<vostok::fixed_vector<int,4096> > *this@<ecx>,
        int a2@<eax>)
{
  return *(vostok::fixed_vector<int,4096> **)(a2 + 16392);
}


vostok::fixed_vector<int,4096> *__usercall vostok::uninitialized_reference<vostok::fixed_vector<int,4096>>::operator+@<eax>(
        vostok::uninitialized_reference<vostok::fixed_vector<int,4096> > *this@<ecx>,
        int a2@<eax>)
{
  _InterlockedExchange((volatile __int32 *)(a2 + 16396), 1);
  return *(vostok::fixed_vector<int,4096> **)(a2 + 16392);
}
