// bad sp value at call has been detected, the output may be wrong!
void __userpurge survarium::grenade_set_core_cook::on_config_ready(
        survarium::grenade_set_core_cook *this@<ecx>,
        int a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        vostok::resources::queries_result *data,
        survarium::grenade_set_cook_data cook_data)
{
  int v6; // esi
  survarium::grenade_set_core_cook *v7; // esi
  vostok::configs::binary_config_value *v8; // eax
  int v9; // edi
  void *v10; // esp
  int v11; // esi
  void *v12; // esp
  vostok::variant<32> *v13; // ecx
  vostok::buffer_vector<vostok::variant<32> const *> *v14; // ecx
  boost::detail::function::basic_vtable1<void,vostok::resources::queries_result &> *v15; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v16; // ecx
  vostok::variant<32> *v17; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf4<void,survarium::grenade_set_core_cook,vostok::resources::queries_result &,survarium::grenade_set_core *,survarium::grenade_set_cook_data,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::list5<boost::_bi::value<survarium::grenade_set_core_cook *>,boost::arg<1>,boost::_bi::value<survarium::grenade_set_core *>,boost::_bi::value<survarium::grenade_set_cook_data>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> > > > v19; // [esp-F8h] [ebp-104h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf4<void,survarium::grenade_set_core_cook,vostok::resources::queries_result &,survarium::grenade_set_core *,survarium::grenade_set_cook_data,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::list5<boost::_bi::value<survarium::grenade_set_core_cook *>,boost::arg<1>,boost::_bi::value<survarium::grenade_set_core *>,boost::_bi::value<survarium::grenade_set_cook_data>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> > > > v20; // [esp-D8h] [ebp-E4h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf4<void,survarium::grenade_set_core_cook,vostok::resources::queries_result &,survarium::grenade_set_core *,survarium::grenade_set_cook_data,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::list5<boost::_bi::value<survarium::grenade_set_core_cook *>,boost::arg<1>,boost::_bi::value<survarium::grenade_set_core *>,boost::_bi::value<survarium::grenade_set_cook_data>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> > > > v21; // [esp-B8h] [ebp-C4h] BYREF
  unsigned int v22; // [esp-98h] [ebp-A4h] BYREF
  int v23; // [esp-90h] [ebp-9Ch] BYREF
  _DWORD v24[2]; // [esp-78h] [ebp-84h] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v25[10]; // [esp-70h] [ebp-7Ch] BYREF
  const vostok::variant<32> *const *v26[6]; // [esp-48h] [ebp-54h] BYREF
  vostok::resources::request v27; // [esp-30h] [ebp-3Ch] BYREF
  _BYTE v28[36]; // [esp-28h] [ebp-34h] BYREF
  _BYTE v29[3]; // [esp-4h] [ebp-10h] BYREF
  char v30; // [esp-1h] [ebp-Dh]
  int v31; // [esp+0h] [ebp-Ch]
  void *v32; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v31 = a2;
  v32 = retaddr;
  *(_DWORD *)&v28[24] = this;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&v28[28],
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data->m_queries[0].m_unmanaged_resource);
  v6 = *(_DWORD *)&v28[28];
  *(_DWORD *)&v28[32] = 0;
  if ( *(_DWORD *)&v28[28] )
  {
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v28[32]);
    *(_DWORD *)&v28[32] = v6;
    _InterlockedExchangeAdd((volatile signed __int32 *)(v6 + 208), 1u);
  }
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v28[28]);
  qmemcpy(
    v26,
    vostok::configs::binary_config_value::operator[](
      *(vostok::configs::binary_config_value **)(*(_DWORD *)&v28[32] + 264),
      "data"),
    sizeof(v26));
  v7 = *(survarium::grenade_set_core_cook **)&v28[24];
  v8 = (vostok::configs::binary_config_value *)(*(int (__thiscall **)(_DWORD, void *, int, int))(**(_DWORD **)&v28[24]
                                                                                               + 36))(
                                                 *(_DWORD *)&v28[24],
                                                 cook_data.game_world,
                                                 a3,
                                                 a4);
  survarium::grenade_set_core::load((survarium::grenade_set_core *)v26, v8, v8, cook_data.stack_size);
  if ( cook_data.stack_size )
  {
    v9 = 8 * cook_data.stack_size;
    v10 = alloca(v9);
    *(_DWORD *)&v28[4] = v29;
    *(_DWORD *)&v28[8] = v29;
    v11 = 4 * cook_data.stack_size;
    *(_DWORD *)&v28[12] = &v29[v9];
    v12 = alloca(v11);
    v26[3] = (const vostok::variant<32> *const *)v29;
    v26[4] = (const vostok::variant<32> *const *)v29;
    *(_DWORD *)&v28[16] = 0;
    v26[5] = (const vostok::variant<32> *const *)&v29[v11];
    vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
      (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&v28[32],
      (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&v28[16]);
    *(_DWORD *)&v28[20] = cook_data.game_world;
    vostok::variant<32>::destroy_previous_variable_if_needed(v13, (int)v24);
    v25[9].m_object = (vostok::particle::particle_system_instance_impl *)vostok::detail::type_to_int<survarium::grenade_cook_data>::get();
    vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      v25,
      (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v28[16]);
    v25[1] = *(vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v28[20];
    v24[0] = &vostok::detail::concrete_type_helper<survarium::grenade_cook_data>::`vftable';
    v25[8].m_object = (vostok::particle::particle_system_instance_impl *)v24;
    v30 = 0;
    v27.path = uri;
    v27.id = grenade_class;
    *(_DWORD *)v28 = v24;
    do
    {
      vostok::buffer_vector<vostok::resources::request>::push_back(
        (vostok::buffer_vector<vostok::resources::request> *)&v28[4],
        &v27);
      vostok::buffer_vector<vostok::variant<32> const *>::push_back(
        v14,
        (int)&v26[3],
        (const vostok::variant<32> **)v28);
      ++v30;
    }
    while ( v30 != cook_data.stack_size );
    *(survarium::grenade_set_cook_data *)&v28[28] = cook_data;
    *(_DWORD *)&v28[24] = 0;
    *(_DWORD *)&v28[20] = survarium::grenade_set_core_cook::on_subresources_loaded;
    *(_DWORD *)&v28[16] = 0;
    vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v28[16],
      (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v28[32]);
    *(_DWORD *)&v28[8] = (unsigned __int8)1_134;
    *(_DWORD *)&v28[4] = *(_DWORD *)&v28[24];
    boost::bind<void,survarium::grenade_set_core_cook,vostok::resources::queries_result &,survarium::grenade_set_core *,survarium::grenade_set_cook_data,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>,survarium::grenade_set_core_cook *,boost::arg<1>,survarium::grenade_set_core *,survarium::grenade_set_cook_data,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>(
      &v20,
      *(void (__thiscall *__ptr64 *)(survarium::grenade_set_core_cook *, vostok::resources::queries_result *, survarium::grenade_set_core *, survarium::grenade_set_cook_data, vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>))&v28[4],
      *(survarium::grenade_set_core **)&v28[28],
      *(vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v28[16],
      *(survarium::grenade_set_core **)&v28[20],
      *(survarium::grenade_set_cook_data *)&v28[24],
      *(vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *)&v28[32]);
    boost::_bi::bind_t<void,boost::_mfi::mf4<void,survarium::grenade_set_core_cook,vostok::resources::queries_result &,survarium::grenade_set_core *,survarium::grenade_set_cook_data,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>,boost::_bi::list5<boost::_bi::value<survarium::grenade_set_core_cook *>,boost::arg<1>,boost::_bi::value<survarium::grenade_set_core *>,boost::_bi::value<survarium::grenade_set_cook_data>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>>>::bind_t<void,boost::_mfi::mf4<void,survarium::grenade_set_core_cook,vostok::resources::queries_result &,survarium::grenade_set_core *,survarium::grenade_set_cook_data,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>,boost::_bi::list5<boost::_bi::value<survarium::grenade_set_core_cook *>,boost::arg<1>,boost::_bi::value<survarium::grenade_set_core *>,boost::_bi::value<survarium::grenade_set_cook_data>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>>>(
      &v19,
      &v20);
    boost::_bi::bind_t<void,boost::_mfi::mf4<void,survarium::grenade_set_core_cook,vostok::resources::queries_result &,survarium::grenade_set_core *,survarium::grenade_set_cook_data,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>,boost::_bi::list5<boost::_bi::value<survarium::grenade_set_core_cook *>,boost::arg<1>,boost::_bi::value<survarium::grenade_set_core *>,boost::_bi::value<survarium::grenade_set_cook_data>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>>>::bind_t<void,boost::_mfi::mf4<void,survarium::grenade_set_core_cook,vostok::resources::queries_result &,survarium::grenade_set_core *,survarium::grenade_set_cook_data,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>,boost::_bi::list5<boost::_bi::value<survarium::grenade_set_core_cook *>,boost::arg<1>,boost::_bi::value<survarium::grenade_set_core *>,boost::_bi::value<survarium::grenade_set_cook_data>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>>>(
      &v21,
      &v19);
    boost::_bi::bind_t<void,boost::_mfi::mf4<void,survarium::grenade_set_core_cook,vostok::resources::queries_result &,survarium::grenade_set_core *,survarium::grenade_set_cook_data,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>,boost::_bi::list5<boost::_bi::value<survarium::grenade_set_core_cook *>,boost::arg<1>,boost::_bi::value<survarium::grenade_set_core *>,boost::_bi::value<survarium::grenade_set_cook_data>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>>>::bind_t<void,boost::_mfi::mf4<void,survarium::grenade_set_core_cook,vostok::resources::queries_result &,survarium::grenade_set_core *,survarium::grenade_set_cook_data,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>,boost::_bi::list5<boost::_bi::value<survarium::grenade_set_core_cook *>,boost::arg<1>,boost::_bi::value<survarium::grenade_set_core *>,boost::_bi::value<survarium::grenade_set_cook_data>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>>>(
      (boost::_bi::bind_t<void,boost::_mfi::mf4<void,survarium::grenade_set_core_cook,vostok::resources::queries_result &,survarium::grenade_set_core *,survarium::grenade_set_cook_data,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::list5<boost::_bi::value<survarium::grenade_set_core_cook *>,boost::arg<1>,boost::_bi::value<survarium::grenade_set_core *>,boost::_bi::value<survarium::grenade_set_cook_data>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> > > > *)&v28[4],
      &v21);
    *(_DWORD *)v28 = &v23;
    v22 = boost::detail::function::basic_vtable1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf4<void,survarium::grenade_set_core_cook,vostok::resources::queries_result &,survarium::grenade_set_core *,survarium::grenade_set_cook_data,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>,boost::_bi::list5<boost::_bi::value<survarium::grenade_set_core_cook *>,boost::arg<1>,boost::_bi::value<survarium::grenade_set_core *>,boost::_bi::value<survarium::grenade_set_cook_data>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>>>>(
            v15,
            *(boost::_bi::bind_t<void,boost::_mfi::mf4<void,survarium::grenade_set_core_cook,vostok::resources::queries_result &,survarium::grenade_set_core *,survarium::grenade_set_cook_data,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::list5<boost::_bi::value<survarium::grenade_set_core_cook *>,boost::arg<1>,boost::_bi::value<survarium::grenade_set_core *>,boost::_bi::value<survarium::grenade_set_cook_data>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> > > > *)v28,
            *(boost::detail::function::function_buffer **)&v28[32]) != 0
        ? (unsigned int)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf4<void,survarium::grenade_set_core_cook,vostok::resources::queries_result &,survarium::grenade_set_core *,survarium::grenade_set_cook_data,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>,boost::_bi::list5<boost::_bi::value<survarium::grenade_set_core_cook *>,boost::arg<1>,boost::_bi::value<survarium::grenade_set_core *>,boost::_bi::value<survarium::grenade_set_cook_data>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>>>>'::`2'::stored_vtable
        : 0;
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v21.l_.a5_);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v19.l_.a5_);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v20.l_.a5_);
    vostok::resources::query_resources(
      *(const vostok::resources::request **)&v28[4],
      (*(_DWORD *)&v28[8] - *(_DWORD *)&v28[4]) >> 3,
      survarium::g_allocator,
      v26[3],
      (const vostok::variant<32> **)data->m_parent_query,
      assert_on_fail_true);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v16,
      (int *)&v22);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v28[16]);
    vostok::variant<32>::destroy_previous_variable_if_needed(v17, (int)v24);
  }
  else
  {
    survarium::grenade_set_core_cook::finish_query(
      v7,
      data->m_parent_query,
      *(survarium::pure_game_effect_emitter_base **)&v28[28]);
  }
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v28[32]);
}
