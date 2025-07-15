void __stdcall Scaleform::GFx::GFx_DefineVideoStream(
        Scaleform::GFx::LoadProcess *p,
        const Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::Video::VideoBase *pObject; // ecx
  Scaleform::GFx::SWFProcessInfo *pAltStream; // eax
  Scaleform::GFx::SWFProcessInfo *p_ProcessInfo; // eax

  pObject = p->pLoadStates.pObject->pVideoPlayerState.pObject;
  if ( pObject )
  {
    pObject->ReadDefineVideoStreamTag(pObject, p, tagInfo);
  }
  else
  {
    pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
    if ( !pAltStream )
      pAltStream = &p->ProcessInfo;
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(
      &pAltStream->Stream,
      "GFx_DefineVideoStream: Video library is not set.\n");
    p_ProcessInfo = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
    if ( !p_ProcessInfo )
      p_ProcessInfo = &p->ProcessInfo;
    Scaleform::GFx::Stream::LogTagBytes(&p_ProcessInfo->Stream);
  }
}
