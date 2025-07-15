void __thiscall btCollisionWorld::AllHitsRayResultCallback::AllHitsRayResultCallback(
        btCollisionWorld::AllHitsRayResultCallback *this,
        const btVector3 *rayFromWorld,
        const btVector3 *rayToWorld,
        const btVector3 *a4)
{
  btCollisionWorld::RayResultCallback::RayResultCallback(this, (int)rayFromWorld);
  rayFromWorld->mVec128.m128_i32[0] = (int)&btCollisionWorld::AllHitsRayResultCallback::`vftable';
  rayFromWorld[2].mVec128.m128_i8[8] = 1;
  rayFromWorld[2].mVec128.m128_i32[1] = 0;
  rayFromWorld[1].mVec128.m128_i32[3] = 0;
  rayFromWorld[2].mVec128.m128_i32[0] = 0;
  rayFromWorld[3] = (const btVector3)rayToWorld->mVec128;
  rayFromWorld[4] = (const btVector3)a4->mVec128;
  rayFromWorld[5].mVec128.m128_i32[3] = 0;
  rayFromWorld[5].mVec128.m128_i32[1] = 0;
  rayFromWorld[5].mVec128.m128_i32[2] = 0;
  rayFromWorld[6].mVec128.m128_i8[0] = 1;
  rayFromWorld[7].mVec128.m128_i32[0] = 0;
  rayFromWorld[6].mVec128.m128_i32[2] = 0;
  rayFromWorld[6].mVec128.m128_i32[3] = 0;
  rayFromWorld[7].mVec128.m128_i8[4] = 1;
  rayFromWorld[8].mVec128.m128_i32[1] = 0;
  rayFromWorld[7].mVec128.m128_i32[3] = 0;
  rayFromWorld[8].mVec128.m128_i32[0] = 0;
  rayFromWorld[8].mVec128.m128_i8[8] = 1;
  rayFromWorld[9].mVec128.m128_i32[2] = 0;
  rayFromWorld[9].mVec128.m128_i32[0] = 0;
  rayFromWorld[9].mVec128.m128_i32[1] = 0;
  rayFromWorld[9].mVec128.m128_i8[12] = 1;
  rayFromWorld[10].mVec128.m128_i32[3] = 0;
  rayFromWorld[10].mVec128.m128_i32[1] = 0;
  rayFromWorld[10].mVec128.m128_i32[2] = 0;
  rayFromWorld[11].mVec128.m128_i8[0] = 1;
}
