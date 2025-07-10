void __stdcall Scaleform::GFx::GFx_DefineSoundLoader(
        Scaleform::GFx::LoadProcess *p,
        const Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::AudioBase *pObject; // ecx
  int v3; // eax

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
    Scaleform::Render::JPEG::JPEGRwSource::TermSource(0);
  }
}
