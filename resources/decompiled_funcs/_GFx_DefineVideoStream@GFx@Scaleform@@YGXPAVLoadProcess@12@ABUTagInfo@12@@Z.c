void __stdcall Scaleform::GFx::GFx_DefineVideoStream(
        Scaleform::GFx::LoadProcess *p,
        const Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::Video::VideoBase *pObject; // ecx
  Scaleform::GFx::SWFProcessInfo *pAltStream; // ecx

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
    Scaleform::Render::JPEG::JPEGRwSource::TermSource((Scaleform::GFx::AS3::RefCountBaseGC<328> *)pAltStream);
  }
}
