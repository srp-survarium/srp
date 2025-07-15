Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLText> *__thiscall Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceText(
        Scaleform::GFx::AS3::InstanceTraits::fl::XML *this,
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLText> *result,
        Scaleform::GFx::AS3::InstanceTraits::Traits *t,
        const Scaleform::GFx::ASString *txt,
        Scaleform::GFx::AS3::Instances::fl::XML *p)
{
  Scaleform::GFx::AS3::Instance *v5; // eax
  Scaleform::GFx::AS3::Instances::fl::XMLText *v6; // esi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLText> *v8; // eax

  v5 = (Scaleform::GFx::AS3::Instance *)this->pVM->MHeap->Alloc(this->pVM->MHeap, 40, 0);
  v6 = (Scaleform::GFx::AS3::Instances::fl::XMLText *)v5;
  if ( v5 )
  {
    Scaleform::GFx::AS3::Instance::Instance(v5, t);
    v6->__vftable = (Scaleform::GFx::AS3::Instances::fl::XMLText_vtbl *)&Scaleform::GFx::AS3::Instances::fl::XML::`vftable';
    pNode = txt->pNode;
    v6->Text = (Scaleform::GFx::ASString)txt->pNode;
    ++pNode->RefCount;
    v6->Parent.pObject = p;
    if ( p )
      p->RefCount = (p->RefCount + 1) & 0x8FBFFFFF;
    v8 = result;
    v6->__vftable = (Scaleform::GFx::AS3::Instances::fl::XMLText_vtbl *)&Scaleform::GFx::AS3::Instances::fl::XMLText::`vftable';
    result->pV = v6;
  }
  else
  {
    v8 = result;
    result->pV = 0;
  }
  return v8;
}


Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLText> *__thiscall Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceText(
        Scaleform::GFx::AS3::InstanceTraits::fl::XML *this,
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLText> *result,
        Scaleform::GFx::AS3::InstanceTraits::Traits *t,
        const Scaleform::StringDataPtr *txt,
        Scaleform::GFx::AS3::Instances::fl::XML *p)
{
  Scaleform::GFx::AS3::VM *pVM; // edi
  Scaleform::GFx::ASStringNode *StringNode; // esi
  Scaleform::GFx::AS3::Instance *v7; // eax
  Scaleform::GFx::AS3::Instances::fl::XMLText *v8; // edi
  bool v9; // zf

  pVM = t->pVM;
  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 pVM->StringManagerRef->pStringManager,
                 (char *)txt->pStr,
                 txt->Size);
  ++StringNode->RefCount;
  v7 = (Scaleform::GFx::AS3::Instance *)pVM->MHeap->Alloc(pVM->MHeap, 40u, 0);
  v8 = (Scaleform::GFx::AS3::Instances::fl::XMLText *)v7;
  if ( v7 )
  {
    Scaleform::GFx::AS3::Instance::Instance(v7, t);
    v8->__vftable = (Scaleform::GFx::AS3::Instances::fl::XMLText_vtbl *)&Scaleform::GFx::AS3::Instances::fl::XML::`vftable';
    v8->Text.pNode = StringNode;
    ++StringNode->RefCount;
    v8->Parent.pObject = p;
    if ( p )
      p->RefCount = (p->RefCount + 1) & 0x8FBFFFFF;
    v8->__vftable = (Scaleform::GFx::AS3::Instances::fl::XMLText_vtbl *)&Scaleform::GFx::AS3::Instances::fl::XMLText::`vftable';
  }
  else
  {
    v8 = 0;
  }
  v9 = StringNode->RefCount-- == 1;
  result->pV = v8;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
  return result;
}
