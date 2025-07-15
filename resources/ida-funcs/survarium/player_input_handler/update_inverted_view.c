void __thiscall survarium::player_input_handler::update_inverted_view(
        survarium::player_input_handler *this,
        const vostok::math::float4x4 *player_head_transform,
        float *a3)
{
  float *v3; // esi
  double y; // st7
  long double v5; // rdi
  vostok::math::float4x4 *v6; // eax
  double z; // st7
  vostok::math::float3 *v8; // edx
  vostok::math::float4x4 *rotation; // eax
  float v10; // xmm6_4
  float v11; // xmm2_4
  float w; // xmm3_4
  unsigned int v13; // xmm1_4
  float v14; // xmm0_4
  float *v15; // edx
  float v16; // [esp+0h] [ebp-E4h]
  float v17; // [esp+0h] [ebp-E4h]
  vostok::math::float4x4 v18; // [esp+14h] [ebp-D0h] BYREF
  vostok::math::float4x4 v19; // [esp+54h] [ebp-90h] BYREF
  vostok::math::float4x4 v20; // [esp+98h] [ebp-4Ch] BYREF
  float v21; // [esp+D8h] [ebp-Ch]
  unsigned int v22; // [esp+DCh] [ebp-8h]
  float v23; // [esp+E0h] [ebp-4h]
  int savedregs; // [esp+E4h] [ebp+0h] BYREF

  v3 = a3;
  if ( LODWORD(player_head_transform[13].k.x) )
  {
    y = player_head_transform[13].j.y;
    qmemcpy(&v19, a3, sizeof(v19));
    v21 = 0.0;
    v22 = 0;
    v23 = 0.0;
    memset(&v19.lines[3], 0, 12);
    v16 = y;
    HIDWORD(v5) = &savedregs;
    LODWORD(v5) = &v19.c.w;
    v6 = vostok::math::create_rotation_y(v5, (__m128i)0LL, &v18, v16);
    vostok::math::mul4x3(v6, &v19, &v20);
    z = player_head_transform[13].j.z;
    qmemcpy(v8, &v20, 0x40u);
    LODWORD(v5) = v8;
    v17 = z;
    rotation = vostok::math::create_rotation(v8, (int)&v18, (__m128i)0LL, v17);
    vostok::math::mul4x3(rotation, (const vostok::math::float4x4 *)LODWORD(v5), &v20);
    v10 = v20.i.z * 0.2;
    LODWORD(v11) = LODWORD(v20.k.z) ^ _mask__NegFloat_;
    w = player_head_transform[13].j.w;
    v21 = a3[12] + (float)(w * (float)(COERCE_FLOAT(LODWORD(v20.k.x) ^ _mask__NegFloat_) + (float)(v20.i.x * 0.2)));
    *(float *)&v13 = a3[13]
                   + (float)(w * (float)(COERCE_FLOAT(LODWORD(v20.k.y) ^ _mask__NegFloat_) + (float)(v20.i.y * 0.2)));
    v14 = a3[14];
    qmemcpy((void *)LODWORD(v5), &v20, 0x40u);
    v22 = v13;
    v23 = v14 + (float)(w * (float)(v11 + v10));
    *(_QWORD *)&v19.lines[3].x = __PAIR64__(v13, LODWORD(v21));
    v19.c.z = v23;
    v3 = v15;
  }
  qmemcpy(&player_head_transform[1].lines[0].elements[2], v3, sizeof(const vostok::math::float4x4));
  LOBYTE(player_head_transform[13].lines[2].elements[1]) = 0;
}
