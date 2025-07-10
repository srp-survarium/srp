bool __usercall vostok::collision::is_inside_cylinder@<al>(
        const vostok::math::float3 *vertex@<ecx>,
        const vostok::math::float4x4 *cylinder_transform@<eax>,
        float cylinder_half_height,
        float squared_cylinder_radius)
{
  float v4; // xmm5_4
  float v5; // xmm6_4
  float v6; // xmm4_4
  float v7; // xmm3_4

  v4 = vertex->y - cylinder_transform->c.y;
  v5 = vertex->z - cylinder_transform->c.z;
  v6 = vertex->x - cylinder_transform->c.x;
  if ( fabs(
         (float)((float)(cylinder_transform->j.z * v5) + (float)(cylinder_transform->j.y * v4))
       + (float)(cylinder_transform->j.x * v6)) > cylinder_half_height )
    return 0;
  v7 = (float)((float)(cylinder_transform->j.z * v5) + (float)(cylinder_transform->j.y * v4))
     + (float)(cylinder_transform->j.x * v6);
  return squared_cylinder_radius >= (float)((float)((float)((float)((float)(cylinder_transform->j.z * v7) - v5)
                                                          * (float)((float)(cylinder_transform->j.z * v7) - v5))
                                                  + (float)((float)((float)(cylinder_transform->j.y * v7) - v4)
                                                          * (float)((float)(cylinder_transform->j.y * v7) - v4)))
                                          + (float)((float)((float)(cylinder_transform->j.x * v7) - v6)
                                                  * (float)((float)(cylinder_transform->j.x * v7) - v6)));
}
