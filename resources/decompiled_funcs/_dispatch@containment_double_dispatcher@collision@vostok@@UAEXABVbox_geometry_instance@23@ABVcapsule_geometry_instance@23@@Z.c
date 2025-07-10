void __thiscall vostok::collision::containment_double_dispatcher::dispatch(
        vostok::collision::containment_double_dispatcher *this,
        const vostok::collision::box_geometry_instance *bounding_volume,
        const vostok::collision::capsule_geometry_instance *testee)
{
  const vostok::math::float4x4 *v5; // eax
  float x; // xmm1_4
  const vostok::math::float4x4 *v7; // eax
  float v8; // xmm0_4
  const vostok::math::float4x4 *v9; // eax
  float v10; // xmm0_4
  const vostok::math::float4x4 *v11; // edi
  const vostok::math::float4x4 *v12; // eax
  const vostok::math::float4x4 *v13; // eax
  const vostok::math::float4x4 *v14; // eax
  const vostok::math::float4x4 *v15; // eax
  float v16; // xmm1_4
  const vostok::math::float4x4 *v17; // eax
  float v18; // xmm0_4
  const vostok::math::float4x4 *v19; // eax
  float v20; // xmm0_4
  const vostok::math::float4x4 *v21; // eax
  const vostok::math::float4x4 *v22; // eax
  const vostok::math::float4x4 *v23; // eax
  float center_to_point_center_4; // [esp+1Ch] [ebp-2Ch]
  float center_to_point_center_4a; // [esp+1Ch] [ebp-2Ch]
  float center_to_point_center_8; // [esp+20h] [ebp-28h]
  float center_to_point_center_8a; // [esp+20h] [ebp-28h]
  float v28; // [esp+24h] [ebp-24h]
  float v29; // [esp+28h] [ebp-20h]
  float v30; // [esp+28h] [ebp-20h]
  float v31; // [esp+2Ch] [ebp-1Ch]
  float v32; // [esp+2Ch] [ebp-1Ch]
  float capsule_start_point_4; // [esp+34h] [ebp-14h]
  float capsule_start_point_4a; // [esp+34h] [ebp-14h]
  float capsule_start_point_8; // [esp+38h] [ebp-10h]
  float capsule_start_point_8a; // [esp+38h] [ebp-10h]
  float capsule_end_point_4; // [esp+40h] [ebp-8h]
  float capsule_end_point_8; // [esp+44h] [ebp-4h]
  float testee_radiusa; // [esp+50h] [ebp+8h]
  float testee_radius; // [esp+50h] [ebp+8h]
  float testee_radiusb; // [esp+50h] [ebp+8h]

  testee_radiusa = testee->m_half_length;
  v5 = this->m_testee->get_matrix(this->m_testee);
  x = v5->j.x;
  v5 = (const vostok::math::float4x4 *)((char *)v5 + 16);
  v29 = v5->i.y * testee_radiusa;
  v31 = v5->i.z * testee_radiusa;
  v7 = this->m_testee->get_matrix(this->m_testee);
  v8 = v7->c.x - (float)(x * testee_radiusa);
  v7 = (const vostok::math::float4x4 *)((char *)v7 + 48);
  capsule_start_point_4 = v7->i.y - v29;
  capsule_start_point_8 = v7->i.z - v31;
  v9 = this->m_bounding_volume->get_matrix(this->m_bounding_volume);
  v10 = v8 - v9->c.x;
  v9 = (const vostok::math::float4x4 *)((char *)v9 + 48);
  center_to_point_center_4 = capsule_start_point_4 - v9->i.y;
  center_to_point_center_8 = capsule_start_point_8 - v9->i.z;
  v11 = bounding_volume->get_matrix(bounding_volume);
  v28 = sqrtf((float)((float)(v11->i.x * v11->i.x) + (float)(v11->i.y * v11->i.y)) + (float)(v11->i.z * v11->i.z));
  v30 = sqrtf((float)((float)(v11->j.z * v11->j.z) + (float)(v11->j.x * v11->j.x)) + (float)(v11->j.y * v11->j.y));
  v32 = sqrtf((float)((float)(v11->k.y * v11->k.y) + (float)(v11->k.z * v11->k.z)) + (float)(v11->k.x * v11->k.x));
  testee_radius = testee->m_radius;
  v12 = this->m_bounding_volume->get_matrix(this->m_bounding_volume);
  if ( (float)(fabs(
                 (float)((float)(v12->i.z * center_to_point_center_8) + (float)(v12->i.y * center_to_point_center_4))
               + (float)(v12->i.x * v10))
             + testee_radius) <= v28 )
  {
    v13 = this->m_bounding_volume->get_matrix(this->m_bounding_volume);
    if ( (float)(fabs(
                   (float)((float)(v13->j.z * center_to_point_center_8) + (float)(v13->j.y * center_to_point_center_4))
                 + (float)(v13->j.x * v10))
               + testee_radius) <= v30 )
    {
      v14 = this->m_bounding_volume->get_matrix(this->m_bounding_volume);
      if ( (float)(fabs(
                     (float)((float)(v14->k.z * center_to_point_center_8) + (float)(v14->k.y * center_to_point_center_4))
                   + (float)(v14->k.x * v10))
                 + testee_radius) <= v32 )
      {
        testee_radiusb = testee->m_half_length;
        v15 = this->m_testee->get_matrix(this->m_testee);
        v16 = v15->j.x;
        v15 = (const vostok::math::float4x4 *)((char *)v15 + 16);
        capsule_start_point_4a = v15->i.y * testee_radiusb;
        capsule_start_point_8a = v15->i.z * testee_radiusb;
        v17 = this->m_testee->get_matrix(this->m_testee);
        v18 = v17->c.x + (float)(v16 * testee_radiusb);
        v17 = (const vostok::math::float4x4 *)((char *)v17 + 48);
        capsule_end_point_4 = v17->i.y + capsule_start_point_4a;
        capsule_end_point_8 = v17->i.z + capsule_start_point_8a;
        v19 = this->m_bounding_volume->get_matrix(this->m_bounding_volume);
        v20 = v18 - v19->c.x;
        v19 = (const vostok::math::float4x4 *)((char *)v19 + 48);
        center_to_point_center_4a = capsule_end_point_4 - v19->i.y;
        center_to_point_center_8a = capsule_end_point_8 - v19->i.z;
        v21 = this->m_bounding_volume->get_matrix(this->m_bounding_volume);
        if ( (float)(testee->m_radius
                   + fabs(
                       (float)((float)(v21->i.z * center_to_point_center_8a)
                             + (float)(v21->i.y * center_to_point_center_4a))
                     + (float)(v21->i.x * v20))) <= v28 )
        {
          v22 = this->m_bounding_volume->get_matrix(this->m_bounding_volume);
          if ( (float)(testee->m_radius
                     + fabs(
                         (float)((float)(v22->j.z * center_to_point_center_8a)
                               + (float)(v22->j.y * center_to_point_center_4a))
                       + (float)(v20 * v22->j.x))) <= v30 )
          {
            v23 = this->m_bounding_volume->get_matrix(this->m_bounding_volume);
            if ( (float)(testee->m_radius
                       + fabs(
                           (float)((float)(v23->k.z * center_to_point_center_8a)
                                 + (float)(v23->k.y * center_to_point_center_4a))
                         + (float)(v20 * v23->k.x))) <= v32 )
              this->m_result = 1;
          }
        }
      }
    }
  }
}
