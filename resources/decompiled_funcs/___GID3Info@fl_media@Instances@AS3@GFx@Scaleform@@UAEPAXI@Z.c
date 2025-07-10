Scaleform::GFx::AS3::Instances::fl_media::ID3Info *__thiscall Scaleform::GFx::AS3::Instances::fl_media::ID3Info::`scalar deleting destructor'(
        Scaleform::GFx::AS3::Instances::fl_media::ID3Info *this,
        char a2)
{
  Scaleform::GFx::AS3::Instances::fl_media::ID3Info::~ID3Info(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
