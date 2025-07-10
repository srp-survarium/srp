void __thiscall Scaleform::GFx::XML::DOMBuilder::EndDocument(Scaleform::GFx::XML::DOMBuilder *this)
{
  Scaleform::GFx::XML::Document *pObject; // eax
  Scaleform::GFx::XML::ObjectManager *v3; // ecx
  Scaleform::Ptr<Scaleform::GFx::XML::ObjectManager> *p_MemoryManager; // eax
  Scaleform::GFx::XML::ObjectManager *v5; // edi
  Scaleform::GFx::XML::DOMStringNode *StringNode; // eax
  Scaleform::GFx::XML::DOMStringNode *v7; // eax
  Scaleform::GFx::XML::DOMString v8; // [esp+Ch] [ebp-4h] BYREF

  this->LoadedBytes = this->pLocator->LoadedBytes;
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::XML::ElementNode>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::XML::ElementNode>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->ParseStack.Data,
    &this->ParseStack,
    0);
  pObject = this->pDoc.pObject;
  v3 = pObject->MemoryManager.pObject;
  p_MemoryManager = &pObject->MemoryManager;
  if ( v3 )
    ++v3->RefCount;
  v5 = p_MemoryManager->pObject;
  StringNode = Scaleform::GFx::XML::DOMStringManager::CreateStringNode(
                 &p_MemoryManager->pObject->StringPool,
                 (char *)this->pLocator->XMLVersion.pStr,
                 (Scaleform::GFx::XML::DOMStringNode *)this->pLocator->XMLVersion.Size);
  Scaleform::GFx::XML::DOMString::DOMString(&v8, StringNode);
  Scaleform::GFx::XML::DOMString::AssignNode(&this->pDoc.pObject->XMLVersion, v8.pNode);
  Scaleform::GFx::XML::DOMString::~DOMString(&v8);
  v7 = Scaleform::GFx::XML::DOMStringManager::CreateStringNode(
         &v5->StringPool,
         (char *)this->pLocator->Encoding.pStr,
         (Scaleform::GFx::XML::DOMStringNode *)this->pLocator->Encoding.Size);
  Scaleform::GFx::XML::DOMString::DOMString(&v8, v7);
  Scaleform::GFx::XML::DOMString::AssignNode(&this->pDoc.pObject->Encoding, v8.pNode);
  Scaleform::GFx::XML::DOMString::~DOMString(&v8);
  this->pDoc.pObject->Standalone = this->pLocator->StandAlone;
  if ( v5 )
    Scaleform::RefCountNTSImpl::Release(v5);
}
