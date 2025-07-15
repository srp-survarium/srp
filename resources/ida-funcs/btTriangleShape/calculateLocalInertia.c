void __thiscall btTriangleShape::calculateLocalInertia(btTriangleMeshShape *this, float mass, btVector3 *inertia)
{
  inertia->mVec128.m128_u64[0] = 0;
  inertia->mVec128.m128_u64[1] = 0;
}
