void __thiscall btRigidBody::internalWritebackVelocity(btRigidBody *this, char *timeStep, float a3)
{
  long double v3; // rdi
  btVector3 v4; // [esp+18h] [ebp-50h] BYREF
  btTransform v5; // [esp+28h] [ebp-40h] BYREF

  if ( *((float *)timeStep + 88) != 0.0 )
  {
    v4.mVec128.m128_f32[0] = *((float *)timeStep + 80) + *((float *)timeStep + 136);
    v4.mVec128.m128_f32[1] = *((float *)timeStep + 81) + *((float *)timeStep + 137);
    v4.mVec128.m128_f32[2] = *((float *)timeStep + 82) + *((float *)timeStep + 138);
    v4.mVec128.m128_i32[3] = 0;
    *((btVector3 *)timeStep + 20) = (btVector3)v4.mVec128;
    HIDWORD(v3) = &v5;
    LODWORD(v3) = timeStep + 336;
    v4.mVec128.m128_f32[0] = *((float *)timeStep + 140) + *((float *)timeStep + 84);
    v4.mVec128.m128_f32[1] = *((float *)timeStep + 141) + *((float *)timeStep + 85);
    v4.mVec128.m128_f32[2] = *((float *)timeStep + 142) + *((float *)timeStep + 86);
    v4.mVec128.m128_i32[3] = 0;
    btRigidBody::setAngularVelocity((btRigidBody *)timeStep, &v4);
    btTransformUtil::integrateTransform(
      (const btVector3 *)timeStep + 38,
      v3,
      (const btTransform *)(timeStep + 16),
      (const btVector3 *)timeStep + 39,
      a3,
      &v5);
    btCollisionObject::setWorldTransform((btCollisionObject *)&v5, (btVector3 *)timeStep);
  }
}
