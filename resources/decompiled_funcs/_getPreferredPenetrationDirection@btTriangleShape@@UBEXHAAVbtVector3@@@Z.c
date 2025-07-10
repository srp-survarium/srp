void __thiscall btTriangleShape::getPreferredPenetrationDirection(
        btTriangleShape *this,
        int index,
        btVector3 *penetrationVector)
{
  btTriangleShape::calcNormal(this, penetrationVector);
  if ( index )
  {
    penetrationVector->mVec128.m128_f32[0] = penetrationVector->mVec128.m128_f32[0] * -1.0;
    penetrationVector->mVec128.m128_f32[1] = penetrationVector->mVec128.m128_f32[1] * -1.0;
    penetrationVector->mVec128.m128_f32[2] = penetrationVector->mVec128.m128_f32[2] * -1.0;
  }
}
