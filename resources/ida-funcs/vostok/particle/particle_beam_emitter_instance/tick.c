void __thiscall vostok::particle::particle_beam_emitter_instance::tick(
        vostok::particle::particle_beam_emitter_instance *this,
        float time_delta,
        bool __formal,
        float alpha)
{
  float v5; // xmm3_4
  float m_speed; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm0_4
  vostok::math::float3 *p_m_beams_target_position; // eax
  float v10; // xmm3_4
  float *p_x; // esi
  float *v12; // esi
  vostok::particle::particle_beam_emitter_instance *v13; // ecx
  vostok::math::float3 *v14; // esi
  vostok::particle::base_particle *m_first; // eax
  vostok::math::float3 *p_m_beams_end_position; // edi
  vostok::particle::particle_action *i; // esi
  float duration; // xmm1_4
  float v19; // xmm0_4
  vostok::math::aabb *p_position; // ecx
  vostok::intrusive_list<vostok::particle::base_particle,vostok::particle::base_particle *,208,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *v21; // ecx
  vostok::math::float4x4 *transform; // eax
  vostok::particle::base_particle *v23; // esi
  float v24; // xmm0_4
  vostok::particle::particle_beam_emitter_instance *v25; // ecx
  float v26; // xmm0_4
  signed int v27; // eax
  vostok::particle::particle_beam_emitter_instance *v28; // [esp+Ch] [ebp-74h]
  vostok::particle::base_particle *v29; // [esp+20h] [ebp-60h]
  float v30; // [esp+20h] [ebp-60h]
  vostok::math::float4x4 v31; // [esp+24h] [ebp-5Ch] BYREF

  this->m_instance_color.w = alpha;
  vostok::math::aabb::zero((vostok::math::aabb *)this, &this->m_aabbox);
  if ( !this->m_num_live_particles )
    this->m_beam_particles_allocated = 0;
  v5 = s_bm_current_air_resistance;
  this->m_emitter_time = this->m_emitter_time + time_delta;
  m_speed = this->m_particle_action_beam->m_speed;
  if ( m_speed <= 0.0000099999997 )
  {
    p_m_beams_target_position = &this->m_beams_target_position;
    p_x = &this->m_beams_target_position.x;
  }
  else
  {
    v7 = (float)(m_speed * time_delta) + this->m_move_from_source_to_target;
    this->m_move_from_source_to_target = v7;
    v8 = 0.0;
    if ( v7 > 0.0 )
    {
      if ( v5 < v7 )
        v8 = v5;
      else
        v8 = v7;
    }
    this->m_move_from_source_to_target = v8;
    p_m_beams_target_position = &this->m_beams_target_position;
    *(_QWORD *)&v31.e01 = *(_QWORD *)&this->m_beams_target_position.x;
    v31.i.w = this->m_beams_target_position.z;
    *(_QWORD *)&v31.lines[1].x = *(_QWORD *)&this->m_beams_source_position.x;
    v31.j.z = this->m_beams_source_position.z;
    v10 = v5 - v8;
    v31.j.x = (float)(v31.j.x * v10) + (float)(v31.i.y * v8);
    v31.j.y = (float)(v31.j.y * v10) + (float)(v31.i.z * v8);
    v31.j.z = (float)(v31.j.z * v10) + (float)(v31.i.w * v8);
    p_x = &v31.j.x;
  }
  this->m_beams_end_position.x = *p_x;
  v12 = p_x + 1;
  this->m_beams_end_position.y = *v12;
  this->m_beams_end_position.z = v12[1];
  v31.j.x = p_m_beams_target_position->x - this->m_beams_source_position.x;
  v31.j.y = p_m_beams_target_position->y - this->m_beams_source_position.y;
  v31.j.z = p_m_beams_target_position->z - this->m_beams_source_position.z;
  v31.i.y = this->m_beams_end_position.x - this->m_beams_source_position.x;
  v31.i.z = this->m_beams_end_position.y - this->m_beams_source_position.y;
  v31.i.w = this->m_beams_end_position.z - this->m_beams_source_position.z;
  v14 = vostok::math::float3_pod::normalize_safe(
          &this->m_beams_end_position,
          (vostok::math::float3 *)&v31.e01,
          &v31.j.x);
  m_first = this->m_particle_list.m_first;
  this->m_beams_direction.x = v14->x;
  v14 = (vostok::math::float3 *)((char *)v14 + 4);
  this->m_beams_direction.y = v14->x;
  this->m_beams_direction.z = v14->y;
  p_m_beams_end_position = &this->m_beams_end_position;
  v29 = m_first;
  if ( m_first )
  {
    while ( 1 )
    {
      m_first->size.x = m_first->start_size.x;
      m_first->size.y = m_first->start_size.y;
      m_first->size.z = m_first->start_size.z;
      m_first->old_position.x = m_first->position.x;
      m_first->old_position.y = m_first->position.y;
      m_first->old_position.z = m_first->position.z;
      for ( i = this->m_emitter->m_actions.pointer; i; i = i->m_next.pointer )
      {
        if ( i->m_visibility )
        {
          ((void (__thiscall *)(vostok::particle::particle_action *, vostok::particle::particle_beam_emitter_instance *, vostok::particle::base_particle *, _DWORD))i->update)(
            i,
            this,
            m_first,
            LODWORD(time_delta));
          m_first = v29;
        }
      }
      duration = m_first->duration;
      v19 = time_delta + m_first->lifetime;
      m_first->lifetime = v19;
      p_position = (vostok::math::aabb *)&m_first->position;
      m_first->position.x = m_first->old_position.x;
      m_first->position.y = m_first->old_position.y;
      m_first->position.z = m_first->old_position.z;
      p_m_beams_end_position = &m_first->spawn_position;
      if ( duration <= 0.001 || v19 <= duration )
      {
        vostok::math::aabb::modify(p_position, &this->m_aabbox);
        v29 = v29->next;
      }
      else
      {
        LODWORD(v31.i.x) = 1;
        vostok::particle::particle_emitter_instance::process_event(
          (vostok::particle::particle_emitter_instance *)p_position,
          (vostok::particle::particle_event *)this,
          &v31,
          &m_first->position);
        p_m_beams_end_position = (vostok::math::float3 *)v29;
        vostok::intrusive_list<vostok::particle::base_particle,vostok::particle::base_particle *,208,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::erase(
          v21,
          (int)&this->m_particle_list,
          v29);
        v29 = v29->next;
        vostok::particle::particle_world::deallocate_particle(
          (vostok::particle::particle_world *)v29,
          (int)this->m_particle_world,
          (vostok::particle::base_particle *)p_m_beams_end_position);
        --this->m_num_live_particles;
      }
      if ( !v29 )
        break;
      m_first = v29;
    }
  }
  if ( !this->m_emitter->m_world_space )
  {
    transform = vostok::particle::particle_emitter_instance::get_transform(
                  v13,
                  this,
                  (vostok::math::float4x4 *)&v31.lines[1].elements[3]);
    vostok::math::aabb::modify((vostok::math::aabb *)transform, &this->m_aabbox);
  }
  v23 = this->m_particle_list.m_first;
  if ( v23 )
  {
    v24 = this->m_particle_action_beam->m_frequency + s_bm_current_air_resistance;
    v30 = v24;
    vostok::particle::base_particle::get_linear_lifetime_impl(
      (vostok::particle::base_particle *)v13,
      (int)this->m_particle_list.m_first,
      v23->lifetime);
    v26 = v24 * v24;
    if ( v26 > this->m_particle_beam_index )
      vostok::particle::particle_beam_emitter_instance::set_particles_positions(
        v25,
        (vostok::particle::base_particle *)p_m_beams_end_position,
        (unsigned int)v23,
        (unsigned int)this,
        1);
    vostok::particle::base_particle::get_linear_lifetime_impl(
      (vostok::particle::base_particle *)v25,
      (int)v23,
      v23->lifetime);
    v27 = vostok::math::floor(v26 * v30);
    v13 = v28;
    this->m_particle_beam_index = (float)v27 + s_bm_current_air_resistance;
  }
  vostok::particle::particle_beam_emitter_instance::set_particles_positions(
    v13,
    (vostok::particle::base_particle *)p_m_beams_end_position,
    (unsigned int)v23,
    (unsigned int)this,
    0);
}
