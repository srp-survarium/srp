void __usercall vostok::memory::detail::call_constructor<char>(char *const begin@<eax>, char *const end@<ecx>)
{
  for ( ; begin != end; ++begin )
  {
    if ( begin )
      *begin = 0;
  }
}


void __usercall vostok::memory::detail::call_constructor<unsigned int>(
        unsigned int *const begin@<eax>,
        unsigned int *const end@<ecx>)
{
  for ( ; begin != end; ++begin )
  {
    if ( begin )
      *begin = 0;
  }
}
