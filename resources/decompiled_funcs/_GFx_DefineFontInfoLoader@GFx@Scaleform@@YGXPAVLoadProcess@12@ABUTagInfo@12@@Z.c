void __stdcall Scaleform::GFx::GFx_DefineFontInfoLoader(
        Scaleform::GFx::LoadProcess *p,
        const Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // esi
  int v3; // eax
  unsigned int Pos; // eax
  unsigned __int16 v5; // dx
  int v6; // esi
  Scaleform::GFx::FontData *FontData; // eax
  Scaleform::GFx::SWFProcessInfo *p_ProcessInfo; // ecx

  pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !pAltStream )
    pAltStream = &p->ProcessInfo;
  v3 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
  pAltStream->Stream.UnusedBits = 0;
  if ( v3 < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
  Pos = pAltStream->Stream.Pos;
  v5 = *(_WORD *)&pAltStream->Stream.pBuffer[Pos];
  pAltStream->Stream.Pos = Pos + 2;
  v6 = v5;
  FontData = (Scaleform::GFx::FontData *)Scaleform::GFx::MovieDataDef::LoadTaskData::GetFontData(
                                           p->pLoadData.pObject,
                                           (Scaleform::GFx::ResourceId)v5);
  if ( FontData )
  {
    p_ProcessInfo = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
    if ( !p_ProcessInfo )
      p_ProcessInfo = &p->ProcessInfo;
    Scaleform::GFx::FontData::ReadFontInfo(FontData, &p_ProcessInfo->Stream, tagInfo->TagType);
  }
  else
  {
    Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogError(
      &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
      "GFx_DefineFontInfoLoader - can't find FontResource w/ id %d",
      v6);
  }
}
