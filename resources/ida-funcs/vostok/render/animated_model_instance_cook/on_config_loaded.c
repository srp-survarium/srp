void __thiscall vostok::render::animated_model_instance_cook::on_config_loaded(
        vostok::render::animated_model_instance_cook *this,
        vostok::resources::queries_result *data)
{
  vostok::resources::query_result_for_cook *m_result; // ecx
  const vostok::variant<32> **m_parent_query; // edi
  vostok::particle::particle_system_instance_impl *m_object; // esi
  vostok::configs::binary_config_value *v5; // eax
  const char *pointer; // esi
  vostok::buffer_string *v7; // ecx
  vostok::buffer_string *v8; // ecx
  boost::function<void __cdecl(vostok::resources::queries_result &)> *v9; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v10; // ecx
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v11; // [esp-10h] [ebp-288h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::render::animated_model_instance_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::list3<boost::_bi::value<vostok::render::animated_model_instance_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> > > > v12; // [esp-Ch] [ebp-284h] BYREF
  int v13; // [esp+0h] [ebp-278h]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v14; // [esp+8h] [ebp-270h] BYREF
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v15; // [esp+Ch] [ebp-26Ch] BYREF
  const vostok::variant<32> **v16; // [esp+10h] [ebp-268h]
  vostok::render::animated_model_instance_cook *a1; // [esp+14h] [ebp-264h]
  vostok::resources::request v18; // [esp+18h] [ebp-260h] BYREF
  vostok::configs::binary_config *v19; // [esp+20h] [ebp-258h]
  int v20; // [esp+24h] [ebp-254h]
  int v21[8]; // [esp+28h] [ebp-250h] BYREF
  _DWORD v22[3]; // [esp+48h] [ebp-230h] BYREF
  _BYTE v23[260]; // [esp+54h] [ebp-224h] BYREF
  char v24; // [esp+158h] [ebp-120h] BYREF
  vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> a3; // [esp+160h] [ebp-118h] BYREF
  _BYTE *v26; // [esp+164h] [ebp-114h]
  char *v27; // [esp+168h] [ebp-110h]
  _BYTE v28[260]; // [esp+16Ch] [ebp-10Ch] BYREF
  char v29; // [esp+270h] [ebp-8h] BYREF

  a1 = this;
  m_result = (vostok::resources::query_result_for_cook *)data->m_result;
  m_parent_query = (const vostok::variant<32> **)data->m_parent_query;
  v16 = m_parent_query;
  if ( m_result == (vostok::resources::query_result_for_cook *)1 )
  {
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      &v15,
      (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data->m_queries[0].m_unmanaged_resource);
    m_object = (vostok::particle::particle_system_instance_impl *)v15.m_object;
    v14.m_object = 0;
    if ( v15.m_object )
    {
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v14);
      v14.m_object = m_object;
      _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
    }
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v15);
    v5 = vostok::configs::binary_config_value::operator[](
           (vostok::configs::binary_config_value *)v14.m_object->m_lods[0].m_template.m_object,
           "attributes");
    pointer = (const char *)vostok::configs::binary_config_value::operator[](v5, "render_model")->data.pointer;
    v22[0] = v23;
    v22[1] = v23;
    v22[2] = &v24;
    v23[0] = 0;
    v24 = 47;
    vostok::fs_new::path_string_impl::assignf(v22, v7, (vostok::buffer_string *)&stru_8010B4, pointer);
    a3.m_object = (vostok::configs::binary_config *)v28;
    v26 = v28;
    v27 = &v29;
    v28[0] = 0;
    v29 = 47;
    vostok::fs_new::path_string_impl::assignf(
      &a3,
      v8,
      (vostok::buffer_string *)"resources/models/%s.skinned_model/settings",
      pointer);
    v18.path = (const char *)v22[0];
    v18.id = binary_config_class_impl;
    v20 = 32;
    v11.m_object = (vostok::particle::particle_system_instance_impl *)a3.m_object;
    v19 = a3.m_object;
    v15.m_object = (survarium::pure_game_effect_emitter_base *)&v12;
    vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      &v11,
      &v14);
    boost::bind<void,vostok::render::animated_model_instance_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>,vostok::render::animated_model_instance_cook *,boost::arg<1>,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>(
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v15.m_object,
      (vostok::particle::particle_system_instance_impl *)vostok::render::animated_model_instance_cook::on_skeleton_config_loaded,
      a1,
      1_66,
      v11);
    boost::function<void __cdecl (vostok::resources::queries_result &)>::function<void __cdecl (vostok::resources::queries_result &)>(
      v9,
      v21,
      v12,
      v13);
    vostok::resources::query_resources(
      &v18,
      2u,
      &vostok::memory::g_resources_unmanaged_allocator,
      0,
      v16,
      assert_on_fail_true);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v10, v21);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v14);
  }
  else
  {
    vostok::resources::query_result_for_cook::finish_query_impl(
      m_result,
      (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)m_parent_query,
      result_success,
      assert_on_fail_true,
      result_out_of_memory|0x8);
  }
}
