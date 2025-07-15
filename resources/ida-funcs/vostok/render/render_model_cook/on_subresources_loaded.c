void __thiscall vostok::render::render_model_cook::on_subresources_loaded(
        vostok::render::render_model_cook *this,
        vostok::resources::queries_result *data,
        vostok::render::cook_intermediate_data *cook_data)
{
  volatile int m_result; // edx
  vostok::particle::particle_system_instance_impl *m_object; // esi
  vostok::resources::unmanaged_resource *v5; // esi
  unsigned __int16 pointer; // ax
  int *v7; // eax
  volatile int v8; // edi
  int v9; // eax
  vostok::resources::managed_resource *v10; // ecx
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *managed_resource; // eax
  vostok::particle::particle_system_instance_impl *v12; // esi
  vostok::render::cook_intermediate_data *v13; // esi
  vostok::resources::pinned_ptr_mutable<unsigned char> *v14; // ecx
  vostok::render::skeleton_render_model *v15; // ecx
  vostok::resources::pinned_ptr_const<unsigned char> *v16; // ecx
  bool v17; // zf
  boost::function<void __cdecl(vostok::resources::queries_result &)> *v18; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v19; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::render::render_model_cook,vostok::resources::queries_result &,vostok::render::cook_intermediate_data *>,boost::_bi::list3<boost::_bi::value<vostok::render::render_model_cook *>,boost::arg<1>,boost::_bi::value<vostok::render::cook_intermediate_data *> > > v20; // [esp-10h] [ebp-1C8h]
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v21; // [esp-4h] [ebp-1BCh] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v22; // [esp+Ch] [ebp-1ACh] BYREF
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v23; // [esp+10h] [ebp-1A8h] BYREF
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *other; // [esp+14h] [ebp-1A4h]
  vostok::resources::query_result *v25; // [esp+18h] [ebp-1A0h]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v26; // [esp+1Ch] [ebp-19Ch] BYREF
  vostok::resources::managed_resource *m_num_render_models; // [esp+20h] [ebp-198h]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v28; // [esp+24h] [ebp-194h] BYREF
  vostok::render::cook_intermediate_data *cook_dataa; // [esp+28h] [ebp-190h]
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v30; // [esp+2Ch] [ebp-18Ch] BYREF
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> ptr; // [esp+30h] [ebp-188h] BYREF
  vostok::render::cook_intermediate_data *v32; // [esp+34h] [ebp-184h]
  vostok::render::cook_intermediate_data *v33; // [esp+38h] [ebp-180h]
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v34; // [esp+3Ch] [ebp-17Ch] BYREF
  volatile int v35; // [esp+40h] [ebp-178h]
  _DWORD v36[3]; // [esp+44h] [ebp-174h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::render::render_model_cook,vostok::resources::queries_result &,vostok::render::cook_intermediate_data *>,boost::_bi::list3<boost::_bi::value<vostok::render::render_model_cook *>,boost::arg<1>,boost::_bi::value<vostok::render::cook_intermediate_data *> > > f; // [esp+50h] [ebp-168h] BYREF
  vostok::memory::writer v38; // [esp+74h] [ebp-144h] BYREF
  const char *v39[3]; // [esp+A0h] [ebp-118h] BYREF
  _BYTE v40[260]; // [esp+ACh] [ebp-10Ch] BYREF
  char v41; // [esp+1B0h] [ebp-8h] BYREF

  m_result = data->m_result;
  cook_dataa = (vostok::render::cook_intermediate_data *)this;
  if ( m_result == 1 )
  {
    m_num_render_models = (vostok::resources::managed_resource *)cook_data->m_num_render_models;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      &v23,
      (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data->m_queries[0].m_unmanaged_resource);
    m_object = (vostok::particle::particle_system_instance_impl *)v23.m_object;
    v28.m_object = 0;
    if ( v23.m_object )
    {
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v28);
      v28.m_object = m_object;
      _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
    }
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v23);
    v5 = v28.m_object->m_lods[0].m_template.m_object;
    v23.m_object = (survarium::pure_game_effect_emitter_base *)1;
    pointer = (unsigned __int16)vostok::configs::binary_config_value::operator[](
                                  (vostok::configs::binary_config_value *)v5,
                                  "type")->data.pointer;
    if ( cook_dataa->root_model_path.m_string.m_max_end == (char *)26 )
      pointer = 200;
    vostok::render::model_factory::create_render_model(pointer);
    v8 = (volatile int)v7;
    v9 = *v7;
    v35 = v8;
    (*(void (__thiscall **)(volatile int, vostok::resources::unmanaged_resource *))(v9 + 28))(v8, v5);
    v22.m_object = 0;
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v22);
    _InterlockedExchangeAdd((volatile signed __int32 *)(v8 + 208), 1u);
    v22.m_object = (vostok::particle::particle_system_instance_impl *)cook_data->result_model.m_object;
    cook_data->result_model.m_object = (vostok::render::render_model *)v8;
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v22);
    v10 = m_num_render_models;
    if ( m_num_render_models )
    {
      v22.m_object = 0;
      other = (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data->m_queries[1].m_unmanaged_resource;
      v25 = &data->m_queries[1];
      do
      {
        vostok::memory::writer::writer(&v38, vostok::render::g_allocator);
        managed_resource = vostok::resources::query_result_for_user::get_managed_resource(v25, &v34);
        vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::operator=(
          managed_resource,
          (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)((char *)v22.m_object + (unsigned int)cook_data->assets));
        vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v34);
        ++v23.m_object;
        other += 184;
        ++v25;
        vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
          &v30,
          other);
        v12 = (vostok::particle::particle_system_instance_impl *)v30.m_object;
        v26.m_object = 0;
        if ( v30.m_object )
        {
          vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v26);
          v26.m_object = v12;
          _InterlockedExchangeAdd(&v12->m_reference_count, 1u);
        }
        vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
          (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&v26,
          (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)((char *)&v22.m_object->m_flags + (unsigned int)cook_data->assets));
        vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v26);
        vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v30);
        ++v23.m_object;
        ++v25;
        other += 184;
        vostok::memory::writer::~writer(&v38);
        v22.m_object = (vostok::particle::particle_system_instance_impl *)((char *)v22.m_object + 288);
        m_num_render_models = (vostok::resources::managed_resource *)((char *)m_num_render_models - 1);
      }
      while ( m_num_render_models );
      v8 = v35;
    }
    v13 = cook_dataa;
    if ( cook_dataa->root_model_path.m_string.m_max_end == (char *)20 )
    {
      v21.m_object = v10;
      vostok::resources::query_result_for_user::get_managed_resource(&data->m_queries[(int)v23.m_object], &v21);
      vostok::resources::pinned_ptr_const<unsigned char>::pinned_ptr_const<unsigned char>(
        v14,
        (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>)&ptr,
        v21);
      v36[0] = v32;
      v36[1] = v32;
      v36[2] = v33;
      vostok::render::skeleton_render_model::load_bones(v15, (vostok::memory::reader *)v8, v36);
      vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>::~pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>(v16);
      v13 = cook_dataa;
    }
    v17 = !cook_data->material_data_ready;
    cook_data->render_model_data_ready = 1;
    if ( !v17 )
      vostok::render::render_model_cook::query_materail_effects(
        (vostok::render::render_model_cook *)v10,
        v13,
        cook_data);
    v21.m_object = (vostok::resources::managed_resource *)cook_data->root_model_path.m_string.m_begin;
    v39[0] = v40;
    v39[1] = v40;
    v39[2] = &v41;
    v40[0] = 0;
    v41 = 47;
    vostok::fs_new::path_string_impl::assignf(
      v39,
      (vostok::buffer_string *)v10,
      (vostok::buffer_string *)&(&stru_809F70.vtable)[1],
      (const char *)v21.m_object);
    v32 = v13;
    ptr.m_object = (vostok::resources::managed_resource *)vostok::render::render_model_cook::on_model_settings_loaded;
    v33 = cook_data;
    v20.l_.a1_.t_ = (vostok::render::render_model_cook *)vostok::render::render_model_cook::on_model_settings_loaded;
    v20.l_.a3_.t_ = v13;
    v20.f_.f_ = (void (__thiscall *)(vostok::render::render_model_cook *, vostok::resources::queries_result *, vostok::render::cook_intermediate_data *))&f;
    boost::function<void __cdecl (vostok::resources::queries_result &)>::function<void __cdecl (vostok::resources::queries_result &)>(
      v18,
      v20,
      (int)cook_data);
    vostok::resources::query_resource(
      v39[0],
      (vostok::variant<32> *)0x20,
      vostok::render::g_allocator,
      0,
      (const vostok::variant<32> **)cook_data->parent_query,
      assert_on_fail_true);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v19,
      (int *)&f);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v28);
  }
  else
  {
    v21.m_object = (vostok::resources::managed_resource *)cook_data;
    cook_data->status_failed = 1;
    vostok::render::render_model_cook::query_materail_effects(
      this,
      (vostok::render::cook_intermediate_data *)this,
      (vostok::render::cook_intermediate_data *)v21.m_object);
  }
}
