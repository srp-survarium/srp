void __thiscall Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::Pop<Scaleform::GFx::AS3::Value>(
        Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value> *this,
        Scaleform::GFx::AS3::Value *result)
{
  const Scaleform::GFx::AS3::Value *v3; // eax
  Scaleform::GFx::AS3::CheckResult v4; // [esp+7h] [ebp-11h] BYREF
  Scaleform::GFx::AS3::Value v5; // [esp+8h] [ebp-10h] BYREF

  if ( Scaleform::GFx::AS3::ArrayBase::CheckFixed(this, &v4)->Result )
  {
    if ( this->ValueA.Data.Size )
    {
      v3 = Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>>::Pop(
             &this->ValueA,
             &v5);
      Scaleform::GFx::AS3::Value::Assign(result, v3);
      if ( (v5.Flags & 0x1F) > 9 )
      {
        if ( (v5.Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v5);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v5);
      }
    }
  }
}
