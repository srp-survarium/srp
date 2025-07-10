void __thiscall Scaleform::GFx::AS3::Instances::fl_media::SoundChannel::stop(
        Scaleform::GFx::AS3::Instances::fl_media::SoundChannel *this,
        const Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::SoundObject *pObject; // ecx

  pObject = this->pSoundObject.pObject;
  if ( pObject )
    Scaleform::GFx::AS3::SoundObject::Stop(pObject);
}
