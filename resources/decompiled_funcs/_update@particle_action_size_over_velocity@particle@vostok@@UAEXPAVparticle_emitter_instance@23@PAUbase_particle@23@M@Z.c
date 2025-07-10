void __userpurge vostok::particle::particle_action_size_over_velocity::update(
        vostok::particle::particle_action_size_over_velocity *this@<ecx>,
        double a2@<xmm0>,
        vostok::particle::particle_emitter_instance *instance,
        vostok::particle::base_particle *P,
        float time)
{
  vostok::math::float3_pod *v5; // ecx
  _BYTE *v6; // eax
  const vostok::math::float3 *v7; // eax
  vostok::particle::base_particle *v8; // ecx
  vostok::math::float3 *v9; // eax
  const vostok::math::float3 *other_z; // [esp+8h] [ebp-64h]
  boost::_bi::list1<vostok::network_core::packet_reader &> *m_seed; // [esp+10h] [ebp-5Ch]
  float value; // [esp+40h] [ebp-2Ch] BYREF
  vostok::math::float3 result; // [esp+44h] [ebp-28h] BYREF
  vostok::math::float3 v15; // [esp+50h] [ebp-1Ch] BYREF
  char v16; // [esp+5Fh] [ebp-Dh]
  vostok::math::float3 size_scale; // [esp+60h] [ebp-Ch] BYREF

  v16 = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( *v6 )
  {
    a2 = time;
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)instance);
  }
  value = vostok::math::float3_pod::length(v5, &P->velocity.x);
  m_seed = (boost::_bi::list1<vostok::network_core::packet_reader &> *)P->m_seed;
  vostok::math::float3::float3(&v15, COERCE_UNSIGNED_INT(1.0), COERCE_UNSIGNED_INT(1.0), 1.0);
  other_z = v7;
  vostok::particle::base_particle::get_linear_lifetime(v8);
  v9 = vostok::particle::curve_line_ranged_xyz_float::evaluate(
         &this->m_size_over_velocity,
         &result,
         *(float *)&a2,
         other_z,
         range_time_type,
         m_seed);
  vostok::math::operator*(v9, &size_scale, &value);
  P->size.x = P->size.x * size_scale.x;
  P->size.y = P->size.y * size_scale.y;
  P->size.z = P->size.z * size_scale.z;
}
