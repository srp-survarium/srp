Scaleform::GFx::AMP::ProfileFrame *__thiscall Scaleform::GFx::AMP::ProfileFrame::`scalar deleting destructor'(
        Scaleform::GFx::AMP::ProfileFrame *this,
        char a2)
{
  Scaleform::GFx::AMP::ProfileFrame::~ProfileFrame(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
