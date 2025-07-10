void __thiscall vostok::particle::curve_line_points<float,0>::reserve(
        vostok::particle::curve_line_points<float,0> *this,
        unsigned int num,
        bool __formal)
{
  unsigned int i; // [esp+34h] [ebp-8h]
  vostok::particle::curve_point<float> *point_to_init; // [esp+38h] [ebp-4h]

  if ( num )
  {
    vostok::particle::curve_line_points<float,0>::clear(this);
    this->num_points = num;
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)num);
    this->points.pointer = (vostok::particle::curve_point<float> *)vostok::memory::malloc_helper<vostok::memory::pthreads3_allocator>(24 * num);
    point_to_init = this->points.pointer;
    for ( i = 0; i < num; ++i )
      operator new(0x18u, point_to_init++);
    vostok::particle::curve_line_points<float,0>::recalculate_ranges(this);
  }
}
