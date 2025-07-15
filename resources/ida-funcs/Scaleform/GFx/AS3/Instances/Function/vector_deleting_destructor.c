Scaleform::GFx::AS3::Instances::Function *__thiscall Scaleform::GFx::AS3::Instances::Function::`vector deleting destructor'(
        Scaleform::GFx::AS3::Instances::Function *this,
        char a2)
{
  Scaleform::GFx::AS3::Instances::Function::~Function(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
