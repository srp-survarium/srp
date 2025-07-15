void __thiscall Scaleform::GFx::AS3::VM::exec_callobject(Scaleform::GFx::AS3::VM *this, unsigned int arg_count)
{
  Scaleform::GFx::AS3::Value::V1U v3; // esi
  Scaleform::GFx::AS3::Value *FixedArr; // edi
  Scaleform::GFx::AS3::ReadArgsObjectRef args; // [esp+10h] [ebp-A8h] BYREF

  Scaleform::GFx::AS3::ReadArgs::ReadArgs(&args, this, arg_count);
  args.ArgObject = args.OpStack->pCurrent;
  Scaleform::GFx::AS3::StackReader::CheckObject(&args, args.ArgObject);
  if ( this->HandleException )
  {
    Scaleform::GFx::AS3::ReadArgs::~ReadArgs(&args);
  }
  else
  {
    v3 = args.ArgObject->value.VS._1;
    FixedArr = args.FixedArr;
    if ( args.ArgNum > 8 )
      FixedArr = args.CallArgs.Data.Data;
    if ( (_S15 & 1) == 0 )
    {
      _S15 |= 1u;
      v.Flags = 0;
      v.Bonus.pWeakProxy = 0;
      atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
    }
    (*(void (__thiscall **)(Scaleform::GFx::AS3::Value::V1U, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *, unsigned int, Scaleform::GFx::AS3::Value *))(*(_DWORD *)v3.VInt + 40))(
      v3,
      &v,
      args.ArgObject,
      arg_count,
      FixedArr);
    Scaleform::GFx::AS3::ReadArgs::~ReadArgs(&args);
  }
}
