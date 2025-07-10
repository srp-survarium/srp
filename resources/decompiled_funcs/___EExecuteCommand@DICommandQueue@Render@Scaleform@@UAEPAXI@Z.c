Scaleform::Render::DICommandQueue::ExecuteCommand *__thiscall Scaleform::Render::DICommandQueue::ExecuteCommand::`vector deleting destructor'(
        Scaleform::Render::DICommandQueue::ExecuteCommand *this,
        char a2)
{
  Scaleform::Event::~Event(&this->ExecuteDone);
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
