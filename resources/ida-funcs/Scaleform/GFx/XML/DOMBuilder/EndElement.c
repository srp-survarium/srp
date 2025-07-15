void __thiscall Scaleform::GFx::XML::DOMBuilder::EndElement(
        Scaleform::GFx::XML::DOMBuilder *this,
        const Scaleform::StringDataPtr *prefix,
        const Scaleform::StringDataPtr *localname)
{
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::ArrayDefaultPolicy> *p_ParseStack; // ebp
  unsigned int Size; // edx
  Scaleform::Ptr<Scaleform::GFx::XML::ElementNode> *Data; // eax
  Scaleform::GFx::XML::ElementNode *pObject; // ecx
  Scaleform::GFx::XML::ElementNode **p_pObject; // eax
  bool v9; // zf
  Scaleform::GFx::XML::ElementNode *v10; // edx
  Scaleform::GFx::XML::Document *v11; // eax
  Scaleform::GFx::XML::ObjectManager *v12; // ecx
  Scaleform::Ptr<Scaleform::GFx::XML::ObjectManager> *p_MemoryManager; // eax
  Scaleform::GFx::XML::ObjectManager *v14; // esi
  char *pData; // eax
  Scaleform::GFx::XML::DOMStringNode *StringNode; // eax
  Scaleform::GFx::XML::TextNode *v17; // ecx
  unsigned int v18; // eax
  bool v19; // sf
  int v20; // eax
  Scaleform::Array<Scaleform::GFx::XML::DOMBuilder::PrefixOwnership,2,Scaleform::ArrayDefaultPolicy> *p_PrefixNamespaceStack; // ebp
  Scaleform::GFx::XML::DOMBuilder::PrefixOwnership *v22; // eax
  Scaleform::GFx::XML::ElementNode *v23; // ecx
  Scaleform::RefCountNTSImpl *v24; // esi
  Scaleform::GFx::XML::ElementNode *v25; // eax
  unsigned int v26; // esi
  int v27; // edi
  Scaleform::GFx::XML::DOMBuilder::PrefixOwnership *v28; // eax
  Scaleform::Array<Scaleform::GFx::XML::DOMBuilder::PrefixOwnership,2,Scaleform::ArrayDefaultPolicy> *p_DefaultNamespaceStack; // esi
  Scaleform::GFx::XML::DOMBuilder::PrefixOwnership *v30; // eax
  Scaleform::GFx::XML::ElementNode *v31; // ecx
  Scaleform::GFx::XML::ElementNode *v32; // ebp
  unsigned int v33; // edi
  int v34; // ebx
  Scaleform::GFx::XML::DOMBuilder::PrefixOwnership *v35; // eax
  unsigned int v36; // ebx
  unsigned int v37; // esi
  Scaleform::RefCountNTSImpl **v38; // edi
  int v39; // ebp
  int v40; // esi
  Scaleform::GFx::AS3::Instances::fl::Object **v41; // eax
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::ArrayDefaultPolicy> *v42; // [esp+Ch] [ebp-14h]
  int i; // [esp+10h] [ebp-10h] BYREF
  Scaleform::Ptr<Scaleform::GFx::XML::ElementNode> pnode; // [esp+14h] [ebp-Ch]
  Scaleform::GFx::XML::DOMBuilder::PrefixOwnership po; // [esp+18h] [ebp-8h]

  p_ParseStack = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::ArrayDefaultPolicy> *)&this->ParseStack;
  this->LoadedBytes = this->pLocator->LoadedBytes;
  Size = this->ParseStack.Data.Size;
  Data = this->ParseStack.Data.Data;
  pObject = Data[Size - 1].pObject;
  p_pObject = &Data[Size - 1].pObject;
  v42 = p_ParseStack;
  if ( pObject )
    ++pObject->RefCount;
  v9 = this->pAppendChainRoot.pObject == 0;
  v10 = *p_pObject;
  pnode.pObject = *p_pObject;
  if ( !v9 )
  {
    v11 = this->pDoc.pObject;
    v12 = v11->MemoryManager.pObject;
    p_MemoryManager = &v11->MemoryManager;
    if ( v12 )
      ++v12->RefCount;
    v14 = p_MemoryManager->pObject;
    Scaleform::GFx::XML::ElementNode::AppendChild(v10, this->pAppendChainRoot.pObject);
    pData = this->AppendText.pData;
    if ( !pData )
      pData = (char *)&buf;
    StringNode = Scaleform::GFx::XML::DOMStringManager::CreateStringNode(
                   &v14->StringPool,
                   pData,
                   (Scaleform::GFx::XML::DOMStringNode *)this->AppendText.Size);
    Scaleform::GFx::XML::DOMString::DOMString((Scaleform::GFx::XML::DOMString *)&i, StringNode);
    Scaleform::GFx::XML::DOMString::AssignNode(
      &this->pAppendChainRoot.pObject->Value,
      (Scaleform::GFx::XML::DOMStringNode *)i);
    Scaleform::GFx::XML::DOMString::~DOMString((Scaleform::GFx::XML::DOMString *)&i);
    v17 = this->pAppendChainRoot.pObject;
    if ( v17 )
      Scaleform::RefCountNTSImpl::Release(v17);
    this->pAppendChainRoot.pObject = 0;
    Scaleform::StringBuffer::Clear(&this->AppendText);
    if ( v14 )
      Scaleform::RefCountNTSImpl::Release(v14);
  }
  v18 = this->PrefixNamespaceStack.Data.Size;
  if ( v18 )
  {
    v19 = (int)(v18 - 1) < 0;
    v20 = v18 - 1;
    i = v20;
    if ( !v19 )
    {
      p_PrefixNamespaceStack = &this->PrefixNamespaceStack;
      while ( 1 )
      {
        v22 = &p_PrefixNamespaceStack->Data.Data[v20];
        if ( v22->mPrefix.pObject )
          ++v22->mPrefix.pObject->RefCount;
        v23 = v22->Owner.pObject;
        v24 = v22->mPrefix.pObject;
        po.mPrefix.pObject = v22->mPrefix.pObject;
        if ( v23 )
          ++v23->RefCount;
        v25 = v22->Owner.pObject;
        po.Owner.pObject = v25;
        if ( v25 != pnode.pObject )
          break;
        v26 = this->PrefixNamespaceStack.Data.Size;
        Scaleform::ArrayDataBase<Scaleform::GFx::XML::DOMBuilder::PrefixOwnership,Scaleform::AllocatorGH<Scaleform::GFx::XML::DOMBuilder::PrefixOwnership,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
          &this->PrefixNamespaceStack.Data,
          &this->PrefixNamespaceStack,
          v26 - 1);
        if ( v26 - 1 > v26 )
        {
          v27 = -1;
          v28 = &p_PrefixNamespaceStack->Data.Data[v26];
          do
          {
            if ( v28 )
            {
              v28->mPrefix.pObject = 0;
              v28->Owner.pObject = 0;
            }
            ++v28;
            --v27;
          }
          while ( v27 );
        }
        if ( po.Owner.pObject )
          Scaleform::RefCountNTSImpl::Release(po.Owner.pObject);
        if ( po.mPrefix.pObject )
          Scaleform::RefCountNTSImpl::Release(po.mPrefix.pObject);
        if ( --i < 0 )
          goto LABEL_36;
        v20 = i;
      }
      if ( v25 )
        Scaleform::RefCountNTSImpl::Release(v25);
      if ( v24 )
        Scaleform::RefCountNTSImpl::Release(v24);
LABEL_36:
      p_ParseStack = v42;
    }
  }
  if ( this->DefaultNamespaceStack.Data.Size )
  {
    p_DefaultNamespaceStack = &this->DefaultNamespaceStack;
    v30 = &this->DefaultNamespaceStack.Data.Data[this->DefaultNamespaceStack.Data.Size - 1];
    if ( v30->mPrefix.pObject )
      ++v30->mPrefix.pObject->RefCount;
    v31 = v30->Owner.pObject;
    po.mPrefix.pObject = v30->mPrefix.pObject;
    if ( v31 )
      ++v31->RefCount;
    v32 = v30->Owner.pObject;
    if ( v32 == pnode.pObject )
    {
      v33 = this->DefaultNamespaceStack.Data.Size;
      Scaleform::ArrayDataBase<Scaleform::GFx::XML::DOMBuilder::PrefixOwnership,Scaleform::AllocatorGH<Scaleform::GFx::XML::DOMBuilder::PrefixOwnership,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        &p_DefaultNamespaceStack->Data,
        p_DefaultNamespaceStack,
        v33 - 1);
      if ( v33 - 1 > v33 )
      {
        v34 = -1;
        v35 = &p_DefaultNamespaceStack->Data.Data[v33];
        do
        {
          if ( v35 )
          {
            v35->mPrefix.pObject = 0;
            v35->Owner.pObject = 0;
          }
          ++v35;
          --v34;
        }
        while ( v34 );
      }
    }
    if ( v32 )
      Scaleform::RefCountNTSImpl::Release(v32);
    if ( po.mPrefix.pObject )
      Scaleform::RefCountNTSImpl::Release(po.mPrefix.pObject);
    p_ParseStack = v42;
  }
  v36 = p_ParseStack->Size;
  v37 = v36 - 1;
  if ( v36 )
  {
    v38 = (Scaleform::RefCountNTSImpl **)&p_ParseStack->Data[v36 - 1];
    if ( v36 != v37 )
    {
      v39 = 1;
      do
      {
        if ( *v38 )
          Scaleform::RefCountNTSImpl::Release(*v38);
        --v38;
        --v39;
      }
      while ( v39 );
      p_ParseStack = v42;
    }
    if ( v37 < p_ParseStack->Policy.Capacity >> 1 )
      Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        p_ParseStack,
        p_ParseStack,
        v36 - 1);
  }
  else if ( v37 >= p_ParseStack->Policy.Capacity )
  {
    Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      p_ParseStack,
      p_ParseStack,
      v37 + (v37 >> 2));
  }
  p_ParseStack->Size = v37;
  if ( v37 > v36 )
  {
    v40 = -1;
    v41 = &p_ParseStack->Data[v36];
    do
    {
      if ( v41 )
        *v41 = 0;
      ++v41;
      --v40;
    }
    while ( v40 );
  }
  if ( pnode.pObject )
    Scaleform::RefCountNTSImpl::Release(pnode.pObject);
}
