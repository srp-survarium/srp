void __thiscall Scaleform::GFx::AS3::Instances::fl::XMLList::AS3replace(
        Scaleform::GFx::AS3::Instances::fl::XMLList *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *result,
        const Scaleform::GFx::AS3::Value *propertyName,
        const Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::CheckResult v5; // [esp+7h] [ebp-1h] BYREF

  if ( Scaleform::GFx::AS3::Instances::fl::XMLList::HasOneItem(this, &v5, "replace")->Result )
    Scaleform::GFx::AS3::Instances::fl::XML::AS3replace(this->List.Data.Data->pObject, result, propertyName, value);
}
