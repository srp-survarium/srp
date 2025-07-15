void __thiscall vostok::sound::composite_sound_cook::on_sub_resources_loaded(
        vostok::sound::composite_sound_cook *this,
        vostok::resources::queries_result *data)
{
  vostok::particle::particle_system_instance_impl *v2; // esi
  vostok::configs::binary_config_value *v3; // eax
  const vostok::configs::binary_config_value *v4; // ebx
  int v5; // ecx
  int v6; // esi
  void *v7; // esp
  boost::function1<void,vostok::resources::queries_result &> *v8; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v9; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::rifle_scope_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> const &>,boost::_bi::list3<boost::_bi::value<survarium::rifle_scope_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> > > > v10; // [esp-10h] [ebp-84h] BYREF
  _BYTE v11[16]; // [esp+0h] [ebp-74h] BYREF
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+10h] [ebp-64h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::sound::composite_sound_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::list3<boost::_bi::value<vostok::sound::composite_sound_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> > > > result; // [esp+30h] [ebp-44h] BYREF
  vostok::buffer_vector<vostok::resources::request> requests; // [esp+44h] [ebp-30h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::rifle_scope_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> const &>,boost::_bi::list3<boost::_bi::value<survarium::rifle_scope_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> > > > __that; // [esp+50h] [ebp-24h] BYREF
  vostok::resources::query_result_for_cook *parent; // [esp+64h] [ebp-10h]
  vostok::sound::composite_sound_cook *a1; // [esp+68h] [ebp-Ch]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> other; // [esp+6Ch] [ebp-8h] BYREF

  a1 = this;
  parent = data->m_parent_query;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data,
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data->m_queries[0].m_unmanaged_resource);
  v2 = (vostok::particle::particle_system_instance_impl *)data;
  other.m_object = 0;
  if ( data )
  {
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&other);
    other.m_object = v2;
    _InterlockedExchangeAdd(&v2->m_reference_count, 1u);
  }
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data);
  v3 = vostok::configs::binary_config_value::operator[](
         (vostok::configs::binary_config_value *)other.m_object->m_lods[0].m_template.m_object,
         "composite_sound");
  v4 = vostok::configs::binary_config_value::operator[](v3, "sound_items");
  data = (vostok::resources::queries_result *)v4->data.pointer;
  v5 = 24;
  v6 = 8 * (24 * v4->count / 24);
  v7 = alloca(v6);
  requests.m_begin = (vostok::resources::request *)v11;
  requests.m_end = (vostok::resources::request *)v11;
  requests.m_max_end = (vostok::resources::request *)&v11[v6];
  while ( data != (vostok::resources::queries_result *)((char *)v4->data.pointer + 24 * v4->count) )
  {
    __that.l_.a1_.t_ = (survarium::rifle_scope_cook *)vostok::configs::binary_config_value::operator[](
                                                        (vostok::configs::binary_config_value *)data,
                                                        "filename")->data.pointer;
    __that.l_.a3_.t_.m_object = (vostok::configs::binary_config *)vostok::configs::binary_config_value::operator[](
                                                                    (vostok::configs::binary_config_value *)data,
                                                                    "resource_type")->data.pointer;
    vostok::buffer_vector<vostok::resources::request>::push_back(
      &requests,
      (const vostok::resources::request *)&__that.l_);
    data = (vostok::resources::queries_result *)((char *)data + 24);
  }
  v10.l_.a3_.t_.m_object = (vostok::configs::binary_config *)v5;
  vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v10.l_.a3_,
    &other);
  boost::bind<void,vostok::sound::composite_sound_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>,vostok::sound::composite_sound_cook *,boost::arg<1>,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>(
    &result,
    (void (__thiscall *__ptr64)(vostok::sound::composite_sound_cook *, vostok::resources::queries_result *, vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>))(unsigned int)vostok::sound::composite_sound_cook::on_sounds_loaded,
    a1,
    1_24,
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>)v10.l_.a3_.t_.m_object);
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::animation::skeleton_animation_scene_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>,boost::_bi::list3<boost::_bi::value<vostok::animation::skeleton_animation_scene_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>>>::bind_t<void,boost::_mfi::mf2<void,vostok::animation::skeleton_animation_scene_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>,boost::_bi::list3<boost::_bi::value<vostok::animation::skeleton_animation_scene_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>>>(
    (const boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::rifle_scope_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> const &>,boost::_bi::list3<boost::_bi::value<survarium::rifle_scope_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> > > > *)&result,
    &__that);
  callback.vtable = 0;
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::animation::skeleton_animation_scene_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>,boost::_bi::list3<boost::_bi::value<vostok::animation::skeleton_animation_scene_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>>>::bind_t<void,boost::_mfi::mf2<void,vostok::animation::skeleton_animation_scene_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>,boost::_bi::list3<boost::_bi::value<vostok::animation::skeleton_animation_scene_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>>>(
    &__that,
    &v10);
  boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::sound::composite_sound_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>,boost::_bi::list3<boost::_bi::value<vostok::sound::composite_sound_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>>>>(
    v8,
    (int)&callback,
    v10);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&__that.l_.a3_);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&result.l_.a3_);
  vostok::resources::query_resources(
    requests.m_begin,
    requests.m_end - requests.m_begin,
    &vostok::memory::g_resources_unmanaged_allocator,
    0,
    (const vostok::variant<32> **)parent,
    assert_on_fail_true);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v9,
    (int *)&callback);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&other);
}
