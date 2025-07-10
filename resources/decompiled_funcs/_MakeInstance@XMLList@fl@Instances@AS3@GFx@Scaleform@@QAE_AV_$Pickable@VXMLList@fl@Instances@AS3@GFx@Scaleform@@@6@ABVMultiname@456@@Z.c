Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *__thiscall Scaleform::GFx::AS3::Instances::fl::XMLList::MakeInstance(
        Scaleform::GFx::AS3::Instances::fl::XMLList *this,
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *result,
        Scaleform::GFx::AS3::SoundObject *mn)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *v3; // ebx
  Scaleform::GFx::AS3::SoundObject *v4; // esi
  unsigned int v5; // eax
  unsigned int v7; // eax
  int Namespace; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // edi
  Scaleform::GFx::AS3::Instances::fl::Namespace *NamespaceByURI; // eax
  Scaleform::GFx::AS3::VM *pVM; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *Pan; // esi
  bool v13; // zf
  Scaleform::GFx::AS3::InstanceTraits::fl::XMLList *v15; // [esp-14h] [ebp-20h]

  v3 = result;
  v4 = mn;
  v5 = (int)mn->Scaleform::GFx::ASSoundIntf::__vftable & 0x1F;
  result->pV = 0;
  if ( (_BYTE)v5 != 10 )
  {
    v3->pV = Scaleform::GFx::AS3::Instances::fl::XMLList::MakeInstance(
               this,
               (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&result)->pV;
    return v3;
  }
  v7 = (int)v4->Scaleform::RefCountBase<Scaleform::GFx::AS3::SoundObject,323>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,323>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable
     & 3;
  if ( v7 <= 1 && v4->RefCount )
  {
    Namespace = Scaleform::GFx::AS3::Multiname::GetNamespace(v4);
    pObject = (Scaleform::GFx::AS3::Instances::fl::Namespace *)Namespace;
    if ( (*(_BYTE *)(Namespace + 40) & 0x1F) != 0 )
      goto LABEL_12;
    NamespaceByURI = Scaleform::GFx::AS3::Instances::fl::XMLList::FindNamespaceByURI(
                       this,
                       (const Scaleform::GFx::ASString *)(Namespace + 28));
    goto LABEL_10;
  }
  pVM = this->pTraits.pObject->pVM;
  pObject = pVM->DefXMLNamespace.pObject;
  if ( !pObject )
  {
    pObject = pVM->PublicNamespace.pObject;
    goto LABEL_12;
  }
  if ( (pObject->Prefix.Flags & 0x1F) == 0 )
  {
    NamespaceByURI = Scaleform::GFx::AS3::Instances::fl::XMLList::FindNamespaceByURI(this, &pObject->Uri);
LABEL_10:
    if ( NamespaceByURI )
      pObject = NamespaceByURI;
  }
LABEL_12:
  Pan = (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *)v4->Pan;
  ++Pan[3].pV;
  v15 = (Scaleform::GFx::AS3::InstanceTraits::fl::XMLList *)this->pTraits.pObject;
  result = Pan;
  Scaleform::GFx::AS3::InstanceTraits::fl::XMLList::MakeInstance(
    v15,
    (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&mn,
    v15,
    (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)this,
    (const Scaleform::GFx::ASString *)&result,
    pObject);
  v13 = Pan[3].pV-- == (Scaleform::GFx::AS3::Instances::fl::XMLList *)1;
  v3->pV = (Scaleform::GFx::AS3::Instances::fl::XMLList *)mn;
  if ( v13 )
  {
    Scaleform::GFx::ASStringNode::ReleaseNode((Scaleform::GFx::ASStringNode *)Pan);
    return v3;
  }
  return v3;
}
