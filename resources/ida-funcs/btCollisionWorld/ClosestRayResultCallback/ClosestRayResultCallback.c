void __thiscall btCollisionWorld::ClosestRayResultCallback::ClosestRayResultCallback(
        btCollisionWorld::ClosestRayResultCallback *this,
        const btVector3 *rayFromWorld,
        const btVector3 *rayToWorld,
        const btVector3 *a4)
{
  btCollisionWorld::RayResultCallback::RayResultCallback(this, (int)rayFromWorld);
  rayFromWorld->mVec128.m128_i32[0] = (int)&btCollisionWorld::ClosestRayResultCallback::`vftable';
  rayFromWorld[2] = (const btVector3)rayToWorld->mVec128;
  rayFromWorld[3] = (const btVector3)a4->mVec128;
}
