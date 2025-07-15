unsigned __int8 *__thiscall Scaleform::HeapPT::AllocEngine::allocSegmentTiny(
        Scaleform::HeapPT::AllocEngine *this,
        unsigned int sizeIdx)
{
  unsigned int v3; // ebp
  unsigned int v4; // edi
  int v5; // eax
  Scaleform::Heap::HeapSegment *v6; // eax
  Scaleform::Heap::HeapSegment *v7; // esi
  int v8; // eax
  Scaleform::HeapPT::AllocEngine::TinyBlock *pData; // ecx
  Scaleform::List<Scaleform::HeapPT::AllocEngine::TinyBlock,Scaleform::HeapPT::AllocEngine::TinyBlock> *i; // edx
  unsigned __int8 *v11; // esi
  Scaleform::LockSafe *lpCriticalSection; // [esp+10h] [ebp-4h]

  lpCriticalSection = &Scaleform::HeapPT::GlobalRoot->RootLock;
  EnterCriticalSection(&Scaleform::HeapPT::GlobalRoot->RootLock.mLock.cs);
  v3 = sizeIdx;
  v4 = (sizeIdx + 1) << this->MinAlignShift;
  v5 = 4 * v4;
  if ( 4 * v4 <= 0x1000 )
    v5 = 4096;
  v6 = Scaleform::HeapPT::AllocEngine::allocSegment(
         this,
         sizeIdx,
         (v5 + 4095) & 0xFFFFF000,
         0x1000u,
         0,
         (bool *)&sizeIdx);
  v7 = v6;
  if ( v6 )
  {
    v8 = v6->DataSize / v4;
    pData = (Scaleform::HeapPT::AllocEngine::TinyBlock *)v7->pData;
    for ( i = &this->TinyBlocks[v3]; v8; --v8 )
    {
      pData->pSegment = v7;
      pData->pPrev = i->Root.pPrev;
      pData->pNext = (Scaleform::HeapPT::AllocEngine::TinyBlock *)i;
      i->Root.pPrev->pNext = pData;
      i->Root.pPrev = pData;
      pData = (Scaleform::HeapPT::AllocEngine::TinyBlock *)((char *)pData + v4);
    }
    this->TinyFreeSpace += v7->DataSize;
    v11 = v7->pData;
    LeaveCriticalSection(&lpCriticalSection->mLock.cs);
    return v11;
  }
  else
  {
    LeaveCriticalSection(&lpCriticalSection->mLock.cs);
    return 0;
  }
}
