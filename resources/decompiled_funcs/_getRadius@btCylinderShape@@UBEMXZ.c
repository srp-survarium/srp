double __thiscall btCylinderShape::getRadius(btCylinderShape *this)
{
  btVector3 v2; // [esp+10h] [ebp-10h] BYREF

  return btBoxShape::getHalfExtentsWithMargin(this, this, &v2)->mVec128.m128_f32[0];
}
