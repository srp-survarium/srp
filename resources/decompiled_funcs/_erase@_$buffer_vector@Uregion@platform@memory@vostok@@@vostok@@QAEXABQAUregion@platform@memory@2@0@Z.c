void __usercall vostok::buffer_vector<vostok::memory::platform::region>::erase(
        vostok::buffer_vector<vostok::memory::platform::region> *this@<edx>,
        vostok::memory::platform::region *const *begin@<edi>,
        vostok::memory::platform::region *const *end@<eax>)
{
  _QWORD *v3; // ecx
  int v5; // eax

  v3 = *begin;
  v5 = (int)*end;
  if ( *begin != (vostok::memory::platform::region *const)v5 )
  {
    for ( ; (vostok::memory::platform::region *)v5 != this->m_end; v3 += 2 )
    {
      if ( v3 )
      {
        *v3 = *(_QWORD *)v5;
        v3[1] = *(_QWORD *)(v5 + 8);
      }
      v5 += 16;
    }
    this->m_end = &this->m_begin[this->m_end - this->m_begin - (*end - *begin)];
  }
}
