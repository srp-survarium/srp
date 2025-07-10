void __thiscall vostok::collision::containment_double_dispatcher::dispatch(
        vostok::collision::containment_double_dispatcher *this,
        const vostok::collision::truncated_sphere_geometry_instance *bounding_volume,
        const vostok::collision::sphere_geometry_instance *testee)
{
  vostok::math::float4_pod *p_c; // esi
  const vostok::math::float4x4 *v5; // eax
  float v6; // xmm2_4
  float v7; // xmm1_4
  vostok::math::float4_pod *v8; // esi
  const vostok::math::float4x4 *v9; // eax
  float v10; // xmm0_4
  unsigned int v11; // esi
  long double v12; // st7
  vostok::math::float4 *v13; // eax
  float i; // [esp+14h] [ebp-38h]
  float ib; // [esp+14h] [ebp-38h]
  unsigned int ia; // [esp+14h] [ebp-38h]
  vostok::math::float4 *m_begin; // [esp+18h] [ebp-34h]
  float m_radius; // [esp+1Ch] [ebp-30h]
  float v19; // [esp+20h] [ebp-2Ch]
  float volume_ot_testee_position_4; // [esp+28h] [ebp-24h]
  float volume_ot_testee_position_8; // [esp+2Ch] [ebp-20h]
  __int64 plane_8; // [esp+44h] [ebp-8h]

  i = bounding_volume->m_radius;
  if ( sqrtf(
         (float)((float)(testee->m_matrix.i.y * testee->m_matrix.i.y)
               + (float)(testee->m_matrix.i.z * testee->m_matrix.i.z))
       + (float)(testee->m_matrix.i.x * testee->m_matrix.i.x)) <= i )
  {
    ib = i
       - sqrtf(
           (float)((float)(testee->m_matrix.i.y * testee->m_matrix.i.y)
                 + (float)(testee->m_matrix.i.z * testee->m_matrix.i.z))
         + (float)(testee->m_matrix.i.x * testee->m_matrix.i.x));
    p_c = &this->m_bounding_volume->get_matrix(this->m_bounding_volume)->c;
    v5 = this->m_testee->get_matrix(this->m_testee);
    v6 = v5->c.z - p_c->z;
    v7 = v5->c.y - p_c->y;
    if ( (float)((float)((float)((float)(v5->c.x - p_c->x) * (float)(v5->c.x - p_c->x)) + (float)(v6 * v6))
               + (float)(v7 * v7)) <= (float)(ib * ib) )
    {
      v8 = &this->m_bounding_volume->get_matrix(this->m_bounding_volume)->c;
      v9 = this->m_testee->get_matrix(this->m_testee);
      v10 = v9->c.x - v8->x;
      v9 = (const vostok::math::float4x4 *)((char *)v9 + 48);
      volume_ot_testee_position_4 = v9->i.y - v8->y;
      volume_ot_testee_position_8 = v9->i.z - v8->z;
      this->m_bounding_volume->get_matrix((vostok::collision::geometry_instance *)this->m_bounding_volume);
      v11 = bounding_volume->m_planes.m_end - bounding_volume->m_planes.m_begin;
      m_begin = bounding_volume->m_planes.m_begin;
      ia = 0;
      if ( v11 )
      {
        m_radius = bounding_volume->m_radius;
        v12 = sqrtf(
                (float)((float)(testee->m_matrix.i.y * testee->m_matrix.i.y)
                      + (float)(testee->m_matrix.i.z * testee->m_matrix.i.z))
              + (float)(testee->m_matrix.i.x * testee->m_matrix.i.x));
        v13 = m_begin;
        while ( 1 )
        {
          plane_8 = *(_QWORD *)&v13->elements[2];
          v19 = -v12;
          if ( (float)((float)((float)((float)(volume_ot_testee_position_8
                                             - (float)((float)(*((float *)&plane_8 + 1) * *(float *)&plane_8) * m_radius))
                                     * *(float *)&plane_8)
                             + (float)((float)(volume_ot_testee_position_4
                                             - (float)((float)(*((float *)&plane_8 + 1) * v13->y) * m_radius))
                                     * v13->y))
                     + (float)((float)(v10 - (float)((float)(*((float *)&plane_8 + 1) * v13->x) * m_radius)) * v13->x)) > v19 )
            break;
          ++v13;
          if ( ++ia >= v11 )
            goto LABEL_7;
        }
      }
      else
      {
LABEL_7:
        this->m_result = 1;
      }
    }
  }
}
