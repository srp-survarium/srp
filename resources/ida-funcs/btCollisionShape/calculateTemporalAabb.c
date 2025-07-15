void __userpurge btCollisionShape::calculateTemporalAabb(
        const btTransform *curTrans@<ecx>,
        btVector3 *temporalAabbMin@<edi>,
        btVector3 *temporalAabbMax@<esi>,
        btCollisionShape *this,
        const btVector3 *linvel,
        const btVector3 *angvel,
        float timeStep)
{
  float v7; // xmm1_4
  float v8; // xmm0_4
  double v9; // st7
  float v10; // xmm1_4
  unsigned __int64 v11; // [esp+ECh] [ebp-2Ch]
  unsigned __int64 v12; // [esp+F4h] [ebp-24h]
  unsigned __int64 v13; // [esp+FCh] [ebp-1Ch]
  float v14; // [esp+104h] [ebp-14h]
  float v15; // [esp+104h] [ebp-14h]

  ((void (__thiscall *)(btCollisionShape *, const btTransform *))this->getAabb)(this, curTrans);
  v7 = linvel->mVec128.m128_f32[1];
  v8 = linvel->mVec128.m128_f32[0];
  v12 = temporalAabbMax->mVec128.m128_u64[0];
  v11 = temporalAabbMin->mVec128.m128_u64[0];
  if ( linvel->mVec128.m128_f32[0] <= 0.0 )
    *(float *)&v11 = v8 + temporalAabbMin->mVec128.m128_f32[0];
  else
    *(float *)&v12 = v8 + temporalAabbMax->mVec128.m128_f32[0];
  if ( v7 <= 0.0 )
    *((float *)&v11 + 1) = v7 + temporalAabbMin->mVec128.m128_f32[1];
  else
    *((float *)&v12 + 1) = v7 + temporalAabbMax->mVec128.m128_f32[1];
  *(float *)&v13 = sqrtf(
                     (float)((float)(angvel->mVec128.m128_f32[0] * angvel->mVec128.m128_f32[0])
                           + (float)(angvel->mVec128.m128_f32[1] * angvel->mVec128.m128_f32[1]))
                   + (float)(angvel->mVec128.m128_f32[2] * angvel->mVec128.m128_f32[2]));
  v9 = ((double (__thiscall *)(btCollisionShape *))this->getAngularMotionDisc)(this) * v14;
  v15 = v9;
  temporalAabbMin->mVec128.m128_u64[0] = v12;
  temporalAabbMin->mVec128.m128_u64[1] = (unsigned int)v11;
  temporalAabbMax->mVec128.m128_u64[0] = v13;
  temporalAabbMax->mVec128.m128_u64[1] = HIDWORD(v11);
  v10 = temporalAabbMin->mVec128.m128_f32[2] - v15;
  temporalAabbMin->mVec128.m128_f32[0] = temporalAabbMin->mVec128.m128_f32[0] - v9;
  temporalAabbMin->mVec128.m128_f32[2] = v10;
  temporalAabbMin->mVec128.m128_f32[1] = temporalAabbMin->mVec128.m128_f32[1] - v9;
  temporalAabbMax->mVec128.m128_f32[0] = temporalAabbMax->mVec128.m128_f32[0] + v15;
  temporalAabbMax->mVec128.m128_f32[1] = temporalAabbMax->mVec128.m128_f32[1] + v15;
  temporalAabbMax->mVec128.m128_f32[2] = temporalAabbMax->mVec128.m128_f32[2] + v15;
}
