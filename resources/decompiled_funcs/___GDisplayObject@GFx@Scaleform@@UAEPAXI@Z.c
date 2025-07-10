Scaleform::GFx::DisplayObject *__thiscall Scaleform::GFx::DisplayObject::`scalar deleting destructor'(
        Scaleform::GFx::DisplayObject *this,
        char a2)
{
  Scaleform::GFx::DisplayObject::~DisplayObject(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
