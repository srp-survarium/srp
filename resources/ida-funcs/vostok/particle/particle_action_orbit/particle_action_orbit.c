void __usercall vostok::particle::particle_action_orbit::particle_action_orbit(
        vostok::particle::particle_action_orbit *this@<ecx>,
        _DWORD *a2@<esi>)
{
  vostok::math::curve_line_ranged_xyz_float *v2; // ecx
  vostok::math::curve_line_ranged_xyz_float *v3; // ecx
  vostok::math::curve_line_ranged_xyz_float *v4; // ecx

  a2[3] = 0;
  a2[2] = 0;
  *a2 = &vostok::particle::particle_action_orbit::`vftable';
  vostok::math::curve_line_ranged_xyz_float::curve_line_ranged_xyz_float(
    (vostok::math::curve_line_ranged_xyz_float *)this,
    a2 + 6);
  vostok::math::curve_line_ranged_xyz_float::curve_line_ranged_xyz_float(v2, a2 + 56);
  vostok::math::curve_line_ranged_xyz_float::curve_line_ranged_xyz_float(v3, a2 + 106);
  a2[160] = 0;
  a2[161] = 0;
  a2[168] = 0;
  a2[169] = 0;
  vostok::math::curve_line_ranged_xyz_float::curve_line_ranged_xyz_float(v4, a2 + 174);
}
