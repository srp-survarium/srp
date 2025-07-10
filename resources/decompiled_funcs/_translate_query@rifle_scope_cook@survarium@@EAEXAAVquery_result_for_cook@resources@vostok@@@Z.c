void __thiscall survarium::rifle_scope_cook::translate_query(
        survarium::rifle_scope_cook *this,
        vostok::resources::query_result_for_cook *parent)
{
  char *m_requery_path; // eax
  void (__cdecl *v4)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::rifle_scope_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::rifle_scope_cook *>,boost::arg<1> > > v5; // [esp-10h] [ebp-168h]
  int v6; // [esp+0h] [ebp-158h]
  vostok::resources::request requests; // [esp+8h] [ebp-150h] BYREF
  __int64 v8; // [esp+10h] [ebp-148h]
  vostok::variant<32> *user_data; // [esp+1Ch] [ebp-13Ch] BYREF
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+20h] [ebp-138h] BYREF
  vostok::fs_new::virtual_path_string config_name; // [esp+40h] [ebp-118h] BYREF

  config_name.m_string.m_begin = config_name.m_string.m_buffer;
  m_requery_path = parent->m_requery_path;
  config_name.m_string.m_end = config_name.m_string.m_buffer;
  config_name.m_string.m_max_end = &config_name.m_separator;
  config_name.m_string.m_buffer[0] = 0;
  config_name.m_separator = 47;
  if ( !m_requery_path )
    m_requery_path = parent->m_request_path;
  vostok::fs_new::path_string_impl::assignf(&config_name, "resources/%s", m_requery_path);
  v5.f_.f_ = (void (__thiscall *__ptr64)(survarium::rifle_scope_cook *, vostok::resources::queries_result *))(unsigned int)survarium::rifle_scope_cook::on_config_loaded;
  LODWORD(v8) = this;
  *(_QWORD *)&v5.l_.a1_.t_ = v8;
  boost::function1<void,vostok::resources::queries_result &>::function1<void,vostok::resources::queries_result &>(
    0,
    (int)&callback,
    (int)parent,
    v5,
    v6);
  requests.path = config_name.m_string.m_begin;
  requests.id = binary_config_class_impl;
  user_data = 0;
  vostok::resources::query_resources(
    &requests,
    1u,
    (boost::function4<void,unsigned int,float,float,char const *> *)&callback,
    (vostok::memory::base_allocator *)survarium::g_allocator.f_.f_,
    (const vostok::variant<32> **)&user_data,
    parent,
    assert_on_fail_true);
  if ( callback.vtable && ((int)callback.vtable & 1) == 0 )
  {
    v4 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)callback.vtable & 0xFFFFFFFE);
    if ( v4 )
      v4(&callback.functor, &callback.functor, 2);
  }
}
