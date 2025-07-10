const char *__userpurge btCompoundShape::serialize@<eax>(
        btCompoundShape *this@<ecx>,
        int a2@<esi>,
        float *dataBuffer,
        btSerializer *serializer)
{
  btCompoundShape *v4; // ebp
  int m_size; // eax
  int v6; // eax
  int v7; // esi
  void *v8; // eax
  bool v9; // cc
  int v10; // ebx
  btCollisionShape *m_childShape; // ecx
  btSerializer_vtbl *v12; // ebp
  int v13; // eax
  int v14; // eax
  btCollisionShape *v15; // ecx
  const char *v16; // eax
  float *v17; // ecx
  int v18; // eax
  bool v19; // zf
  int i; // [esp+38h] [ebp-10h]
  int v22; // [esp+3Ch] [ebp-Ch]
  btCompoundShape *v23; // [esp+40h] [ebp-8h]
  int retaddr; // [esp+48h] [ebp+0h]
  btChunk *v25; // [esp+54h] [ebp+Ch]
  float *v26; // [esp+54h] [ebp+Ch]

  v4 = this;
  btCollisionShape::serialize(this, dataBuffer, serializer);
  dataBuffer[5] = v4->m_collisionMargin;
  m_size = v4->m_children.m_size;
  *((_DWORD *)dataBuffer + 4) = m_size;
  dataBuffer[3] = 0.0;
  if ( m_size )
  {
    v6 = ((int (__thiscall *)(btSerializer *, int, int, int))serializer->allocate)(serializer, 76, m_size, a2);
    v7 = *(_DWORD *)(v6 + 8);
    retaddr = v6;
    v8 = serializer->getUniquePointer(serializer, v7);
    v9 = *((_DWORD *)dataBuffer + 4) <= 0;
    *((_DWORD *)dataBuffer + 3) = v8;
    v22 = 0;
    if ( !v9 )
    {
      v10 = 0;
      do
      {
        *(float *)(v7 + 72) = v4->m_children.m_data[v10].m_childMargin;
        *(_DWORD *)(v7 + 64) = serializer->getUniquePointer(serializer, v4->m_children.m_data[v10].m_childShape);
        if ( !serializer->findPointer(serializer, v4->m_children.m_data[v10].m_childShape) )
        {
          m_childShape = v4->m_children.m_data[v10].m_childShape;
          v12 = serializer->__vftable;
          v13 = ((int (__thiscall *)(btCollisionShape *, int))m_childShape->calculateSerializeBufferSize)(
                  m_childShape,
                  1);
          v14 = ((int (__thiscall *)(btSerializer *, int))v12->allocate)(serializer, v13);
          v4 = v23;
          v15 = v23->m_children.m_data[v10].m_childShape;
          v25 = (btChunk *)v14;
          v16 = v15->serialize(v15, *(void **)(v14 + 8), serializer);
          serializer->finalizeChunk(serializer, v25, v16, 1346455635, (void *)v23->m_children.m_data[v10].m_childShape);
        }
        *(_DWORD *)(v7 + 68) = v4->m_children.m_data[v10].m_childShapeType;
        v17 = (float *)&v4->m_children.m_data[v10];
        v26 = v17 + 3;
        v18 = v7 + 4;
        i = 3;
        do
        {
          *(float *)(v18 - 4) = *(v26 - 3);
          v18 += 16;
          *(float *)(v18 - 16) = *(float *)((char *)v17 + v18 - v7 - 16);
          v19 = i-- == 1;
          *(float *)(v18 - 12) = *(v26 - 1);
          v26 += 4;
          *(float *)(v18 - 8) = *(v26 - 4);
        }
        while ( !v19 );
        *(float *)(v7 + 48) = v17[12];
        ++v10;
        *(float *)(v7 + 52) = v17[13];
        v7 += 76;
        ++v22;
        *(float *)(v7 - 20) = v17[14];
        *(float *)(v7 - 16) = v17[15];
      }
      while ( v22 < (int)serializer[4].__vftable );
    }
    ((void (__thiscall *)(btSerializer *, int, const char *, int))serializer->finalizeChunk)(
      serializer,
      retaddr,
      "btCompoundShapeChildData",
      1497453121);
  }
  return "btCompoundShapeData";
}
