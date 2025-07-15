void __userpurge survarium::player::update_speed_info(
        survarium::player *this@<ecx>,
        vostok::math::float3 *a2@<edi>,
        vostok::math::axis_rotation_order a3@<esi>,
        int last_frame_angular_displacement)
{
  float v5; // xmm0_4
  float v6; // xmm1_4
  float v7; // xmm2_4
  float *v8; // esi
  float *v9; // ecx
  int v10; // edx
  float v11; // xmm1_4
  int v12; // esi
  vostok::math::float3 *angles; // eax
  float *v14; // esi
  float *v15; // ecx
  int v16; // edx
  float v17; // xmm0_4
  int v18; // esi
  float _X; // [esp+8h] [ebp-5Ch]
  char buffer[64]; // [esp+24h] [ebp-40h] BYREF
  float last_frame_angular_displacementa; // [esp+68h] [ebp+4h]

  v5 = *(float *)(last_frame_angular_displacement + 34720)
     - *(float *)((char *)&dword_10EC4 + last_frame_angular_displacement);
  v6 = *(float *)(last_frame_angular_displacement + 34724)
     - *(float *)((char *)&dword_10EC8 + last_frame_angular_displacement);
  v7 = *(float *)(last_frame_angular_displacement + 34728)
     - *(float *)((char *)&dword_10ECC + last_frame_angular_displacement);
  v8 = *(float **)((char *)&dword_10EF8 + last_frame_angular_displacement);
  *(_QWORD *)(last_frame_angular_displacement + 69316) = *(_QWORD *)(last_frame_angular_displacement + 34720);
  *(int *)((char *)&dword_10ECC + last_frame_angular_displacement) = *(_DWORD *)(last_frame_angular_displacement + 34728);
  if ( v8 )
  {
    _X = sqrtf((float)((float)(v6 * v6) + (float)(v7 * v7)) + (float)(v5 * v5));
    survarium::stats_graph::add_value(
      *(survarium::stats_graph **)((char *)&dword_10F04 + last_frame_angular_displacement),
      v8,
      *(float *)(*(int *)((char *)&dword_10F04 + last_frame_angular_displacement) + 1004),
      _X);
    v9 = *(float **)((char *)&dword_10EF8 + last_frame_angular_displacement);
    v10 = **(_DWORD **)v9;
    if ( fabs(*(float *)(*(_DWORD *)v9 + 8) - *(float *)(v10 + 8)) >= 0.0000099999997 )
      v11 = (float)(v9[6] - *(float *)(v10 + 12)) / (float)(*(float *)(*(_DWORD *)v9 + 8) - *(float *)(v10 + 8));
    else
      v11 = 0.0;
    v12 = *(_DWORD *)(*(int *)((char *)&dword_10F04 + last_frame_angular_displacement) + 116);
    vostok::sprintf<64>((char (*)[64])buffer, "linear speed: %3.2f", v11);
    (*(void (__thiscall **)(_DWORD, char *))(**(_DWORD **)(v12 + 32) + 8))(*(_DWORD *)(v12 + 32), buffer);
  }
  angles = vostok::math::float4x4::get_angles((vostok::math::float4x4 *)this, a2, a3);
  v14 = *(float **)((char *)&dword_10EFC + last_frame_angular_displacement);
  last_frame_angular_displacementa = fabs(angles->y - *(float *)((char *)&dword_10F10 + last_frame_angular_displacement));
  *(int *)((char *)&dword_10F10 + last_frame_angular_displacement) = LODWORD(angles->y);
  if ( v14 )
  {
    survarium::stats_graph::add_value(
      *(survarium::stats_graph **)((char *)&dword_10F04 + last_frame_angular_displacement),
      v14,
      *(float *)(*(int *)((char *)&dword_10F04 + last_frame_angular_displacement) + 1004),
      last_frame_angular_displacementa);
    v15 = *(float **)((char *)&dword_10EFC + last_frame_angular_displacement);
    v16 = **(_DWORD **)v15;
    if ( fabs(*(float *)(*(_DWORD *)v15 + 8) - *(float *)(v16 + 8)) >= 0.0000099999997 )
      v17 = (float)(v15[6] - *(float *)(v16 + 12)) / (float)(*(float *)(*(_DWORD *)v15 + 8) - *(float *)(v16 + 8));
    else
      v17 = 0.0;
    v18 = *(_DWORD *)(*(int *)((char *)&dword_10F04 + last_frame_angular_displacement) + 116);
    vostok::sprintf<64>((char (*)[64])buffer, "angular speed: %3.2f", (float)((float)(v17 * 0.31830987) * 180.0));
    (*(void (__thiscall **)(_DWORD, char *))(**(_DWORD **)(v18 + 36) + 8))(*(_DWORD *)(v18 + 36), buffer);
  }
}
