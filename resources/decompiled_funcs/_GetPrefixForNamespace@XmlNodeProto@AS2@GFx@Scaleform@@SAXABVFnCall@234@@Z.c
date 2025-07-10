void __cdecl Scaleform::GFx::AS2::XmlNodeProto::GetPrefixForNamespace(const Scaleform::GFx::AS2::FnCall *fn)
{
  bool v1; // bl
  bool v2; // al
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // ebp
  bool v4; // zf
  Scaleform::GFx::AS2::XmlNodeObject *p_pProto; // ebp
  Scaleform::GFx::AS2::Value *v6; // edi
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // ebx
  Scaleform::GFx::LogState *Log; // eax
  Scaleform::GFx::XML::Node *pRealNode; // edi
  Scaleform::GFx::AS2::Environment *Env; // ebp
  Scaleform::GFx::AS2::Value *v11; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::XML::ElementNode *i; // ebp
  Scaleform::GFx::AS2::XmlNodeObject *pObject; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Value *v16; // edi
  Scaleform::GFx::ASStringNode *v17; // eax
  Scaleform::GFx::AS2::Value *v18; // ecx
  const char *pData; // edi
  int v20; // eax
  unsigned int Size; // ebp
  Scaleform::GFx::AS2::StringManager *StringManager; // eax
  Scaleform::GFx::AS2::XmlNodeObject *StringNode; // edi
  Scaleform::GFx::AS2::StringManager *v24; // eax
  Scaleform::GFx::AS2::Value *v25; // ecx
  Scaleform::GFx::ASStringNode *v26; // eax
  Scaleform::GFx::ASStringNode *v27; // eax
  Scaleform::GFx::ASString pfx; // [esp+20h] [ebp-30h] BYREF
  Scaleform::GFx::ASString str; // [esp+24h] [ebp-2Ch] BYREF
  Scaleform::GFx::AS2::XmlNodeObject *pthis; // [esp+28h] [ebp-28h]
  Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> result; // [esp+2Ch] [ebp-24h] BYREF
  Scaleform::GFx::AS2::XMLPrefixQuerier pq; // [esp+30h] [ebp-20h] BYREF
  Scaleform::GFx::AS2::Value qval; // [esp+40h] [ebp-10h] BYREF

  v1 = Scaleform::GFx::AS2::FnCall::CheckThisPtr(fn, 0x1Du);
  v2 = Scaleform::GFx::AS2::FnCall::CheckThisPtr(fn, 0x1Cu);
  if ( v1 || v2 )
  {
    ThisPtr = fn->ThisPtr;
    if ( ThisPtr )
    {
      v4 = ThisPtr == (Scaleform::GFx::AS2::ObjectInterface *)16;
      p_pProto = (Scaleform::GFx::AS2::XmlNodeObject *)&ThisPtr[-2].pProto;
      pthis = p_pProto;
      if ( !v4 )
      {
        v6 = fn->Result;
        Scaleform::GFx::AS2::Value::DropRefs(v6);
        v6->T.Type = 1;
        p_StringContext = &fn->Env->StringContext;
        Log = (Scaleform::GFx::LogState *)Scaleform::GFx::AS2::FnCall::GetLog(fn);
        pRealNode = p_pProto->pRealNode;
        if ( pRealNode )
        {
          if ( pRealNode->Type == 1 )
          {
            if ( fn->NArgs >= 1 )
            {
              Env = fn->Env;
              v11 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
              Scaleform::GFx::AS2::Value::ToStringImpl(v11, &str, Env, -1, 0);
              pq.pEnv = fn->Env;
              qval.T.Type = 0;
              pq.__vftable = (Scaleform::GFx::AS2::XMLPrefixQuerier_vtbl *)&Scaleform::GFx::AS2::XMLPrefixQuerier::`vftable';
              pq.pKey = &str;
              pq.pVal = &qval;
              (*((void (__thiscall **)(Scaleform::GFx::XML::ShadowRefBase_vtbl *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::AS2::XMLPrefixQuerier *, _DWORD, _DWORD))pRealNode->pShadow[2].__vftable[4].~Scaleform::GFx::XML::ShadowRefBase
               + 8))(
                pRealNode->pShadow[2].__vftable + 4,
                p_StringContext,
                &pq,
                0,
                0);
              if ( qval.T.Type )
              {
                if ( qval.T.Type != 10 )
                {
                  Scaleform::GFx::AS2::Value::ToStringImpl(&qval, &pfx, fn->Env, -1, 0);
                  Scaleform::GFx::AS2::Value::SetString(fn->Result, &pfx);
                  pNode = pfx.pNode;
                  --pfx.pNode->RefCount;
                  if ( !pNode->RefCount )
                    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
                }
              }
              for ( i = pRealNode->Parent; fn->Result->T.Type == 1; i = i->Parent )
              {
                if ( !i )
                  break;
                if ( !i->pShadow )
                {
                  Scaleform::GFx::AS2::CreateShadow(&result, fn->Env, i, pthis->pRootNode.pObject);
                  pObject = result.pObject;
                  if ( result.pObject )
                  {
                    RefCount = result.pObject->RefCount;
                    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
                    {
                      result.pObject->RefCount = RefCount - 1;
                      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pObject);
                    }
                  }
                }
                (*((void (__thiscall **)(Scaleform::GFx::XML::ShadowRefBase_vtbl *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::AS2::XMLPrefixQuerier *, _DWORD, _DWORD))i->pShadow[2].__vftable[4].~Scaleform::GFx::XML::ShadowRefBase
                 + 8))(
                  i->pShadow[2].__vftable + 4,
                  p_StringContext,
                  &pq,
                  0,
                  0);
                if ( qval.T.Type && qval.T.Type != 10 )
                {
                  Scaleform::GFx::AS2::Value::ToStringImpl(&qval, &pfx, fn->Env, -1, 0);
                  v16 = fn->Result;
                  if ( v16->T.Type >= 5u )
                    Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
                  v16->T.Type = 5;
                  v16->NV.Int32Value = (int)pfx.pNode;
                  ++pfx.pNode->RefCount;
                  v17 = pfx.pNode;
                  --pfx.pNode->RefCount;
                  if ( !v17->RefCount )
                    Scaleform::GFx::ASStringNode::ReleaseNode(v17);
                }
              }
              v18 = fn->Result;
              if ( v18->T.Type != 1 )
              {
                Scaleform::GFx::AS2::Value::ToStringImpl(v18, &pfx, fn->Env, -1, 0);
                pData = pfx.pNode->pData;
                strchr((char *)pfx.pNode->pData, 0x3Au);
                Size = pfx.pNode->Size;
                if ( v20 )
                {
                  StringManager = Scaleform::GFx::AS2::GlobalContext::GetStringManager(p_StringContext->pContext);
                  StringNode = (Scaleform::GFx::AS2::XmlNodeObject *)Scaleform::GFx::ASStringManager::CreateStringNode(
                                                                       StringManager->pStringManager,
                                                                       (char *)pData + 6,
                                                                       Size - 6);
                }
                else
                {
                  v24 = Scaleform::GFx::AS2::GlobalContext::GetStringManager(p_StringContext->pContext);
                  StringNode = (Scaleform::GFx::AS2::XmlNodeObject *)Scaleform::GFx::ASStringManager::CreateStringNode(
                                                                       v24->pStringManager,
                                                                       (char *)pData + 5,
                                                                       Size - 5);
                }
                ++StringNode->RefCount;
                v25 = fn->Result;
                result.pObject = StringNode;
                Scaleform::GFx::AS2::Value::SetString(v25, (const Scaleform::GFx::ASString *)&result);
                v4 = StringNode->RefCount-- == 1;
                if ( v4 )
                  Scaleform::GFx::ASStringNode::ReleaseNode((Scaleform::GFx::ASStringNode *)StringNode);
                v26 = pfx.pNode;
                --pfx.pNode->RefCount;
                if ( !v26->RefCount )
                  Scaleform::GFx::ASStringNode::ReleaseNode(v26);
              }
              pq.__vftable = (Scaleform::GFx::AS2::XMLPrefixQuerier_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
              Scaleform::GFx::AS2::Value::~Value(&qval);
              v27 = str.pNode;
              --str.pNode->RefCount;
              if ( !v27->RefCount )
                Scaleform::GFx::ASStringNode::ReleaseNode(v27);
            }
          }
          else if ( Log )
          {
            Scaleform::GFx::LogState::LogMessageByType(
              Log,
              (Scaleform::LogMessageId)147456,
              "XMLNodeProto::GetNamespaceForPrefix - only element nodes support this method.");
          }
        }
      }
    }
  }
  else
  {
    Scaleform::GFx::AS2::FnCall::ThisPtrError(fn, "XMLNode", 0, 0);
  }
}
