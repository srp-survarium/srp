vostok::math::float3 *__userpurge vostok::collision::composite_geometry::get_closest_point_to@<eax>(
        vostok::collision::composite_geometry *this@<eax>,
        const vostok::math::float3 *point@<esi>,
        vostok::math::float3 *origin,
        const vostok::math::float4x4 *origina)
{
  vostok::collision::geometry_instance **m_begin; // ecx
  vostok::math::float3 *result; // eax
  float z; // edx
  vostok::collision::geometry_instance **m_end; // ebx
  vostok::collision::geometry_instance **v8; // edi
  float v9; // xmm3_4
  float v10; // xmm2_4
  float v11; // ecx
  float min_squared_distance; // [esp+18h] [ebp-1Ch]
  vostok::math::float3 min_closest_point; // [esp+1Ch] [ebp-18h] BYREF
  vostok::math::float3 closest_point; // [esp+28h] [ebp-Ch] BYREF

  m_begin = this->m_geometry_instances.m_begin;
  if ( m_begin == this->m_geometry_instances.m_end )
  {
    result = origin;
    z = origina->c.z;
    *(_QWORD *)&origin->x = *(_QWORD *)&origina->lines[3].x;
    origin->z = z;
  }
  else
  {
    m_end = this->m_geometry_instances.m_end;
    v8 = this->m_geometry_instances.m_begin + 1;
    (*m_begin)->get_closest_point_to(*m_begin, &min_closest_point, point, origina);
    for ( min_squared_distance = (float)((float)((float)(point->z - min_closest_point.z)
                                               * (float)(point->z - min_closest_point.z))
                                       + (float)((float)(point->y - min_closest_point.y)
                                               * (float)(point->y - min_closest_point.y)))
                               + (float)((float)(point->x - min_closest_point.x)
                                       * (float)(point->x - min_closest_point.x)); v8 != m_end; ++v8 )
    {
      (*v8)->get_closest_point_to(*v8, &closest_point, point, origina);
      v9 = (float)(point->y - closest_point.y) * (float)(point->y - closest_point.y);
      v10 = (float)(point->x - closest_point.x) * (float)(point->x - closest_point.x);
      if ( min_squared_distance > (float)((float)((float)((float)(point->z - closest_point.z)
                                                        * (float)(point->z - closest_point.z))
                                                + v9)
                                        + v10) )
      {
        min_squared_distance = (float)((float)((float)(point->z - closest_point.z) * (float)(point->z - closest_point.z))
                                     + v9)
                             + v10;
        min_closest_point = closest_point;
      }
    }
    result = origin;
    v11 = min_closest_point.z;
    *(_QWORD *)&origin->x = *(_QWORD *)&min_closest_point.x;
    origin->z = v11;
  }
  return result;
}
