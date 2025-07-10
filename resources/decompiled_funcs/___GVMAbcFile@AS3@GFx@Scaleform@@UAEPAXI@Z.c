Scaleform::GFx::AS3::VMAbcFile *__thiscall Scaleform::GFx::AS3::VMAbcFile::`scalar deleting destructor'(
        Scaleform::GFx::AS3::VMAbcFile *this,
        char a2)
{
  Scaleform::GFx::AS3::VMAbcFile::~VMAbcFile(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
