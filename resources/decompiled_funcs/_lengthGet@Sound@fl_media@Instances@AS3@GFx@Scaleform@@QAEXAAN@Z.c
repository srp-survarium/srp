void __thiscall Scaleform::GFx::AS3::Instances::fl_media::Sound::lengthGet(
        Scaleform::GFx::AS3::Instances::fl_media::Sound *this,
        long double *result)
{
  Scaleform::GFx::AS3::SoundObject *pObject; // ecx
  float length; // [esp+0h] [ebp-4h]

  pObject = this->pSoundObject.pObject;
  length = 0.0;
  if ( pObject )
    length = Scaleform::GFx::AS3::SoundObject::GetDuration(pObject);
  *result = length;
}
