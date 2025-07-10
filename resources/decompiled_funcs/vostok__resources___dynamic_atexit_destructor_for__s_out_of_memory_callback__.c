void __cdecl vostok::resources::_dynamic_atexit_destructor_for__s_out_of_memory_callback__()
{
  void (__cdecl *v0)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax

  if ( s_out_of_memory_callback.vtable )
  {
    if ( ((int)s_out_of_memory_callback.vtable & 1) == 0 )
    {
      v0 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)s_out_of_memory_callback.vtable & 0xFFFFFFFE);
      if ( v0 )
        v0(&s_out_of_memory_callback.functor, &s_out_of_memory_callback.functor, 2);
    }
    s_out_of_memory_callback.vtable = 0;
  }
}
