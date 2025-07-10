void __userpurge vostok::collision::intersection_double_dispatcher::dispatch(
        vostok::collision::intersection_double_dispatcher *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        const vostok::collision::truncated_sphere_geometry_instance *bounding_volume,
        const vostok::collision::sphere_geometry_instance *testee)
{
  float *v7; // esi
  const vostok::math::float4x4 *v8; // eax
  float v9; // xmm1_4
  float v10; // xmm2_4
  vostok::math::float4_pod *p_c; // esi
  const vostok::math::float4x4 *v12; // eax
  float v13; // xmm0_4
  unsigned int v14; // esi
  vostok::math::float4 *m_begin; // eax
  float plane; // [esp+1Ch] [ebp-10h]
  int planea; // [esp+1Ch] [ebp-10h]
  float plane_8; // [esp+24h] [ebp-8h]
  float vars0; // [esp+2Ch] [ebp+0h]
  float retaddr; // [esp+30h] [ebp+4h]

  sqrtf(
    (float)((float)(testee->m_matrix.i.y * testee->m_matrix.i.y) + (float)(testee->m_matrix.i.z * testee->m_matrix.i.z))
  + (float)(testee->m_matrix.i.x * testee->m_matrix.i.x));
  v7 = (float *)(((int (__thiscall *)(const vostok::collision::geometry_instance *, int, int, int))this->m_bounding_volume->get_matrix)(
                   this->m_bounding_volume,
                   a3,
                   a4,
                   a2)
               + 48);
  v8 = this->m_testee->get_matrix(this->m_testee);
  v9 = v8->c.y - v7[1];
  v10 = v8->c.z - v7[2];
  if ( (float)((float)((float)(v9 * v9) + (float)(v10 * v10)) + (float)((float)(v8->c.x - *v7) * (float)(v8->c.x - *v7))) <= (float)(plane * plane) )
  {
    p_c = &this->m_bounding_volume->get_matrix(this->m_bounding_volume)->c;
    v12 = this->m_testee->get_matrix(this->m_testee);
    v13 = v12->c.x - p_c->x;
    v12 = (const vostok::math::float4x4 *)((char *)v12 + 48);
    vars0 = v12->i.y - p_c->y;
    retaddr = v12->i.z - p_c->z;
    this->m_bounding_volume->get_matrix((vostok::collision::geometry_instance *)this->m_bounding_volume);
    v14 = bounding_volume->m_planes.m_end - bounding_volume->m_planes.m_begin;
    planea = 0;
    if ( v14 )
    {
      plane_8 = sqrtf(
                  (float)((float)(testee->m_matrix.i.y * testee->m_matrix.i.y)
                        + (float)(testee->m_matrix.i.z * testee->m_matrix.i.z))
                + (float)(testee->m_matrix.i.x * testee->m_matrix.i.x));
      m_begin = bounding_volume->m_planes.m_begin;
      while ( (float)((float)((float)(m_begin->x * v13) + (float)(m_begin->z * retaddr)) + (float)(m_begin->y * vars0)) <= (float)((float)(bounding_volume->m_radius * m_begin->w) + plane_8) )
      {
        ++m_begin;
        if ( ++planea >= v14 )
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
