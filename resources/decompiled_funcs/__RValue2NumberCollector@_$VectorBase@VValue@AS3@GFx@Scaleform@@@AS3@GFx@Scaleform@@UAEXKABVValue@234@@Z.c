void __thiscall Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::Value2NumberCollector::operator()(
        Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::Value2NumberCollector *this,
        unsigned int ind,
        Scaleform::GFx::AS3::Value *v)
{
  Scaleform::ArrayDH<Scaleform::Pair<double,unsigned long>,2,Scaleform::ArrayDefaultPolicy> *Pairs; // ecx
  long double num; // [esp+4h] [ebp-18h] BYREF
  Scaleform::Pair<double,unsigned long> val; // [esp+Ch] [ebp-10h] BYREF

  if ( Scaleform::GFx::AS3::Value::Convert2Number(v, (Scaleform::GFx::AS3::CheckResult *)&v, &num)->Result )
  {
    Pairs = this->Pairs;
    val.First = num;
    val.Second = ind;
    Scaleform::ArrayDataDH<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
      &Pairs->Data,
      &val);
  }
}
