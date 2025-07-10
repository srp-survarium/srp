void __thiscall vostok::collision::intersection_double_dispatcher::dispatch(
        vostok::collision::intersection_double_dispatcher *this,
        const vostok::collision::sphere_geometry_instance *bounding_volume,
        const vostok::collision::box_geometry_instance *testee)
{
  const vostok::math::float3 *v4; // edi
  const vostok::math::float4x4 *v5; // esi
  const vostok::math::float4x4 *v6; // eax
  vostok::math::float3 box_half_sides; // [esp+10h] [ebp-18h] BYREF
  vostok::math::float3 closest_point; // [esp+1Ch] [ebp-Ch] BYREF
  float testeea; // [esp+30h] [ebp+8h]

  v4 = (const vostok::math::float3 *)&this->m_bounding_volume->get_matrix(this->m_bounding_volume)->lines[3];
  v5 = testee->get_matrix(testee);
  box_half_sides.x = sqrtf((float)((float)(v5->i.y * v5->i.y) + (float)(v5->i.z * v5->i.z)) + (float)(v5->i.x * v5->i.x));
  box_half_sides.y = sqrtf((float)((float)(v5->j.z * v5->j.z) + (float)(v5->j.x * v5->j.x)) + (float)(v5->j.y * v5->j.y));
  box_half_sides.z = sqrtf((float)((float)(v5->k.y * v5->k.y) + (float)(v5->k.z * v5->k.z)) + (float)(v5->k.x * v5->k.x));
  v6 = this->m_testee->get_matrix(this->m_testee);
  vostok::collision::closest_point_to_point(&closest_point, &box_half_sides, v4, v6);
  testeea = sqrtf(
              (float)((float)(bounding_volume->m_matrix.i.y * bounding_volume->m_matrix.i.y)
                    + (float)(bounding_volume->m_matrix.i.z * bounding_volume->m_matrix.i.z))
            + (float)(bounding_volume->m_matrix.i.x * bounding_volume->m_matrix.i.x));
  this->m_result = (float)(testeea * testeea) > (float)((float)((float)((float)(closest_point.z - v4->z)
                                                                      * (float)(closest_point.z - v4->z))
                                                              + (float)((float)(closest_point.y - v4->y)
                                                                      * (float)(closest_point.y - v4->y)))
                                                      + (float)((float)(closest_point.x - v4->x)
                                                              * (float)(closest_point.x - v4->x)));
}
