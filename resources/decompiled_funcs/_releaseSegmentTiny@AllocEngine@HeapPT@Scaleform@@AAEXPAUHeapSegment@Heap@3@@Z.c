void __thiscall Scaleform::HeapPT::AllocEngine::releaseSegmentTiny(
        Scaleform::HeapPT::AllocEngine *this,
        Scaleform::Heap::HeapSegment *seg)
{
  unsigned int v3; // esi
  unsigned __int8 *pData; // ecx
  unsigned int i; // eax
  _DWORD *v6; // edx
  int v7; // ebp

  v3 = (seg->SegType + 1) << this->MinAlignShift;
  pData = seg->pData;
  for ( i = seg->DataSize / v3; i; *v6 = v7 )
  {
    *(_DWORD *)(*(_DWORD *)pData + 4) = *((_DWORD *)pData + 1);
    v6 = (_DWORD *)*((_DWORD *)pData + 1);
    v7 = *(_DWORD *)pData;
    pData += v3;
    --i;
  }
  this->TinyFreeSpace -= seg->DataSize;
  Scaleform::HeapPT::AllocEngine::freeSegment(this, seg);
}
