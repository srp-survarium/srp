void __userpurge vostok::math::cuboid::cuboid(
        const vostok::math::float4x4 *matrix@<esi>,
        vostok::math::cuboid *this,
        const vostok::math::cuboid *other)
{
  vostok::math::cuboid *v3; // edi
  int v4; // ebx
  float v5; // xmm2_4
  float v6; // xmm0_4
  float v7; // xmm1_4
  __int64 v8; // [esp+14h] [ebp-24h]
  __int64 v9; // [esp+1Ch] [ebp-1Ch]
  float v10; // [esp+2Ch] [ebp-Ch]
  float v11; // [esp+30h] [ebp-8h]
  float othera; // [esp+40h] [ebp+8h]

  v3 = this;
  v4 = (char *)other - (char *)this;
  do
  {
    v8 = *(_QWORD *)((char *)&v3->m_planes[0].plane.normal.x + v4);
    v9 = *(_QWORD *)((char *)&v3->m_planes[0].plane.vector.elements[2] + v4);
    v5 = (float)((float)((float)(matrix->j.x * *((float *)&v8 + 1)) + (float)(matrix->c.x * *((float *)&v9 + 1)))
               + (float)(matrix->k.x * *(float *)&v9))
       + (float)(matrix->i.x * *(float *)&v8);
    v6 = (float)((float)((float)(matrix->j.y * *((float *)&v8 + 1)) + (float)(matrix->k.y * *(float *)&v9))
               + (float)(*(float *)&v8 * matrix->i.y))
       + (float)(*((float *)&v9 + 1) * matrix->c.y);
    v10 = (float)((float)((float)(matrix->i.z * *(float *)&v8) + (float)(matrix->c.z * *((float *)&v9 + 1)))
                + (float)(matrix->j.z * *((float *)&v8 + 1)))
        + (float)(*(float *)&v9 * matrix->k.z);
    v11 = (float)((float)((float)(matrix->k.w * *(float *)&v9) + (float)(matrix->i.w * *(float *)&v8))
                + (float)(matrix->c.w * *((float *)&v9 + 1)))
        + (float)(*((float *)&v8 + 1) * matrix->j.w);
    othera = sqrtf((float)((float)(v10 * v10) + (float)(v5 * v5)) + (float)(v6 * v6));
    *(float *)&v8 = (float)(*(float *)&clear_value / othera) * v5;
    *((float *)&v8 + 1) = (float)(*(float *)&clear_value / othera) * v6;
    v7 = (float)(*(float *)&clear_value / othera) * v10;
    *((float *)&v9 + 1) = (float)(*(float *)&clear_value / othera) * v11;
    *(_QWORD *)&v3->m_planes[0].plane.normal.x = v8;
    *(float *)&v9 = v7;
    *(_QWORD *)&v3->m_planes[0].plane.vector.elements[2] = v9;
    vostok::math::aabb_plane::normalize(v3->m_planes);
    v3 = (vostok::math::cuboid *)((char *)v3 + 20);
  }
  while ( v3 != &this[1] );
}
