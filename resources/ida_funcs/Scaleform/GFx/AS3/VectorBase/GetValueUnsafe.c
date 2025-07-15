void __thiscall Scaleform::GFx::AS3::VectorBase<long>::GetValueUnsafe(
        Scaleform::GFx::AS3::VectorBase<long> *this,
        unsigned int ind,
        Scaleform::GFx::AS3::Value *v)
{
  unsigned int v3; // edx
  Scaleform::GFx::AS3::Value::V2U v4; // [esp+4h] [ebp-4h]

  v3 = v->Flags & 0xFFFFFFE2;
  v->value.VS._1.VInt = this->ValueA.Data.Data[ind];
  v->Flags = v3 | 2;
  v->value.VS._2 = v4;
}


void __thiscall Scaleform::GFx::AS3::VectorBase<unsigned long>::GetValueUnsafe(
        Scaleform::GFx::AS3::VectorBase<unsigned long> *this,
        unsigned int ind,
        Scaleform::GFx::AS3::Value *v)
{
  unsigned int v3; // edx
  Scaleform::GFx::AS3::Value::V2U v4; // [esp+4h] [ebp-4h]

  v3 = v->Flags & 0xFFFFFFE3;
  v->value.VS._1.VInt = this->ValueA.Data.Data[ind];
  v->Flags = v3 | 3;
  v->value.VS._2 = v4;
}


void __thiscall Scaleform::GFx::AS3::VectorBase<double>::GetValueUnsafe(
        Scaleform::GFx::AS3::VectorBase<double> *this,
        unsigned int ind,
        Scaleform::GFx::AS3::Value *v)
{
  long double v3; // [esp+0h] [ebp-8h]

  v3 = this->ValueA.Data.Data[ind];
  v->Flags = v->Flags & 0xFFFFFFE0 | 4;
  v->value.VNumber = v3;
}


void __thiscall Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::GetValueUnsafe(
        Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value> *this,
        unsigned int ind,
        Scaleform::GFx::AS3::Value *v)
{
  Scaleform::GFx::AS3::Value::AssignUnsafe(v, &this->ValueA.Data.Data[ind]);
}


void __thiscall Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::GetValueUnsafe(
        Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> > *this,
        unsigned int ind,
        Scaleform::GFx::AS3::Value *v)
{
  Scaleform::GFx::AS3::Value::AssignUnsafe(v, this->ValueA.Data.Data[ind].pObject);
}
