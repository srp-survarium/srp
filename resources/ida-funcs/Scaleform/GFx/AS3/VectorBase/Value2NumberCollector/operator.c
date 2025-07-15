void __thiscall Scaleform::GFx::AS3::VectorBase<long>::Value2NumberCollector::operator()(
        Scaleform::GFx::AS3::VectorBase<long>::Value2NumberCollector *this,
        unsigned int ind,
        const int *v)
{
  Scaleform::ArrayDH<Scaleform::Pair<double,unsigned long>,2,Scaleform::ArrayDefaultPolicy> *Pairs; // ecx
  Scaleform::Pair<double,unsigned long> val; // [esp+0h] [ebp-10h] BYREF

  Pairs = this->Pairs;
  val.First = (double)*v;
  val.Second = ind;
  Scaleform::ArrayDataDH<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
    &Pairs->Data,
    &val);
}


void __thiscall Scaleform::GFx::AS3::VectorBase<unsigned long>::Value2NumberCollector::operator()(
        Scaleform::GFx::AS3::VectorBase<unsigned long>::Value2NumberCollector *this,
        unsigned int ind,
        const unsigned int *v)
{
  Scaleform::ArrayDH<Scaleform::Pair<double,unsigned long>,2,Scaleform::ArrayDefaultPolicy> *Pairs; // ecx
  Scaleform::Pair<double,unsigned long> val; // [esp+0h] [ebp-10h] BYREF

  val.First = (double)*v;
  Pairs = this->Pairs;
  val.Second = ind;
  Scaleform::ArrayDataDH<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
    &Pairs->Data,
    &val);
}


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


void __thiscall Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::Value2NumberCollector::operator()(
        Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> >::Value2NumberCollector *this,
        unsigned int ind,
        const Scaleform::Ptr<Scaleform::GFx::ASStringNode> *v)
{
  Scaleform::ArrayDH<Scaleform::Pair<double,unsigned long>,2,Scaleform::ArrayDefaultPolicy> *Pairs; // ecx
  long double num; // [esp+4h] [ebp-28h] BYREF
  Scaleform::GFx::AS3::Value value; // [esp+Ch] [ebp-20h] BYREF
  Scaleform::Pair<double,unsigned long> val; // [esp+1Ch] [ebp-10h] BYREF

  Scaleform::GFx::AS3::Value::Value(&value, v->pObject);
  if ( Scaleform::GFx::AS3::Value::Convert2Number(&value, (Scaleform::GFx::AS3::CheckResult *)&v, &num)->Result )
  {
    Pairs = this->Pairs;
    val.First = num;
    val.Second = ind;
    Scaleform::ArrayDataDH<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
      &Pairs->Data,
      &val);
  }
  if ( (value.Flags & 0x1F) > 9 )
  {
    if ( (value.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&value);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&value);
  }
}
