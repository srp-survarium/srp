Scaleform::StringLH *__thiscall Scaleform::GFx::LoadProcess::AllocMovieDefClass<Scaleform::GFx::ImportData>(
        Scaleform::GFx::LoadProcess *this)
{
  Scaleform::GFx::MovieDataDef::LoadTaskData *pObject; // ecx
  unsigned int BytesLeft; // eax
  Scaleform::GFx::DataAllocator *p_TagMemAllocator; // ecx
  Scaleform::StringLH *pCurrent; // esi

  pObject = this->pLoadData.pObject;
  BytesLeft = pObject->TagMemAllocator.BytesLeft;
  p_TagMemAllocator = &pObject->TagMemAllocator;
  if ( BytesLeft < 0x1C )
  {
    pCurrent = (Scaleform::StringLH *)Scaleform::GFx::DataAllocator::OverflowAlloc(p_TagMemAllocator, 0x1Cu);
  }
  else
  {
    pCurrent = (Scaleform::StringLH *)p_TagMemAllocator->pCurrent;
    p_TagMemAllocator->pCurrent += 28;
    p_TagMemAllocator->BytesLeft = BytesLeft - 28;
  }
  if ( !pCurrent )
    return 0;
  pCurrent->HeapTypeBits = 0;
  pCurrent[1].HeapTypeBits = 0;
  pCurrent[2].HeapTypeBits = 0;
  Scaleform::StringLH::StringLH(pCurrent + 3);
  pCurrent[4].HeapTypeBits = 0;
  pCurrent[5].HeapTypeBits = 0;
  pCurrent[6].HeapTypeBits = 0;
  return pCurrent;
}
