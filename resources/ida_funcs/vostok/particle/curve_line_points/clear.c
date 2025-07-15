void __thiscall vostok::particle::curve_line_points<float,0>::clear(vostok::particle::curve_line_points<float,0> *this)
{
  vostok::memory::pthreads3_allocator *v1; // eax
  vostok::particle::curve_point<float> *pointer; // [esp+14h] [ebp-4h]

  if ( this->num_points )
  {
    pointer = this->points.pointer;
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
    if ( pointer )
      vostok::memory::pthreads3_allocator::free_impl(v1, pointer);
    this->points.pointer = 0;
    this->num_points = 0;
  }
}


void __thiscall vostok::particle::curve_line_points<vostok::math::float3_pod,0>::clear(
        vostok::particle::curve_line_points<vostok::math::float3_pod,0> *this)
{
  vostok::memory::pthreads3_allocator *v1; // eax
  vostok::particle::curve_point<vostok::math::float3_pod> *pointer; // [esp+14h] [ebp-4h]

  if ( this->num_points )
  {
    pointer = this->points.pointer;
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
    if ( pointer )
      vostok::memory::pthreads3_allocator::free_impl(v1, pointer);
    this->points.pointer = 0;
    this->num_points = 0;
  }
}


void __thiscall vostok::particle::curve_line_points<vostok::math::float4_pod,1>::clear(
        vostok::particle::curve_line_points<vostok::math::float4_pod,1> *this)
{
  vostok::memory::pthreads3_allocator *v1; // eax
  vostok::particle::curve_point<vostok::math::float4_pod> *pointer; // [esp+14h] [ebp-4h]

  if ( this->num_points )
  {
    pointer = this->points.pointer;
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
    if ( pointer )
      vostok::memory::pthreads3_allocator::free_impl(v1, pointer);
    this->points.pointer = 0;
    this->num_points = 0;
  }
}
