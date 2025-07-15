Scaleform::GFx::LoadProcess *__thiscall Scaleform::GFx::LoadProcess::`scalar deleting destructor'(
        Scaleform::GFx::LoadProcess *this,
        char a2)
{
  Scaleform::GFx::LoadProcess::~LoadProcess(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
