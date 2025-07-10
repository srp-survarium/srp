void __thiscall vostok::particle::particle_action_initial_rotation::init(
        vostok::particle::particle_action_initial_rotation *this,
        vostok::particle::particle_emitter_instance *instance,
        vostok::particle::base_particle *P,
        float time)
{
  _BYTE *v4; // eax
  const vostok::math::float3 *v5; // eax
  vostok::math::float3 *v6; // eax
  float other_y; // [esp+4h] [ebp-60h]
  const vostok::math::float3 *other_z; // [esp+8h] [ebp-5Ch]
  boost::_bi::list1<vostok::network_core::packet_reader &> *m_seed; // [esp+10h] [ebp-54h]
  vostok::math::float3 result; // [esp+3Ch] [ebp-28h] BYREF
  vostok::math::float3 v12; // [esp+48h] [ebp-1Ch] BYREF
  char v13; // [esp+57h] [ebp-Dh]
  vostok::math::float3 rotation; // [esp+58h] [ebp-Ch] BYREF

  v13 = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( *v4 )
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)instance);
  m_seed = (boost::_bi::list1<vostok::network_core::packet_reader &> *)P->m_seed;
  vostok::math::float3::float3(&v12, COERCE_UNSIGNED_INT(0.0), COERCE_UNSIGNED_INT(0.0), 0.0);
  other_z = v5;
  other_y = vostok::particle::particle_emitter_instance::get_linear_emitter_time(instance);
  v6 = vostok::particle::curve_line_ranged_xyz_float::evaluate(
         &this->m_init_rotation,
         &result,
         other_y,
         other_z,
         range_time_type,
         m_seed);
  vostok::math::operator*(v6, &rotation, (float *)&pi_x2_2);
  P->rotation = P->rotation + rotation.x;
  P->rotationY = P->rotationY + rotation.y;
  P->rotationZ = P->rotationZ + rotation.z;
}
