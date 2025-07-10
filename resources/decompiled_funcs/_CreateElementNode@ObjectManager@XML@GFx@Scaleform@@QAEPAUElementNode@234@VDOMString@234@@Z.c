Scaleform::GFx::XML::ElementNode *__thiscall Scaleform::GFx::XML::ObjectManager::CreateElementNode(
        Scaleform::GFx::XML::ObjectManager *this,
        Scaleform::GFx::XML::DOMString value)
{
  Scaleform::GFx::XML::ElementNode *v3; // eax
  int v4; // eax
  int v5; // edi
  Scaleform::GFx::XML::DOMStringManager *pManager; // ecx
  Scaleform::GFx::XML::DOMStringNode *key; // [esp+8h] [ebp-4h] BYREF

  v3 = (Scaleform::GFx::XML::ElementNode *)this->pHeap->Alloc(this->pHeap, 60, 0);
  if ( v3 )
  {
    ++value.pNode->RefCount;
    Scaleform::GFx::XML::ElementNode::ElementNode(v3, this, value);
    v5 = v4;
  }
  else
  {
    v5 = 0;
  }
  if ( !--value.pNode->RefCount )
  {
    pManager = value.pNode->pManager;
    key = value.pNode;
    Scaleform::HashSetBase<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::XML::DOMStringNode *,326>,Scaleform::HashsetEntry<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>>>::RemoveAlt<Scaleform::GFx::XML::DOMStringNode *>(
      &pManager->StringSet,
      &key);
    Scaleform::GFx::XML::DOMStringManager::FreeStringNode(value.pNode->pManager, value.pNode);
  }
  return (Scaleform::GFx::XML::ElementNode *)v5;
}
