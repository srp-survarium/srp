void __thiscall Scaleform::GFx::AS3::Instances::fl_media::SoundChannel::positionGet(
        Scaleform::GFx::AS3::Instances::fl_media::SoundChannel *this,
        long double *result)
{
  Scaleform::GFx::AS3::SoundObject *pObject; // ecx
  float position; // [esp+0h] [ebp-4h]

  pObject = this->pSoundObject.pObject;
  position = 0.0;
  if ( pObject )
    position = Scaleform::GFx::AS3::SoundObject::GetPosition(pObject);
  *result = position;
}
