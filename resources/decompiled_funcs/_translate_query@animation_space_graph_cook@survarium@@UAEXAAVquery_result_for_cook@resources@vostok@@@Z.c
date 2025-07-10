void __userpurge survarium::animation_space_graph_cook::translate_query(
        survarium::animation_space_graph_cook *this@<ecx>,
        int a2@<esi>,
        vostok::resources::query_result_for_cook *parent)
{
  char *m_requery_path; // eax
  void (__cdecl *v4)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::animation_space_graph_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::animation_space_graph_cook *>,boost::arg<1> > > v5; // [esp-10h] [ebp-48h]
  int v6; // [esp+0h] [ebp-38h]
  vostok::variant<32> *user_data; // [esp+4h] [ebp-34h] BYREF
  vostok::resources::request requests; // [esp+8h] [ebp-30h] BYREF
  __int64 v9; // [esp+10h] [ebp-28h]
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+18h] [ebp-20h] BYREF

  requests.path = (const char *)survarium::animation_space_graph_cook::on_options_received;
  requests.id = unknown_data_class;
  v5.f_.f_ = (void (__thiscall *__ptr64)(survarium::animation_space_graph_cook *, vostok::resources::queries_result *))(unsigned int)survarium::animation_space_graph_cook::on_options_received;
  LODWORD(v9) = this;
  *(_QWORD *)&v5.l_.a1_.t_ = v9;
  boost::function1<void,vostok::resources::queries_result &>::function1<void,vostok::resources::queries_result &>(
    (boost::function1<void,vostok::resources::queries_result &> *)this,
    (int)&callback,
    a2,
    v5,
    v6);
  m_requery_path = parent->m_requery_path;
  if ( !m_requery_path )
    m_requery_path = parent->m_request_path;
  requests.path = m_requery_path;
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
