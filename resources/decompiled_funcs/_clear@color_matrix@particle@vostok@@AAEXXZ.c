void __thiscall vostok::particle::color_matrix::clear(vostok::particle::color_matrix *this)
{
  vostok::memory::pthreads3_allocator *v1; // eax
  vostok::particle::color_matrix_point_type *pointer; // [esp+10h] [ebp-4h]

  if ( this->m_num_rows && this->m_num_columns )
  {
    pointer = this->m_points.pointer;
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this->m_points.pointer);
    if ( pointer )
      vostok::memory::pthreads3_allocator::free_impl(v1, pointer);
    this->m_points.pointer = 0;
    this->m_num_rows = 0;
    this->m_num_columns = 0;
  }
}
