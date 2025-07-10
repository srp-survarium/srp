Scaleform::GFx::AS3::SoundObject *__thiscall Scaleform::GFx::AS3::SoundObject::`scalar deleting destructor'(
        Scaleform::GFx::AS3::SoundObject *this,
        char a2)
{
  Scaleform::GFx::AS3::SoundObject::~SoundObject(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
