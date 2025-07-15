void __thiscall btRigidBody::saveKinematicState(btRigidBody *this, float timeStep, float a3)
{
  int v3; // ecx

  if ( a3 != 0.0 )
  {
    v3 = *(_DWORD *)(LODWORD(timeStep) + 500);
    if ( v3 )
      (*(void (__thiscall **)(int, int))(*(_DWORD *)v3 + 4))(v3, LODWORD(timeStep) + 16);
    btTransformUtil::calculateVelocity(
      (const btTransform *)(LODWORD(timeStep) + 80),
      (const btTransform *)(LODWORD(timeStep) + 16),
      a3,
      (btVector3 *)(LODWORD(timeStep) + 320),
      (btVector3 *)(LODWORD(timeStep) + 336));
    *(_DWORD *)(LODWORD(timeStep) + 144) = *(_DWORD *)(LODWORD(timeStep) + 320);
    *(_DWORD *)(LODWORD(timeStep) + 148) = *(_DWORD *)(LODWORD(timeStep) + 324);
    *(_DWORD *)(LODWORD(timeStep) + 152) = *(_DWORD *)(LODWORD(timeStep) + 328);
    *(_DWORD *)(LODWORD(timeStep) + 156) = *(_DWORD *)(LODWORD(timeStep) + 332);
    *(_DWORD *)(LODWORD(timeStep) + 160) = *(_DWORD *)(LODWORD(timeStep) + 336);
    *(_DWORD *)(LODWORD(timeStep) + 164) = *(_DWORD *)(LODWORD(timeStep) + 340);
    *(_DWORD *)(LODWORD(timeStep) + 168) = *(_DWORD *)(LODWORD(timeStep) + 344);
    *(_DWORD *)(LODWORD(timeStep) + 172) = *(_DWORD *)(LODWORD(timeStep) + 348);
    *(_DWORD *)(LODWORD(timeStep) + 80) = *(_DWORD *)(LODWORD(timeStep) + 16);
    *(_DWORD *)(LODWORD(timeStep) + 84) = *(_DWORD *)(LODWORD(timeStep) + 20);
    *(_DWORD *)(LODWORD(timeStep) + 88) = *(_DWORD *)(LODWORD(timeStep) + 24);
    *(_DWORD *)(LODWORD(timeStep) + 92) = *(_DWORD *)(LODWORD(timeStep) + 28);
    *(_DWORD *)(LODWORD(timeStep) + 96) = *(_DWORD *)(LODWORD(timeStep) + 32);
    *(_DWORD *)(LODWORD(timeStep) + 100) = *(_DWORD *)(LODWORD(timeStep) + 36);
    *(_DWORD *)(LODWORD(timeStep) + 104) = *(_DWORD *)(LODWORD(timeStep) + 40);
    *(_DWORD *)(LODWORD(timeStep) + 108) = *(_DWORD *)(LODWORD(timeStep) + 44);
    *(_DWORD *)(LODWORD(timeStep) + 112) = *(_DWORD *)(LODWORD(timeStep) + 48);
    *(_DWORD *)(LODWORD(timeStep) + 116) = *(_DWORD *)(LODWORD(timeStep) + 52);
    *(_DWORD *)(LODWORD(timeStep) + 120) = *(_DWORD *)(LODWORD(timeStep) + 56);
    *(_DWORD *)(LODWORD(timeStep) + 124) = *(_DWORD *)(LODWORD(timeStep) + 60);
    *(_DWORD *)(LODWORD(timeStep) + 128) = *(_DWORD *)(LODWORD(timeStep) + 64);
    *(_DWORD *)(LODWORD(timeStep) + 132) = *(_DWORD *)(LODWORD(timeStep) + 68);
    *(_DWORD *)(LODWORD(timeStep) + 136) = *(_DWORD *)(LODWORD(timeStep) + 72);
    *(_DWORD *)(LODWORD(timeStep) + 140) = *(_DWORD *)(LODWORD(timeStep) + 76);
  }
}
