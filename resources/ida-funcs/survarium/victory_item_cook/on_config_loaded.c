void __thiscall survarium::victory_item_cook::on_config_loaded(
        survarium::victory_item_cook *this,
        vostok::resources::queries_result *data,
        vostok::physics::world *physics_world)
{
  survarium::victory_item_cook_vtbl *v3; // eax
  vostok::resources::class_id_enum id; // esi
  void *v5; // esp
  vostok::configs::binary_config_value *v6; // eax
  vostok::configs::binary_config_value *v7; // eax
  survarium::weapon *v8; // ecx
  boost::function1<void,vostok::resources::queries_result &> *v9; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v10; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::victory_item_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>,survarium::victory_item *>,boost::_bi::list4<boost::_bi::value<survarium::victory_item_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::value<survarium::victory_item *> > > v11; // [esp-28h] [ebp-A0h] BYREF
  _BYTE v12[16]; // [esp-10h] [ebp-88h] BYREF
  int v13; // [esp+0h] [ebp-78h] BYREF
  int v14[8]; // [esp+Ch] [ebp-6Ch] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::weapon_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>,survarium::weapon_core *>,boost::_bi::list4<boost::_bi::value<survarium::weapon_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::value<survarium::weapon *> > > result; // [esp+2Ch] [ebp-4Ch] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::weapon_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>,survarium::weapon_core *>,boost::_bi::list4<boost::_bi::value<survarium::weapon_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::value<survarium::weapon *> > > __that; // [esp+44h] [ebp-34h] BYREF
  vostok::buffer_vector<vostok::resources::request> v17; // [esp+5Ch] [ebp-1Ch] BYREF
  survarium::weapon_cook *a1; // [esp+68h] [ebp-10h]
  survarium::weapon *a4; // [esp+6Ch] [ebp-Ch]
  vostok::resources::request v20; // [esp+70h] [ebp-8h] BYREF

  v3 = this->__vftable;
  a1 = (survarium::weapon_cook *)this;
  a4 = (survarium::weapon *)((int (__stdcall *)(vostok::physics::world *))v3->create_resource)(physics_world);
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&v20.id,
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data->m_queries[0].m_unmanaged_resource);
  id = v20.id;
  physics_world = 0;
  if ( v20.id )
  {
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&physics_world);
    physics_world = (vostok::physics::world *)id;
    _InterlockedExchangeAdd((volatile signed __int32 *)(id + 208), 1u);
  }
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v20.id);
  v5 = alloca(16);
  v17.m_begin = (vostok::resources::request *)v12;
  v17.m_end = (vostok::resources::request *)v12;
  v17.m_max_end = (vostok::resources::request *)&v13;
  v6 = vostok::configs::binary_config_value::operator[](
         (vostok::configs::binary_config_value *)physics_world[66].__vftable,
         "object");
  v20.path = (const char *)vostok::configs::binary_config_value::operator[](v6, "skeleton_model")->data.pointer;
  v20.id = skeleton_model_instance_class;
  vostok::buffer_vector<vostok::resources::request>::push_back(&v17, &v20);
  v7 = vostok::configs::binary_config_value::operator[](
         (vostok::configs::binary_config_value *)physics_world[66].__vftable,
         "object");
  v20.path = (const char *)vostok::configs::binary_config_value::operator[](v7, "static_model")->data.pointer;
  v20.id = static_model_instance_class;
  vostok::buffer_vector<vostok::resources::request>::push_back(&v17, &v20);
  *((_DWORD *)&v11.l_ + 3) = a4;
  v11.l_.a4_.t_ = (survarium::victory_item *)v8;
  vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v11.l_.a4_,
    (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&physics_world);
  boost::bind<void,survarium::victory_item_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>,survarium::victory_item *,survarium::victory_item_cook *,boost::arg<1>,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>,survarium::victory_item *>(
    &result,
    (void (__thiscall *__ptr64)(survarium::weapon_cook *, vostok::resources::queries_result *, vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>, survarium::weapon_core *))(unsigned int) __thiscall survarium::victory_item_cook::`vcall'{44,{flat}},
    a1,
    1_86,
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>)v11.l_.a4_.t_,
    *((survarium::weapon **)&v11.l_ + 3));
  boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::weapon_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>,survarium::weapon_core *>,boost::_bi::list4<boost::_bi::value<survarium::weapon_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>,boost::_bi::value<survarium::weapon *>>>::bind_t<void,boost::_mfi::mf3<void,survarium::weapon_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>,survarium::weapon_core *>,boost::_bi::list4<boost::_bi::value<survarium::weapon_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>,boost::_bi::value<survarium::weapon *>>>(
    &__that,
    &result);
  v14[0] = 0;
  boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::weapon_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>,survarium::weapon_core *>,boost::_bi::list4<boost::_bi::value<survarium::weapon_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>,boost::_bi::value<survarium::weapon *>>>::bind_t<void,boost::_mfi::mf3<void,survarium::weapon_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>,survarium::weapon_core *>,boost::_bi::list4<boost::_bi::value<survarium::weapon_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>,boost::_bi::value<survarium::weapon *>>>(
    (boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::weapon_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>,survarium::weapon_core *>,boost::_bi::list4<boost::_bi::value<survarium::weapon_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::value<survarium::weapon *> > > *)&v11,
    &__that);
  boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::victory_item_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>,survarium::victory_item *>,boost::_bi::list4<boost::_bi::value<survarium::victory_item_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>,boost::_bi::value<survarium::victory_item *>>>>(
    v9,
    (int)v14,
    v11);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&__that.l_.a3_);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&result.l_.a3_);
  vostok::resources::query_resources(
    v17.m_begin,
    v17.m_end - v17.m_begin,
    survarium::g_allocator,
    0,
    (const vostok::variant<32> **)data->m_parent_query,
    assert_on_fail_true);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v10, v14);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&physics_world);
}
