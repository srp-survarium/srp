void __userpurge vostok::render::render_particle_emitter_instance::draw_debug(
        vostok::render::render_particle_emitter_instance *this@<ecx>,
        int a2@<eax>,
        float view_matrix,
        const vostok::math::float4x4 *debug_mode)
{
  float v5; // xmm5_4
  float v6; // xmm2_4
  float v7; // xmm3_4
  float v8; // xmm6_4
  float v9; // xmm7_4
  float v10; // xmm2_4
  float v11; // xmm3_4
  float v12; // xmm5_4
  float v13; // xmm4_4
  int v14; // ebx
  float v15; // eax
  vostok::render::system_renderer *v16; // ecx
  float v17; // xmm4_4
  float v18; // xmm2_4
  float v19; // xmm3_4
  float v20; // xmm4_4
  float v21; // xmm4_4
  float v22; // xmm1_4
  float v23; // xmm0_4
  float v24; // xmm0_4
  float v25; // xmm0_4
  float v26; // xmm4_4
  float v27; // xmm1_4
  float v28; // xmm4_4
  vostok::render::system_renderer *v29; // ecx
  int v30; // esi
  vostok::render::system_renderer *v31; // ecx
  BOOL v32; // [esp+Ch] [ebp-B8h]
  float v33; // [esp+Ch] [ebp-B8h]
  unsigned int v34; // [esp+10h] [ebp-B4h]
  unsigned int v35; // [esp+10h] [ebp-B4h]
  bool v36; // [esp+14h] [ebp-B0h]
  bool v37; // [esp+14h] [ebp-B0h]
  bool v38; // [esp+18h] [ebp-ACh]
  bool v39; // [esp+18h] [ebp-ACh]
  vostok::math::float4x4 v40; // [esp+1Ch] [ebp-A8h] BYREF
  float v41; // [esp+5Ch] [ebp-68h] BYREF
  float v42; // [esp+60h] [ebp-64h]
  float v43; // [esp+64h] [ebp-60h]
  float v44; // [esp+68h] [ebp-5Ch]
  float v45; // [esp+6Ch] [ebp-58h]
  float v46; // [esp+70h] [ebp-54h]
  float v47; // [esp+74h] [ebp-50h]
  float v48; // [esp+78h] [ebp-4Ch]
  float v49; // [esp+7Ch] [ebp-48h]
  float v50; // [esp+80h] [ebp-44h]
  float v51; // [esp+84h] [ebp-40h]
  float v52; // [esp+88h] [ebp-3Ch]
  float v53; // [esp+8Ch] [ebp-38h]
  float v54; // [esp+90h] [ebp-34h]
  float v55; // [esp+94h] [ebp-30h]
  float v56; // [esp+98h] [ebp-2Ch]
  float v57; // [esp+9Ch] [ebp-28h]
  float v58; // [esp+A0h] [ebp-24h]
  float v59; // [esp+A4h] [ebp-20h]
  float v60; // [esp+A8h] [ebp-1Ch]
  float v61; // [esp+ACh] [ebp-18h]
  float v62; // [esp+B0h] [ebp-14h]
  float v63; // [esp+B4h] [ebp-10h]
  float v64; // [esp+B8h] [ebp-Ch]
  float v65; // [esp+BCh] [ebp-8h]
  vostok::math::color v66; // [esp+C0h] [ebp-4h] BYREF

  vostok::math::float4x4::try_invert((const vostok::math::float4x4 *)LODWORD(view_matrix), &v40);
  v5 = (float)((float)(v40.j.x * 1000.0) + (float)(v40.i.x * 0.0)) + (float)(v40.k.x * 0.0);
  view_matrix = v40.k.x * 0.0;
  v59 = v40.k.y * 0.0;
  v6 = (float)((float)(v40.j.y * 1000.0) + (float)(v40.i.y * 0.0)) + (float)(v40.k.y * 0.0);
  v7 = (float)((float)(v40.j.z * 1000.0) + (float)(v40.i.z * 0.0)) + (float)(v40.k.z * 0.0);
  *(float *)&v66.m_value = v40.k.z * 0.0;
  v8 = s_bm_current_air_resistance / fsqrt((float)((float)(v5 * v5) + (float)(v7 * v7)) + (float)(v6 * v6));
  v62 = v7 * v8;
  v9 = v8 * v5;
  v61 = v6 * v8;
  v10 = (float)((float)(v40.j.x * 0.0) + (float)(v40.i.x * 1000.0)) + (float)(v40.k.x * 0.0);
  v11 = (float)((float)(v40.j.y * 0.0) + (float)(v40.i.y * 1000.0)) + (float)(v40.k.y * 0.0);
  v12 = (float)((float)(v40.j.z * 0.0) + (float)(v40.i.z * 1000.0)) + (float)(v40.k.z * 0.0);
  v60 = v9;
  v13 = s_bm_current_air_resistance / fsqrt((float)((float)(v10 * v10) + (float)(v12 * v12)) + (float)(v11 * v11));
  v63 = v13 * v10;
  v64 = v11 * v13;
  v65 = v12 * v13;
  if ( debug_mode == (const vostok::math::float4x4 *)1 )
  {
    v30 = *(_DWORD *)(*(_DWORD *)(a2 + 340) + 36);
    if ( v30 )
    {
      view_matrix = COERCE_FLOAT(vostok::math::color_rgba(0.0, COERCE_VOSTOK_MATH_(1.0), 1.0, 1.0));
      do
      {
        vostok::render::system_renderer::draw_3D_point(
          v31,
          vostok::quasi_singleton<vostok::render::system_renderer>::pinst,
          v30 + 44,
          (const vostok::math::color *)&view_matrix,
          v32);
        v30 = *(_DWORD *)(v30 + 208);
      }
      while ( v30 );
    }
  }
  else if ( debug_mode == (const vostok::math::float4x4 *)2 )
  {
    v14 = *(_DWORD *)(*(_DWORD *)(a2 + 340) + 36);
    if ( v14 )
    {
      v15 = COERCE_FLOAT(vostok::math::color_rgba(0.0, COERCE_VOSTOK_MATH_(1.0), 1.0, 1.0));
      view_matrix = v15;
      *(float *)&v66.m_value = v15;
      while ( 1 )
      {
        v17 = *(float *)(v14 + 116);
        v18 = v64 * v17;
        v19 = v65 * v17;
        v20 = *(float *)(v14 + 44) - (float)((float)(v63 * v17) * 0.5);
        v57 = *(float *)(v14 + 48) - (float)(v18 * 0.5);
        v58 = *(float *)(v14 + 52) - (float)(v19 * 0.5);
        v56 = v20;
        v21 = *(float *)(v14 + 116);
        v41 = v56;
        v42 = v57;
        v22 = (float)((float)(v63 * v21) * 0.5) + *(float *)(v14 + 44);
        v23 = *(float *)(v14 + 48);
        v43 = v58;
        v51 = v23 + (float)((float)(v64 * v21) * 0.5);
        v24 = *(float *)(v14 + 52);
        v50 = v22;
        v52 = v24 + (float)((float)(v65 * v21) * 0.5);
        v44 = v22;
        debug_mode = (const vostok::math::float4x4 *)LODWORD(v15);
        v45 = v51;
        v46 = v52;
        vostok::render::system_renderer::draw_screen_lines(
          v16,
          (unsigned int)vostok::quasi_singleton<vostok::render::system_renderer>::pinst,
          &v41,
          (const vostok::math::color *)&debug_mode,
          *(float *)&v32,
          v34,
          v36,
          v38);
        v25 = *(float *)(v14 + 120);
        v26 = *(float *)(v14 + 44) - (float)((float)(v60 * v25) * 0.5);
        v48 = *(float *)(v14 + 48) - (float)((float)(v61 * v25) * 0.5);
        v27 = *(float *)(v14 + 52);
        v47 = v26;
        v28 = *(float *)(v14 + 120);
        v49 = v27 - (float)((float)(v62 * v25) * 0.5);
        v41 = v47;
        v42 = v48;
        v43 = v49;
        v53 = *(float *)(v14 + 44) + (float)((float)(v60 * v28) * 0.5);
        v54 = *(float *)(v14 + 48) + (float)((float)(v61 * v28) * 0.5);
        v55 = *(float *)(v14 + 52) + (float)((float)(v62 * v28) * 0.5);
        v44 = v53;
        v45 = v54;
        v46 = v55;
        vostok::render::system_renderer::draw_screen_lines(
          v29,
          (unsigned int)vostok::quasi_singleton<vostok::render::system_renderer>::pinst,
          &v41,
          &v66,
          v33,
          v35,
          v37,
          v39);
        v14 = *(_DWORD *)(v14 + 208);
        if ( !v14 )
          break;
        v15 = view_matrix;
      }
    }
  }
}
