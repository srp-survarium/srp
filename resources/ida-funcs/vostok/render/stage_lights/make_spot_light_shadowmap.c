void __userpurge vostok::render::stage_lights::make_spot_light_shadowmap(
        long double l@<esi:edi>,
        vostok::render::light *this,
        unsigned int shadow_quality)
{
  float v3; // xmm0_4
  float v4; // xmm4_4
  float v5; // xmm6_4
  float v6; // xmm1_4
  float v7; // xmm3_4
  float v8; // xmm2_4
  float v9; // xmm3_4
  float v10; // xmm6_4
  float v11; // xmm2_4
  float v12; // xmm3_4
  float v13; // xmm0_4
  float v14; // xmm4_4
  float v15; // xmm1_4
  float v16; // xmm0_4
  vostok::math::float4x4 view_matrix; // [esp+18h] [ebp-A4h] BYREF
  vostok::math::float4x4 projection_matrix; // [esp+58h] [ebp-64h] BYREF
  vostok::math::float3 v19; // [esp+9Ch] [ebp-20h] BYREF
  vostok::math::float3 v20; // [esp+A8h] [ebp-14h] BYREF
  float v21; // [esp+B4h] [ebp-8h]

  v3 = *(float *)(HIDWORD(l) + 544);
  if ( v3 <= *(float *)(HIDWORD(l) + 572) )
    v3 = *(float *)(HIDWORD(l) + 572);
  v21 = *(float *)(HIDWORD(l) + 608);
  vostok::math::create_perspective_projection(
    l,
    v3,
    (vostok::math *)&projection_matrix,
    COERCE_STRUCT_VOSTOK_MATH_FLOAT4X4_(1.0),
    v21 * 0.001,
    v21);
  v4 = *(float *)(HIDWORD(l) + 552);
  v5 = *(float *)(HIDWORD(l) + 556);
  v6 = (float)(*(float *)(HIDWORD(l) + 584) * v4) - (float)(*(float *)(HIDWORD(l) + 580) * v5);
  v7 = *(float *)(HIDWORD(l) + 576);
  v8 = v7 * v4;
  v9 = v7 * v5;
  v10 = *(float *)(HIDWORD(l) + 548);
  v11 = (float)(v10 * *(float *)(HIDWORD(l) + 580)) - v8;
  v12 = v9 - (float)(v10 * *(float *)(HIDWORD(l) + 584));
  v13 = s_bm_current_air_resistance / fsqrt((float)((float)(v11 * v11) + (float)(v12 * v12)) + (float)(v6 * v6));
  v14 = v13 * v6;
  v15 = v13;
  v19.z = v13 * v11;
  v20.x = *(float *)(HIDWORD(l) + 532) + *(float *)(HIDWORD(l) + 548);
  v20.y = *(float *)(HIDWORD(l) + 536) + *(float *)(HIDWORD(l) + 552);
  v16 = *(float *)(HIDWORD(l) + 540) + *(float *)(HIDWORD(l) + 556);
  v19.x = v14;
  v19.y = v15 * v12;
  v20.z = v16;
  vostok::math::create_camera_at((const vostok::math::float3 *)(HIDWORD(l) + 532), &v20, &view_matrix, &v19);
  vostok::render::stage_lights::render_to_hw_shadowmap(
    *(vostok::render::stage_lights **)(HIDWORD(l) + 900),
    this,
    HIDWORD(l),
    *(float *)(HIDWORD(l) + 848),
    (const vostok::math::float4x4 *)(1024 >> *(_DWORD *)(HIDWORD(l) + 900)),
    *(vostok::render::render_surface_instance ***)(HIDWORD(l) + 900),
    &view_matrix,
    &projection_matrix,
    0,
    LODWORD(view_matrix.i.x));
}
