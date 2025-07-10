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
