char __thiscall Scaleform::Render::TreeNodeArray::Insert(
        Scaleform::Render::TreeNodeArray *this,
        unsigned int index,
        Scaleform::Render::TreeNode *node)
{
  unsigned int v4; // ebx
  unsigned int v6; // eax
  unsigned int v7; // ebx
  unsigned int v8; // eax
  _DWORD *v9; // ecx
  int v10; // eax
  unsigned int v11; // ebp
  unsigned int v12; // edi
  unsigned int v13; // eax
  unsigned int v14; // ecx

  v4 = this->pData[0];
  if ( !this->pData[0] )
  {
    this->pData[0] = (unsigned int)node;
    return 1;
  }
  if ( (v4 & 1) == 0 )
  {
    if ( !this->pData[1] )
    {
      if ( !index )
        this->pData[1] = v4;
      this->pData[index] = (unsigned int)node;
      return 1;
    }
    v6 = (unsigned int)Scaleform::Render::TreeNodeArray::allocByCapacity(this, 6u, 3u);
    if ( !v6 )
      return 0;
    if ( index )
    {
      if ( index != 1 )
      {
        if ( index == 2 )
        {
          *(_DWORD *)(v6 + 8) = this->pData[0];
          *(_DWORD *)(v6 + 12) = this->pNodes[1];
        }
        goto LABEL_17;
      }
      *(_DWORD *)(v6 + 8) = this->pData[0];
    }
    else
    {
      *(_DWORD *)(v6 + 12) = this->pData[0];
    }
    *(_DWORD *)(v6 + 16) = this->pNodes[1];
LABEL_17:
    *(_DWORD *)(v6 + 4 * index + 8) = node;
    this->pData[0] = v6 | 1;
    this->pData[1] = 6;
    return 1;
  }
  v7 = v4 & 0xFFFFFFFE;
  v8 = *(_DWORD *)(v7 + 4);
  if ( v8 + 1 > this->pData[1] )
  {
    v11 = (((v8 >> 1) + v8 + 1) & 0xFFFFFFFC) + 2;
    v12 = (unsigned int)Scaleform::Render::TreeNodeArray::allocByCapacity(this, v11, v8 + 1);
    if ( v12 )
    {
      v13 = index;
      if ( index )
      {
        memcpy(v12 + 8, (const __m128i *)(v7 + 8), 4 * index);
        v13 = index;
      }
      *(_DWORD *)(v12 + 4 * v13 + 8) = node;
      v14 = *(_DWORD *)(v7 + 4);
      if ( v13 < v14 )
        memcpy(v12 + 4 * v13 + 12, (const __m128i *)(v7 + 4 * v13 + 8), 4 * (v14 - v13));
      Scaleform::Render::TreeNodeArray::ArrayData::Release((Scaleform::Render::TreeNodeArray::ArrayData *)v7);
      this->pData[0] = v12 | 1;
      this->pData[1] = v11;
      return 1;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    if ( v8 > index )
    {
      v9 = (_DWORD *)(v7 + 4 * v8 + 8);
      v10 = v8 - index;
      do
      {
        *v9 = *(v9 - 1);
        --v9;
        --v10;
      }
      while ( v10 );
    }
    *(_DWORD *)(v7 + 4 * index + 8) = node;
    ++*(_DWORD *)(v7 + 4);
    return 1;
  }
}
