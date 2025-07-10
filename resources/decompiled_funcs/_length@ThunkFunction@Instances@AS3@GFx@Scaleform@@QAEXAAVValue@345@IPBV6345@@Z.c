void __thiscall Scaleform::GFx::AS3::Instances::ThunkFunction::length(
        Scaleform::GFx::AS3::Instances::ThunkFunction *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *argv)
{
  const Scaleform::GFx::AS3::ThunkInfo *Thunk; // eax
  Scaleform::GFx::AS3::Traits *pObject; // ecx
  Scaleform::GFx::AS3::Value _this; // [esp+0h] [ebp-10h] BYREF

  Thunk = this->Thunk;
  pObject = this->pTraits.pObject;
  _this.Flags = 5;
  _this.Bonus.pWeakProxy = 0;
  _this.value.VS._1.VInt = (int)Thunk;
  Scaleform::GFx::AS3::InstanceTraits::Thunk::lengthGet(Thunk, pObject->pVM, &_this, result);
  if ( (_this.Flags & 0x1F) > 9 )
  {
    if ( (_this.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&_this);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&_this);
  }
}
