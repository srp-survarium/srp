void __thiscall Scaleform::GFx::RemoveObject2Tag::Read(
        Scaleform::GFx::RemoveObject2Tag *this,
        Scaleform::GFx::LoadProcess *p)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // esi
  int v4; // eax
  unsigned int Pos; // eax
  unsigned __int16 v6; // dx

  pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !pAltStream )
    pAltStream = &p->ProcessInfo;
  v4 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
  pAltStream->Stream.UnusedBits = 0;
  if ( v4 < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
  Pos = pAltStream->Stream.Pos;
  v6 = *(_WORD *)&pAltStream->Stream.pBuffer[Pos];
  pAltStream->Stream.Pos = Pos + 2;
  this->Depth = v6;
}
