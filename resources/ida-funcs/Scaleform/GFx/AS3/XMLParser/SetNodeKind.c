void __thiscall Scaleform::GFx::AS3::XMLParser::SetNodeKind(
        Scaleform::GFx::AS3::XMLParser *this,
        Scaleform::GFx::AS3::XMLParser::Kind k)
{
  Scaleform::GFx::AS3::XMLParser::Kind NodeKind; // eax
  Scaleform::GFx::ASStringNode *v4; // esi
  Scaleform::GFx::ASStringNode *pNode; // ecx
  bool v6; // zf
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLText> *InstanceText; // eax
  Scaleform::GFx::AS3::Instances::fl::XML *pObject; // ecx
  unsigned int RefCount; // edx
  Scaleform::GFx::AS3::Instances::fl::XML *v10; // ecx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> ptr_el; // [esp+4h] [ebp-8h] BYREF
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLText> result; // [esp+8h] [ebp-4h] BYREF

  NodeKind = this->NodeKind;
  if ( NodeKind != k )
  {
    if ( NodeKind == kText )
    {
      if ( BYTE2(Scaleform::GFx::AS3::Traits::GetConstructor(this->ITr)[1].__vftable) )
      {
        v4 = Scaleform::GFx::ASConstString::TruncateWhitespaceNode(&this->Text);
        v4->RefCount += 2;
        pNode = this->Text.pNode;
        v6 = pNode->RefCount-- == 1;
        if ( v6 )
          Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
        this->Text.pNode = v4;
        v6 = v4->RefCount-- == 1;
        if ( v6 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v4);
      }
      if ( this->Text.pNode->Size )
      {
        InstanceText = Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceText(
                         this->ITr,
                         &result,
                         this->ITr,
                         &this->Text,
                         this->pCurrElem.pObject);
        pObject = this->pCurrElem.pObject;
        ptr_el.pObject = InstanceText->pV;
        if ( pObject && pObject->GetKind(pObject) == kElement )
        {
          this->pCurrElem.pObject->AppendChild(this->pCurrElem.pObject, &ptr_el);
        }
        else
        {
          Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
            &this->RootElements,
            &ptr_el);
          Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event>::Set(
            (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)&this->pCurrElem,
            (const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)&ptr_el);
        }
        Scaleform::GFx::ASString::Clear(&this->Text);
        if ( ptr_el.pObject && ((int)ptr_el.pObject & 1) == 0 )
        {
          RefCount = ptr_el.pObject->RefCount;
          v10 = ptr_el.pObject;
          if ( (RefCount & 0x3FFFFF) != 0 )
          {
            ptr_el.pObject->RefCount = RefCount - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v10);
          }
        }
      }
    }
    this->NodeKind = k;
  }
}
