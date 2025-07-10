Scaleform::GFx::MovieBindProcess *__thiscall Scaleform::GFx::MovieBindProcess::`vector deleting destructor'(
        Scaleform::GFx::MovieBindProcess *this,
        char a2)
{
  Scaleform::GFx::MovieBindProcess::~MovieBindProcess(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
