void __thiscall Scaleform::GFx::AS3::VectorBase<unsigned long>::Get(
        Scaleform::GFx::AS3::VectorBase<unsigned long> *this,
        unsigned int ind,
        Scaleform::GFx::AS3::Value *v)
{
  Scaleform::GFx::AS3::Value::V1U v3; // edi
  unsigned int v4; // eax
  Scaleform::GFx::AS3::Value::V2U v5; // [esp+4h] [ebp-4h]

  if ( ind < this->ValueA.Data.Size )
  {
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
}
