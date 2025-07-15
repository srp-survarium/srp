Scaleform::GFx::AMP::ViewStats *__thiscall Scaleform::GFx::AMP::ViewStats::`scalar deleting destructor'(
        Scaleform::GFx::AMP::ViewStats *this,
        char a2)
{
  Scaleform::GFx::AMP::ViewStats::~ViewStats(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
