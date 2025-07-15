void __thiscall Scaleform::GFx::AS3::Instances::fl::XMLList::AS3insertChildAfter(
        Scaleform::GFx::AS3::Instances::fl::XMLList *this,
        Scaleform::GFx::AS3::Value *result,
        const Scaleform::GFx::AS3::Value *child1,
        const Scaleform::GFx::AS3::Value *child2)
{
  Scaleform::GFx::AS3::CheckResult v5; // [esp+7h] [ebp-1h] BYREF

  if ( Scaleform::GFx::AS3::Instances::fl::XMLList::HasOneItem(this, &v5, "insertChildAfter")->Result )
    Scaleform::GFx::AS3::Instances::fl::XML::AS3insertChildAfter(this->List.Data.Data->pObject, result, child1, child2);
}
