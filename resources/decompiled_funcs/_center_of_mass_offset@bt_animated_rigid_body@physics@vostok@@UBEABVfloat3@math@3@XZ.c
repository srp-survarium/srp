const vostok::math::float3 *__thiscall vostok::physics::bt_animated_rigid_body::center_of_mass_offset(
        vostok::physics::bt_animated_rigid_body *this)
{
  if ( (_S4_2 & 1) == 0 )
  {
    _S4_2 |= 1u;
    *(_QWORD *)&offset_0.x = 0;
    offset_0.z = 0.0;
  }
  return &offset_0;
}
