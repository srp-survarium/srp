void __userpurge btDiscreteDynamicsWorld::updateActions(
        btDiscreteDynamicsWorld *this@<ecx>,
        int a2@<edi>,
        float timeStep)
{
  btAlignedObjectArray<GrahamVector2> *v3; // ecx
  int i; // esi
  btAlignedObjectArray<int> v5; // [esp+8h] [ebp-14h] BYREF

  btAlignedObjectArray<int>::btAlignedObjectArray<int>(
    (btAlignedObjectArray<int> *)this,
    &v5,
    (const btAlignedObjectArray<int> *)(a2 + 248));
  for ( i = 0; i < v5.m_size; ++i )
    (*(void (__stdcall **)(int, _DWORD))(*(_DWORD *)v5.m_data[i] + 4))(a2, LODWORD(timeStep));
  btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(v3, (int)&v5);
}
