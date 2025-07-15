Scaleform::GFx::AS3::Instances::fl_media::Sound *__thiscall Scaleform::GFx::AS3::Instances::fl_media::Sound::`scalar deleting destructor'(
        Scaleform::GFx::AS3::Instances::fl_media::Sound *this,
        char a2)
{
  Scaleform::GFx::AS3::Instances::fl_media::Sound::~Sound(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
