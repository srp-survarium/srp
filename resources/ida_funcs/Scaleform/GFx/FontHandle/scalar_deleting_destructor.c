Scaleform::GFx::FontHandle *__thiscall Scaleform::GFx::FontHandle::`scalar deleting destructor'(
        Scaleform::GFx::FontHandle *this,
        char a2)
{
  Scaleform::GFx::FontHandle::~FontHandle(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
