void __thiscall Scaleform::GFx::XML::Prefix::Prefix(
        Scaleform::GFx::XML::Prefix *this,
        Scaleform::GFx::XML::DOMString name,
        Scaleform::GFx::XML::DOMString value)
{
  Scaleform::GFx::XML::DOMStringManager *pManager; // ecx
  Scaleform::GFx::XML::DOMStringManager *v4; // ecx
  Scaleform::GFx::XML::DOMStringNode *key; // [esp+8h] [ebp-4h] BYREF

  this->__vftable = (Scaleform::GFx::XML::Prefix_vtbl *)&Scaleform::GFx::XML::Prefix::`vftable';
  this->RefCount = 1;
  this->Name = name;
  ++name.pNode->RefCount;
  this->Value = value;
  ++value.pNode->RefCount;
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
    v4 = value.pNode->pManager;
    key = value.pNode;
    Scaleform::HashSetBase<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::XML::DOMStringNode *,326>,Scaleform::HashsetEntry<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>>>::RemoveAlt<Scaleform::GFx::XML::DOMStringNode *>(
      &v4->StringSet,
      &key);
    Scaleform::GFx::XML::DOMStringManager::FreeStringNode(value.pNode->pManager, value.pNode);
  }
}
