void __usercall vostok::math::curve_line_ranged_xyz_float::set_defaults(
        vostok::math::curve_line_ranged_xyz_float *this@<ecx>,
        int a2@<esi>)
{
  vostok::math::curve_line_ranged_base::set_defaults((vostok::math::curve_line_ranged_base *)a2);
  vostok::math::curve_line_ranged_base::set_defaults((vostok::math::curve_line_ranged_base *)(a2 + 64));
  vostok::math::curve_line_ranged_base::set_defaults((vostok::math::curve_line_ranged_base *)(a2 + 128));
  *(_DWORD *)(a2 + 192) = 0;
}
