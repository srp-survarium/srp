Scaleform::GFx::AS3::MovieRoot *__thiscall Scaleform::GFx::AS3::MovieRoot::`scalar deleting destructor'(
        Scaleform::GFx::AS3::MovieRoot *this,
        char a2)
{
  Scaleform::GFx::AS3::MovieRoot::~MovieRoot(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
