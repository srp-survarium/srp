void __thiscall vostok::particle::particle_beam_emitter_instance::free_dynamic_data(
        vostok::particle::particle_beam_emitter_instance *this)
{
  vostok::memory::pthreads3_allocator *v1; // eax
  vostok::memory::pthreads3_allocator *v2; // eax
  void **p_m_random_offsets; // [esp+4h] [ebp-34h]
  void **p_m_curve_line; // [esp+10h] [ebp-28h]
  unsigned int i; // [esp+34h] [ebp-4h]

  for ( i = 0; i < this->m_num_curves; ++i )
    vostok::particle::curve_line_points<vostok::math::float3_pod,0>::clear(&this->m_curve_line[i]);
  p_m_curve_line = (void **)&this->m_curve_line;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->m_curve_line);
  if ( this->m_curve_line )
  {
    vostok::memory::pthreads3_allocator::free_impl(v1, *p_m_curve_line);
    *p_m_curve_line = 0;
  }
  p_m_random_offsets = (void **)&this->m_random_offsets;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->m_random_offsets);
  if ( this->m_random_offsets )
  {
    vostok::memory::pthreads3_allocator::free_impl(v2, *p_m_random_offsets);
    *p_m_random_offsets = 0;
  }
}
