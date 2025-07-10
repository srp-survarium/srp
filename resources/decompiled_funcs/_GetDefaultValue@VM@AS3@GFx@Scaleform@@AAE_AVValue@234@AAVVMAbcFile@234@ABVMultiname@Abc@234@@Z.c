Scaleform::GFx::AS3::Value *__thiscall Scaleform::GFx::AS3::VM::GetDefaultValue(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::VMAbcFile *file,
        Scaleform::GFx::AS3::Abc::Multiname *mn)
{
  Scaleform::GFx::AS3::ClassTraits::ClassClass *v5; // eax

  if ( mn->Kind || mn->NameIndex || mn->Ind )
  {
    v5 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(this, file, mn);
    if ( v5 )
    {
      Scaleform::GFx::AS3::VM::GetDefaultValue(this, result, v5);
      return result;
    }
  }
  if ( (_S10_0 & 1) == 0 )
  {
    _S10_0 |= 1u;
    v.Flags = 0;
    v.Bonus.pWeakProxy = 0;
    atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
  }
  *result = v;
  if ( (v.Flags & 0x1F) > 9 )
  {
    if ( (v.Flags & 0x200) != 0 )
    {
      ++v.Bonus.pWeakProxy->RefCount;
      return result;
    }
    Scaleform::GFx::AS3::Value::AddRefInternal(&v);
  }
  return result;
}
