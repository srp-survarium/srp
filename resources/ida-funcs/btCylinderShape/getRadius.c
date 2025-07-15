double __thiscall btCylinderShape::getRadius(btCylinderShape *this)
{
  btVector3 v2; // [esp+0h] [ebp-10h] BYREF

  return btBoxShape::getHalfExtentsWithMargin((btBoxShape *)this, (btVector3 *)this, &v2)->mVec128.m128_f32[0];
}
