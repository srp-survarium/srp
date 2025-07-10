void __thiscall Scaleform::GFx::MovieDataDef::SetSoundStream(
        Scaleform::GFx::MovieDataDef *this,
        Scaleform::GFx::SoundStreamDef *pdef)
{
  Scaleform::GFx::MovieDataDef::LoadTaskData *pObject; // esi
  Scaleform::RefCountNTSImpl *pSoundStream; // ecx

  pObject = this->pData.pObject;
  pSoundStream = pObject->pSoundStream;
  if ( pSoundStream )
    Scaleform::RefCountNTSImpl::Release(pSoundStream);
  if ( pdef )
    ++pdef->RefCount;
  pObject->pSoundStream = pdef;
}
