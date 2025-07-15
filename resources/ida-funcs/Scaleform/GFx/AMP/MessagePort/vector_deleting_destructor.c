Scaleform::GFx::AMP::MessagePort *__thiscall Scaleform::GFx::AMP::MessagePort::`vector deleting destructor'(
        Scaleform::GFx::AMP::MessagePort *this,
        char a2)
{
  Scaleform::GFx::AMP::MessagePort::~MessagePort(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
