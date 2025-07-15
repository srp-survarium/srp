const char *__thiscall btCompoundShape::serialize(btCompoundShape *this, float *dataBuffer, btSerializer *serializer)
{
  int m_size; // eax
  void *v6; // eax
  bool v7; // cc
  int v8; // ebx
  btCollisionShape *m_childShape; // ecx
  int v10; // eax
  int v11; // eax
  btCollisionShape *v12; // ecx
  const char *v13; // eax
  char *v14; // eax
  float *v15; // edx
  int v16; // ecx
  float *v17; // ecx
  int v18; // edx
  btChunk *v20; // [esp+Ch] [ebp-Ch]
  btChunk *(__thiscall **p_allocate)(btSerializer *, unsigned int, int); // [esp+10h] [ebp-8h]
  btChunk *v22; // [esp+10h] [ebp-8h]
  int v23; // [esp+10h] [ebp-8h]
  int v24; // [esp+14h] [ebp-4h]
  btSerializer *serializera; // [esp+24h] [ebp+Ch]

  btCollisionShape::serialize(this, dataBuffer, serializer);
  dataBuffer[5] = this->m_collisionMargin;
  m_size = this->m_children.m_size;
  dataBuffer[3] = 0.0;
  *((_DWORD *)dataBuffer + 4) = m_size;
  if ( m_size )
  {
    v20 = serializer->allocate(serializer, 76, m_size);
    serializera = (btSerializer *)v20->m_oldPtr;
    v6 = serializer->getUniquePointer(serializer, serializera);
    v24 = 0;
    v7 = *((_DWORD *)dataBuffer + 4) <= 0;
    *((_DWORD *)dataBuffer + 3) = v6;
    if ( !v7 )
    {
      v8 = 0;
      do
      {
        serializera[18].__vftable = (btSerializer_vtbl *)LODWORD(this->m_children.m_data[v8].m_childMargin);
        serializera[16].__vftable = (btSerializer_vtbl *)serializer->getUniquePointer(
                                                           serializer,
                                                           this->m_children.m_data[v8].m_childShape);
        if ( !serializer->findPointer(serializer, this->m_children.m_data[v8].m_childShape) )
        {
          m_childShape = this->m_children.m_data[v8].m_childShape;
          p_allocate = &serializer->allocate;
          v10 = ((int (__thiscall *)(btCollisionShape *, int))m_childShape->calculateSerializeBufferSize)(
                  m_childShape,
                  1);
          v11 = ((int (__thiscall *)(btSerializer *, int))*p_allocate)(serializer, v10);
          v12 = this->m_children.m_data[v8].m_childShape;
          v22 = (btChunk *)v11;
          v13 = v12->serialize(v12, *(void **)(v11 + 8), serializer);
          serializer->finalizeChunk(serializer, v22, v13, 1346455635, this->m_children.m_data[v8].m_childShape);
        }
        serializera[17].__vftable = (btSerializer_vtbl *)this->m_children.m_data[v8].m_childShapeType;
        v14 = (char *)((char *)&this->m_children.m_data[v8] - (char *)serializera);
        v15 = (float *)serializera;
        v23 = 3;
        do
        {
          v16 = 4;
          do
          {
            *v15 = *(float *)((char *)v15 + (_DWORD)v14);
            ++v15;
            --v16;
          }
          while ( v16 );
          --v23;
        }
        while ( v23 );
        v17 = (float *)&serializera[12];
        v18 = 4;
        do
        {
          *v17 = *(float *)&v14[(_DWORD)v17];
          ++v17;
          --v18;
        }
        while ( v18 );
        ++v24;
        serializera += 19;
        ++v8;
      }
      while ( v24 < *((_DWORD *)dataBuffer + 4) );
    }
    serializer->finalizeChunk(serializer, v20, "btCompoundShapeChildData", 1497453121, v20->m_oldPtr);
  }
  return "btCompoundShapeData";
}
