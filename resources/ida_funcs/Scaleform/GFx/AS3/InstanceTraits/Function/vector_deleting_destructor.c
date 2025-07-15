Scaleform::GFx::AS3::InstanceTraits::Function *__thiscall Scaleform::GFx::AS3::InstanceTraits::Function::`vector deleting destructor'(
        Scaleform::GFx::AS3::InstanceTraits::Function *this,
        char a2)
{
  Scaleform::GFx::AS3::InstanceTraits::Function::~Function(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
