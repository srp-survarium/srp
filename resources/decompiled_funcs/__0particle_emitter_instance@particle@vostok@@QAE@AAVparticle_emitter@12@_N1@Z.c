void __thiscall vostok::particle::particle_emitter_instance::particle_emitter_instance(
        vostok::particle::particle_emitter_instance *this,
        vostok::particle::particle_emitter *emitter,
        bool is_child_emitter_instance,
        bool need_query_material)
{
  vostok::math::float4x4 *v4; // eax
  vostok::math::float4 *v5; // ecx
  vostok::math::float2 *v6; // ecx
  float v7; // [esp+Ch] [ebp-E4h]
  vostok::network_core::packet_reader *v8; // [esp+Ch] [ebp-E4h]
  float v9; // [esp+Ch] [ebp-E4h]
  vostok::particle::particle_emitter *v10; // [esp+14h] [ebp-DCh]
  survarium::game_options var4C; // [esp+A4h] [ebp-4Ch] BYREF

  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->m_transform);
  this->__vftable = (vostok::particle::particle_emitter_instance_vtbl *)&vostok::particle::particle_emitter_instance::`vftable';
  v4 = (vostok::math::float4x4 *)survarium::weapon_core::cast_weapon_core(&var4C);
  qmemcpy((void *)&this->m_transform, vostok::math::float4x4::identity(v4), sizeof(this->m_transform));
  vostok::math::create_zero_aabb(&this->m_aabbox);
  vostok::math::float4::float4(v5, (int)&this->m_instance_color, (int)clear_value, 1.0, 1.0, 1.0, v7);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)&this->m_particle_list,
    &this->m_particle_list.m_size);
  vostok::threading::mutex::mutex(&this->m_particle_list.vostok::threading::mutex);
  this->m_particle_list.m_first = 0;
  this->m_particle_list.m_last = 0;
  vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>((vostok::render::stage_lights::lights_instance *)&this->m_scene);
  this->m_engine = 0;
  vostok::resources::memory_usage_type::memory_usage_type(
    0,
    (boost::_bi::list2<unsigned char &,vostok::network_core::packet_reader &> **)&this->m_subuv_pos_uv,
    0,
    v8);
  vostok::math::float2::float2(v6, (int)&this->m_subuv_size_uv, (int)clear_value, 1.0, v9);
  vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>((vostok::render::stage_lights::lights_instance *)&this->m_material);
  this->m_particle_world = 0;
  vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>((vostok::render::stage_lights::lights_instance *)&this->m_particle_system_instance_ptr);
  this->m_render_instance = 0;
  this->m_data_type_action = 0;
  this->m_cook_data_to_delete = 0;
  this->m_emitter = emitter;
  this->m_billboard_parameters = 0;
  this->m_beamtrail_parameters = 0;
  this->m_next = 0;
  this->m_num_live_particles = 0;
  this->m_num_created_particles = 0;
  this->m_delay_time = *(float *)&FLOAT_0_0;
  this->m_emitter_time = *(float *)&FLOAT_0_0;
  this->m_current_loop = 0;
  this->m_time_to_create_new_one = *(float *)&FLOAT_0_0;
  this->m_num_particles_to_create = 0;
  this->m_current_max_num_particles = emitter->m_max_num_particles;
  this->m_current_calc_num_max_particles = 0;
  this->m_create_rate = retry_to_increase_quality_period_sec;
  this->m_current_create_rate = retry_to_increase_quality_period_sec;
  this->m_current_duration = vostok::particle::calc_duration(emitter->m_duration, emitter->m_duration_variance);
  this->m_subimage_index = *(float *)&FLOAT_0_0;
  this->m_max_num_particles = emitter->m_max_num_particles;
  this->m_is_child_emitter_instance = is_child_emitter_instance;
  this->m_waiting_for_end = 0;
  this->m_delayed = 0;
  this->m_visible = 1;
  this->m_particle_added = 0;
  for ( var4C.m_conflicted_action_ids._M_impl._M_finish = (survarium::game_action_id *)emitter->m_actions.pointer;
        var4C.m_conflicted_action_ids._M_impl._M_finish;
        var4C.m_conflicted_action_ids._M_impl._M_finish = (survarium::game_action_id *)*((_DWORD *)var4C.m_conflicted_action_ids._M_impl._M_finish
                                                                                       + 2) )
  {
    var4C.m_conflicted_action_ids._M_impl._M_start = (survarium::game_action_id *)__RTDynamicCast(
                                                                                    (void **)var4C.m_conflicted_action_ids._M_impl._M_finish,
                                                                                    0,
                                                                                    (TypeDescriptor *)&vostok::particle::particle_action `RTTI Type Descriptor',
                                                                                    (TypeDescriptor *)&vostok::particle::particle_action_data_type `RTTI Type Descriptor',
                                                                                    0);
    if ( var4C.m_conflicted_action_ids._M_impl._M_start
      && *((_BYTE *)var4C.m_conflicted_action_ids._M_impl._M_start + 16) )
    {
      this->m_data_type_action = (vostok::particle::particle_action_data_type *)var4C.m_conflicted_action_ids._M_impl._M_start;
      var4C.m_conflicted_action_ids._M_impl._M_finish = (survarium::game_action_id *)*((_DWORD *)var4C.m_conflicted_action_ids._M_impl._M_finish
                                                                                     + 2);
      break;
    }
  }
  if ( this->m_data_type_action
    && this->m_data_type_action->get_data_type(this->m_data_type_action) == particle_data_type_billboard )
  {
    this->m_billboard_parameters = (vostok::particle::billboard_parameters *)&this->m_data_type_action[4];
  }
  if ( this->m_data_type_action
    && this->m_data_type_action->get_data_type(this->m_data_type_action) == particle_data_type_trail )
  {
    this->m_beamtrail_parameters = (vostok::particle::beamtrail_parameters *)&this->m_data_type_action[1];
  }
  else if ( this->m_data_type_action
         && this->m_data_type_action->get_data_type(this->m_data_type_action) == particle_data_type_beam )
  {
    this->m_beamtrail_parameters = (vostok::particle::beamtrail_parameters *)&this->m_data_type_action[1];
  }
  this->m_world_space = this->m_emitter->m_world_space;
  if ( (!this->m_data_type_action
     || this->m_data_type_action->get_data_type(this->m_data_type_action) != particle_data_type_mesh
     && this->m_data_type_action->get_data_type(this->m_data_type_action) != particle_data_type_decal)
    && need_query_material )
  {
    if ( emitter->m_material_name[0] )
      v10 = emitter;
    else
      v10 = (vostok::particle::particle_emitter *)"default_particle";
    var4C.m_conflicted_action_to_bind = (survarium::game_action_id)v10;
    vostok::particle::particle_emitter_instance::load_material(this, v10->m_material_name);
  }
}
