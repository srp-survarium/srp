void __thiscall btCollisionWorld::debugDrawObject(
        btCollisionWorld *this,
        const btTransform *worldTransform,
        btVector3 *shape,
        const btVector3 *color)
{
  btCollisionWorld_vtbl *v5; // eax
  btIDebugDraw *v6; // eax
  btVector3 *v7; // esi
  btMatrix3x3 *v8; // ecx
  int v9; // eax
  int v10; // eax
  int v11; // eax
  float v12; // xmm0_4
  float v13; // xmm2_4
  float v14; // xmm1_4
  float v15; // eax
  float v16; // xmm5_4
  float v17; // xmm3_4
  float v18; // xmm4_4
  float v19; // xmm5_4
  float v20; // xmm4_4
  float v21; // xmm3_4
  float v22; // xmm4_4
  float v23; // xmm3_4
  float v24; // xmm4_4
  float v25; // xmm3_4
  float v26; // xmm4_4
  float v27; // xmm3_4
  float v28; // xmm4_4
  btCollisionWorld_vtbl *v29; // eax
  int v30; // eax
  int v31; // eax
  int v32; // eax
  int v33; // eax
  int v34; // eax
  int v35; // eax
  btCollisionWorld_vtbl *v36; // eax
  int v37; // eax
  btBoxShape *v38; // ecx
  float v39; // esi
  double v40; // st7
  btCollisionWorld_vtbl *v41; // eax
  int v42; // eax
  btCollisionWorld_vtbl *v43; // eax
  int v44; // esi
  int v45; // eax
  btCollisionWorld_vtbl *v46; // eax
  int v47; // eax
  int v48; // eax
  int v49; // eax
  int v50; // esi
  btCollisionWorld_vtbl *v51; // eax
  int v52; // eax
  float v53; // xmm0_4
  float v54; // xmm2_4
  float v55; // xmm1_4
  float v56; // xmm5_4
  float v57; // xmm3_4
  float v58; // xmm4_4
  float v59; // xmm5_4
  float v60; // xmm4_4
  float v61; // xmm3_4
  float v62; // xmm4_4
  float v63; // xmm3_4
  float v64; // xmm4_4
  float v65; // xmm3_4
  float v66; // xmm4_4
  float v67; // xmm3_4
  float v68; // xmm4_4
  int v69; // edx
  btIDebugDraw *v70; // eax
  btIDebugDraw *v71; // eax
  const float *v72; // [esp+20h] [ebp-130h]
  float v73; // [esp+30h] [ebp-120h] BYREF
  int v74; // [esp+34h] [ebp-11Ch]
  btMatrix3x3 v75; // [esp+38h] [ebp-118h] BYREF
  float v76; // [esp+68h] [ebp-E8h]
  int v77; // [esp+6Ch] [ebp-E4h]
  float v78; // [esp+70h] [ebp-E0h]
  float v79; // [esp+74h] [ebp-DCh]
  float v80; // [esp+78h] [ebp-D8h]
  int v81; // [esp+7Ch] [ebp-D4h]
  float v82; // [esp+80h] [ebp-D0h] BYREF
  btMatrix3x3 v83; // [esp+84h] [ebp-CCh] BYREF
  btCollisionWorld *v84; // [esp+BCh] [ebp-94h]
  _DWORD v85[4]; // [esp+C0h] [ebp-90h] BYREF
  int v86; // [esp+D0h] [ebp-80h] BYREF
  int v87; // [esp+D4h] [ebp-7Ch]
  int v88; // [esp+D8h] [ebp-78h]
  int v89; // [esp+DCh] [ebp-74h]
  int v90; // [esp+E0h] [ebp-70h]
  int v91; // [esp+E4h] [ebp-6Ch]
  int v92; // [esp+E8h] [ebp-68h]
  int v93; // [esp+ECh] [ebp-64h]
  int v94; // [esp+F0h] [ebp-60h]
  int v95; // [esp+F4h] [ebp-5Ch]
  int v96; // [esp+F8h] [ebp-58h]
  int v97; // [esp+FCh] [ebp-54h]
  int v98; // [esp+100h] [ebp-50h] BYREF
  int v99; // [esp+104h] [ebp-4Ch]
  int v100; // [esp+108h] [ebp-48h]
  int v101; // [esp+10Ch] [ebp-44h]
  int v102; // [esp+110h] [ebp-40h]
  int v103; // [esp+114h] [ebp-3Ch]
  int v104; // [esp+118h] [ebp-38h]
  int v105; // [esp+11Ch] [ebp-34h]
  int v106; // [esp+120h] [ebp-30h]
  int v107; // [esp+124h] [ebp-2Ch]
  int v108; // [esp+128h] [ebp-28h]
  int v109; // [esp+12Ch] [ebp-24h]
  int v110; // [esp+130h] [ebp-20h]
  unsigned __int64 v111; // [esp+134h] [ebp-1Ch]
  int v112; // [esp+13Ch] [ebp-14h]
  btVector3 v113; // [esp+140h] [ebp-10h] BYREF

  v5 = this->__vftable;
  v84 = this;
  if ( ((int (__fastcall *)(btCollisionWorld *))v5->getDebugDrawer)(this) )
  {
    v6 = this->getDebugDrawer(this);
    v7 = shape;
    if ( !v6->debugDrawObject(v6, worldTransform, (const btCollisionShape *)shape, color) )
    {
      if ( shape->mVec128.m128_i32[1] == 31 )
      {
        v9 = shape[1].mVec128.m128_i32[0] - 1;
        v74 = v9;
        if ( v9 >= 0 )
        {
          v10 = 80 * v9;
          v83.m_el[2].mVec128.m128_i32[2] = 0;
          v75.m_el[0].mVec128.m128_i32[1] = v10;
          while ( 1 )
          {
            v11 = v7[1].mVec128.m128_i32[2] + v10;
            v75.m_el[0].mVec128.m128_u64[1] = *(_QWORD *)v11;
            v75.m_el[1] = *(btVector3 *)(v11 + 8);
            v75.m_el[2] = *(btVector3 *)(v11 + 24);
            v76 = *(float *)(v11 + 40);
            v77 = *(_DWORD *)(v11 + 44);
            v12 = worldTransform->m_basis.m_el[0].mVec128.m128_f32[1];
            v13 = worldTransform->m_basis.m_el[0].mVec128.m128_f32[0];
            v14 = worldTransform->m_basis.m_el[0].mVec128.m128_f32[2];
            v78 = *(float *)(v11 + 48);
            v79 = *(float *)(v11 + 52);
            v80 = *(float *)(v11 + 56);
            v81 = *(_DWORD *)(v11 + 60);
            v15 = *(float *)(v11 + 64);
            v16 = worldTransform->m_basis.m_el[1].mVec128.m128_f32[2] * v80;
            v83.m_el[1].mVec128.m128_f32[3] = (float)((float)((float)(v13 * v78) + (float)(v12 * v79))
                                                    + (float)(v14 * v80))
                                            + worldTransform->m_origin.mVec128.m128_f32[0];
            v17 = v78 * worldTransform->m_basis.m_el[2].mVec128.m128_f32[0];
            v18 = (float)((float)((float)(worldTransform->m_basis.m_el[1].mVec128.m128_f32[1] * v79) + v16)
                        + (float)(v78 * worldTransform->m_basis.m_el[1].mVec128.m128_f32[0]))
                + worldTransform->m_origin.mVec128.m128_f32[1];
            v19 = worldTransform->m_basis.m_el[2].mVec128.m128_f32[2] * v80;
            v83.m_el[2].mVec128.m128_f32[0] = v18;
            v20 = (float)((float)((float)(worldTransform->m_basis.m_el[2].mVec128.m128_f32[1] * v79) + v19) + v17)
                + worldTransform->m_origin.mVec128.m128_f32[2];
            v21 = worldTransform->m_basis.m_el[2].mVec128.m128_f32[1] * v75.m_el[2].mVec128.m128_f32[0];
            v83.m_el[2].mVec128.m128_f32[1] = v20;
            v22 = worldTransform->m_basis.m_el[2].mVec128.m128_f32[2] * v75.m_el[2].mVec128.m128_f32[3];
            v83.m_el[0].mVec128.m128_f32[2] = (float)(v21
                                                    + (float)(worldTransform->m_basis.m_el[2].mVec128.m128_f32[2] * v76))
                                            + (float)(worldTransform->m_basis.m_el[2].mVec128.m128_f32[0]
                                                    * v75.m_el[1].mVec128.m128_f32[0]);
            v83.m_el[0].mVec128.m128_f32[0] = (float)((float)(worldTransform->m_basis.m_el[2].mVec128.m128_f32[1]
                                                            * v75.m_el[1].mVec128.m128_f32[3])
                                                    + v22)
                                            + (float)(worldTransform->m_basis.m_el[2].mVec128.m128_f32[0]
                                                    * v75.m_el[0].mVec128.m128_f32[3]);
            v23 = worldTransform->m_basis.m_el[2].mVec128.m128_f32[1] * v75.m_el[1].mVec128.m128_f32[2];
            v73 = v15;
            v24 = worldTransform->m_basis.m_el[1].mVec128.m128_f32[2] * v76;
            v83.m_el[0].mVec128.m128_f32[3] = (float)(v23
                                                    + (float)(worldTransform->m_basis.m_el[2].mVec128.m128_f32[2]
                                                            * v75.m_el[2].mVec128.m128_f32[2]))
                                            + (float)(worldTransform->m_basis.m_el[2].mVec128.m128_f32[0]
                                                    * v75.m_el[0].mVec128.m128_f32[2]);
            v25 = (float)((float)(worldTransform->m_basis.m_el[1].mVec128.m128_f32[1] * v75.m_el[2].mVec128.m128_f32[0])
                        + v24)
                + (float)(v75.m_el[1].mVec128.m128_f32[0] * worldTransform->m_basis.m_el[1].mVec128.m128_f32[0]);
            v26 = worldTransform->m_basis.m_el[1].mVec128.m128_f32[2] * v75.m_el[2].mVec128.m128_f32[3];
            v83.m_el[0].mVec128.m128_f32[1] = v25;
            v27 = (float)((float)(worldTransform->m_basis.m_el[1].mVec128.m128_f32[1] * v75.m_el[1].mVec128.m128_f32[3])
                        + v26)
                + (float)(v75.m_el[0].mVec128.m128_f32[3] * worldTransform->m_basis.m_el[1].mVec128.m128_f32[0]);
            v28 = worldTransform->m_basis.m_el[1].mVec128.m128_f32[2] * v75.m_el[2].mVec128.m128_f32[2];
            v83.m_el[1].mVec128.m128_f32[0] = v27;
            v83.m_el[1].mVec128.m128_f32[2] = (float)((float)(worldTransform->m_basis.m_el[1].mVec128.m128_f32[1]
                                                            * v75.m_el[1].mVec128.m128_f32[2])
                                                    + v28)
                                            + (float)(worldTransform->m_basis.m_el[1].mVec128.m128_f32[0]
                                                    * v75.m_el[0].mVec128.m128_f32[2]);
            v82 = (float)((float)(v12 * v75.m_el[2].mVec128.m128_f32[0]) + (float)(v14 * v76))
                + (float)(v13 * v75.m_el[1].mVec128.m128_f32[0]);
            v83.m_el[1].mVec128.m128_f32[1] = (float)((float)(v12 * v75.m_el[1].mVec128.m128_f32[3])
                                                    + (float)(v14 * v75.m_el[2].mVec128.m128_f32[3]))
                                            + (float)(v13 * v75.m_el[0].mVec128.m128_f32[3]);
            v75.m_el[0].mVec128.m128_f32[0] = (float)((float)(v12 * v75.m_el[1].mVec128.m128_f32[2])
                                                    + (float)(v14 * v75.m_el[2].mVec128.m128_f32[2]))
                                            + (float)(v13 * v75.m_el[0].mVec128.m128_f32[2]);
            btMatrix3x3::setValue(
              &v75,
              (int)&v86,
              &v83.m_el[1].mVec128.m128_f32[1],
              &v82,
              &v83.m_el[1].mVec128.m128_f32[2],
              v83.m_el[1].mVec128.m128_f32,
              &v83.m_el[0].mVec128.m128_f32[1],
              &v83.m_el[0].mVec128.m128_f32[3],
              (float *)&v83,
              &v83.m_el[0].mVec128.m128_f32[2],
              v72);
            v98 = v86;
            v99 = v87;
            v100 = v88;
            v101 = v89;
            v102 = v90;
            v103 = v91;
            v104 = v92;
            v105 = v93;
            v106 = v94;
            v107 = v95;
            v29 = v84->__vftable;
            v108 = v96;
            v109 = v97;
            v110 = v83.m_el[1].mVec128.m128_i32[3];
            v111 = v83.m_el[2].mVec128.m128_u64[0];
            v112 = v83.m_el[2].mVec128.m128_i32[2];
            ((void (__thiscall *)(btCollisionWorld *, int *, float, const btVector3 *))v29->debugDrawObject)(
              v84,
              &v98,
              COERCE_FLOAT(LODWORD(v73)),
              color);
            --v74;
            v75.m_el[0].mVec128.m128_i32[1] -= 80;
            if ( v74 < 0 )
              break;
            v10 = v75.m_el[0].mVec128.m128_i32[1];
            v7 = shape;
          }
        }
      }
      else
      {
        if ( (_S1_8 & 1) == 0 )
        {
          _S1_8 |= 1u;
          prim_color.mVec128.m128_f32[0] = s_aim_transition_time;
          *(unsigned __int64 *)((char *)prim_color.mVec128.m128_u64 + 4) = LODWORD(s_aim_transition_time);
          prim_color.mVec128.m128_i32[3] = 0;
        }
        v30 = shape->mVec128.m128_i32[1];
        if ( v30 )
        {
          v31 = v30 - 8;
          if ( v31 )
          {
            v32 = v31 - 1;
            if ( v32 )
            {
              v33 = v32 - 1;
              if ( v33 )
              {
                v34 = v33 - 1;
                if ( v34 )
                {
                  v35 = v34 - 2;
                  if ( v35 )
                  {
                    if ( v35 == 15 )
                    {
                      v36 = this->__vftable;
                      v73 = shape[4].mVec128.m128_f32[0];
                      v37 = (int)v36->getDebugDrawer(this);
                      (*(void (__thiscall **)(int, btVector3 *, float, const btTransform *, const btVector3 *))(*(_DWORD *)v37 + 88))(
                        v37,
                        shape + 3,
                        COERCE_FLOAT(LODWORD(v73)),
                        worldTransform,
                        color);
                    }
                  }
                  else
                  {
                    v73 = shape[4].mVec128.m128_f32[0];
                    v75.m_el[0].mVec128.m128_f32[0] = ((double (__thiscall *)(btVector3 *))*(_DWORD *)(shape->mVec128.m128_i32[0] + 84))(shape);
                    v39 = v73;
                    v40 = btBoxShape::getHalfExtentsWithMargin(v38, shape, &v113)->mVec128.m128_f32[LODWORD(v73)];
                    v41 = this->__vftable;
                    v73 = v40;
                    v42 = (int)v41->getDebugDrawer(this);
                    (*(void (__thiscall **)(int, int, float, float, const btTransform *, const btVector3 *))(*(_DWORD *)v42 + 80))(
                      v42,
                      v75.m_el[0].mVec128.m128_i32[0],
                      COERCE_FLOAT(LODWORD(v73)),
                      COERCE_FLOAT(LODWORD(v39)),
                      worldTransform,
                      color);
                  }
                }
                else
                {
                  v43 = this->__vftable;
                  v75.m_el[0].mVec128.m128_f32[0] = shape[4].mVec128.m128_f32[1];
                  v44 = shape[5].mVec128.m128_i32[0];
                  v73 = shape[4].mVec128.m128_f32[2];
                  v45 = (int)v43->getDebugDrawer(this);
                  (*(void (__thiscall **)(int, int, float, int, const btTransform *, const btVector3 *))(*(_DWORD *)v45 + 84))(
                    v45,
                    v75.m_el[0].mVec128.m128_i32[0],
                    COERCE_FLOAT(LODWORD(v73)),
                    v44,
                    worldTransform,
                    color);
                }
              }
              else
              {
                v74 = shape[4].mVec128.m128_i32[0];
                v75.m_el[0].mVec128.m128_f32[0] = shape[2].mVec128.m128_f32[(v74 + 2) % 3];
                v46 = this->__vftable;
                v73 = shape[2].mVec128.m128_f32[v74];
                v47 = (int)v46->getDebugDrawer(this);
                (*(void (__thiscall **)(int, int, float, int, const btTransform *, const btVector3 *))(*(_DWORD *)v47 + 76))(
                  v47,
                  v75.m_el[0].mVec128.m128_i32[0],
                  COERCE_FLOAT(LODWORD(v73)),
                  v74,
                  worldTransform,
                  color);
              }
            }
            else
            {
              btMatrix3x3::setIdentity(v8, (int)&v75.m_el[0].mVec128.m128_i32[2]);
              v48 = shape[7].mVec128.m128_i32[1] - 1;
              v75.m_el[0].mVec128.m128_i32[1] = v48;
              if ( v48 >= 0 )
              {
                v49 = 16 * v48;
                v83.m_el[2].mVec128.m128_i32[2] = 0;
                v74 = v49;
                while ( 1 )
                {
                  v50 = v49 + v7[7].mVec128.m128_i32[3];
                  v51 = v84->__vftable;
                  v78 = *(float *)v50;
                  v50 += 4;
                  v79 = *(float *)v50;
                  v50 += 4;
                  v80 = *(float *)v50;
                  v81 = *(_DWORD *)(v50 + 4);
                  v52 = (int)v51->getDebugDrawer(v84);
                  v53 = worldTransform->m_basis.m_el[0].mVec128.m128_f32[1];
                  v54 = worldTransform->m_basis.m_el[0].mVec128.m128_f32[0];
                  v55 = worldTransform->m_basis.m_el[0].mVec128.m128_f32[2];
                  v56 = worldTransform->m_basis.m_el[1].mVec128.m128_f32[1] * v79;
                  v83.m_el[1].mVec128.m128_f32[3] = (float)((float)((float)(worldTransform->m_basis.m_el[0].mVec128.m128_f32[0]
                                                                          * v78)
                                                                  + (float)(v53 * v79))
                                                          + (float)(v55 * v80))
                                                  + worldTransform->m_origin.mVec128.m128_f32[0];
                  v57 = v78 * worldTransform->m_basis.m_el[2].mVec128.m128_f32[0];
                  v58 = (float)((float)((float)(worldTransform->m_basis.m_el[1].mVec128.m128_f32[2] * v80) + v56)
                              + (float)(v78 * worldTransform->m_basis.m_el[1].mVec128.m128_f32[0]))
                      + worldTransform->m_origin.mVec128.m128_f32[1];
                  v59 = worldTransform->m_basis.m_el[2].mVec128.m128_f32[1] * v79;
                  v83.m_el[2].mVec128.m128_f32[0] = v58;
                  v60 = (float)((float)((float)(worldTransform->m_basis.m_el[2].mVec128.m128_f32[2] * v80) + v59) + v57)
                      + worldTransform->m_origin.mVec128.m128_f32[2];
                  v61 = worldTransform->m_basis.m_el[2].mVec128.m128_f32[1] * v75.m_el[2].mVec128.m128_f32[0];
                  v83.m_el[2].mVec128.m128_f32[1] = v60;
                  v62 = worldTransform->m_basis.m_el[2].mVec128.m128_f32[2] * v75.m_el[2].mVec128.m128_f32[3];
                  v73 = (float)(v61 + (float)(worldTransform->m_basis.m_el[2].mVec128.m128_f32[2] * v76))
                      + (float)(worldTransform->m_basis.m_el[2].mVec128.m128_f32[0] * v75.m_el[1].mVec128.m128_f32[0]);
                  v63 = (float)((float)(worldTransform->m_basis.m_el[2].mVec128.m128_f32[1]
                                      * v75.m_el[1].mVec128.m128_f32[3])
                              + v62)
                      + (float)(worldTransform->m_basis.m_el[2].mVec128.m128_f32[0] * v75.m_el[0].mVec128.m128_f32[3]);
                  v64 = worldTransform->m_basis.m_el[2].mVec128.m128_f32[2] * v75.m_el[2].mVec128.m128_f32[2];
                  v75.m_el[0].mVec128.m128_f32[0] = v63;
                  v65 = (float)((float)(worldTransform->m_basis.m_el[2].mVec128.m128_f32[1]
                                      * v75.m_el[1].mVec128.m128_f32[2])
                              + v64)
                      + (float)(v75.m_el[0].mVec128.m128_f32[2] * worldTransform->m_basis.m_el[2].mVec128.m128_f32[0]);
                  v66 = worldTransform->m_basis.m_el[1].mVec128.m128_f32[2] * v76;
                  v83.m_el[1].mVec128.m128_f32[1] = v65;
                  v82 = (float)((float)(worldTransform->m_basis.m_el[1].mVec128.m128_f32[1]
                                      * v75.m_el[2].mVec128.m128_f32[0])
                              + v66)
                      + (float)(v75.m_el[1].mVec128.m128_f32[0] * worldTransform->m_basis.m_el[1].mVec128.m128_f32[0]);
                  v67 = worldTransform->m_basis.m_el[1].mVec128.m128_f32[1];
                  v83.m_el[0].mVec128.m128_i32[2] = v52;
                  v68 = worldTransform->m_basis.m_el[1].mVec128.m128_f32[2] * v75.m_el[2].mVec128.m128_f32[2];
                  v83.m_el[1].mVec128.m128_f32[2] = (float)((float)(v67 * v75.m_el[1].mVec128.m128_f32[3])
                                                          + (float)(worldTransform->m_basis.m_el[1].mVec128.m128_f32[2]
                                                                  * v75.m_el[2].mVec128.m128_f32[3]))
                                                  + (float)(v75.m_el[0].mVec128.m128_f32[3]
                                                          * worldTransform->m_basis.m_el[1].mVec128.m128_f32[0]);
                  v83.m_el[1].mVec128.m128_f32[0] = (float)((float)(worldTransform->m_basis.m_el[1].mVec128.m128_f32[1]
                                                                  * v75.m_el[1].mVec128.m128_f32[2])
                                                          + v68)
                                                  + (float)(worldTransform->m_basis.m_el[1].mVec128.m128_f32[0]
                                                          * v75.m_el[0].mVec128.m128_f32[2]);
                  v83.m_el[0].mVec128.m128_f32[1] = (float)((float)(v53 * v75.m_el[2].mVec128.m128_f32[0])
                                                          + (float)(v55 * v76))
                                                  + (float)(v54 * v75.m_el[1].mVec128.m128_f32[0]);
                  v83.m_el[0].mVec128.m128_f32[3] = (float)((float)(v53 * v75.m_el[1].mVec128.m128_f32[3])
                                                          + (float)(v55 * v75.m_el[2].mVec128.m128_f32[3]))
                                                  + (float)(v54 * v75.m_el[0].mVec128.m128_f32[3]);
                  v83.m_el[0].mVec128.m128_f32[0] = (float)((float)(v53 * v75.m_el[1].mVec128.m128_f32[2])
                                                          + (float)(v55 * v75.m_el[2].mVec128.m128_f32[2]))
                                                  + (float)(v54 * v75.m_el[0].mVec128.m128_f32[2]);
                  btMatrix3x3::setValue(
                    &v83,
                    (int)&v86,
                    &v83.m_el[0].mVec128.m128_f32[3],
                    &v83.m_el[0].mVec128.m128_f32[1],
                    v83.m_el[1].mVec128.m128_f32,
                    &v83.m_el[1].mVec128.m128_f32[2],
                    &v82,
                    &v83.m_el[1].mVec128.m128_f32[1],
                    (float *)&v75,
                    &v73,
                    v72);
                  v98 = v86;
                  v99 = v87;
                  v100 = v88;
                  v101 = v89;
                  v102 = v90;
                  v103 = v91;
                  v104 = v92;
                  v105 = v93;
                  v106 = v94;
                  v107 = v95;
                  v108 = v96;
                  v109 = v97;
                  v110 = v83.m_el[1].mVec128.m128_i32[3];
                  v111 = v83.m_el[2].mVec128.m128_u64[0];
                  v69 = shape[9].mVec128.m128_i32[0];
                  v112 = v83.m_el[2].mVec128.m128_i32[2];
                  (*(void (__stdcall **)(_DWORD, int *, const btVector3 *))(*(_DWORD *)v83.m_el[0].mVec128.m128_i32[2]
                                                                          + 20))(
                    *(float *)(v69 + 4 * v75.m_el[0].mVec128.m128_i32[1]--),
                    &v98,
                    color);
                  v74 -= 16;
                  if ( v75.m_el[0].mVec128.m128_i32[1] < 0 )
                    break;
                  v49 = v74;
                  v7 = shape;
                }
              }
            }
          }
          else
          {
            v73 = ((double (__thiscall *)(btVector3 *))*(_DWORD *)(shape->mVec128.m128_i32[0] + 40))(shape);
            v70 = this->getDebugDrawer(this);
            v70->drawSphere(v70, COERCE_FLOAT(LODWORD(v73)), worldTransform, color);
          }
        }
        else
        {
          btBoxShape::getHalfExtentsWithMargin((btBoxShape *)v8, shape, (btVector3 *)&v83.m_el[1].m_floats[3]);
          v71 = this->getDebugDrawer(this);
          v85[0] = v83.m_el[1].mVec128.m128_i32[3] ^ _mask__NegFloat_;
          v85[1] = v83.m_el[2].mVec128.m128_i32[0] ^ _mask__NegFloat_;
          v85[2] = v83.m_el[2].mVec128.m128_i32[1] ^ _mask__NegFloat_;
          v85[3] = 0;
          v71->drawBox(v71, (const btVector3 *)v85, (const btVector3 *)&v83.m_el[1].m_floats[3], worldTransform, color);
        }
      }
    }
  }
}
