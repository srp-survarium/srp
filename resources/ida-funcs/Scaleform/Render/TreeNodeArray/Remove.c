char __thiscall Scaleform::Render::TreeNodeArray::Remove(
        Scaleform::Render::TreeNodeArray *this,
        unsigned int index,
        unsigned int count)
{
  Scaleform::Render::TreeNode *v4; // ecx
  unsigned int v6; // esi
  int v7; // ebx
  unsigned int v8; // ebx
  bool v9; // cf
  Scaleform::Render::TreeNode *v10; // ebp
  unsigned int v11; // eax
  unsigned int v12; // ebx
  unsigned int v13; // eax
  _DWORD *v14; // ecx
  _DWORD *v15; // edx
  int v16; // eax
  unsigned int v17; // [esp+4h] [ebp-4h]

  if ( !count )
    return 1;
  if ( ((int)this->pNodes[0] & 1) == 0 )
  {
    v4 = this->pNodes[1];
    if ( !v4 )
    {
      this->pData[0] = 0;
      return 1;
    }
    if ( count == 2 )
    {
      this->pData[0] = 0;
      this->pData[1] = 0;
      return 1;
    }
    if ( !index )
      this->pData[0] = (unsigned int)v4;
    this->pData[1] = 0;
    return 1;
  }
  v6 = this->pData[0] & 0xFFFFFFFE;
  v7 = *(_DWORD *)(v6 + 4);
  v9 = v7 == count;
  v8 = v7 - count;
  if ( v9 || v8 == 1 )
  {
    if ( v8 == 1 )
    {
      if ( index )
        this->pData[0] = *(_DWORD *)(v6 + 8);
      else
        this->pData[0] = *(_DWORD *)(v6 + 4 * count + 8);
    }
    else
    {
      this->pData[0] = 0;
    }
    this->pData[1] = 0;
    if ( InterlockedExchangeAdd((volatile LONG *)v6, -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v6);
    return 1;
  }
  else
  {
    v10 = this->pNodes[1];
    if ( v10 )
      v11 = Scaleform::Render::TreeNodeArray::calcRemoveCapacity(this, (unsigned int)v10, v8);
    else
      v11 = ((v8 + 1) & 0xFFFFFFFC) + 2;
    v17 = v11;
    if ( (Scaleform::Render::TreeNode *)v11 == v10 )
    {
      if ( index < v8 )
      {
        v14 = (_DWORD *)(v6 + 4 * (count + index) + 8);
        v15 = (_DWORD *)(v6 + 4 * index + 8);
        v16 = v8 - index;
        do
        {
          *v15++ = *v14++;
          --v16;
        }
        while ( v16 );
      }
      *(_DWORD *)(v6 + 4) = v8;
      this->pData[1] = v17;
      return 1;
    }
    else
    {
      v12 = (unsigned int)Scaleform::Render::TreeNodeArray::allocByCapacity(this, v11, v8);
      if ( v12 )
      {
        if ( index )
          memcpy(v12 + 8, (const __m128i *)(v6 + 8), 4 * index);
        v13 = *(_DWORD *)(v6 + 4);
        if ( count + index < v13 )
          memcpy(v12 + 4 * index + 8, (const __m128i *)(v6 + 4 * (count + index) + 8), 4 * (v13 - index - count));
        Scaleform::Render::TreeNodeArray::ArrayData::Release((Scaleform::Render::TreeNodeArray::ArrayData *)v6);
        this->pData[0] = v12 | 1;
        this->pData[1] = v17;
        return 1;
      }
      else
      {
        return 0;
      }
    }
  }
}
