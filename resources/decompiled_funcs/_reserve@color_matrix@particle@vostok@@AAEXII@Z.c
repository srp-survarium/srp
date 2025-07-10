void __thiscall vostok::particle::color_matrix::reserve(
        vostok::particle::color_matrix *this,
        unsigned int num_rows,
        unsigned int num_columns)
{
  survarium::game_camera *v3; // ecx
  unsigned int i; // [esp+28h] [ebp-8h]
  vostok::particle::color_matrix_point_type *point_to_init; // [esp+2Ch] [ebp-4h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  survarium::weapon_user_dead_state::finalize(v3);
  vostok::particle::color_matrix::clear(this);
  this->m_num_rows = num_rows;
  this->m_num_columns = num_columns;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  this->m_points.pointer = (vostok::particle::color_matrix_point_type *)vostok::memory::malloc_helper<vostok::memory::pthreads3_allocator>(24 * num_columns * num_rows);
  point_to_init = this->m_points.pointer;
  for ( i = 0; i < this->m_num_columns * this->m_num_rows; ++i )
    operator new(0x18u, point_to_init++);
}
