void __thiscall Scaleform::GFx::AS3::Instances::fl::Array::AS3unshift(
        Scaleform::GFx::AS3::Instances::fl::Array *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Impl::SparseArray *p_SA; // esi
  Scaleform::GFx::AS3::Value::V1U Length; // esi
  unsigned int v6; // eax
  Scaleform::GFx::AS3::Value::V2U v7; // [esp+Ch] [ebp-4h]

  p_SA = &this->SA;
  Scaleform::GFx::AS3::Impl::SparseArray::Insert(&this->SA, 0, argc, argv);
  Length = (Scaleform::GFx::AS3::Value::V1U)p_SA->Length;
  if ( (result->Flags & 0x1F) > 9 )
  {
    if ( (result->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(result);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(result);
  }
  v6 = result->Flags & 0xFFFFFFE0 | 3;
  result->value.VS._1 = Length;
  result->Flags = v6;
  result->value.VS._2 = v7;
}
