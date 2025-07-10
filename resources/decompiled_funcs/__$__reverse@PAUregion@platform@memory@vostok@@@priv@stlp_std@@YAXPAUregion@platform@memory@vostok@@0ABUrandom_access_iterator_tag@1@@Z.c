void __usercall stlp_std::priv::__reverse<vostok::memory::platform::region *>(
        vostok::memory::platform::region *__first@<ecx>,
        vostok::memory::platform::region *__last@<eax>)
{
  unsigned __int64 size; // xmm0_8
  __int64 v3; // xmm1_8
  unsigned __int64 v4; // xmm2_8

  for ( ; __first < __last; *(_QWORD *)&__last->address = v3 )
  {
    size = __first->size;
    v3 = *(_QWORD *)&__first->address;
    v4 = __last[-1].size;
    --__last;
    __first->size = v4;
    *(_QWORD *)&__first->address = *(_QWORD *)&__last->address;
    ++__first;
    __last->size = size;
  }
}
