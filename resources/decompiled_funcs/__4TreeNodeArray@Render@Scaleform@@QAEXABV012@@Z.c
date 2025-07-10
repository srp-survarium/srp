void __thiscall Scaleform::Render::TreeNodeArray::operator=(
        Scaleform::Render::TreeNodeArray *this,
        const Scaleform::Render::TreeNodeArray *src)
{
  Scaleform::Render::TreeNode *v2; // ebp
  unsigned int v4; // ebx
  void *v5; // ebx
  unsigned int v6; // ecx

  v2 = src->pNodes[1];
  v4 = this->pData[0];
  if ( ((int)src->pNodes[0] & 1) != 0 )
  {
    InterlockedExchangeAdd((volatile LONG *)(src->pData[0] & 0xFFFFFFFE), 1);
    v2 = 0;
  }
  if ( (v4 & 1) != 0 )
  {
    v5 = (void *)(v4 & 0xFFFFFFFE);
    if ( InterlockedExchangeAdd((volatile LONG *)v5, -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v5);
  }
  v6 = src->pData[0];
  this->pData[1] = (unsigned int)v2;
  this->pData[0] = v6;
}
