void __thiscall Scaleform::GFx::XML::DOMBuilder::PrefixMapping(
        Scaleform::GFx::XML::DOMBuilder *this,
        const Scaleform::StringDataPtr *prefix,
        const Scaleform::StringDataPtr *uri)
{
  Scaleform::GFx::XML::Document *pObject; // eax
  Scaleform::GFx::XML::ObjectManager *v5; // ecx
  Scaleform::GFx::XML::ObjectManager *v6; // esi
  __m128i *pStr; // eax
  Scaleform::GFx::XML::DOMStringNode *StringNode; // eax
  Scaleform::GFx::XML::DOMStringNode *Size; // eax
  Scaleform::GFx::XML::DOMStringNode *v10; // eax
  Scaleform::GFx::XML::Prefix *v11; // eax
  bool v12; // zf
  Scaleform::RefCountNTSImpl *v13; // ebx
  Scaleform::GFx::XML::DOMStringNode *v14; // ecx
  Scaleform::GFx::XML::Prefix **v15; // eax
  Scaleform::Array<Scaleform::GFx::XML::DOMBuilder::PrefixOwnership,2,Scaleform::ArrayDefaultPolicy> *p_DefaultNamespaceStack; // esi
  Scaleform::GFx::XML::Prefix **v17; // edi
  Scaleform::GFx::XML::DOMBuilder::PrefixOwnership *v18; // eax
  Scaleform::GFx::XML::Prefix *v19; // ecx
  Scaleform::GFx::XML::DOMString v20; // [esp-8h] [ebp-24h] BYREF
  Scaleform::GFx::XML::DOMString v21; // [esp-4h] [ebp-20h] BYREF
  Scaleform::Ptr<Scaleform::GFx::XML::ObjectManager> memMgr; // [esp+10h] [ebp-Ch]
  Scaleform::GFx::XML::DOMBuilder::PrefixOwnership v23; // [esp+14h] [ebp-8h] BYREF

  pObject = this->pDoc.pObject;
  this->LoadedBytes = this->pLocator->LoadedBytes;
  v5 = pObject->MemoryManager.pObject;
  if ( v5 )
    ++v5->RefCount;
  v6 = pObject->MemoryManager.pObject;
  pStr = (__m128i *)uri->pStr;
  v21.pNode = (Scaleform::GFx::XML::DOMStringNode *)uri->Size;
  memMgr.pObject = v6;
  v6 = (Scaleform::GFx::XML::ObjectManager *)((char *)v6 + 16);
  StringNode = Scaleform::GFx::XML::DOMStringManager::CreateStringNode(
                 (Scaleform::GFx::XML::DOMStringManager *)v6,
                 pStr,
                 v21.pNode);
  Scaleform::GFx::XML::DOMString::DOMString(&v21, StringNode);
  Size = (Scaleform::GFx::XML::DOMStringNode *)prefix->Size;
  v20.pNode = (Scaleform::GFx::XML::DOMStringNode *)prefix->pStr;
  v10 = Scaleform::GFx::XML::DOMStringManager::CreateStringNode(
          (Scaleform::GFx::XML::DOMStringManager *)v6,
          (__m128i *)v20.pNode,
          Size);
  Scaleform::GFx::XML::DOMString::DOMString(&v20, v10);
  v11 = Scaleform::GFx::XML::ObjectManager::CreatePrefix(memMgr.pObject, v20, v21);
  v12 = prefix->Size == 0;
  v13 = v11;
  v20.pNode = v14;
  v21.pNode = 0;
  if ( v12 )
  {
    if ( v11 )
      ++v11->RefCount;
    Scaleform::GFx::XML::DOMBuilder::PrefixOwnership::PrefixOwnership(
      &v23,
      (Scaleform::Ptr<Scaleform::GFx::XML::Prefix>)v11,
      (Scaleform::Ptr<Scaleform::GFx::XML::ElementNode>)v21.pNode);
    p_DefaultNamespaceStack = &this->DefaultNamespaceStack;
  }
  else
  {
    if ( v11 )
      ++v11->RefCount;
    Scaleform::GFx::XML::DOMBuilder::PrefixOwnership::PrefixOwnership(
      &v23,
      (Scaleform::Ptr<Scaleform::GFx::XML::Prefix>)v11,
      (Scaleform::Ptr<Scaleform::GFx::XML::ElementNode>)v21.pNode);
    p_DefaultNamespaceStack = &this->PrefixNamespaceStack;
  }
  v17 = v15;
  Scaleform::ArrayDataBase<Scaleform::GFx::XML::DOMBuilder::PrefixOwnership,Scaleform::AllocatorGH<Scaleform::GFx::XML::DOMBuilder::PrefixOwnership,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &p_DefaultNamespaceStack->Data,
    p_DefaultNamespaceStack,
    p_DefaultNamespaceStack->Data.Size + 1);
  v18 = &p_DefaultNamespaceStack->Data.Data[p_DefaultNamespaceStack->Data.Size - 1];
  if ( &p_DefaultNamespaceStack->Data.Data[p_DefaultNamespaceStack->Data.Size] != (Scaleform::GFx::XML::DOMBuilder::PrefixOwnership *)8 )
  {
    if ( *v17 )
      ++(*v17)->RefCount;
    v18->mPrefix.pObject = *v17;
    v19 = v17[1];
    if ( v19 )
      ++v19->RefCount;
    v18->Owner.pObject = (Scaleform::GFx::XML::ElementNode *)v17[1];
  }
  if ( v23.Owner.pObject )
    Scaleform::RefCountNTSImpl::Release(v23.Owner.pObject);
  if ( v23.mPrefix.pObject )
    Scaleform::RefCountNTSImpl::Release(v23.mPrefix.pObject);
  if ( v13 )
    Scaleform::RefCountNTSImpl::Release(v13);
  if ( memMgr.pObject )
    Scaleform::RefCountNTSImpl::Release(memMgr.pObject);
}
