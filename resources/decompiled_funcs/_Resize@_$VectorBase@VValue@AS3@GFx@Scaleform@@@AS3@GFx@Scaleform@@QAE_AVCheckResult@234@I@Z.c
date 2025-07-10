Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::Resize(
        Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value> *this,
        Scaleform::GFx::AS3::CheckResult *result,
        unsigned int newSise)
{
  unsigned int Size; // ebx
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *p_ValueA; // ebp
  int v6; // edi
  int v7; // esi
  Scaleform::GFx::AS3::Value *Null; // ecx
  Scaleform::GFx::AS3::CheckResult *v9; // eax
  Scaleform::GFx::AS3::CheckResult v10; // [esp+Bh] [ebp-11h] BYREF
  Scaleform::GFx::AS3::Value other; // [esp+Ch] [ebp-10h] BYREF

  if ( Scaleform::GFx::AS3::ArrayBase::CheckFixed(this, &v10)->Result )
  {
    Size = this->ValueA.Data.Size;
    p_ValueA = &this->ValueA;
    Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
      &this->ValueA.Data,
      newSise);
    if ( Size < newSise )
    {
      v6 = Size;
      v7 = newSise - Size;
      do
      {
        Null = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Value::GetNull();
        other = *Null;
        if ( (Null->Flags & 0x1F) > 9 )
        {
          if ( (Null->Flags & 0x200) != 0 )
            Scaleform::GFx::AS3::Value::AddRefWeakRef(Null);
          else
            Scaleform::GFx::AS3::Value::AddRefInternal(Null);
        }
        Scaleform::GFx::AS3::Value::Assign(&p_ValueA->Data.Data[v6], &other);
        if ( (other.Flags & 0x1F) > 9 )
        {
          if ( (other.Flags & 0x200) != 0 )
            Scaleform::GFx::AS3::Value::ReleaseWeakRef(&other);
          else
            Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
        }
        ++v6;
        --v7;
      }
      while ( v7 );
    }
    v9 = result;
    result->Result = 1;
  }
  else
  {
    v9 = result;
    result->Result = 0;
  }
  return v9;
}
