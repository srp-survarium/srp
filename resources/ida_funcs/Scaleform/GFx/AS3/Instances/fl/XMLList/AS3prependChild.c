void __thiscall Scaleform::GFx::AS3::Instances::fl::XMLList::AS3prependChild(
        Scaleform::GFx::AS3::Instances::fl::XMLList *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *result,
        const Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::CheckResult v4; // [esp+7h] [ebp-1h] BYREF

  if ( Scaleform::GFx::AS3::Instances::fl::XMLList::HasOneItem(this, &v4)->Result )
    Scaleform::GFx::AS3::Instances::fl::XML::AS3prependChild(this->List.Data.Data->pObject, result, value);
}
