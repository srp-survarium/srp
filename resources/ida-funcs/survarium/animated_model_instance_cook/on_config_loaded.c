void __thiscall survarium::animated_model_instance_cook::on_config_loaded(
        survarium::animated_model_instance_cook *this,
        vostok::resources::queries_result *data)
{
  vostok::resources::query_result_for_cook *m_result; // ecx
  vostok::resources::query_result_for_cook *m_parent_query; // edi
  vostok::particle::particle_system_instance_impl *m_object; // esi
  vostok::configs::binary_config_value *v5; // esi
  const char *pointer; // ebx
  const vostok::variant<32> **v7; // edi
  int m_helper_storage; // esi
  vostok::variant<32> *v9; // ecx
  boost::function<void __cdecl(vostok::resources::queries_result &)> *v10; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v11; // ecx
  vostok::variant<32> *v12; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::animated_model_instance_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::animated_model_instance_cook *>,boost::arg<1> > > v13; // [esp-8h] [ebp-1B8h]
  const char *v14; // [esp-4h] [ebp-1B4h]
  vostok::variant<32> *v15; // [esp-4h] [ebp-1B4h]
  int v16; // [esp+0h] [ebp-1B0h]
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v17; // [esp+10h] [ebp-1A0h] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v18; // [esp+14h] [ebp-19Ch] BYREF
  vostok::physics::world *out_value; // [esp+18h] [ebp-198h] BYREF
  survarium::animated_model_instance_cook *v20; // [esp+1Ch] [ebp-194h]
  vostok::resources::query_result_for_cook *v21; // [esp+20h] [ebp-190h]
  const vostok::variant<32> *v22[3]; // [esp+24h] [ebp-18Ch] BYREF
  vostok::resources::request v23; // [esp+30h] [ebp-180h] BYREF
  survarium::pure_game_effect_emitter_base *v24; // [esp+38h] [ebp-178h]
  int v25; // [esp+3Ch] [ebp-174h]
  int v26; // [esp+40h] [ebp-170h]
  int v27; // [esp+44h] [ebp-16Ch]
  _BYTE v28[40]; // [esp+48h] [ebp-168h] BYREF
  int v29; // [esp+70h] [ebp-140h]
  int v30; // [esp+74h] [ebp-13Ch]
  int v31[8]; // [esp+78h] [ebp-138h] BYREF
  _DWORD v32[3]; // [esp+98h] [ebp-118h] BYREF
  _BYTE v33[260]; // [esp+A4h] [ebp-10Ch] BYREF
  _BYTE v34[8]; // [esp+1A8h] [ebp-8h] BYREF

  v20 = this;
  m_result = (vostok::resources::query_result_for_cook *)data->m_result;
  m_parent_query = data->m_parent_query;
  v21 = m_parent_query;
  if ( m_result == (vostok::resources::query_result_for_cook *)1 )
  {
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      &v17,
      (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data->m_queries[0].m_unmanaged_resource);
    m_object = (vostok::particle::particle_system_instance_impl *)v17.m_object;
    v18.m_object = 0;
    if ( v17.m_object )
    {
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v18);
      v18.m_object = m_object;
      _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
    }
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v17);
    v5 = vostok::configs::binary_config_value::operator[](
           (vostok::configs::binary_config_value *)v18.m_object->m_lods[0].m_template.m_object,
           "models");
    pointer = (const char *)vostok::configs::binary_config_value::operator[](v5, "render_animated_model")->data.pointer;
    v17.m_object = (survarium::pure_game_effect_emitter_base *)vostok::configs::binary_config_value::operator[](
                                                                 v5,
                                                                 "physics_animated_model")->data.pointer;
    v14 = (const char *)vostok::configs::binary_config_value::operator[](v5, "damage_collision_object")->data.pointer;
    v32[0] = v33;
    v32[1] = v33;
    v32[2] = v34;
    v33[0] = 0;
    v34[0] = 47;
    vostok::fs_new::path_string_impl::assignf(
      v32,
      (vostok::buffer_string *)v34,
      (vostok::buffer_string *)"resources/models/%s.skinned_model/hit_targets",
      v14);
    v7 = (const vostok::variant<32> **)v21;
    m_helper_storage = (int)v21->m_user_data->m_helper_storage;
    out_value = 0;
    vostok::variant<32>::try_get<vostok::physics::world *>(v15, m_helper_storage, &out_value);
    v29 = 0;
    v30 = 0;
    vostok::variant<32>::set<vostok::physics::world *>(v9, (int)v28, &out_value);
    v13.l_.a1_.t_ = v20;
    v22[1] = (const vostok::variant<32> *)v28;
    v24 = v17.m_object;
    v26 = v32[0];
    v22[0] = 0;
    v22[2] = 0;
    v13.f_.f_ = (void (__thiscall *)(survarium::animated_model_instance_cook *, vostok::resources::queries_result *))vostok::animation::mixing::binary_tree_null_weight_searcher::visit;
    v23.path = pointer;
    v23.id = render_animated_model_instance_class;
    v25 = 95;
    v27 = 32;
    boost::function<void __cdecl (vostok::resources::queries_result &)>::function<void __cdecl (vostok::resources::queries_result &)>(
      v10,
      (boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::animated_model_instance_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::animated_model_instance_cook *>,boost::arg<1> > > *)v31,
      v13,
      v16);
    vostok::resources::query_resources(
      &v23,
      3u,
      &vostok::memory::g_resources_unmanaged_allocator,
      v22,
      v7,
      assert_on_fail_true);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v11, v31);
    vostok::variant<32>::destroy_previous_variable_if_needed(v12, (int)v28);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v18);
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
