void __thiscall vostok::collision::containment_double_dispatcher::dispatch(
        vostok::collision::containment_double_dispatcher *this,
        const vostok::collision::truncated_sphere_geometry_instance *bounding_volume,
        const vostok::collision::box_geometry_instance *testee)
{
  const vostok::math::float4x4 *v4; // esi
  long double v5; // st7
  float x; // xmm4_4
  float y; // xmm5_4
  float z; // xmm6_4
  float *p_y; // edi
  float v10; // xmm0_4
  float v11; // xmm2_4
  const vostok::math::float4x4 *v12; // eax
  const vostok::math::float4x4 *v13; // eax
  float v14; // xmm0_4
  vostok::math::float4 *m_begin; // edx
  unsigned int v16; // eax
  unsigned int i; // ecx
  unsigned int v18; // [esp+10h] [ebp-7Ch]
  float squared_sphere_radius; // [esp+14h] [ebp-78h]
  float v20; // [esp+18h] [ebp-74h]
  float v21; // [esp+1Ch] [ebp-70h]
  float v22; // [esp+20h] [ebp-6Ch]
  float volume_to_vertex; // [esp+24h] [ebp-68h]
  float volume_to_vertex_4a; // [esp+28h] [ebp-64h]
  float volume_to_vertex_4; // [esp+28h] [ebp-64h]
  float volume_to_vertex_8; // [esp+2Ch] [ebp-60h]
  __int64 plane_8; // [esp+44h] [ebp-48h]
  vostok::math::float4x4 matrix; // [esp+4Ch] [ebp-40h] BYREF

  qmemcpy((void *)&matrix, this->m_testee->get_matrix(this->m_testee), sizeof(matrix));
  v4 = testee->get_matrix(testee);
  volume_to_vertex = sqrtf((float)((float)(v4->i.y * v4->i.y) + (float)(v4->i.z * v4->i.z)) + (float)(v4->i.x * v4->i.x));
  volume_to_vertex_4a = sqrtf((float)((float)(v4->j.z * v4->j.z) + (float)(v4->j.x * v4->j.x)) + (float)(v4->j.y * v4->j.y));
  v5 = sqrtf((float)((float)(v4->k.y * v4->k.y) + (float)(v4->k.z * v4->k.z)) + (float)(v4->k.x * v4->k.x));
  x = volume_to_vertex * matrix.i.x;
  matrix.j.x = matrix.j.x * volume_to_vertex_4a;
  y = matrix.i.y * volume_to_vertex;
  z = matrix.i.z * volume_to_vertex;
  matrix.j.y = volume_to_vertex_4a * matrix.j.y;
  matrix.i.x = volume_to_vertex * matrix.i.x;
  matrix.i.y = matrix.i.y * volume_to_vertex;
  matrix.i.z = matrix.i.z * volume_to_vertex;
  matrix.j.z = matrix.j.z * volume_to_vertex_4a;
  matrix.k.x = matrix.k.x * v5;
  squared_sphere_radius = bounding_volume->m_radius * bounding_volume->m_radius;
  p_y = &cuboid_vertices[0].y;
  matrix.k.y = matrix.k.y * v5;
  v18 = 0;
  matrix.k.z = v5 * matrix.k.z;
  while ( 1 )
  {
    v10 = *(p_y - 1);
    v11 = p_y[1];
    v20 = (float)((float)((float)(v11 * matrix.k.x) + (float)(v10 * x)) + (float)(*p_y * matrix.j.x)) + matrix.c.x;
    v21 = (float)((float)((float)(v10 * y) + (float)(matrix.k.y * v11)) + (float)(matrix.j.y * *p_y)) + matrix.c.y;
    v22 = (float)((float)((float)(v10 * z) + (float)(matrix.k.z * v11)) + (float)(matrix.j.z * *p_y)) + matrix.c.z;
    v12 = this->m_bounding_volume->get_matrix(this->m_bounding_volume);
    if ( squared_sphere_radius < (float)((float)((float)((float)(v20 - v12->c.x) * (float)(v20 - v12->c.x))
                                               + (float)((float)(v22 - v12->c.z) * (float)(v22 - v12->c.z)))
                                       + (float)((float)(v21 - v12->c.y) * (float)(v21 - v12->c.y))) )
      break;
    v13 = this->m_bounding_volume->get_matrix(this->m_bounding_volume);
    v14 = v20 - v13->c.x;
    v13 = (const vostok::math::float4x4 *)((char *)v13 + 48);
    volume_to_vertex_4 = v21 - v13->i.y;
    volume_to_vertex_8 = v22 - v13->i.z;
    this->m_bounding_volume->get_matrix((vostok::collision::geometry_instance *)this->m_bounding_volume);
    m_begin = bounding_volume->m_planes.m_begin;
    v16 = bounding_volume->m_planes.m_end - m_begin;
    for ( i = 0; i < v16; ++m_begin )
    {
      plane_8 = *(_QWORD *)&m_begin->elements[2];
      if ( (float)((float)((float)((float)(v14
                                         - (float)((float)(*((float *)&plane_8 + 1) * m_begin->x)
                                                 * bounding_volume->m_radius))
                                 * m_begin->x)
                         + (float)((float)(volume_to_vertex_8
                                         - (float)((float)(*((float *)&plane_8 + 1) * *(float *)&plane_8)
                                                 * bounding_volume->m_radius))
                                 * *(float *)&plane_8))
                 + (float)((float)(volume_to_vertex_4
                                 - (float)((float)(*((float *)&plane_8 + 1) * m_begin->y) * bounding_volume->m_radius))
                         * m_begin->y)) > 0.0 )
        return;
      ++i;
    }
    p_y += 3;
    v18 += 12;
    if ( v18 >= 0x60 )
    {
      this->m_result = 1;
      return;
    }
    z = matrix.i.z;
    y = matrix.i.y;
    x = matrix.i.x;
  }
}
