void __thiscall vostok::animation::animation_collection_cook::translate_query(
        vostok::animation::animation_collection_cook *this,
        const vostok::variant<32> **parent)
{
  vostok::variant<32> *v2; // esi
  vostok::resources::query_result_for_cook *v4; // ecx
  vostok::animation::animation_collection_cook *v5; // ecx
  vostok::animation::animation_collection_cook *v6; // ecx
  const char *requested_path; // eax
  vostok::buffer_string *v8; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v9; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::animation::animation_collection_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::animation::animation_collection_cook *>,boost::arg<1> > > v10; // [esp-14h] [ebp-154h] BYREF
  const vostok::variant<32> **v11; // [esp-4h] [ebp-144h]
  vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> config_ptr; // [esp+Ch] [ebp-134h]
  vostok::animation::animation_collection_cook_user_data out_value; // [esp+10h] [ebp-130h] BYREF
  vostok::animation::animation_collection_cook *v14; // [esp+18h] [ebp-128h]
  int v15; // [esp+1Ch] [ebp-124h]
  const char *v16[3]; // [esp+30h] [ebp-110h] BYREF
  _BYTE v17[260]; // [esp+3Ch] [ebp-104h] BYREF
  char vars0; // [esp+140h] [ebp+0h] BYREF

  v2 = (vostok::variant<32> *)parent[66];
  config_ptr.m_object = (vostok::configs::binary_config *)this;
  if ( v2 )
  {
    out_value.cfg_ptr.m_object = 0;
    vostok::variant<32>::try_get<vostok::animation::animation_collection_cook_user_data>(
      (vostok::variant<32> *)this,
      (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)v2,
      (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&out_value);
    vostok::resources::query_result_for_cook::clear_user_data(v4, (int)parent);
    v11 = parent;
    *((_DWORD *)&v10.l_ + 1) = out_value.val;
    v10.l_.a1_.t_ = v5;
    vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v10.l_,
      (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&out_value.cfg_ptr);
    vostok::animation::animation_collection_cook::request_items(
      v6,
      (const vostok::variant<32> *)&vars0,
      (const bool *)&out_value.cfg_ptr,
      (const unsigned int *)&v10.l_,
      config_ptr,
      (const vostok::configs::binary_config_value *)v10.l_.a1_.t_,
      *((vostok::configs::binary_config_value **)&v10.l_ + 1),
      v11);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&out_value.cfg_ptr);
  }
  else
  {
    v16[0] = v17;
    v16[1] = v17;
    v16[2] = &vars0;
    v17[0] = 0;
    requested_path = vostok::resources::query_result_for_user::get_requested_path((vostok::resources::query_result_for_user *)parent);
    vostok::fs_new::path_string_impl::assignf(
      v16,
      v8,
      (vostok::buffer_string *)&stru_7FF1F0,
      "resources/animations/collections/",
      requested_path,
      ".anim_collection");
    v14 = this;
    out_value.val = (const vostok::configs::binary_config_value *)vostok::animation::animation_collection_cook::collection_config_loaded;
    out_value.cfg_ptr.m_object = 0;
    HIDWORD(v10.f_.f_) = vostok::animation::animation_collection_cook::collection_config_loaded;
    v10.l_.a1_.t_ = 0;
    *((_DWORD *)&v10.l_ + 1) = this;
    LODWORD(v10.f_.f_) = &out_value;
    boost::function<void __cdecl (vostok::resources::queries_result &)>::function<void __cdecl (vostok::resources::queries_result &)>(
      0,
      v10,
      v15);
    vostok::resources::query_resource(
      v16[0],
      (vostok::variant<32> *)0x20,
      &vostok::memory::g_resources_unmanaged_allocator,
      0,
      parent,
      assert_on_fail_true);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v9,
      (int *)&out_value);
  }
}
