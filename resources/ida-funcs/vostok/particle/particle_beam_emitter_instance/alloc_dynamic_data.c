void __thiscall vostok::particle::particle_beam_emitter_instance::alloc_dynamic_data(
        vostok::particle::particle_beam_emitter_instance *this,
        unsigned int num_curves,
        unsigned int num_points)
{
  vostok::particle::curve_line_points<vostok::math::float3_pod,0> *v3; // eax
  survarium::game_camera *v4; // ecx
  _DWORD *v6; // [esp+40h] [ebp-10h]
  _DWORD *v7; // [esp+44h] [ebp-Ch]
  unsigned int j; // [esp+48h] [ebp-8h]
  unsigned int i; // [esp+4Ch] [ebp-4h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  v3 = (vostok::particle::curve_line_points<vostok::math::float3_pod,0> *)vostok::memory::malloc_helper<vostok::memory::pthreads3_allocator>(48 * num_curves);
  v4 = (survarium::game_camera *)this;
  this->m_curve_line = v3;
  this->m_num_curves = num_curves;
  for ( i = 0; i < num_curves; ++i )
  {
    v7 = operator new(0x30u, &this->m_curve_line[i]);
    if ( v7 )
    {
      v7[8] = 0;
      v7[9] = 0;
    }
    vostok::particle::curve_line_points<vostok::math::float3_pod,0>::reserve(&this->m_curve_line[i], num_points, 1);
    v4 = (survarium::game_camera *)(i + 1);
  }
  survarium::weapon_user_dead_state::finalize(v4);
  this->m_random_offsets = (vostok::math::float3 (*)[15])vostok::memory::malloc_helper<vostok::memory::pthreads3_allocator>(180 * num_curves);
  for ( j = 0; j < num_curves; ++j )
  {
    v6 = operator new(0x30u, this->m_random_offsets[j]);
    if ( v6 )
    {
      v6[8] = 0;
      v6[9] = 0;
    }
  }
}
