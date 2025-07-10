char __userpurge btDbvt::update@<al>(
        btDbvtAabbMm *volume@<eax>,
        const btVector3 *velocity@<ecx>,
        btDbvt *this,
        btDbvtNode *leaf,
        float margin)
{
  float v6; // xmm0_4
  float v7; // xmm0_4
  float v8; // xmm0_4

  if ( volume->mi.mVec128.m128_f32[0] >= leaf->volume.mi.mVec128.m128_f32[0]
    && volume->mi.mVec128.m128_f32[1] >= leaf->volume.mi.mVec128.m128_f32[1]
    && volume->mi.mVec128.m128_f32[2] >= leaf->volume.mi.mVec128.m128_f32[2]
    && leaf->volume.mx.mVec128.m128_f32[0] >= volume->mx.mVec128.m128_f32[0]
    && leaf->volume.mx.mVec128.m128_f32[1] >= volume->mx.mVec128.m128_f32[1]
    && leaf->volume.mx.mVec128.m128_f32[2] >= volume->mx.mVec128.m128_f32[2] )
  {
    return 0;
  }
  volume->mi.mVec128.m128_f32[0] = volume->mi.mVec128.m128_f32[0] - margin;
  volume->mi.mVec128.m128_f32[1] = volume->mi.mVec128.m128_f32[1] - margin;
  volume->mi.mVec128.m128_f32[2] = volume->mi.mVec128.m128_f32[2] - margin;
  volume->mx.mVec128.m128_f32[0] = margin + volume->mx.mVec128.m128_f32[0];
  volume->mx.mVec128.m128_f32[1] = volume->mx.mVec128.m128_f32[1] + margin;
  volume->mx.mVec128.m128_f32[2] = volume->mx.mVec128.m128_f32[2] + margin;
  v6 = velocity->mVec128.m128_f32[0];
  if ( velocity->mVec128.m128_f32[0] <= 0.0 )
    volume->mi.mVec128.m128_f32[0] = volume->mi.mVec128.m128_f32[0] + v6;
  else
    volume->mx.mVec128.m128_f32[0] = v6 + volume->mx.mVec128.m128_f32[0];
  v7 = velocity->mVec128.m128_f32[1];
  if ( v7 <= 0.0 )
    volume->mi.mVec128.m128_f32[1] = volume->mi.mVec128.m128_f32[1] + v7;
  else
    volume->mx.mVec128.m128_f32[1] = volume->mx.mVec128.m128_f32[1] + v7;
  v8 = velocity->mVec128.m128_f32[2];
  if ( v8 <= 0.0 )
    volume->mi.mVec128.m128_f32[2] = v8 + volume->mi.mVec128.m128_f32[2];
  else
    volume->mx.mVec128.m128_f32[2] = volume->mx.mVec128.m128_f32[2] + v8;
  btDbvt::update(leaf, this, volume);
  return 1;
}
