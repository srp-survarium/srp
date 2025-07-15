Scaleform::GFx::DisplayObjectBase *__thiscall Scaleform::GFx::DisplayObjectBase::`scalar deleting destructor'(
        Scaleform::GFx::DisplayObjectBase *this,
        char a2)
{
  Scaleform::GFx::DisplayObjectBase::~DisplayObjectBase(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
