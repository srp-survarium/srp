void __thiscall btDiscreteDynamicsWorld::predictUnconstraintMotion(btDiscreteDynamicsWorld *this, float timeStep)
{
  long double v2; // rdi
  int i; // ebx
  int v4; // eax
  btRigidBody *v5; // ecx

  LODWORD(v2) = this;
  for ( i = 0; i < *(_DWORD *)(LODWORD(v2) + 208); ++i )
  {
    v4 = *(_DWORD *)(LODWORD(v2) + 216);
    HIDWORD(v2) = *(_DWORD *)(v4 + 4 * i);
    if ( (*(_BYTE *)(HIDWORD(v2) + 216) & 3) == 0 )
    {
      btRigidBody::integrateVelocities((btRigidBody *)this, *(_DWORD *)(v4 + 4 * i), timeStep);
      btRigidBody::applyDamping(v5, timeStep);
      btRigidBody::predictIntegratedTransform(
        (btRigidBody *)HIDWORD(v2),
        v2,
        timeStep,
        (btTransform *)(HIDWORD(v2) + 80));
    }
  }
}
