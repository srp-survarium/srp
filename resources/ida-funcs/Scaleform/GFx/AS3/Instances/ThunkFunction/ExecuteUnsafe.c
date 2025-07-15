void __thiscall Scaleform::GFx::AS3::Instances::ThunkFunction::ExecuteUnsafe(
        Scaleform::GFx::AS3::Instances::ThunkFunction *this,
        const Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Traits *pObject; // eax
  Scaleform::GFx::AS3::Value func; // [esp+0h] [ebp-10h] BYREF

  func.value.VS._1.VInt = (int)this->Thunk;
  pObject = this->pTraits.pObject;
  func.Flags = 5;
  func.Bonus.pWeakProxy = 0;
  Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(pObject->pVM, &func, _this, result, argc, argv, 0);
  if ( (func.Flags & 0x1F) > 9 )
  {
    if ( (func.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&func);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&func);
  }
}
