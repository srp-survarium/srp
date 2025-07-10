Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *__thiscall Scaleform::GFx::AS3::Instances::fl::XMLList::MakeInstance(
        Scaleform::GFx::AS3::Instances::fl::XMLList *this,
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *result)
{
  Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // eax
  Scaleform::GFx::AS3::InstanceTraits::fl::XMLList *v3; // edi
  Scaleform::GFx::ASStringNode *TargetProperty; // esi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *v6; // eax
  Scaleform::GFx::AS3::Instance *v7; // eax
  Scaleform::GFx::AS3::Instances::fl::XMLList *v8; // esi
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *v9; // [esp-Ch] [ebp-1Ch]
  Scaleform::GFx::ASString target_prop; // [esp+Ch] [ebp-4h] BYREF

  pObject = this->TargetNamespace.pObject;
  v3 = (Scaleform::GFx::AS3::InstanceTraits::fl::XMLList *)this->pTraits.pObject;
  if ( pObject && this->TargetObject.pObject && (TargetProperty = this->TargetProperty) != 0 )
  {
    ++TargetProperty->RefCount;
    v9 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)this->TargetObject.pObject;
    target_prop.pNode = TargetProperty;
    Scaleform::GFx::AS3::InstanceTraits::fl::XMLList::MakeInstance(v3, result, v3, v9, &target_prop, pObject);
    if ( TargetProperty->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(TargetProperty);
    return result;
  }
  else
  {
    v7 = (Scaleform::GFx::AS3::Instance *)Scaleform::GFx::AS3::Traits::Alloc(this->pTraits.pObject);
    v8 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)v7;
    if ( v7 )
    {
      Scaleform::GFx::AS3::Instance::Instance(v7, v3);
      v6 = result;
      v8->__vftable = (Scaleform::GFx::AS3::Instances::fl::XMLList_vtbl *)&Scaleform::GFx::AS3::Instances::fl::XMLList::`vftable';
      v8->TargetObject.pObject = 0;
      v8->TargetProperty = 0;
      v8->TargetNamespace.pObject = 0;
      v8->List.Data.Data = 0;
      v8->List.Data.Size = 0;
      v8->List.Data.Policy.Capacity = 0;
      result->pV = v8;
    }
    else
    {
      v6 = result;
      result->pV = 0;
    }
  }
  return v6;
}
