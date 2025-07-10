void __userpurge btCollisionWorld::serializeCollisionObjects(
        btCollisionWorld *this@<ecx>,
        int a2@<eax>,
        btSerializer *serializer)
{
  int v4; // ebx
  int i; // edi
  bool v6; // cc
  btCollisionShape *v7; // edi
  int Index; // eax
  btCollisionShape *shape; // [esp+Ch] [ebp-64h] BYREF
  btHashPtr key; // [esp+10h] [ebp-60h] BYREF
  btHashPtr v11; // [esp+18h] [ebp-58h] BYREF
  btHashMap<btHashPtr,btCollisionShape *> serializedShapes; // [esp+20h] [ebp-50h] BYREF

  v4 = 0;
  for ( i = 0; i < *(_DWORD *)(a2 + 8); ++i )
  {
    this = *(btCollisionWorld **)(*(_DWORD *)(a2 + 16) + 4 * i);
    if ( this[2].m_dispatchInfo.m_stackAllocator == (btStackAlloc *)1 )
    {
      ((void (__thiscall *)(btCollisionWorld *, btSerializer *))this->debugDrawObject)(this, serializer);
      v4 = 0;
    }
  }
  v6 = *(_DWORD *)(a2 + 8) <= 0;
  serializedShapes.m_hashTable.m_ownsMemory = 1;
  memset(&serializedShapes.m_hashTable.m_size, 0, 12);
  serializedShapes.m_next.m_ownsMemory = 1;
  memset(&serializedShapes.m_next.m_size, 0, 12);
  serializedShapes.m_valueArray.m_ownsMemory = 1;
  memset(&serializedShapes.m_valueArray.m_size, 0, 12);
  serializedShapes.m_keyArray.m_ownsMemory = 1;
  memset(&serializedShapes.m_keyArray.m_size, 0, 12);
  if ( !v6 )
  {
    do
    {
      v7 = *(btCollisionShape **)(*(_DWORD *)(*(_DWORD *)(a2 + 16) + 4 * v4) + 204);
      shape = v7;
      key.m_hashValues[0] = (int)v7;
      Index = btHashMap<btHashPtr,int>::findIndex((btHashMap<btHashPtr,int> *)&serializedShapes, &key);
      if ( Index == -1 || !&serializedShapes.m_valueArray.m_data[Index] )
      {
        v11.m_hashValues[0] = (int)v7;
        btHashMap<btHashPtr,btCollisionShape *>::insert(
          (btHashMap<btHashPtr,int> *)&v11,
          (btHashMap<btHashPtr,int> *)&serializedShapes,
          &v11,
          (int *)&shape);
        shape->serializeSingleShape(shape, serializer);
      }
      ++v4;
    }
    while ( v4 < *(_DWORD *)(a2 + 8) );
  }
  btHashMap<btHashPtr,int>::~btHashMap<btHashPtr,int>(
    (btHashMap<btInternalVertexPair,btInternalEdge> *)this,
    (int)&serializedShapes);
}
