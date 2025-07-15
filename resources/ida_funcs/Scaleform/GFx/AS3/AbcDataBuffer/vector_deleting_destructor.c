Scaleform::GFx::AS3::AbcDataBuffer *__thiscall Scaleform::GFx::AS3::AbcDataBuffer::`vector deleting destructor'(
        Scaleform::GFx::AS3::AbcDataBuffer *this,
        char a2)
{
  Scaleform::GFx::AS3::AbcDataBuffer::~AbcDataBuffer(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
