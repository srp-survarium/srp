void __thiscall Scaleform::GFx::AS3::Instances::fl::XML::AS3comments(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *result)
{
  Scaleform::GFx::AS3::VM *pVM; // eax
  Scaleform::GFx::ASStringManager *pStringManager; // esi
  Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // ebx
  Scaleform::GFx::AS3::XMLSupport *v6; // ecx
  const Scaleform::GFx::AS3::ClassTraits::Traits *(__thiscall *GetClassTraitsXMLList)(Scaleform::GFx::AS3::XMLSupport *); // eax
  Scaleform::GFx::ASStringNode *p_NullStringNode; // esi
  int v9; // eax
  Scaleform::GFx::AS3::Instances::fl::XMLList *v11; // ecx
  Scaleform::GFx::AS3::Instances::fl::XMLList *pV; // ebx
  unsigned int RefCount; // eax
  Scaleform::GFx::ASString target_prop; // [esp+Ch] [ebp-8h] BYREF
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> list; // [esp+10h] [ebp-4h] BYREF

  pVM = this->pTraits.pObject->pVM;
  pStringManager = pVM->StringManagerRef->pStringManager;
  pObject = pVM->PublicNamespace.pObject;
  ++pStringManager->NullStringNode.RefCount;
  v6 = this->pTraits.pObject->pVM->XMLSupport_.pObject;
  GetClassTraitsXMLList = v6->GetClassTraitsXMLList;
  p_NullStringNode = &pStringManager->NullStringNode;
  target_prop.pNode = p_NullStringNode;
  v9 = (int)GetClassTraitsXMLList(v6);
  Scaleform::GFx::AS3::InstanceTraits::fl::XMLList::MakeInstance(
    *(Scaleform::GFx::AS3::InstanceTraits::fl::XMLList **)(v9 + 100),
    &list,
    *(Scaleform::GFx::AS3::InstanceTraits::Traits **)(v9 + 100),
    (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)this,
    &target_prop,
    pObject);
  if ( p_NullStringNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_NullStringNode);
  v11 = result->pObject;
  pV = list.pV;
  if ( list.pV != result->pObject )
  {
    if ( v11 )
    {
      if ( ((unsigned __int8)v11 & 1) != 0 )
      {
        result->pObject = (Scaleform::GFx::AS3::Instances::fl::XMLList *)((char *)v11 - 1);
      }
      else
      {
        RefCount = v11->RefCount;
        if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
        {
          v11->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v11);
        }
      }
    }
    result->pObject = pV;
  }
  this->GetChildren(this, pV, kComment, 0);
}
