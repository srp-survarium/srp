void __thiscall vostok::physics::animated_model_instance_cook::on_config_loaded(
        vostok::physics::animated_model_instance_cook *this,
        vostok::resources::queries_result *data)
{
  vostok::resources::query_result_for_cook *m_result; // ecx
  vostok::resources::query_result_for_cook *m_parent_query; // edi
  vostok::particle::particle_system_instance_impl *m_object; // esi
  vostok::configs::binary_config_value *v6; // eax
  boost::function<void __cdecl(vostok::resources::queries_result &)> *v7; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v8; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::physics::animated_model_instance_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::physics::animated_model_instance_cook *>,boost::arg<1> > > v9; // [esp-8h] [ebp-158h]
  const char *pointer; // [esp-4h] [ebp-154h]
  boost::function<void __cdecl(vostok::resources::queries_result &)> *v11; // [esp-4h] [ebp-154h]
  int v12; // [esp+0h] [ebp-150h]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v13; // [esp+Ch] [ebp-144h] BYREF
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v14; // [esp+10h] [ebp-140h] BYREF
  vostok::resources::query_result_for_cook *parent; // [esp+14h] [ebp-13Ch]
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+18h] [ebp-138h] BYREF
  char *request_path[3]; // [esp+38h] [ebp-118h] BYREF
  _BYTE v18[260]; // [esp+44h] [ebp-10Ch] BYREF
  _BYTE v19[8]; // [esp+148h] [ebp-8h] BYREF

  m_result = (vostok::resources::query_result_for_cook *)data->m_result;
  m_parent_query = data->m_parent_query;
  parent = m_parent_query;
  if ( m_result == (vostok::resources::query_result_for_cook *)1 )
  {
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      &v14,
      (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data->m_queries[0].m_unmanaged_resource);
    m_object = (vostok::particle::particle_system_instance_impl *)v14.m_object;
    v13.m_object = 0;
    if ( v14.m_object )
    {
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v13);
      v13.m_object = m_object;
      _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
    }
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v14);
    v6 = vostok::configs::binary_config_value::operator[](
           (vostok::configs::binary_config_value *)v13.m_object->m_lods[0].m_template.m_object,
           "attributes");
    pointer = (const char *)vostok::configs::binary_config_value::operator[](v6, "skeleton")->data.pointer;
    request_path[0] = v18;
    request_path[1] = v18;
    request_path[2] = v19;
    v18[0] = 0;
    v19[0] = 47;
    vostok::fs_new::path_string_impl::assignf(
      (int)request_path,
      (vostok::buffer_string *)v19,
      (vostok::buffer_string *)&stru_8010B4,
      pointer);
    v7 = v11;
    v9.l_.a1_.t_ = this;
    v9.f_.f_ = vostok::physics::animated_model_instance_cook::on_skeleton_config_loaded;
    boost::function<void __cdecl (vostok::resources::queries_result &)>::function<void __cdecl (vostok::resources::queries_result &)>(
      v7,
      (boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::physics::animated_model_instance_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::physics::animated_model_instance_cook *>,boost::arg<1> > > *)&callback,
      v9,
      v12);
    vostok::resources::query_resource(
      request_path[0],
      &callback,
      (vostok::variant<32> *)0x20,
      this->m_allocator,
      0,
      parent,
      assert_on_fail_true);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v8,
      (int *)&callback);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v13);
  }
  else
  {
    vostok::resources::query_result_for_cook::finish_query_impl(
      m_result,
      (const vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)m_parent_query,
      result_success,
      assert_on_fail_true,
      result_out_of_memory|0x8);
  }
}
