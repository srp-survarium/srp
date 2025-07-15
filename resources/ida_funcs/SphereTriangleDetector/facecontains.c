bool __userpurge SphereTriangleDetector::facecontains@<al>(
        const btVector3 *p@<ecx>,
        btVector3 *normal@<eax>,
        SphereTriangleDetector *this,
        const btVector3 *vertices)
{
  btVector3 v5; // [esp+30h] [ebp-20h] BYREF
  btVector3 v6; // [esp+40h] [ebp-10h] BYREF

  v5.mVec128 = p->mVec128;
  v6.mVec128 = normal->mVec128;
  return SphereTriangleDetector::pointInTriangle(&v6, &v5, this, (const btVector3 *)v5.mVec128.m128_i32[0]);
}
