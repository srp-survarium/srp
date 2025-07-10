SpeedTree::Mat4x4 *__usercall vostok::render::vostok_to_speedtree@<eax>(int a1@<esi>, SpeedTree::Mat4x4 *result)
{
  const vostok::math::float4x4 *v2; // xmm0_4

  memset(a1, 0, 0x40u);
  v2 = clear_value;
  *(_DWORD *)(a1 + 60) = clear_value;
  *(_DWORD *)(a1 + 40) = v2;
  *(_DWORD *)(a1 + 20) = v2;
  *(_DWORD *)a1 = v2;
  memcpy((unsigned __int8 *)a1, (unsigned __int8 *)result, 0x40u);
  return (SpeedTree::Mat4x4 *)a1;
}
