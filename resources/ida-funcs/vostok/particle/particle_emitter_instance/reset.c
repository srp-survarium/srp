void __thiscall vostok::particle::particle_emitter_instance::reset(vostok::particle::particle_emitter_instance *this)
{
  unsigned int *v1; // eax
  vostok::math::float2 *v2; // ecx
  unsigned int v3; // edx
  int v4; // eax
  vostok::math::float4 *v5; // ecx
  float v6; // edx
  vostok::math::float4x4 *v7; // eax
  vostok::network_core::packet_reader *v8; // [esp+Ch] [ebp-ACh]
  float v9; // [esp+Ch] [ebp-ACh]
  float v10; // [esp+Ch] [ebp-ACh]
  survarium::game_options v12; // [esp+58h] [ebp-60h] BYREF
  _BYTE v13[8]; // [esp+A8h] [ebp-10h] BYREF
  boost::_bi::list2<unsigned char &,vostok::network_core::packet_reader &> *v14; // [esp+B0h] [ebp-8h] BYREF

  vostok::particle::particle_emitter_instance::remove_particles(this, 0xFFFFFFFF);
  this->m_num_live_particles = 0;
  this->m_num_created_particles = 0;
  this->m_waiting_for_end = 0;
  this->m_emitter_time = *(float *)&FLOAT_0_0;
  this->m_current_loop = 0;
  this->m_delayed = 0;
  this->m_delay_time = *(float *)&FLOAT_0_0;
  this->m_time_to_create_new_one = *(float *)&FLOAT_0_0;
  this->m_max_num_particles = this->m_emitter->m_max_num_particles;
  this->m_current_max_num_particles = this->m_emitter->m_max_num_particles;
  this->m_create_rate = retry_to_increase_quality_period_sec;
  this->m_current_create_rate = retry_to_increase_quality_period_sec;
  this->m_current_calc_num_max_particles = 0;
  this->m_num_particles_to_create = 0;
  this->m_subimage_index = *(float *)&FLOAT_0_0;
  this->m_visible = 1;
  this->m_particle_added = 0;
  this->m_current_duration = vostok::particle::calc_duration(
                               this->m_emitter->m_duration,
                               this->m_emitter->m_duration_variance);
  vostok::resources::memory_usage_type::memory_usage_type(0, &v14, 0, v8);
  v2 = (vostok::math::float2 *)*v1;
  v3 = v1[1];
  this->m_subuv_pos_uv.x = *v1;
  this->m_subuv_pos_uv.y = v3;
  v4 = vostok::math::float2::float2(v2, (int)v13, (int)clear_value, 1.0, v9);
  v5 = *(vostok::math::float4 **)v4;
  v6 = *(float *)(v4 + 4);
  this->m_subuv_size_uv.x = *(float *)v4;
  this->m_subuv_size_uv.y = v6;
  this->m_instance_color = *(vostok::math::float4 *)vostok::math::float4::float4(
                                                      v5,
                                                      (int)&v12.m_conflicted_action_to_bind,
                                                      (int)clear_value,
                                                      1.0,
                                                      1.0,
                                                      1.0,
                                                      v10);
  v7 = (vostok::math::float4x4 *)survarium::weapon_core::cast_weapon_core(&v12);
  qmemcpy((void *)&this->m_transform, vostok::math::float4x4::identity(v7), sizeof(this->m_transform));
}
