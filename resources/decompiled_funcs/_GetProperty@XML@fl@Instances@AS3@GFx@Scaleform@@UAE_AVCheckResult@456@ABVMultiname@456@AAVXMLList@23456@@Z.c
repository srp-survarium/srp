Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::Instances::fl::XML::GetProperty(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        Scaleform::GFx::AS3::CheckResult *result,
        const Scaleform::GFx::AS3::Multiname *prop_name,
        Scaleform::GFx::AS3::Instances::fl::XMLList *list)
{
  Scaleform::GFx::AS3::CheckResult *v5; // eax
  unsigned int ind; // [esp+4h] [ebp-4h] BYREF

  if ( !Scaleform::GFx::AS3::GetVectorInd((Scaleform::GFx::AS3::CheckResult *)&prop_name, prop_name, &ind)->Result
    || ind )
  {
    v5 = result;
    result->Result = 0;
  }
  else
  {
    Scaleform::GFx::AS3::Instances::fl::XMLList::Apppend(list, this);
    v5 = result;
    result->Result = 1;
  }
  return v5;
}
