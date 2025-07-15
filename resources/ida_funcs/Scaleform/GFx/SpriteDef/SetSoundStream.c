void __thiscall Scaleform::GFx::SpriteDef::SetSoundStream(
        Scaleform::GFx::SpriteDef *this,
        Scaleform::GFx::SoundStreamDef *psoundStream)
{
  Scaleform::GFx::SoundStreamDef *pObject; // ecx

  if ( psoundStream )
    ++psoundStream->RefCount;
  pObject = this->pSoundStream.pObject;
  if ( pObject )
    Scaleform::RefCountNTSImpl::Release(pObject);
  this->pSoundStream.pObject = psoundStream;
}
