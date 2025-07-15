void __cdecl Scaleform::GFx::AS2::XmlNodeProto::AppendChild(const Scaleform::GFx::AS2::FnCall *fn)
{
  bool v1; // bl
  bool v2; // al
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *p_pProto; // ebx
  Scaleform::GFx::LogState *Log; // edi
  Scaleform::GFx::XML::ElementNode *pObject; // eax
  Scaleform::GFx::AS2::Value *v7; // eax
  Scaleform::GFx::AS2::Object *v8; // eax
  Scaleform::GFx::AS2::Object *v9; // esi
  Scaleform::GFx::AS2::RefCountCollector<323> *pRCC; // edx
  Scaleform::GFx::AS2::RefCountCollector<323> *NumPages; // eax
  Scaleform::RefCountNTSImpl *v12; // edi
  Scaleform::GFx::AS2::RefCountCollector<323> *v13; // edx
  Scaleform::GFx::AS2::Object *v14; // eax
  Scaleform::RefCountNTSImpl *v15; // ecx
  Scaleform::GFx::AS2::RefCountCollector<323> *v16; // esi
  Scaleform::GFx::AS2::Environment *Env; // [esp-4h] [ebp-18h]
  Scaleform::GFx::XML::ElementNode *v18; // [esp+10h] [ebp-4h]

  v1 = Scaleform::GFx::AS2::FnCall::CheckThisPtr(fn, 0x1Du);
  v2 = Scaleform::GFx::AS2::FnCall::CheckThisPtr(fn, 0x1Cu);
  if ( v1 || v2 )
  {
    ThisPtr = fn->ThisPtr;
    if ( ThisPtr )
    {
      p_pProto = &ThisPtr[-2].pProto;
      if ( ThisPtr != (Scaleform::GFx::AS2::ObjectInterface *)16 )
      {
        Log = (Scaleform::GFx::LogState *)Scaleform::GFx::AS2::FnCall::GetLog(fn);
        pObject = (Scaleform::GFx::XML::ElementNode *)p_pProto[14].pObject;
        v18 = pObject;
        if ( pObject )
        {
          if ( pObject->Type == 1 )
          {
            if ( fn->NArgs > 0 )
            {
              Env = fn->Env;
              v7 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
              v8 = Scaleform::GFx::AS2::Value::ToObject(v7, Env);
              v9 = v8;
              if ( v8 && v8->GetObjectType(&v8->Scaleform::GFx::AS2::ObjectInterface) == Object_XMLNode )
              {
                pRCC = v9[1].pRCC;
                if ( pRCC )
                {
                  NumPages = (Scaleform::GFx::AS2::RefCountCollector<323> *)p_pProto[14].pObject->__vftable;
                  if ( NumPages )
                  {
                    while ( NumPages->Roots.NumPages )
                      NumPages = (Scaleform::GFx::AS2::RefCountCollector<323> *)NumPages->Roots.NumPages;
                  }
                  if ( NumPages == pRCC )
                  {
                    if ( Log )
                      Scaleform::GFx::LogState::LogMessageByType(
                        Log,
                        (Scaleform::LogMessageId)147456,
                        "XMLNode::appendChild - trying to add a child that is the root of the current tree");
                  }
                  else
                  {
                    v12 = (Scaleform::RefCountNTSImpl *)v9[1].pRCC;
                    ++pRCC->RefCount;
                    v13 = v9[1].pRCC;
                    if ( v13->Roots.NumPages )
                      Scaleform::GFx::XML::ElementNode::RemoveChild(
                        (Scaleform::GFx::XML::ElementNode *)v13->Roots.NumPages,
                        (Scaleform::GFx::XML::Node *)v9[1].pRCC);
                    Scaleform::GFx::XML::ElementNode::AppendChild(v18, (Scaleform::GFx::XML::Node *)v9[1].pRCC);
                    v14 = p_pProto[13].pObject;
                    if ( v14 )
                      ++v14->pRCC;
                    v15 = (Scaleform::RefCountNTSImpl *)v9[1].Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable;
                    if ( v15 )
                      Scaleform::RefCountNTSImpl::Release(v15);
                    v9[1].Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::Object_vtbl *)p_pProto[13].pObject;
                    v16 = v9[1].pRCC;
                    if ( LOBYTE(v16->ListRoot.__vftable) == 1 && !*(_DWORD *)(v16->ListRoot.RootIndex + 12) )
                      Scaleform::GFx::AS2::ResolveNamespace(
                        fn->Env,
                        (Scaleform::GFx::ASStringNode *)v16,
                        (Scaleform::GFx::XML::RootNode *)p_pProto[13].pObject);
                    Scaleform::RefCountNTSImpl::Release(v12);
                  }
                }
              }
              else if ( Log )
              {
                Scaleform::GFx::LogState::LogMessageByType(
                  Log,
                  (Scaleform::LogMessageId)147456,
                  "XMLNode::appendChild - trying to add a child that is not of type XMLNode");
              }
            }
          }
          else if ( Log )
          {
            Scaleform::GFx::LogState::LogMessageByType(
              Log,
              (Scaleform::LogMessageId)147456,
              "XMLNode::appendChild - trying to add a child to a text node");
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
