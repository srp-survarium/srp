Scaleform::GFx::AS3::AvmLoader *__thiscall Scaleform::GFx::AS3::AvmLoader::`vector deleting destructor'(
        Scaleform::GFx::AS3::AvmLoader *this,
        char a2)
{
  Scaleform::GFx::AS3::AvmLoader::~AvmLoader(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
