bool __thiscall Scaleform::GFx::AS3::ClassTraits::fl::Namespace::Coerce(
        Scaleform::GFx::AS3::ClassTraits::fl::Namespace *this,
        const Scaleform::GFx::AS3::Value *value,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Class *Constructor; // eax

  Constructor = Scaleform::GFx::AS3::Traits::GetConstructor(this->ITraits.pObject);
  Constructor->Construct(Constructor, result, 1u, value, 0);
  return !this->pVM->HandleException;
}
