BOOL __thiscall survarium::base_game_scene::point_to_screen(
        survarium::base_game_scene *this,
        survarium::base_game_scene *p,
        const vostok::math::float3 *result,
        vostok::math::float2 *resulta)
{
  vostok::resources::unmanaged_resource *v4; // ebx
  unsigned int v5; // esi
  unsigned int v6; // edi
  float z; // xmm6_4
  float y; // xmm5_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm3_4
  float v12; // xmm0_4
  const vostok::math::float4x4 *v13; // xmm5_4
  float v14; // xmm4_4
  float v15; // xmm0_4
  double v16; // st6
  double v17; // st7
  double v18; // st6
  BOOL v19; // eax
  float v20; // [esp+10h] [ebp-98h]
  float v21; // [esp+18h] [ebp-90h]
  float pos_4; // [esp+20h] [ebp-88h]
  float vp; // [esp+28h] [ebp-80h]
  float vp_4; // [esp+2Ch] [ebp-7Ch]
  float vp_8; // [esp+30h] [ebp-78h]
  float vp_12; // [esp+34h] [ebp-74h]
  float vp_16; // [esp+38h] [ebp-70h]
  float vp_20; // [esp+3Ch] [ebp-6Ch]
  float vp_24; // [esp+40h] [ebp-68h]
  float vp_28; // [esp+44h] [ebp-64h]
  float vp_32; // [esp+48h] [ebp-60h]
  float vp_36; // [esp+4Ch] [ebp-5Ch]
  float vp_40; // [esp+50h] [ebp-58h]
  float vp_44; // [esp+54h] [ebp-54h]
  float vp_48; // [esp+58h] [ebp-50h]
  float vp_52; // [esp+5Ch] [ebp-4Ch]
  float vp_56; // [esp+60h] [ebp-48h]
  float vp_60; // [esp+64h] [ebp-44h]
  vostok::math::float4x4 view; // [esp+68h] [ebp-40h] BYREF

  v4 = survarium::base_game_scene::output_window_size(this, (int)p);
  v5 = (unsigned int)v4->__vftable >> 1;
  v6 = v4->type >> 1;
  vostok::math::float4x4::try_invert(&view, &p->m_inverted_view_matrix);
  vostok::math::mul4x4(&view, &p->m_projection_matrix);
  z = result->z;
  y = result->y;
  v9 = (float)((float)((float)(vp * result->x) + (float)(vp_32 * z)) + (float)(vp_16 * y)) + vp_48;
  v10 = (float)((float)((float)(vp_4 * result->x) + (float)(vp_36 * z)) + (float)(vp_20 * y)) + vp_52;
  v11 = (float)((float)((float)(vp_8 * result->x) + (float)(vp_40 * z)) + (float)(vp_24 * y)) + vp_56;
  v12 = vp_28 * y;
  v13 = clear_value;
  v14 = (float)((float)((float)(vp_12 * result->x) + (float)(vp_44 * z)) + v12) + vp_60;
  pos_4 = (float)(*(float *)&clear_value / v14) * v10;
  v15 = (float)(*(float *)&clear_value / v14) * v11;
  v16 = ((float)((float)(*(float *)&clear_value / v14) * v9) + 1.0) * (double)v5;
  v21 = v16;
  resulta->x = v16;
  v17 = v16;
  v18 = (1.0 - pos_4) * (double)v6;
  resulta->y = v18;
  v19 = 0;
  if ( *(float *)&v13 > v15 && v21 > 0.0 )
  {
    v20 = v18;
    if ( v20 > 0.0 && (double)(unsigned int)v4->__vftable > v17 && (double)v4->type > v18 )
      return 1;
  }
  return v19;
}
