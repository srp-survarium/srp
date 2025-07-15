void __cdecl btSoftBodyHelpers::DrawFrame(btSoftBody *psb, btIDebugDraw *idraw)
{
  float v2; // xmm3_4
  float v3; // xmm4_4
  float v4; // xmm0_4
  float v5; // xmm5_4
  float v6; // xmm7_4
  float v7; // xmm1_4
  float v8; // xmm6_4
  float v9; // xmm6_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm7_4
  float v13; // xmm6_4
  float v14; // xmm5_4
  float v15; // xmm7_4
  float v16; // xmm5_4
  float v17; // xmm6_4
  float v18; // xmm5_4
  float v19; // xmm6_4
  float v20; // xmm7_4
  float v21; // xmm0_4
  float v22; // xmm7_4
  float v23; // xmm6_4
  float v24; // xmm0_4
  float v25; // xmm3_4
  float v26; // xmm2_4
  float v27; // xmm3_4
  float v28; // xmm4_4
  float v29; // xmm5_4
  float v30; // xmm6_4
  float v31; // xmm4_4
  float v32; // xmm2_4
  float v33; // xmm5_4
  float v34; // xmm7_4
  float v35; // xmm5_4
  float v36; // xmm4_4
  float v37; // xmm7_4
  float v38; // xmm2_4
  float v39; // xmm5_4
  float v40; // xmm4_4
  float v41; // xmm3_4
  btIDebugDraw *v42; // edi
  btIDebugDraw_vtbl *v43; // eax
  btIDebugDraw_vtbl *v44; // eax
  btIDebugDraw_vtbl *v45; // eax
  bool v46; // cc
  float *v47; // eax
  float v48; // xmm4_4
  float v49; // xmm3_4
  unsigned int v50; // xmm1_4
  unsigned int v51; // xmm2_4
  const float *v52; // [esp+2Ch] [ebp-D0h]
  float v53; // [esp+3Ch] [ebp-C0h] BYREF
  float v54; // [esp+40h] [ebp-BCh]
  float v55; // [esp+44h] [ebp-B8h] BYREF
  float v56; // [esp+48h] [ebp-B4h] BYREF
  btVector3 v57; // [esp+4Ch] [ebp-B0h] BYREF
  btMatrix3x3 v58; // [esp+68h] [ebp-94h] BYREF
  int v59; // [esp+98h] [ebp-64h]
  float v60; // [esp+9Ch] [ebp-60h] BYREF
  float v61; // [esp+A0h] [ebp-5Ch] BYREF
  float v62; // [esp+A4h] [ebp-58h] BYREF
  float v63; // [esp+A8h] [ebp-54h] BYREF
  float v64; // [esp+ACh] [ebp-50h] BYREF
  float v65; // [esp+B0h] [ebp-4Ch]
  float v66; // [esp+B4h] [ebp-48h]
  float v67; // [esp+BCh] [ebp-40h]
  float v68; // [esp+C0h] [ebp-3Ch]
  float v69; // [esp+C4h] [ebp-38h]
  float v70; // [esp+CCh] [ebp-30h]
  float v71; // [esp+D0h] [ebp-2Ch]
  float v72; // [esp+D4h] [ebp-28h]
  float v73; // [esp+DCh] [ebp-20h]
  float v74; // [esp+E0h] [ebp-1Ch]
  float v75; // [esp+E4h] [ebp-18h]
  float v76; // [esp+ECh] [ebp-10h]
  float v77; // [esp+F0h] [ebp-Ch]
  float v78; // [esp+F4h] [ebp-8h]

  if ( psb->m_pose.m_bframe )
  {
    v2 = psb->m_pose.m_scl.m_el[2].mVec128.m128_f32[2];
    v3 = psb->m_pose.m_scl.m_el[1].mVec128.m128_f32[2];
    v4 = psb->m_pose.m_scl.m_el[0].mVec128.m128_f32[2];
    v5 = psb->m_pose.m_scl.m_el[1].mVec128.m128_f32[1];
    v6 = psb->m_pose.m_rot.m_el[2].mVec128.m128_f32[1];
    v7 = (float)((float)(v6 * v3) + (float)(psb->m_pose.m_rot.m_el[2].mVec128.m128_f32[2] * v2))
       + (float)(v4 * psb->m_pose.m_rot.m_el[2].mVec128.m128_f32[0]);
    v8 = psb->m_pose.m_rot.m_el[2].mVec128.m128_f32[2] * psb->m_pose.m_scl.m_el[2].mVec128.m128_f32[1];
    v54 = psb->m_pose.m_scl.m_el[2].mVec128.m128_f32[1];
    v9 = v8 + (float)(psb->m_pose.m_rot.m_el[2].mVec128.m128_f32[1] * v5);
    v53 = v5;
    v55 = psb->m_pose.m_scl.m_el[2].mVec128.m128_f32[0];
    v63 = v7;
    v10 = psb->m_pose.m_scl.m_el[0].mVec128.m128_f32[1];
    v11 = psb->m_pose.m_scl.m_el[0].mVec128.m128_f32[0];
    v61 = v9 + (float)(v10 * psb->m_pose.m_rot.m_el[2].mVec128.m128_f32[0]);
    v58.m_el[0].mVec128.m128_i32[0] = psb->m_pose.m_scl.m_el[1].mVec128.m128_i32[0];
    v12 = (float)((float)(v6 * v58.m_el[0].mVec128.m128_f32[0])
                + (float)(psb->m_pose.m_rot.m_el[2].mVec128.m128_f32[2] * v55))
        + (float)(v11 * psb->m_pose.m_rot.m_el[2].mVec128.m128_f32[0]);
    v13 = psb->m_pose.m_rot.m_el[1].mVec128.m128_f32[2] * v54;
    v58.m_el[2].mVec128.m128_f32[0] = (float)((float)(psb->m_pose.m_rot.m_el[1].mVec128.m128_f32[1] * v3)
                                            + (float)(psb->m_pose.m_rot.m_el[1].mVec128.m128_f32[2] * v2))
                                    + (float)(v4 * psb->m_pose.m_rot.m_el[1].mVec128.m128_f32[0]);
    v14 = (float)(psb->m_pose.m_rot.m_el[1].mVec128.m128_f32[1] * v5) + v13;
    v58.m_el[2].mVec128.m128_i32[1] = psb->m_pose.m_com.mVec128.m128_i32[0];
    v62 = v12;
    v15 = psb->m_pose.m_rot.m_el[1].mVec128.m128_f32[2];
    v16 = v14 + (float)(v10 * psb->m_pose.m_rot.m_el[1].mVec128.m128_f32[0]);
    v17 = psb->m_pose.m_rot.m_el[1].mVec128.m128_f32[1] * v58.m_el[0].mVec128.m128_f32[0];
    v58.m_el[2].mVec128.m128_i32[2] = psb->m_pose.m_com.mVec128.m128_i32[1];
    v60 = v16;
    v18 = v55;
    v19 = (float)(v17 + (float)(v15 * v55)) + (float)(v11 * psb->m_pose.m_rot.m_el[1].mVec128.m128_f32[0]);
    v20 = psb->m_pose.m_rot.m_el[0].mVec128.m128_f32[0];
    v58.m_el[2].mVec128.m128_i32[3] = psb->m_pose.m_com.mVec128.m128_i32[2];
    v21 = v4 * v20;
    v22 = psb->m_pose.m_rot.m_el[0].mVec128.m128_f32[1];
    v55 = v19;
    v23 = psb->m_pose.m_rot.m_el[0].mVec128.m128_f32[2];
    v59 = psb->m_pose.m_com.mVec128.m128_i32[3];
    v24 = (float)(v21 + (float)(v3 * v22)) + (float)(v2 * v23);
    v25 = psb->m_pose.m_rot.m_el[0].mVec128.m128_f32[0];
    v56 = v24;
    v53 = (float)((float)(v10 * v25) + (float)(v53 * v22)) + (float)(v54 * v23);
    v58.m_el[0].mVec128.m128_f32[0] = (float)((float)(v11 * v25) + (float)(v58.m_el[0].mVec128.m128_f32[0] * v22))
                                    + (float)(v18 * v23);
    btMatrix3x3::setValue(&v58, (int)&v64, &v53, &v56, &v55, &v60, v58.m_el[2].mVec128.m128_f32, &v62, &v61, &v63, v52);
    v62 = v65 * 0.0;
    v63 = v68 * 0.0;
    v26 = (float)(v67 + (float)(v68 * 0.0)) + (float)(v69 * 0.0);
    v27 = (float)(v70 + (float)(v71 * 0.0)) + (float)(v72 * 0.0);
    v60 = v72 * 0.0;
    v55 = v71 * 0.0;
    v28 = (float)(v64 + (float)(v65 * 0.0)) + (float)(v66 * 0.0);
    v29 = s_bm_current_air_resistance / fsqrt((float)((float)(v28 * v28) + (float)(v27 * v27)) + (float)(v26 * v26));
    v30 = v29 * v28;
    v57.mVec128.m128_f32[1] = v26 * v29;
    v57.mVec128.m128_f32[2] = v27 * v29;
    v58.m_el[2].mVec128.m128_f32[0] = v64 * 0.0;
    v31 = (float)(v68 + (float)(v67 * 0.0)) + (float)(v69 * 0.0);
    v32 = (float)(v65 + (float)(v64 * 0.0)) + (float)(v66 * 0.0);
    v61 = v67 * 0.0;
    v33 = (float)(v71 + (float)(v70 * 0.0)) + (float)(v72 * 0.0);
    v56 = v70 * 0.0;
    v34 = fsqrt((float)((float)(v32 * v32) + (float)(v33 * v33)) + (float)(v31 * v31));
    v35 = v33 * (float)(s_bm_current_air_resistance / v34);
    v36 = v31 * (float)(s_bm_current_air_resistance / v34);
    v37 = (float)(s_bm_current_air_resistance / v34) * v32;
    v38 = (float)(v66 + (float)(v64 * 0.0)) + (float)(v65 * 0.0);
    v73 = v37;
    v75 = v35;
    v39 = (float)(v72 + (float)(v70 * 0.0)) + (float)(v71 * 0.0);
    v74 = v36;
    v40 = (float)(v69 + (float)(v67 * 0.0)) + (float)(v68 * 0.0);
    v41 = s_bm_current_air_resistance / fsqrt((float)((float)(v38 * v38) + (float)(v39 * v39)) + (float)(v40 * v40));
    *(unsigned __int64 *)((char *)v58.m_el[0].mVec128.m128_u64 + 4) = LODWORD(s_bm_current_air_resistance);
    v57.mVec128.m128_f32[1] = v58.m_el[2].mVec128.m128_f32[2] + (float)(v57.mVec128.m128_f32[1] * 10.0);
    v76 = v41 * v38;
    v77 = v40 * v41;
    v78 = v39 * v41;
    v58.m_el[0].mVec128.m128_i32[3] = 0;
    v58.m_el[1].mVec128.m128_i32[0] = 0;
    v57.mVec128.m128_f32[0] = (float)(v30 * 10.0) + v58.m_el[2].mVec128.m128_f32[1];
    v42 = idraw;
    v43 = idraw->__vftable;
    v57.mVec128.m128_f32[2] = v58.m_el[2].mVec128.m128_f32[3] + (float)(v57.mVec128.m128_f32[2] * 10.0);
    v57.mVec128.m128_i32[3] = 0;
    v43->drawLine(idraw, (const btVector3 *)&v58.m_el[2].m_floats[1], &v57, (const btVector3 *)&v58.m_el[0].m_floats[1]);
    v44 = idraw->__vftable;
    *(unsigned __int64 *)((char *)v57.mVec128.m128_u64 + 4) = LODWORD(s_bm_current_air_resistance);
    v57.mVec128.m128_i32[0] = 0;
    v57.mVec128.m128_i32[3] = 0;
    v58.m_el[0].mVec128.m128_f32[1] = (float)(v73 * 10.0) + v58.m_el[2].mVec128.m128_f32[1];
    v58.m_el[0].mVec128.m128_f32[2] = (float)(v74 * 10.0) + v58.m_el[2].mVec128.m128_f32[2];
    v58.m_el[0].mVec128.m128_f32[3] = (float)(v75 * 10.0) + v58.m_el[2].mVec128.m128_f32[3];
    v58.m_el[1].mVec128.m128_i32[0] = 0;
    v44->drawLine(idraw, (const btVector3 *)&v58.m_el[2].m_floats[1], (const btVector3 *)&v58.m_el[0].m_floats[1], &v57);
    v45 = idraw->__vftable;
    v57.mVec128.m128_u64[1] = LODWORD(s_bm_current_air_resistance);
    v57.mVec128.m128_u64[0] = 0;
    v58.m_el[0].mVec128.m128_f32[1] = (float)(v76 * 10.0) + v58.m_el[2].mVec128.m128_f32[1];
    v58.m_el[0].mVec128.m128_f32[2] = (float)(v77 * 10.0) + v58.m_el[2].mVec128.m128_f32[2];
    v58.m_el[0].mVec128.m128_f32[3] = (float)(v78 * 10.0) + v58.m_el[2].mVec128.m128_f32[3];
    v58.m_el[1].mVec128.m128_i32[0] = 0;
    v45->drawLine(idraw, (const btVector3 *)&v58.m_el[2].m_floats[1], (const btVector3 *)&v58.m_el[0].m_floats[1], &v57);
    v46 = psb->m_pose.m_pos.m_size <= 0;
    v53 = 0.0;
    if ( !v46 )
    {
      v58.m_el[1].mVec128.m128_i32[0] = 0;
      v54 = 0.0;
      while ( 1 )
      {
        v47 = (float *)((char *)psb->m_pose.m_pos.m_data->mVec128.m128_f32 + LODWORD(v54));
        v48 = v47[1];
        v49 = v47[2];
        *(float *)&v50 = (float)((float)((float)(v67 * *v47) + (float)(v68 * v48)) + (float)(v69 * v49))
                       + v58.m_el[2].mVec128.m128_f32[2];
        *(float *)&v51 = (float)((float)((float)(v70 * *v47) + (float)(v71 * v48)) + (float)(v72 * v49))
                       + v58.m_el[2].mVec128.m128_f32[3];
        v58.m_el[0].mVec128.m128_f32[1] = (float)((float)((float)(v64 * *v47) + (float)(v65 * v48)) + (float)(v66 * v49))
                                        + v58.m_el[2].mVec128.m128_f32[1];
        v58.m_el[0].mVec128.m128_u64[1] = __PAIR64__(v51, v50);
        v57.mVec128.m128_u64[0] = LODWORD(s_bm_current_air_resistance);
        v57.mVec128.m128_u64[1] = LODWORD(s_bm_current_air_resistance);
        drawVertex(v42, (const btVector3 *)&v58.m_el[0].m_floats[1], 0.1, &v57);
        ++LODWORD(v53);
        LODWORD(v54) += 16;
        if ( SLODWORD(v53) >= psb->m_pose.m_pos.m_size )
          break;
        v42 = idraw;
      }
    }
  }
}
