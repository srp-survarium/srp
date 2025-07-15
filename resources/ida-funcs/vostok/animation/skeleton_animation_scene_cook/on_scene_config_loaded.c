void __thiscall vostok::animation::skeleton_animation_scene_cook::on_scene_config_loaded(
        vostok::animation::skeleton_animation_scene_cook *this,
        vostok::resources::queries_result *data)
{
  vostok::particle::particle_system_instance_impl *m_object; // esi
  vostok::resources::unmanaged_resource *v3; // eax
  vostok::configs::binary_config_value *v4; // eax
  survarium::pure_game_effect_emitter_base *v5; // ebx
  const void *pointer; // eax
  boost::function1<void,vostok::resources::queries_result &> *v7; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v8; // ecx
  vostok::vectora<vostok::resources::request> *v9; // ecx
  _BYTE v10[20]; // [esp-14h] [ebp-BCh] BYREF
  const vostok::resources::request *v11; // [esp+0h] [ebp-A8h]
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v12; // [esp+10h] [ebp-98h] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v13; // [esp+14h] [ebp-94h] BYREF
  char *v14; // [esp+18h] [ebp-90h]
  const vostok::resources::request *v15; // [esp+1Ch] [ebp-8Ch] BYREF
  int v16; // [esp+20h] [ebp-88h]
  vostok::memory::doug_lea_allocator *v17; // [esp+24h] [ebp-84h]
  int v18; // [esp+28h] [ebp-80h]
  vostok::animation::skeleton_animation_scene_cook *v19; // [esp+2Ch] [ebp-7Ch]
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::rifle_scope_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> const &>,boost::_bi::list3<boost::_bi::value<survarium::rifle_scope_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> > > > __that; // [esp+30h] [ebp-78h] BYREF
  _BYTE v21[24]; // [esp+40h] [ebp-68h] BYREF
  vostok::configs::binary_config_value v22; // [esp+58h] [ebp-50h] BYREF
  vostok::configs::binary_config_value v23; // [esp+78h] [ebp-30h] BYREF
  _DWORD v24[6]; // [esp+90h] [ebp-18h] BYREF

  v19 = this;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &v12,
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data->m_queries[0].m_unmanaged_resource);
  m_object = (vostok::particle::particle_system_instance_impl *)v12.m_object;
  v13.m_object = 0;
  if ( v12.m_object )
  {
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v13);
    v13.m_object = m_object;
    _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v12);
  v3 = v13.m_object->m_lods[0].m_template.m_object;
  v15 = 0;
  v16 = 0;
  v18 = 0;
  v17 = &vostok::memory::g_resources_unmanaged_allocator;
  v4 = vostok::configs::binary_config_value::operator[]((vostok::configs::binary_config_value *)v3, "scene");
  qmemcpy(v21, vostok::configs::binary_config_value::operator[](v4, "nodes"), sizeof(v21));
  v5 = (survarium::pure_game_effect_emitter_base *)(*(_DWORD *)v21 + 24 * HIWORD(*(_DWORD *)&v21[20]));
  for ( v12.m_object = *(survarium::pure_game_effect_emitter_base **)v21;
        v12.m_object != v5;
        v12.m_object = (survarium::pure_game_effect_emitter_base *)((char *)v12.m_object + 24) )
  {
    qmemcpy((void *)&v23, v12.m_object, sizeof(v23));
    pointer = vostok::configs::binary_config_value::operator[](&v23, "type")->data.pointer;
    HIDWORD(__that.f_.f_) = 0;
    if ( pointer == (const void *)1 )
    {
      qmemcpy(v24, vostok::configs::binary_config_value::operator[](&v23, "intervals"), sizeof(v24));
      v14 = (char *)v24[0];
      for ( LODWORD(__that.f_.f_) = v24[0] + 24 * HIWORD(v24[5]); v14 != (char *)LODWORD(__that.f_.f_); v14 += 24 )
      {
        qmemcpy((void *)&v22, v14, sizeof(v22));
        *(_DWORD *)v21 = vostok::configs::binary_config_value::operator[](&v22, "animation")->data.pointer;
        *(_DWORD *)&v21[4] = 50;
        stlp_std::vector<vostok::resources::request,vostok::vectora_allocator<void *>>::push_back(
          (stlp_std::vector<vostok::resources::request,vostok::vectora_allocator<void *> > *)v21,
          v11);
      }
    }
  }
  *(_DWORD *)&v10[16] = 0;
  *(_DWORD *)&v10[12] = vostok::animation::skeleton_animation_scene_cook::on_animation_loaded;
  *(_DWORD *)&v10[8] = 0;
  vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v10[8],
    &v13);
  *(_DWORD *)&v10[4] = (unsigned __int8)1_225;
  *(_DWORD *)v10 = v19;
  boost::bind<void,vostok::animation::skeleton_animation_scene_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>,vostok::animation::skeleton_animation_scene_cook *,boost::arg<1>,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>(
    &__that,
    *(void (__thiscall *__ptr64 *)(survarium::rifle_scope_cook *, vostok::resources::queries_result *, const vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *))v10,
    *(survarium::rifle_scope_cook **)&v10[8],
    *(vostok::particle::particle_system_instance_impl **)&v10[12],
    *(vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *)&v10[16]);
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::animation::skeleton_animation_scene_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>,boost::_bi::list3<boost::_bi::value<vostok::animation::skeleton_animation_scene_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>>>::bind_t<void,boost::_mfi::mf2<void,vostok::animation::skeleton_animation_scene_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>,boost::_bi::list3<boost::_bi::value<vostok::animation::skeleton_animation_scene_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>>>(
    &__that,
    (boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::rifle_scope_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> const &>,boost::_bi::list3<boost::_bi::value<survarium::rifle_scope_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> > > > *)v21);
  v22.data.pointer = 0;
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::animation::skeleton_animation_scene_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>,boost::_bi::list3<boost::_bi::value<vostok::animation::skeleton_animation_scene_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>>>::bind_t<void,boost::_mfi::mf2<void,vostok::animation::skeleton_animation_scene_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>,boost::_bi::list3<boost::_bi::value<vostok::animation::skeleton_animation_scene_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>>>(
    (const boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::rifle_scope_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> const &>,boost::_bi::list3<boost::_bi::value<survarium::rifle_scope_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> > > > *)v21,
    (boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::rifle_scope_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> const &>,boost::_bi::list3<boost::_bi::value<survarium::rifle_scope_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> > > > *)&v10[4]);
  boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::animation::skeleton_animation_scene_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>,boost::_bi::list3<boost::_bi::value<vostok::animation::skeleton_animation_scene_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>>>>(
    v7,
    (int)&v22,
    *(boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::animation::skeleton_animation_scene_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::list3<boost::_bi::value<vostok::animation::skeleton_animation_scene_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> > > > *)&v10[4]);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v21[12]);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&__that.l_.a3_);
  vostok::resources::query_resources(
    v15,
    (v16 - (int)v15) >> 3,
    &vostok::memory::g_resources_helper_allocator,
    0,
    (const vostok::variant<32> **)data->m_parent_query,
    assert_on_fail_true);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v8,
    (int *)&v22);
  vostok::vectora<vostok::resources::request>::~vectora<vostok::resources::request>(v9, (int)&v15);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v13);
}
