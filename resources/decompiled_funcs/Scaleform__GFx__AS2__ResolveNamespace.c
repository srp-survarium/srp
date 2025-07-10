void __usercall Scaleform::GFx::AS2::ResolveNamespace(
        Scaleform::GFx::AS2::Environment *penv@<esi>,
        Scaleform::GFx::ASStringNode *elemNode,
        Scaleform::GFx::XML::RootNode *proot)
{
  Scaleform::GFx::XML::ElementNode *v3; // ebx
  Scaleform::GFx::AS2::StringManager *StringManager; // eax
  Scaleform::GFx::XML::DOMString *p_Namespace; // ebp
  Scaleform::GFx::XML::DOMStringNode *v6; // eax
  Scaleform::GFx::ASStringNode *v7; // eax
  Scaleform::GFx::XML::ElementNode *Parent; // edi
  Scaleform::GFx::ASStringNode *pNode; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::XML::DOMStringNode *StringNode; // eax
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::XML::DOMStringNode *p_EmptyStringNode; // [esp+8h] [ebp-28h]
  Scaleform::GFx::XML::DOMString v14; // [esp+18h] [ebp-18h] BYREF
  Scaleform::GFx::ASString ns; // [esp+1Ch] [ebp-14h] BYREF
  Scaleform::GFx::AS2::Value qval; // [esp+20h] [ebp-10h] BYREF

  v3 = (Scaleform::GFx::XML::ElementNode *)elemNode;
  StringManager = Scaleform::GFx::AS2::GlobalContext::GetStringManager(penv->StringContext.pContext);
  elemNode = Scaleform::GFx::ASStringManager::CreateStringNode(StringManager->pStringManager, "xmlns", 5u);
  ++elemNode->RefCount;
  if ( v3->Prefix.pNode->Size )
  {
    Scaleform::GFx::ASString::Append(
      (Scaleform::GFx::ASString *)&elemNode,
      (char *)&stru_95963C.m_max_end,
      (Scaleform::GFx::ASStringNode *)1);
    Scaleform::GFx::ASString::Append(
      (Scaleform::GFx::ASString *)&elemNode,
      (char *)v3->Prefix.pNode->pData,
      (Scaleform::GFx::ASStringNode *)strlen(v3->Prefix.pNode->pData));
  }
  p_EmptyStringNode = &v3->MemoryManager.pObject->StringPool.EmptyStringNode;
  qval.T.Type = 0;
  Scaleform::GFx::XML::DOMString::DOMString(&v14, p_EmptyStringNode);
  p_Namespace = &v3->Namespace;
  Scaleform::GFx::XML::DOMString::AssignNode(&v3->Namespace, v14.pNode);
  Scaleform::GFx::XML::DOMString::~DOMString(&v14);
  (*((void (__thiscall **)(Scaleform::GFx::XML::ShadowRefBase_vtbl *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::ASStringNode **, Scaleform::GFx::AS2::Value *))v3->pShadow[2].__vftable[4].~Scaleform::GFx::XML::ShadowRefBase
   + 4))(
    v3->pShadow[2].__vftable + 4,
    penv,
    &elemNode,
    &qval);
  if ( !qval.T.Type || qval.T.Type == 10 )
  {
    Parent = v3->Parent;
    if ( !Parent )
      goto LABEL_18;
    while ( 1 )
    {
      if ( !Parent->pShadow )
      {
        Scaleform::GFx::AS2::CreateShadow(
          (Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> *)&ns,
          penv,
          Parent,
          proot);
        pNode = ns.pNode;
        if ( ns.pNode )
        {
          RefCount = ns.pNode->RefCount;
          if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
          {
            ns.pNode->RefCount = RefCount - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)pNode);
          }
        }
      }
      (*((void (__thiscall **)(Scaleform::GFx::XML::ShadowRefBase_vtbl *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::ASStringNode **, Scaleform::GFx::AS2::Value *))Parent->pShadow[2].__vftable[4].~Scaleform::GFx::XML::ShadowRefBase
       + 4))(
        Parent->pShadow[2].__vftable + 4,
        penv,
        &elemNode,
        &qval);
      if ( qval.T.Type )
      {
        if ( qval.T.Type != 10 )
          break;
      }
      Parent = Parent->Parent;
      if ( !Parent )
        goto LABEL_18;
    }
    Scaleform::GFx::AS2::Value::ToStringImpl(&qval, (Scaleform::GFx::ASString *)&v14, penv, -1, 0);
    StringNode = Scaleform::GFx::XML::DOMStringManager::CreateStringNode(
                   &v3->MemoryManager.pObject->StringPool,
                   v14.pNode->pData,
                   (unsigned int)v14.pNode[1].pData);
    Scaleform::GFx::XML::DOMString::DOMString((Scaleform::GFx::XML::DOMString *)&ns, StringNode);
    Scaleform::GFx::XML::DOMString::AssignNode(p_Namespace, (Scaleform::GFx::XML::DOMStringNode *)ns.pNode);
    Scaleform::GFx::XML::DOMString::~DOMString((Scaleform::GFx::XML::DOMString *)&ns);
    v7 = (Scaleform::GFx::ASStringNode *)v14.pNode;
  }
  else
  {
    Scaleform::GFx::AS2::Value::ToStringImpl(&qval, &ns, penv, -1, 0);
    v6 = Scaleform::GFx::XML::DOMStringManager::CreateStringNode(
           &v3->MemoryManager.pObject->StringPool,
           ns.pNode->pData,
           ns.pNode->Size);
    Scaleform::GFx::XML::DOMString::DOMString(&v14, v6);
    Scaleform::GFx::XML::DOMString::AssignNode(p_Namespace, v14.pNode);
    Scaleform::GFx::XML::DOMString::~DOMString(&v14);
    v7 = ns.pNode;
  }
  if ( !--v7->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v7);
LABEL_18:
  Scaleform::GFx::AS2::Value::~Value(&qval);
  v12 = elemNode;
  --elemNode->RefCount;
  if ( !v12->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
}
