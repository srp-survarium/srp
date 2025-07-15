void __thiscall vostok::render::material_cook::translate_query(
        vostok::render::material_cook *this,
        vostok::resources::query_result_for_cook *parent)
{
  vostok::variant<32> *m_user_data; // esi
  vostok::render::material_cook *v3; // ecx
  const char *requested_path; // eax
  vostok::buffer_string *v5; // ecx
  boost::function<void __cdecl(vostok::resources::queries_result &)> *v6; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v7; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::render::material_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::render::material_cook *>,boost::arg<1> > > v8; // [esp-8h] [ebp-150h]
  boost::function<void __cdecl(vostok::resources::queries_result &)> *v9; // [esp-4h] [ebp-14Ch]
  int v10; // [esp+0h] [ebp-148h]
  vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> out_value; // [esp+Ch] [ebp-13Ch] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::render::material_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::render::material_cook *>,boost::arg<1> > > v12[4]; // [esp+10h] [ebp-138h] BYREF
  const char *v13[3]; // [esp+30h] [ebp-118h] BYREF
  _BYTE v14[260]; // [esp+3Ch] [ebp-10Ch] BYREF
  char v15; // [esp+140h] [ebp-8h] BYREF

  m_user_data = parent->m_user_data;
  out_value.m_object = (vostok::configs::binary_config *)this;
  if ( m_user_data )
  {
    out_value.m_object = 0;
    vostok::variant<32>::try_get<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>(
      (vostok::variant<32> *)this,
      (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)m_user_data,
      (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&out_value);
    vostok::render::material_cook::on_material_binary_config_loaded(
      v3,
      parent,
      (vostok::particle::particle_system_instance_impl *)out_value.m_object);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&out_value);
  }
  else
  {
    v13[0] = v14;
    v13[1] = v14;
    v13[2] = &v15;
    v14[0] = 0;
    v15 = 47;
    requested_path = vostok::resources::query_result_for_user::get_requested_path(parent);
    vostok::fs_new::path_string_impl::assignf(
      v13,
      v5,
      (vostok::buffer_string *)"resources/material_instances/%s.material",
      requested_path);
    v6 = v9;
    v8.l_.a1_.t_ = (vostok::render::material_cook *)out_value.m_object;
    v8.f_.f_ = (void (__thiscall *)(vostok::render::material_cook *, vostok::resources::queries_result *))vostok::render::material_cook::on_material_config_loaded;
    boost::function<void __cdecl (vostok::resources::queries_result &)>::function<void __cdecl (vostok::resources::queries_result &)>(
      v6,
      v12,
      v8,
      v10);
    vostok::resources::query_resource(
      v13[0],
      (vostok::variant<32> *)0x20,
      vostok::render::g_allocator,
      0,
      (const vostok::variant<32> **)parent,
      assert_on_fail_true);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v7,
      (int *)v12);
  }
}
