void __thiscall Scaleform::GFx::XML::DOMBuilder::StartElement(
        Scaleform::GFx::XML::DOMBuilder *this,
        const Scaleform::StringDataPtr *prefix,
        const Scaleform::StringDataPtr *localname,
        Scaleform::GFx::XML::DOMString *atts)
{
  Scaleform::GFx::XML::DOMBuilder *v4; // esi
  Scaleform::GFx::XML::Document *pObject; // eax
  Scaleform::GFx::XML::DOMStringNode *v6; // ecx
  bool v7; // zf
  Scaleform::GFx::XML::ObjectManager *v8; // ebx
  unsigned int Size; // edx
  Scaleform::Ptr<Scaleform::GFx::XML::ElementNode> *Data; // eax
  Scaleform::GFx::XML::ElementNode *v11; // ecx
  Scaleform::GFx::XML::ElementNode **p_pObject; // eax
  Scaleform::GFx::XML::ElementNode *v13; // edi
  char *pData; // eax
  Scaleform::GFx::XML::DOMStringNode *StringNode; // eax
  Scaleform::RefCountNTSImpl *v16; // ecx
  Scaleform::GFx::XML::DOMStringNode *v17; // edx
  char *pStr; // eax
  Scaleform::GFx::XML::DOMStringNode *v19; // eax
  Scaleform::GFx::XML::ElementNode *ElementNode; // eax
  const Scaleform::GFx::XML::ParserAttributes *v21; // ebx
  unsigned int v22; // edi
  Scaleform::GFx::XML::ElementNode *v23; // edx
  int v24; // ebp
  Scaleform::GFx::XML::DOMStringNode *v25; // eax
  Scaleform::GFx::XML::DOMString *v26; // esi
  Scaleform::GFx::XML::DOMStringNode *v27; // eax
  Scaleform::GFx::XML::DOMStringNode *pNode; // eax
  Scaleform::GFx::XML::DOMStringNode *v29; // eax
  Scaleform::GFx::XML::Attribute *Attribute; // eax
  unsigned int v31; // eax
  int i; // ebx
  int v33; // edi
  Scaleform::RefCountNTSImpl *v34; // ecx
  unsigned int v35; // ecx
  Scaleform::GFx::XML::DOMBuilder::PrefixOwnership *v36; // eax
  int v37; // edi
  Scaleform::RefCountNTSImpl *v38; // ecx
  unsigned int v39; // eax
  bool v40; // sf
  Scaleform::GFx::XML::DOMString *v41; // eax
  Scaleform::GFx::XML::ObjectManager *v42; // ebx
  Scaleform::GFx::XML::DOMStringNode *v43; // eax
  Scaleform::GFx::XML::DOMBuilder::PrefixOwnership *v44; // eax
  Scaleform::GFx::XML::ElementNode *v45; // ecx
  Scaleform::GFx::XML::Prefix *v46; // edi
  Scaleform::RefCountNTSImpl *v47; // ebx
  Scaleform::GFx::XML::DOMString *p_Namespace; // ecx
  Scaleform::GFx::XML::DOMBuilder::PrefixOwnership *v49; // eax
  Scaleform::GFx::XML::ElementNode *v50; // ecx
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::ArrayDefaultPolicy> *p_ParseStack; // edi
  int v52; // eax
  const Scaleform::GFx::XML::ParserAttributes *v53; // ebp
  unsigned int v54; // eax
  unsigned int v55; // esi
  Scaleform::RefCountNTSImpl **v56; // ebx
  int v57; // ebp
  Scaleform::GFx::AS3::Instances::fl::Object **v58; // ecx
  Scaleform::GFx::XML::ElementNode **v59; // esi
  Scaleform::GFx::XML::DOMString v60; // [esp-8h] [ebp-24h] BYREF
  Scaleform::GFx::XML::DOMString v61[5]; // [esp-4h] [ebp-20h] BYREF
  Scaleform::Ptr<Scaleform::GFx::XML::ObjectManager> memMgr; // [esp+10h] [ebp-Ch]
  Scaleform::GFx::XML::DOMString v63; // [esp+14h] [ebp-8h] BYREF
  Scaleform::GFx::XML::DOMBuilder *v64; // [esp+18h] [ebp-4h]
  Scaleform::GFx::XML::ElementNode *localnamea; // [esp+24h] [ebp+8h]

  v4 = this;
  pObject = this->pDoc.pObject;
  this->LoadedBytes = this->pLocator->LoadedBytes;
  v6 = (Scaleform::GFx::XML::DOMStringNode *)pObject->MemoryManager.pObject;
  v64 = v4;
  if ( v6 )
    ++v6->pManager;
  v7 = v4->pAppendChainRoot.pObject == 0;
  v8 = pObject->MemoryManager.pObject;
  memMgr.pObject = v8;
  if ( !v7 )
  {
    Size = v4->ParseStack.Data.Size;
    Data = v4->ParseStack.Data.Data;
    v11 = Data[Size - 1].pObject;
    p_pObject = &Data[Size - 1].pObject;
    if ( v11 )
      ++v11->RefCount;
    v13 = *p_pObject;
    Scaleform::GFx::XML::ElementNode::AppendChild(*p_pObject, v4->pAppendChainRoot.pObject);
    pData = v4->AppendText.pData;
    if ( !pData )
      pData = (char *)&buf;
    StringNode = Scaleform::GFx::XML::DOMStringManager::CreateStringNode(
                   &v8->StringPool,
                   pData,
                   (Scaleform::GFx::XML::DOMStringNode *)v4->AppendText.Size);
    Scaleform::GFx::XML::DOMString::DOMString(&v63, StringNode);
    Scaleform::GFx::XML::DOMString::AssignNode(&v4->pAppendChainRoot.pObject->Value, v63.pNode);
    Scaleform::GFx::XML::DOMString::~DOMString(&v63);
    v16 = v4->pAppendChainRoot.pObject;
    if ( v16 )
      Scaleform::RefCountNTSImpl::Release(v16);
    v4->pAppendChainRoot.pObject = 0;
    Scaleform::StringBuffer::Clear(&v4->AppendText);
    if ( v13 )
      Scaleform::RefCountNTSImpl::Release(v13);
  }
  v17 = (Scaleform::GFx::XML::DOMStringNode *)localname->Size;
  pStr = (char *)localname->pStr;
  v61[0].pNode = v6;
  v19 = Scaleform::GFx::XML::DOMStringManager::CreateStringNode(&v8->StringPool, pStr, v17);
  Scaleform::GFx::XML::DOMString::DOMString(v61, v19);
  ElementNode = Scaleform::GFx::XML::ObjectManager::CreateElementNode(v8, v61[0]);
  v21 = (const Scaleform::GFx::XML::ParserAttributes *)atts;
  v22 = 0;
  v23 = ElementNode;
  localnamea = ElementNode;
  if ( atts[1].pNode )
  {
    v24 = 0;
    do
    {
      v25 = (Scaleform::GFx::XML::DOMStringNode *)v21->Attributes[v24].Value.Size;
      v26 = (Scaleform::GFx::XML::DOMString *)&v21->Attributes[v24];
      v61[0] = v26[2];
      atts = v61;
      v27 = Scaleform::GFx::XML::DOMStringManager::CreateStringNode(
              &memMgr.pObject->StringPool,
              (char *)v61[0].pNode,
              v25);
      Scaleform::GFx::XML::DOMString::DOMString(atts, v27);
      pNode = v26[1].pNode;
      v60.pNode = v26->pNode;
      v29 = Scaleform::GFx::XML::DOMStringManager::CreateStringNode(
              &memMgr.pObject->StringPool,
              (char *)v60.pNode,
              pNode);
      Scaleform::GFx::XML::DOMString::DOMString(&v60, v29);
      Attribute = Scaleform::GFx::XML::ObjectManager::CreateAttribute(memMgr.pObject, v60, v61[0]);
      Scaleform::GFx::XML::ElementNode::AddAttribute(localnamea, Attribute);
      ++v22;
      ++v24;
    }
    while ( v22 < v21->Length );
    v4 = v64;
    v23 = localnamea;
  }
  v31 = v4->PrefixNamespaceStack.Data.Size;
  if ( v31 )
  {
    for ( i = v31 - 1; i >= 0; *(_DWORD *)(v33 + 4) = v23 )
    {
      v33 = (int)&v4->PrefixNamespaceStack.Data.Data[i];
      if ( *(_DWORD *)(v33 + 4) )
        break;
      if ( v23 )
        ++v23->RefCount;
      v34 = *(Scaleform::RefCountNTSImpl **)(v33 + 4);
      if ( v34 )
      {
        Scaleform::RefCountNTSImpl::Release(v34);
        v23 = localnamea;
      }
      --i;
    }
  }
  if ( v4->DefaultNamespaceStack.Data.Size )
  {
    v35 = v4->DefaultNamespaceStack.Data.Size;
    v36 = v4->DefaultNamespaceStack.Data.Data;
    v37 = (int)&v36[v35 - 1];
    if ( !v36[v35 - 1].Owner.pObject )
    {
      if ( v23 )
        ++v23->RefCount;
      v38 = *(Scaleform::RefCountNTSImpl **)(v37 + 4);
      if ( v38 )
      {
        Scaleform::RefCountNTSImpl::Release(v38);
        v23 = localnamea;
      }
      *(_DWORD *)(v37 + 4) = v23;
    }
  }
  if ( !prefix->Size )
  {
    if ( !v4->DefaultNamespaceStack.Data.Size )
      goto LABEL_56;
    v49 = &v4->DefaultNamespaceStack.Data.Data[v4->DefaultNamespaceStack.Data.Size - 1];
    if ( v49->mPrefix.pObject )
      ++v49->mPrefix.pObject->RefCount;
    v50 = v49->Owner.pObject;
    v46 = v49->mPrefix.pObject;
    if ( v50 )
      ++v50->RefCount;
    v47 = v49->Owner.pObject;
    Scaleform::GFx::XML::DOMString::AssignNode(&v23->Prefix, v46->Name.pNode);
    v61[0] = v46->Value;
    p_Namespace = &localnamea->Namespace;
    goto LABEL_52;
  }
  v39 = v4->PrefixNamespaceStack.Data.Size;
  if ( v39 )
  {
    v40 = (int)(v39 - 1) < 0;
    v41 = (Scaleform::GFx::XML::DOMString *)(v39 - 1);
    atts = v41;
    if ( !v40 )
    {
      while ( 1 )
      {
        v44 = &v4->PrefixNamespaceStack.Data.Data[(_DWORD)v41];
        if ( v44->mPrefix.pObject )
          ++v44->mPrefix.pObject->RefCount;
        v45 = v44->Owner.pObject;
        v46 = v44->mPrefix.pObject;
        if ( v45 )
          ++v45->RefCount;
        v47 = v44->Owner.pObject;
        if ( !strncmp(v46->Name.pNode->pData, prefix->pStr, prefix->Size) )
          break;
        if ( v47 )
          Scaleform::RefCountNTSImpl::Release(v47);
        Scaleform::RefCountNTSImpl::Release(v46);
        atts = (Scaleform::GFx::XML::DOMString *)((char *)atts - 1);
        if ( (int)atts < 0 )
          goto LABEL_34;
        v41 = atts;
      }
      Scaleform::GFx::XML::DOMString::AssignNode(&localnamea->Prefix, v46->Name.pNode);
      v61[0] = v46->Value;
      p_Namespace = &localnamea->Namespace;
LABEL_52:
      Scaleform::GFx::XML::DOMString::AssignNode(p_Namespace, v61[0].pNode);
      if ( v47 )
        Scaleform::RefCountNTSImpl::Release(v47);
      Scaleform::RefCountNTSImpl::Release(v46);
      goto LABEL_55;
    }
  }
LABEL_34:
  v42 = memMgr.pObject;
  v43 = Scaleform::GFx::XML::DOMStringManager::CreateStringNode(
          &memMgr.pObject->StringPool,
          (char *)prefix->pStr,
          (Scaleform::GFx::XML::DOMStringNode *)prefix->Size);
  Scaleform::GFx::XML::DOMString::DOMString((Scaleform::GFx::XML::DOMString *)&atts, v43);
  Scaleform::GFx::XML::DOMString::AssignNode(&localnamea->Prefix, (Scaleform::GFx::XML::DOMStringNode *)atts);
  Scaleform::GFx::XML::DOMString::~DOMString((Scaleform::GFx::XML::DOMString *)&atts);
  Scaleform::GFx::XML::DOMString::DOMString((Scaleform::GFx::XML::DOMString *)&atts, &v42->StringPool.EmptyStringNode);
  Scaleform::GFx::XML::DOMString::AssignNode(&localnamea->Namespace, (Scaleform::GFx::XML::DOMStringNode *)atts);
  Scaleform::GFx::XML::DOMString::~DOMString((Scaleform::GFx::XML::DOMString *)&atts);
LABEL_55:
  v23 = localnamea;
LABEL_56:
  p_ParseStack = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::ArrayDefaultPolicy> *)&v4->ParseStack;
  v52 = (int)&v4->ParseStack.Data.Data[v4->ParseStack.Data.Size - 1];
  if ( *(_DWORD *)v52 )
    ++*(_DWORD *)(*(_DWORD *)v52 + 4);
  v53 = *(const Scaleform::GFx::XML::ParserAttributes **)v52;
  atts = (Scaleform::GFx::XML::DOMString *)v53;
  Scaleform::GFx::XML::ElementNode::AppendChild((Scaleform::GFx::XML::ElementNode *)v53, v23);
  v54 = v4->ParseStack.Data.Size;
  v55 = v54 + 1;
  if ( v54 + 1 >= v54 )
  {
    if ( v55 < p_ParseStack->Policy.Capacity )
      goto LABEL_70;
    v61[0].pNode = (Scaleform::GFx::XML::DOMStringNode *)(v55 + (v55 >> 2));
    goto LABEL_69;
  }
  v56 = (Scaleform::RefCountNTSImpl **)&p_ParseStack->Data[v54 - 1];
  v57 = -1;
  do
  {
    if ( *v56 )
      Scaleform::RefCountNTSImpl::Release(*v56);
    --v56;
    --v57;
  }
  while ( v57 );
  v53 = (const Scaleform::GFx::XML::ParserAttributes *)atts;
  if ( v55 < p_ParseStack->Policy.Capacity >> 1 )
  {
    v61[0].pNode = (Scaleform::GFx::XML::DOMStringNode *)v55;
LABEL_69:
    Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      p_ParseStack,
      p_ParseStack,
      (unsigned int)v61[0].pNode);
  }
LABEL_70:
  v58 = p_ParseStack->Data;
  p_ParseStack->Size = v55;
  v59 = (Scaleform::GFx::XML::ElementNode **)&v58[v55 - 1];
  if ( v59 )
  {
    if ( localnamea )
      ++localnamea->RefCount;
    *v59 = localnamea;
  }
  if ( v53 )
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)v53);
  if ( localnamea )
    Scaleform::RefCountNTSImpl::Release(localnamea);
  if ( memMgr.pObject )
    Scaleform::RefCountNTSImpl::Release(memMgr.pObject);
}
