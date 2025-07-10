Scaleform::GFx::AS2::TextFieldProto *__thiscall Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::TextFieldObject,Scaleform::GFx::AS2::Environment>::`scalar deleting destructor'(
        Scaleform::GFx::AS2::TextFieldProto *this,
        char a2)
{
  Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::TextFieldObject,Scaleform::GFx::AS2::Environment>::~Prototype<Scaleform::GFx::AS2::TextFieldObject,Scaleform::GFx::AS2::Environment>(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
