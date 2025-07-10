void __thiscall vostok::core::configs::binary_config_cook::translate_query(
        vostok::core::configs::binary_config_cook *this,
        vostok::resources::query_result_for_cook *parent)
{
  char *m_requery_path; // eax
  void (__cdecl *v4)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::core::configs::binary_config_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::core::configs::binary_config_cook *>,boost::arg<1> > > v5; // [esp-8h] [ebp-278h]
  char *other; // [esp+Ch] [ebp-264h] BYREF
  vostok::resources::request fs_iterator_requests[2]; // [esp+10h] [ebp-260h] BYREF
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+20h] [ebp-250h] BYREF
  vostok::fs_new::virtual_path_string source_path; // [esp+40h] [ebp-230h] BYREF
  vostok::fs_new::virtual_path_string converted_path; // [esp+158h] [ebp-118h] BYREF

  m_requery_path = parent->m_requery_path;
  if ( !m_requery_path )
    m_requery_path = parent->m_request_path;
  other = m_requery_path;
  vostok::fs_new::virtual_path_string::virtual_path_string(&converted_path, (const char **)&other);
  source_path.m_string.m_max_end = &source_path.m_separator;
  source_path.m_string.m_begin = source_path.m_string.m_buffer;
  source_path.m_string.m_end = source_path.m_string.m_buffer;
  source_path.m_string.m_buffer[0] = 0;
  source_path.m_separator = 47;
  vostok::core::configs::make_source_path(&source_path, &converted_path);
  fs_iterator_requests[0].id = fs_iterator_class;
  fs_iterator_requests[1].id = fs_iterator_class;
  v5.l_.a1_.t_ = this;
  v5.f_.f_ = vostok::core::configs::binary_config_cook::on_fs_iterators_ready;
  fs_iterator_requests[0].path = source_path.m_string.m_begin;
  fs_iterator_requests[1].path = converted_path.m_string.m_begin;
  callback.vtable = 0;
  boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::core::configs::binary_config_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::core::configs::binary_config_cook *>,boost::arg<1>>>>(
    (boost::function1<void,vostok::resources::queries_result &> *)source_path.m_string.m_begin,
    (boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::core::configs::binary_config_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::core::configs::binary_config_cook *>,boost::arg<1> > > *)&callback,
    v5);
  vostok::resources::query_resources(
    fs_iterator_requests,
    2u,
    (boost::function4<void,unsigned int,float,float,char const *> *)&callback,
    &vostok::memory::g_resources_helper_allocator,
    0,
    parent,
    assert_on_fail_true);
  if ( callback.vtable && ((int)callback.vtable & 1) == 0 )
  {
    v4 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)callback.vtable & 0xFFFFFFFE);
    if ( v4 )
      v4(&callback.functor, &callback.functor, 2);
  }
}
