long double __thiscall btCollisionShape::getAngularMotionDisc(btCollisionShape *this)
{
  long double v1; // st7
  float v3; // [esp+30h] [ebp-14h] BYREF
  float v4; // [esp+34h] [ebp-10h] BYREF
  float v5; // [esp+38h] [ebp-Ch]
  float v6; // [esp+3Ch] [ebp-8h]

  this->getBoundingSphere(this, (btVector3 *)&v4, &v3);
  v1 = sqrtf((float)((float)(v4 * v4) + (float)(v5 * v5)) + (float)(v6 * v6));
  return v1 + v3;
}
