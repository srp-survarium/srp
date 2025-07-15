Scaleform::GFx::AS2::XmlObject *__thiscall Scaleform::GFx::AS2::XmlObject::`vector deleting destructor'(
        Scaleform::GFx::AS2::XmlObject *this,
        char a2)
{
  Scaleform::GFx::AS2::XmlNodeObject::~XmlNodeObject(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}


Scaleform::GFx::AS2::XmlObject *__thiscall Scaleform::GFx::AS2::XmlObject::`vector deleting destructor'(
        char *this,
        char a2)
{
  return Scaleform::GFx::AS2::XmlObject::`vector deleting destructor'((Scaleform::GFx::AS2::XmlObject *)(this - 16), a2);
}
