Scaleform::GFx::TextField *__thiscall Scaleform::GFx::TextField::`scalar deleting destructor'(
        Scaleform::GFx::TextField *this,
        char a2)
{
  Scaleform::GFx::TextField::~TextField(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
