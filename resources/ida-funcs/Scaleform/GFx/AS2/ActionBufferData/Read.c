void __thiscall Scaleform::GFx::AS2::ActionBufferData::Read(
        Scaleform::GFx::AS2::ActionBufferData *this,
        Scaleform::GFx::StreamContext *psc,
        unsigned int eventLength)
{
  unsigned __int8 *v4; // eax
  Scaleform::AmpServer *Instance; // eax

  if ( psc->CurBitIndex )
    ++psc->CurByteIndex;
  psc->CurBitIndex = 0;
  v4 = (unsigned __int8 *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                            Scaleform::Memory::pGlobalHeap,
                            this,
                            eventLength,
                            0);
  this->pBuffer = v4;
  memcpy((int)v4, (const __m128i *)&psc->pData[psc->CurByteIndex], eventLength);
  this->BufferLen = eventLength;
  if ( psc->CurBitIndex )
    ++psc->CurByteIndex;
  psc->CurByteIndex += eventLength;
  psc->CurBitIndex = 0;
  if ( !this->SwdHandle )
  {
    Instance = Scaleform::AmpServer::GetInstance();
    this->SwdHandle = Instance->GetNextSwdHandle(Instance);
  }
}


void __thiscall Scaleform::GFx::AS2::ActionBufferData::Read(
        Scaleform::GFx::AS2::ActionBufferData *this,
        Scaleform::GFx::Stream *in,
        unsigned int actionLength)
{
  unsigned __int8 *v4; // eax
  unsigned __int8 *pBuffer; // ebp
  int v6; // esi
  char v7; // bl
  int v8; // eax
  Scaleform::AmpServer *Instance; // eax
  unsigned int BufferLen; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS2::Disasm v11; // [esp+Ch] [ebp-8h] BYREF
  int v12; // [esp+1Ch] [ebp+8h]

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
    v11.MsgId.Id = 20483;
    do
    {
      v7 = pBuffer[v6];
      v12 = v6;
      v8 = v6++;
      if ( v7 < 0 )
        v6 += *(unsigned __int16 *)&pBuffer[v6] + 2;
      Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseAction(in, "%4d\t", v8);
      v11.pLog = (Scaleform::Log *)Scaleform::GFx::AS3::Multiname::GetNamespace((Scaleform::GFx::AS3::SoundObject *)in);
      Scaleform::GFx::AS2::Disasm::LogDisasm(&v11, &this->pBuffer[v12]);
    }
    while ( v7 );
  }
  if ( !this->SwdHandle )
  {
    Instance = Scaleform::AmpServer::GetInstance();
    this->SwdHandle = Instance->GetNextSwdHandle(Instance);
  }
}
