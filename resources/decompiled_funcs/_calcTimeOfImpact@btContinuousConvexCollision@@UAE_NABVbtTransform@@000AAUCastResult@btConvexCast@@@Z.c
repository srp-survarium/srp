char __thiscall btContinuousConvexCollision::calcTimeOfImpact(
        btContinuousConvexCollision *this,
        const btTransform *fromA,
        const btTransform *toA,
        const btTransform *fromB,
        const btTransform *toB,
        btConvexCast::CastResult *result)
{
  float v7; // xmm1_4
  btIDebugDraw *m_debugDrawer; // ecx
  const vostok::math::float4x4 *v9; // xmm2_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  btIDebugDraw *v12; // ecx
  int v13; // eax
  float v15; // [esp+1798h] [ebp-1B4h]
  float v16; // [esp+1798h] [ebp-1B4h]
  float v17; // [esp+1798h] [ebp-1B4h]
  float v18; // [esp+179Ch] [ebp-1B0h]
  float v19; // [esp+17A0h] [ebp-1ACh]
  int v20; // [esp+17A0h] [ebp-1ACh]
  float v21; // [esp+17A4h] [ebp-1A8h]
  float v22; // [esp+17A8h] [ebp-1A4h]
  float v23; // [esp+17ACh] [ebp-1A0h]
  float v24; // [esp+17B0h] [ebp-19Ch]
  float v25; // [esp+17B4h] [ebp-198h]
  btVector3 v27; // [esp+17CCh] [ebp-180h]
  btVector3 angVel; // [esp+17DCh] [ebp-170h] BYREF
  _DWORD v29[4]; // [esp+17ECh] [ebp-160h] BYREF
  btVector3 v30; // [esp+17FCh] [ebp-150h] BYREF
  btVector3 linVel; // [esp+180Ch] [ebp-140h] BYREF
  _DWORD v32[4]; // [esp+181Ch] [ebp-130h] BYREF
  btVector3 linvel; // [esp+182Ch] [ebp-120h] BYREF
  btVector3 angvel; // [esp+183Ch] [ebp-110h] BYREF
  btPointCollector v35; // [esp+184Ch] [ebp-100h] BYREF
  btPointCollector v36; // [esp+188Ch] [ebp-C0h] BYREF
  btTransform predictedTransform; // [esp+18CCh] [ebp-80h] BYREF
  btTransform transB; // [esp+190Ch] [ebp-40h] BYREF

  btTransformUtil::calculateVelocity(toA, &linVel, &angVel, fromA, 1.0);
  btTransformUtil::calculateVelocity(toB, &linvel, &angvel, fromB, 1.0);
  v15 = this->m_convexA->getAngularMotionDisc((struct btConvexShape *)this->m_convexA);
  if ( this->m_convexB1 )
    v19 = this->m_convexB1->getAngularMotionDisc((struct btConvexShape *)this->m_convexB1);
  else
    v19 = 0.0;
  v16 = sqrtf(
          (float)((float)(angVel.mVec128.m128_f32[2] * angVel.mVec128.m128_f32[2])
                + (float)(angVel.mVec128.m128_f32[0] * angVel.mVec128.m128_f32[0]))
        + (float)(angVel.mVec128.m128_f32[1] * angVel.mVec128.m128_f32[1]))
      * v15;
  v21 = sqrtf(
          (float)((float)(angvel.mVec128.m128_f32[1] * angvel.mVec128.m128_f32[1])
                + (float)(angvel.mVec128.m128_f32[2] * angvel.mVec128.m128_f32[2]))
        + (float)(angvel.mVec128.m128_f32[0] * angvel.mVec128.m128_f32[0]))
      * v19
      + v16;
  v23 = linvel.mVec128.m128_f32[0] - linVel.mVec128.m128_f32[0];
  v24 = linvel.mVec128.m128_f32[1] - linVel.mVec128.m128_f32[1];
  v25 = linvel.mVec128.m128_f32[2] - linVel.mVec128.m128_f32[2];
  if ( sqrtf(
         (float)((float)((float)(linvel.mVec128.m128_f32[0] - linVel.mVec128.m128_f32[0])
                       * (float)(linvel.mVec128.m128_f32[0] - linVel.mVec128.m128_f32[0]))
               + (float)((float)(linvel.mVec128.m128_f32[2] - linVel.mVec128.m128_f32[2])
                       * (float)(linvel.mVec128.m128_f32[2] - linVel.mVec128.m128_f32[2])))
       + (float)((float)(linvel.mVec128.m128_f32[1] - linVel.mVec128.m128_f32[1])
               * (float)(linvel.mVec128.m128_f32[1] - linVel.mVec128.m128_f32[1])))
     + v21 != 0.0 )
  {
    v18 = 0.0;
    v22 = 0.0;
    v20 = 0;
    v35.__vftable = (btPointCollector_vtbl *)&btPointCollector::`vftable';
    strcpy((char *)&v35.m_distance, "k\v^]");
    btContinuousConvexCollision::computeClosestPoints(fromA, fromB, (btVoronoiSimplexSolver *)&v35, this, &v35);
    v30.mVec128 = (__m128)_mm_load_si128((const __m128i *)&v35.m_pointInWorld);
    if ( v35.m_hasResult )
    {
      v7 = result->m_allowedPenetration + v35.m_distance;
      v27.mVec128 = (__m128)_mm_load_si128((const __m128i *)&v35.m_normalOnBInWorld);
      v17 = v7;
      if ( (float)((float)((float)((float)(v35.m_normalOnBInWorld.mVec128.m128_f32[1] * v24)
                                 + (float)(v35.m_normalOnBInWorld.mVec128.m128_f32[0] * v23))
                         + (float)(v35.m_normalOnBInWorld.mVec128.m128_f32[2] * v25))
                 + v21) > 0.00000011920929 )
      {
        if ( v7 <= 0.001 )
        {
LABEL_19:
          result->m_fraction = v18;
          result->m_normal = (btVector3)v27.mVec128;
          result->m_hitPoint = (btVector3)v30.mVec128;
          return 1;
        }
        while ( 1 )
        {
          m_debugDrawer = result->m_debugDrawer;
          v9 = clear_value;
          if ( m_debugDrawer )
          {
            v32[0] = clear_value;
            v32[1] = clear_value;
            v32[2] = clear_value;
            v32[3] = 0;
            ((void (__thiscall *)(btIDebugDraw *, btVector3 *, _DWORD, _DWORD *))m_debugDrawer->drawSphere)(
              m_debugDrawer,
              &v30,
              0.2,
              v32);
            v9 = clear_value;
            v7 = v17;
          }
          v10 = (float)((float)((float)(v27.mVec128.m128_f32[1] * v24) + (float)(v27.mVec128.m128_f32[0] * v23))
                      + (float)(v25 * v27.mVec128.m128_f32[2]))
              + v21;
          if ( v10 <= 0.00000011920929 )
            break;
          v11 = (float)(v7 / v10) + v18;
          v18 = v11;
          if ( v11 > *(float *)&v9 || v11 < 0.0 || v22 >= v11 )
            break;
          v22 = v11;
          btTransformUtil::integrateTransform(fromA, &linVel, &angVel, v11, &predictedTransform);
          btTransformUtil::integrateTransform(fromB, &linvel, &angvel, v11, &transB);
          v12 = result->m_debugDrawer;
          if ( v12 )
          {
            v29[0] = clear_value;
            memset(&v29[1], 0, 12);
            ((void (__thiscall *)(btIDebugDraw *, btVector3 *, _DWORD, _DWORD *))v12->drawSphere)(
              v12,
              &predictedTransform.m_origin,
              0.2,
              v29);
          }
          ((void (__thiscall *)(btConvexCast::CastResult *, _DWORD))result->DebugDraw)(result, LODWORD(v11));
          v36.__vftable = (btPointCollector_vtbl *)&btPointCollector::`vftable';
          strcpy((char *)&v36.m_distance, "k\v^]");
          btContinuousConvexCollision::computeClosestPoints(
            &predictedTransform,
            &transB,
            (btVoronoiSimplexSolver *)this,
            this,
            &v36);
          if ( !v36.m_hasResult )
          {
            result->reportFailure(result, -1, v20);
            return 0;
          }
          v7 = result->m_allowedPenetration + v36.m_distance;
          v13 = v20 + 1;
          v30.mVec128 = (__m128)_mm_load_si128((const __m128i *)&v36.m_pointInWorld);
          v17 = v7;
          v27.mVec128 = (__m128)_mm_load_si128((const __m128i *)&v36.m_normalOnBInWorld);
          v20 = v13;
          if ( v13 > 64 )
          {
            result->reportFailure(result, -2, v13);
            return 0;
          }
          if ( v7 <= 0.001 )
            goto LABEL_19;
        }
      }
    }
  }
  return 0;
}
