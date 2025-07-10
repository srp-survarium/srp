void __thiscall Scaleform::GFx::XML::ElementNode::~ElementNode(Scaleform::GFx::XML::ElementNode *this)
{
  Scaleform::GFx::XML::Node *LastChild; // eax
  Scaleform::GFx::XML::Node *PrevSibling; // esi
  Scaleform::RefCountNTSImpl *pObject; // ecx
  Scaleform::GFx::XML::Node *v5; // ecx
  Scaleform::GFx::XML::Attribute *FirstAttribute; // esi
  Scaleform::GFx::XML::Attribute *Next; // ebx
  Scaleform::GFx::XML::Node *v8; // ecx
  Scaleform::GFx::XML::ShadowRefBase *pShadow; // ecx
  Scaleform::GFx::XML::Node *v10; // ecx
  Scaleform::GFx::XML::ObjectManager *v11; // ecx

  LastChild = this->LastChild;
  this->__vftable = (Scaleform::GFx::XML::ElementNode_vtbl *)&Scaleform::GFx::XML::ElementNode::`vftable';
  if ( LastChild )
  {
    do
    {
      PrevSibling = LastChild->PrevSibling;
      LastChild->Parent = 0;
      if ( PrevSibling )
      {
        pObject = PrevSibling->NextSibling.pObject;
        if ( pObject )
          Scaleform::RefCountNTSImpl::Release(pObject);
        PrevSibling->NextSibling.pObject = 0;
      }
      LastChild = PrevSibling;
    }
    while ( PrevSibling );
  }
  if ( this->FirstChild.pObject )
  {
    v5 = this->FirstChild.pObject;
    if ( v5 )
      Scaleform::RefCountNTSImpl::Release(v5);
    this->FirstChild.pObject = 0;
  }
  FirstAttribute = this->FirstAttribute;
  if ( FirstAttribute )
  {
    do
    {
      Next = FirstAttribute->Next;
      Scaleform::GFx::XML::DOMString::~DOMString(&FirstAttribute->Value);
      Scaleform::GFx::XML::DOMString::~DOMString(&FirstAttribute->Name);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, FirstAttribute);
      FirstAttribute = Next;
    }
    while ( Next );
  }
  v8 = this->FirstChild.pObject;
  if ( v8 )
    Scaleform::RefCountNTSImpl::Release(v8);
  Scaleform::GFx::XML::DOMString::~DOMString(&this->Namespace);
  Scaleform::GFx::XML::DOMString::~DOMString(&this->Prefix);
  pShadow = this->pShadow;
  this->__vftable = (Scaleform::GFx::XML::ElementNode_vtbl *)&Scaleform::GFx::XML::Node::`vftable';
  if ( pShadow )
    ((void (__thiscall *)(Scaleform::GFx::XML::ShadowRefBase *, int))pShadow->~Scaleform::GFx::XML::ShadowRefBase)(
      pShadow,
      1);
  v10 = this->NextSibling.pObject;
  if ( v10 )
    Scaleform::RefCountNTSImpl::Release(v10);
  Scaleform::GFx::XML::DOMString::~DOMString(&this->Value);
  v11 = this->MemoryManager.pObject;
  if ( v11 )
    Scaleform::RefCountNTSImpl::Release(v11);
  Scaleform::RefCountNTSImplCore::~RefCountNTSImplCore(this);
}
