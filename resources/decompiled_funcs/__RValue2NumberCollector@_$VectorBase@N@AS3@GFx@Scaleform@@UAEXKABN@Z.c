void __thiscall Scaleform::GFx::AS3::VectorBase<double>::Value2NumberCollector::operator()(
        Scaleform::GFx::AS3::VectorBase<double>::Value2NumberCollector *this,
        unsigned int ind,
        long double *v)
{
  Scaleform::ArrayDH<Scaleform::Pair<double,unsigned long>,2,Scaleform::ArrayDefaultPolicy> *Pairs; // ecx
  Scaleform::Pair<double,unsigned long> val; // [esp+0h] [ebp-10h] BYREF

  Pairs = this->Pairs;
  val.First = *v;
  val.Second = ind;
  Scaleform::ArrayDataDH<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
    &Pairs->Data,
    &val);
}
