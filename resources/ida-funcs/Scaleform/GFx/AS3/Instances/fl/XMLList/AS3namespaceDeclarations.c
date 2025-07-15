void __thiscall Scaleform::GFx::AS3::Instances::fl::XMLList::AS3namespaceDeclarations(
        Scaleform::GFx::AS3::Instances::fl::XMLList *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array> *result)
{
  Scaleform::GFx::AS3::CheckResult v3; // [esp+7h] [ebp-1h] BYREF

  if ( Scaleform::GFx::AS3::Instances::fl::XMLList::HasOneItem(this, &v3, "namespaceDeclarations")->Result )
    Scaleform::GFx::AS3::Instances::fl::XML::AS3namespaceDeclarations(this->List.Data.Data->pObject, result);
}
