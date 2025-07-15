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


void __thiscall Scaleform::GFx::AS2::ActionBufferData::Read(
        Scaleform::GFx::AS2::ActionBufferData *this,
        Scaleform::GFx::Stream *in,
        unsigned int actionLength)
{
  unsigned __int8 *v4; // eax
  unsigned __int8 *pBuffer; // edi
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v6; // esi
  char v7; // bl
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v8; // ecx
  unsigned int BufferLen; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS2::Disasm da; // [esp+Ch] [ebp-8h] BYREF

  this->BufferLen = actionLength;
  v4 = (unsigned __int8 *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                            Scaleform::Memory::pGlobalHeap,
                            this,
                            actionLength,
                            0);
  BufferLen = this->BufferLen;
  this->pBuffer = v4;
  Scaleform::GFx::Stream::ReadToBuffer(in, v4, BufferLen);
  if ( (unsigned __int8)Scaleform::GFx::Stream::IsVerboseParseAction(in) )
  {
    pBuffer = this->pBuffer;
    v6 = 0;
    da.MsgId.Id = 20483;
    do
    {
      v7 = *((_BYTE *)&v6->__vftable + (_DWORD)pBuffer);
      v8 = v6;
      v6 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v6 + 1);
      if ( v7 < 0 )
        v6 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v6
                                                        + *(unsigned __int16 *)((char *)&v6->__vftable + (_DWORD)pBuffer)
                                                        + 2);
      Scaleform::Render::JPEG::JPEGRwSource::TermSource(v8);
      da.pLog = (Scaleform::Log *)Scaleform::GFx::AS3::Multiname::GetNamespace((Scaleform::GFx::AS3::SoundObject *)in);
      Scaleform::GFx::AS2::Disasm::LogF(&da, "<disasm is disabled>\n");
    }
    while ( v7 );
  }
}
