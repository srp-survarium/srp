Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *__thiscall Scaleform::GFx::AS3::Instances::fl::XML::MakeXMLListInstance(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *result,
        Scaleform::GFx::AS3::SoundObject *mn)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *v3; // ebx
  Scaleform::GFx::AS3::SoundObject *v4; // esi
  unsigned int v5; // eax
  unsigned int v7; // eax
  int Namespace; // edi
  Scaleform::GFx::AS3::VM *pVM; // eax
  int v10; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *Pan; // esi
  Scaleform::GFx::AS3::XMLSupport *pObject; // ecx
  const Scaleform::GFx::AS3::ClassTraits::Traits *(__thiscall *GetClassTraitsXMLList)(Scaleform::GFx::AS3::XMLSupport *); // eax
  int v14; // eax
  bool v15; // zf

  v3 = result;
  v4 = mn;
  v5 = (int)mn->Scaleform::GFx::ASSoundIntf::__vftable & 0x1F;
  result->pV = 0;
  if ( (_BYTE)v5 != 10 )
  {
    v3->pV = Scaleform::GFx::AS3::Instances::fl::XML::MakeXMLListInstance(
               this,
               (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&result)->pV;
    return v3;
  }
  v7 = (int)v4->Scaleform::RefCountBase<Scaleform::GFx::AS3::SoundObject,323>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,323>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable
     & 3;
  if ( v7 <= 1 && v4->RefCount )
  {
    Namespace = Scaleform::GFx::AS3::Multiname::GetNamespace(v4);
    if ( (*(_BYTE *)(Namespace + 40) & 0x1F) != 0 )
      goto LABEL_11;
LABEL_9:
    v10 = ((int (__stdcall *)(int, _DWORD))this->FindNamespaceByURI)(Namespace + 28, 0);
    if ( v10 )
      Namespace = v10;
    goto LABEL_11;
  }
  pVM = this->pTraits.pObject->pVM;
  Namespace = (int)pVM->DefXMLNamespace.pObject;
  if ( !Namespace )
  {
    Namespace = (int)pVM->PublicNamespace.pObject;
    goto LABEL_11;
  }
  if ( (*(_BYTE *)(Namespace + 40) & 0x1F) == 0 )
    goto LABEL_9;
LABEL_11:
  Pan = (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *)v4->Pan;
  ++Pan[3].pV;
  pObject = this->pTraits.pObject->pVM->XMLSupport_.pObject;
  GetClassTraitsXMLList = pObject->GetClassTraitsXMLList;
  result = Pan;
  v14 = (int)GetClassTraitsXMLList(pObject);
  Scaleform::GFx::AS3::InstanceTraits::fl::XMLList::MakeInstance(
    *(Scaleform::GFx::AS3::InstanceTraits::fl::XMLList **)(v14 + 100),
    (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&mn,
    *(Scaleform::GFx::AS3::InstanceTraits::Traits **)(v14 + 100),
    (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)this,
    (const Scaleform::GFx::ASString *)&result,
    (Scaleform::GFx::AS3::Instances::fl::Namespace *)Namespace);
  v15 = Pan[3].pV-- == (Scaleform::GFx::AS3::Instances::fl::XMLList *)1;
  v3->pV = (Scaleform::GFx::AS3::Instances::fl::XMLList *)mn;
  if ( v15 )
  {
    Scaleform::GFx::ASStringNode::ReleaseNode((Scaleform::GFx::ASStringNode *)Pan);
    return v3;
  }
  return v3;
}
