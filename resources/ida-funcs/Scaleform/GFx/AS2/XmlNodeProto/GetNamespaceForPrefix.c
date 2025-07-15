void __cdecl Scaleform::GFx::AS2::XmlNodeProto::GetNamespaceForPrefix(const Scaleform::GFx::AS2::FnCall *fn)
{
  bool v1; // bl
  bool v2; // al
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *p_pProto; // ebp
  Scaleform::GFx::AS2::Value *v5; // edi
  Scaleform::GFx::LogState *Log; // eax
  Scaleform::GFx::AS2::Object *pObject; // ebp
  Scaleform::GFx::AS2::Environment *Env; // edi
  Scaleform::GFx::AS2::Value *v9; // eax
  Scaleform::GFx::AS2::StringManager *StringManager; // eax
  Scaleform::GFx::XML::ElementNode *Parent; // edi
  Scaleform::GFx::AS2::XmlNodeObject *v12; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::ASStringNode *v14; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v16; // eax
  Scaleform::GFx::ASString pfxquery; // [esp+10h] [ebp-20h] BYREF
  Scaleform::GFx::ASString str; // [esp+14h] [ebp-1Ch] BYREF
  Scaleform::GFx::AS2::XmlNodeObject *pthis; // [esp+18h] [ebp-18h] BYREF
  Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> result; // [esp+1Ch] [ebp-14h] BYREF
  Scaleform::GFx::AS2::Value qval; // [esp+20h] [ebp-10h] BYREF

  v1 = Scaleform::GFx::AS2::FnCall::CheckThisPtr(fn, 0x1Du);
  v2 = Scaleform::GFx::AS2::FnCall::CheckThisPtr(fn, 0x1Cu);
  if ( !v1 && !v2 )
  {
    Scaleform::GFx::AS2::FnCall::ThisPtrError(fn, "XMLNode", 0, 0);
    return;
  }
  ThisPtr = fn->ThisPtr;
  if ( ThisPtr )
  {
    p_pProto = &ThisPtr[-2].pProto;
    pthis = (Scaleform::GFx::AS2::XmlNodeObject *)&ThisPtr[-2].pProto;
    if ( ThisPtr != (Scaleform::GFx::AS2::ObjectInterface *)16 )
    {
      v5 = fn->Result;
      Scaleform::GFx::AS2::Value::DropRefs(v5);
      v5->T.Type = 1;
      Log = (Scaleform::GFx::LogState *)Scaleform::GFx::AS2::FnCall::GetLog(fn);
      pObject = p_pProto[14].pObject;
      if ( pObject )
      {
        if ( LOBYTE(pObject->ResolveHandler.Function) == 1 )
        {
          if ( fn->NArgs < 1 )
            return;
          Env = fn->Env;
          v9 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
          Scaleform::GFx::AS2::Value::ToStringImpl(v9, &str, Env, -1, 0);
          StringManager = Scaleform::GFx::AS2::GlobalContext::GetStringManager(fn->Env->StringContext.pContext);
          pfxquery.pNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                             StringManager->pStringManager,
                             (__m128i *)"xmlns",
                             5u);
          ++pfxquery.pNode->RefCount;
          if ( str.pNode->Size )
          {
            Scaleform::GFx::ASString::operator+=(&pfxquery, (const __m128i *)":");
            Scaleform::GFx::ASString::operator+=(&pfxquery, (const __m128i *)str.pNode->pData);
          }
          qval.T.Type = 0;
          (*(void (__thiscall **)(unsigned int, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))(*(_DWORD *)(pObject->Members.mHash.pTable[1].EntryCount + 16) + 16))(
            pObject->Members.mHash.pTable[1].EntryCount + 16,
            fn->Env,
            &pfxquery,
            &qval);
          if ( !qval.T.Type || qval.T.Type == 10 )
          {
            Parent = (Scaleform::GFx::XML::ElementNode *)pObject->Scaleform::GFx::AS2::ObjectInterface::__vftable;
            if ( !Parent )
            {
LABEL_24:
              Scaleform::GFx::AS2::Value::~Value(&qval);
              pNode = pfxquery.pNode;
              --pfxquery.pNode->RefCount;
              if ( !pNode->RefCount )
                Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
              v16 = str.pNode;
              --str.pNode->RefCount;
              if ( !v16->RefCount )
                Scaleform::GFx::ASStringNode::ReleaseNode(v16);
              return;
            }
            while ( 1 )
            {
              if ( !Parent->pShadow )
              {
                Scaleform::GFx::AS2::CreateShadow(&result, fn->Env, Parent, pthis->pRootNode.pObject);
                v12 = result.pObject;
                if ( result.pObject )
                {
                  RefCount = result.pObject->RefCount;
                  if ( (RefCount & 0x3FFFFFF) != 0 )
                  {
                    result.pObject->RefCount = RefCount - 1;
                    Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v12);
                  }
                }
              }
              (*((void (__thiscall **)(Scaleform::GFx::XML::ShadowRefBase_vtbl *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))Parent->pShadow[2].__vftable[4].~Scaleform::GFx::XML::ShadowRefBase
               + 4))(
                Parent->pShadow[2].__vftable + 4,
                fn->Env,
                &pfxquery,
                &qval);
              if ( qval.T.Type )
              {
                if ( qval.T.Type != 10 )
                  break;
              }
              Parent = Parent->Parent;
              if ( !Parent )
                goto LABEL_24;
            }
          }
          Scaleform::GFx::AS2::Value::ToStringImpl(&qval, (Scaleform::GFx::ASString *)&pthis, fn->Env, -1, 0);
          Scaleform::GFx::AS2::Value::SetString(fn->Result, (const Scaleform::GFx::ASString *)&pthis);
          v14 = (Scaleform::GFx::ASStringNode *)pthis;
          --pthis->RefCount;
          if ( !v14->RefCount )
            Scaleform::GFx::ASStringNode::ReleaseNode(v14);
          goto LABEL_24;
        }
        if ( Log )
          Scaleform::GFx::LogState::LogMessageByType(
            Log,
            (Scaleform::LogMessageId)147456,
            "XMLNodeProto::GetNamespaceForPrefix - only element nodes support this method.");
      }
    }
  }
}
