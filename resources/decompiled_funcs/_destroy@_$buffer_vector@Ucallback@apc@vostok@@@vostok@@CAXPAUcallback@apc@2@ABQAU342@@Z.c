void __usercall vostok::buffer_vector<vostok::apc::callback>::destroy(
        vostok::apc::callback *begin@<eax>,
        vostok::apc::callback **end)
{
  vostok::apc::callback *v2; // esi
  boost::detail::function::function_buffer *p_functor; // edi
  boost::detail::function::vtable_base *vtable; // eax
  void (__cdecl *v5)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax

  v2 = begin;
  if ( begin != *end )
  {
    p_functor = &begin->m_callback.functor;
    do
    {
      vtable = v2->m_callback.vtable;
      if ( v2->m_callback.vtable )
      {
        if ( ((unsigned __int8)vtable & 1) == 0 )
        {
          v5 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((unsigned int)vtable & 0xFFFFFFFE);
          if ( v5 )
            v5(p_functor, p_functor, 2);
        }
        v2->m_callback.vtable = 0;
      }
      ++v2;
      p_functor += 2;
    }
    while ( v2 != *end );
  }
}
