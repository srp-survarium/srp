Scaleform::Render::DICommandQueue *__thiscall Scaleform::Render::DICommandQueue::`vector deleting destructor'(
        Scaleform::Render::DICommandQueue *this,
        char a2)
{
  Scaleform::Render::DICommandQueue::~DICommandQueue(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
