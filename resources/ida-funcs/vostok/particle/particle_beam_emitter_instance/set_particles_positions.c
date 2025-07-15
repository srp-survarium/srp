void __thiscall vostok::particle::particle_beam_emitter_instance::set_particles_positions(
        vostok::particle::particle_beam_emitter_instance *this,
        bool gen_new)
{
  const vostok::math::float3_pod *v2; // eax
  vostok::math::float3_pod *v3; // eax
  unsigned int other_x; // [esp+8h] [ebp-A0h]
  unsigned int min_value; // [esp+Ch] [ebp-9Ch]
  float max_value; // [esp+10h] [ebp-98h]
  const vostok::math::float3_pod *max_valuea; // [esp+10h] [ebp-98h]
  vostok::math::float3 v9; // [esp+50h] [ebp-58h] BYREF
  vostok::math::float3 v10; // [esp+5Ch] [ebp-4Ch] BYREF
  unsigned int particle_index; // [esp+68h] [ebp-40h]
  vostok::particle::base_particle *P; // [esp+6Ch] [ebp-3Ch]
  unsigned int beam_index; // [esp+70h] [ebp-38h]
  vostok::math::float3 up_vector; // [esp+74h] [ebp-34h] BYREF
  vostok::math::float3 beams_vector; // [esp+80h] [ebp-28h] BYREF
  vostok::math::float3 temp_vector; // [esp+8Ch] [ebp-1Ch] BYREF
  unsigned int num_particle_per_beam; // [esp+98h] [ebp-10h]
  vostok::math::float3 right_vector; // [esp+9Ch] [ebp-Ch] BYREF

  if ( this->m_num_live_particles >= 2 )
  {
    if ( gen_new )
      vostok::particle::particle_beam_emitter_instance::generate_offsets(this);
    beams_vector = this->m_beams_direction;
    max_value = vostok::particle::random_float(0.0, 1.0);
    *(float *)&min_value = vostok::particle::random_float(0.0, 1.0);
    *(float *)&other_x = vostok::particle::random_float(0.0, 1.0);
    vostok::math::float3::float3(&v9, other_x, min_value, max_value);
    max_valuea = v2;
    vostok::math::float3::float3(
      &v10,
      COERCE_UNSIGNED_INT(beams_vector.z * (*this->m_random_offsets)[0].x),
      COERCE_UNSIGNED_INT(beams_vector.x * (*this->m_random_offsets)[0].y),
      beams_vector.y * (*this->m_random_offsets)[0].z);
    temp_vector = *vostok::math::float3_pod::normalize_safe(v3, max_valuea);
    vostok::math::cross_product(&up_vector, &beams_vector, &temp_vector);
    vostok::math::cross_product(&right_vector, &beams_vector, &up_vector);
    num_particle_per_beam = this->m_num_live_particles / this->m_beamtrail_parameters->num_beams;
    for ( beam_index = 0; beam_index < this->m_beamtrail_parameters->num_beams; ++beam_index )
    {
      P = vostok::intrusive_list<vostok::particle::base_particle,vostok::particle::base_particle *,128,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::front(
            (vostok::intrusive_list<vostok::particle::base_particle,vostok::particle::base_particle *,128,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)this,
            (int)&this->m_particle_list);
      particle_index = 0;
      while ( P && particle_index != num_particle_per_beam * beam_index )
      {
        ++particle_index;
        P = vostok::intrusive_list<vostok::particle::base_particle,vostok::particle::base_particle *,128,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::get_next_of_object(P);
      }
      vostok::particle::particle_beam_emitter_instance::apply_noise(
        this,
        beam_index,
        &up_vector,
        &right_vector,
        1.0,
        1u,
        1,
        P,
        num_particle_per_beam);
    }
  }
}
