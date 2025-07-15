const vostok::math::float4x4 *__usercall vostok::render::aabb_to_occlusion_bound@<eax>(
        const vostok::math::aabb *in_aabb@<eax>,
        const vostok::math::float4x4 *in_instance_transform,
        vostok::math::aabb *a3)
{
  float v3; // xmm5_4
  float v4; // xmm6_4
  float v5; // xmm0_4
  vostok::math::aabb v7; // [esp+10h] [ebp-18h] BYREF

  qmemcpy(&v7, in_aabb, sizeof(v7));
  vostok::math::aabb::modify(a3, &v7);
  v3 = (float)(v7.max.y + v7.min.y) * 0.5;
  v4 = (float)(v7.max.z + v7.min.z) * 0.5;
  v5 = fsqrt(
         (float)((float)((float)((float)(v7.max.z - v7.min.z) * 0.5) * (float)((float)(v7.max.z - v7.min.z) * 0.5))
               + (float)((float)((float)(v7.max.y - v7.min.y) * 0.5) * (float)((float)(v7.max.y - v7.min.y) * 0.5)))
       + (float)((float)((float)(v7.max.x - v7.min.x) * 0.5) * (float)((float)(v7.max.x - v7.min.x) * 0.5)));
  in_instance_transform->i.x = (float)(v7.max.x + v7.min.x) * 0.5;
  in_instance_transform->i.y = v3;
  in_instance_transform->i.z = v4;
  in_instance_transform->i.w = v5;
  return in_instance_transform;
}
