void __userpurge boost::function1<void,vostok::network_core::packet_reader &>::swap(
        boost::function2<void,unsigned int,unsigned int> *other@<esi>,
        boost::function<void __cdecl(unsigned int,float,float,char const *)> *a2@<ecx>,
        boost::function2<void,unsigned int,unsigned int> *this)
{
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v3; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v4; // ecx
  void (__cdecl *v5)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::function2<void,unsigned int,unsigned int> tmp; // [esp+8h] [ebp-20h] BYREF

  if ( other != this )
  {
    tmp.vtable = 0;
    boost::function1<void,vostok::resources::query_result *>::move_assign(&tmp, this, a2);
    boost::function1<void,vostok::resources::query_result *>::move_assign(this, other, v3);
    boost::function1<void,vostok::resources::query_result *>::move_assign(other, &tmp, v4);
    if ( tmp.vtable )
    {
      if ( ((int)tmp.vtable & 1) == 0 )
      {
        v5 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)tmp.vtable & 0xFFFFFFFE);
        if ( v5 )
          v5(&tmp.functor, &tmp.functor, 2);
      }
    }
  }
}
