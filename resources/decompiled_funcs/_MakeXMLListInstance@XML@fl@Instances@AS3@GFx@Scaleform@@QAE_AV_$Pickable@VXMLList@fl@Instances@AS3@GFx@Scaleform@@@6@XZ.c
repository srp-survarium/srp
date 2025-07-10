Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *__thiscall Scaleform::GFx::AS3::Instances::fl::XML::MakeXMLListInstance(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *result)
{
  Scaleform::GFx::AS3::XMLSupport *pObject; // ecx
  Scaleform::GFx::AS3::InstanceTraits::Traits *v3; // edi
  Scaleform::GFx::AS3::Instance *v4; // eax
  Scaleform::GFx::AS3::Instances::fl::XMLList *v5; // esi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *v6; // eax

  pObject = this->pTraits.pObject->pVM->XMLSupport_.pObject;
  v3 = pObject->GetClassTraitsXMLList(pObject)->ITraits.pObject;
  v4 = (Scaleform::GFx::AS3::Instance *)Scaleform::GFx::AS3::Traits::Alloc(v3);
  v5 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)v4;
  if ( v4 )
  {
    Scaleform::GFx::AS3::Instance::Instance(v4, v3);
    v6 = result;
    v5->__vftable = (Scaleform::GFx::AS3::Instances::fl::XMLList_vtbl *)&Scaleform::GFx::AS3::Instances::fl::XMLList::`vftable';
    v5->TargetObject.pObject = 0;
    v5->TargetProperty = 0;
    v5->TargetNamespace.pObject = 0;
    v5->List.Data.Data = 0;
    v5->List.Data.Size = 0;
    v5->List.Data.Policy.Capacity = 0;
    result->pV = v5;
  }
  else
  {
    v6 = result;
    result->pV = 0;
  }
  return v6;
}
