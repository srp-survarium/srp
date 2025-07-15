long double __thiscall btCollisionShape::getAngularMotionDisc(btCollisionShape *this)
{
  float v2; // [esp+Ch] [ebp-14h] BYREF
  float v3; // [esp+10h] [ebp-10h] BYREF
  float v4; // [esp+14h] [ebp-Ch]
  float v5; // [esp+18h] [ebp-8h]

  this->getBoundingSphere(this, (btVector3 *)&v3, &v2);
  return sqrt(v3 * v3 + v5 * v5 + v4 * v4) + v2;
}
