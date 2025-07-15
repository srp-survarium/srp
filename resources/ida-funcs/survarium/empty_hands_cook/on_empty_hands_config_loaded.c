void __thiscall survarium::empty_hands_cook::on_empty_hands_config_loaded(
        survarium::empty_hands_cook *this,
        vostok::resources::queries_result *data)
{
  vostok::particle::particle_system_instance_impl *m_object; // esi
  int v3; // esi
  void *v4; // esp
  vostok::resources::request *m_end; // ebx
  const char **path; // ebx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v7; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::empty_hands_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::empty_hands_cook *>,boost::arg<1> > > v8; // [esp-14h] [ebp-60h]
  _BYTE v9[12]; // [esp+0h] [ebp-4Ch] BYREF
  vostok::buffer_vector<vostok::resources::request> v10; // [esp+Ch] [ebp-40h] BYREF
  int f[2]; // [esp+18h] [ebp-34h] BYREF
  vostok::resources::request f_8[3]; // [esp+20h] [ebp-2Ch] BYREF
  survarium::empty_hands_cook *v13; // [esp+3Ch] [ebp-10h]
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v14; // [esp+40h] [ebp-Ch] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v15; // [esp+44h] [ebp-8h] BYREF

  v13 = this;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &v14,
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data->m_queries[0].m_unmanaged_resource);
  m_object = (vostok::particle::particle_system_instance_impl *)v14.m_object;
  v15.m_object = 0;
  if ( v14.m_object )
  {
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v15);
    v15.m_object = m_object;
    _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v14);
  qmemcpy(
    f_8,
    vostok::configs::binary_config_value::operator[](
      (vostok::configs::binary_config_value *)v15.m_object->m_lods[0].m_template.m_object,
      "user_animations"),
    sizeof(f_8));
  v3 = 8 * ((signed int)(24 * ((unsigned int)f_8[2].id >> 16)) / 24);
  v4 = alloca(v3);
  m_end = (vostok::resources::request *)v9;
  v10.m_begin = (vostok::resources::request *)v9;
  v10.m_end = (vostok::resources::request *)v9;
  v10.m_max_end = (vostok::resources::request *)&v9[v3];
  if ( (signed int)(24 * ((unsigned int)f_8[2].id >> 16)) / 24 )
  {
    path = (const char **)f_8[0].path;
    v14.m_object = (survarium::pure_game_effect_emitter_base *)((signed int)(24 * ((unsigned int)f_8[2].id >> 16)) / 24);
    do
    {
      f_8[2].path = *path;
      f_8[2].id = animation_class;
      vostok::buffer_vector<vostok::resources::request>::push_back(&v10, &f_8[2]);
      path += 6;
      --v14.m_object;
    }
    while ( v14.m_object );
    m_end = v10.m_end;
  }
  f_8[1].path = (const char *)survarium::empty_hands_cook::on_empty_hands_animations_loaded;
  f_8[2].path = (const char *)v13;
  f_8[1].id = unknown_data_class;
  HIDWORD(v8.f_.f_) = survarium::empty_hands_cook::on_empty_hands_animations_loaded;
  v8.l_.a1_.t_ = 0;
  *((_DWORD *)&v8.l_ + 1) = v13;
  LODWORD(v8.f_.f_) = f;
  boost::function<void __cdecl (vostok::resources::queries_result &)>::function<void __cdecl (vostok::resources::queries_result &)>(
    0,
    v8,
    f_8[2].id);
  vostok::resources::query_resources(
    v10.m_begin,
    m_end - v10.m_begin,
    survarium::g_allocator,
    0,
    (const vostok::variant<32> **)data->m_parent_query,
    assert_on_fail_true);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v7, f);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v15);
}
