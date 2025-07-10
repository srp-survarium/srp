void __thiscall vostok::particle::particle_action_orbit::init(
        vostok::particle::particle_action_orbit *this,
        vostok::particle::particle_emitter_instance *instance,
        vostok::particle::base_particle *P,
        float time)
{
  _BYTE *v4; // eax
  const vostok::math::float3 *v5; // eax
  const vostok::math::float3 *v6; // eax
  vostok::math::float3 *v7; // eax
  vostok::math::float4x4 *v8; // eax
  float other_x; // [esp+4h] [ebp-184h]
  float other_y; // [esp+8h] [ebp-180h]
  const vostok::math::float3 *other_ya; // [esp+8h] [ebp-180h]
  const vostok::math::float3 *other_z; // [esp+Ch] [ebp-17Ch]
  boost::_bi::list1<vostok::network_core::packet_reader &> *v13; // [esp+10h] [ebp-178h]
  boost::_bi::list1<vostok::network_core::packet_reader &> *m_seed; // [esp+14h] [ebp-174h]
  vostok::math::float3 v16; // [esp+FCh] [ebp-8Ch] BYREF
  vostok::math::float4x4 v17; // [esp+108h] [ebp-80h] BYREF
  vostok::math::float3 result; // [esp+148h] [ebp-40h] BYREF
  vostok::math::float3 v19; // [esp+154h] [ebp-34h] BYREF
  vostok::math::float3 v20; // [esp+160h] [ebp-28h] BYREF
  char v21; // [esp+16Fh] [ebp-19h]
  vostok::math::float3 offset; // [esp+170h] [ebp-18h] BYREF
  vostok::math::float3 rotation; // [esp+17Ch] [ebp-Ch] BYREF

  v21 = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( *v4 )
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)instance);
  m_seed = (boost::_bi::list1<vostok::network_core::packet_reader &> *)P->m_seed;
  vostok::math::float3::float3(&v20, COERCE_UNSIGNED_INT(0.0), COERCE_UNSIGNED_INT(0.0), 0.0);
  other_z = v5;
  other_y = vostok::particle::particle_emitter_instance::get_linear_emitter_time(instance);
  vostok::particle::curve_line_ranged_xyz_float::evaluate(
    &this->m_offset_amount,
    &offset,
    other_y,
    other_z,
    range_time_type,
    m_seed);
  v13 = (boost::_bi::list1<vostok::network_core::packet_reader &> *)P->m_seed;
  vostok::math::float3::float3(&v19, COERCE_UNSIGNED_INT(0.0), COERCE_UNSIGNED_INT(0.0), 0.0);
  other_ya = v6;
  other_x = vostok::particle::particle_emitter_instance::get_linear_emitter_time(instance);
  v7 = vostok::particle::curve_line_ranged_xyz_float::evaluate(
         &this->m_rotation_amount,
         &result,
         other_x,
         other_ya,
         range_time_type,
         v13);
  vostok::math::operator*(v7, &rotation, (float *)&pi_x2_2);
  v8 = vostok::math::create_rotation(&v17, &rotation);
  offset = *vostok::math::float4x4::transform_position(&offset, &v16, v8);
  vostok::math::float3_pod::operator+=(&offset, &P->position);
  vostok::math::float3_pod::operator+=(&offset, &P->old_position);
  P->prev_offset_position = P->position;
}
