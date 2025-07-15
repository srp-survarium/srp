double __userpurge vostok::animation::anm_track::evaluate@<st0>(
        vostok::animation::anm_track *this@<ecx>,
        _DWORD *a2@<eax>,
        float id,
        float channel_position,
        const float a5)
{
  return vostok::animation::engineAnimEvaluate((vostok::animation::EtCurve *)*(_DWORD *)(*a2 + 4 * (_DWORD)this), id);
}


void __userpurge vostok::animation::anm_track::evaluate(
        vostok::animation::anm_track *this@<ecx>,
        _DWORD *a2@<eax>,
        int a3@<edi>,
        vostok::math::float4x4 *pose,
        float on_track_position)
{
  float v6; // xmm0_4
  bool v7; // cc
  float v8; // xmm0_4
  float v9; // xmm0_4
  float v10; // xmm0_4
  float v11; // xmm0_4
  float v12; // xmm0_4
  float v13; // xmm0_4
  float v14; // xmm0_4
  float v15; // xmm0_4
  vostok::math::float4x4 *v16; // ebx
  vostok::math::float4x4 *v17; // eax
  float v18; // [esp+4h] [ebp-F8h]
  float v19; // [esp+8h] [ebp-F4h]
  vostok::math::float4x4 v20; // [esp+14h] [ebp-E8h] BYREF
  _BYTE v21[64]; // [esp+54h] [ebp-A8h] BYREF
  vostok::math::float4x4 v22; // [esp+94h] [ebp-68h] BYREF
  vostok::math::float3 v23; // [esp+D4h] [ebp-28h] BYREF
  vostok::math::float3 v24; // [esp+E0h] [ebp-1Ch] BYREF
  __int64 v25; // [esp+ECh] [ebp-10h]
  float v26; // [esp+F4h] [ebp-8h]
  float v27; // [esp+F8h] [ebp-4h]
  float v28; // [esp+108h] [ebp+Ch]

  if ( (int)a2[4] <= 0 )
  {
    v6 = 0.0;
  }
  else
  {
    v27 = vostok::animation::anm_track::evaluate(0, a2, on_track_position, v18, v19);
    v6 = v27;
  }
  v7 = a2[4] <= 1;
  *(float *)&v25 = v6;
  if ( v7 )
  {
    v8 = 0.0;
  }
  else
  {
    v27 = vostok::animation::anm_track::evaluate((vostok::animation::anm_track *)1, a2, on_track_position, v18, v19);
    v8 = v27;
  }
  v7 = a2[4] <= 2;
  *((float *)&v25 + 1) = v8;
  if ( v7 )
  {
    v9 = 0.0;
  }
  else
  {
    v27 = vostok::animation::anm_track::evaluate((vostok::animation::anm_track *)2, a2, on_track_position, v18, v19);
    v9 = v27;
  }
  v7 = a2[4] <= 3;
  v26 = v9;
  if ( v7 )
  {
    v10 = 0.0;
  }
  else
  {
    v27 = vostok::animation::anm_track::evaluate((vostok::animation::anm_track *)3, a2, on_track_position, v18, v19);
    v10 = v27;
  }
  v7 = a2[4] <= 4;
  v23.x = v10;
  if ( v7 )
  {
    v11 = 0.0;
  }
  else
  {
    v27 = vostok::animation::anm_track::evaluate((vostok::animation::anm_track *)4, a2, on_track_position, v18, v19);
    v11 = v27;
  }
  v7 = a2[4] <= 5;
  v23.y = v11;
  if ( v7 )
  {
    v12 = 0.0;
  }
  else
  {
    v27 = vostok::animation::anm_track::evaluate((vostok::animation::anm_track *)5, a2, on_track_position, v18, v19);
    v12 = v27;
  }
  v7 = a2[4] <= 6;
  v23.z = v12;
  if ( v7 )
  {
    v13 = s_bm_current_air_resistance;
  }
  else
  {
    v27 = vostok::animation::anm_track::evaluate((vostok::animation::anm_track *)6, a2, on_track_position, v18, v19);
    v13 = v27;
  }
  v7 = a2[4] <= 7;
  v24.x = v13;
  if ( v7 )
  {
    v14 = s_bm_current_air_resistance;
  }
  else
  {
    v27 = vostok::animation::anm_track::evaluate((vostok::animation::anm_track *)7, a2, on_track_position, v18, v19);
    v14 = v27;
  }
  v7 = a2[4] <= 8;
  v24.y = v14;
  if ( v7 )
  {
    v15 = s_bm_current_air_resistance;
  }
  else
  {
    v28 = vostok::animation::anm_track::evaluate((vostok::animation::anm_track *)8, a2, on_track_position, v18, v19);
    v15 = v28;
  }
  v24.z = v15;
  v16 = vostok::math::create_rotation(&v23, a3, (int)v21);
  v17 = vostok::math::create_scale(&v24, &v20);
  vostok::math::mul4x3(v16, v17, &v22);
  qmemcpy(pose, &v22, sizeof(vostok::math::float4x4));
  *(_QWORD *)&pose->lines[3].x = v25;
  pose->c.z = v26;
}
