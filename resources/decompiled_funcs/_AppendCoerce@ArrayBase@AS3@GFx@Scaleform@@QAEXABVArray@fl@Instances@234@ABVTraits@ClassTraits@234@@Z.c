void __thiscall Scaleform::GFx::AS3::ArrayBase::AppendCoerce(
        Scaleform::GFx::AS3::ArrayBase *this,
        const Scaleform::GFx::AS3::Instances::fl::Array *arr,
        const Scaleform::GFx::AS3::ClassTraits::Traits *tr)
{
  Scaleform::GFx::AS3::Impl::SparseArray *p_SA; // ebp
  unsigned int v5; // edi
  const Scaleform::GFx::AS3::ClassTraits::Traits *v6; // ebx
  const Scaleform::GFx::AS3::Value *v7; // eax
  Scaleform::GFx::AS3::CheckResult result; // [esp+7h] [ebp-15h] BYREF
  unsigned int size; // [esp+8h] [ebp-14h]
  Scaleform::GFx::AS3::Value r; // [esp+Ch] [ebp-10h] BYREF

  if ( Scaleform::GFx::AS3::ArrayBase::CheckFixed(this, &result)->Result )
  {
    p_SA = &arr->SA;
    v5 = 0;
    size = arr->SA.Length;
    if ( size )
    {
      v6 = tr;
      while ( 1 )
      {
        r.Flags = 0;
        r.Bonus.pWeakProxy = 0;
        v7 = Scaleform::GFx::AS3::Impl::SparseArray::At(p_SA, v5);
        if ( !Scaleform::GFx::AS3::ArrayBase::CheckCoerce(this, (Scaleform::GFx::AS3::CheckResult *)&arr, v6, v7, &r)->Result )
          break;
        this->PushBackValueUnsafe(this, &r);
        if ( (r.Flags & 0x1F) > 9 )
        {
          if ( (r.Flags & 0x200) != 0 )
            Scaleform::GFx::AS3::Value::ReleaseWeakRef(&r);
          else
            Scaleform::GFx::AS3::Value::ReleaseInternal(&r);
        }
        if ( ++v5 >= size )
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
