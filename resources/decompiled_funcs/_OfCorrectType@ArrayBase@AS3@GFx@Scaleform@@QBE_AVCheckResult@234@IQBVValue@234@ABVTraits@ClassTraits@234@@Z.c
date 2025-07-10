Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::ArrayBase::OfCorrectType(
        Scaleform::GFx::AS3::ArrayBase *this,
        Scaleform::GFx::AS3::CheckResult *result,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *const argv,
        const Scaleform::GFx::AS3::ClassTraits::Traits *tr)
{
  unsigned int v5; // esi
  const Scaleform::GFx::AS3::ClassTraits::Traits *ClassTraits; // eax
  Scaleform::GFx::AS3::CheckResult *v9; // eax

  v5 = 0;
  if ( argc )
  {
    while ( 1 )
    {
      ClassTraits = Scaleform::GFx::AS3::VM::GetClassTraits(this->VMRef, argv);
      if ( !Scaleform::GFx::AS3::ClassTraits::Traits::IsParentTypeOf(tr, ClassTraits) )
        break;
      ++v5;
      ++argv;
      if ( v5 >= argc )
        goto LABEL_4;
    }
    v9 = result;
    result->Result = 0;
  }
  else
  {
LABEL_4:
    v9 = result;
    result->Result = 1;
  }
  return v9;
}
