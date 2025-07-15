void __thiscall btSphereShape::calculateLocalInertia(btSphereShape *this, float mass, btVector3 *inertia)
{
  double v4; // st7
  double v5; // st7
  float v6; // [esp+4h] [ebp-4h]

  v6 = this->getMargin(this);
  v4 = ((double (__thiscall *)(btSphereShape *))this->getMargin)(this);
  inertia->mVec128.m128_i32[3] = 0;
  v5 = v4 * v6 * mass * 0.40000001;
  inertia->mVec128.m128_f32[0] = v5;
  inertia->mVec128.m128_f32[1] = v5;
  inertia->mVec128.m128_f32[2] = v5;
}
