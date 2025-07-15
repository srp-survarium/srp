void __thiscall Scaleform::GFx::AS3::Instances::fl::XMLList::AS3removeNamespace(
        Scaleform::GFx::AS3::Instances::fl::XMLList *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *result,
        const Scaleform::GFx::AS3::Value *ns)
{
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *v4; // eax
  Scaleform::GFx::AS3::CheckResult v5; // [esp+7h] [ebp-1h] BYREF

  if ( Scaleform::GFx::AS3::Instances::fl::XMLList::HasOneItem(this, &v5)->Result )
  {
    v4 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)this->List.Data.Data->pObject->RemoveNamespace(
                                                                    this->List.Data.Data->pObject,
                                                                    ns);
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)result,
      v4);
  }
}
