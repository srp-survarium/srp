void __thiscall Scaleform::GFx::AS3::Instances::FunctionBase::Call(
        Scaleform::GFx::AS3::Instances::FunctionBase *this,
        const Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *const argv)
{
  Scaleform::GFx::AS3::Value *Undefined; // ecx
  Scaleform::GFx::AS3::Value r; // [esp+10h] [ebp-10h] BYREF

  Undefined = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Value::GetUndefined();
  r = *Undefined;
  if ( (Undefined->Flags & 0x1F) > 9 )
  {
    if ( (Undefined->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(Undefined);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(Undefined);
  }
  this->ExecuteUnsafe(this, _this, &r, argc, argv);
  Scaleform::GFx::AS3::Value::Swap(&r, result);
  if ( (r.Flags & 0x1F) > 9 )
  {
    if ( (r.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&r);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&r);
  }
}
