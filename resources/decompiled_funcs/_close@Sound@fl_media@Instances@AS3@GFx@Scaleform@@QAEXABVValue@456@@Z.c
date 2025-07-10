void __thiscall Scaleform::GFx::AS3::Instances::fl_media::Sound::close(
        Scaleform::GFx::AS3::Instances::fl_media::Sound *this,
        const Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::SoundObject *pObject; // ecx
  Scaleform::RefCountVImpl *v4; // ecx

  pObject = this->pSoundObject.pObject;
  if ( pObject )
  {
    Scaleform::GFx::AS3::SoundObject::Stop(pObject);
    v4 = (Scaleform::RefCountVImpl *)this->pSoundObject.pObject;
    if ( v4 )
      Scaleform::RefCountImpl::Release(v4);
    this->pSoundObject.pObject = 0;
  }
}
