void __usercall btSoftRigidDynamicsWorld::debugDrawWorld(btSoftRigidDynamicsWorld *this@<ecx>, double a2@<st1>)
{
  __int64 v2; // rdi
  float v3; // ebx
  int v4; // eax

  HIDWORD(v2) = this;
  btDiscreteDynamicsWorld::debugDrawWorld(this, a2);
  if ( (*(int (__thiscall **)(_DWORD))(*(_DWORD *)HIDWORD(v2) + 12))(HIDWORD(v2)) )
  {
    v3 = 0.0;
    if ( *(int *)(HIDWORD(v2) + 276) > 0 )
    {
      do
      {
        LODWORD(v2) = *(_DWORD *)(*(_DWORD *)(HIDWORD(v2) + 284) + 4 * LODWORD(v3));
        if ( (*(int (__thiscall **)(_DWORD))(*(_DWORD *)HIDWORD(v2) + 12))(HIDWORD(v2)) )
        {
          v4 = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)HIDWORD(v2) + 12))(HIDWORD(v2));
          if ( ((*(int (__thiscall **)(int))(*(_DWORD *)v4 + 48))(v4) & 1) != 0 )
          {
            btSoftBodyHelpers::DrawFrame(*(btIDebugDraw **)(HIDWORD(v2) + 80), (btSoftBody *)v2);
            btSoftBodyHelpers::Draw(
              *(btIDebugDraw **)(HIDWORD(v2) + 80),
              v3,
              v2,
              (btSoftBody *)v2,
              *(_DWORD *)(HIDWORD(v2) + 292));
          }
        }
        if ( *(_DWORD *)(HIDWORD(v2) + 80)
          && ((*(int (__thiscall **)(_DWORD))(**(_DWORD **)(HIDWORD(v2) + 80) + 48))(*(_DWORD *)(HIDWORD(v2) + 80)) & 2) != 0 )
        {
          if ( *(_BYTE *)(HIDWORD(v2) + 296) )
            btSoftBodyHelpers::DrawNodeTree((btSoftBody *)v2, *(btIDebugDraw **)(HIDWORD(v2) + 80));
          if ( *(_BYTE *)(HIDWORD(v2) + 297) )
            btSoftBodyHelpers::DrawFaceTree((btSoftBody *)v2, *(btIDebugDraw **)(HIDWORD(v2) + 80));
          if ( *(_BYTE *)(HIDWORD(v2) + 298) )
            btSoftBodyHelpers::DrawClusterTree((btSoftBody *)v2, *(btIDebugDraw **)(HIDWORD(v2) + 80));
        }
        ++LODWORD(v3);
      }
      while ( SLODWORD(v3) < *(_DWORD *)(HIDWORD(v2) + 276) );
    }
  }
}
