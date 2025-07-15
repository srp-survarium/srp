void __usercall btSoftBodyHelpers::DrawFrame(btIDebugDraw *idraw@<eax>, btSoftBody *psb)
{
  float v3; // xmm1_4
  float v4; // xmm5_4
  float v5; // xmm4_4
  float v6; // xmm3_4
  float v7; // xmm2_4
  float v8; // xmm4_4
  float v9; // xmm2_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm4_4
  float v13; // xmm2_4
  float v14; // xmm5_4
  float v15; // xmm7_4
  float v16; // xmm0_4
  float v17; // xmm0_4
  float v18; // xmm6_4
  float v19; // xmm7_4
  btIDebugDraw_vtbl *v20; // eax
  void (__thiscall *drawLine)(btIDebugDraw *, const btVector3 *, const btVector3 *, const btVector3 *); // edx
  btIDebugDraw_vtbl *v22; // eax
  void (__thiscall *v23)(btIDebugDraw *, const btVector3 *, const btVector3 *, const btVector3 *); // edx
  btIDebugDraw_vtbl *v24; // eax
  btVector3 *v25; // eax
  unsigned int v26; // xmm1_4
  float v27; // xmm6_4
  unsigned int v28; // xmm2_4
  float v29; // [esp+2ACh] [ebp-B4h]
  int v30; // [esp+2ACh] [ebp-B4h]
  float v31; // [esp+2B0h] [ebp-B0h]
  float v32; // [esp+2B0h] [ebp-B0h]
  int v33; // [esp+2B0h] [ebp-B0h]
  float v34; // [esp+2B4h] [ebp-ACh]
  float v35; // [esp+2B4h] [ebp-ACh]
  float v36; // [esp+2B8h] [ebp-A8h]
  float v37; // [esp+2BCh] [ebp-A4h]
  float v38; // [esp+2BCh] [ebp-A4h]
  float v39; // [esp+2C0h] [ebp-A0h]
  float v40; // [esp+2C4h] [ebp-9Ch]
  float v41; // [esp+2C8h] [ebp-98h]
  float v42; // [esp+2C8h] [ebp-98h]
  float v43; // [esp+2CCh] [ebp-94h]
  float v44; // [esp+2D0h] [ebp-90h] BYREF
  float v45; // [esp+2D4h] [ebp-8Ch]
  float v46; // [esp+2D8h] [ebp-88h]
  int v47; // [esp+2DCh] [ebp-84h]
  btVector3 v48; // [esp+2E0h] [ebp-80h] BYREF
  unsigned __int64 v49; // [esp+2F0h] [ebp-70h] BYREF
  unsigned __int64 v50; // [esp+2F8h] [ebp-68h]
  float v51; // [esp+30Ch] [ebp-54h]
  float v52; // [esp+310h] [ebp-50h] BYREF
  float v53; // [esp+314h] [ebp-4Ch]
  float v54; // [esp+318h] [ebp-48h]
  int v55; // [esp+31Ch] [ebp-44h]
  float v56; // [esp+32Ch] [ebp-34h]
  btVector3 c; // [esp+330h] [ebp-30h] BYREF
  float v58; // [esp+34Ch] [ebp-14h]
  float v59; // [esp+350h] [ebp-10h]
  float v60; // [esp+354h] [ebp-Ch]
  float v61; // [esp+358h] [ebp-8h]
  float v62; // [esp+35Ch] [ebp-4h]

  if ( psb->m_pose.m_bframe )
  {
    v3 = psb->m_pose.m_scl.m_el[2].mVec128.m128_f32[2];
    v4 = psb->m_pose.m_scl.m_el[1].mVec128.m128_f32[1];
    v5 = psb->m_pose.m_rot.m_el[2].mVec128.m128_f32[2];
    v29 = psb->m_pose.m_scl.m_el[1].mVec128.m128_f32[2];
    v37 = psb->m_pose.m_scl.m_el[2].mVec128.m128_f32[0];
    v31 = psb->m_pose.m_scl.m_el[1].mVec128.m128_f32[0];
    v6 = (float)(psb->m_pose.m_rot.m_el[2].mVec128.m128_f32[1] * v29) + (float)(v5 * v3);
    v7 = psb->m_pose.m_scl.m_el[2].mVec128.m128_f32[1];
    v49 = psb->m_pose.m_com.mVec128.m128_u64[0];
    v8 = v5 * v7;
    v41 = v7;
    v9 = psb->m_pose.m_rot.m_el[2].mVec128.m128_f32[1] * v4;
    v34 = v3;
    v50 = psb->m_pose.m_com.mVec128.m128_u64[1];
    v10 = psb->m_pose.m_scl.m_el[0].mVec128.m128_f32[2];
    v36 = v4;
    v11 = psb->m_pose.m_scl.m_el[0].mVec128.m128_f32[1];
    v12 = (float)(v8 + v9) + (float)(v11 * psb->m_pose.m_rot.m_el[2].mVec128.m128_f32[0]);
    v13 = psb->m_pose.m_scl.m_el[0].mVec128.m128_f32[0];
    v14 = (float)((float)(psb->m_pose.m_rot.m_el[2].mVec128.m128_f32[1] * v31)
                + (float)(psb->m_pose.m_rot.m_el[2].mVec128.m128_f32[2] * v37))
        + (float)(v13 * psb->m_pose.m_rot.m_el[2].mVec128.m128_f32[0]);
    v43 = (float)((float)(psb->m_pose.m_rot.m_el[1].mVec128.m128_f32[1] * v29)
                + (float)(psb->m_pose.m_rot.m_el[1].mVec128.m128_f32[2] * v34))
        + (float)(v10 * psb->m_pose.m_rot.m_el[1].mVec128.m128_f32[0]);
    v40 = (float)((float)(psb->m_pose.m_rot.m_el[1].mVec128.m128_f32[1] * v36)
                + (float)(psb->m_pose.m_rot.m_el[1].mVec128.m128_f32[2] * v41))
        + (float)(v11 * psb->m_pose.m_rot.m_el[1].mVec128.m128_f32[0]);
    v15 = psb->m_pose.m_rot.m_el[0].mVec128.m128_f32[1];
    v39 = (float)((float)(psb->m_pose.m_rot.m_el[1].mVec128.m128_f32[1] * v31)
                + (float)(psb->m_pose.m_rot.m_el[1].mVec128.m128_f32[2] * v37))
        + (float)(v13 * psb->m_pose.m_rot.m_el[1].mVec128.m128_f32[0]);
    v16 = v10 * psb->m_pose.m_rot.m_el[0].mVec128.m128_f32[0];
    v60 = v6 + (float)(psb->m_pose.m_scl.m_el[0].mVec128.m128_f32[2] * psb->m_pose.m_rot.m_el[2].mVec128.m128_f32[0]);
    v58 = v12;
    v59 = v14;
    v17 = v16 + (float)(v29 * v15);
    v18 = psb->m_pose.m_rot.m_el[0].mVec128.m128_f32[2];
    v19 = psb->m_pose.m_rot.m_el[0].mVec128.m128_f32[1];
    v35 = v17 + (float)(v34 * v18);
    v42 = (float)((float)(v11 * psb->m_pose.m_rot.m_el[0].mVec128.m128_f32[0]) + (float)(v36 * v19))
        + (float)(v41 * v18);
    v38 = (float)((float)(v13 * psb->m_pose.m_rot.m_el[0].mVec128.m128_f32[0]) + (float)(v31 * v19))
        + (float)(v37 * v18);
    v62 = v42 * 0.0;
    v51 = v60 * 0.0;
    v44 = (float)((float)(v35 * 0.0) + (float)(v42 * 0.0)) + v38;
    v61 = v40 * 0.0;
    v45 = (float)((float)(v43 * 0.0) + (float)(v40 * 0.0)) + v39;
    v56 = v12 * 0.0;
    v46 = (float)((float)(v60 * 0.0) + (float)(v12 * 0.0)) + v14;
    v32 = 1.0
        / sqrtf(
            (float)((float)(v44 * v44)
                  + (float)((float)((float)((float)(v60 * 0.0) + v56) + v14)
                          * (float)((float)((float)(v60 * 0.0) + v56) + v14)))
          + (float)(v45 * v45));
    v52 = v44 * v32;
    v53 = v45 * v32;
    v54 = v46 * v32;
    v44 = (float)((float)(v38 * 0.0) + (float)(v35 * 0.0)) + v42;
    v45 = (float)((float)(v39 * 0.0) + (float)(v43 * 0.0)) + v40;
    v46 = (float)((float)(v14 * 0.0) + (float)(v60 * 0.0)) + v12;
    v51 = 1.0
        / sqrtf(
            (float)((float)(v44 * v44)
                  + (float)((float)((float)((float)(v59 * 0.0) + v51) + v58)
                          * (float)((float)((float)(v59 * 0.0) + v51) + v58)))
          + (float)(v45 * v45));
    v48.mVec128.m128_f32[0] = v44 * v51;
    v48.mVec128.m128_f32[1] = v45 * v51;
    v48.mVec128.m128_f32[2] = v46 * v51;
    v44 = (float)((float)(v38 * 0.0) + (float)(v42 * 0.0)) + v35;
    v45 = (float)((float)(v39 * 0.0) + (float)(v40 * 0.0)) + v43;
    v46 = (float)((float)(v14 * 0.0) + (float)(v12 * 0.0)) + v60;
    v56 = 1.0 / sqrtf((float)((float)(v44 * v44) + (float)(v46 * v46)) + (float)(v45 * v45));
    c.mVec128.m128_f32[0] = v44 * v56;
    c.mVec128.m128_f32[1] = v45 * v56;
    c.mVec128.m128_f32[2] = v46 * v56;
    v44 = *(float *)&clear_value;
    v45 = 0.0;
    v46 = 0.0;
    v47 = 0;
    v20 = idraw->__vftable;
    v52 = (float)(v52 * 10.0) + *(float *)&v49;
    drawLine = v20->drawLine;
    v53 = *((float *)&v49 + 1) + (float)(v53 * 10.0);
    v54 = *(float *)&v50 + (float)(v54 * 10.0);
    v55 = 0;
    drawLine(idraw, (const btVector3 *)&v49, (const btVector3 *)&v52, (const btVector3 *)&v44);
    v22 = idraw->__vftable;
    v53 = *(float *)&clear_value;
    v23 = v22->drawLine;
    v52 = 0.0;
    v54 = 0.0;
    v55 = 0;
    v48.mVec128.m128_f32[0] = (float)(v48.mVec128.m128_f32[0] * 10.0) + *(float *)&v49;
    v48.mVec128.m128_f32[1] = (float)(v48.mVec128.m128_f32[1] * 10.0) + *((float *)&v49 + 1);
    v48.mVec128.m128_f32[2] = (float)(v48.mVec128.m128_f32[2] * 10.0) + *(float *)&v50;
    v48.mVec128.m128_i32[3] = 0;
    v23(idraw, (const btVector3 *)&v49, &v48, (const btVector3 *)&v52);
    v24 = idraw->__vftable;
    v48.mVec128.m128_u64[1] = (unsigned int)clear_value;
    v48.mVec128.m128_u64[0] = 0;
    c.mVec128.m128_f32[0] = (float)(c.mVec128.m128_f32[0] * 10.0) + *(float *)&v49;
    c.mVec128.m128_f32[1] = (float)(c.mVec128.m128_f32[1] * 10.0) + *((float *)&v49 + 1);
    c.mVec128.m128_f32[2] = (float)(c.mVec128.m128_f32[2] * 10.0) + *(float *)&v50;
    c.mVec128.m128_i32[3] = 0;
    v24->drawLine(idraw, (const btVector3 *)&v49, &c, &v48);
    v33 = 0;
    if ( psb->m_pose.m_pos.m_size > 0 )
    {
      v48.mVec128.m128_i32[3] = 0;
      v30 = 0;
      do
      {
        v25 = &psb->m_pose.m_pos.m_data[v30];
        *(float *)&v26 = (float)((float)((float)(v25->mVec128.m128_f32[0] * v38)
                                       + (float)(v25->mVec128.m128_f32[1] * v42))
                               + (float)(v25->mVec128.m128_f32[2] * v35))
                       + *(float *)&v49;
        v27 = v25->mVec128.m128_f32[2];
        *(float *)&v28 = (float)((float)((float)(v25->mVec128.m128_f32[0] * v39)
                                       + (float)(v25->mVec128.m128_f32[1] * v40))
                               + (float)(v27 * v43))
                       + *((float *)&v49 + 1);
        v48.mVec128.m128_f32[2] = (float)((float)((float)(v25->mVec128.m128_f32[0] * v59)
                                                + (float)(v25->mVec128.m128_f32[1] * v58))
                                        + (float)(v27 * v60))
                                + *(float *)&v50;
        v48.mVec128.m128_u64[0] = __PAIR64__(v28, v26);
        c.mVec128.m128_u64[0] = (unsigned int)clear_value;
        c.mVec128.m128_u64[1] = (unsigned int)clear_value;
        drawVertex(idraw, &v48, 0.1, &c);
        ++v30;
        ++v33;
      }
      while ( v33 < psb->m_pose.m_pos.m_size );
    }
  }
}
