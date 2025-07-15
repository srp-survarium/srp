bool __thiscall Scaleform::Render::MatrixPoolImpl::MatrixPool::squeezeMemoryRange(
        Scaleform::Render::MatrixPoolImpl::MatrixPool *this,
        Scaleform::Render::MatrixPoolImpl::DataPage *squeezeStart,
        Scaleform::Render::MatrixPoolImpl::DataPage *squeezeEnd,
        Scaleform::Render::MatrixPoolImpl::MatrixPool::SqueezeType type)
{
  Scaleform::Render::MatrixPoolImpl::MatrixPool *v5; // edx
  bool result; // al
  Scaleform::Render::MatrixPoolImpl::DataPage *v7; // ebx
  Scaleform::Render::MatrixPoolImpl::DataPage *v8; // edi
  unsigned __int16 FreeMiddle; // ax
  int FreeTail; // ecx
  Scaleform::Render::MatrixPoolImpl::DataHeader *v11; // edx
  Scaleform::Render::MatrixPoolImpl::DataPage *v12; // ebp
  unsigned int v13; // ecx
  int v14; // eax
  Scaleform::Render::MatrixPoolImpl::DataPage *pPrev; // ecx
  $863ACD953D7DE0B7EBE039C91E7D8E4F *v16; // eax
  Scaleform::Render::MatrixPoolImpl::DataPage *v17; // ebp
  Scaleform::Render::MatrixPoolImpl::MatrixPool *v18; // eax
  Scaleform::Render::MatrixPoolImpl::DataPage *pLastFreedPage; // edx
  bool freedData; // [esp+Fh] [ebp-15h]
  unsigned int advanceUnitSize; // [esp+14h] [ebp-10h]
  Scaleform::Render::MatrixPoolImpl::DataHeader *sourceEnd; // [esp+18h] [ebp-Ch]
  int v24; // [esp+1Ch] [ebp-8h]
  unsigned __int16 middleFreed; // [esp+20h] [ebp-4h]
  Scaleform::Render::MatrixPoolImpl::DataHeader *destBufferEnd; // [esp+28h] [ebp+4h]

  v5 = this;
  result = 0;
  v7 = 0;
  v8 = 0;
  freedData = 0;
  this->pAllocPage = 0;
  this->pSqueezePage = 0;
  destBufferEnd = 0;
  if ( squeezeStart == squeezeEnd )
    goto LABEL_29;
  while ( 1 )
  {
    FreeMiddle = squeezeStart->FreeMiddle;
    FreeTail = squeezeStart->FreeTail;
    if ( FreeTail + FreeMiddle <= 204 )
    {
      squeezeStart = squeezeStart->pNext;
      goto LABEL_25;
    }
    v11 = (Scaleform::Render::MatrixPoolImpl::DataHeader *)((char *)&squeezeStart[256] - FreeTail);
    v12 = squeezeStart + 1;
    sourceEnd = v11;
    middleFreed = squeezeStart->FreeMiddle;
    if ( v7
      || (v7 = squeezeStart,
          v8 = squeezeStart + 1,
          destBufferEnd = (Scaleform::Render::MatrixPoolImpl::DataHeader *)&squeezeStart[256],
          FreeMiddle) )
    {
      for ( ; v12 != (Scaleform::Render::MatrixPoolImpl::DataPage *)v11; v12 += v13 )
      {
        v13 = BYTE2(v12->pPool);
        advanceUnitSize = v13;
        if ( v12->pNext )
        {
          v14 = 16 * v13;
          v24 = 16 * v13;
          if ( &v8[v13] > (Scaleform::Render::MatrixPoolImpl::DataPage *)destBufferEnd )
          {
            v7->FreeTail = (_WORD)destBufferEnd - (_WORD)v8;
            v7 = squeezeStart;
            v8 = squeezeStart + 1;
            destBufferEnd = (Scaleform::Render::MatrixPoolImpl::DataHeader *)&squeezeStart[256];
          }
          if ( v8 != v12 )
          {
            memmove((unsigned __int8 *)v8, (unsigned __int8 *)v12, 16 * BYTE2(v12->pPool));
            pPrev = v8->pPrev;
            v11 = sourceEnd;
            LOWORD(v8->pPool) = (_WORD)v7 - (_WORD)v8;
            v14 = v24;
            pPrev->pPrev = v8;
          }
          v13 = advanceUnitSize;
          v8 = (Scaleform::Render::MatrixPoolImpl::DataPage *)((char *)v8 + v14);
        }
      }
    }
    else
    {
      v8 = (Scaleform::Render::MatrixPoolImpl::DataPage *)((char *)squeezeStart - FreeTail + 4096);
    }
    v5 = this;
    this->FreedSpace -= squeezeStart->FreeMiddle;
    squeezeStart->FreeMiddle = 0;
    if ( v7 != squeezeStart )
      goto LABEL_22;
    if ( v8 == &v7[1] )
      break;
    if ( middleFreed )
    {
      if ( (char *)destBufferEnd - (char *)v8 >= 1020 )
      {
        freedData = 1;
        if ( type == Squeeze_Incremental )
          goto LABEL_26;
      }
    }
    squeezeStart = squeezeStart->pNext;
LABEL_25:
    if ( squeezeStart == squeezeEnd )
      goto LABEL_26;
  }
  v7 = 0;
LABEL_22:
  v16 = &squeezeStart->4;
  v17 = squeezeStart;
  squeezeStart = squeezeStart->pNext;
  v17->pPrev->pNext = squeezeStart;
  v16->pNext->pPrev = v17->pPrev;
  v18 = this;
  pLastFreedPage = this->pLastFreedPage;
  this->AllocatedSpace -= 4080;
  --this->DataPageCount;
  if ( pLastFreedPage )
  {
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pLastFreedPage);
    v18 = this;
  }
  v5 = this;
  v18->pLastFreedPage = v17;
  freedData = 1;
  if ( type )
    goto LABEL_25;
LABEL_26:
  if ( v7 )
  {
    v7->FreeTail = (_WORD)destBufferEnd - (_WORD)v8;
    result = freedData;
    v5->pAllocPage = v7;
    v5->pSqueezePage = v7;
    return result;
  }
  result = freedData;
LABEL_29:
  v5->pAllocPage = 0;
  if ( squeezeStart != (Scaleform::Render::MatrixPoolImpl::DataPage *)&v5->DataPages )
    v5->pSqueezePage = squeezeStart;
  return result;
}
