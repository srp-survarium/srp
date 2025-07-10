void __usercall stlp_std::sort<vostok::memory::platform::region *>(
        vostok::memory::platform::region *__first@<edi>,
        vostok::memory::platform::region *__last@<esi>,
        stlp_std::less<vostok::memory::platform::region> a3@<cl>)
{
  int v3; // eax
  int i; // ecx

  if ( __first != __last )
  {
    v3 = __last - __first;
    for ( i = 0; v3 != 1; ++i )
      v3 >>= 1;
    stlp_std::priv::__introsort_loop<vostok::memory::platform::region *,vostok::memory::platform::region,int,stlp_std::less<vostok::memory::platform::region>>(
      __first,
      __last,
      0,
      2 * i,
      a3);
    stlp_std::priv::__final_insertion_sort<vostok::memory::platform::region *,stlp_std::less<vostok::memory::platform::region>>(
      __first,
      __last,
      a3);
  }
}
