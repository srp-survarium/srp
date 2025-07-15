// attributes: thunk
void __thiscall btBU_Simplex1to4::getAabb(
        btBU_Simplex1to4 *this,
        const btTransform *t,
        btVector3 *aabbMin,
        btVector3 *aabbMax)
{
  btPolyhedralConvexAabbCachingShape::getAabb(this, t, aabbMin, aabbMax);
}
