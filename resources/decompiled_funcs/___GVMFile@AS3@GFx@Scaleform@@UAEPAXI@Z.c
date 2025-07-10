Scaleform::GFx::AS3::VMFile *__thiscall Scaleform::GFx::AS3::VMFile::`scalar deleting destructor'(
        Scaleform::GFx::AS3::VMFile *this,
        char a2)
{
  Scaleform::GFx::AS3::VMFile::~VMFile(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
