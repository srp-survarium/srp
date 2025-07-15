void __stdcall Scaleform::GFx::GFx_SetTabIndexLoader(
        Scaleform::GFx::LoadProcess *p,
        const Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // esi
  int v3; // eax
  Scaleform::GFx::SWFProcessInfo *p_ProcessInfo; // esi
  int v5; // ecx

  pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !pAltStream )
    pAltStream = &p->ProcessInfo;
  v3 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
  pAltStream->Stream.UnusedBits = 0;
  if ( v3 < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
  pAltStream->Stream.Pos += 2;
  p_ProcessInfo = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !p_ProcessInfo )
    p_ProcessInfo = &p->ProcessInfo;
  v5 = p_ProcessInfo->Stream.DataSize - p_ProcessInfo->Stream.Pos;
  p_ProcessInfo->Stream.UnusedBits = 0;
  if ( v5 < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&p_ProcessInfo->Stream, 2);
  p_ProcessInfo->Stream.Pos += 2;
  Scaleform::Render::JPEG::JPEGRwSource::TermSource((Scaleform::GFx::AS3::RefCountBaseGC<328> *)v5);
}
