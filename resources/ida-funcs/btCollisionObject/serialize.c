const char *__thiscall btCollisionObject::serialize(
        btCollisionObject *this,
        _BYTE *dataBuffer,
        btSerializer *serializer)
{
  float *v5; // eax
  int v6; // edx
  int v7; // ebx
  float *v8; // eax
  int v9; // ebx
  int v10; // eax
  float *v11; // ebx
  bool v12; // zf
  float *v13; // edx
  int v14; // ebx
  float *v15; // eax
  int v16; // edx
  int v17; // ebx
  float *v18; // eax
  int v19; // ebx
  float *v20; // eax
  int v21; // ebx
  double m_contactProcessingThreshold; // st7
  void *v24; // eax
  void *v25; // eax
  int v27; // [esp+Ch] [ebp-8h]
  int v28; // [esp+10h] [ebp-4h]
  int v29; // [esp+1Ch] [ebp+8h]
  float *v30; // [esp+1Ch] [ebp+8h]
  const char *v31; // [esp+1Ch] [ebp+8h]

  v5 = (float *)(dataBuffer + 16);
  v6 = (char *)this - dataBuffer;
  v29 = 3;
  do
  {
    v7 = 4;
    do
    {
      *v5 = *(float *)((char *)v5 + v6);
      ++v5;
      --v7;
    }
    while ( v7 );
    --v29;
  }
  while ( v29 );
  v8 = (float *)(dataBuffer + 64);
  v9 = 4;
  do
  {
    *v8 = *(float *)((char *)v8 + v6);
    ++v8;
    --v9;
  }
  while ( v9 );
  v10 = (char *)this - dataBuffer;
  v30 = (float *)(dataBuffer + 80);
  v27 = 3;
  do
  {
    v28 = 4;
    do
    {
      *v30 = *(float *)((char *)v30 + v10);
      v11 = v30 + 1;
      v12 = v28-- == 1;
      ++v30;
    }
    while ( !v12 );
    v12 = v27-- == 1;
    v30 = v11;
  }
  while ( !v12 );
  v13 = (float *)(dataBuffer + 128);
  v14 = 4;
  do
  {
    *v13 = *(float *)((char *)v13 + v10);
    ++v13;
    --v14;
  }
  while ( v14 );
  v15 = (float *)(dataBuffer + 144);
  v16 = (char *)this - dataBuffer;
  v17 = 4;
  do
  {
    *v15 = *(float *)((char *)v15 + v16);
    ++v15;
    --v17;
  }
  while ( v17 );
  v18 = (float *)(dataBuffer + 160);
  v19 = 4;
  do
  {
    *v18 = *(float *)((char *)v18 + v16);
    ++v18;
    --v19;
  }
  while ( v19 );
  v20 = (float *)(dataBuffer + 176);
  v21 = 4;
  do
  {
    *v20 = *(float *)((char *)v20 + v16);
    ++v20;
    --v21;
  }
  while ( v21 );
  *((_DWORD *)dataBuffer + 55) = this->m_hasAnisotropicFriction;
  m_contactProcessingThreshold = this->m_contactProcessingThreshold;
  *(_DWORD *)dataBuffer = 0;
  *((float *)dataBuffer + 48) = m_contactProcessingThreshold;
  v24 = serializer->getUniquePointer(serializer, this->m_collisionShape);
  *((_DWORD *)dataBuffer + 2) = 0;
  *((_DWORD *)dataBuffer + 1) = v24;
  *((_DWORD *)dataBuffer + 56) = this->m_collisionFlags;
  *((_DWORD *)dataBuffer + 57) = this->m_islandTag1;
  *((_DWORD *)dataBuffer + 58) = this->m_companionId;
  *((_DWORD *)dataBuffer + 59) = this->m_activationState1;
  *((_DWORD *)dataBuffer + 59) = this->m_activationState1;
  *((float *)dataBuffer + 49) = this->m_deactivationTime;
  *((float *)dataBuffer + 50) = this->m_friction;
  *((float *)dataBuffer + 51) = this->m_restitution;
  *((_DWORD *)dataBuffer + 60) = this->m_internalType;
  v31 = serializer->findNameForPointer(serializer, this);
  v25 = serializer->getUniquePointer(serializer, v31);
  *((_DWORD *)dataBuffer + 3) = v25;
  if ( v25 )
    serializer->serializeName(serializer, v31);
  *((float *)dataBuffer + 52) = this->m_hitFraction;
  *((float *)dataBuffer + 53) = this->m_ccdSweptSphereRadius;
  *((float *)dataBuffer + 54) = this->m_ccdMotionThreshold;
  *((float *)dataBuffer + 54) = this->m_ccdMotionThreshold;
  *((_DWORD *)dataBuffer + 61) = this->m_checkCollideWith;
  return "btCollisionObjectFloatData";
}
