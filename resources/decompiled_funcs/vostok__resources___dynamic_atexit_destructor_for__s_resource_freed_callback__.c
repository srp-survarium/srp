void __cdecl vostok::resources::_dynamic_atexit_destructor_for__s_resource_freed_callback__()
{
  void (__cdecl *v0)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax

  if ( s_resource_freed_callback.vtable )
  {
    if ( ((int)s_resource_freed_callback.vtable & 1) == 0 )
    {
      v0 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)s_resource_freed_callback.vtable & 0xFFFFFFFE);
      if ( v0 )
        v0(&s_resource_freed_callback.functor, &s_resource_freed_callback.functor, 2);
    }
    s_resource_freed_callback.vtable = 0;
  }
}
