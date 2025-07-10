void __thiscall vostok::collision::containment_double_dispatcher::dispatch(
        vostok::collision::containment_double_dispatcher *this,
        const vostok::collision::truncated_sphere_geometry_instance *bounding_volume,
        const vostok::collision::capsule_geometry_instance *testee)
{
  const vostok::math::float4x4 *v4; // eax
  float x; // xmm1_4
  const vostok::math::float4x4 *v6; // eax
  float v7; // xmm0_4
  const vostok::math::float4x4 *v8; // eax
  float v9; // xmm1_4
  const vostok::math::float4x4 *v10; // eax
  float v11; // xmm0_4
  const vostok::math::float4x4 *v12; // eax
  float v13; // xmm4_4
  float y; // xmm5_4
  float z; // xmm6_4
  float v16; // xmm2_4
  vostok::math::float4_pod *p_c; // eax
  float v18; // xmm3_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm5_4
  vostok::math::float4 *m_begin; // edx
  unsigned int v23; // eax
  unsigned int v24; // ecx
  float m_radius; // xmm3_4
  float v26; // xmm7_4
  float v27; // xmm1_4
  float m_half_length; // [esp+Ch] [ebp-3Ch]
  float v29; // [esp+Ch] [ebp-3Ch]
  float v30; // [esp+10h] [ebp-38h]
  float plane_point; // [esp+14h] [ebp-34h]
  float plane_point_4; // [esp+18h] [ebp-30h]
  float plane_point_8; // [esp+1Ch] [ebp-2Ch]
  float plane_point_8a; // [esp+1Ch] [ebp-2Ch]
  float volume_to_second_testee_point; // [esp+20h] [ebp-28h]
  float volume_to_second_testee_point_4; // [esp+24h] [ebp-24h]
  float volume_to_second_testee_point_4a; // [esp+24h] [ebp-24h]
  float volume_to_second_testee_point_8; // [esp+28h] [ebp-20h]
  float volume_to_second_testee_point_8a; // [esp+28h] [ebp-20h]
  float volume_to_first_testee_point_4; // [esp+30h] [ebp-18h]
  float volume_to_first_testee_point_8; // [esp+34h] [ebp-14h]
  float volume_to_first_testee_point_8a; // [esp+34h] [ebp-14h]
  __int64 plane_8; // [esp+40h] [ebp-8h]

  if ( testee->m_radius <= bounding_volume->m_radius )
  {
    m_half_length = testee->m_half_length;
    v4 = this->m_testee->get_matrix(this->m_testee);
    x = v4->j.x;
    v4 = (const vostok::math::float4x4 *)((char *)v4 + 16);
    volume_to_second_testee_point_4 = v4->i.y * m_half_length;
    volume_to_second_testee_point_8 = v4->i.z * m_half_length;
    v6 = this->m_testee->get_matrix(this->m_testee);
    v7 = v6->c.x + (float)(x * m_half_length);
    v6 = (const vostok::math::float4x4 *)((char *)v6 + 48);
    plane_point = v7;
    plane_point_4 = v6->i.y + volume_to_second_testee_point_4;
    plane_point_8 = v6->i.z + volume_to_second_testee_point_8;
    v29 = testee->m_half_length;
    v8 = this->m_testee->get_matrix(this->m_testee);
    v9 = v8->j.x;
    v8 = (const vostok::math::float4x4 *)((char *)v8 + 16);
    volume_to_second_testee_point_4a = v8->i.y * v29;
    volume_to_second_testee_point_8a = v8->i.z * v29;
    v10 = this->m_testee->get_matrix(this->m_testee);
    v11 = v10->c.x - (float)(v9 * v29);
    v10 = (const vostok::math::float4x4 *)((char *)v10 + 48);
    volume_to_first_testee_point_4 = v10->i.y - volume_to_second_testee_point_4a;
    volume_to_first_testee_point_8 = v10->i.z - volume_to_second_testee_point_8a;
    v12 = this->m_bounding_volume->get_matrix(this->m_bounding_volume);
    v13 = v12->c.x;
    y = v12->c.y;
    z = v12->c.z;
    v16 = bounding_volume->m_radius - testee->m_radius;
    p_c = &v12->c;
    if ( (float)((float)((float)((float)(plane_point - v13) * (float)(plane_point - v13))
                       + (float)((float)(plane_point_8 - z) * (float)(plane_point_8 - z)))
               + (float)((float)(plane_point_4 - y) * (float)(plane_point_4 - y))) <= (float)(v16 * v16) )
    {
      v18 = v11 - v13;
      if ( (float)((float)((float)(v18 * v18)
                         + (float)((float)(volume_to_first_testee_point_8 - z)
                                 * (float)(volume_to_first_testee_point_8 - z)))
                 + (float)((float)(volume_to_first_testee_point_4 - y) * (float)(volume_to_first_testee_point_4 - y))) <= (float)(v16 * v16) )
      {
        v19 = p_c->y;
        v20 = p_c->z;
        v21 = volume_to_first_testee_point_8 - v20;
        volume_to_first_testee_point_8a = plane_point_8 - v20;
        volume_to_second_testee_point = v18;
        this->m_bounding_volume->get_matrix((vostok::collision::geometry_instance *)this->m_bounding_volume);
        m_begin = bounding_volume->m_planes.m_begin;
        v23 = bounding_volume->m_planes.m_end - m_begin;
        v24 = 0;
        if ( v23 )
        {
          m_radius = bounding_volume->m_radius;
          v30 = -testee->m_radius;
          while ( 1 )
          {
            plane_8 = *(_QWORD *)&m_begin->elements[2];
            v26 = (float)(*((float *)&plane_8 + 1) * m_begin->x) * m_radius;
            plane_point_8a = (float)(*((float *)&plane_8 + 1) * *(float *)&plane_8) * m_radius;
            v27 = (float)(*((float *)&plane_8 + 1) * m_begin->y) * m_radius;
            if ( (float)((float)((float)((float)((float)(plane_point - v13) - v26) * m_begin->x)
                               + (float)((float)(volume_to_first_testee_point_8a - plane_point_8a) * *(float *)&plane_8))
                       + (float)((float)((float)(plane_point_4 - v19) - v27) * m_begin->y)) > v30
              || (float)((float)((float)((float)(volume_to_second_testee_point - v26) * m_begin->x)
                               + (float)((float)(v21 - plane_point_8a) * m_begin->z))
                       + (float)((float)((float)(volume_to_first_testee_point_4 - v19) - v27) * m_begin->y)) > v30 )
            {
              break;
            }
            ++v24;
            ++m_begin;
            if ( v24 >= v23 )
              goto LABEL_10;
            m_radius = bounding_volume->m_radius;
          }
        }
        else
        {
LABEL_10:
          this->m_result = 1;
        }
      }
    }
  }
}
