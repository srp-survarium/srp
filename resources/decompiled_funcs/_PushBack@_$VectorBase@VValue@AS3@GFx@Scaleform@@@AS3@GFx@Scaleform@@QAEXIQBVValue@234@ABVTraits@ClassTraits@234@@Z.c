void __thiscall Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::PushBack(
        Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value> *this,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *const argv,
        const Scaleform::GFx::AS3::ClassTraits::Traits *tr)
{
  int v5; // ebp
  const Scaleform::GFx::AS3::ClassTraits::Traits *v6; // ebx
  const Scaleform::GFx::AS3::Value *i; // esi
  Scaleform::GFx::AS3::CheckResult result; // [esp+7h] [ebp-11h] BYREF
  Scaleform::GFx::AS3::Value r; // [esp+8h] [ebp-10h] BYREF

  if ( Scaleform::GFx::AS3::ArrayBase::CheckFixed(this, &result)->Result )
  {
    v5 = 0;
    if ( argc )
    {
      v6 = tr;
      for ( i = argv; ; ++i )
      {
        r.Flags = 0;
        r.Bonus.pWeakProxy = 0;
        if ( !Scaleform::GFx::AS3::ArrayBase::CheckCoerce(this, (Scaleform::GFx::AS3::CheckResult *)&argv, v6, i, &r)->Result )
          break;
        Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::PushBackUnsafe(this, &r);
        if ( (r.Flags & 0x1F) > 9 )
        {
          if ( (r.Flags & 0x200) != 0 )
            Scaleform::GFx::AS3::Value::ReleaseWeakRef(&r);
          else
            Scaleform::GFx::AS3::Value::ReleaseInternal(&r);
        }
        if ( ++v5 >= argc )
          return;
      }
      if ( (r.Flags & 0x1F) > 9 )
      {
        if ( (r.Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&r);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(&r);
      }
    }
  }
}
