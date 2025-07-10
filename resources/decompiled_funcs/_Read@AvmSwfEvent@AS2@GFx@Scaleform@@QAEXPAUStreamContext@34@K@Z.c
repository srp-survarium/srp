void __thiscall Scaleform::GFx::AS2::AvmSwfEvent::Read(
        Scaleform::GFx::AS2::AvmSwfEvent *this,
        Scaleform::GFx::StreamContext *psc,
        unsigned int flags)
{
  unsigned int CurByteIndex; // ecx
  const unsigned __int8 *pData; // edx
  int v6; // ebp
  int v7; // eax
  unsigned int v8; // ecx
  int v9; // eax
  unsigned int v10; // ebp
  unsigned __int8 v11; // dl
  Scaleform::GFx::AS2::ActionBufferData *v12; // eax
  Scaleform::RefCountVImpl *pObject; // ecx
  unsigned int BufferLen; // eax
  unsigned int v15; // edx
  unsigned int CurBitIndex; // ecx
  unsigned int v17; // eax
  Scaleform::GFx::AS2::ActionBufferData *flagsa; // [esp+2Ch] [ebp+8h]

  this->Event.Id = flags;
  this->Event.WcharCode = 0;
  this->Event.KeyCode = 0;
  this->Event.AsciiCode = 0;
  this->Event.RollOverCnt = 0;
  this->Event.ControllerIndex = -1;
  this->Event.KeysState.States = 0;
  this->Event.MouseWheelDelta = 0;
  if ( psc->CurBitIndex )
    ++psc->CurByteIndex;
  CurByteIndex = psc->CurByteIndex;
  pData = psc->pData;
  psc->CurBitIndex = 0;
  v6 = pData[CurByteIndex];
  v7 = (pData[CurByteIndex + 1] | (*(unsigned __int16 *)&pData[CurByteIndex + 2] << 8)) << 8;
  v8 = CurByteIndex + 4;
  v9 = v6 | v7;
  psc->CurByteIndex = v8;
  v10 = v9;
  if ( ((unsigned int)&loc_20000 & this->Event.Id) != 0 )
  {
    psc->CurBitIndex = 0;
    v11 = pData[v8];
    psc->CurByteIndex = v8 + 1;
    this->Event.KeyCode = v11;
    v10 = v9 - 1;
  }
  v12 = (Scaleform::GFx::AS2::ActionBufferData *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                   Scaleform::Memory::pGlobalHeap,
                                                   24,
                                                   0);
  if ( v12 )
  {
    v12->__vftable = (Scaleform::GFx::AS2::ActionBufferData_vtbl *)&Scaleform::RefCountImplCore::`vftable';
    v12->RefCount = 1;
    v12->__vftable = (Scaleform::GFx::AS2::ActionBufferData_vtbl *)&Scaleform::GFx::AS2::ActionBufferData::`vftable';
    v12->pBuffer = 0;
    v12->BufferLen = 0;
    v12->SwdHandle = 0;
    v12->SWFFileOffset = 0;
    flagsa = v12;
  }
  else
  {
    flagsa = 0;
  }
  pObject = (Scaleform::RefCountVImpl *)this->pActionOpData.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->pActionOpData.pObject = flagsa;
  Scaleform::GFx::AS2::ActionBufferData::Read(flagsa, psc, v10);
  BufferLen = this->pActionOpData.pObject->BufferLen;
  if ( v10 != BufferLen )
  {
    if ( v10 <= BufferLen )
    {
      psc->CurByteIndex += v10 - BufferLen;
    }
    else
    {
      v15 = v10 - BufferLen;
      if ( v10 != BufferLen )
      {
        CurBitIndex = psc->CurBitIndex;
        v17 = psc->CurByteIndex;
        do
        {
          if ( CurBitIndex )
            ++v17;
          CurBitIndex = 0;
          ++v17;
          --v15;
        }
        while ( v15 );
        psc->CurBitIndex = 0;
        psc->CurByteIndex = v17;
      }
    }
  }
}
