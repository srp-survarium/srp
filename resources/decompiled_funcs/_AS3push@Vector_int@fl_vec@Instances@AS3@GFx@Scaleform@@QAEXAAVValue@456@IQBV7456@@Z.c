void __thiscall Scaleform::GFx::AS3::Instances::fl_vec::Vector_int::AS3push(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_int *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  unsigned int Size; // esi
  unsigned int v6; // eax
  Scaleform::GFx::AS3::Value::V2U v7; // [esp+Ch] [ebp-4h]

  Scaleform::GFx::AS3::VectorBase<unsigned long>::PushBack(
    (Scaleform::GFx::AS3::VectorBase<unsigned long> *)&this->V,
    argc,
    argv,
    this->pTraits.pObject->pVM->TraitsInt.pObject);
  Size = this->V.ValueA.Data.Size;
  if ( (result->Flags & 0x1F) > 9 )
  {
    if ( (result->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(result);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(result);
  }
  v6 = result->Flags & 0xFFFFFFE0 | 3;
  result->value.VS._1.VInt = Size;
  result->Flags = v6;
  result->value.VS._2 = v7;
}
