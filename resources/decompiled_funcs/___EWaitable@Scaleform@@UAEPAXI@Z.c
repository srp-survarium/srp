Scaleform::Waitable *__thiscall Scaleform::Waitable::`vector deleting destructor'(Scaleform::Waitable *this, char a2)
{
  Scaleform::Waitable::~Waitable(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
