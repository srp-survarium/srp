void __thiscall Scaleform::GFx::AS3::Instances::fl::Array::AS3concat(
        Scaleform::GFx::AS3::Instances::fl::Array *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Instances::fl::Array *pV; // edi
  Scaleform::GFx::AS3::Traits *ValueTraits; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> r; // [esp+8h] [ebp-4h] BYREF

  Scaleform::GFx::AS3::InstanceTraits::MakeInstance<Scaleform::GFx::AS3::InstanceTraits::fl::Array>(
    &r,
    (Scaleform::GFx::AS3::InstanceTraits::fl::Array *)this->pTraits.pObject);
  pV = r.pV;
  Scaleform::GFx::AS3::Value::Pick(result, r.pV);
  if ( pV != this )
    Scaleform::GFx::AS3::Impl::SparseArray::Assign(&pV->SA, &this->SA);
  ValueTraits = Scaleform::GFx::AS3::VM::GetValueTraits(this->pTraits.pObject->pVM, argv);
  if ( argc == 1 && ValueTraits->TraitsType == Traits_Array && (ValueTraits->Flags & 0x20) == 0 )
    Scaleform::GFx::AS3::Impl::SparseArray::Append(
      &pV->SA,
      (Scaleform::GFx::AS3::Impl::SparseArray *)(argv->value.VS._1.VInt + 32),
      0,
      *(_DWORD *)(argv->value.VS._1.VInt + 32));
  else
    Scaleform::GFx::AS3::Impl::SparseArray::Append(&pV->SA, argc, argv);
}
