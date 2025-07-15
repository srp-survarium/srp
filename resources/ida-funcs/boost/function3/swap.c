void __usercall boost::function3<void,vostok::resources::query_result *,vostok::resources::memory_usage_type const &,enum vostok::resources::class_id_enum>::swap(
        boost::function3<void,vostok::resources::query_result *,vostok::resources::memory_usage_type const &,enum vostok::resources::class_id_enum> *this@<ecx>,
        boost::function2<void,unsigned int,unsigned int> *a2@<esi>)
{
  void (__cdecl *v2)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::function3<void,vostok::resources::query_result *,vostok::resources::memory_usage_type const &,enum vostok::resources::class_id_enum> tmp; // [esp+8h] [ebp-24h] BYREF

  if ( a2 != (boost::function2<void,unsigned int,unsigned int> *)&s_resource_freed_callback )
  {
    tmp.vtable = 0;
    boost::function1<void,vostok::resources::query_result *>::move_assign(
      (boost::function2<void,unsigned int,unsigned int> *)&tmp,
      a2);
    boost::function1<void,vostok::resources::query_result *>::move_assign(
      a2,
      (boost::function2<void,unsigned int,unsigned int> *)&s_resource_freed_callback);
    boost::function1<void,vostok::resources::query_result *>::move_assign(
      (boost::function2<void,unsigned int,unsigned int> *)&s_resource_freed_callback,
      (boost::function2<void,unsigned int,unsigned int> *)&tmp);
    if ( tmp.vtable )
    {
      if ( ((int)tmp.vtable & 1) == 0 )
      {
        v2 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)tmp.vtable & 0xFFFFFFFE);
        if ( v2 )
          v2(&tmp.functor, &tmp.functor, 2);
      }
    }
  }
}
