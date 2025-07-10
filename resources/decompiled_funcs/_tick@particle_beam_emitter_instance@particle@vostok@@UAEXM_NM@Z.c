void __thiscall vostok::particle::particle_beam_emitter_instance::tick(
        vostok::particle::particle_beam_emitter_instance *this,
        float time_delta,
        bool __formal,
        float alpha)
{
  vostok::math::float3 *v4; // eax
  vostok::particle::particle_emitter *m_emitter; // eax
  BOOL m_world_space; // ecx
  vostok::particle::base_particle *v7; // ecx
  float v8; // xmm0_4
  float v9; // xmm0_4
  vostok::particle::base_particle *v10; // ecx
  vostok::math::float3 *max; // [esp+0h] [ebp-B0h]
  BOOL v12; // [esp+4h] [ebp-ACh]
  bool v14; // [esp+51h] [ebp-5Fh]
  vostok::particle::enum_particle_event event_type; // [esp+78h] [ebp-38h] BYREF
  vostok::math::float3 v16; // [esp+7Ch] [ebp-34h] BYREF
  vostok::math::float3 v17; // [esp+88h] [ebp-28h] BYREF
  vostok::math::float3 result; // [esp+94h] [ebp-1Ch] BYREF
  float frequency; // [esp+A0h] [ebp-10h]
  vostok::particle::base_particle *to_del; // [esp+A4h] [ebp-Ch]
  vostok::particle::particle_action *modifier; // [esp+A8h] [ebp-8h]
  vostok::particle::base_particle *P; // [esp+ACh] [ebp-4h]

  this->m_instance_color.w = alpha;
  vostok::math::aabb::zero((vostok::math::aabb *)this, &this->m_aabbox);
  if ( !this->m_num_live_particles )
    this->m_beam_particles_allocated = 0;
  this->m_emitter_time = this->m_emitter_time + time_delta;
  if ( this->m_particle_action_beam->m_speed <= 0.0000099999997 )
  {
    this->m_beams_end_position.x = this->m_beams_target_position.x;
    this->m_beams_end_position.y = this->m_beams_target_position.y;
    this->m_beams_end_position.z = this->m_beams_target_position.z;
  }
  else
  {
    this->m_move_from_source_to_target = (float)(time_delta * this->m_particle_action_beam->m_speed)
                                       + this->m_move_from_source_to_target;
    vostok::math::clamp<float>(&this->m_move_from_source_to_target, 0.0, 1.0);
    this->m_beams_end_position = *vostok::particle::linear_interpolation<vostok::math::float3>(
                                    &result,
                                    this->m_beams_source_position,
                                    this->m_beams_target_position,
                                    this->m_move_from_source_to_target);
  }
  max = vostok::math::operator-(&this->m_beams_source_position, &this->m_beams_target_position, &v16);
  v4 = vostok::math::operator-(&this->m_beams_source_position, &this->m_beams_end_position, &v17);
  this->m_beams_direction = *vostok::math::float3_pod::normalize_safe(v4, max);
  P = vostok::intrusive_list<vostok::particle::base_particle,vostok::particle::base_particle *,128,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::front(
        (vostok::intrusive_list<vostok::particle::base_particle,vostok::particle::base_particle *,128,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)&this->m_beams_direction,
        (int)&this->m_particle_list);
  while ( P )
  {
    P->size = P->start_size;
    P->old_position = P->position;
    for ( modifier = this->m_emitter->m_actions.pointer; modifier; modifier = modifier->m_next.pointer )
    {
      if ( modifier->m_visibility )
        ((void (__thiscall *)(vostok::particle::particle_action *, vostok::particle::particle_beam_emitter_instance *, vostok::particle::base_particle *, _DWORD))modifier->update)(
          modifier,
          this,
          P,
          LODWORD(time_delta));
    }
    P->lifetime = P->lifetime + time_delta;
    P->position = P->old_position;
    if ( P->duration <= 0.001 )
    {
      v14 = 0;
    }
    else
    {
      v12 = P->lifetime > P->duration;
      v14 = P->lifetime > P->duration;
    }
    if ( v14 )
    {
      event_type = event_on_death;
      vostok::particle::particle_emitter_instance::process_event(this, &event_type, &P->position);
      vostok::intrusive_list<vostok::particle::base_particle,vostok::particle::base_particle *,128,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::erase(
        &this->m_particle_list,
        P);
      to_del = P;
      P = P->next;
      vostok::particle::particle_world::deallocate_particle(this->m_particle_world, to_del);
      --this->m_num_live_particles;
    }
    else
    {
      vostok::math::aabb::modify((vostok::math::aabb *)&P->position, &this->m_aabbox);
      P = P->next;
    }
  }
  m_emitter = this->m_emitter;
  m_world_space = m_emitter->m_world_space;
  if ( !m_emitter->m_world_space )
    vostok::math::aabb::modify((vostok::math::aabb *)&this->m_transform, (const vostok::math::float4x4 *)v12);
  P = vostok::intrusive_list<vostok::particle::base_particle,vostok::particle::base_particle *,128,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::front(
        (vostok::intrusive_list<vostok::particle::base_particle,vostok::particle::base_particle *,128,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)m_world_space,
        (int)&this->m_particle_list);
  if ( P )
  {
    frequency = this->m_particle_action_beam->m_frequency + *(float *)&clear_value;
    v8 = frequency;
    vostok::particle::base_particle::get_linear_lifetime(v7);
    v9 = v8 * frequency;
    v10 = (vostok::particle::base_particle *)this;
    if ( v9 > this->m_particle_beam_index )
      vostok::particle::particle_beam_emitter_instance::set_particles_positions(this, 1);
    vostok::particle::base_particle::get_linear_lifetime(v10);
    this->m_particle_beam_index = (float)(int)vostok::math::floor(v9 * frequency) + *(float *)&clear_value;
  }
  vostok::particle::particle_beam_emitter_instance::set_particles_positions(this, 0);
}
