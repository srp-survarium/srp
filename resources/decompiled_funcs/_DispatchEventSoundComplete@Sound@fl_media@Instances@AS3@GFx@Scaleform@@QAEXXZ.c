void __thiscall Scaleform::GFx::AS3::Instances::fl_media::Sound::DispatchEventSoundComplete(
        Scaleform::GFx::AS3::Instances::fl_media::Sound *this)
{
  Scaleform::GFx::AS3::Instances::fl_media::SoundChannel *pObject; // ecx

  pObject = this->pChannel.pObject;
  if ( pObject )
    Scaleform::GFx::AS3::Instances::fl_media::SoundChannel::DispatchEventSoundComplete(pObject);
}
