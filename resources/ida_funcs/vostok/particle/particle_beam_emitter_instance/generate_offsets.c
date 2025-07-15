void __thiscall vostok::particle::particle_beam_emitter_instance::generate_offsets(
        vostok::particle::particle_beam_emitter_instance *this)
{
  vostok::math::float3 *v1; // ecx
  float *v2; // eax
  unsigned int other_x; // [esp+4h] [ebp-24h]
  unsigned int min_value; // [esp+8h] [ebp-20h]
  float max_value; // [esp+Ch] [ebp-1Ch]
  vostok::math::float3 v7; // [esp+14h] [ebp-14h] BYREF
  unsigned int i; // [esp+20h] [ebp-8h]
  unsigned int beam_index; // [esp+24h] [ebp-4h]

  for ( beam_index = 0; beam_index < this->m_beamtrail_parameters->num_beams; ++beam_index )
  {
    for ( i = 0; i < 0xF; ++i )
    {
      max_value = vostok::particle::random_float(0.0, 1.0);
      *(float *)&min_value = vostok::particle::random_float(0.0, 1.0);
      *(float *)&other_x = vostok::particle::random_float(0.0, 1.0);
      vostok::math::float3::float3(&v7, other_x, min_value, max_value);
      v1 = &this->m_random_offsets[beam_index][i];
      v1->x = *v2;
      v1->y = v2[1];
      v1->z = v2[2];
    }
  }
}
