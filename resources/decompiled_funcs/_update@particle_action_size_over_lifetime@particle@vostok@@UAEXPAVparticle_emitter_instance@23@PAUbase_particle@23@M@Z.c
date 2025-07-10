void __userpurge vostok::particle::particle_action_size_over_lifetime::update(
        vostok::particle::particle_action_size_over_lifetime *this@<ecx>,
        double a2@<xmm0>,
        vostok::particle::particle_emitter_instance *instance,
        vostok::particle::base_particle *P,
        float time)
{
  _BYTE *v5; // eax
  const vostok::math::float3 *v6; // eax
  vostok::particle::base_particle *v7; // ecx
  const vostok::math::float3 *other_z; // [esp+8h] [ebp-6Ch]
  boost::_bi::list1<vostok::network_core::packet_reader &> *m_seed; // [esp+10h] [ebp-64h]
  vostok::math::float3 v11; // [esp+58h] [ebp-1Ch] BYREF
  char v12; // [esp+67h] [ebp-Dh]
  vostok::math::float3 size_scale; // [esp+68h] [ebp-Ch] BYREF

  v12 = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( *v5 )
  {
    a2 = time;
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)instance);
  }
  m_seed = (boost::_bi::list1<vostok::network_core::packet_reader &> *)P->m_seed;
  vostok::math::float3::float3(&v11, COERCE_UNSIGNED_INT(1.0), COERCE_UNSIGNED_INT(1.0), 1.0);
  other_z = v6;
  vostok::particle::base_particle::get_linear_lifetime(v7);
  vostok::particle::curve_line_ranged_xyz_float::evaluate(
    &this->m_size_over_life,
    &size_scale,
    *(float *)&a2,
    other_z,
    range_time_type,
    m_seed);
  if ( this->m_multiply_x )
    P->size.x = P->size.x * size_scale.x;
  if ( this->m_multiply_y )
    P->size.y = P->size.y * size_scale.y;
  if ( this->m_multiply_z )
    P->size.z = P->size.z * size_scale.z;
}
