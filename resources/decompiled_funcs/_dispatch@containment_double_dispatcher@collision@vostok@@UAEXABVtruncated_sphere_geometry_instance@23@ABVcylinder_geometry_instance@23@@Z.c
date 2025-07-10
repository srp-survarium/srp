void __thiscall vostok::collision::containment_double_dispatcher::dispatch(
        vostok::collision::containment_double_dispatcher *this,
        const vostok::collision::truncated_sphere_geometry_instance *bounding_volume,
        const vostok::collision::cylinder_geometry_instance *testee)
{
  vostok::math::float4_pod *p_c; // edi
  const vostok::math::float4x4 *v5; // eax
  float v6; // xmm0_4
  const vostok::math::float4x4 *v7; // eax
  float y; // xmm5_4
  float z; // xmm6_4
  float x; // xmm7_4
  const vostok::math::float4x4 *v11; // eax
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm7_4
  float v15; // xmm2_4
  float v16; // xmm0_4
  long double v17; // st7
  const vostok::math::float4x4 *v18; // eax
  const vostok::math::float4x4 *v19; // eax
  const vostok::math::float4x4 *v20; // eax
  const vostok::collision::truncated_sphere_geometry_instance *v21; // ecx
  vostok::math::float4 *m_begin; // eax
  float m_radius; // xmm3_4
  const vostok::math::float4x4 *v24; // eax
  float v25; // xmm0_4
  int v26; // [esp+14h] [ebp-50h]
  float ia; // [esp+18h] [ebp-4Ch]
  float ib; // [esp+18h] [ebp-4Ch]
  float ic; // [esp+18h] [ebp-4Ch]
  float id; // [esp+18h] [ebp-4Ch]
  float ie; // [esp+18h] [ebp-4Ch]
  unsigned int i; // [esp+18h] [ebp-4Ch]
  float v33; // [esp+1Ch] [ebp-48h]
  float v34; // [esp+1Ch] [ebp-48h]
  float v35; // [esp+20h] [ebp-44h]
  float v36; // [esp+24h] [ebp-40h]
  float v37; // [esp+28h] [ebp-3Ch]
  unsigned int count; // [esp+2Ch] [ebp-38h]
  __int64 testee_x_axe; // [esp+30h] [ebp-34h]
  float testee_x_axe_4; // [esp+34h] [ebp-30h]
  float testee_x_axe_8b; // [esp+38h] [ebp-2Ch]
  float testee_x_axe_8; // [esp+38h] [ebp-2Ch]
  float testee_x_axe_8a; // [esp+38h] [ebp-2Ch]
  float plane_position; // [esp+3Ch] [ebp-28h]
  float plane_positiona; // [esp+3Ch] [ebp-28h]
  float plane_position_4; // [esp+40h] [ebp-24h]
  float plane_position_4a; // [esp+40h] [ebp-24h]
  float plane_position_4b; // [esp+40h] [ebp-24h]
  float plane_position_8; // [esp+44h] [ebp-20h]
  float plane_position_8a; // [esp+44h] [ebp-20h]
  float plane_position_8b; // [esp+44h] [ebp-20h]
  __int64 plane; // [esp+54h] [ebp-10h]
  __int64 plane_8; // [esp+5Ch] [ebp-8h]

  p_c = &this->m_testee->get_matrix(this->m_testee)->c;
  v5 = this->m_bounding_volume->get_matrix(this->m_bounding_volume);
  v6 = v5->c.x - p_c->x;
  v5 = (const vostok::math::float4x4 *)((char *)v5 + 48);
  testee_x_axe_4 = v5->i.y - p_c->y;
  testee_x_axe_8b = v5->i.z - p_c->z;
  v7 = this->m_testee->get_matrix(this->m_testee);
  y = v7->j.y;
  z = v7->j.z;
  x = v7->j.x;
  plane_position_8 = (float)(testee_x_axe_4 * x) - (float)(v6 * y);
  plane_position = (float)(testee_x_axe_8b * y) - (float)(testee_x_axe_4 * z);
  plane_position_4 = (float)(v6 * z) - (float)(testee_x_axe_8b * x);
  v11 = this->m_testee->get_matrix(this->m_testee);
  if ( (float)((float)(plane_position_8 + plane_position_4) + plane_position) == 0.0 )
  {
    testee_x_axe = *(_QWORD *)&v11->i.x;
    testee_x_axe_8 = v11->i.z;
  }
  else
  {
    v12 = v11->j.z;
    v13 = (float)(v11->j.y * plane_position_8) - (float)(v12 * plane_position_4);
    v14 = v11->j.x;
    v15 = (float)(v14 * plane_position_4) - (float)(v11->j.y * plane_position);
    v16 = (float)(v12 * plane_position) - (float)(v14 * plane_position_8);
    v17 = 1.0 / sqrtf((float)((float)(v15 * v15) + (float)(v16 * v16)) + (float)(v13 * v13));
    ia = v17;
    *(float *)&testee_x_axe = ia * v13;
    *((float *)&testee_x_axe + 1) = v16 * v17;
    testee_x_axe_8 = v17 * v15;
  }
  ib = sqrtf(
         (float)((float)(testee->m_matrix.i.x * testee->m_matrix.i.x)
               + (float)(testee->m_matrix.i.y * testee->m_matrix.i.y))
       + (float)(testee->m_matrix.i.z * testee->m_matrix.i.z));
  *(float *)&testee_x_axe = p_c->x + (float)(*(float *)&testee_x_axe * ib);
  testee_x_axe_8a = (float)(testee_x_axe_8 * ib) + p_c->z;
  *((float *)&testee_x_axe + 1) = (float)(*((float *)&testee_x_axe + 1) * ib) + p_c->y;
  ic = sqrtf(
         (float)((float)(testee->m_matrix.j.x * testee->m_matrix.j.x)
               + (float)(testee->m_matrix.j.y * testee->m_matrix.j.y))
       + (float)(testee->m_matrix.j.z * testee->m_matrix.j.z));
  v18 = this->m_testee->get_matrix(this->m_testee);
  plane_positiona = v18->j.x * ic;
  plane_position_4a = v18->j.y * ic;
  plane_position_8a = v18->j.z * ic;
  id = bounding_volume->m_radius;
  v19 = this->m_bounding_volume->get_matrix(this->m_bounding_volume);
  if ( (float)((float)((float)((float)((float)(plane_position_8a + testee_x_axe_8a) - v19->c.z)
                             * (float)((float)(plane_position_8a + testee_x_axe_8a) - v19->c.z))
                     + (float)((float)((float)(plane_position_4a + *((float *)&testee_x_axe + 1)) - v19->c.y)
                             * (float)((float)(plane_position_4a + *((float *)&testee_x_axe + 1)) - v19->c.y)))
             + (float)((float)((float)(plane_positiona + *(float *)&testee_x_axe) - v19->c.x)
                     * (float)((float)(plane_positiona + *(float *)&testee_x_axe) - v19->c.x))) <= (float)(id * id) )
  {
    ie = bounding_volume->m_radius;
    v20 = this->m_bounding_volume->get_matrix(this->m_bounding_volume);
    if ( (float)((float)((float)((float)((float)(testee_x_axe_8a - plane_position_8a) - v20->c.z)
                               * (float)((float)(testee_x_axe_8a - plane_position_8a) - v20->c.z))
                       + (float)((float)((float)(*((float *)&testee_x_axe + 1) - plane_position_4a) - v20->c.y)
                               * (float)((float)(*((float *)&testee_x_axe + 1) - plane_position_4a) - v20->c.y)))
               + (float)((float)((float)(*(float *)&testee_x_axe - plane_positiona) - v20->c.x)
                       * (float)((float)(*(float *)&testee_x_axe - plane_positiona) - v20->c.x))) <= (float)(ie * ie) )
    {
      this->m_bounding_volume->get_matrix((vostok::collision::geometry_instance *)this->m_bounding_volume);
      v21 = bounding_volume;
      count = bounding_volume->m_planes.m_end - bounding_volume->m_planes.m_begin;
      i = 0;
      if ( count )
      {
        v26 = 0;
        while ( 1 )
        {
          m_begin = v21->m_planes.m_begin;
          m_radius = v21->m_radius;
          plane = *(_QWORD *)&m_begin[v26].x;
          plane_8 = *(_QWORD *)&m_begin[v26].elements[2];
          v24 = this->m_bounding_volume->get_matrix(this->m_bounding_volume);
          v25 = (float)((float)(*(float *)&plane * *((float *)&plane_8 + 1)) * m_radius) + v24->c.x;
          v24 = (const vostok::math::float4x4 *)((char *)v24 + 48);
          plane_position_4b = v24->i.y + (float)((float)(*((float *)&plane + 1) * *((float *)&plane_8 + 1)) * m_radius);
          plane_position_8b = v24->i.z + (float)((float)(*(float *)&plane_8 * *((float *)&plane_8 + 1)) * m_radius);
          this->m_testee->get_matrix((vostok::collision::geometry_instance *)this->m_testee);
          this->m_testee->get_matrix((vostok::collision::geometry_instance *)this->m_testee);
          v35 = p_c->x - v25;
          v36 = p_c->y - plane_position_4b;
          v37 = p_c->z - plane_position_8b;
          v33 = *(float *)&plane_8 * v37 + *((float *)&plane + 1) * v36 + v35 * *(float *)&plane;
          if ( v33 > -sqrtf(
                        (float)((float)(testee->m_matrix.i.x * testee->m_matrix.i.x)
                              + (float)(testee->m_matrix.i.y * testee->m_matrix.i.y))
                      + (float)(testee->m_matrix.i.z * testee->m_matrix.i.z)) )
            break;
          v34 = v36 * *((float *)&plane + 1) + v37 * *(float *)&plane_8 + v35 * *(float *)&plane;
          if ( v34 > -sqrtf(
                        (float)((float)(testee->m_matrix.i.z * testee->m_matrix.i.z)
                              + (float)(testee->m_matrix.i.x * testee->m_matrix.i.x))
                      + (float)(testee->m_matrix.i.y * testee->m_matrix.i.y)) )
            break;
          ++v26;
          if ( ++i >= count )
            goto LABEL_12;
          v21 = bounding_volume;
        }
      }
      else
      {
LABEL_12:
        this->m_result = 1;
      }
    }
  }
}
