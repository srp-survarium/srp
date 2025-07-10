vostok::math::float4x4 *__usercall vostok::render::speedtree_to_vostok@<eax>(
        SpeedTree::Mat4x4 *m@<eax>,
        unsigned __int8 *a2@<esi>)
{
  memcpy(a2, (unsigned __int8 *)m, 0x40u);
  return (vostok::math::float4x4 *)a2;
}
