Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::Instances::fl::XMLList::ResolveValue(
        Scaleform::GFx::AS3::Instances::fl::XMLList *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::Instances::fl::XML **el)
{
  Scaleform::GFx::AS3::Instances::fl::XML **v3; // ebp
  unsigned int Size; // eax
  Scaleform::GFx::AS3::VM *pVM; // esi
  Scaleform::GFx::AS3::CheckResult *v7; // eax
  const Scaleform::GFx::AS3::VM::Error *v8; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::Instances::fl::XML *pObject; // ebx
  Scaleform::GFx::AS3::Traits *v11; // eax
  Scaleform::GFx::AS3::BuiltinTraitsType TraitsType; // ecx
  Scaleform::GFx::AS3::InstanceTraits::fl::XML *v13; // eax
  Scaleform::GFx::ASStringNode *TargetProperty; // esi
  Scaleform::GFx::AS3::Instances::fl::Namespace *v16; // [esp-Ch] [ebp-2Ch]
  Scaleform::GFx::AS3::Instances::fl::XML *base; // [esp+10h] [ebp-10h] BYREF
  Scaleform::GFx::ASString n; // [esp+14h] [ebp-Ch] BYREF
  Scaleform::GFx::AS3::VM::Error v19; // [esp+18h] [ebp-8h] BYREF

  v3 = el;
  *el = 0;
  Size = this->List.Data.Size;
  pVM = this->pTraits.pObject->pVM;
  if ( Size )
  {
    if ( Size == 1 )
    {
      *v3 = this->List.Data.Data->pObject;
      v7 = result;
      result->Result = 1;
      return v7;
    }
    Scaleform::GFx::AS3::VM::Error::Error(&v19, eXMLAssigmentOneItemLists, this->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowTypeError(pVM, v8);
    pNode = v19.Message.pNode;
    --v19.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    goto LABEL_6;
  }
  pObject = (Scaleform::GFx::AS3::Instances::fl::XML *)this->TargetObject.pObject;
  if ( pObject )
  {
    if ( this->TargetProperty )
    {
      el = (Scaleform::GFx::AS3::Instances::fl::XML **)this->TargetProperty;
      if ( Scaleform::GFx::ASConstString::operator!=((Scaleform::GFx::ASConstString *)&el, "*") )
      {
        v11 = pObject->pTraits.pObject;
        TraitsType = v11->TraitsType;
        base = 0;
        if ( TraitsType == Traits_XML )
        {
          if ( (v11->Flags & 0x20) == 0 )
          {
            base = pObject;
            goto LABEL_16;
          }
        }
        else if ( TraitsType == Traits_XMLList
               && (v11->Flags & 0x20) == 0
               && Scaleform::GFx::AS3::Instances::fl::XMLList::ResolveValue(
                    (Scaleform::GFx::AS3::Instances::fl::XMLList *)pObject,
                    (Scaleform::GFx::AS3::CheckResult *)&el,
                    &base)->Result )
        {
LABEL_16:
          if ( base )
          {
            v13 = (Scaleform::GFx::AS3::InstanceTraits::fl::XML *)pVM->XMLSupport_.pObject->GetITraitsXML(pVM->XMLSupport_.pObject);
            TargetProperty = this->TargetProperty;
            ++TargetProperty->RefCount;
            v16 = this->TargetNamespace.pObject;
            n.pNode = TargetProperty;
            el = (Scaleform::GFx::AS3::Instances::fl::XML **)Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceElement(
                                                               v13,
                                                               (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLElement> *)&v19,
                                                               v13,
                                                               v16,
                                                               &n,
                                                               base)->pV;
            if ( TargetProperty->RefCount-- == 1 )
              Scaleform::GFx::ASStringNode::ReleaseNode(TargetProperty);
            base->AppendChild(base, (const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *)&el);
            Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
              (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> > *)&this->List,
              (const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits> *)&el);
            *v3 = (Scaleform::GFx::AS3::Instances::fl::XML *)el;
            Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>::~SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>((Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *)&el);
          }
          goto LABEL_20;
        }
LABEL_6:
        v7 = result;
        result->Result = 0;
        return v7;
      }
    }
  }
LABEL_20:
  v7 = result;
  result->Result = 1;
  return v7;
}
