void __thiscall vostok::collision::intersection_double_dispatcher::dispatch(
        vostok::collision::intersection_double_dispatcher *this,
        const vostok::collision::box_geometry_instance *bounding_volume,
        const vostok::collision::capsule_geometry_instance *testee)
{
  const vostok::collision::geometry_instance *m_testee; // eax

  m_testee = this->m_testee;
  this->m_testee = this->m_bounding_volume;
  this->m_bounding_volume = m_testee;
  this->dispatch(this, testee, bounding_volume);
}


void __thiscall vostok::collision::intersection_double_dispatcher::dispatch(
        vostok::collision::intersection_double_dispatcher *this,
        const vostok::collision::box_geometry_instance *bounding_volume,
        const vostok::collision::cylinder_geometry_instance *testee)
{
  const vostok::collision::geometry_instance *m_testee; // eax

  m_testee = this->m_testee;
  this->m_testee = this->m_bounding_volume;
  this->m_bounding_volume = m_testee;
  this->dispatch(this, testee, bounding_volume);
}


void __thiscall vostok::collision::intersection_double_dispatcher::dispatch(
        vostok::collision::intersection_double_dispatcher *this,
        const vostok::collision::box_geometry_instance *bounding_volume,
        const vostok::collision::sphere_geometry_instance *testee)
{
  const vostok::collision::geometry_instance *m_testee; // eax

  m_testee = this->m_testee;
  this->m_testee = this->m_bounding_volume;
  this->m_bounding_volume = m_testee;
  this->dispatch(this, testee, bounding_volume);
}


void __thiscall vostok::collision::intersection_double_dispatcher::dispatch(
        vostok::collision::intersection_double_dispatcher *this,
        const vostok::collision::box_geometry_instance *bounding_volume,
        const vostok::collision::truncated_sphere_geometry_instance *testee)
{
  const vostok::collision::geometry_instance *m_testee; // eax

  m_testee = this->m_testee;
  this->m_testee = this->m_bounding_volume;
  this->m_bounding_volume = m_testee;
  this->dispatch(this, testee, bounding_volume);
}


void __thiscall vostok::collision::intersection_double_dispatcher::dispatch(
        vostok::collision::intersection_double_dispatcher *this,
        const vostok::collision::capsule_geometry_instance *bounding_volume,
        const vostok::collision::capsule_geometry_instance *testee)
{
  const vostok::math::float4x4 *v4; // eax
  float x; // xmm1_4
  const vostok::math::float4x4 *v6; // eax
  float v7; // xmm0_4
  const vostok::collision::geometry_instance *m_testee; // ecx
  const vostok::math::float4x4 *(__thiscall *get_matrix)(vostok::collision::geometry_instance *); // edx
  float *p_x; // eax
  const vostok::math::float4x4 *v11; // eax
  float v12; // xmm0_4
  const vostok::collision::geometry_instance *m_bounding_volume; // ecx
  const vostok::math::float4x4 *(__thiscall *v14)(vostok::collision::geometry_instance *); // edx
  float *v15; // eax
  float v16; // xmm1_4
  const vostok::math::float4x4 *v17; // eax
  float v18; // xmm0_4
  const vostok::collision::geometry_instance *v19; // ecx
  const vostok::math::float4x4 *(__thiscall *v20)(vostok::collision::geometry_instance *); // edx
  float *v21; // eax
  float v22; // xmm1_4
  const vostok::math::float4x4 *v23; // eax
  float v24; // xmm0_4
  float m_half_length; // [esp+0h] [ebp-4Ch]
  float v26; // [esp+4h] [ebp-48h]
  float v27; // [esp+8h] [ebp-44h]
  float m_radius; // [esp+Ch] [ebp-40h]
  float v29; // [esp+10h] [ebp-3Ch]
  float v30; // [esp+14h] [ebp-38h]
  float v31; // [esp+14h] [ebp-38h]
  float v32; // [esp+14h] [ebp-38h]
  float v33; // [esp+14h] [ebp-38h]
  float v34; // [esp+18h] [ebp-34h]
  float v35; // [esp+18h] [ebp-34h]
  float v36; // [esp+18h] [ebp-34h]
  float v37; // [esp+18h] [ebp-34h]
  vostok::math::float3 p4; // [esp+1Ch] [ebp-30h] BYREF
  vostok::math::float3 p1; // [esp+28h] [ebp-24h] BYREF
  vostok::math::float3 v40; // [esp+34h] [ebp-18h] BYREF
  float v41[3]; // [esp+40h] [ebp-Ch] BYREF

  m_half_length = testee->m_half_length;
  v26 = bounding_volume->m_half_length;
  m_radius = testee->m_radius;
  v27 = bounding_volume->m_radius;
  v4 = this->m_testee->get_matrix(this->m_testee);
  x = v4->j.x;
  v4 = (const vostok::math::float4x4 *)((char *)v4 + 16);
  v30 = v4->i.y * m_half_length;
  v34 = v4->i.z * m_half_length;
  v6 = this->m_testee->get_matrix(this->m_testee);
  v7 = v6->c.x - (float)(x * m_half_length);
  m_testee = this->m_testee;
  v6 = (const vostok::math::float4x4 *)((char *)v6 + 48);
  p4.x = v7;
  p4.y = v6->i.y - v30;
  get_matrix = m_testee->get_matrix;
  p4.z = v6->i.z - v34;
  p_x = &get_matrix((vostok::collision::geometry_instance *)m_testee)->j.x;
  v29 = m_half_length * *p_x;
  v31 = p_x[1] * m_half_length;
  v35 = p_x[2] * m_half_length;
  v11 = this->m_testee->get_matrix(this->m_testee);
  v12 = v29 + v11->c.x;
  m_bounding_volume = this->m_bounding_volume;
  v11 = (const vostok::math::float4x4 *)((char *)v11 + 48);
  v40.x = v12;
  v40.y = v11->i.y + v31;
  v14 = m_bounding_volume->get_matrix;
  v40.z = v11->i.z + v35;
  v15 = (float *)v14((vostok::collision::geometry_instance *)m_bounding_volume);
  v16 = v15[4];
  v15 += 4;
  v32 = v15[1] * v26;
  v36 = v15[2] * v26;
  v17 = this->m_bounding_volume->get_matrix(this->m_bounding_volume);
  v18 = v17->c.x - (float)(v16 * v26);
  v19 = this->m_bounding_volume;
  v17 = (const vostok::math::float4x4 *)((char *)v17 + 48);
  v41[0] = v18;
  v41[1] = v17->i.y - v32;
  v20 = v19->get_matrix;
  v41[2] = v17->i.z - v36;
  v21 = (float *)v20((vostok::collision::geometry_instance *)v19);
  v22 = v21[4];
  v21 += 4;
  v33 = v21[1] * v26;
  v37 = v21[2] * v26;
  v23 = this->m_bounding_volume->get_matrix(this->m_bounding_volume);
  v24 = (float)(v22 * v26) + v23->c.x;
  v23 = (const vostok::math::float4x4 *)((char *)v23 + 48);
  p1.x = v24;
  p1.y = v23->i.y + v33;
  p1.z = v23->i.z + v37;
  this->m_result = vostok::collision::segment_segment_intersect(v41, &v40, v27 + m_radius, &p1, &p4);
}


void __thiscall vostok::collision::intersection_double_dispatcher::dispatch(
        vostok::collision::intersection_double_dispatcher *this,
        const vostok::collision::capsule_geometry_instance *bounding_volume,
        const vostok::collision::box_geometry_instance *testee)
{
  const vostok::math::float4x4 *v4; // eax
  const vostok::math::float4x4 *v5; // eax
  float y; // xmm2_4
  float x; // xmm0_4
  float z; // xmm1_4
  const vostok::math::float4x4 *v9; // eax
  float v10; // xmm3_4
  float v11; // xmm2_4
  float v12; // xmm1_4
  const vostok::math::float4x4 *v13; // esi
  float m_half_length; // xmm1_4
  float m_radius; // xmm0_4
  float v16; // [esp+18h] [ebp-64h]
  float v17; // [esp+1Ch] [ebp-60h]
  float v18; // [esp+20h] [ebp-5Ch]
  float v19; // [esp+24h] [ebp-58h]
  float v20; // [esp+28h] [ebp-54h]
  float v21; // [esp+2Ch] [ebp-50h]
  float v22; // [esp+30h] [ebp-4Ch]
  float v23; // [esp+34h] [ebp-48h]
  float v24; // [esp+38h] [ebp-44h]
  vostok::math::float4x4 inverted_matrix; // [esp+3Ch] [ebp-40h] BYREF

  v4 = this->m_testee->get_matrix(this->m_testee);
  invert_impl(
    v4,
    &inverted_matrix,
    (float)((float)((float)((float)(v4->j.y * v4->k.z) - (float)(v4->j.z * v4->k.y)) * v4->i.x)
          - (float)((float)((float)(v4->j.x * v4->k.z) - (float)(v4->k.x * v4->j.z)) * v4->i.y))
  + (float)((float)((float)(v4->j.x * v4->k.y) - (float)(v4->k.x * v4->j.y)) * v4->i.z));
  v5 = this->m_bounding_volume->get_matrix(this->m_bounding_volume);
  y = v5->j.y;
  x = v5->j.x;
  z = v5->j.z;
  v22 = (float)((float)(x * inverted_matrix.i.x) + (float)(y * inverted_matrix.j.x)) + (float)(z * inverted_matrix.k.x);
  v23 = (float)((float)(x * inverted_matrix.i.y) + (float)(y * inverted_matrix.j.y)) + (float)(z * inverted_matrix.k.y);
  v24 = (float)((float)(x * inverted_matrix.i.z) + (float)(y * inverted_matrix.j.z)) + (float)(z * inverted_matrix.k.z);
  v9 = this->m_bounding_volume->get_matrix(this->m_bounding_volume);
  v10 = v9->c.y;
  v11 = v9->c.z;
  v16 = (float)((float)((float)(v9->c.x * inverted_matrix.i.x) + (float)(v10 * inverted_matrix.j.x))
              + (float)(v11 * inverted_matrix.k.x))
      + inverted_matrix.c.x;
  v12 = v9->c.x;
  v17 = (float)((float)((float)(v12 * inverted_matrix.i.y) + (float)(v10 * inverted_matrix.j.y))
              + (float)(v11 * inverted_matrix.k.y))
      + inverted_matrix.c.y;
  v18 = (float)((float)((float)(v12 * inverted_matrix.i.z) + (float)(v10 * inverted_matrix.j.z))
              + (float)(v11 * inverted_matrix.k.z))
      + inverted_matrix.c.z;
  v13 = testee->get_matrix(testee);
  v19 = sqrtf((float)((float)(v13->i.z * v13->i.z) + (float)(v13->i.x * v13->i.x)) + (float)(v13->i.y * v13->i.y));
  v20 = sqrtf((float)((float)(v13->j.z * v13->j.z) + (float)(v13->j.x * v13->j.x)) + (float)(v13->j.y * v13->j.y));
  v21 = sqrtf((float)((float)(v13->k.x * v13->k.x) + (float)(v13->k.y * v13->k.y)) + (float)(v13->k.z * v13->k.z));
  m_half_length = bounding_volume->m_half_length;
  m_radius = bounding_volume->m_radius;
  if ( COERCE_FLOAT(LODWORD(v16) & 0x7FFFFFFF) <= (float)((float)((float)(COERCE_FLOAT(LODWORD(v22) & 0x7FFFFFFF)
                                                                        * m_half_length)
                                                                + v19)
                                                        + m_radius)
    && COERCE_FLOAT(LODWORD(v17) & 0x7FFFFFFF) <= (float)((float)((float)(COERCE_FLOAT(LODWORD(v23) & 0x7FFFFFFF)
                                                                        * m_half_length)
                                                                + v20)
                                                        + m_radius)
    && COERCE_FLOAT(LODWORD(v18) & 0x7FFFFFFF) <= (float)((float)((float)(COERCE_FLOAT(LODWORD(v24) & 0x7FFFFFFF)
                                                                        * m_half_length)
                                                                + v21)
                                                        + m_radius)
    && fabs((float)(v17 * v24) - (float)(v18 * v23)) <= (float)((float)((float)(v21
                                                                              * COERCE_FLOAT(LODWORD(v23) & 0x7FFFFFFF))
                                                                      + (float)(v20
                                                                              * COERCE_FLOAT(LODWORD(v24) & 0x7FFFFFFF)))
                                                              + m_radius)
    && fabs((float)(v18 * v22) - (float)(v24 * v16)) <= (float)((float)((float)(COERCE_FLOAT(LODWORD(v24) & 0x7FFFFFFF)
                                                                              * v19)
                                                                      + (float)(v21
                                                                              * COERCE_FLOAT(LODWORD(v22) & 0x7FFFFFFF)))
                                                              + m_radius)
    && fabs((float)(v23 * v16) - (float)(v17 * v22)) <= (float)((float)((float)(COERCE_FLOAT(LODWORD(v23) & 0x7FFFFFFF)
                                                                              * v19)
                                                                      + (float)(v20
                                                                              * COERCE_FLOAT(LODWORD(v22) & 0x7FFFFFFF)))
                                                              + m_radius) )
  {
    this->m_result = 1;
  }
}


void __thiscall vostok::collision::intersection_double_dispatcher::dispatch(
        vostok::collision::intersection_double_dispatcher *this,
        const vostok::collision::capsule_geometry_instance *bounding_volume,
        const vostok::collision::cylinder_geometry_instance *testee)
{
  _BYTE v3[148]; // [esp-94h] [ebp-124h] BYREF
  _BYTE v4[136]; // [esp+0h] [ebp-90h] BYREF

  qmemcpy(v4, testee, sizeof(v4));
  qmemcpy(v3, bounding_volume, sizeof(v3));
  survarium::weapon_user_dead_state::finalize(0);
  JUMPOUT(0x6D54C6);
}


void __thiscall vostok::collision::intersection_double_dispatcher::dispatch(
        vostok::collision::intersection_double_dispatcher *this,
        const vostok::collision::capsule_geometry_instance *bounding_volume,
        const vostok::collision::sphere_geometry_instance *testee)
{
  vostok::math::float4_pod *p_c; // esi
  vostok::math::float4_pod *p_j; // edi
  const vostok::math::float4x4 *v6; // eax
  float m_half_length; // xmm3_4
  float v9; // xmm5_4
  float v10; // xmm6_4
  float v11; // xmm7_4
  float v12; // xmm4_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // xmm1_4
  float v16; // xmm0_4
  float v17; // xmm3_4
  float z; // [esp+14h] [ebp-20h]
  float y; // [esp+14h] [ebp-20h]
  float v20; // [esp+18h] [ebp-1Ch]
  float v; // [esp+1Ch] [ebp-18h]
  float bounding_volumeb; // [esp+38h] [ebp+4h]
  float bounding_volumea; // [esp+38h] [ebp+4h]
  float testeea; // [esp+3Ch] [ebp+8h]

  p_c = &this->m_bounding_volume->get_matrix(this->m_bounding_volume)->c;
  p_j = &this->m_bounding_volume->get_matrix(this->m_bounding_volume)->j;
  v6 = this->m_testee->get_matrix(this->m_testee);
  m_half_length = bounding_volume->m_half_length;
  v9 = p_c->x - (float)(p_j->x * m_half_length);
  bounding_volumeb = p_c->y;
  v10 = bounding_volumeb - (float)(p_j->y * m_half_length);
  z = p_c->z;
  v11 = z - (float)(p_j->z * m_half_length);
  v12 = bounding_volume->m_half_length;
  v13 = bounding_volumeb + (float)(p_j->y * v12);
  v = (float)(p_c->x + (float)(p_j->x * v12)) - v9;
  v14 = (float)(z + (float)(p_j->z * v12)) - v11;
  v20 = v6->c.z;
  bounding_volumea = v6->c.x;
  y = v6->c.y;
  v15 = v13 - v10;
  v16 = (float)((float)((float)((float)(v20 - v11) * v14) + (float)((float)(y - v10) * v15))
              + (float)((float)(bounding_volumea - v9) * v))
      / (float)((float)((float)(v14 * v14) + (float)(v15 * v15)) + (float)(v * v));
  v17 = 0.0;
  if ( v16 > 0.0 )
  {
    v17 = *(float *)&clear_value;
    if ( *(float *)&clear_value >= v16 )
      v17 = (float)((float)((float)((float)(v20 - v11) * v14) + (float)((float)(y - v10) * v15))
                  + (float)((float)(bounding_volumea - v9) * v))
          / (float)((float)((float)(v14 * v14) + (float)(v15 * v15)) + (float)(v * v));
  }
  testeea = sqrtf(
              (float)((float)(testee->m_matrix.i.y * testee->m_matrix.i.y)
                    + (float)(testee->m_matrix.i.z * testee->m_matrix.i.z))
            + (float)(testee->m_matrix.i.x * testee->m_matrix.i.x))
          + bounding_volume->m_radius;
  if ( (float)((float)((float)((float)((float)((float)(v17 * v) + v9) - bounding_volumea)
                             * (float)((float)((float)(v17 * v) + v9) - bounding_volumea))
                     + (float)((float)((float)((float)(v14 * v17) + v11) - v20)
                             * (float)((float)((float)(v14 * v17) + v11) - v20)))
             + (float)((float)((float)((float)(v15 * v17) + v10) - y) * (float)((float)((float)(v15 * v17) + v10) - y))) <= (float)(testeea * testeea) )
    this->m_result = 1;
}


void __thiscall vostok::collision::intersection_double_dispatcher::dispatch(
        vostok::collision::intersection_double_dispatcher *this,
        const vostok::collision::capsule_geometry_instance *bounding_volume,
        const vostok::collision::truncated_sphere_geometry_instance *testee)
{
  const vostok::collision::geometry_instance *m_testee; // eax

  m_testee = this->m_testee;
  this->m_testee = this->m_bounding_volume;
  this->m_bounding_volume = m_testee;
  this->dispatch(this, testee, bounding_volume);
}


void __thiscall vostok::collision::intersection_double_dispatcher::dispatch(
        vostok::collision::intersection_double_dispatcher *this,
        const vostok::collision::cylinder_geometry_instance *bounding_volume,
        const vostok::collision::cylinder_geometry_instance *testee)
{
  _BYTE v3[136]; // [esp-88h] [ebp-118h] BYREF
  _BYTE v4[136]; // [esp+0h] [ebp-90h] BYREF

  qmemcpy(v4, testee, sizeof(v4));
  qmemcpy(v3, bounding_volume, sizeof(v3));
  survarium::weapon_user_dead_state::finalize(0);
  JUMPOUT(0x6D5506);
}


void __thiscall vostok::collision::intersection_double_dispatcher::dispatch(
        vostok::collision::intersection_double_dispatcher *this,
        const vostok::collision::cylinder_geometry_instance *bounding_volume,
        const vostok::collision::box_geometry_instance *testee)
{
  _BYTE v3[136]; // [esp-88h] [ebp-118h] BYREF
  _BYTE v4[136]; // [esp+0h] [ebp-90h] BYREF

  qmemcpy(v4, testee, sizeof(v4));
  qmemcpy(v3, bounding_volume, sizeof(v3));
  survarium::weapon_user_dead_state::finalize(0);
  JUMPOUT(0x733366);
}


void __thiscall vostok::collision::intersection_double_dispatcher::dispatch(
        vostok::collision::intersection_double_dispatcher *this,
        const vostok::collision::cylinder_geometry_instance *bounding_volume,
        const vostok::collision::capsule_geometry_instance *testee)
{
  _BYTE v3[136]; // [esp-88h] [ebp-124h] BYREF
  _BYTE v4[148]; // [esp+0h] [ebp-9Ch] BYREF

  qmemcpy(v4, testee, sizeof(v4));
  qmemcpy(v3, bounding_volume, sizeof(v3));
  survarium::weapon_user_dead_state::finalize(0);
  JUMPOUT(0x6D5586);
}


void __thiscall vostok::collision::intersection_double_dispatcher::dispatch(
        vostok::collision::intersection_double_dispatcher *this,
        const vostok::collision::truncated_sphere_geometry_instance *bounding_volume,
        const vostok::collision::sphere_geometry_instance *testee)
{
  vostok::collision::intersection_double_dispatcher *v3; // ecx
  _BYTE v4[136]; // [esp-88h] [ebp-D8h] BYREF
  _BYTE v5[72]; // [esp+0h] [ebp-50h] BYREF

  qmemcpy(v5, testee, sizeof(v5));
  qmemcpy(v4, bounding_volume, sizeof(v4));
  survarium::weapon_user_dead_state::finalize(0);
  vostok::collision::intersection_double_dispatcher::dispatch(v3, bounding_volume, testee);
}


void __thiscall vostok::collision::intersection_double_dispatcher::dispatch(
        vostok::collision::intersection_double_dispatcher *this,
        const vostok::collision::cylinder_geometry_instance *bounding_volume,
        const vostok::collision::truncated_sphere_geometry_instance *testee)
{
  const vostok::collision::geometry_instance *m_testee; // eax

  m_testee = this->m_testee;
  this->m_testee = this->m_bounding_volume;
  this->m_bounding_volume = m_testee;
  this->dispatch(this, testee, bounding_volume);
}


void __thiscall vostok::collision::intersection_double_dispatcher::dispatch(
        vostok::collision::intersection_double_dispatcher *this,
        const vostok::collision::sphere_geometry_instance *bounding_volume,
        const vostok::collision::sphere_geometry_instance *testee)
{
  float v4; // xmm2_4
  float z; // xmm1_4
  float x; // xmm0_4
  long double v7; // st7
  float v8; // xmm0_4
  vostok::math::float4_pod *p_c; // esi
  const vostok::math::float4x4 *v10; // eax
  float v11; // xmm2_4
  float v12; // xmm1_4
  float y; // [esp+Ch] [ebp-4h]
  float bounding_volumea; // [esp+14h] [ebp+4h]
  float bounding_volumeb; // [esp+14h] [ebp+4h]
  float bounding_volumec; // [esp+14h] [ebp+4h]
  float testeea; // [esp+18h] [ebp+8h]

  y = bounding_volume->m_matrix.i.y;
  v4 = testee->m_matrix.i.y;
  z = testee->m_matrix.i.z;
  x = testee->m_matrix.i.x;
  testeea = bounding_volume->m_matrix.i.x;
  bounding_volumea = bounding_volume->m_matrix.i.z;
  v7 = sqrtf((float)((float)(v4 * v4) + (float)(z * z)) + (float)(x * x));
  v8 = bounding_volumea;
  bounding_volumeb = v7;
  bounding_volumec = sqrtf((float)((float)(v8 * v8) + (float)(testeea * testeea)) + (float)(y * y)) + bounding_volumeb;
  p_c = &this->m_bounding_volume->get_matrix(this->m_bounding_volume)->c;
  v10 = this->m_testee->get_matrix(this->m_testee);
  v11 = v10->c.z - p_c->z;
  v12 = v10->c.y - p_c->y;
  if ( (float)((float)((float)(v11 * v11) + (float)(v12 * v12))
             + (float)((float)(v10->c.x - p_c->x) * (float)(v10->c.x - p_c->x))) <= (float)(bounding_volumec
                                                                                          * bounding_volumec) )
    this->m_result = 1;
}


void __thiscall vostok::collision::intersection_double_dispatcher::dispatch(
        vostok::collision::intersection_double_dispatcher *this,
        const vostok::collision::sphere_geometry_instance *bounding_volume,
        const vostok::collision::box_geometry_instance *testee)
{
  const vostok::math::float3 *v4; // edi
  const vostok::math::float4x4 *v5; // esi
  const vostok::math::float4x4 *v6; // eax
  vostok::math::float3 box_half_sides; // [esp+10h] [ebp-18h] BYREF
  vostok::math::float3 closest_point; // [esp+1Ch] [ebp-Ch] BYREF
  float testeea; // [esp+30h] [ebp+8h]

  v4 = (const vostok::math::float3 *)&this->m_bounding_volume->get_matrix(this->m_bounding_volume)->lines[3];
  v5 = testee->get_matrix(testee);
  box_half_sides.x = sqrtf((float)((float)(v5->i.y * v5->i.y) + (float)(v5->i.z * v5->i.z)) + (float)(v5->i.x * v5->i.x));
  box_half_sides.y = sqrtf((float)((float)(v5->j.z * v5->j.z) + (float)(v5->j.x * v5->j.x)) + (float)(v5->j.y * v5->j.y));
  box_half_sides.z = sqrtf((float)((float)(v5->k.y * v5->k.y) + (float)(v5->k.z * v5->k.z)) + (float)(v5->k.x * v5->k.x));
  v6 = this->m_testee->get_matrix(this->m_testee);
  vostok::collision::closest_point_to_point(&closest_point, &box_half_sides, v4, v6);
  testeea = sqrtf(
              (float)((float)(bounding_volume->m_matrix.i.y * bounding_volume->m_matrix.i.y)
                    + (float)(bounding_volume->m_matrix.i.z * bounding_volume->m_matrix.i.z))
            + (float)(bounding_volume->m_matrix.i.x * bounding_volume->m_matrix.i.x));
  this->m_result = (float)(testeea * testeea) > (float)((float)((float)((float)(closest_point.z - v4->z)
                                                                      * (float)(closest_point.z - v4->z))
                                                              + (float)((float)(closest_point.y - v4->y)
                                                                      * (float)(closest_point.y - v4->y)))
                                                      + (float)((float)(closest_point.x - v4->x)
                                                              * (float)(closest_point.x - v4->x)));
}


void __thiscall vostok::collision::intersection_double_dispatcher::dispatch(
        vostok::collision::intersection_double_dispatcher *this,
        const vostok::collision::sphere_geometry_instance *bounding_volume,
        const vostok::collision::capsule_geometry_instance *testee)
{
  const vostok::collision::geometry_instance *m_testee; // eax

  m_testee = this->m_testee;
  this->m_testee = this->m_bounding_volume;
  this->m_bounding_volume = m_testee;
  this->dispatch(this, testee, bounding_volume);
}


void __thiscall vostok::collision::intersection_double_dispatcher::dispatch(
        vostok::collision::intersection_double_dispatcher *this,
        const vostok::collision::sphere_geometry_instance *bounding_volume,
        const vostok::collision::cylinder_geometry_instance *testee)
{
  const vostok::collision::geometry_instance *m_testee; // eax

  m_testee = this->m_testee;
  this->m_testee = this->m_bounding_volume;
  this->m_bounding_volume = m_testee;
  this->dispatch(this, testee, bounding_volume);
}


void __thiscall vostok::collision::intersection_double_dispatcher::dispatch(
        vostok::collision::intersection_double_dispatcher *this,
        const vostok::collision::sphere_geometry_instance *bounding_volume,
        const vostok::collision::truncated_sphere_geometry_instance *testee)
{
  const vostok::collision::geometry_instance *m_testee; // eax

  m_testee = this->m_testee;
  this->m_testee = this->m_bounding_volume;
  this->m_bounding_volume = m_testee;
  this->dispatch(this, testee, bounding_volume);
}


void __thiscall vostok::collision::intersection_double_dispatcher::dispatch(
        vostok::collision::intersection_double_dispatcher *this,
        const vostok::collision::truncated_sphere_geometry_instance *bounding_volume,
        const vostok::collision::truncated_sphere_geometry_instance *testee)
{
  _BYTE v3[148]; // [esp-94h] [ebp-130h] BYREF
  _BYTE v4[148]; // [esp+0h] [ebp-9Ch] BYREF

  qmemcpy(v4, testee, sizeof(v4));
  qmemcpy(v3, bounding_volume, sizeof(v3));
  survarium::weapon_user_dead_state::finalize(0);
  JUMPOUT(0x6D6336);
}


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


void __thiscall vostok::collision::intersection_double_dispatcher::dispatch(
        vostok::collision::intersection_double_dispatcher *this,
        const vostok::collision::truncated_sphere_geometry_instance *bounding_volume,
        const vostok::collision::capsule_geometry_instance *testee)
{
  vostok::math::float4_pod *p_c; // esi
  vostok::math::float4_pod *p_j; // edi
  const vostok::math::float4x4 *v6; // eax
  float m_half_length; // xmm3_4
  float v8; // xmm5_4
  float v9; // xmm6_4
  float v10; // xmm7_4
  float v11; // xmm0_4
  float v12; // xmm4_4
  float v13; // xmm3_4
  float v14; // xmm4_4
  float v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm4_4
  float v18; // xmm3_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm2_4
  const vostok::math::float4x4 *v22; // eax
  float v23; // xmm0_4
  vostok::math::float4 *m_begin; // edx
  unsigned int v25; // eax
  unsigned int v26; // ecx
  float y; // [esp+Ch] [ebp-34h]
  float v28; // [esp+Ch] [ebp-34h]
  float z; // [esp+10h] [ebp-30h]
  float x; // [esp+10h] [ebp-30h]
  float v31; // [esp+14h] [ebp-2Ch]
  float closest_point; // [esp+18h] [ebp-28h]
  float v; // [esp+24h] [ebp-1Ch]
  float v_4; // [esp+28h] [ebp-18h]
  float v_8; // [esp+2Ch] [ebp-14h]

  p_c = &this->m_testee->get_matrix(this->m_testee)->c;
  p_j = &this->m_testee->get_matrix(this->m_testee)->j;
  v6 = this->m_bounding_volume->get_matrix(this->m_bounding_volume);
  m_half_length = testee->m_half_length;
  v8 = p_c->x - (float)(p_j->x * m_half_length);
  y = p_c->y;
  v9 = y - (float)(p_j->y * m_half_length);
  z = p_c->z;
  v10 = z - (float)(p_j->z * m_half_length);
  v11 = y + (float)(p_j->y * m_half_length);
  v12 = z + (float)(p_j->z * m_half_length);
  v31 = v6->c.z;
  v28 = v6->c.y;
  v = (float)(p_c->x + (float)(p_j->x * m_half_length)) - v8;
  v13 = v11 - v9;
  x = v6->c.x;
  v14 = v12 - v10;
  v15 = (float)((float)((float)((float)(x - v8) * v) + (float)((float)(v31 - v10) * v14))
              + (float)((float)(v28 - v9) * v13))
      / (float)((float)((float)(v * v) + (float)(v14 * v14)) + (float)(v13 * v13));
  v16 = 0.0;
  if ( v15 > 0.0 )
  {
    v16 = *(float *)&clear_value;
    if ( *(float *)&clear_value >= v15 )
      v16 = (float)((float)((float)((float)(x - v8) * v) + (float)((float)(v31 - v10) * v14))
                  + (float)((float)(v28 - v9) * v13))
          / (float)((float)((float)(v * v) + (float)(v14 * v14)) + (float)(v13 * v13));
  }
  v17 = (float)(v14 * v16) + v10;
  v18 = v13 * v16;
  v19 = v16;
  v20 = bounding_volume->m_radius + testee->m_radius;
  closest_point = (float)(v19 * v) + v8;
  v21 = v18 + v9;
  if ( (float)((float)((float)((float)(closest_point - x) * (float)(closest_point - x))
                     + (float)((float)(v17 - v31) * (float)(v17 - v31)))
             + (float)((float)(v21 - v28) * (float)(v21 - v28))) <= (float)(v20 * v20) )
  {
    v22 = this->m_bounding_volume->get_matrix(this->m_bounding_volume);
    v23 = closest_point - v22->c.x;
    v22 = (const vostok::math::float4x4 *)((char *)v22 + 48);
    v_4 = v21 - v22->i.y;
    v_8 = v17 - v22->i.z;
    this->m_bounding_volume->get_matrix((vostok::collision::geometry_instance *)this->m_bounding_volume);
    m_begin = bounding_volume->m_planes.m_begin;
    v25 = bounding_volume->m_planes.m_end - m_begin;
    v26 = 0;
    if ( v25 )
    {
      while ( (float)((float)((float)(m_begin->x * v23) + (float)(m_begin->z * v_8)) + (float)(m_begin->y * v_4)) <= (float)((float)(bounding_volume->m_radius * m_begin->w) + testee->m_radius) )
      {
        ++v26;
        ++m_begin;
        if ( v26 >= v25 )
          goto LABEL_8;
      }
    }
    else
    {
LABEL_8:
      this->m_result = 1;
    }
  }
}


void __thiscall vostok::collision::intersection_double_dispatcher::dispatch(
        vostok::collision::intersection_double_dispatcher *this,
        const vostok::collision::truncated_sphere_geometry_instance *bounding_volume,
        const vostok::collision::cylinder_geometry_instance *testee)
{
  _BYTE v3[148]; // [esp-94h] [ebp-124h] BYREF
  _BYTE v4[136]; // [esp+0h] [ebp-90h] BYREF

  qmemcpy(v4, testee, sizeof(v4));
  qmemcpy(v3, bounding_volume, sizeof(v3));
  survarium::weapon_user_dead_state::finalize(0);
  JUMPOUT(0x6D5486);
}


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
