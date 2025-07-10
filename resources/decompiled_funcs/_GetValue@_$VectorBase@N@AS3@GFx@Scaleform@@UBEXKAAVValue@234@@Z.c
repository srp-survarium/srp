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
