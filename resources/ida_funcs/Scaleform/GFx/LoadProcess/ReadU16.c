int __thiscall Scaleform::GFx::LoadProcess::ReadU16(Scaleform::GFx::LoadProcess *this)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // esi
  int v2; // eax
  unsigned int Pos; // ecx
  unsigned __int16 v4; // dx

  pAltStream = (Scaleform::GFx::SWFProcessInfo *)this->pAltStream;
  if ( !pAltStream )
    pAltStream = &this->ProcessInfo;
  v2 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
  pAltStream->Stream.UnusedBits = 0;
  if ( v2 < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
  Pos = pAltStream->Stream.Pos;
  v4 = *(_WORD *)&pAltStream->Stream.pBuffer[Pos];
  pAltStream->Stream.Pos = Pos + 2;
  return v4;
}
