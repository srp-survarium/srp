Scaleform::GFx::AS3::Value *__thiscall Scaleform::GFx::AS3::VM::GetDefaultValue(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::ClassTraits::ClassClass *ctr)
{
  Scaleform::GFx::AS3::Value *v3; // eax
  double v4; // st7
  Scaleform::GFx::AS3::Value *v5; // esi
  Scaleform::GFx::AS3::Value *Null; // eax

  switch ( ctr->TraitsType )
  {
    case Traits_Boolean:
      v3 = result;
      result->Flags = 1;
      result->Bonus.pWeakProxy = 0;
      result->value.VS._1.VBool = 0;
      return v3;
    case Traits_SInt:
      v3 = result;
      result->Flags = 2;
      result->Bonus.pWeakProxy = 0;
      result->value.VS._1.VInt = 0;
      return v3;
    case Traits_UInt:
      v3 = result;
      result->Flags = 3;
      result->Bonus.pWeakProxy = 0;
      result->value.VS._1.VInt = 0;
      return v3;
    case Traits_Number:
      v4 = Scaleform::GFx::NumberUtil::NaN();
      v3 = result;
      result->Flags = 4;
      result->value.VNumber = v4;
      result->Bonus.pWeakProxy = 0;
      return v3;
    default:
      if ( ctr != this->TraitsClassClass.pObject )
      {
        Null = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Value::GetNull();
        v5 = result;
        *result = *Null;
        if ( (Null->Flags & 0x1F) > 9 )
        {
          if ( (Null->Flags & 0x200) != 0 )
          {
            ++Null->Bonus.pWeakProxy->RefCount;
            return result;
          }
          Scaleform::GFx::AS3::Value::AddRefInternal(Null);
        }
        return v5;
      }
      if ( (_S10_0 & 1) == 0 )
      {
        _S10_0 |= 1u;
        v.Flags = 0;
        v.Bonus.pWeakProxy = 0;
        atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
      }
      v5 = result;
      *result = v;
      if ( (v.Flags & 0x1F) <= 9 )
        return v5;
      if ( (v.Flags & 0x200) != 0 )
        ++v.Bonus.pWeakProxy->RefCount;
      else
        Scaleform::GFx::AS3::Value::AddRefInternal(&v);
      return result;
  }
}
