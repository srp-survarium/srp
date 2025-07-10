void __thiscall vostok::collision::intersection_double_dispatcher::dispatch(
        vostok::collision::intersection_double_dispatcher *this,
        const vostok::collision::truncated_sphere_geometry_instance *bounding_volume,
        const vostok::collision::box_geometry_instance *testee)
{
  const vostok::math::float3 *v4; // edi
  const vostok::math::float4x4 *v5; // esi
  const vostok::math::float4x4 *v6; // eax
  float v7; // xmm1_4
  float v8; // xmm2_4
  const vostok::collision::geometry_instance *m_bounding_volume; // ecx
  const vostok::math::float4x4 *(__thiscall *get_matrix)(vostok::collision::geometry_instance *); // edx
  vostok::math::float4 *m_begin; // edx
  unsigned int v12; // eax
  unsigned int v13; // ecx
  float m_radius; // xmm0_4
  vostok::math::float3 volume_to_closest_point; // [esp+10h] [ebp-1Ch] BYREF
  vostok::math::float4 plane; // [esp+1Ch] [ebp-10h] BYREF

  v4 = (const vostok::math::float3 *)&this->m_bounding_volume->get_matrix(this->m_bounding_volume)->lines[3];
  v5 = testee->get_matrix(testee);
  volume_to_closest_point.x = sqrtf(
                                (float)((float)(v5->i.z * v5->i.z) + (float)(v5->i.x * v5->i.x))
                              + (float)(v5->i.y * v5->i.y));
  volume_to_closest_point.y = sqrtf(
                                (float)((float)(v5->j.y * v5->j.y) + (float)(v5->j.z * v5->j.z))
                              + (float)(v5->j.x * v5->j.x));
  volume_to_closest_point.z = sqrtf(
                                (float)((float)(v5->k.y * v5->k.y) + (float)(v5->k.z * v5->k.z))
                              + (float)(v5->k.x * v5->k.x));
  v6 = this->m_testee->get_matrix(this->m_testee);
  vostok::collision::closest_point_to_point((vostok::math::float3 *)&plane, &volume_to_closest_point, v4, v6);
  v7 = plane.y - v4->y;
  v8 = plane.z - v4->z;
  if ( (float)((float)((float)(v8 * v8) + (float)(v7 * v7))
             + (float)((float)(plane.x - v4->x) * (float)(plane.x - v4->x))) <= (float)(bounding_volume->m_radius
                                                                                      * bounding_volume->m_radius) )
  {
    m_bounding_volume = this->m_bounding_volume;
    get_matrix = m_bounding_volume->get_matrix;
    volume_to_closest_point.x = plane.x - v4->x;
    *(_QWORD *)&volume_to_closest_point.elements[1] = __PAIR64__(LODWORD(v8), LODWORD(v7));
    get_matrix((vostok::collision::geometry_instance *)m_bounding_volume);
    m_begin = bounding_volume->m_planes.m_begin;
    v12 = bounding_volume->m_planes.m_end - m_begin;
    v13 = 0;
    if ( v12 )
    {
      m_radius = bounding_volume->m_radius;
      while ( 1 )
      {
        plane = *m_begin;
        if ( (float)((float)((float)(plane.z * volume_to_closest_point.z) + (float)(plane.y * volume_to_closest_point.y))
                   + (float)(plane.x * volume_to_closest_point.x)) > (float)(m_radius * plane.w) )
          break;
        ++v13;
        ++m_begin;
        if ( v13 >= v12 )
          goto LABEL_6;
      }
    }
    else
    {
LABEL_6:
      this->m_result = 1;
    }
  }
}
