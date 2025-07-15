Scaleform::GFx::AS2::LocalFrame *__thiscall Scaleform::GFx::AS2::LocalFrame::`vector deleting destructor'(
        Scaleform::GFx::AS2::LocalFrame *this,
        char a2)
{
  Scaleform::GFx::AS2::LocalFrame::~LocalFrame(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
