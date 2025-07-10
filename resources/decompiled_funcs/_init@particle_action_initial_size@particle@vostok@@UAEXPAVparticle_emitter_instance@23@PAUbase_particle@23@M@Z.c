void __thiscall vostok::particle::particle_action_initial_size::init(
        vostok::particle::particle_action_initial_size *this,
        vostok::particle::particle_emitter_instance *instance,
        vostok::particle::base_particle *P,
        float time)
{
  _BYTE *v4; // eax
  const vostok::math::float3 *v5; // eax
  float other_y; // [esp+4h] [ebp-54h]
  const vostok::math::float3 *other_z; // [esp+8h] [ebp-50h]
  boost::_bi::list1<vostok::network_core::packet_reader &> *m_seed; // [esp+10h] [ebp-48h]
  vostok::math::float3 result; // [esp+3Ch] [ebp-1Ch] BYREF
  vostok::math::float3 v11; // [esp+48h] [ebp-10h] BYREF
  char v12; // [esp+57h] [ebp-1h]

  v12 = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( *v4 )
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)instance);
  m_seed = (boost::_bi::list1<vostok::network_core::packet_reader &> *)P->m_seed;
  vostok::math::float3::float3(&v11, COERCE_UNSIGNED_INT(0.0), COERCE_UNSIGNED_INT(0.0), 0.0);
  other_z = v5;
  other_y = vostok::particle::particle_emitter_instance::get_linear_emitter_time(instance);
  P->start_size = *vostok::particle::curve_line_ranged_xyz_float::evaluate(
                     &this->m_init_size,
                     &result,
                     other_y,
                     other_z,
                     range_time_type,
                     m_seed);
  vostok::math::float3_pod::operator+=(&P->start_size, &P->size);
}
