void __thiscall Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::Unshift(
        Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value> *this,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv,
        const Scaleform::GFx::AS3::ClassTraits::Traits *tr)
{
  unsigned int v4; // esi
  Scaleform::GFx::AS3::Value *v6; // edi
  Scaleform::GFx::AS3::CheckResult result; // [esp+Ah] [ebp-16h] BYREF
  Scaleform::GFx::AS3::CheckResult v8; // [esp+Bh] [ebp-15h] BYREF
  int v9; // [esp+Ch] [ebp-14h]
  Scaleform::GFx::AS3::Value val; // [esp+10h] [ebp-10h] BYREF

  v4 = 0;
  v9 = 0;
  if ( Scaleform::GFx::AS3::ArrayBase::CheckFixed(this, &result)->Result )
  {
    v6 = argv;
    if ( Scaleform::GFx::AS3::ArrayBase::CheckCorrectType(this, &v8, argc, argv, tr)->Result )
    {
      val.Flags = 0;
      val.Bonus.pWeakProxy = 0;
      Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>>::InsertMultipleAt(
        &this->ValueA,
        0,
        argc,
        &val);
      if ( (val.Flags & 0x1F) > 9 )
      {
        if ( (val.Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&val);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(&val);
      }
      if ( argc )
      {
        do
          Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::SetUnsafe(this, v4++, v6++);
        while ( v4 < argc );
      }
    }
  }
}
