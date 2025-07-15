void __thiscall Scaleform::GFx::AS3::Instances::fl::XMLList::AS3setNamespace(
        Scaleform::GFx::AS3::Instances::fl::XMLList *this,
        const Scaleform::GFx::AS3::Value *result,
        const Scaleform::GFx::AS3::Value *ns)
{
  Scaleform::GFx::AS3::CheckResult v4; // [esp+7h] [ebp-1h] BYREF

  if ( Scaleform::GFx::AS3::Instances::fl::XMLList::HasOneItem(this, &v4)->Result )
    Scaleform::GFx::AS3::Instances::fl::XML::AS3setNamespace(this->List.Data.Data->pObject, result, ns);
}
