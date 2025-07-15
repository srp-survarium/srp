void __usercall survarium::player::reset_fov_factor(survarium::player *this@<ecx>, int a2@<eax>)
{
  const vostok::math::float4x4 *v2; // xmm0_4

  v2 = clear_value;
  *(int *)((char *)&dword_10F1C + a2) = (int)clear_value;
  *(int *)((char *)&dword_10F18 + a2) = (int)v2;
  *(int *)((char *)&dword_10F20 + a2) = (int)v2;
}
