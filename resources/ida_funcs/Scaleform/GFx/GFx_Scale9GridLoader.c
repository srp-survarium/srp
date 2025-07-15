void __stdcall Scaleform::GFx::GFx_Scale9GridLoader(
        Scaleform::GFx::LoadProcess *p,
        const Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // esi
  int v3; // eax
  unsigned int Pos; // eax
  Scaleform::GFx::ResourceId v5; // edi
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v6; // ecx
  Scaleform::GFx::SpriteDef *BindIndex; // edi
  Scaleform::GFx::ResourceHandle phandle; // [esp+40h] [ebp-18h] BYREF
  Scaleform::Render::Rect<float> pr; // [esp+48h] [ebp-10h] BYREF

  pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !pAltStream )
    pAltStream = &p->ProcessInfo;
  pr.x1 = 0.0;
  pr.y1 = 0.0;
  pr.x2 = 0.0;
  pr.y2 = 0.0;
  v3 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
  pAltStream->Stream.UnusedBits = 0;
  if ( v3 < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
  Pos = pAltStream->Stream.Pos;
  v5.Id = *(unsigned __int16 *)&pAltStream->Stream.pBuffer[Pos];
  pAltStream->Stream.Pos = Pos + 2;
  Scaleform::GFx::Stream::ReadRect(&pAltStream->Stream, &pr);
  if ( Scaleform::GFx::Stream::IsVerboseParse(&pAltStream->Stream) )
    Scaleform::Render::JPEG::JPEGRwSource::TermSource(v6);
  if ( pr.x2 <= (double)pr.x1 )
  {
    Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogWarning(
      &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
      "Scale9Grid for resource=%d has negative width %f",
      v5.Id,
      (pr.x2 - pr.x1) / 20.0);
    return;
  }
  if ( pr.y2 <= (double)pr.y1 )
  {
    Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogWarning(
      &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
      "Scale9Grid for resource=%d has negative height %f",
      v5.Id,
      (pr.y2 - pr.y1) / 20.0);
    return;
  }
  phandle.HType = RH_Pointer;
  phandle.BindIndex = 0;
  if ( Scaleform::GFx::MovieDataDef::LoadTaskData::GetResourceHandle(p->pLoadData.pObject, &phandle, v5) )
  {
    if ( phandle.HType )
      return;
    BindIndex = (Scaleform::GFx::SpriteDef *)phandle.BindIndex;
    if ( !phandle.BindIndex )
      return;
    if ( ((*(int (__thiscall **)(unsigned int))(*(_DWORD *)phandle.BindIndex + 8))(phandle.BindIndex) & 0xFF00) == 0x8400 )
    {
      Scaleform::GFx::SpriteDef::SetScale9Grid(BindIndex, &pr);
    }
    else if ( (BindIndex->GetResourceTypeCode(BindIndex) & 0xFF00) == 0x8100 )
    {
      Scaleform::GFx::ButtonDef::SetScale9Grid((Scaleform::GFx::ButtonDef *)BindIndex, &pr);
    }
  }
  if ( phandle.HType == RH_Pointer )
  {
    if ( phandle.BindIndex )
      Scaleform::GFx::Resource::Release(phandle.pResource);
  }
}
