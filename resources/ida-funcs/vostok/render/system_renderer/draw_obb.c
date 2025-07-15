void __thiscall vostok::render::system_renderer::draw_obb(
        vostok::render::system_renderer *this,
        vostok::render::system_renderer *transform,
        const vostok::math::color *color,
        int *a4)
{
  vostok::render::system_renderer *v5; // ecx
  float v6; // xmm6_4
  float v7; // xmm3_4
  float v8; // xmm4_4
  float v9; // xmm2_4
  float v10; // xmm5_4
  float v11; // xmm3_4
  float v12; // xmm4_4
  float v13; // xmm2_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm2_4
  float v17; // xmm1_4
  int v18; // eax
  float v19; // xmm0_4
  float v20; // xmm7_4
  float v21; // xmm0_4
  float v22; // xmm7_4
  float v23; // xmm0_4
  float v24; // xmm0_4
  float v25; // xmm7_4
  float v26; // xmm0_4
  float v27; // xmm0_4
  float v28; // xmm7_4
  float v29; // xmm5_4
  float v30; // xmm7_4
  float v31; // xmm3_4
  float v32; // xmm7_4
  float v33; // xmm5_4
  float v34; // xmm5_4
  float v35; // xmm0_4
  _DWORD v36[32]; // [esp+10h] [ebp-C4h] BYREF
  vostok::render::vertex_colored v37; // [esp+90h] [ebp-44h] BYREF
  float v38; // [esp+A0h] [ebp-34h]
  float v39; // [esp+A4h] [ebp-30h]
  float v40; // [esp+A8h] [ebp-2Ch]
  float v41; // [esp+ACh] [ebp-28h]
  float v42; // [esp+B0h] [ebp-24h]
  float v43; // [esp+B4h] [ebp-20h]
  float v44; // [esp+B8h] [ebp-1Ch]
  float v45; // [esp+BCh] [ebp-18h]
  float v46; // [esp+C0h] [ebp-14h]
  float v47; // [esp+C4h] [ebp-10h]
  float v48; // [esp+C8h] [ebp-Ch]
  float v49; // [esp+CCh] [ebp-8h]
  float v50; // [esp+E0h] [ebp+Ch]
  float v51; // [esp+E4h] [ebp+10h]

  if ( vostok::render::system_renderer::is_effects_ready(this, transform) )
  {
    v6 = *(float *)&color[12].m_value;
    v7 = *(float *)&color[1].m_value;
    v8 = *(float *)&color[5].m_value;
    v9 = *(float *)&color[8].m_value * -1.0;
    v10 = *(float *)&color->m_value * -1.0;
    v45 = *(float *)&color[4].m_value * -1.0;
    v11 = v7 * -1.0;
    v12 = v8 * -1.0;
    v46 = v9;
    v13 = v9 + v45;
    v47 = (float)(v10 + v13) + v6;
    v14 = *(float *)&color[9].m_value * -1.0;
    v43 = v13;
    v15 = *(float *)&color[6].m_value;
    v48 = (float)((float)(v11 + v14) + v12) + *(float *)&color[13].m_value;
    v16 = v15 * -1.0;
    v41 = *(float *)&color[10].m_value * -1.0;
    v44 = v14;
    v17 = *(float *)&color[2].m_value * -1.0;
    v18 = *a4;
    v19 = *(float *)&color[8].m_value;
    v49 = (float)((float)(v17 + v41) + v16) + *(float *)&color[14].m_value;
    *(float *)v36 = v47;
    *(float *)&v36[1] = v48;
    v37.position.z = v19;
    *(float *)&v36[2] = v49;
    *(float *)&v37.color.m_value = v19 + v45;
    v47 = (float)((float)(v19 + v45) + v10) + v6;
    v20 = (float)(*(float *)&color[9].m_value + v11) + v12;
    v42 = *(float *)&color[9].m_value;
    v21 = *(float *)&color[10].m_value;
    v48 = v20 + *(float *)&color[13].m_value;
    v22 = v21 + v17;
    v45 = v21;
    v23 = *(float *)&color[14].m_value;
    v36[3] = v18;
    v49 = (float)(v22 + v16) + v23;
    *(float *)&v36[4] = v47;
    v39 = v16;
    v37.position.y = v17;
    *(float *)&v36[5] = v48;
    v24 = *(float *)&color[4].m_value;
    v25 = *(float *)&color[13].m_value;
    *(float *)&v36[6] = v49;
    v40 = v24;
    v38 = v24 + v46;
    v47 = (float)((float)(v24 + v46) + v10) + v6;
    v51 = *(float *)&color[5].m_value;
    v48 = (float)((float)(v51 + v11) + v44) + v25;
    v46 = *(float *)&color[6].m_value;
    v26 = *(float *)&color->m_value;
    v49 = (float)((float)(v46 + v17) + v41) + *(float *)&color[14].m_value;
    v36[7] = v18;
    *(float *)&v36[8] = v47;
    *(float *)&v36[9] = v48;
    *(float *)&v36[10] = v49;
    v50 = v26;
    v47 = (float)(v26 + v43) + v6;
    v43 = *(float *)&color[1].m_value;
    v27 = v43 + v44;
    v48 = (float)((float)(v43 + v44) + v12) + v25;
    v44 = *(float *)&color[2].m_value;
    v36[11] = v18;
    v49 = (float)((float)(v44 + v41) + v16) + *(float *)&color[14].m_value;
    *(float *)&v36[12] = v47;
    *(float *)&v36[13] = v48;
    *(float *)&v36[14] = v49;
    v28 = (float)(v40 + v37.position.z) + v10;
    v29 = *(float *)&color[13].m_value;
    v47 = v28 + v6;
    v30 = (float)(v51 + v42) + v11;
    v31 = *(float *)&color[14].m_value;
    v48 = v30 + v29;
    v36[15] = v18;
    v49 = (float)((float)(v46 + v45) + v17) + v31;
    *(float *)&v36[16] = v47;
    *(float *)&v36[17] = v30 + v29;
    *(float *)&v36[18] = v49;
    v36[19] = v18;
    v47 = (float)(v50 + *(float *)&v37.color.m_value) + v6;
    v32 = (float)((float)(v43 + v42) + v12) + v29;
    v33 = *(float *)&color[14].m_value;
    v48 = v32;
    v49 = (float)((float)(v44 + v45) + v16) + v33;
    *(float *)&v36[20] = v47;
    *(float *)&v36[21] = v32;
    *(float *)&v36[22] = v49;
    v47 = (float)(v50 + v38) + v6;
    v34 = *(float *)&color[13].m_value;
    v36[23] = v18;
    v48 = (float)(v27 + v51) + v34;
    v35 = *(float *)&color[14].m_value;
    *(float *)&v36[24] = v47;
    *(float *)&v36[25] = v48;
    *(float *)&v36[26] = (float)((float)(v44 + v41) + v46) + v35;
    v36[27] = v18;
    v47 = (float)((float)(v40 + v37.position.z) + v50) + v6;
    v48 = (float)((float)(v43 + v42) + v51) + v34;
    v49 = (float)((float)(v44 + v45) + v46) + v35;
    *(float *)&v36[28] = v47;
    *(float *)&v36[29] = v48;
    *(float *)&v36[30] = v49;
    v36[31] = v18;
    vostok::render::system_renderer::draw_lines(
      &v37,
      v5,
      transform,
      (unsigned int)v36,
      (unsigned __int8 *)vostok::render::aabb_indices,
      (char *)&bad_alloc_Message_180,
      0);
  }
}
