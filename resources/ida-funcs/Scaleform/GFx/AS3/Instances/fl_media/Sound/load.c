void __thiscall Scaleform::GFx::AS3::Instances::fl_media::Sound::load(
        Scaleform::GFx::AS3::Instances::fl_media::Sound *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_net::URLRequest *stream,
        Scaleform::GFx::AS3::Instances::fl_media::SoundLoaderContext *context)
{
  const __m128i ***Name; // eax

  if ( this->pSoundObject.pObject )
  {
    if ( stream )
    {
      Name = (const __m128i ***)Scaleform::GFx::AS3::Instances::fl::XML::GetName(stream);
      Scaleform::String::operator=(&this->SoundURL, **Name);
    }
    if ( context )
      this->Streaming = context->bufferTime > 0.0;
    Scaleform::GFx::AS3::SoundObject::LoadFile(this->pSoundObject.pObject, &this->SoundURL, this->Streaming);
  }
}
