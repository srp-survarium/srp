void __thiscall survarium::game::on_ui_sounds_cfg_loaded(
        survarium::game *this,
        vostok::resources::queries_result *data)
{
  vostok::resources::queries_result *id; // esi
  int v3; // eax
  vostok::memory::doug_lea_allocator *v4; // esi
  int v5; // edi
  char *v6; // eax
  vostok::memory::doug_lea_allocator *v7; // ecx
  char *v8; // eax
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *v9; // eax
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *v10; // edi
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *i; // edx
  int m_ui_sounds_count; // esi
  void *v13; // esp
  int *pointer; // esi
  const vostok::configs::binary_config_value *v15; // eax
  int v16; // esi
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v17; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::game,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::game *>,boost::arg<1> > > v18; // [esp-14h] [ebp-60h]
  const char *v19[3]; // [esp+0h] [ebp-4Ch] BYREF
  vostok::buffer_vector<vostok::resources::request> v20; // [esp+Ch] [ebp-40h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::game,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::game *>,boost::arg<1> > > f; // [esp+18h] [ebp-34h] BYREF
  void (__thiscall *v22)(survarium::game *, vostok::resources::queries_result *); // [esp+28h] [ebp-24h]
  int v23; // [esp+2Ch] [ebp-20h]
  vostok::resources::request v24; // [esp+30h] [ebp-1Ch] BYREF
  survarium::game *v25; // [esp+3Ch] [ebp-10h]
  vostok::resources::request v26; // [esp+40h] [ebp-Ch] BYREF

  v25 = this;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&v26.id,
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data->m_queries[0].m_unmanaged_resource);
  id = (vostok::resources::queries_result *)v26.id;
  data = 0;
  if ( v26.id )
  {
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data);
    data = id;
    _InterlockedExchangeAdd((volatile signed __int32 *)&id->m_queries[0].m_target_quality_level, 1u);
  }
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v26.id);
  v3 = 24
     * vostok::configs::binary_config_value::operator[](
         (vostok::configs::binary_config_value *)data->m_queries[0].m_next_for_grm_observer_list,
         "sounds")->count
     / 24;
  v4 = survarium::g_allocator;
  v25->m_ui_sounds_count = v3;
  v5 = (unsigned __int8)v3;
  v6 = type_info::raw_name(&vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> `RTTI Type Descriptor');
  v8 = vostok::memory::doug_lea_allocator::malloc_impl(
         v7,
         (int)v4,
         4 * v5 + 8,
         v6,
         v19[0],
         v19[1],
         (const unsigned int)v19[2]);
  *(_DWORD *)v8 = v5;
  v8 += 4;
  *(_DWORD *)v8 = 4;
  v9 = (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)(v8 + 4);
  v10 = &v9[v5];
  for ( i = v9; i != v10; ++i )
  {
    if ( i )
      i->m_object = 0;
  }
  m_ui_sounds_count = v25->m_ui_sounds_count;
  v25->m_ui_sounds = v9;
  m_ui_sounds_count *= 8;
  v13 = alloca(m_ui_sounds_count + 8);
  v20.m_begin = (vostok::resources::request *)v19;
  v20.m_end = (vostok::resources::request *)v19;
  v20.m_max_end = (vostok::resources::request *)((char *)&v19[2] + m_ui_sounds_count);
  v26.path = "items_dictionary";
  v26.id = items_dictionary_class;
  vostok::buffer_vector<vostok::resources::request>::push_back(&v20, &v26);
  pointer = (int *)vostok::configs::binary_config_value::operator[](
                     (vostok::configs::binary_config_value *)data->m_queries[0].m_next_for_grm_observer_list,
                     "sounds")->data.pointer;
  for ( v26.id = (vostok::resources::class_id_enum)pointer; ; pointer = (int *)v26.id )
  {
    v15 = vostok::configs::binary_config_value::operator[](
            (vostok::configs::binary_config_value *)data->m_queries[0].m_next_for_grm_observer_list,
            "sounds");
    if ( pointer == (int *)v15->data.pointer + 6 * v15->count )
      break;
    v16 = *pointer;
    v24.path = *(const char **)(v16 + 24);
    v24.id = *(_DWORD *)v16;
    vostok::buffer_vector<vostok::resources::request>::push_back(&v20, &v24);
    v26.id += 24;
  }
  v22 = survarium::game::on_base_resources_created;
  v24.path = (const char *)v25;
  v23 = 0;
  HIDWORD(v18.f_.f_) = survarium::game::on_base_resources_created;
  v18.l_.a1_.t_ = 0;
  *((_DWORD *)&v18.l_ + 1) = v25;
  LODWORD(v18.f_.f_) = &f;
  boost::function<void __cdecl (vostok::resources::queries_result &)>::function<void __cdecl (vostok::resources::queries_result &)>(
    0,
    v18,
    v24.id);
  vostok::resources::query_resources(
    v20.m_begin,
    v20.m_end - v20.m_begin,
    survarium::g_allocator,
    0,
    0,
    assert_on_fail_true);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v17,
    (int *)&f);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data);
}
