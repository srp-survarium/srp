void __thiscall Scaleform::GFx::AS3::Instances::ThunkFunction::Execute(
        Scaleform::GFx::AS3::Instances::ThunkFunction *this,
        const Scaleform::GFx::AS3::Value *_this,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *argv,
        bool discard_result)
{
  const Scaleform::GFx::AS3::ThunkInfo *Thunk; // eax
  Scaleform::GFx::AS3::Traits *pObject; // ecx
  Scaleform::GFx::AS3::VM *pVM; // esi
  Scaleform::GFx::AS3::Value *Undefined; // ecx
  Scaleform::GFx::AS3::Value result; // [esp+4h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::Value func; // [esp+14h] [ebp-10h] BYREF

  Thunk = this->Thunk;
  pObject = this->pTraits.pObject;
  func.Flags = 5;
  func.Bonus.pWeakProxy = 0;
  func.value.VS._1.VInt = (int)Thunk;
  pVM = pObject->pVM;
  Undefined = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Value::GetUndefined();
  result = *Undefined;
  if ( (Undefined->Flags & 0x1F) > 9 )
  {
    if ( (Undefined->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(Undefined);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(Undefined);
  }
  Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(pVM, &func, _this, &result, argc, argv, !discard_result);
  if ( (result.Flags & 0x1F) > 9 )
  {
    if ( (result.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&result);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&result);
  }
  if ( (func.Flags & 0x1F) > 9 )
  {
    if ( (func.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&func);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&func);
  }
}
