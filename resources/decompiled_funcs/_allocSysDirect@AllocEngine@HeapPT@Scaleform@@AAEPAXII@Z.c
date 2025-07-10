unsigned __int8 *__thiscall Scaleform::HeapPT::AllocEngine::allocSysDirect(
        Scaleform::HeapPT::AllocEngine *this,
        unsigned int dataSize,
        unsigned int alignSize)
{
  unsigned int SysDirectThreshold; // eax
  Scaleform::Heap::HeapSegment *v5; // eax
  unsigned int SysGranularity; // ecx
  unsigned int v7; // ebp
  Scaleform::LockSafe *p_RootLock; // esi
  Scaleform::Heap::HeapSegment *v9; // ebp
  bool limHandlerOK; // [esp+Fh] [ebp-1h] BYREF
  unsigned int dataSizea; // [esp+14h] [ebp+4h]

  SysDirectThreshold = this->SysDirectThreshold;
  limHandlerOK = 0;
  if ( SysDirectThreshold && dataSize >= SysDirectThreshold )
  {
    while ( 1 )
    {
      v5 = Scaleform::HeapPT::AllocEngine::allocSegmentNoGranulator(this, dataSize, alignSize, &limHandlerOK);
      if ( v5 )
        break;
      if ( !limHandlerOK )
        goto LABEL_5;
    }
    this->SysDirectSpace += v5->DataSize;
    return v5->pData;
  }
  else
  {
LABEL_5:
    SysGranularity = this->SysGranularity;
    limHandlerOK = 0;
    v7 = SysGranularity * (((~(alignSize - 1) & (dataSize + alignSize - 1)) + SysGranularity - 1) / SysGranularity);
    for ( dataSizea = v7; ; v7 = dataSizea )
    {
      p_RootLock = &Scaleform::HeapPT::GlobalRoot->RootLock;
      EnterCriticalSection(&Scaleform::HeapPT::GlobalRoot->RootLock.mLock.cs);
      v9 = Scaleform::HeapPT::AllocEngine::allocSegment(this, 9u, v7, alignSize, 0, &limHandlerOK);
      LeaveCriticalSection(&p_RootLock->mLock.cs);
      if ( v9 )
      {
        this->SysDirectSpace += v9->DataSize;
        return v9->pData;
      }
      if ( !limHandlerOK )
        break;
    }
    return 0;
  }
}
