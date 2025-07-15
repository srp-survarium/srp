Scaleform::GFx::AS3::Instances::CheckTypeTF *__thiscall Scaleform::GFx::AS3::Instances::ThunkFunction::`scalar deleting destructor'(
        Scaleform::GFx::AS3::Instances::CheckTypeTF *this,
        char a2)
{
  Scaleform::GFx::AS3::Instances::ThunkFunction::~ThunkFunction(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
