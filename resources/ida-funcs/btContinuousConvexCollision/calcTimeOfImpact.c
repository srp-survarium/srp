char __thiscall btContinuousConvexCollision::calcTimeOfImpact(
        btContinuousConvexCollision *this,
        const btTransform *fromA,
        const btTransform *toA,
        const btTransform *fromB,
        const btTransform *toB,
        btConvexCast::CastResult *result)
{
  btContinuousConvexCollision *v7; // ecx
  float v8; // xmm2_4
  long double v9; // rdi
  btIDebugDraw *m_debugDrawer; // ecx
  float v12; // xmm1_4
  float v13; // xmm0_4
  float v14; // xmm2_4
  btIDebugDraw *v15; // ecx
  btContinuousConvexCollision *v16; // ecx
  const float *v17; // [esp+Ch] [ebp-220h]
  float v18; // [esp+18h] [ebp-214h]
  int v19; // [esp+18h] [ebp-214h]
  float v20; // [esp+1Ch] [ebp-210h]
  float v21; // [esp+20h] [ebp-20Ch]
  float v22; // [esp+20h] [ebp-20Ch]
  float v23; // [esp+24h] [ebp-208h]
  float v24; // [esp+28h] [ebp-204h]
  float v25; // [esp+2Ch] [ebp-200h]
  float v26; // [esp+30h] [ebp-1FCh]
  float v27; // [esp+34h] [ebp-1F8h]
  btVector3 v29; // [esp+4Ch] [ebp-1E0h] BYREF
  btMatrix3x3 v30; // [esp+60h] [ebp-1CCh] BYREF
  float v31; // [esp+94h] [ebp-198h] BYREF
  float v32; // [esp+98h] [ebp-194h] BYREF
  btTransform v33; // [esp+9Ch] [ebp-190h] BYREF
  btVector3 v34; // [esp+DCh] [ebp-150h]
  _DWORD v35[4]; // [esp+ECh] [ebp-140h] BYREF
  btTransform v36; // [esp+FCh] [ebp-130h] BYREF
  btVector3 v37; // [esp+13Ch] [ebp-F0h] BYREF
  btVector3 v38; // [esp+14Ch] [ebp-E0h] BYREF
  _DWORD v39[4]; // [esp+15Ch] [ebp-D0h] BYREF
  unsigned __int64 v40; // [esp+16Ch] [ebp-C0h] BYREF
  int v41; // [esp+174h] [ebp-B8h]
  int v42; // [esp+178h] [ebp-B4h]
  btIDebugDraw v43; // [esp+17Ch] [ebp-B0h] BYREF
  btVector3 v44; // [esp+18Ch] [ebp-A0h]
  unsigned __int64 v45; // [esp+19Ch] [ebp-90h] BYREF
  int v46; // [esp+1A4h] [ebp-88h]
  int v47; // [esp+1A8h] [ebp-84h]
  float v48[2]; // [esp+1ACh] [ebp-80h] BYREF
  btIDebugDraw v49; // [esp+1BCh] [ebp-70h] BYREF
  btVector3 v50; // [esp+1CCh] [ebp-60h]
  unsigned __int64 v51; // [esp+1DCh] [ebp-50h] BYREF
  int v52; // [esp+1E4h] [ebp-48h]
  int v53; // [esp+1E8h] [ebp-44h]
  float v54[2]; // [esp+1ECh] [ebp-40h] BYREF
  _BYTE v55[48]; // [esp+1FCh] [ebp-30h] BYREF

  btTransformUtil::calculateVelocity(fromA, toA, 1.0, &v37, (btVector3 *)&v30.m_el[1].m_floats[3]);
  btTransformUtil::calculateVelocity(fromB, toB, 1.0, &v38, &v29);
  v21 = this->m_convexA->getAngularMotionDisc((struct btConvexShape *)this->m_convexA);
  if ( this->m_convexB1 )
    v18 = this->m_convexB1->getAngularMotionDisc((struct btConvexShape *)this->m_convexB1);
  else
    v18 = 0.0;
  v25 = v38.mVec128.m128_f32[0] - v37.mVec128.m128_f32[0];
  v23 = (float)(fsqrt(
                  (float)((float)(v30.m_el[2].mVec128.m128_f32[0] * v30.m_el[2].mVec128.m128_f32[0])
                        + (float)(v30.m_el[2].mVec128.m128_f32[1] * v30.m_el[2].mVec128.m128_f32[1]))
                + (float)(v30.m_el[1].mVec128.m128_f32[3] * v30.m_el[1].mVec128.m128_f32[3]))
              * v21)
      + (float)(fsqrt(
                  (float)((float)(v29.mVec128.m128_f32[2] * v29.mVec128.m128_f32[2])
                        + (float)(v29.mVec128.m128_f32[0] * v29.mVec128.m128_f32[0]))
                + (float)(v29.mVec128.m128_f32[1] * v29.mVec128.m128_f32[1]))
              * v18);
  v26 = v38.mVec128.m128_f32[1] - v37.mVec128.m128_f32[1];
  v27 = v38.mVec128.m128_f32[2] - v37.mVec128.m128_f32[2];
  if ( (float)(fsqrt(
                 (float)((float)((float)(v38.mVec128.m128_f32[0] - v37.mVec128.m128_f32[0])
                               * (float)(v38.mVec128.m128_f32[0] - v37.mVec128.m128_f32[0]))
                       + (float)((float)(v38.mVec128.m128_f32[2] - v37.mVec128.m128_f32[2])
                               * (float)(v38.mVec128.m128_f32[2] - v37.mVec128.m128_f32[2])))
               + (float)((float)(v38.mVec128.m128_f32[1] - v37.mVec128.m128_f32[1])
                       * (float)(v38.mVec128.m128_f32[1] - v37.mVec128.m128_f32[1])))
             + v23) != 0.0 )
  {
    v19 = 0;
    v20 = 0.0;
    v24 = 0.0;
    v43.__vftable = (btIDebugDraw_vtbl *)&btPointCollector::`vftable';
    strcpy((char *)v48, "k\v^]");
    btContinuousConvexCollision::computeClosestPoints(v7, (int)this, fromA, fromB, &v43);
    v40 = v45;
    v41 = v46;
    v42 = v47;
    if ( LOBYTE(v48[1]) )
    {
      v8 = result->m_allowedPenetration + v48[0];
      v34.mVec128 = v44.mVec128;
      v22 = v8;
      HIDWORD(v9) = &v45;
      LODWORD(v9) = v35;
      if ( (float)((float)((float)((float)(v44.mVec128.m128_f32[0] * v25) + (float)(v44.mVec128.m128_f32[2] * v27))
                         + (float)(v44.mVec128.m128_f32[1] * v26))
                 + v23) > 0.00000011920929 )
      {
        while ( 1 )
        {
          if ( v8 <= 0.001 )
          {
            result->m_normal = (btVector3)v34.mVec128;
            result->m_hitPoint.mVec128.m128_u64[0] = v40;
            result->m_hitPoint.mVec128.m128_i32[2] = v41;
            result->m_fraction = v20;
            result->m_hitPoint.mVec128.m128_i32[3] = v42;
            return 1;
          }
          m_debugDrawer = result->m_debugDrawer;
          v12 = s_bm_current_air_resistance;
          if ( m_debugDrawer )
          {
            *(float *)v39 = s_bm_current_air_resistance;
            *(float *)&v39[1] = s_bm_current_air_resistance;
            *(float *)&v39[2] = s_bm_current_air_resistance;
            v39[3] = 0;
            ((void (__thiscall *)(btIDebugDraw *, unsigned __int64 *, _DWORD, _DWORD *))m_debugDrawer->drawSphere)(
              m_debugDrawer,
              &v40,
              0.2,
              v39);
            v12 = s_bm_current_air_resistance;
            v8 = v22;
          }
          v13 = (float)((float)((float)(v25 * v34.mVec128.m128_f32[0]) + (float)(v34.mVec128.m128_f32[2] * v27))
                      + (float)(v34.mVec128.m128_f32[1] * v26))
              + v23;
          if ( v13 <= 0.00000011920929 )
            return 0;
          v14 = (float)(v8 / v13) + v20;
          v20 = v14;
          if ( v14 > v12 || v14 < 0.0 || v24 >= v14 )
            return 0;
          v24 = v14;
          btTransformUtil::integrateTransform(&v37, v9, fromA, (const btVector3 *)&v30.m_el[1].m_floats[3], v14, &v36);
          btTransformUtil::integrateTransform(&v38, v9, fromB, &v29, v14, &v33);
          v30.m_el[0].mVec128.m128_f32[3] = (float)((float)(v36.m_basis.m_el[1].mVec128.m128_f32[2]
                                                          * v33.m_basis.m_el[1].mVec128.m128_f32[2])
                                                  + (float)(v36.m_basis.m_el[2].mVec128.m128_f32[2]
                                                          * v33.m_basis.m_el[2].mVec128.m128_f32[2]))
                                          + (float)(v36.m_basis.m_el[0].mVec128.m128_f32[2]
                                                  * v33.m_basis.m_el[0].mVec128.m128_f32[2]);
          v30.m_el[1].mVec128.m128_f32[1] = (float)((float)(v36.m_basis.m_el[1].mVec128.m128_f32[1]
                                                          * v33.m_basis.m_el[1].mVec128.m128_f32[2])
                                                  + (float)(v36.m_basis.m_el[2].mVec128.m128_f32[1]
                                                          * v33.m_basis.m_el[2].mVec128.m128_f32[2]))
                                          + (float)(v36.m_basis.m_el[0].mVec128.m128_f32[1]
                                                  * v33.m_basis.m_el[0].mVec128.m128_f32[2]);
          v32 = (float)((float)(v36.m_basis.m_el[1].mVec128.m128_f32[0] * v33.m_basis.m_el[1].mVec128.m128_f32[2])
                      + (float)(v36.m_basis.m_el[2].mVec128.m128_f32[0] * v33.m_basis.m_el[2].mVec128.m128_f32[2]))
              + (float)(v36.m_basis.m_el[0].mVec128.m128_f32[0] * v33.m_basis.m_el[0].mVec128.m128_f32[2]);
          v30.m_el[0].mVec128.m128_f32[2] = (float)((float)(v36.m_basis.m_el[1].mVec128.m128_f32[2]
                                                          * v33.m_basis.m_el[1].mVec128.m128_f32[1])
                                                  + (float)(v36.m_basis.m_el[2].mVec128.m128_f32[2]
                                                          * v33.m_basis.m_el[2].mVec128.m128_f32[1]))
                                          + (float)(v36.m_basis.m_el[0].mVec128.m128_f32[2]
                                                  * v33.m_basis.m_el[0].mVec128.m128_f32[1]);
          v30.m_el[0].mVec128.m128_f32[1] = (float)((float)(v36.m_basis.m_el[1].mVec128.m128_f32[1]
                                                          * v33.m_basis.m_el[1].mVec128.m128_f32[1])
                                                  + (float)(v36.m_basis.m_el[2].mVec128.m128_f32[1]
                                                          * v33.m_basis.m_el[2].mVec128.m128_f32[1]))
                                          + (float)(v36.m_basis.m_el[0].mVec128.m128_f32[1]
                                                  * v33.m_basis.m_el[0].mVec128.m128_f32[1]);
          v30.m_el[1].mVec128.m128_f32[0] = (float)((float)(v36.m_basis.m_el[0].mVec128.m128_f32[2]
                                                          * v33.m_basis.m_el[0].mVec128.m128_f32[0])
                                                  + (float)(v36.m_basis.m_el[1].mVec128.m128_f32[2]
                                                          * v33.m_basis.m_el[1].mVec128.m128_f32[0]))
                                          + (float)(v36.m_basis.m_el[2].mVec128.m128_f32[2]
                                                  * v33.m_basis.m_el[2].mVec128.m128_f32[0]);
          v30.m_el[1].mVec128.m128_f32[2] = (float)((float)(v36.m_basis.m_el[1].mVec128.m128_f32[0]
                                                          * v33.m_basis.m_el[1].mVec128.m128_f32[1])
                                                  + (float)(v36.m_basis.m_el[2].mVec128.m128_f32[0]
                                                          * v33.m_basis.m_el[2].mVec128.m128_f32[1]))
                                          + (float)(v36.m_basis.m_el[0].mVec128.m128_f32[0]
                                                  * v33.m_basis.m_el[0].mVec128.m128_f32[1]);
          v31 = (float)((float)(v36.m_basis.m_el[0].mVec128.m128_f32[1] * v33.m_basis.m_el[0].mVec128.m128_f32[0])
                      + (float)(v36.m_basis.m_el[1].mVec128.m128_f32[1] * v33.m_basis.m_el[1].mVec128.m128_f32[0]))
              + (float)(v36.m_basis.m_el[2].mVec128.m128_f32[1] * v33.m_basis.m_el[2].mVec128.m128_f32[0]);
          v30.m_el[0].mVec128.m128_f32[0] = (float)((float)(v36.m_basis.m_el[0].mVec128.m128_f32[0]
                                                          * v33.m_basis.m_el[0].mVec128.m128_f32[0])
                                                  + (float)(v36.m_basis.m_el[1].mVec128.m128_f32[0]
                                                          * v33.m_basis.m_el[1].mVec128.m128_f32[0]))
                                          + (float)(v36.m_basis.m_el[2].mVec128.m128_f32[0]
                                                  * v33.m_basis.m_el[2].mVec128.m128_f32[0]);
          btMatrix3x3::setValue(
            &v30,
            (int)v55,
            &v31,
            v30.m_el[1].mVec128.m128_f32,
            &v30.m_el[1].mVec128.m128_f32[2],
            &v30.m_el[0].mVec128.m128_f32[1],
            &v30.m_el[0].mVec128.m128_f32[2],
            &v32,
            &v30.m_el[1].mVec128.m128_f32[1],
            &v30.m_el[0].mVec128.m128_f32[3],
            v17);
          v15 = result->m_debugDrawer;
          if ( v15 )
          {
            *(float *)v35 = s_bm_current_air_resistance;
            memset(&v35[1], 0, 12);
            ((void (__thiscall *)(btIDebugDraw *, btVector3 *, _DWORD, _DWORD *))v15->drawSphere)(
              v15,
              &v36.m_origin,
              0.2,
              v35);
          }
          ((void (__thiscall *)(btConvexCast::CastResult *, _DWORD))result->DebugDraw)(result, LODWORD(v14));
          v49.__vftable = (btIDebugDraw_vtbl *)&btPointCollector::`vftable';
          strcpy((char *)v54, "k\v^]");
          btContinuousConvexCollision::computeClosestPoints(v16, (int)this, &v36, &v33, &v49);
          if ( !LOBYTE(v54[1]) )
            break;
          v40 = v51;
          ++v19;
          v8 = result->m_allowedPenetration + v54[0];
          v41 = v52;
          v42 = v53;
          v34.mVec128 = v50.mVec128;
          v22 = v8;
          HIDWORD(v9) = &v51;
          LODWORD(v9) = v35;
          if ( v19 > 64 )
          {
            result->reportFailure(result, -2, v19);
            return 0;
          }
        }
        result->reportFailure(result, -1, v19);
      }
    }
  }
  return 0;
}
