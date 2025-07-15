void __thiscall Scaleform::Render::BitSet::resize(Scaleform::Render::BitSet *this, unsigned int newSize)
{
  unsigned int v3; // ebx
  unsigned int v4; // esi
  Scaleform::Render::BitSet *pData; // eax
  Scaleform::MemoryHeap *pHeap; // ecx
  unsigned int *v7; // eax
  unsigned int Local; // ecx

  v3 = (this->Size + 31) >> 5;
  v4 = (newSize + 31) >> 5;
  if ( v4 < 2 * v3 )
    v4 = 2 * v3;
  if ( v4 > v3 )
  {
    pData = (Scaleform::Render::BitSet *)this->pData;
    pHeap = this->pHeap;
    if ( pData == (Scaleform::Render::BitSet *)&this->Local )
    {
      v7 = (unsigned int *)pHeap->Alloc(pHeap, 4 * v4, 0);
      Local = this->Local;
      this->pData = v7;
      *v7 = Local;
    }
    else
    {
      this->pData = (unsigned int *)pHeap->Realloc(pHeap, pData, 4 * v4);
    }
    memset((int)&this->pData[v3], 0, 4 * (v4 - v3));
    this->Size = 32 * v4;
  }
}
