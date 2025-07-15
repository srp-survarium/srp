void __thiscall Scaleform::GFx::AS3::AS3Vectoruint_DIPixelProvider::WriteNextPixel(
        Scaleform::GFx::AS3::AS3Vectoruint_DIPixelProvider *this,
        unsigned int pixel)
{
  unsigned int Location; // eax
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *PixelVector; // ecx
  const Scaleform::GFx::AS3::ClassTraits::Traits *pObject; // [esp-4h] [ebp-18h]
  Scaleform::GFx::AS3::Value v; // [esp+4h] [ebp-10h] BYREF

  Location = this->Location;
  this->Location = Location + 1;
  PixelVector = this->PixelVector;
  pObject = PixelVector->pTraits.pObject->pVM->TraitsUint.pObject;
  v.Flags = 3;
  v.Bonus.pWeakProxy = 0;
  v.value.VS._1.VInt = pixel;
  Scaleform::GFx::AS3::VectorBase<unsigned long>::Set(
    (Scaleform::GFx::AS3::VectorBase<long> *)&PixelVector->V,
    (Scaleform::GFx::AS3::CheckResult *)&pixel,
    Location,
    &v,
    pObject);
  if ( (v.Flags & 0x1F) > 9 )
  {
    if ( (v.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
  }
}
