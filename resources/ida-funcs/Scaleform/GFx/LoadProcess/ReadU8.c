unsigned __int8 __thiscall Scaleform::GFx::LoadProcess::ReadU8(Scaleform::GFx::LoadProcess *this)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // esi
  int v2; // eax
  unsigned int Pos; // ecx
  unsigned __int8 result; // al

  pAltStream = (Scaleform::GFx::SWFProcessInfo *)this->pAltStream;
  if ( !pAltStream )
    pAltStream = &this->ProcessInfo;
  v2 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
  pAltStream->Stream.UnusedBits = 0;
  if ( v2 < 1 )
    Scaleform::GFx::Stream::PopulateBuffer1(&pAltStream->Stream);
  Pos = pAltStream->Stream.Pos;
  result = pAltStream->Stream.pBuffer[Pos];
  pAltStream->Stream.Pos = Pos + 1;
  return result;
}
