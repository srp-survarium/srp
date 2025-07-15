void __usercall Scaleform::GFx::AS2::ResolveNamespace(
        Scaleform::GFx::AS2::Environment *penv@<esi>,
        Scaleform::GFx::ASStringNode *elemNode,
        Scaleform::GFx::XML::RootNode *proot)
{
  Scaleform::GFx::ASStringNode *v3; // ebx
  Scaleform::GFx::AS2::StringManager *StringManager; // eax
  Scaleform::GFx::XML::DOMString *v5; // ebp
  Scaleform::GFx::XML::DOMStringNode *v6; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::XML::ElementNode *HashFlags; // edi
  Scaleform::GFx::AS2::XmlNodeObject *pObject; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::XML::DOMStringNode *StringNode; // eax
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::XML::DOMStringNode *p_HashFlags; // [esp+8h] [ebp-28h]
  Scaleform::GFx::XML::DOMString v14; // [esp+18h] [ebp-18h] BYREF
  Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> result; // [esp+1Ch] [ebp-14h] BYREF
  Scaleform::GFx::AS2::Value v16; // [esp+20h] [ebp-10h] BYREF

  v3 = elemNode;
  StringManager = Scaleform::GFx::AS2::GlobalContext::GetStringManager(penv->StringContext.pContext);
  elemNode = Scaleform::GFx::ASStringManager::CreateStringNode(StringManager->pStringManager, (__m128i *)"xmlns", 5u);
  ++elemNode->RefCount;
  if ( *(_DWORD *)(v3[1].RefCount + 12) )
  {
    Scaleform::GFx::ASString::Append(
      (Scaleform::GFx::ASString *)&elemNode,
      (const __m128i *)":",
      (Scaleform::GFx::ASStringNode *)1);
    Scaleform::GFx::ASString::Append(
      (Scaleform::GFx::ASString *)&elemNode,
      *(const __m128i **)v3[1].RefCount,
      (Scaleform::GFx::ASStringNode *)strlen(*(const char **)v3[1].RefCount));
  }
  p_HashFlags = (Scaleform::GFx::XML::DOMStringNode *)&v3->pLower[1].HashFlags;
  v16.T.Type = 0;
  Scaleform::GFx::XML::DOMString::DOMString(&v14, p_HashFlags);
  v5 = (Scaleform::GFx::XML::DOMString *)&v3[1].HashFlags;
  Scaleform::GFx::XML::DOMString::AssignNode((Scaleform::GFx::XML::DOMString *)&v3[1].HashFlags, v14.pNode);
  Scaleform::GFx::XML::DOMString::~DOMString(&v14);
  (*(void (__thiscall **)(Scaleform::HashSetBase<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::ASStringNode *,324>,Scaleform::HashsetEntry<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *> > >::TableType *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::ASStringNode **, Scaleform::GFx::AS2::Value *))(v3[1].pManager->StringSet.pTable[2].EntryCount + 16))(
    v3[1].pManager->StringSet.pTable + 2,
    penv,
    &elemNode,
    &v16);
  if ( !v16.T.Type || v16.T.Type == 10 )
  {
    HashFlags = (Scaleform::GFx::XML::ElementNode *)v3->HashFlags;
    if ( !HashFlags )
      goto LABEL_18;
    while ( 1 )
    {
      if ( !HashFlags->pShadow )
      {
        Scaleform::GFx::AS2::CreateShadow(&result, penv, HashFlags, proot);
        pObject = result.pObject;
        if ( result.pObject )
        {
          RefCount = result.pObject->RefCount;
          if ( (RefCount & 0x3FFFFFF) != 0 )
          {
            result.pObject->RefCount = RefCount - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pObject);
          }
        }
      }
      (*((void (__thiscall **)(Scaleform::GFx::XML::ShadowRefBase_vtbl *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::ASStringNode **, Scaleform::GFx::AS2::Value *))HashFlags->pShadow[2].__vftable[4].~Scaleform::GFx::XML::ShadowRefBase
       + 4))(
        HashFlags->pShadow[2].__vftable + 4,
        penv,
        &elemNode,
        &v16);
      if ( v16.T.Type )
      {
        if ( v16.T.Type != 10 )
          break;
      }
      HashFlags = HashFlags->Parent;
      if ( !HashFlags )
        goto LABEL_18;
    }
    Scaleform::GFx::AS2::Value::ToStringImpl(&v16, (Scaleform::GFx::ASString *)&v14, penv, -1, 0);
    StringNode = Scaleform::GFx::XML::DOMStringManager::CreateStringNode(
                   (Scaleform::GFx::XML::DOMStringManager *)&v3->pLower->HashFlags,
                   v14.pNode->pData,
                   (unsigned int)v14.pNode[1].pData);
    Scaleform::GFx::XML::DOMString::DOMString((Scaleform::GFx::XML::DOMString *)&result, StringNode);
    Scaleform::GFx::XML::DOMString::AssignNode(v5, (Scaleform::GFx::XML::DOMStringNode *)result.pObject);
    Scaleform::GFx::XML::DOMString::~DOMString((Scaleform::GFx::XML::DOMString *)&result);
    pNode = (Scaleform::GFx::ASStringNode *)v14.pNode;
  }
  else
  {
    Scaleform::GFx::AS2::Value::ToStringImpl(&v16, (Scaleform::GFx::ASString *)&result, penv, -1, 0);
    v6 = Scaleform::GFx::XML::DOMStringManager::CreateStringNode(
           (Scaleform::GFx::XML::DOMStringManager *)&v3->pLower->HashFlags,
           (const char *)result.pObject->__vftable,
           (unsigned int)result.pObject->pUserDataHolder);
    Scaleform::GFx::XML::DOMString::DOMString(&v14, v6);
    Scaleform::GFx::XML::DOMString::AssignNode(v5, v14.pNode);
    Scaleform::GFx::XML::DOMString::~DOMString(&v14);
    pNode = (Scaleform::GFx::ASStringNode *)result.pObject;
  }
  if ( !--pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
LABEL_18:
  Scaleform::GFx::AS2::Value::~Value(&v16);
  v12 = elemNode;
  --elemNode->RefCount;
  if ( !v12->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
}
