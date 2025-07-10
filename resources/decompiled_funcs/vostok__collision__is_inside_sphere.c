BOOL __usercall vostok::collision::is_inside_sphere@<eax>(
        const vostok::math::float3 *vertex@<ecx>,
        const vostok::math::float3 *sphere_center@<eax>,
        float squared_sphere_radius)
{
  float v3; // xmm2_4
  float v4; // xmm1_4

  v3 = vertex->z - sphere_center->z;
  v4 = vertex->y - sphere_center->y;
  return squared_sphere_radius >= (float)((float)((float)(v3 * v3)
                                                + (float)((float)(vertex->x - sphere_center->x)
                                                        * (float)(vertex->x - sphere_center->x)))
                                        + (float)(v4 * v4));
}
