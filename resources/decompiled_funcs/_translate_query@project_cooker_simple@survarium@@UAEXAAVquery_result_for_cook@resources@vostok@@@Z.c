void __thiscall survarium::project_cooker_simple::translate_query(
        survarium::project_cooker_simple *this,
        vostok::resources::query_result_for_cook *parent)
{
  char *m_requery_path; // eax
  boost::_bi::list3<boost::_bi::value<survarium::project_cooker_simple *>,boost::arg<1>,boost::_bi::value<vostok::resources::query_result_for_cook *> > v3; // rdi
  void (__cdecl *v4)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::project_cooker_simple,vostok::resources::queries_result &,vostok::resources::query_result_for_cook *>,boost::_bi::list3<boost::_bi::value<survarium::project_cooker_simple *>,boost::arg<1>,boost::_bi::value<vostok::resources::query_result_for_cook *> > > v5; // [esp-10h] [ebp-280h]
  int v6; // [esp+0h] [ebp-270h]
  char *other; // [esp+Ch] [ebp-264h] BYREF
  vostok::resources::request requests; // [esp+10h] [ebp-260h] BYREF
  boost::_bi::list3<boost::_bi::value<survarium::project_cooker_simple *>,boost::arg<1>,boost::_bi::value<vostok::resources::query_result_for_cook *> > v9; // [esp+18h] [ebp-258h]
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+20h] [ebp-250h] BYREF
  vostok::fs_new::virtual_path_string game_proj_path; // [esp+40h] [ebp-230h] BYREF
  vostok::fs_new::virtual_path_string project_name; // [esp+158h] [ebp-118h] BYREF

  m_requery_path = parent->m_requery_path;
  v3 = (boost::_bi::list3<boost::_bi::value<survarium::project_cooker_simple *>,boost::arg<1>,boost::_bi::value<vostok::resources::query_result_for_cook *> >)__PAIR64__((unsigned int)parent, (unsigned int)this);
  if ( !m_requery_path )
    m_requery_path = parent->m_request_path;
  other = m_requery_path;
  vostok::fs_new::virtual_path_string::virtual_path_string(&project_name, (const char **)&other);
  game_proj_path.m_string.m_begin = game_proj_path.m_string.m_buffer;
  game_proj_path.m_string.m_end = game_proj_path.m_string.m_buffer;
  game_proj_path.m_string.m_max_end = &game_proj_path.m_separator;
  game_proj_path.m_string.m_buffer[0] = 0;
  game_proj_path.m_separator = 47;
  vostok::fs_new::path_string_impl::assignf(
    &game_proj_path,
    "%sprojects/%s/client_project",
    "resources/",
    project_name.m_string.m_begin);
  requests.path = (const char *)survarium::project_cooker_simple::on_game_project_loaded;
  requests.id = unknown_data_class;
  v5.f_.f_ = (void (__thiscall *__ptr64)(survarium::project_cooker_simple *, vostok::resources::queries_result *, vostok::resources::query_result_for_cook *))(unsigned int)survarium::project_cooker_simple::on_game_project_loaded;
  v9 = v3;
  v5.l_ = v3;
  boost::function1<void,vostok::resources::queries_result &>::function1<void,vostok::resources::queries_result &>(
    0,
    (int)&callback,
    (int)v3.a3_.t_,
    v5,
    v6);
  requests.path = game_proj_path.m_string.m_begin;
  requests.id = binary_config_class_impl;
  other = 0;
  vostok::resources::query_resources(
    &requests,
    1u,
    &callback,
    (vostok::memory::base_allocator *)survarium::g_allocator.f_.f_,
    (const vostok::variant<32> **)&other,
    v3.a3_.t_,
    assert_on_fail_true);
  if ( callback.vtable && ((int)callback.vtable & 1) == 0 )
  {
    v4 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)callback.vtable & 0xFFFFFFFE);
    if ( v4 )
      v4(&callback.functor, &callback.functor, 2);
  }
}
