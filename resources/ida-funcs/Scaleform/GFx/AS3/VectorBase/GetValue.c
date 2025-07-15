void __thiscall Scaleform::GFx::AS3::VectorBase<long>::GetValue(
        Scaleform::GFx::AS3::VectorBase<long> *this,
        unsigned int ind,
        Scaleform::GFx::AS3::Value *v)
{
  Scaleform::GFx::AS3::Value::V1U v3; // edi
  unsigned int v4; // eax
  Scaleform::GFx::AS3::Value::V2U v5; // [esp+Ch] [ebp-4h]

  v3 = (Scaleform::GFx::AS3::Value::V1U)this->ValueA.Data.Data[ind];
  if ( (v->Flags & 0x1F) > 9 )
  {
    if ( (v->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(v);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(v);
  }
  v4 = v->Flags & 0xFFFFFFE2;
  v->value.VS._1 = v3;
  v->Flags = v4 | 2;
  v->value.VS._2 = v5;
}


void __thiscall Scaleform::GFx::AS3::VectorBase<unsigned long>::GetValue(
        Scaleform::GFx::AS3::VectorBase<unsigned long> *this,
        unsigned int ind,
        Scaleform::GFx::AS3::Value *v)
{
  Scaleform::GFx::AS3::Value::V1U v3; // edi
  unsigned int v4; // eax
  Scaleform::GFx::AS3::Value::V2U v5; // [esp+Ch] [ebp-4h]

  v3 = (Scaleform::GFx::AS3::Value::V1U)this->ValueA.Data.Data[ind];
  if ( (v->Flags & 0x1F) > 9 )
  {
    if ( (v->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(v);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(v);
  }
  v4 = v->Flags & 0xFFFFFFE3;
  v->value.VS._1 = v3;
  v->Flags = v4 | 3;
  v->value.VS._2 = v5;
}


void __thiscall Scaleform::GFx::AS3::VectorBase<double>::GetValue(
        Scaleform::GFx::AS3::VectorBase<double> *this,
        unsigned int ind,
        Scaleform::GFx::AS3::Value *v)
{
  double v3; // [esp+4h] [ebp-8h]

  v3 = this->ValueA.Data.Data[ind];
  if ( (v->Flags & 0x1F) > 9 )
  {
    if ( (v->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(v);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(v);
  }
  v->Flags = v->Flags & 0xFFFFFFE0 | 4;
  v->value.VNumber = v3;
}


void __thiscall Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::GetValue(
        Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value> *this,
        unsigned int ind,
        Scaleform::GFx::AS3::Value *v)
{
  Scaleform::GFx::AS3::Value::Assign(v, &this->ValueA.Data.Data[ind]);
}


void __thiscall Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::GetValue(
        Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> > *this,
        unsigned int ind,
        Scaleform::GFx::AS3::Value *v)
{
  Scaleform::GFx::AS3::Value::Assign(v, this->ValueA.Data.Data[ind].pObject);
}
