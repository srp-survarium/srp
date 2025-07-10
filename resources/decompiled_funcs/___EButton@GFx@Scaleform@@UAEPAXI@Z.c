Scaleform::GFx::Button *__thiscall Scaleform::GFx::Button::`vector deleting destructor'(
        Scaleform::GFx::Button *this,
        char a2)
{
  Scaleform::GFx::Button::~Button(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
