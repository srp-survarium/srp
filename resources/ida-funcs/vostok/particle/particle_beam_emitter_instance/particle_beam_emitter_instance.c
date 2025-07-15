void __thiscall vostok::particle::particle_beam_emitter_instance::particle_beam_emitter_instance(
        vostok::particle::particle_beam_emitter_instance *this,
        vostok::particle::particle_emitter *emitter,
        bool is_child_emitter_instance,
        bool need_query_material)
{
  float *v4; // eax
  survarium::game_camera *v5; // ecx
  vostok::math::float3 *v6; // eax
  vostok::math::float3 *v7; // eax
  vostok::math::float3 *v8; // eax
  unsigned int other_x; // [esp+4h] [ebp-ECh]
  unsigned int other_y; // [esp+8h] [ebp-E8h]
  float other_z; // [esp+Ch] [ebp-E4h]
  vostok::math::float3 *other_za; // [esp+Ch] [ebp-E4h]
  vostok::math::float3 *v13; // [esp+18h] [ebp-D8h]
  vostok::math::float3 v15; // [esp+60h] [ebp-90h] BYREF
  vostok::math::float3 v16; // [esp+6Ch] [ebp-84h] BYREF
  vostok::math::float3 v17; // [esp+78h] [ebp-78h] BYREF
  vostok::math::float3 v18; // [esp+84h] [ebp-6Ch] BYREF
  vostok::math::float3 v19; // [esp+90h] [ebp-60h] BYREF
  vostok::math::float3 *v20; // [esp+9Ch] [ebp-54h]
  vostok::math::float4x4 result; // [esp+A0h] [ebp-50h] BYREF
  vostok::math::float3 v22; // [esp+E0h] [ebp-10h] BYREF
  float *v23; // [esp+ECh] [ebp-4h]

  vostok::particle::particle_emitter_instance::particle_emitter_instance(
    this,
    emitter,
    is_child_emitter_instance,
    need_query_material);
  this->__vftable = (vostok::particle::particle_beam_emitter_instance_vtbl *)&vostok::particle::particle_beam_emitter_instance::`vftable';
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->m_beams_source_position);
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->m_beams_target_position);
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->m_beams_direction);
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->m_beams_end_position);
  this->m_particle_action_beam = 0;
  this->m_curve_line = 0;
  this->m_random_offsets = 0;
  this->m_num_curves = 0;
  this->m_move_from_source_to_target = *(float *)&FLOAT_0_0;
  this->m_beam_pose_index = *(float *)&FLOAT_0_0;
  this->m_particle_beam_index = *(float *)&FLOAT_0_0;
  this->m_beam_lifetime = *(float *)&FLOAT_0_0;
  this->m_beam_particles_allocated = 0;
  if ( emitter->m_source_action.pointer )
  {
    vostok::particle::particle_action_source::get_transform(emitter->m_source_action.pointer, &result);
    survarium::weapon_user_dead_state::finalize(v5);
  }
  else
  {
    vostok::math::float3::float3(&v22, COERCE_UNSIGNED_INT(0.0), COERCE_UNSIGNED_INT(0.0), 0.0);
  }
  v23 = v4;
  this->m_beams_source_position.x = *v4;
  this->m_beams_source_position.y = v4[1];
  this->m_beams_source_position.z = v4[2];
  if ( emitter->m_target_action.pointer )
  {
    v13 = vostok::particle::particle_domain_complex::generate(&emitter->m_target_action.pointer->m_domain, &v18);
  }
  else
  {
    vostok::math::float3::float3(&v19, COERCE_UNSIGNED_INT(50.0), COERCE_UNSIGNED_INT(50.0), 50.0);
    v13 = v6;
  }
  v20 = v13;
  this->m_beams_target_position.x = v13->x;
  this->m_beams_target_position.y = v13->y;
  this->m_beams_target_position.z = v13->z;
  this->m_beams_end_position.x = this->m_beams_target_position.x;
  this->m_beams_end_position.y = this->m_beams_target_position.y;
  this->m_beams_end_position.z = this->m_beams_target_position.z;
  other_z = vostok::particle::random_float(0.0, 1.0);
  *(float *)&other_y = vostok::particle::random_float(0.0, 1.0);
  *(float *)&other_x = vostok::particle::random_float(0.0, 1.0);
  vostok::math::float3::float3(&v17, other_x, other_y, other_z);
  other_za = v7;
  v8 = vostok::math::operator-(&this->m_beams_source_position, &this->m_beams_target_position, &v16);
  this->m_beams_direction = *vostok::math::normalize_safe(v8, &v15, other_za);
  this->m_max_num_particles = this->m_emitter->m_max_num_particles * this->m_beamtrail_parameters->num_beams;
  this->m_current_max_num_particles = this->m_max_num_particles;
  vostok::particle::particle_beam_emitter_instance::alloc_dynamic_data(this, 1u, 0xFu);
  if ( this->m_beamtrail_parameters->num_beams != this->m_num_curves )
  {
    vostok::particle::particle_beam_emitter_instance::free_dynamic_data(this);
    vostok::particle::particle_beam_emitter_instance::alloc_dynamic_data(
      this,
      this->m_beamtrail_parameters->num_beams,
      0xFu);
  }
  if ( this->m_data_type_action )
    this->m_particle_action_beam = (vostok::particle::particle_action_beam *)this->m_data_type_action;
  vostok::particle::particle_beam_emitter_instance::generate_offsets(this);
}
