void __usercall vostok::logging::enumerate_filters(
        const vostok::logging::filter_tree *filter_tree@<eax>,
        boost::bad_function_call *a2@<ecx>,
        const boost::function<void __cdecl(vostok::logging::filter const &)> *callback)
{
  vostok::logging::initiator_filter *m_first; // edi
  const std::exception *v4; // eax
  boost::bad_function_call *v5; // [esp-4h] [ebp-124h]
  stlp_std::out_of_range v6; // [esp+10h] [ebp-110h] BYREF

  m_first = filter_tree->filter_stack.m_first;
  while ( m_first )
  {
    if ( !callback->vtable )
    {
      boost::bad_function_call::bad_function_call(a2, (stlp_std::runtime_error *)&v6);
      boost::throw_exception(v4);
      stlp_std::__Named_exception::~__Named_exception(&v6);
    }
    (*(void (__cdecl **)(boost::detail::function::function_buffer *, vostok::logging::filter *))(((int)callback->vtable
                                                                                                & 0xFFFFFFFE)
                                                                                               + 4))(
      &callback->functor,
      &m_first->filter);
    m_first = m_first->next;
    a2 = v5;
  }
}
