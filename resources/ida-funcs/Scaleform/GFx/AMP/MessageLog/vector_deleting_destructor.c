Scaleform::GFx::AMP::MessageLog *__thiscall Scaleform::GFx::AMP::MessageLog::`vector deleting destructor'(
        Scaleform::GFx::AMP::MessageLog *this,
        char a2)
{
  Scaleform::GFx::AMP::MessageLog::~MessageLog(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
