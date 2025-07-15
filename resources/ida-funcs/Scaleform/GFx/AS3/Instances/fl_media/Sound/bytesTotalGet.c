void __thiscall Scaleform::GFx::AS3::Instances::fl_media::Sound::bytesTotalGet(
        Scaleform::GFx::AS3::Instances::fl_media::Sound *this,
        int *result)
{
  Scaleform::GFx::AS3::SoundObject *pObject; // ecx

  *result = 0;
  pObject = this->pSoundObject.pObject;
  if ( pObject )
    *result = Scaleform::GFx::AS3::SoundObject::GetBytesTotal(pObject);
}
