SpeedTree::Vec3 *__usercall vostok::render::speedtree_to_vostok@<eax>(
        const SpeedTree::Vec3 *v@<ecx>,
        SpeedTree::Vec3 *result@<eax>)
{
  *result = *v;
  return result;
}


SpeedTree::Vec4 *__usercall vostok::render::speedtree_to_vostok@<eax>(
        const SpeedTree::Vec4 *v@<ecx>,
        SpeedTree::Vec4 *result@<eax>)
{
  *result = *v;
  return result;
}


vostok::math::float4x4 *__usercall vostok::render::speedtree_to_vostok@<eax>(
        SpeedTree::Mat4x4 *m@<eax>,
        unsigned __int8 *a2@<esi>)
{
  memcpy(a2, (unsigned __int8 *)m, 0x40u);
  return (vostok::math::float4x4 *)a2;
}
