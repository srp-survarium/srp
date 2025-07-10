void __thiscall vostok::collision::containment_double_dispatcher::dispatch(
        vostok::collision::containment_double_dispatcher *this,
        const vostok::collision::box_geometry_instance *bounding_volume,
        const vostok::collision::sphere_geometry_instance *testee)
{
  vostok::math::float4_pod *p_c; // esi
  const vostok::math::float4x4 *v5; // eax
  float v6; // xmm0_4
  const vostok::math::float4x4 *v7; // eax
  const vostok::math::float4x4 *v8; // esi
  const vostok::math::float4x4 *v9; // eax
  const vostok::math::float4x4 *v10; // eax
  float projection_on_x; // [esp+Ch] [ebp-1Ch]
  float v12; // [esp+14h] [ebp-14h]
  float v13; // [esp+18h] [ebp-10h]
  float v14; // [esp+1Ch] [ebp-Ch]
  float v15; // [esp+20h] [ebp-8h]
  float v16; // [esp+24h] [ebp-4h]
  float projection_on_z; // [esp+2Ch] [ebp+4h]
  float projection_on_za; // [esp+2Ch] [ebp+4h]

  p_c = &this->m_bounding_volume->get_matrix(this->m_bounding_volume)->c;
  v5 = this->m_testee->get_matrix(this->m_testee);
  v6 = v5->c.x - p_c->x;
  v5 = (const vostok::math::float4x4 *)((char *)v5 + 48);
  v12 = v5->i.y - p_c->y;
  v13 = v5->i.z - p_c->z;
  v7 = this->m_bounding_volume->get_matrix(this->m_bounding_volume);
  projection_on_x = fabs((float)((float)(v7->i.z * v13) + (float)(v7->i.y * v12)) + (float)(v7->i.x * v6));
  v8 = bounding_volume->get_matrix(bounding_volume);
  v14 = sqrtf((float)((float)(v8->i.y * v8->i.y) + (float)(v8->i.z * v8->i.z)) + (float)(v8->i.x * v8->i.x));
  v15 = sqrtf((float)((float)(v8->j.x * v8->j.x) + (float)(v8->j.y * v8->j.y)) + (float)(v8->j.z * v8->j.z));
  v16 = sqrtf((float)((float)(v8->k.y * v8->k.y) + (float)(v8->k.z * v8->k.z)) + (float)(v8->k.x * v8->k.x));
  if ( sqrtf(
         (float)((float)(testee->m_matrix.i.y * testee->m_matrix.i.y)
               + (float)(testee->m_matrix.i.z * testee->m_matrix.i.z))
       + (float)(testee->m_matrix.i.x * testee->m_matrix.i.x))
     + projection_on_x <= v14 )
  {
    v9 = this->m_bounding_volume->get_matrix(this->m_bounding_volume);
    projection_on_z = fabs((float)((float)(v9->j.z * v13) + (float)(v9->j.y * v12)) + (float)(v6 * v9->j.x));
    if ( sqrtf(
           (float)((float)(testee->m_matrix.i.y * testee->m_matrix.i.y)
                 + (float)(testee->m_matrix.i.z * testee->m_matrix.i.z))
         + (float)(testee->m_matrix.i.x * testee->m_matrix.i.x))
       + projection_on_z <= v15 )
    {
      v10 = this->m_bounding_volume->get_matrix(this->m_bounding_volume);
      projection_on_za = fabs((float)((float)(v10->k.z * v13) + (float)(v10->k.y * v12)) + (float)(v10->k.x * v6));
      if ( sqrtf(
             (float)((float)(testee->m_matrix.i.x * testee->m_matrix.i.x)
                   + (float)(testee->m_matrix.i.y * testee->m_matrix.i.y))
           + (float)(testee->m_matrix.i.z * testee->m_matrix.i.z))
         + projection_on_za <= v16 )
        this->m_result = 1;
    }
  }
}
