boost::function<void __cdecl(unsigned int,unsigned int)> *__usercall boost::function<void __cdecl (unsigned char,vostok::network_core::packet_reader &)>::operator=@<eax>(
        boost::function<void __cdecl(unsigned int,unsigned int)> *this@<ecx>,
        boost::function2<void,unsigned int,unsigned int> *a2@<edi>)
{
  void (__cdecl *v2)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  const boost::function4<void,unsigned int,float,float,char const *> *v4; // [esp+0h] [ebp-28h]
  boost::function2<void,unsigned int,unsigned int> v5; // [esp+8h] [ebp-20h] BYREF

  boost::function2<void,unsigned int,unsigned int>::function2<void,unsigned int,unsigned int>(
    (boost::function4<void,unsigned int,float,float,char const *> *)this,
    v4);
  boost::function1<void,vostok::network_core::packet_reader &>::swap(&v5, a2);
  if ( v5.vtable )
  {
    if ( ((int)v5.vtable & 1) == 0 )
    {
      v2 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)v5.vtable & 0xFFFFFFFE);
      if ( v2 )
        v2(&v5.functor, &v5.functor, 2);
    }
  }
  return (boost::function<void __cdecl(unsigned int,unsigned int)> *)a2;
}
