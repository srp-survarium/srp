void __cdecl vostok::resources::set_resource_freed_callback(
        boost::function<void __cdecl(vostok::resources::query_result *,vostok::resources::memory_usage_type const &,enum vostok::resources::class_id_enum)> callback)
{
  void (__cdecl *v1)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax

  boost::function<void __cdecl (vostok::resources::query_result *,vostok::resources::memory_usage_type const &,enum vostok::resources::class_id_enum)>::operator=(&callback);
  if ( callback.vtable && ((int)callback.vtable & 1) == 0 )
  {
    v1 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)callback.vtable & 0xFFFFFFFE);
    if ( v1 )
      v1(&callback.functor, &callback.functor, 2);
  }
}
