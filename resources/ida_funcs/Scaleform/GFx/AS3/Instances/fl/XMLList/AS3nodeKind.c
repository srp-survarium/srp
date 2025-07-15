void __thiscall Scaleform::GFx::AS3::Instances::fl::XMLList::AS3nodeKind(
        Scaleform::GFx::AS3::Instances::fl::XMLList *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::AS3::CheckResult v3; // [esp+7h] [ebp-1h] BYREF

  if ( Scaleform::GFx::AS3::Instances::fl::XMLList::HasOneItem(this, &v3)->Result )
    Scaleform::GFx::AS3::Instances::fl::XML::AS3nodeKind(this->List.Data.Data->pObject, result);
}
