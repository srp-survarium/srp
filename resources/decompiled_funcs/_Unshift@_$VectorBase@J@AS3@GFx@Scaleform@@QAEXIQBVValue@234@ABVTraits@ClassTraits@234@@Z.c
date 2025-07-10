void __thiscall Scaleform::GFx::AS3::VectorBase<long>::Unshift(
        Scaleform::GFx::AS3::VectorBase<unsigned long> *this,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *const argv,
        const Scaleform::GFx::AS3::ClassTraits::Traits *tr)
{
  Scaleform::ArrayDH<unsigned long,2,Scaleform::ArrayDefaultPolicy> *p_ValueA; // edi
  unsigned int v6; // eax
  Scaleform::GFx::AS3::Value::VU *p_value; // ecx
  Scaleform::GFx::AS3::CheckResult result; // [esp+Ah] [ebp-6h] BYREF
  Scaleform::GFx::AS3::CheckResult v9; // [esp+Bh] [ebp-5h] BYREF
  int v10; // [esp+Ch] [ebp-4h]

  v10 = 0;
  if ( Scaleform::GFx::AS3::ArrayBase::CheckFixed(this, &result)->Result
    && Scaleform::GFx::AS3::ArrayBase::CheckCorrectType(this, &v9, argc, argv, tr)->Result )
  {
    p_ValueA = &this->ValueA;
    tr = 0;
    Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned long,Scaleform::AllocatorDH<unsigned long,2>,Scaleform::ArrayDefaultPolicy>>::InsertMultipleAt(
      p_ValueA,
      0,
      argc,
      (unsigned int *)&tr);
    v6 = 0;
    if ( argc )
    {
      p_value = &argv->value;
      do
      {
        p_ValueA->Data.Data[v6++] = p_value->VS._1.VInt;
        p_value += 2;
      }
      while ( v6 < argc );
    }
  }
}
