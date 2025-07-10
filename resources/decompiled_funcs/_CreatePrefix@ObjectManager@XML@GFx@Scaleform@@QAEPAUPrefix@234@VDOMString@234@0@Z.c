Scaleform::GFx::XML::Prefix *__thiscall Scaleform::GFx::XML::ObjectManager::CreatePrefix(
        Scaleform::GFx::XML::ObjectManager *this,
        Scaleform::GFx::XML::DOMString name,
        Scaleform::GFx::XML::DOMString value)
{
  Scaleform::GFx::XML::Prefix *v3; // eax
  int v4; // eax
  int v5; // edi
  Scaleform::GFx::XML::DOMStringManager *pManager; // ecx
  Scaleform::GFx::XML::DOMStringManager *v7; // ecx
  Scaleform::GFx::XML::DOMStringNode *key; // [esp+8h] [ebp-4h] BYREF

  key = (Scaleform::GFx::XML::DOMStringNode *)this;
  v3 = (Scaleform::GFx::XML::Prefix *)this->pHeap->Alloc(this->pHeap, 16, 0);
  if ( v3 )
  {
    ++value.pNode->RefCount;
    ++name.pNode->RefCount;
    Scaleform::GFx::XML::Prefix::Prefix(v3, name, value);
    v5 = v4;
  }
  else
  {
    v5 = 0;
  }
  if ( !--name.pNode->RefCount )
  {
    pManager = name.pNode->pManager;
    key = name.pNode;
    Scaleform::HashSetBase<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::XML::DOMStringNode *,326>,Scaleform::HashsetEntry<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>>>::RemoveAlt<Scaleform::GFx::XML::DOMStringNode *>(
      &pManager->StringSet,
      &key);
    Scaleform::GFx::XML::DOMStringManager::FreeStringNode(name.pNode->pManager, name.pNode);
  }
  if ( !--value.pNode->RefCount )
  {
    v7 = value.pNode->pManager;
    key = value.pNode;
    Scaleform::HashSetBase<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::XML::DOMStringNode *,326>,Scaleform::HashsetEntry<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>>>::RemoveAlt<Scaleform::GFx::XML::DOMStringNode *>(
      &v7->StringSet,
      &key);
    Scaleform::GFx::XML::DOMStringManager::FreeStringNode(value.pNode->pManager, value.pNode);
  }
  return (Scaleform::GFx::XML::Prefix *)v5;
}
