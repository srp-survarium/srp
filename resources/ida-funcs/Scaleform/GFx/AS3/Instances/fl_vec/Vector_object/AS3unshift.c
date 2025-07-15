void __thiscall Scaleform::GFx::AS3::Instances::fl_vec::Vector_object::AS3unshift(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Class *Constructor; // eax
  unsigned int Size; // esi
  unsigned int v7; // edx
  Scaleform::GFx::AS3::Value::V2U v8; // [esp+Ch] [ebp-4h]

  Constructor = Scaleform::GFx::AS3::Traits::GetConstructor(this->pTraits.pObject);
  Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::Unshift(
    &this->V,
    argc,
    argv,
    (Scaleform::GFx::AS3::ClassTraits::Traits *)Constructor->pTraits.pObject[1]._pRCC);
  Size = this->V.ValueA.Data.Size;
  if ( (result->Flags & 0x1F) > 9 )
  {
    if ( (result->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(result);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(result);
  }
  v7 = result->Flags & 0xFFFFFFE0 | 3;
  result->value.VS._1.VInt = Size;
  result->Flags = v7;
  result->value.VS._2 = v8;
}
