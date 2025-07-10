vostok::math::float4 *__usercall vostok::render::aabb_to_occlusion_bound@<eax>(
        const vostok::math::aabb *in_aabb@<eax>,
        vostok::math::aabb *in_instance_transform@<ecx>,
        float *a3@<esi>)
{
  vostok::math::aabb bound_box; // [esp+4h] [ebp-1Ch]

  bound_box = *in_aabb;
  vostok::math::aabb::modify(in_instance_transform, (const vostok::math::float4x4 *)LODWORD(in_aabb->min.x));
  *a3 = (float)(bound_box.max.x + bound_box.min.x) * 0.5;
  a3[1] = (float)(bound_box.max.y + bound_box.min.y) * 0.5;
  a3[2] = (float)(bound_box.max.z + bound_box.min.z) * 0.5;
  a3[3] = sqrtf(
            (float)((float)((float)((float)(bound_box.max.z - bound_box.min.z) * 0.5)
                          * (float)((float)(bound_box.max.z - bound_box.min.z) * 0.5))
                  + (float)((float)((float)(bound_box.max.y - bound_box.min.y) * 0.5)
                          * (float)((float)(bound_box.max.y - bound_box.min.y) * 0.5)))
          + (float)((float)((float)(bound_box.max.x - bound_box.min.x) * 0.5)
                  * (float)((float)(bound_box.max.x - bound_box.min.x) * 0.5)));
  return (vostok::math::float4 *)a3;
}
