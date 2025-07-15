void __thiscall vostok::render::skeleton_model_instance_cook::on_skeleton_config_loaded(
        vostok::render::skeleton_model_instance_cook *this,
        vostok::resources::queries_result *result,
        vostok::render::skeleton_model_instance_cook_data *cook_data)
{
  vostok::resources::query_result_for_cook *m_result; // ecx
  vostok::particle::particle_system_instance_impl *m_object; // esi
  char **v5; // eax
  vostok::fixed_string<260> *v6; // ecx
  boost::function<void __cdecl(vostok::resources::queries_result &)> *v7; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v8; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::render::skeleton_model_instance_cook,vostok::resources::queries_result &,vostok::render::skeleton_model_instance_cook_data *>,boost::_bi::list3<boost::_bi::value<vostok::render::skeleton_model_instance_cook *>,boost::arg<1>,boost::_bi::value<vostok::render::skeleton_model_instance_cook_data *> > > v9; // [esp-10h] [ebp-170h]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v10; // [esp+10h] [ebp-150h] BYREF
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v11; // [esp+14h] [ebp-14Ch] BYREF
  vostok::render::skeleton_model_instance_cook_data *v12; // [esp+18h] [ebp-148h]
  void (__thiscall *v13)(vostok::render::skeleton_model_instance_cook *, vostok::resources::queries_result *, vostok::render::skeleton_model_instance_cook_data *); // [esp+1Ch] [ebp-144h]
  vostok::render::skeleton_model_instance_cook_data *v14; // [esp+20h] [ebp-140h]
  vostok::render::skeleton_model_instance_cook_data *v15; // [esp+24h] [ebp-13Ch]
  int f[8]; // [esp+28h] [ebp-138h] BYREF
  vostok::buffer_string v17[22]; // [esp+48h] [ebp-118h] BYREF
  char v18; // [esp+158h] [ebp-8h]

  v12 = (vostok::render::skeleton_model_instance_cook_data *)this;
  m_result = (vostok::resources::query_result_for_cook *)result->m_result;
  if ( m_result == (vostok::resources::query_result_for_cook *)1 )
  {
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      &v11,
      (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&result->m_queries[0].m_unmanaged_resource);
    m_object = (vostok::particle::particle_system_instance_impl *)v11.m_object;
    v10.m_object = 0;
    if ( v11.m_object )
    {
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v10);
      v10.m_object = m_object;
      _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
    }
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v11);
    v5 = (char **)vostok::configs::binary_config_value::operator[](
                    (vostok::configs::binary_config_value *)v10.m_object->m_lods[0].m_template.m_object,
                    "skeleton");
    vostok::fixed_string<260>::fixed_string<260>(v6, v17, *v5);
    v14 = v12;
    v13 = vostok::render::skeleton_model_instance_cook::on_skeleton_loaded;
    v15 = cook_data;
    v9.l_.a1_.t_ = (vostok::render::skeleton_model_instance_cook *)vostok::render::skeleton_model_instance_cook::on_skeleton_loaded;
    v9.l_.a3_.t_ = v12;
    v9.f_.f_ = (void (__thiscall *)(vostok::render::skeleton_model_instance_cook *, vostok::resources::queries_result *, vostok::render::skeleton_model_instance_cook_data *))f;
    v18 = 47;
    boost::function<void __cdecl (vostok::resources::queries_result &)>::function<void __cdecl (vostok::resources::queries_result &)>(
      v7,
      v9,
      (int)cook_data);
    vostok::resources::query_resource(
      v17[0].m_begin,
      (vostok::variant<32> *)0x2D,
      vostok::render::g_allocator,
      0,
      (const vostok::variant<32> **)cook_data->parent_query,
      assert_on_fail_true);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v8, f);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v10);
  }
  else
  {
    vostok::resources::query_result_for_cook::finish_query_impl(
      m_result,
      (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)cook_data->parent_query,
      result_success,
      assert_on_fail_true,
      result_out_of_memory|0x8);
  }
}
