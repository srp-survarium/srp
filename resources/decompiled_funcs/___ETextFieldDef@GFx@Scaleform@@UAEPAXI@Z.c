Scaleform::GFx::TextFieldDef *__thiscall Scaleform::GFx::TextFieldDef::`vector deleting destructor'(
        Scaleform::GFx::TextFieldDef *this,
        char a2)
{
  Scaleform::GFx::TextFieldDef::~TextFieldDef(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
