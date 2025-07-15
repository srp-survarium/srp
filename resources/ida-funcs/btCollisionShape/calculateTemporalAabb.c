void __userpurge btCollisionShape::calculateTemporalAabb(
        const btVector3 *linvel@<eax>,
        btCollisionShape *this,
        const btTransform *curTrans,
        const btVector3 *angvel,
        btVector3 *timeStep,
        btVector3 *temporalAabbMin,
        btVector3 *temporalAabbMax)
{
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm0_4
  double v11; // st7
  double v12; // st7
  float v13; // [esp+14h] [ebp-2Ch]
  float v14; // [esp+18h] [ebp-28h]
  float v15; // [esp+1Ch] [ebp-24h]
  float v16; // [esp+1Ch] [ebp-24h]
  unsigned __int64 v17; // [esp+20h] [ebp-20h]
  unsigned __int64 v18; // [esp+28h] [ebp-18h]

  this->getAabb(this, curTrans, timeStep, temporalAabbMin);
  v8 = linvel->mVec128.m128_f32[1];
  v9 = linvel->mVec128.m128_f32[2];
  v14 = temporalAabbMin->mVec128.m128_f32[2];
  v13 = timeStep->mVec128.m128_f32[2];
  v10 = linvel->mVec128.m128_f32[0];
  v18 = temporalAabbMin->mVec128.m128_u64[0];
  v17 = timeStep->mVec128.m128_u64[0];
  if ( linvel->mVec128.m128_f32[0] <= 0.0 )
    *(float *)&v17 = v10 + timeStep->mVec128.m128_f32[0];
  else
    *(float *)&v18 = v10 + temporalAabbMin->mVec128.m128_f32[0];
  if ( v8 <= 0.0 )
    *((float *)&v17 + 1) = v8 + timeStep->mVec128.m128_f32[1];
  else
    *((float *)&v18 + 1) = v8 + temporalAabbMin->mVec128.m128_f32[1];
  if ( v9 <= 0.0 )
    v13 = v9 + v13;
  else
    v14 = v9 + v14;
  v15 = (float)((float)(angvel->mVec128.m128_f32[0] * angvel->mVec128.m128_f32[0])
              + (float)(angvel->mVec128.m128_f32[1] * angvel->mVec128.m128_f32[1]))
      + (float)(angvel->mVec128.m128_f32[2] * angvel->mVec128.m128_f32[2]);
  v11 = ((double (__thiscall *)(btCollisionShape *))this->getAngularMotionDisc)(this);
  timeStep->mVec128.m128_u64[0] = v17;
  timeStep->mVec128.m128_u64[1] = LODWORD(v13);
  temporalAabbMin->mVec128.m128_u64[0] = v18;
  temporalAabbMin->mVec128.m128_u64[1] = LODWORD(v14);
  v16 = v11 * sqrt(v15);
  v12 = timeStep->mVec128.m128_f32[0] - v16;
  timeStep->mVec128.m128_f32[2] = timeStep->mVec128.m128_f32[2] - v16;
  timeStep->mVec128.m128_f32[0] = v12;
  timeStep->mVec128.m128_f32[1] = timeStep->mVec128.m128_f32[1] - v16;
  temporalAabbMin->mVec128.m128_f32[0] = temporalAabbMin->mVec128.m128_f32[0] + v16;
  temporalAabbMin->mVec128.m128_f32[1] = temporalAabbMin->mVec128.m128_f32[1] + v16;
  temporalAabbMin->mVec128.m128_f32[2] = temporalAabbMin->mVec128.m128_f32[2] + v16;
}
