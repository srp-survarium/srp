void __stdcall Scaleform::GFx::GFx_FileAttributesLoader(
        Scaleform::GFx::LoadProcess *p,
        const Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // esi
  int v4; // eax
  unsigned int Pos; // eax
  unsigned __int16 v6; // bx
  char v7; // [esp+10h] [ebp+4h]

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
  p->pLoadData.pObject->FileAttributes = v6;
  if ( v6 )
  {
    Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogParse(
      &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
      "  fileAttr:");
    v7 = 32;
    if ( (v6 & 1) != 0 )
    {
      Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogParse(
        &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
        "%cUseNetwork",
        32);
      v7 = 44;
    }
    if ( (v6 & 8) != 0 )
      Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogParse(
        &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
        "%cUseActionScript3",
        v7);
    if ( (v6 & 0x10) != 0 )
      Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogParse(
        &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
        "%cHasMetadata",
        v7);
    Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogParse(
      &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
      "\n");
  }
}
