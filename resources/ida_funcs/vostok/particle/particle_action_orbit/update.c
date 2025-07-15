void __thiscall vostok::particle::particle_action_orbit::update(
        vostok::particle::particle_action_orbit *this,
        vostok::particle::particle_emitter_instance *instance,
        vostok::particle::base_particle *P,
        float time)
{
  _BYTE *v4; // eax
  const vostok::math::float3 *v5; // eax
  const vostok::math::float3 *v6; // eax
  vostok::math::float3 *v7; // eax
  const vostok::math::float3 *v8; // eax
  vostok::math::float3 *v9; // eax
  vostok::math::float4x4 *v10; // eax
  vostok::math::float3 *v11; // eax
  vostok::math::float4x4 *v12; // eax
  vostok::math::float3 *v13; // eax
  vostok::math::float3 *v14; // eax
  float other_x; // [esp+4h] [ebp-17Ch]
  float other_xa; // [esp+4h] [ebp-17Ch]
  float other_y; // [esp+8h] [ebp-178h]
  const vostok::math::float3 *other_ya; // [esp+8h] [ebp-178h]
  const vostok::math::float3 *other_yb; // [esp+8h] [ebp-178h]
  const vostok::math::float3 *other_z; // [esp+Ch] [ebp-174h]
  boost::_bi::list1<vostok::network_core::packet_reader &> *v21; // [esp+10h] [ebp-170h]
  boost::_bi::list1<vostok::network_core::packet_reader &> *v22; // [esp+10h] [ebp-170h]
  boost::_bi::list1<vostok::network_core::packet_reader &> *m_seed; // [esp+14h] [ebp-16Ch]
  vostok::math::float3 v25; // [esp+5Ch] [ebp-124h] BYREF
  vostok::math::float3 v26; // [esp+68h] [ebp-118h] BYREF
  vostok::math::float4x4 v27; // [esp+74h] [ebp-10Ch] BYREF
  vostok::math::float3 v28; // [esp+B4h] [ebp-CCh] BYREF
  vostok::math::float3 v29; // [esp+C0h] [ebp-C0h] BYREF
  vostok::math::float4x4 v30; // [esp+CCh] [ebp-B4h] BYREF
  vostok::math::float3 v31; // [esp+10Ch] [ebp-74h] BYREF
  vostok::math::float3 v32; // [esp+118h] [ebp-68h] BYREF
  vostok::math::float3 result; // [esp+124h] [ebp-5Ch] BYREF
  vostok::math::float3 v34; // [esp+130h] [ebp-50h] BYREF
  vostok::math::float3 v35; // [esp+13Ch] [ebp-44h] BYREF
  char v36; // [esp+14Bh] [ebp-35h]
  vostok::math::float3 next_position; // [esp+14Ch] [ebp-34h] BYREF
  vostok::math::float3 offset; // [esp+158h] [ebp-28h] BYREF
  vostok::math::float3 rotation; // [esp+164h] [ebp-1Ch] BYREF
  float curr_time; // [esp+170h] [ebp-10h] BYREF
  vostok::math::float3 rotation_rate; // [esp+174h] [ebp-Ch] BYREF

  v36 = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( *v4 )
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)instance);
  m_seed = (boost::_bi::list1<vostok::network_core::packet_reader &> *)P->m_seed;
  vostok::math::float3::float3(&v35, COERCE_UNSIGNED_INT(0.0), COERCE_UNSIGNED_INT(0.0), 0.0);
  other_z = v5;
  other_y = vostok::particle::particle_emitter_instance::get_linear_emitter_time(instance);
  vostok::particle::curve_line_ranged_xyz_float::evaluate(
    &this->m_offset_amount,
    &offset,
    other_y,
    other_z,
    range_time_type,
    m_seed);
  v21 = (boost::_bi::list1<vostok::network_core::packet_reader &> *)P->m_seed;
  vostok::math::float3::float3(&v34, COERCE_UNSIGNED_INT(0.0), COERCE_UNSIGNED_INT(0.0), 0.0);
  other_ya = v6;
  other_x = vostok::particle::particle_emitter_instance::get_linear_emitter_time(instance);
  v7 = vostok::particle::curve_line_ranged_xyz_float::evaluate(
         &this->m_rotation_amount,
         &result,
         other_x,
         other_ya,
         range_time_type,
         v21);
  vostok::math::operator*(v7, &rotation, (float *)&pi_x2_2);
  v22 = (boost::_bi::list1<vostok::network_core::packet_reader &> *)P->m_seed;
  vostok::math::float3::float3(&v32, COERCE_UNSIGNED_INT(0.0), COERCE_UNSIGNED_INT(0.0), 0.0);
  other_yb = v8;
  other_xa = vostok::particle::particle_emitter_instance::get_linear_emitter_time(instance);
  v9 = vostok::particle::curve_line_ranged_xyz_float::evaluate(
         &this->m_rotation_rate_amount,
         &v31,
         other_xa,
         other_yb,
         range_time_type,
         v22);
  vostok::math::operator*(v9, &rotation_rate, (float *)&pi_x2_2);
  v10 = vostok::math::create_rotation(&v30, &rotation);
  offset = *vostok::math::float4x4::transform_position(&offset, &v29, v10);
  curr_time = P->lifetime;
  v11 = vostok::math::operator*(&rotation_rate, &v28, &curr_time);
  v12 = vostok::math::create_rotation(&v27, v11);
  v13 = vostok::math::float4x4::transform_position(&offset, &v26, v12);
  vostok::math::operator+(v13, &P->spawn_position, &next_position);
  v14 = vostok::math::operator-(&P->prev_offset_position, &next_position, &v25);
  vostok::math::float3_pod::operator+=(v14, &P->position);
  P->prev_offset_position = next_position;
}
