Scaleform::GFx::AS2::MovieRoot *__thiscall Scaleform::GFx::AS2::MovieRoot::`scalar deleting destructor'(
        Scaleform::GFx::AS2::MovieRoot *this,
        char a2)
{
  Scaleform::GFx::AS2::MovieRoot::~MovieRoot(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
