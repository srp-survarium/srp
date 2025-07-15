// bad sp value at call has been detected, the output may be wrong!
void __userpurge survarium::booby_trap_set_core_cook::on_resources_loaded(
        survarium::booby_trap_set_core_cook *this@<ecx>,
        int a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        vostok::resources::queries_result *data,
        survarium::booby_trap_set_cook_data cook_data)
{
  vostok::configs::binary_config *m_object; // esi
  survarium::pure_game_effect_emitter_base *v7; // esi
  vostok::physics::world *physics_world; // esi
  const vostok::configs::binary_config_value *v9; // eax
  int v10; // edi
  void *v11; // esp
  int v12; // esi
  void *v13; // esp
  vostok::variant<32> *v14; // ecx
  vostok::buffer_vector<vostok::variant<32> const *> *v15; // ecx
  boost::detail::function::basic_vtable1<void,vostok::resources::queries_result &> *v16; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v17; // ecx
  vostok::variant<32> *v18; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf4<void,survarium::booby_trap_set_core_cook,vostok::resources::queries_result &,survarium::booby_trap_set_core *,survarium::booby_trap_set_cook_data,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::list5<boost::_bi::value<survarium::booby_trap_set_core_cook *>,boost::arg<1>,boost::_bi::value<survarium::booby_trap_set_core *>,boost::_bi::value<survarium::booby_trap_set_cook_data>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> > > > v20; // [esp-100h] [ebp-10Ch] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf4<void,survarium::booby_trap_set_core_cook,vostok::resources::queries_result &,survarium::booby_trap_set_core *,survarium::booby_trap_set_cook_data,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::list5<boost::_bi::value<survarium::booby_trap_set_core_cook *>,boost::arg<1>,boost::_bi::value<survarium::booby_trap_set_core *>,boost::_bi::value<survarium::booby_trap_set_cook_data>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> > > > v21; // [esp-E0h] [ebp-ECh] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf4<void,survarium::booby_trap_set_core_cook,vostok::resources::queries_result &,survarium::booby_trap_set_core *,survarium::booby_trap_set_cook_data,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::list5<boost::_bi::value<survarium::booby_trap_set_core_cook *>,boost::arg<1>,boost::_bi::value<survarium::booby_trap_set_core *>,boost::_bi::value<survarium::booby_trap_set_cook_data>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> > > > v22; // [esp-C0h] [ebp-CCh] BYREF
  vostok::variant<32> v23; // [esp-A0h] [ebp-ACh] BYREF
  unsigned int v24; // [esp-70h] [ebp-7Ch] BYREF
  int v25; // [esp-68h] [ebp-74h] BYREF
  vostok::configs::binary_config_value v26; // [esp-50h] [ebp-5Ch] BYREF
  vostok::resources::request v27; // [esp-38h] [ebp-44h] BYREF
  vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> v28[2]; // [esp-30h] [ebp-3Ch] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf4<void,survarium::booby_trap_set_core_cook,vostok::resources::queries_result &,survarium::booby_trap_set_core *,survarium::booby_trap_set_cook_data,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::list5<boost::_bi::value<survarium::booby_trap_set_core_cook *>,boost::arg<1>,boost::_bi::value<survarium::booby_trap_set_core *>,boost::_bi::value<survarium::booby_trap_set_cook_data>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> > > > v29; // [esp-28h] [ebp-34h] BYREF
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v30; // [esp-8h] [ebp-14h] BYREF
  _BYTE v31[3]; // [esp-4h] [ebp-10h] BYREF
  char v32; // [esp-1h] [ebp-Dh]
  int v33; // [esp+0h] [ebp-Ch]
  void *v34; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v33 = a2;
  v34 = retaddr;
  v29.l_.a4_.t_.physics_world = (vostok::physics::world *)this;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &v30,
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data->m_queries[0].m_unmanaged_resource);
  m_object = (vostok::configs::binary_config *)v30.m_object;
  v29.l_.a5_.t_.m_object = 0;
  if ( v30.m_object )
  {
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v29.l_.a5_);
    v29.l_.a5_.t_.m_object = m_object;
    _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v30);
  qmemcpy(
    (void *)&v26,
    vostok::configs::binary_config_value::operator[](v29.l_.a5_.t_.m_object->m_root, "data"),
    sizeof(v26));
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &v30,
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data->m_queries[1].m_unmanaged_resource);
  v7 = v30.m_object;
  v29.l_.a4_.t_.game_world = 0;
  if ( v30.m_object )
  {
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v29.l_.a4_.t_.game_world);
    v29.l_.a4_.t_.game_world = v7;
    _InterlockedExchangeAdd(&v7->m_reference_count, 1u);
  }
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v30);
  physics_world = v29.l_.a4_.t_.physics_world;
  v9 = (const vostok::configs::binary_config_value *)((int (__thiscall *)(vostok::physics::world *, vostok::physics::world *, void **, void *, int, int))v29.l_.a4_.t_.physics_world->add)(
                                                       v29.l_.a4_.t_.physics_world,
                                                       cook_data.physics_world,
                                                       &v29.l_.a4_.t_.game_world,
                                                       cook_data.game_world,
                                                       a3,
                                                       a4);
  survarium::booby_trap_set_core::load((survarium::booby_trap_set_core *)&v26, v9, &v26, (unsigned __int8)v9);
  if ( cook_data.stack_size )
  {
    v10 = 8 * cook_data.stack_size;
    v11 = alloca(v10);
    v29.l_.a1_.t_ = (survarium::booby_trap_set_core_cook *)v31;
    v29.l_.a3_.t_ = (survarium::booby_trap_set_core *)v31;
    v12 = 4 * cook_data.stack_size;
    *(_DWORD *)&v29.l_.a4_.t_.is_local_player = &v31[v10];
    v13 = alloca(v12);
    HIDWORD(v26.id.max_storage) = v31;
    v26.id_crc = (unsigned int)v31;
    v23.m_helper = 0;
    v23.m_type_id = 0;
    v28[0].m_object = 0;
    *(_DWORD *)&v26.type = &v31[v12];
    vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
      (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&v29.l_.a5_,
      v28);
    v28[1] = (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base>)cook_data.physics_world;
    LODWORD(v29.f_.f_) = cook_data.game_world;
    vostok::variant<32>::set<survarium::booby_trap_core_query_data>(&v28[0], v14, &v23);
    v32 = 0;
    v27.path = uri;
    v27.id = booby_trap_class;
    HIDWORD(v29.f_.f_) = &v23;
    do
    {
      vostok::buffer_vector<vostok::resources::request>::push_back(
        (vostok::buffer_vector<vostok::resources::request> *)&v29.l_,
        &v27);
      vostok::buffer_vector<vostok::variant<32> const *>::push_back(
        v15,
        (int)&v26.id.max_storage + 4,
        (const vostok::variant<32> **)&v29.f_.f_ + 1);
      ++v32;
    }
    while ( v32 != cook_data.stack_size );
    v30.m_object = 0;
    v29.l_.a5_.t_.m_object = (vostok::configs::binary_config *)survarium::booby_trap_set_core_cook::on_subresources_loaded;
    v29.l_.a4_.t_.game_world = 0;
    vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v29.l_.a4_.t_.game_world,
      (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v29.l_.a5_);
    HIDWORD(v29.f_.f_) = (unsigned __int8)1_132;
    LODWORD(v29.f_.f_) = v29.l_.a4_.t_.physics_world;
    v29.l_.a4_.t_.physics_world = (vostok::physics::world *)cook_data.game_world;
    boost::bind<void,survarium::booby_trap_set_core_cook,vostok::resources::queries_result &,survarium::booby_trap_set_core *,survarium::booby_trap_set_cook_data,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>,survarium::booby_trap_set_core_cook *,boost::arg<1>,survarium::booby_trap_set_core *,survarium::booby_trap_set_cook_data,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>(
      &v21,
      v29.f_.f_,
      (survarium::booby_trap_set_core *)v30.m_object,
      *(int *)&cook_data.is_local_player,
      cook_data.physics_world,
      *(survarium::booby_trap_set_cook_data *)&v29.l_.a4_.t_.physics_world,
      (vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>)v30.m_object);
    boost::_bi::bind_t<void,boost::_mfi::mf4<void,survarium::booby_trap_set_core_cook,vostok::resources::queries_result &,survarium::booby_trap_set_core *,survarium::booby_trap_set_cook_data,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>,boost::_bi::list5<boost::_bi::value<survarium::booby_trap_set_core_cook *>,boost::arg<1>,boost::_bi::value<survarium::booby_trap_set_core *>,boost::_bi::value<survarium::booby_trap_set_cook_data>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>>>::bind_t<void,boost::_mfi::mf4<void,survarium::booby_trap_set_core_cook,vostok::resources::queries_result &,survarium::booby_trap_set_core *,survarium::booby_trap_set_cook_data,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>,boost::_bi::list5<boost::_bi::value<survarium::booby_trap_set_core_cook *>,boost::arg<1>,boost::_bi::value<survarium::booby_trap_set_core *>,boost::_bi::value<survarium::booby_trap_set_cook_data>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>>>(
      &v22,
      &v21);
    boost::_bi::bind_t<void,boost::_mfi::mf4<void,survarium::booby_trap_set_core_cook,vostok::resources::queries_result &,survarium::booby_trap_set_core *,survarium::booby_trap_set_cook_data,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>,boost::_bi::list5<boost::_bi::value<survarium::booby_trap_set_core_cook *>,boost::arg<1>,boost::_bi::value<survarium::booby_trap_set_core *>,boost::_bi::value<survarium::booby_trap_set_cook_data>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>>>::bind_t<void,boost::_mfi::mf4<void,survarium::booby_trap_set_core_cook,vostok::resources::queries_result &,survarium::booby_trap_set_core *,survarium::booby_trap_set_cook_data,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>,boost::_bi::list5<boost::_bi::value<survarium::booby_trap_set_core_cook *>,boost::arg<1>,boost::_bi::value<survarium::booby_trap_set_core *>,boost::_bi::value<survarium::booby_trap_set_cook_data>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>>>(
      &v20,
      &v22);
    boost::_bi::bind_t<void,boost::_mfi::mf4<void,survarium::booby_trap_set_core_cook,vostok::resources::queries_result &,survarium::booby_trap_set_core *,survarium::booby_trap_set_cook_data,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>,boost::_bi::list5<boost::_bi::value<survarium::booby_trap_set_core_cook *>,boost::arg<1>,boost::_bi::value<survarium::booby_trap_set_core *>,boost::_bi::value<survarium::booby_trap_set_cook_data>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>>>::bind_t<void,boost::_mfi::mf4<void,survarium::booby_trap_set_core_cook,vostok::resources::queries_result &,survarium::booby_trap_set_core *,survarium::booby_trap_set_cook_data,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>,boost::_bi::list5<boost::_bi::value<survarium::booby_trap_set_core_cook *>,boost::arg<1>,boost::_bi::value<survarium::booby_trap_set_core *>,boost::_bi::value<survarium::booby_trap_set_cook_data>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>>>(
      (boost::_bi::bind_t<void,boost::_mfi::mf4<void,survarium::booby_trap_set_core_cook,vostok::resources::queries_result &,survarium::booby_trap_set_core *,survarium::booby_trap_set_cook_data,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::list5<boost::_bi::value<survarium::booby_trap_set_core_cook *>,boost::arg<1>,boost::_bi::value<survarium::booby_trap_set_core *>,boost::_bi::value<survarium::booby_trap_set_cook_data>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> > > > *)((char *)&v29.f_.f_ + 4),
      &v20);
    LODWORD(v29.f_.f_) = &v25;
    v24 = boost::detail::function::basic_vtable1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf4<void,survarium::booby_trap_set_core_cook,vostok::resources::queries_result &,survarium::booby_trap_set_core *,survarium::booby_trap_set_cook_data,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>,boost::_bi::list5<boost::_bi::value<survarium::booby_trap_set_core_cook *>,boost::arg<1>,boost::_bi::value<survarium::booby_trap_set_core *>,boost::_bi::value<survarium::booby_trap_set_cook_data>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>>>>(
            v16,
            v29,
            (boost::detail::function::function_buffer *)v30.m_object) != 0
        ? (unsigned int)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf4<void,survarium::booby_trap_set_core_cook,vostok::resources::queries_result &,survarium::booby_trap_set_core *,survarium::booby_trap_set_cook_data,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>,boost::_bi::list5<boost::_bi::value<survarium::booby_trap_set_core_cook *>,boost::arg<1>,boost::_bi::value<survarium::booby_trap_set_core *>,boost::_bi::value<survarium::booby_trap_set_cook_data>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>>>>'::`2'::stored_vtable
        : 0;
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v20.l_.a5_);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v22.l_.a5_);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v21.l_.a5_);
    vostok::resources::query_resources(
      (const vostok::resources::request *)v29.l_.a1_.t_,
      ((char *)v29.l_.a3_.t_ - (char *)v29.l_.a1_.t_) >> 3,
      survarium::g_allocator,
      (const vostok::variant<32> *const *)HIDWORD(v26.id.max_storage),
      (const vostok::variant<32> **)data->m_parent_query,
      assert_on_fail_true);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v17,
      (int *)&v24);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v28[0]);
    vostok::variant<32>::destroy_previous_variable_if_needed(v18, (int)&v23);
  }
  else
  {
    survarium::grenade_set_core_cook::finish_query(
      (survarium::grenade_set_core_cook *)physics_world,
      data->m_parent_query,
      v30.m_object);
  }
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v29.l_.a4_.t_.game_world);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v29.l_.a5_);
}
