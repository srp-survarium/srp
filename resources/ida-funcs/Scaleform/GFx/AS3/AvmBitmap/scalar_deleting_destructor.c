Scaleform::GFx::AS3::AvmBitmap *__thiscall Scaleform::GFx::AS3::AvmBitmap::`scalar deleting destructor'(
        Scaleform::GFx::AS3::AvmBitmap *this,
        char a2)
{
  Scaleform::GFx::AS3::AvmBitmap::~AvmBitmap(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
