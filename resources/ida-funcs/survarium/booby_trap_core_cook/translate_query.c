void __thiscall survarium::booby_trap_core_cook::translate_query(
        survarium::booby_trap_core_cook *this,
        const vostok::variant<32> **parent)
{
  vostok::variant<32> *v2; // eax
  vostok::configs::binary_config_value *v3; // eax
  boost::function1<void,vostok::resources::queries_result &> *v4; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v5; // ecx
  _BYTE v6[28]; // [esp-1Ch] [ebp-1A4h] BYREF
  survarium::booby_trap_core_query_data out_value; // [esp+10h] [ebp-178h] BYREF
  survarium::booby_trap_core_cook *f; // [esp+1Ch] [ebp-16Ch]
  void (__thiscall *__ptr64 f_4)(survarium::booby_trap_core_cook *, vostok::resources::queries_result *, vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>, vostok::physics::world *, void *); // [esp+20h] [ebp-168h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf4<void,survarium::booby_trap_core_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>,vostok::physics::world *,void *>,boost::_bi::list5<boost::_bi::value<survarium::booby_trap_core_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::value<vostok::physics::world *>,boost::_bi::value<void *> > > __that; // [esp+28h] [ebp-160h] BYREF
  int v11[8]; // [esp+40h] [ebp-148h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf4<void,survarium::booby_trap_core_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>,vostok::physics::world *,void *>,boost::_bi::list5<boost::_bi::value<survarium::booby_trap_core_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::value<vostok::physics::world *>,boost::_bi::value<void *> > > result; // [esp+60h] [ebp-128h] BYREF
  _DWORD v13[3]; // [esp+78h] [ebp-110h] BYREF
  _BYTE v14[260]; // [esp+84h] [ebp-104h] BYREF
  char vars0; // [esp+188h] [ebp+0h] BYREF

  out_value.config.m_object = 0;
  v2 = (vostok::variant<32> *)parent[66];
  f = this;
  vostok::variant<32>::try_get<survarium::booby_trap_core_query_data>(
    v2,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&out_value);
  v3 = vostok::configs::binary_config_value::operator[](out_value.config.m_object->m_root, "data");
  *(_DWORD *)&v6[24] = vostok::configs::binary_config_value::operator[](v3, "model_armed")->data.pointer;
  v13[0] = v14;
  v13[1] = v14;
  v13[2] = &vars0;
  v14[0] = 0;
  vostok::fs_new::path_string_impl::assignf(
    v13,
    (vostok::buffer_string *)&vars0,
    (vostok::buffer_string *)"resources/models/%s.model/render/export_properties",
    *(const char **)&v6[24]);
  *(_DWORD *)&v6[24] = 0;
  LODWORD(f_4) = v14;
  *(_DWORD *)&v6[20] = survarium::booby_trap_core_cook::on_subresources_loaded;
  *(_DWORD *)&v6[16] = out_value.game_world;
  *(_DWORD *)&v6[12] = out_value.physics_world;
  HIDWORD(f_4) = 32;
  *(_DWORD *)&v6[8] = 0;
  vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v6[8],
    (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&out_value);
  *(_DWORD *)&v6[4] = (unsigned __int8)1_133;
  *(_DWORD *)v6 = f;
  boost::bind<void,survarium::booby_trap_core_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>,vostok::physics::world *,void *,survarium::booby_trap_core_cook *,boost::arg<1>,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>,vostok::physics::world *,void *>(
    &result,
    *(void (__thiscall *__ptr64 *)(survarium::booby_trap_core_cook *, vostok::resources::queries_result *, vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>, vostok::physics::world *, void *))v6,
    *(survarium::booby_trap_core_cook **)&v6[8],
    *(int *)&v6[12],
    *(vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *)&v6[16],
    *(vostok::physics::world **)&v6[20],
    *(void **)&v6[24]);
  boost::_bi::bind_t<void,boost::_mfi::mf4<void,survarium::booby_trap_core_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>,vostok::physics::world *,void *>,boost::_bi::list5<boost::_bi::value<survarium::booby_trap_core_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>,boost::_bi::value<vostok::physics::world *>,boost::_bi::value<void *>>>::bind_t<void,boost::_mfi::mf4<void,survarium::booby_trap_core_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>,vostok::physics::world *,void *>,boost::_bi::list5<boost::_bi::value<survarium::booby_trap_core_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>,boost::_bi::value<vostok::physics::world *>,boost::_bi::value<void *>>>(
    &__that,
    &result);
  v11[0] = 0;
  boost::_bi::bind_t<void,boost::_mfi::mf4<void,survarium::booby_trap_core_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>,vostok::physics::world *,void *>,boost::_bi::list5<boost::_bi::value<survarium::booby_trap_core_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>,boost::_bi::value<vostok::physics::world *>,boost::_bi::value<void *>>>::bind_t<void,boost::_mfi::mf4<void,survarium::booby_trap_core_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>,vostok::physics::world *,void *>,boost::_bi::list5<boost::_bi::value<survarium::booby_trap_core_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>,boost::_bi::value<vostok::physics::world *>,boost::_bi::value<void *>>>(
    (boost::_bi::bind_t<void,boost::_mfi::mf4<void,survarium::booby_trap_core_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>,vostok::physics::world *,void *>,boost::_bi::list5<boost::_bi::value<survarium::booby_trap_core_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::value<vostok::physics::world *>,boost::_bi::value<void *> > > *)&v6[4],
    &__that);
  boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf4<void,survarium::booby_trap_core_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>,vostok::physics::world *,void *>,boost::_bi::list5<boost::_bi::value<survarium::booby_trap_core_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>,boost::_bi::value<vostok::physics::world *>,boost::_bi::value<void *>>>>(
    v4,
    (int)v11,
    *(boost::_bi::bind_t<void,boost::_mfi::mf4<void,survarium::booby_trap_core_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>,vostok::physics::world *,void *>,boost::_bi::list5<boost::_bi::value<survarium::booby_trap_core_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::value<vostok::physics::world *>,boost::_bi::value<void *> > > *)&v6[4]);
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
