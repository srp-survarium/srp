void __userpurge btRigidBody::saveKinematicState(btRigidBody *this@<ecx>, int a2@<edi>, float timeStep)
{
  int v3; // ecx

  if ( timeStep != 0.0 )
  {
    v3 = *(_DWORD *)(a2 + 500);
    if ( v3 )
      (*(void (__thiscall **)(int, int))(*(_DWORD *)v3 + 4))(v3, a2 + 16);
    btTransformUtil::calculateVelocity(
      (const btTransform *)(a2 + 16),
      (btVector3 *)(a2 + 320),
      (btVector3 *)(a2 + 336),
      (const btTransform *)(a2 + 80),
      timeStep);
    *(_QWORD *)(a2 + 144) = *(_QWORD *)(a2 + 320);
    *(_QWORD *)(a2 + 152) = *(_QWORD *)(a2 + 328);
    *(_QWORD *)(a2 + 160) = *(_QWORD *)(a2 + 336);
    *(_QWORD *)(a2 + 168) = *(_QWORD *)(a2 + 344);
    *(_QWORD *)(a2 + 80) = *(_QWORD *)(a2 + 16);
    *(_QWORD *)(a2 + 88) = *(_QWORD *)(a2 + 24);
    *(_QWORD *)(a2 + 96) = *(_QWORD *)(a2 + 32);
    *(_QWORD *)(a2 + 104) = *(_QWORD *)(a2 + 40);
    *(_QWORD *)(a2 + 112) = *(_QWORD *)(a2 + 48);
    *(_QWORD *)(a2 + 120) = *(_QWORD *)(a2 + 56);
    *(_QWORD *)(a2 + 128) = *(_QWORD *)(a2 + 64);
    *(_QWORD *)(a2 + 136) = *(_QWORD *)(a2 + 72);
  }
}
