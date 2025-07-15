void __thiscall Scaleform::GFx::XML::DOMBuilder::Characters(
        Scaleform::GFx::XML::DOMBuilder *this,
        const Scaleform::StringDataPtr *text)
{
  Scaleform::Ptr<Scaleform::GFx::XML::ObjectManager> *p_MemoryManager; // eax
  Scaleform::GFx::XML::DOMStringNode *pObject; // ecx
  Scaleform::GFx::XML::ObjectManager *v5; // edi
  Scaleform::GFx::XML::TextNode *TextNode; // eax
  Scaleform::GFx::XML::TextNode *v7; // ecx
  Scaleform::GFx::XML::TextNode *v8; // ebx
  Scaleform::GFx::XML::DOMString v9; // [esp-4h] [ebp-10h] BYREF

  p_MemoryManager = &this->pDoc.pObject->MemoryManager;
  this->LoadedBytes = this->pLocator->LoadedBytes;
  pObject = (Scaleform::GFx::XML::DOMStringNode *)p_MemoryManager->pObject;
  if ( p_MemoryManager->pObject )
    ++pObject->pManager;
  v5 = p_MemoryManager->pObject;
  if ( !this->pAppendChainRoot.pObject )
  {
    v9.pNode = pObject;
    Scaleform::GFx::XML::DOMString::DOMString(&v9, &v5->StringPool.EmptyStringNode);
    TextNode = Scaleform::GFx::XML::ObjectManager::CreateTextNode(v5, v9);
    v7 = this->pAppendChainRoot.pObject;
    v8 = TextNode;
    if ( v7 )
      Scaleform::RefCountNTSImpl::Release(v7);
    this->pAppendChainRoot.pObject = v8;
  }
  Scaleform::StringBuffer::AppendString(&this->AppendText, (const __m128i *)text->pStr, text->Size);
  if ( v5 )
    Scaleform::RefCountNTSImpl::Release(v5);
}
