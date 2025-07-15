void __usercall stlp_std::reverse<char *>(char *__first@<ecx>, char *__last@<eax>)
{
  char v2; // dl

  for ( ; __first < __last; *__last = v2 )
  {
    v2 = *__first;
    *__first++ = *--__last;
  }
}


void __usercall stlp_std::reverse<vostok::memory::platform::region *>(
        vostok::memory::platform::region *__first@<ecx>,
        vostok::memory::platform::region *__last@<eax>)
{
  vostok::memory::platform::region v2; // [esp+0h] [ebp-10h]

  for ( ; __first < __last; ++__first )
  {
    v2 = *__first;
    *__first = *--__last;
    *__last = v2;
  }
}
