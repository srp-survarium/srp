void __cdecl vostok::resources::set_query_finished_callback(
        boost::function<void __cdecl(vostok::resources::resource_base *)> callback)
{
  void (__cdecl *v1)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  void (__cdecl *v2)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::function<void __cdecl(unsigned int,unsigned int)> v3; // [esp+8h] [ebp-24h] BYREF

  boost::function2<void,unsigned int,unsigned int>::function2<void,unsigned int,unsigned int>(
    (boost::function4<void,unsigned int,float,float,char const *> *)&callback,
    (int)&v3);
  boost::function<void __cdecl (unsigned char,vostok::network_core::packet_reader &)>::operator=(
    &v3,
    (boost::function2<void,unsigned int,unsigned int> *)((char *)&dword_205B0
                                                       + (unsigned int)vostok::resources::g_resources_manager.m_variable));
  if ( v3.vtable )
  {
    if ( ((int)v3.vtable & 1) == 0 )
    {
      v1 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)v3.vtable & 0xFFFFFFFE);
      if ( v1 )
        v1(&v3.functor, &v3.functor, 2);
    }
  }
  if ( callback.vtable && ((int)callback.vtable & 1) == 0 )
  {
    v2 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)callback.vtable & 0xFFFFFFFE);
    if ( v2 )
      v2(&callback.functor, &callback.functor, 2);
  }
}
