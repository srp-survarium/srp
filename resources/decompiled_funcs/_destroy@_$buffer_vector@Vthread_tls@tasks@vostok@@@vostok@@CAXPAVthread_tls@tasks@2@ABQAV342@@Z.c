void __cdecl vostok::buffer_vector<vostok::tasks::thread_tls>::destroy(
        vostok::tasks::thread_tls *begin,
        vostok::tasks::thread_tls **end)
{
  vostok::tasks::thread_tls *v2; // ebp
  boost::detail::function::function_buffer *p_functor; // esi
  unsigned int obj_ptr; // eax
  void (__cdecl *v5)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax

  v2 = begin;
  if ( begin != *end )
  {
    p_functor = &begin->user_thread_root_task.m_function.functor;
    do
    {
      CloseHandle(p_functor[2].bound_memfunc_ptr.obj_ptr);
      CloseHandle(p_functor[2].vostok_pointer_size_alignment[2]);
      CloseHandle(p_functor[2].obj_ptr);
      obj_ptr = (unsigned int)p_functor[-1].bound_memfunc_ptr.obj_ptr;
      if ( obj_ptr )
      {
        if ( (obj_ptr & 1) == 0 )
        {
          v5 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))(obj_ptr & 0xFFFFFFFE);
          if ( v5 )
            v5(p_functor, p_functor, 2);
        }
        p_functor[-1].bound_memfunc_ptr.obj_ptr = 0;
      }
      CloseHandle(p_functor[-6].bound_memfunc_ptr.obj_ptr);
      ++v2;
      p_functor += 15;
    }
    while ( v2 != *end );
  }
}
