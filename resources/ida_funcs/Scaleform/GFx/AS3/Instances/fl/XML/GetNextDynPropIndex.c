Scaleform::GFx::AS3::GlobalSlotIndex *__thiscall Scaleform::GFx::AS3::Instances::fl::XML::GetNextDynPropIndex(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        Scaleform::GFx::AS3::GlobalSlotIndex *result,
        Scaleform::GFx::AS3::GlobalSlotIndex ind)
{
  Scaleform::GFx::AS3::GlobalSlotIndex *v3; // eax

  v3 = result;
  if ( ind.Index )
    result->Index = 0;
  else
    result->Index = 1;
  return v3;
}
