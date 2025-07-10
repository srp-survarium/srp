void __thiscall vostok::particle::particle_emitter_instance::tick(
        vostok::particle::particle_emitter_instance *this,
        float time_delta,
        bool __formal,
        float alpha)
{
  survarium::game_camera *v4; // ecx
  vostok::math::aabb *v5; // eax
  vostok::intrusive_list<vostok::particle::base_particle,vostok::particle::base_particle *,128,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *v6; // ecx
  vostok::math::float3 *v7; // eax
  vostok::math::float3 *v8; // eax
  vostok::math::float3_pod *v9; // eax
  vostok::math::float3 *v10; // eax
  vostok::math::float3 *v11; // eax
  vostok::math::float3 *v12; // eax
  vostok::math::float3 *v13; // eax
  vostok::math::float3 *v14; // eax
  vostok::math::float3 *v15; // eax
  vostok::math::float3_pod *v16; // eax
  vostok::math::float3_pod *v17; // eax
  const vostok::math::float4x4 *v18; // [esp+Ch] [ebp-114h]
  vostok::particle::enum_particle_event event_type; // [esp+74h] [ebp-ACh] BYREF
  vostok::math::float3 v21; // [esp+78h] [ebp-A8h] BYREF
  vostok::math::float3 v22; // [esp+84h] [ebp-9Ch] BYREF
  vostok::math::float3 v23; // [esp+90h] [ebp-90h] BYREF
  vostok::math::float3 v24; // [esp+9Ch] [ebp-84h] BYREF
  vostok::math::float3 v25; // [esp+A8h] [ebp-78h] BYREF
  vostok::math::float3 v26; // [esp+B4h] [ebp-6Ch] BYREF
  vostok::math::float3 v27; // [esp+C0h] [ebp-60h] BYREF
  vostok::math::float3 v28; // [esp+CCh] [ebp-54h] BYREF
  float right; // [esp+D8h] [ebp-48h] BYREF
  vostok::math::float3 v30; // [esp+DCh] [ebp-44h] BYREF
  vostok::math::float3 v31; // [esp+E8h] [ebp-38h] BYREF
  vostok::math::float3 v32; // [esp+F4h] [ebp-2Ch] BYREF
  vostok::particle::base_particle *to_del; // [esp+100h] [ebp-20h]
  vostok::particle::particle_action *modifier; // [esp+104h] [ebp-1Ch]
  vostok::math::float3 ratation_rate; // [esp+108h] [ebp-18h] BYREF
  vostok::particle::burst_entry *one_burst; // [esp+114h] [ebp-Ch]
  unsigned int i; // [esp+118h] [ebp-8h]
  vostok::particle::base_particle *P; // [esp+11Ch] [ebp-4h]

  if ( this->m_data_type_action )
  {
    this->m_instance_color.w = alpha;
    vostok::math::aabb::zero((vostok::math::aabb *)this, &this->m_aabbox);
    if ( this->m_delayed )
    {
      this->m_delay_time = this->m_delay_time + time_delta;
      if ( this->m_delay_time <= this->m_emitter->m_delay )
        return;
      this->m_delayed = 0;
    }
    this->m_emitter_time = this->m_emitter_time + time_delta;
    if ( vostok::particle::particle_emitter_instance::is_emitter_finished(this) )
    {
      if ( this->m_emitter->m_num_loops )
      {
        ++this->m_current_loop;
        vostok::math::clamp<unsigned int>(&this->m_current_loop, 0, this->m_emitter->m_num_loops);
        vostok::particle::particle_emitter_instance::recalc_duration(this);
      }
      vostok::particle::particle_emitter_instance::recalc_duration(this);
      this->m_emitter_time = *(float *)&FLOAT_0_0;
      for ( i = 0; i < this->m_emitter->m_num_burst_entries; ++i )
      {
        one_burst = &this->m_emitter->m_burst_entries.pointer[i];
        if ( one_burst->count < 0 )
          one_burst->count = -one_burst->count;
      }
    }
    if ( this->m_emitter->m_num_loops && this->m_current_loop == this->m_emitter->m_num_loops )
      this->m_waiting_for_end = 1;
    if ( this->m_waiting_for_end && !this->m_num_live_particles )
      this->m_waiting_for_end = 0;
    vostok::particle::particle_emitter_instance::append_particles(this, time_delta);
    survarium::weapon_user_dead_state::finalize(v4);
    vostok::math::aabb::move(v5, &this->m_aabbox);
    P = vostok::intrusive_list<vostok::particle::base_particle,vostok::particle::base_particle *,128,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::front(
          v6,
          (int)&this->m_particle_list);
    while ( P )
    {
      P->rotation_rate = P->start_rotation_rate;
      P->size = P->start_size;
      P->velocity = P->start_velocity;
      P->old_position = P->position;
      for ( modifier = this->m_emitter->m_actions.pointer; modifier; modifier = modifier->m_next.pointer )
      {
        if ( modifier->m_visibility )
          ((void (__thiscall *)(vostok::particle::particle_action *, vostok::particle::particle_emitter_instance *, vostok::particle::base_particle *, _DWORD))modifier->update)(
            modifier,
            this,
            P,
            LODWORD(time_delta));
      }
      P->lifetime = P->lifetime + time_delta;
      v7 = vostok::math::operator*(&P->velocity, &v32, &time_delta);
      vostok::math::float3_pod::operator+=(v7, &P->position);
      v8 = vostok::math::operator*(&P->rotation_rate, &v31, &time_delta);
      vostok::math::operator*(v8, &ratation_rate, (float *)&pi_x2_3);
      P->rotation = P->rotation + ratation_rate.x;
      P->rotationY = P->rotationY + ratation_rate.y;
      P->rotationZ = P->rotationZ + ratation_rate.z;
      vostok::math::aabb::modify((vostok::math::aabb *)&P->position, &this->m_aabbox);
      if ( this->m_world_space )
      {
        vostok::math::float3::float3(
          &v30,
          COERCE_UNSIGNED_INT(0.0),
          COERCE_UNSIGNED_INT((float)-P->gravity * time_delta),
          0.0);
        vostok::math::float3_pod::operator+=(v9, &P->position);
        P->render_position = P->position;
        P->render_old_position = P->old_position;
      }
      else
      {
        right = *(float *)&FLOAT_0_0;
        if ( vostok::math::is_similar<float>(&P->gravity_accumulation, &right, 0.0000099999997) )
        {
          v10 = vostok::math::float4x4::transform_position(&P->position, &v28, &this->m_transform);
          P->render_position = *v10;
          v11 = vostok::math::float4x4::transform_position(&P->old_position, &v27, &this->m_transform);
          P->render_old_position = *v11;
        }
        else
        {
          v12 = vostok::math::operator*(&P->velocity, &v26, &time_delta);
          v13 = vostok::math::float4x4::transform_direction(v12, &v25, &this->m_transform);
          vostok::math::float3_pod::operator+=(v13, &P->render_position);
          v14 = vostok::math::operator*(&P->velocity, &v24, &time_delta);
          v15 = vostok::math::float4x4::transform_direction(v14, &v23, &this->m_transform);
          vostok::math::float3_pod::operator+=(v15, &P->render_old_position);
        }
        P->gravity_accumulation = -P->gravity;
        vostok::math::float3::float3(
          &v22,
          COERCE_UNSIGNED_INT(0.0),
          COERCE_UNSIGNED_INT(P->gravity_accumulation * time_delta),
          0.0);
        vostok::math::float3_pod::operator+=(v16, &P->render_position);
        vostok::math::float3::float3(
          &v21,
          COERCE_UNSIGNED_INT(0.0),
          COERCE_UNSIGNED_INT(P->gravity_accumulation * time_delta),
          0.0);
        vostok::math::float3_pod::operator+=(v17, &P->render_old_position);
      }
      if ( vostok::particle::base_particle::is_dead(P) )
      {
        event_type = event_on_death;
        vostok::particle::particle_emitter_instance::process_event(this, &event_type, &P->position);
        vostok::intrusive_list<vostok::particle::base_particle,vostok::particle::base_particle *,128,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::erase(
          &this->m_particle_list,
          P);
        to_del = P;
        P = vostok::intrusive_list<vostok::particle::base_particle,vostok::particle::base_particle *,128,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::get_next_of_object(P);
        vostok::particle::particle_world::deallocate_particle(this->m_particle_world, to_del);
        --this->m_num_live_particles;
      }
      else
      {
        P = vostok::intrusive_list<vostok::particle::base_particle,vostok::particle::base_particle *,128,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::get_next_of_object(P);
      }
    }
    if ( !this->m_emitter->m_world_space )
      vostok::math::aabb::modify((vostok::math::aabb *)&this->m_transform, v18);
    this->m_render_instance->set_aabb(this->m_render_instance, &this->m_aabbox);
  }
}
