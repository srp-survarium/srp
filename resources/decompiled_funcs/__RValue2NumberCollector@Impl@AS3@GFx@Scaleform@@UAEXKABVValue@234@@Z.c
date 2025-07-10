void __thiscall Scaleform::GFx::AS3::Impl::Value2NumberCollector::operator()(
        Scaleform::GFx::AS3::Impl::Value2NumberCollector *this,
        unsigned int ind,
        Scaleform::GFx::AS3::Value *v)
{
  const Scaleform::GFx::AS3::Value *v3; // edi
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Impl::Triple<double,Scaleform::GFx::AS3::Value const *,unsigned long>,2,Scaleform::ArrayDefaultPolicy> *Pairs; // ecx
  long double num; // [esp+8h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::Impl::Triple<double,Scaleform::GFx::AS3::Value const *,unsigned long> val; // [esp+10h] [ebp-18h] BYREF

  v3 = v;
  if ( Scaleform::GFx::AS3::Value::Convert2Number(v, (Scaleform::GFx::AS3::CheckResult *)&v, &num)->Result )
  {
    Pairs = this->Pairs;
    val.First = num;
    val.Second = v3;
    val.Third = ind;
    Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Impl::Triple<double,Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Impl::Triple<double,Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
      &Pairs->Data,
      &val);
  }
}
