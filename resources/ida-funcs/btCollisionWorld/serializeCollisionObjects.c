void __userpurge btCollisionWorld::serializeCollisionObjects(
        btCollisionWorld *this@<ecx>,
        int a2@<eax>,
        btSerializer *serializer)
{
  int i; // ebx
  bool v5; // cc
  btCollisionShape *v6; // ebx
  int Index; // eax
  btAlignedObjectArray<GrahamVector2> *v8; // ecx
  btAlignedObjectArray<GrahamVector2> *v9; // ecx
  btAlignedObjectArray<GrahamVector2> *v10; // ecx
  int v11; // [esp+10h] [ebp-68h]
  btCollisionShape *value; // [esp+14h] [ebp-64h] BYREF
  btHashPtr key; // [esp+18h] [ebp-60h] BYREF
  btHashPtr v14; // [esp+20h] [ebp-58h] BYREF
  btHashMap<btHashPtr,btCollisionShape *> v15; // [esp+28h] [ebp-50h] BYREF

  for ( i = 0; i < *(_DWORD *)(a2 + 8); ++i )
  {
    this = *(btCollisionWorld **)(*(_DWORD *)(a2 + 16) + 4 * i);
    if ( this[2].m_dispatchInfo.m_stackAllocator == (btStackAlloc *)1 )
      ((void (__thiscall *)(btCollisionWorld *, btSerializer *))this->debugDrawObject)(this, serializer);
  }
  v5 = *(_DWORD *)(a2 + 8) <= 0;
  v15.m_hashTable.m_ownsMemory = 1;
  memset(&v15.m_hashTable.m_size, 0, 12);
  v15.m_next.m_ownsMemory = 1;
  memset(&v15.m_next.m_size, 0, 12);
  v15.m_valueArray.m_ownsMemory = 1;
  memset(&v15.m_valueArray.m_size, 0, 12);
  v15.m_keyArray.m_ownsMemory = 1;
  memset(&v15.m_keyArray.m_size, 0, 12);
  v11 = 0;
  if ( !v5 )
  {
    do
    {
      v6 = *(btCollisionShape **)(*(_DWORD *)(*(_DWORD *)(a2 + 16) + 4 * v11) + 204);
      value = v6;
      key.m_hashValues[0] = (int)v6;
      Index = btHashMap<btHashPtr,btCollisionShape *>::findIndex(&v15, &key);
      if ( Index == -1 || (this = (btCollisionWorld *)v15.m_valueArray.m_data, !&v15.m_valueArray.m_data[Index]) )
      {
        v14.m_hashValues[0] = (int)v6;
        btHashMap<btHashPtr,btCollisionShape *>::insert(
          (btHashMap<btHashPtr,btCollisionShape *> *)this,
          &v15,
          (const btHashPtr *)v6,
          &v14,
          &value);
        value->serializeSingleShape(value, serializer);
      }
      ++v11;
    }
    while ( v11 < *(_DWORD *)(a2 + 8) );
  }
  btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(
    (btAlignedObjectArray<GrahamVector2> *)this,
    (int)&v15.m_keyArray);
  btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(v8, (int)&v15.m_valueArray);
  btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(v9, (int)&v15.m_next);
  btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(v10, (int)&v15);
}
