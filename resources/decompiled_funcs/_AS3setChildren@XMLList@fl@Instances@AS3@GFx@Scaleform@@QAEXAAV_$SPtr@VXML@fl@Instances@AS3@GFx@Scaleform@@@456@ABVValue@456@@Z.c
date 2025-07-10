void __thiscall Scaleform::GFx::AS3::Instances::fl::XMLList::AS3setChildren(
        Scaleform::GFx::AS3::Instances::fl::XMLList *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *result,
        const Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::Instances::fl::XML *pObject; // esi
  Scaleform::GFx::AS3::CheckResult v5; // [esp+7h] [ebp-1h] BYREF

  if ( Scaleform::GFx::AS3::Instances::fl::XMLList::HasOneItem(this, &v5)->Result )
  {
    pObject = this->List.Data.Data->pObject;
    pObject->SetChildren(pObject, value);
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)result,
      (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)pObject);
  }
}
