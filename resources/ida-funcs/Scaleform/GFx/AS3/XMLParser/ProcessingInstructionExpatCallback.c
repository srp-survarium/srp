void __cdecl Scaleform::GFx::AS3::XMLParser::ProcessingInstructionExpatCallback(
        Scaleform::GFx::AS3::XMLParser *userData,
        char *target,
        char *data)
{
  Scaleform::GFx::AS3::XMLParser *v3; // ebx
  Scaleform::GFx::AS3::InstanceTraits::Traits *ITr; // esi
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // edi
  Scaleform::GFx::ASStringNode *StringNode; // ebp
  Scaleform::GFx::ASStringManager *pStringManager; // ecx
  Scaleform::GFx::ASStringNode *v8; // edi
  Scaleform::MemoryHeap *MHeap; // ecx
  void *(__thiscall *Alloc)(Scaleform::MemoryHeap *, unsigned int, const Scaleform::AllocInfo *); // eax
  Scaleform::GFx::AS3::Instances::fl::XMLProcInstr *v11; // eax
  Scaleform::GFx::AS3::XMLParser *v12; // eax
  Scaleform::GFx::AS3::XMLParser *v13; // esi
  bool v14; // zf
  Scaleform::GFx::AS3::Instances::fl::XML *pObject; // ecx
  Scaleform::GFx::AS3::XMLParser *v16; // eax
  Scaleform::GFx::AS3::Instances::fl::XML *v17; // edx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v18; // ecx
  Scaleform::GFx::AS3::Instances::fl::XML *p; // [esp+10h] [ebp-Ch]
  Scaleform::GFx::ASString v; // [esp+14h] [ebp-8h] BYREF
  Scaleform::GFx::ASString n; // [esp+18h] [ebp-4h] BYREF

  v3 = userData;
  Scaleform::GFx::AS3::XMLParser::SetNodeKind(userData, kAttr|kText);
  ITr = v3->ITr;
  StringManagerRef = ITr->pVM->StringManagerRef;
  p = v3->pCurrElem.pObject;
  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(StringManagerRef->pStringManager, data);
  ++StringNode->RefCount;
  pStringManager = StringManagerRef->pStringManager;
  v.pNode = StringNode;
  v8 = Scaleform::GFx::ASStringManager::CreateStringNode(pStringManager, target);
  ++v8->RefCount;
  MHeap = ITr->pVM->MHeap;
  Alloc = MHeap->Alloc;
  n.pNode = v8;
  v11 = (Scaleform::GFx::AS3::Instances::fl::XMLProcInstr *)Alloc(MHeap, 44u, 0);
  if ( v11 )
  {
    Scaleform::GFx::AS3::Instances::fl::XMLProcInstr::XMLProcInstr(v11, ITr, &n, &v, p);
    v13 = v12;
  }
  else
  {
    v13 = 0;
  }
  v14 = v8->RefCount-- == 1;
  if ( v14 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v8);
  v14 = StringNode->RefCount-- == 1;
  if ( v14 )
    Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
  pObject = v3->pCurrElem.pObject;
  userData = v13;
  if ( pObject && pObject->GetKind(pObject) == kElement )
  {
    v3->pCurrElem.pObject->AppendChild(
      v3->pCurrElem.pObject,
      (const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *)&userData);
  }
  else
  {
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event>::Set(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)&v3->pCurrElem,
      (const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)&userData);
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &v3->RootElements.Data,
      v3->RootElements.Data.pHeap,
      v3->RootElements.Data.Size + 1);
    if ( &v3->RootElements.Data.Data[v3->RootElements.Data.Size] != (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *)4 )
    {
      v3->RootElements.Data.Data[v3->RootElements.Data.Size - 1].pObject = (Scaleform::GFx::AS3::Instances::fl::XML *)userData;
      v16 = userData;
      if ( userData )
      {
        ++userData->pCurrElem.pObject;
        v16->pCurrElem.pObject = (Scaleform::GFx::AS3::Instances::fl::XML *)((int)v16->pCurrElem.pObject & 0x8FBFFFFF);
      }
    }
    XML_StopParser(v3->Parser, 1);
  }
  if ( userData && ((unsigned __int8)userData & 1) == 0 )
  {
    v17 = userData->pCurrElem.pObject;
    v18 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)userData;
    if ( ((unsigned int)&byte_3FFFFF & (unsigned int)v17) != 0 )
    {
      userData->pCurrElem.pObject = (Scaleform::GFx::AS3::Instances::fl::XML *)((char *)v17 - 1);
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v18);
    }
  }
}
