int __thiscall Scaleform::GFx::LoadProcess::ReadU32(Scaleform::GFx::LoadProcess *this)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // esi
  int v2; // eax
  unsigned int Pos; // edx
  unsigned __int8 *pBuffer; // ecx
  int v5; // eax
  int v6; // edi
  unsigned __int8 *v7; // ecx
  int v8; // eax
  int v9; // edi
  int v10; // ecx

  pAltStream = (Scaleform::GFx::SWFProcessInfo *)this->pAltStream;
  if ( !pAltStream )
    pAltStream = &this->ProcessInfo;
  v2 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
  pAltStream->Stream.UnusedBits = 0;
  if ( v2 < 4 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 4);
  Pos = pAltStream->Stream.Pos;
  pBuffer = pAltStream->Stream.pBuffer;
  v5 = pBuffer[Pos + 3];
  v6 = pBuffer[Pos + 2];
  v7 = &pBuffer[Pos];
  v8 = v6 | (v5 << 8);
  v9 = v7[1];
  v10 = *v7;
  pAltStream->Stream.Pos = Pos + 4;
  return v10 | ((v9 | (v8 << 8)) << 8);
}
