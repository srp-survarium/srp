void __userpurge btGImpactCollisionAlgorithm::shape_vs_shape_collision(
        btGImpactCollisionAlgorithm *this@<ecx>,
        int a2@<eax>,
        btCollisionObject *body0,
        btCollisionObject *body1,
        btCollisionShape *shape0,
        btCollisionShape *shape1)
{
  int v8; // edi
  btCollisionShape *v9; // [esp+Ch] [ebp-4h]
  btCollisionShape *m_collisionShape; // [esp+1Ch] [ebp+Ch]

  m_collisionShape = body0->m_collisionShape;
  v9 = body1->m_collisionShape;
  body0->m_collisionShape = shape0;
  body1->m_collisionShape = shape1;
  if ( !*(_DWORD *)(a2 + 12) )
    *(_DWORD *)(a2 + 12) = (*(int (__thiscall **)(_DWORD, btCollisionObject *, btCollisionObject *))(**(_DWORD **)(a2 + 4) + 8))(
                             *(_DWORD *)(a2 + 4),
                             body0,
                             body1);
  *(_DWORD *)(*(_DWORD *)(a2 + 16) + 4) = *(_DWORD *)(a2 + 12);
  v8 = (*(int (__thiscall **)(_DWORD, btCollisionObject *, btCollisionObject *, _DWORD))(**(_DWORD **)(a2 + 4) + 4))(
         *(_DWORD *)(a2 + 4),
         body0,
         body1,
         *(_DWORD *)(a2 + 12));
  (*(void (__thiscall **)(_DWORD, _DWORD, _DWORD))(**(_DWORD **)(a2 + 16) + 4))(
    *(_DWORD *)(a2 + 16),
    *(_DWORD *)(a2 + 28),
    *(_DWORD *)(a2 + 24));
  (*(void (__thiscall **)(_DWORD, _DWORD, _DWORD))(**(_DWORD **)(a2 + 16) + 8))(
    *(_DWORD *)(a2 + 16),
    *(_DWORD *)(a2 + 36),
    *(_DWORD *)(a2 + 32));
  (*(void (__thiscall **)(int, btCollisionObject *, btCollisionObject *, _DWORD, _DWORD))(*(_DWORD *)v8 + 4))(
    v8,
    body0,
    body1,
    *(_DWORD *)(a2 + 20),
    *(_DWORD *)(a2 + 16));
  (**(void (__thiscall ***)(int, _DWORD))v8)(v8, 0);
  (*(void (__thiscall **)(_DWORD, int))(**(_DWORD **)(a2 + 4) + 56))(*(_DWORD *)(a2 + 4), v8);
  body0->m_collisionShape = m_collisionShape;
  body1->m_collisionShape = v9;
}
