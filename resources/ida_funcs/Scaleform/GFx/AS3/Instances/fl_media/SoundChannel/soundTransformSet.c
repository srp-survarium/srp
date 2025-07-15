void __thiscall Scaleform::GFx::AS3::Instances::fl_media::SoundChannel::soundTransformSet(
        Scaleform::GFx::AS3::Instances::fl_media::SoundChannel *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_media::SoundTransform *value)
{
  Scaleform::GFx::AS3::SoundObject *pObject; // edi

  pObject = this->pSoundObject.pObject;
  if ( pObject )
  {
    Scaleform::GFx::AS3::SoundObject::SetVolume(pObject, (int)(value->Volume * 100.0));
    Scaleform::GFx::AS3::SoundObject::SetPan(this->pSoundObject.pObject, (int)(value->Pan * 100.0));
  }
}
