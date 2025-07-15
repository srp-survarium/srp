void __thiscall survarium::grenade_core_cook::translate_query(
        survarium::grenade_core_cook *this,
        const vostok::variant<32> **parent)
{
  const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *v2; // esi
  vostok::configs::binary_config_value *v3; // eax
  boost::function1<void,vostok::resources::queries_result &> *v4; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v5; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::grenade_core_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>,void *>,boost::_bi::list4<boost::_bi::value<survarium::grenade_core_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::value<void *> > > v6; // [esp-18h] [ebp-198h] BYREF
  survarium::grenade_cook_data out_value; // [esp+Ch] [ebp-174h] BYREF
  survarium::grenade_core_cook *f; // [esp+14h] [ebp-16Ch]
  void (__thiscall *__ptr64 f_4)(survarium::weapon_core_cook *, vostok::resources::queries_result *, vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>, survarium::weapon_core *); // [esp+18h] [ebp-168h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::weapon_core_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>,survarium::weapon_core *>,boost::_bi::list4<boost::_bi::value<survarium::weapon_core_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::value<survarium::weapon_core *> > > __that; // [esp+20h] [ebp-160h] BYREF
  int v11[8]; // [esp+38h] [ebp-148h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::weapon_core_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>,survarium::weapon_core *>,boost::_bi::list4<boost::_bi::value<survarium::weapon_core_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::value<survarium::weapon_core *> > > result; // [esp+58h] [ebp-128h] BYREF
  _DWORD v13[3]; // [esp+70h] [ebp-110h] BYREF
  _BYTE v14[260]; // [esp+7Ch] [ebp-104h] BYREF
  char vars0; // [esp+180h] [ebp+0h] BYREF

  out_value.config.m_object = 0;
  v2 = (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)parent[66];
  f = this;
  vostok::variant<32>::try_get<survarium::grenade_cook_data>(
    (vostok::variant<32> *)this,
    v2,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&out_value);
  v3 = vostok::configs::binary_config_value::operator[](out_value.config.m_object->m_root, "data");
  *((_DWORD *)&v6.l_ + 3) = vostok::configs::binary_config_value::operator[](v3, "model")->data.pointer;
  v13[0] = v14;
  v13[1] = v14;
  v13[2] = &vars0;
  v14[0] = 0;
  vostok::fs_new::path_string_impl::assignf(
    v13,
    (vostok::buffer_string *)&vars0,
    (vostok::buffer_string *)"resources/models/%s.model/settings",
    *((const char **)&v6.l_ + 3));
  *((_DWORD *)&v6.l_ + 3) = 0;
  LODWORD(f_4) = v13[0];
  v6.l_.a4_.t_ = survarium::grenade_core_cook::on_subresources_loaded;
  v6.l_.a3_.t_.m_object = (vostok::configs::binary_config *)out_value.game_world;
  v6.l_.a1_.t_ = 0;
  HIDWORD(f_4) = 32;
  vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v6.l_,
    (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&out_value);
  HIDWORD(v6.f_.f_) = (unsigned __int8)1_135;
  LODWORD(v6.f_.f_) = f;
  boost::bind<void,survarium::grenade_core_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>,void *,survarium::grenade_core_cook *,boost::arg<1>,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>,void *>(
    &result,
    (void (__thiscall *__ptr64)(survarium::weapon_core_cook *, vostok::resources::queries_result *, vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>, survarium::weapon_core *))v6.f_.f_,
    (survarium::weapon_core_cook *)v6.l_.a1_.t_,
    (int)v6.l_.a3_.t_.m_object,
    (vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>)v6.l_.a4_.t_,
    *((survarium::weapon_core **)&v6.l_ + 3));
  boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::grenade_core_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>,void *>,boost::_bi::list4<boost::_bi::value<survarium::grenade_core_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>,boost::_bi::value<void *>>>::bind_t<void,boost::_mfi::mf3<void,survarium::grenade_core_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>,void *>,boost::_bi::list4<boost::_bi::value<survarium::grenade_core_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>,boost::_bi::value<void *>>>(
    &__that,
    &result);
  v11[0] = 0;
  boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::grenade_core_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>,void *>,boost::_bi::list4<boost::_bi::value<survarium::grenade_core_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>,boost::_bi::value<void *>>>::bind_t<void,boost::_mfi::mf3<void,survarium::grenade_core_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>,void *>,boost::_bi::list4<boost::_bi::value<survarium::grenade_core_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>,boost::_bi::value<void *>>>(
    (boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::weapon_core_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>,survarium::weapon_core *>,boost::_bi::list4<boost::_bi::value<survarium::weapon_core_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::value<survarium::weapon_core *> > > *)&v6,
    &__that);
  boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::grenade_core_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>,void *>,boost::_bi::list4<boost::_bi::value<survarium::grenade_core_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>,boost::_bi::value<void *>>>>(
    v4,
    (int)v11,
    v6);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&__that.l_.a3_);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&result.l_.a3_);
  vostok::resources::query_resources(
    (const vostok::resources::request *)&f_4,
    1u,
    survarium::g_allocator,
    0,
    parent,
    assert_on_fail_true);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v5, v11);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&out_value);
}
