void __stdcall Scaleform::GFx::GFx_DefineSoundLoader(
        Scaleform::GFx::LoadProcess *p,
        const Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::AudioBase *pObject; // ecx
  int v3; // eax
  Scaleform::GFx::SWFProcessInfo *pAltStream; // eax
  Scaleform::GFx::SWFProcessInfo *p_ProcessInfo; // eax

  pObject = p->pLoadStates.pObject->pAudioState.pObject;
  if ( pObject )
  {
    v3 = (int)pObject->GetSoundTagsReader(pObject);
    (*(void (__thiscall **)(int, Scaleform::GFx::LoadProcess *, const Scaleform::GFx::TagInfo *))(*(_DWORD *)v3 + 8))(
      v3,
      p,
      tagInfo);
  }
  else
  {
    pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
    if ( !pAltStream )
      pAltStream = &p->ProcessInfo;
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(
      &pAltStream->Stream,
      "GFx_DefineSoundLoader: Audio library is not set.\n");
    p_ProcessInfo = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
    if ( !p_ProcessInfo )
      p_ProcessInfo = &p->ProcessInfo;
    Scaleform::GFx::Stream::LogTagBytes(&p_ProcessInfo->Stream);
  }
}
