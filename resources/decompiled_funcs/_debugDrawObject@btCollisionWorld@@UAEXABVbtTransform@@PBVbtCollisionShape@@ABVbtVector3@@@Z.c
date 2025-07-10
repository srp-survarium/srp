void __thiscall btCollisionWorld::debugDrawObject(
        btCollisionWorld *this,
        const btTransform *worldTransform,
        const btCollisionShape *shape,
        const btVector3 *color)
{
  btIDebugDraw *v5; // eax
  btIDebugDraw *v6; // eax
  btCylinderShape *v7; // ecx
  int v8; // eax
  int v9; // eax
  btCollisionShape_vtbl *v10; // ecx
  __int64 v11; // xmm0_8
  float v12; // xmm2_4
  float v13; // xmm1_4
  __m128i *v14; // eax
  float v15; // xmm7_4
  float v16; // xmm3_4
  const btCollisionShape *v17; // eax
  float v18; // xmm6_4
  unsigned int v19; // xmm3_4
  float v20; // xmm4_4
  float v21; // xmm5_4
  unsigned int v22; // xmm4_4
  unsigned int v23; // xmm5_4
  __m128i v24; // xmm0
  void (__thiscall *debugDrawObject)(btCollisionWorld *, const btTransform *, const btCollisionShape *, const btVector3 *); // edx
  btIDebugDraw *v26; // eax
  btIDebugDraw *v27; // eax
  int v28; // ecx
  int v29; // ecx
  int m_shapeType; // eax
  btIDebugDraw *(__thiscall *getDebugDrawer)(btCollisionWorld *); // edx
  int v32; // eax
  float v33; // xmm1_4
  float v34; // xmm2_4
  float v35; // xmm6_4
  float v36; // xmm5_4
  float v37; // xmm6_4
  float v38; // xmm4_4
  float v39; // xmm3_4
  float v40; // xmm6_4
  unsigned int v41; // xmm3_4
  unsigned int v42; // xmm4_4
  unsigned int v43; // xmm5_4
  btCollisionShape_vtbl *v44; // ecx
  btIDebugDraw *v45; // eax
  void *v46; // edi
  btIDebugDraw *v47; // eax
  btCylinderShape *v48; // ecx
  int v49; // esi
  btIDebugDraw *v50; // eax
  btIDebugDraw *v51; // eax
  int j; // [esp+CB8h] [ebp-104h]
  int v54; // [esp+CBCh] [ebp-100h]
  unsigned int v55; // [esp+CC0h] [ebp-FCh]
  float v56; // [esp+CC0h] [ebp-FCh]
  float v57; // [esp+CC0h] [ebp-FCh]
  void *m_userPointer; // [esp+CC0h] [ebp-FCh]
  float v59; // [esp+CC0h] [ebp-FCh]
  float v60; // [esp+CC4h] [ebp-F8h]
  btCollisionShape_vtbl *v61; // [esp+CC4h] [ebp-F8h]
  int v62; // [esp+CC4h] [ebp-F8h]
  float v63; // [esp+CC4h] [ebp-F8h]
  int v64; // [esp+CC4h] [ebp-F8h]
  int i; // [esp+CC8h] [ebp-F4h]
  int v66; // [esp+CC8h] [ebp-F4h]
  int v67; // [esp+CCCh] [ebp-F0h]
  float v68; // [esp+CCCh] [ebp-F0h]
  unsigned int v69; // [esp+CD0h] [ebp-ECh]
  __int64 v70; // [esp+CD0h] [ebp-ECh]
  unsigned int v71; // [esp+CD4h] [ebp-E8h]
  unsigned int v72; // [esp+CD8h] [ebp-E4h]
  btVector3 v73; // [esp+CDCh] [ebp-E0h] BYREF
  __m128i v74; // [esp+CECh] [ebp-D0h] BYREF
  __m128i v75; // [esp+CFCh] [ebp-C0h]
  __m128i v76; // [esp+D0Ch] [ebp-B0h]
  __m128i v77; // [esp+D1Ch] [ebp-A0h]
  __m128i v78; // [esp+D2Ch] [ebp-90h] BYREF
  __m128i v79; // [esp+D3Ch] [ebp-80h] BYREF
  __m128i v80; // [esp+D4Ch] [ebp-70h] BYREF
  unsigned __int64 v81; // [esp+D5Ch] [ebp-60h] BYREF
  float v82; // [esp+D64h] [ebp-58h]
  int v83; // [esp+D68h] [ebp-54h]
  _OWORD v84[3]; // [esp+D6Ch] [ebp-50h] BYREF
  __m128i si128; // [esp+D9Ch] [ebp-20h]
  btVector3 v86; // [esp+DACh] [ebp-10h] BYREF

  if ( ((int (__fastcall *)(btCollisionWorld *))this->getDebugDrawer)(this) )
  {
    v5 = this->getDebugDrawer(this);
    if ( !v5->debugDrawObject(v5, worldTransform, shape, color) )
    {
      v6 = this->getDebugDrawer(this);
      ((void (__thiscall *)(btIDebugDraw *, const btTransform *, _DWORD))v6->drawTransform)(v6, worldTransform, 1.0);
      if ( shape->m_shapeType == 31 )
      {
        v8 = shape[1].m_shapeType - 1;
        v67 = v8;
        if ( v8 >= 0 )
        {
          v9 = 80 * v8;
          v73.mVec128.m128_i32[3] = 0;
          for ( i = v9; ; v9 = i )
          {
            v10 = shape[2].__vftable;
            v11 = *(_QWORD *)((char *)&v10->~btCollisionShape + v9);
            v12 = worldTransform->m_basis.m_el[0].mVec128.m128_f32[0];
            v13 = worldTransform->m_basis.m_el[0].mVec128.m128_f32[2];
            v14 = (__m128i *)((char *)v10 + v9);
            v74.m128i_i64[0] = v11;
            v74.m128i_i64[1] = v14->m128i_i64[1];
            v75 = v14[1];
            v76 = v14[2];
            v77 = v14[3];
            LODWORD(v11) = worldTransform->m_basis.m_el[0].mVec128.m128_i32[1];
            v15 = worldTransform->m_basis.m_el[1].mVec128.m128_f32[2];
            v73.mVec128.m128_f32[0] = (float)((float)((float)(v12 * *(float *)v77.m128i_i32)
                                                    + (float)(*(float *)&v11 * *(float *)&v77.m128i_i32[1]))
                                            + (float)(v13 * *(float *)&v77.m128i_i32[2]))
                                    + worldTransform->m_origin.mVec128.m128_f32[0];
            v16 = *(float *)v77.m128i_i32 * worldTransform->m_basis.m_el[2].mVec128.m128_f32[0];
            v73.mVec128.m128_f32[1] = (float)((float)((float)(worldTransform->m_basis.m_el[1].mVec128.m128_f32[1]
                                                            * *(float *)&v77.m128i_i32[1])
                                                    + (float)(v15 * *(float *)&v77.m128i_i32[2]))
                                            + (float)(*(float *)v77.m128i_i32
                                                    * worldTransform->m_basis.m_el[1].mVec128.m128_f32[0]))
                                    + worldTransform->m_origin.mVec128.m128_f32[1];
            v17 = (const btCollisionShape *)v14[4].m128i_i32[0];
            v18 = (float)((float)(worldTransform->m_basis.m_el[2].mVec128.m128_f32[1] * *(float *)&v77.m128i_i32[1])
                        + (float)(worldTransform->m_basis.m_el[2].mVec128.m128_f32[2] * *(float *)&v77.m128i_i32[2]))
                + v16;
            *(float *)&v19 = (float)((float)(worldTransform->m_basis.m_el[2].mVec128.m128_f32[1]
                                           * *(float *)&v75.m128i_i32[2])
                                   + (float)(worldTransform->m_basis.m_el[2].mVec128.m128_f32[2]
                                           * *(float *)&v76.m128i_i32[2]))
                           + (float)(worldTransform->m_basis.m_el[2].mVec128.m128_f32[0] * *(float *)&v74.m128i_i32[2]);
            v20 = (float)(worldTransform->m_basis.m_el[2].mVec128.m128_f32[1] * *(float *)&v75.m128i_i32[1])
                + (float)(worldTransform->m_basis.m_el[2].mVec128.m128_f32[2] * *(float *)&v76.m128i_i32[1]);
            v21 = worldTransform->m_basis.m_el[2].mVec128.m128_f32[0] * *(float *)&v74.m128i_i32[1];
            v73.mVec128.m128_f32[2] = v18 + worldTransform->m_origin.mVec128.m128_f32[2];
            *(float *)&v22 = v20 + v21;
            *(float *)&v23 = (float)((float)(worldTransform->m_basis.m_el[2].mVec128.m128_f32[1]
                                           * *(float *)v75.m128i_i32)
                                   + (float)(worldTransform->m_basis.m_el[2].mVec128.m128_f32[2]
                                           * *(float *)v76.m128i_i32))
                           + (float)(worldTransform->m_basis.m_el[2].mVec128.m128_f32[0] * *(float *)v74.m128i_i32);
            *(float *)&v55 = (float)((float)(worldTransform->m_basis.m_el[1].mVec128.m128_f32[1]
                                           * *(float *)&v75.m128i_i32[2])
                                   + (float)(worldTransform->m_basis.m_el[1].mVec128.m128_f32[2]
                                           * *(float *)&v76.m128i_i32[2]))
                           + (float)(*(float *)&v74.m128i_i32[2] * worldTransform->m_basis.m_el[1].mVec128.m128_f32[0]);
            *(float *)&v69 = (float)((float)(worldTransform->m_basis.m_el[1].mVec128.m128_f32[1]
                                           * *(float *)&v75.m128i_i32[1])
                                   + (float)(worldTransform->m_basis.m_el[1].mVec128.m128_f32[2]
                                           * *(float *)&v76.m128i_i32[1]))
                           + (float)(*(float *)&v74.m128i_i32[1] * worldTransform->m_basis.m_el[1].mVec128.m128_f32[0]);
            *(float *)&v71 = (float)((float)(worldTransform->m_basis.m_el[1].mVec128.m128_f32[1]
                                           * *(float *)v75.m128i_i32)
                                   + (float)(worldTransform->m_basis.m_el[1].mVec128.m128_f32[2]
                                           * *(float *)v76.m128i_i32))
                           + (float)(worldTransform->m_basis.m_el[1].mVec128.m128_f32[0] * *(float *)v74.m128i_i32);
            *(float *)v78.m128i_i32 = (float)((float)(*(float *)&v11 * *(float *)v75.m128i_i32)
                                            + (float)(v13 * *(float *)v76.m128i_i32))
                                    + (float)(v12 * *(float *)v74.m128i_i32);
            *(float *)&v78.m128i_i32[2] = (float)((float)(v12 * *(float *)&v74.m128i_i32[2])
                                                + (float)(*(float *)&v11 * *(float *)&v75.m128i_i32[2]))
                                        + (float)(v13 * *(float *)&v76.m128i_i32[2]);
            v79.m128i_i64[0] = __PAIR64__(v69, v71);
            v78.m128i_i32[3] = 0;
            *(float *)&v78.m128i_i32[1] = (float)((float)(v12 * *(float *)&v74.m128i_i32[1])
                                                + (float)(*(float *)&v11 * *(float *)&v75.m128i_i32[1]))
                                        + (float)(v13 * *(float *)&v76.m128i_i32[1]);
            v84[0] = _mm_load_si128(&v78);
            v79.m128i_i64[1] = v55;
            v24 = _mm_load_si128(&v79);
            v80.m128i_i64[0] = __PAIR64__(v22, v23);
            v80.m128i_i64[1] = v19;
            v84[1] = v24;
            v84[2] = _mm_load_si128(&v80);
            debugDrawObject = this->debugDrawObject;
            si128 = _mm_load_si128((const __m128i *)&v73);
            debugDrawObject(this, (const btTransform *)v84, v17, color);
            i -= 80;
            if ( --v67 < 0 )
              break;
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
        switch ( shape->m_shapeType )
        {
          case 0:
            btBoxShape::getHalfExtentsWithMargin(v7, shape, &v73);
            v26 = this->getDebugDrawer(this);
            v81 = v73.mVec128.m128_u64[0] ^ 0x8000000080000000uLL;
            v82 = -v73.mVec128.m128_f32[2];
            v83 = 0;
            v26->drawBox(v26, (const btVector3 *)&v81, &v73, worldTransform, color);
            break;
          case 8:
            v56 = shape->getMargin(shape);
            v27 = this->getDebugDrawer(this);
            ((void (__thiscall *)(btIDebugDraw *, _DWORD, const btTransform *, const btVector3 *))v27->drawSphere)(
              v27,
              LODWORD(v56),
              worldTransform,
              color);
            break;
          case 9:
            v28 = (int)shape[9].m_userPointer - 1;
            v66 = v28;
            if ( v28 >= 0 )
            {
              v29 = 16 * v28;
              v73.mVec128.m128_i32[3] = 0;
              for ( j = v29; ; v29 = j )
              {
                m_shapeType = shape[10].m_shapeType;
                si128.m128i_i64[0] = *(_QWORD *)(m_shapeType + v29);
                getDebugDrawer = this->getDebugDrawer;
                si128.m128i_i64[1] = *(_QWORD *)(v29 + m_shapeType + 8);
                v32 = (int)getDebugDrawer(this);
                v33 = worldTransform->m_basis.m_el[0].mVec128.m128_f32[1];
                v34 = worldTransform->m_basis.m_el[0].mVec128.m128_f32[0];
                v68 = worldTransform->m_basis.m_el[0].mVec128.m128_f32[2];
                v35 = worldTransform->m_basis.m_el[1].mVec128.m128_f32[1] * *(float *)&si128.m128i_i32[1];
                v73.mVec128.m128_f32[0] = (float)((float)((float)(worldTransform->m_basis.m_el[0].mVec128.m128_f32[0]
                                                                * *(float *)si128.m128i_i32)
                                                        + (float)(v33 * *(float *)&si128.m128i_i32[1]))
                                                + (float)(v68 * *(float *)&si128.m128i_i32[2]))
                                        + worldTransform->m_origin.mVec128.m128_f32[0];
                v36 = (float)((float)((float)(worldTransform->m_basis.m_el[1].mVec128.m128_f32[2]
                                            * *(float *)&si128.m128i_i32[2])
                                    + v35)
                            + (float)(worldTransform->m_basis.m_el[1].mVec128.m128_f32[0] * *(float *)si128.m128i_i32))
                    + worldTransform->m_origin.mVec128.m128_f32[1];
                v37 = worldTransform->m_basis.m_el[1].mVec128.m128_f32[1]
                    + worldTransform->m_basis.m_el[1].mVec128.m128_f32[0];
                v73.mVec128.m128_f32[1] = v36;
                *(float *)&v72 = (float)(v37 * 0.0) + worldTransform->m_basis.m_el[1].mVec128.m128_f32[2];
                v38 = worldTransform->m_basis.m_el[2].mVec128.m128_f32[2]
                    + worldTransform->m_basis.m_el[2].mVec128.m128_f32[0];
                v39 = worldTransform->m_basis.m_el[2].mVec128.m128_f32[1]
                    + worldTransform->m_basis.m_el[2].mVec128.m128_f32[0];
                *((float *)&v70 + 1) = (float)((float)(worldTransform->m_basis.m_el[1].mVec128.m128_f32[2]
                                                     + worldTransform->m_basis.m_el[1].mVec128.m128_f32[0])
                                             * 0.0)
                                     + worldTransform->m_basis.m_el[1].mVec128.m128_f32[1];
                v40 = worldTransform->m_basis.m_el[1].mVec128.m128_f32[2]
                    + worldTransform->m_basis.m_el[1].mVec128.m128_f32[1];
                v73.mVec128.m128_f32[2] = (float)((float)((float)(worldTransform->m_basis.m_el[2].mVec128.m128_f32[2]
                                                                * *(float *)&si128.m128i_i32[2])
                                                        + (float)(worldTransform->m_basis.m_el[2].mVec128.m128_f32[1]
                                                                * *(float *)&si128.m128i_i32[1]))
                                                + (float)(worldTransform->m_basis.m_el[2].mVec128.m128_f32[0]
                                                        * *(float *)si128.m128i_i32))
                                        + worldTransform->m_origin.mVec128.m128_f32[2];
                *(float *)&v70 = (float)(v40 * 0.0) + worldTransform->m_basis.m_el[1].mVec128.m128_f32[0];
                *(float *)&v41 = (float)(v39 * 0.0) + worldTransform->m_basis.m_el[2].mVec128.m128_f32[2];
                *(float *)&v42 = (float)(v38 * 0.0) + worldTransform->m_basis.m_el[2].mVec128.m128_f32[1];
                *(float *)&v43 = (float)((float)(worldTransform->m_basis.m_el[2].mVec128.m128_f32[2]
                                               + worldTransform->m_basis.m_el[2].mVec128.m128_f32[1])
                                       * 0.0)
                               + worldTransform->m_basis.m_el[2].mVec128.m128_f32[0];
                *(float *)&v78.m128i_i32[1] = (float)(v33 + (float)(v68 * 0.0)) + (float)(v34 * 0.0);
                v79.m128i_i64[0] = v70;
                v78.m128i_i32[3] = 0;
                *(float *)v78.m128i_i32 = (float)(v34 + (float)(v68 * 0.0)) + (float)(v33 * 0.0);
                *(float *)&v78.m128i_i32[2] = (float)(v68 + (float)(v34 * 0.0)) + (float)(v33 * 0.0);
                v74 = _mm_load_si128(&v78);
                v79.m128i_i64[1] = v72;
                v75 = _mm_load_si128(&v79);
                v44 = shape[12].__vftable;
                v80.m128i_i64[0] = __PAIR64__(v42, v43);
                v80.m128i_i64[1] = v41;
                v76 = _mm_load_si128(&v80);
                v77 = _mm_load_si128((const __m128i *)&v73);
                (*(void (__thiscall **)(int, _DWORD, __m128i *, const btVector3 *))(*(_DWORD *)v32 + 20))(
                  v32,
                  *((float *)&v44->~btCollisionShape + v66),
                  &v74,
                  color);
                j -= 16;
                if ( --v66 < 0 )
                  break;
              }
            }
            break;
          case 0xA:
            v54 = shape[5].m_shapeType;
            v57 = *((float *)&shape[2].m_userPointer + (v54 + 2) % 3);
            v60 = *((float *)&shape[2].m_userPointer + v54);
            v45 = this->getDebugDrawer(this);
            ((void (__thiscall *)(btIDebugDraw *, _DWORD, _DWORD, int, const btTransform *, const btVector3 *))v45->drawCapsule)(
              v45,
              LODWORD(v57),
              LODWORD(v60),
              v54,
              worldTransform,
              color);
            break;
          case 0xB:
            m_userPointer = shape[5].m_userPointer;
            v46 = shape[6].m_userPointer;
            v61 = shape[6].__vftable;
            v47 = this->getDebugDrawer(this);
            ((void (__thiscall *)(btIDebugDraw *, void *, btCollisionShape_vtbl *, void *, const btTransform *, const btVector3 *))v47->drawCone)(
              v47,
              m_userPointer,
              v61,
              v46,
              worldTransform,
              color);
            break;
          case 0xD:
            v62 = shape[5].m_shapeType;
            v59 = ((double (__thiscall *)(const btCollisionShape *))shape->__vftable[1].calculateLocalInertia)(shape);
            v49 = v62;
            v63 = btBoxShape::getHalfExtentsWithMargin(v48, shape, &v86)->mVec128.m128_f32[v62];
            v50 = this->getDebugDrawer(this);
            ((void (__thiscall *)(btIDebugDraw *, _DWORD, _DWORD, int, const btTransform *, const btVector3 *))v50->drawCylinder)(
              v50,
              LODWORD(v59),
              LODWORD(v63),
              v49,
              worldTransform,
              color);
            break;
          case 0x1C:
            v64 = shape[5].m_shapeType;
            v51 = this->getDebugDrawer(this);
            ((void (__thiscall *)(btIDebugDraw *, const btCollisionShape *, int, const btTransform *, const btVector3 *))v51->drawPlane)(
              v51,
              shape + 4,
              v64,
              worldTransform,
              color);
            break;
          default:
            return;
        }
      }
    }
  }
}
