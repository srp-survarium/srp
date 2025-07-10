void __thiscall survarium::human_npc_cook::translate_query(
        survarium::human_npc_cook *this,
        vostok::resources::query_result_for_cook *parent)
{
  vostok::sound::encoded_sound_interface *m_data; // eax
  vostok::configs::binary_config_value *v4; // eax
  const char *pointer; // ebx
  vostok::variant<32> *m_user_data; // edx
  char *m_requery_path; // eax
  vostok::variant<32> *v8; // ecx
  void (__cdecl *v9)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::human_npc_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::human_npc_cook *>,boost::arg<1> > > v10; // [esp-10h] [ebp-58h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::human_npc_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::human_npc_cook *>,boost::arg<1> > > v11; // [esp-10h] [ebp-58h]
  int v12; // [esp+0h] [ebp-48h]
  vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v13; // [esp+10h] [ebp-38h] BYREF
  unsigned int m_size; // [esp+14h] [ebp-34h]
  vostok::resources::request requests; // [esp+18h] [ebp-30h] BYREF
  __int64 v16; // [esp+20h] [ebp-28h]
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+28h] [ebp-20h] BYREF

  m_data = (vostok::sound::encoded_sound_interface *)parent->m_creation_data_from_user.m_data;
  m_size = parent->m_creation_data_from_user.m_size;
  v13.m_object = m_data;
  v4 = (vostok::configs::binary_config_value *)vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::c_ptr(&v13);
  if ( v4 )
  {
    pointer = (const char *)vostok::configs::binary_config_value::operator[](v4, "brain")->data.pointer;
    requests.path = (const char *)survarium::human_npc_cook::on_queried_data_received;
    requests.id = unknown_data_class;
    v10.f_.f_ = (void (__thiscall *__ptr64)(survarium::human_npc_cook *, vostok::resources::queries_result *))(unsigned int)survarium::human_npc_cook::on_queried_data_received;
    LODWORD(v16) = this;
    *(_QWORD *)&v10.l_.a1_.t_ = v16;
    boost::function1<void,vostok::resources::queries_result &>::function1<void,vostok::resources::queries_result &>(
      0,
      (int)&callback,
      (int)parent,
      v10,
      v12);
    m_user_data = parent->m_user_data;
    requests.path = pointer;
    v13.m_object = (vostok::sound::encoded_sound_interface *)m_user_data;
  }
  else
  {
    requests.path = (const char *)survarium::human_npc_cook::on_queried_data_received;
    requests.id = unknown_data_class;
    v11.f_.f_ = (void (__thiscall *__ptr64)(survarium::human_npc_cook *, vostok::resources::queries_result *))(unsigned int)survarium::human_npc_cook::on_queried_data_received;
    LODWORD(v16) = this;
    *(_QWORD *)&v11.l_.a1_.t_ = v16;
    boost::function1<void,vostok::resources::queries_result &>::function1<void,vostok::resources::queries_result &>(
      0,
      (int)&callback,
      (int)parent,
      v11,
      v12);
    m_requery_path = parent->m_requery_path;
    v8 = parent->m_user_data;
    if ( !m_requery_path )
      m_requery_path = parent->m_request_path;
    requests.path = m_requery_path;
    v13.m_object = (vostok::sound::encoded_sound_interface *)v8;
  }
  requests.id = binary_config_class_impl;
  vostok::resources::query_resources(
    &requests,
    1u,
    (boost::function4<void,unsigned int,float,float,char const *> *)&callback,
    (vostok::memory::base_allocator *)survarium::g_allocator.f_.f_,
    (const vostok::variant<32> **)&v13,
    parent,
    assert_on_fail_true);
  if ( callback.vtable && ((int)callback.vtable & 1) == 0 )
  {
    v9 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)callback.vtable & 0xFFFFFFFE);
    if ( v9 )
      v9(&callback.functor, &callback.functor, 2);
  }
}
