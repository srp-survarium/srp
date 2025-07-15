void __cdecl Scaleform::GFx::AS2::XmlNodeCtorFunction::GlobalCtor(const Scaleform::GFx::AS2::FnCall *fn)
{
  const Scaleform::GFx::AS2::FnCall *v1; // ebx
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // ebp
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *p_pProto; // ebp
  Scaleform::MemoryHeap *pHeap; // ecx
  Scaleform::GFx::AS2::XmlNodeObject *v5; // eax
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *v6; // eax
  Scaleform::Log *Log; // eax
  bool v8; // cc
  Scaleform::GFx::LogState *v9; // esi
  const Scaleform::GFx::AS2::Value *v10; // eax
  const Scaleform::GFx::AS2::Value *v11; // eax
  Scaleform::GFx::MovieImpl *MovieImpl; // esi
  Scaleform::GFx::ExternalLibPtr *pXMLObjectManager; // eax
  Scaleform::MemoryHeap *v14; // ecx
  Scaleform::GFx::XML::ObjectManager *v15; // eax
  Scaleform::GFx::XML::ObjectManager *v16; // eax
  Scaleform::GFx::XML::ObjectManager *v17; // edi
  Scaleform::GFx::XML::DOMStringNode *v18; // ecx
  const char *v19; // eax
  const char *v20; // esi
  Scaleform::GFx::XML::DOMString *String; // eax
  Scaleform::GFx::XML::DOMStringNode *v22; // ecx
  Scaleform::GFx::XML::DOMStringNode *ElementNode; // esi
  const Scaleform::GFx::AS2::FnCall *RootNode; // eax
  Scaleform::RefCountNTSImpl *pObject; // ecx
  Scaleform::GFx::XML::DOMStringNode *pNode; // edx
  Scaleform::GFx::XML::DOMString *v27; // eax
  Scaleform::GFx::XML::DOMStringNode *v28; // ecx
  Scaleform::GFx::XML::DOMStringNode *TextNode; // esi
  Scaleform::GFx::XML::RootNode *v30; // eax
  Scaleform::RefCountNTSImpl *v31; // ecx
  Scaleform::GFx::XML::RootNode *v32; // ebx
  Scaleform::GFx::XML::RootNode *v33; // eax
  Scaleform::RefCountNTSImpl *v34; // ecx
  Scaleform::GFx::XML::RootNode *v35; // ebx
  long double v36; // st7
  Scaleform::GFx::AS2::Object *v37; // edx
  Scaleform::GFx::ASStringNode *v38; // eax
  Scaleform::GFx::AS2::Object *v39; // eax
  Scaleform::GFx::XML::DOMString v40[5]; // [esp-4h] [ebp-4Ch] BYREF
  Scaleform::GFx::XML::DOMString result; // [esp+10h] [ebp-38h] BYREF
  Scaleform::GFx::XML::DOMString localname; // [esp+14h] [ebp-34h] BYREF
  Scaleform::GFx::ASString s; // [esp+18h] [ebp-30h] BYREF
  Scaleform::GFx::XML::DOMString prefix; // [esp+1Ch] [ebp-2Ch] BYREF
  long double nt; // [esp+20h] [ebp-28h]
  Scaleform::GFx::AS2::Value nodeValue; // [esp+28h] [ebp-20h] BYREF
  Scaleform::GFx::AS2::Value nodeType; // [esp+38h] [ebp-10h] BYREF

  v1 = fn;
  if ( fn->ThisPtr
    && (fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_XMLNode
     || v1->ThisPtr->GetObjectType(v1->ThisPtr) == Object_XML) )
  {
    ThisPtr = v1->ThisPtr;
    if ( ThisPtr )
    {
      p_pProto = &ThisPtr[-2].pProto;
      if ( p_pProto )
        p_pProto[3].pObject = (Scaleform::GFx::AS2::Object *)(((int)&p_pProto[3].pObject->__vftable + 1) & 0x8FFFFFFF);
    }
    else
    {
      p_pProto = 0;
    }
  }
  else
  {
    pHeap = v1->Env->StringContext.pContext->pHeap;
    v5 = (Scaleform::GFx::AS2::XmlNodeObject *)pHeap->Alloc(pHeap, 60u, 0);
    if ( v5 )
      Scaleform::GFx::AS2::XmlNodeObject::XmlNodeObject(v5, v1->Env);
    else
      v6 = 0;
    p_pProto = v6;
  }
  Log = Scaleform::GFx::AS2::FnCall::GetLog(v1);
  v8 = v1->NArgs <= 0;
  v9 = (Scaleform::GFx::LogState *)Log;
  nodeType.T.Type = 0;
  nodeValue.T.Type = 0;
  if ( v8 )
    goto LABEL_52;
  v10 = Scaleform::GFx::AS2::FnCall::Arg(v1, 0);
  Scaleform::GFx::AS2::Value::operator=(&nodeType, v10);
  if ( v1->NArgs > 1 )
  {
    v11 = Scaleform::GFx::AS2::FnCall::Arg(v1, 1);
    Scaleform::GFx::AS2::Value::operator=(&nodeValue, v11);
  }
  if ( !nodeType.T.Type || nodeType.T.Type == 10 )
  {
LABEL_52:
    if ( v9 )
      Scaleform::GFx::LogState::LogMessageByType(
        v9,
        (Scaleform::LogMessageId)147456,
        "XMLNodeCtorFunction::GlobalCtor - node type not specified");
  }
  else
  {
    nt = Scaleform::GFx::AS2::Value::ToNumber(&nodeType, v1->Env);
    if ( !nodeValue.T.Type || nodeValue.T.Type == 10 )
    {
      if ( v9 )
        Scaleform::GFx::LogState::LogMessageByType(
          v9,
          (Scaleform::LogMessageId)147456,
          "XMLNodeCtorFunction::GlobalCtor - malformed XMLNode object");
    }
    else
    {
      MovieImpl = Scaleform::GFx::AS2::Environment::GetMovieImpl(v1->Env);
      pXMLObjectManager = MovieImpl->pXMLObjectManager;
      if ( pXMLObjectManager )
      {
        v17 = (Scaleform::GFx::XML::ObjectManager *)&pXMLObjectManager[-1];
        if ( pXMLObjectManager != (Scaleform::GFx::ExternalLibPtr *)8 )
          ++v17->RefCount;
      }
      else
      {
        v14 = v1->Env->StringContext.pContext->pHeap;
        v15 = (Scaleform::GFx::XML::ObjectManager *)v14->Alloc(v14, 64u, 0);
        if ( v15 )
          Scaleform::GFx::XML::ObjectManager::ObjectManager(v15, MovieImpl);
        else
          v16 = 0;
        v17 = v16;
        if ( v16 )
          MovieImpl->pXMLObjectManager = &v16->Scaleform::GFx::ExternalLibPtr;
        else
          MovieImpl->pXMLObjectManager = 0;
      }
      Scaleform::GFx::XML::DOMString::DOMString(&localname, &v17->StringPool.EmptyStringNode);
      Scaleform::GFx::XML::DOMString::DOMString(&prefix, &v17->StringPool.EmptyStringNode);
      Scaleform::GFx::AS2::Value::ToStringImpl(&nodeValue, &s, v1->Env, -1, 0);
      if ( nt == 1.0 )
      {
        strchr((char *)s.pNode->pData, 0x3Au);
        v20 = v19;
        if ( v19 )
        {
          String = Scaleform::GFx::XML::ObjectManager::CreateString(
                     v17,
                     (Scaleform::GFx::XML::DOMString *)&fn,
                     s.pNode->pData,
                     v19 - s.pNode->pData);
          Scaleform::GFx::XML::DOMString::AssignNode(&prefix, String->pNode);
          Scaleform::GFx::XML::DOMString::~DOMString((Scaleform::GFx::XML::DOMString *)&fn);
          v40[0] = (Scaleform::GFx::XML::DOMString)Scaleform::GFx::XML::ObjectManager::CreateString(
                                                     v17,
                                                     (Scaleform::GFx::XML::DOMString *)&fn,
                                                     v20 + 1,
                                                     strlen(v20))->pNode;
        }
        else
        {
          v40[0] = (Scaleform::GFx::XML::DOMString)Scaleform::GFx::XML::ObjectManager::CreateString(
                                                     v17,
                                                     (Scaleform::GFx::XML::DOMString *)&fn,
                                                     s.pNode->pData,
                                                     s.pNode->Size)->pNode;
        }
        Scaleform::GFx::XML::DOMString::AssignNode(&localname, v40[0].pNode);
        Scaleform::GFx::XML::DOMString::~DOMString((Scaleform::GFx::XML::DOMString *)&fn);
        v40[0].pNode = v22;
        Scaleform::GFx::XML::DOMString::DOMString(v40, &localname);
        ElementNode = (Scaleform::GFx::XML::DOMStringNode *)Scaleform::GFx::XML::ObjectManager::CreateElementNode(
                                                              v17,
                                                              v40[0]);
        v40[0].pNode = ElementNode;
        p_pProto[14].pObject = (Scaleform::GFx::AS2::Object *)ElementNode;
        RootNode = (const Scaleform::GFx::AS2::FnCall *)Scaleform::GFx::XML::ObjectManager::CreateRootNode(
                                                          v17,
                                                          (Scaleform::GFx::XML::Node *)v40[0].pNode);
        pObject = (Scaleform::RefCountNTSImpl *)p_pProto[13].pObject;
        fn = RootNode;
        if ( pObject )
          Scaleform::RefCountNTSImpl::Release(pObject);
        pNode = prefix.pNode;
        p_pProto[13].pObject = (Scaleform::GFx::AS2::Object *)fn;
        Scaleform::GFx::XML::DOMString::AssignNode(
          (Scaleform::GFx::XML::DOMString *)&p_pProto[14].pObject->ResolveHandler.pLocalFrame,
          pNode);
        if ( ElementNode )
          Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)ElementNode);
      }
      else
      {
        if ( 3.0 == nt )
        {
          v27 = Scaleform::GFx::XML::ObjectManager::CreateString(v17, &result, s.pNode->pData, s.pNode->Size);
          Scaleform::GFx::XML::DOMString::AssignNode(&localname, v27->pNode);
          Scaleform::GFx::XML::DOMString::~DOMString(&result);
          v40[0].pNode = v28;
          Scaleform::GFx::XML::DOMString::DOMString(v40, &localname);
          TextNode = (Scaleform::GFx::XML::DOMStringNode *)Scaleform::GFx::XML::ObjectManager::CreateTextNode(
                                                             v17,
                                                             v40[0]);
          v40[0].pNode = TextNode;
          p_pProto[14].pObject = (Scaleform::GFx::AS2::Object *)TextNode;
          v30 = Scaleform::GFx::XML::ObjectManager::CreateRootNode(v17, (Scaleform::GFx::XML::Node *)v40[0].pNode);
          v31 = (Scaleform::RefCountNTSImpl *)p_pProto[13].pObject;
          v32 = v30;
          if ( v31 )
            Scaleform::RefCountNTSImpl::Release(v31);
          p_pProto[13].pObject = (Scaleform::GFx::AS2::Object *)v32;
        }
        else
        {
          v40[0].pNode = v18;
          Scaleform::GFx::XML::DOMString::DOMString(v40, &localname);
          TextNode = (Scaleform::GFx::XML::DOMStringNode *)Scaleform::GFx::XML::ObjectManager::CreateTextNode(
                                                             v17,
                                                             v40[0]);
          v40[0].pNode = TextNode;
          p_pProto[14].pObject = (Scaleform::GFx::AS2::Object *)TextNode;
          v33 = Scaleform::GFx::XML::ObjectManager::CreateRootNode(v17, (Scaleform::GFx::XML::Node *)v40[0].pNode);
          v34 = (Scaleform::RefCountNTSImpl *)p_pProto[13].pObject;
          v35 = v33;
          if ( v34 )
            Scaleform::RefCountNTSImpl::Release(v34);
          v36 = nt;
          p_pProto[13].pObject = (Scaleform::GFx::AS2::Object *)v35;
          v37 = p_pProto[14].pObject;
          LODWORD(nt) = (int)v36;
          LOBYTE(v37->ResolveHandler.Function) = (int)v36;
        }
        if ( TextNode )
          Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)TextNode);
        v1 = fn;
      }
      Scaleform::GFx::AS2::SetupShadow(
        (Scaleform::GFx::XML::ElementNode *)p_pProto[14].pObject,
        v1->Env,
        (Scaleform::GFx::XML::ShadowRefBase_vtbl *)p_pProto);
      v38 = s.pNode;
      --s.pNode->RefCount;
      if ( !v38->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v38);
      Scaleform::GFx::XML::DOMString::~DOMString(&prefix);
      Scaleform::GFx::XML::DOMString::~DOMString(&localname);
      if ( v17 )
        Scaleform::RefCountNTSImpl::Release(v17);
    }
  }
  Scaleform::GFx::AS2::Value::SetAsObject(v1->Result, (Scaleform::GFx::AS2::Object *)p_pProto);
  Scaleform::GFx::AS2::Value::~Value(&nodeValue);
  Scaleform::GFx::AS2::Value::~Value(&nodeType);
  if ( p_pProto )
  {
    v39 = p_pProto[3].pObject;
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & (unsigned int)v39) != 0 )
    {
      p_pProto[3].pObject = (Scaleform::GFx::AS2::Object *)((char *)v39 - 1);
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)p_pProto);
    }
  }
}
