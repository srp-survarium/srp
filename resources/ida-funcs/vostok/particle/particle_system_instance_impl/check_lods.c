void __thiscall vostok::particle::particle_system_instance_impl::check_lods(
        vostok::particle::particle_system_instance_impl *this,
        const vostok::math::float3 *view_location)
{
  BOOL m_use_lods; // ecx
  survarium::game_camera *v3; // ecx
  const vostok::math::float3_pod *v4; // eax
  vostok::math::float3 *v5; // eax
  vostok::math::float3 v7; // [esp+8h] [ebp-20h] BYREF
  char v8; // [esp+17h] [ebp-11h]
  float activate_dist; // [esp+18h] [ebp-10h]
  vostok::particle::lod_entry *lod; // [esp+1Ch] [ebp-Ch]
  int i; // [esp+20h] [ebp-8h]
  float distance; // [esp+24h] [ebp-4h]

  m_use_lods = this->m_use_lods;
  if ( m_use_lods )
  {
    v8 = 0;
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)m_use_lods);
    survarium::weapon_user_dead_state::finalize(v3);
    v5 = vostok::math::operator-(v4, view_location, &v7);
    distance = vostok::math::float3_pod::squared_length((SpeedTree::Vec3 *)v5);
    for ( i = this->m_num_lods - 1; i >= 0; --i )
    {
      lod = &this->m_lods[i];
      activate_dist = this->m_lods[i].m_distance * this->m_lods[i].m_distance;
      if ( distance >= activate_dist )
      {
        if ( i != this->m_current_lod )
          vostok::particle::particle_system_instance_impl::apply_lod(this, i);
        return;
      }
    }
  }
}
