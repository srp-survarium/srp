void __thiscall Scaleform::GFx::AS2::ActionBufferData::Read(
        Scaleform::GFx::AS2::ActionBufferData *this,
        Scaleform::GFx::StreamContext *psc,
        unsigned int eventLength)
{
  unsigned __int8 *v4; // eax
  bool v5; // zf

  if ( psc->CurBitIndex )
    ++psc->CurByteIndex;
  psc->CurBitIndex = 0;
  v4 = (unsigned __int8 *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                            Scaleform::Memory::pGlobalHeap,
                            this,
                            eventLength,
                            0);
  this->pBuffer = v4;
  memcpy(v4, (unsigned __int8 *)&psc->pData[psc->CurByteIndex], eventLength);
  this->BufferLen = eventLength;
  v5 = psc->CurBitIndex == 0;
  psc->CurBitIndex = 0;
  if ( !v5 )
    ++psc->CurByteIndex;
  psc->CurByteIndex += eventLength;
}
