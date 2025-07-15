Scaleform::GFx::AS3::GlobalSlotIndex *__thiscall Scaleform::GFx::AS3::Instances::fl::Namespace::GetNextPropIndex(
        Scaleform::GFx::AS3::Instances::fl::QName *this,
        Scaleform::GFx::AS3::GlobalSlotIndex *result,
        Scaleform::GFx::AS3::GlobalSlotIndex ind)
{
  Scaleform::GFx::AS3::GlobalSlotIndex *v3; // eax

  v3 = result;
  if ( ind.Index > 1 )
    result->Index = 0;
  else
    result->Index = ind.Index + 1;
  return v3;
}
