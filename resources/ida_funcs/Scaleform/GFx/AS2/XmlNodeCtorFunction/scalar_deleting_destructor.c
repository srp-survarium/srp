Scaleform::GFx::AS2::GASImeCtorFunction *__thiscall Scaleform::GFx::AS2::XmlNodeCtorFunction::`scalar deleting destructor'(
        Scaleform::GFx::AS2::GASImeCtorFunction *this,
        char a2)
{
  Scaleform::GFx::AS2::CFunctionObject::~CFunctionObject(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
