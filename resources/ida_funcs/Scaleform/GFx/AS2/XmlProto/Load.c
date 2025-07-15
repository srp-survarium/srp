// local variable allocation has failed, the output may be wrong!
void __usercall Scaleform::GFx::AS2::XmlProto::Load(
        int a1@<ebx>,
        int a2@<ebp>,
        int a3@<edi>,
        const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // ebp
  Scaleform::GFx::AS2::Object *p_pProto; // ebp
  Scaleform::GFx::AS2::Value *Result; // esi
  Scaleform::GFx::AS2::Environment *Env; // edi
  Scaleform::GFx::AS2::Value *v8; // eax
  Scaleform::GFx::AS2::Environment *v9; // edx
  Scaleform::GFx::AS2::StringManager *StringManager; // eax
  char *v11; // edi
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::MovieImpl *MovieImpl; // ebx
  Scaleform::GFx::ExternalLibPtr *pXMLObjectManager; // eax
  Scaleform::MemoryHeap *pHeap; // ecx
  Scaleform::GFx::XML::ObjectManager *v16; // eax
  Scaleform::RefCountNTSImpl *v17; // eax
  Scaleform::GFx::Resource *v18; // eax
  Scaleform::GFx::Resource *v19; // ebx
  Scaleform::RefCountNTSImpl *v20; // eax
  Scaleform::RefCountVImpl *v21; // eax
  Scaleform::GFx::Resource *v22; // ebx
  Scaleform::GFx::AS2::StringManager *v23; // eax
  Scaleform::GFx::ASStringNode *pLocalFrame; // eax
  Scaleform::GFx::AS2::XMLFileLoaderAndParserImpl *v25; // eax
  Scaleform::GFx::Resource *v26; // eax
  Scaleform::GFx::Resource *v27; // ebx
  Scaleform::GFx::AS2::MovieRoot *AS2Root; // eax
  Scaleform::GFx::AS2::MovieRoot *v29; // eax
  Scaleform::GFx::AS2::Value *v30; // ebp
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // eax
  Scaleform::GFx::AS2::StringManager *v32; // eax
  Scaleform::GFx::ASStringNode *v33; // eax
  unsigned int RefCount; // edx
  Scaleform::GFx::AS2::FunctionObject *Function; // ecx
  unsigned int v36; // edx
  Scaleform::GFx::AS2::LocalFrame *v37; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  char *v40; // [esp+10h] [ebp-5Ch]
  char *v41; // [esp+10h] [ebp-5Ch]
  Scaleform::Ptr<Scaleform::GFx::XML::ObjectManager> memMgr; // [esp+20h] [ebp-4Ch] BYREF
  Scaleform::GFx::ASString urlStr; // [esp+24h] [ebp-48h] BYREF
  char v45; // [esp+2Bh] [ebp-41h]
  Scaleform::GFx::XML::ObjectManager *bws; // [esp+2Ch] [ebp-40h] OVERLAPPED
  Scaleform::GFx::AS2::FunctionRef odf; // [esp+30h] [ebp-3Ch] BYREF
  Scaleform::GFx::AS2::Value ignorews; // [esp+3Ch] [ebp-30h] BYREF
  Scaleform::GFx::AS2::Value v49; // [esp+4Ch] [ebp-20h] BYREF
  Scaleform::GFx::AS2::Value onDataHandler; // [esp+5Ch] [ebp-10h] BYREF

  if ( !Scaleform::GFx::AS2::FnCall::CheckThisPtr(fn, 0x1Cu) )
  {
    Scaleform::GFx::AS2::FnCall::ThisPtrError(fn, "XML", 0, 0);
    return;
  }
  ThisPtr = fn->ThisPtr;
  if ( ThisPtr )
  {
    p_pProto = (Scaleform::GFx::AS2::Object *)&ThisPtr[-2].pProto;
    if ( p_pProto )
    {
      if ( !fn->NArgs )
      {
        Result = fn->Result;
        Scaleform::GFx::AS2::Value::DropRefs(Result);
        Result->T.Type = 2;
        Result->V.BooleanValue = 0;
        return;
      }
      Env = fn->Env;
      v8 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
      Scaleform::GFx::AS2::Value::ToStringImpl(v8, &urlStr, Env, -1, 0);
      v9 = fn->Env;
      onDataHandler.T.Type = 0;
      StringManager = Scaleform::GFx::AS2::GlobalContext::GetStringManager(v9->StringContext.pContext);
      memMgr.pObject = (Scaleform::GFx::XML::ObjectManager *)Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                                               StringManager->pStringManager,
                                                               "onData",
                                                               6u,
                                                               0);
      ++memMgr.pObject->pOwner;
      v11 = (char *)&p_pProto->Scaleform::GFx::AS2::ObjectInterface;
      ((void (__thiscall *)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::Environment *, Scaleform::Ptr<Scaleform::GFx::XML::ObjectManager> *, Scaleform::GFx::AS2::Value *, int, int, int))p_pProto->GetMember)(
        &p_pProto->Scaleform::GFx::AS2::ObjectInterface,
        fn->Env,
        &memMgr,
        &onDataHandler,
        a3,
        a1,
        a2);
      v12 = (Scaleform::GFx::ASStringNode *)bws;
      --bws->pOwner;
      if ( !v12->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v12);
      Scaleform::GFx::AS2::Value::ToFunction(
        (Scaleform::GFx::AS2::Value *)(&onDataHandler.NV + 1),
        (Scaleform::GFx::AS2::FunctionRef *)&ignorews,
        fn->Env);
      if ( (*(unsigned __int8 (__thiscall **)(_DWORD))(**(_DWORD **)&ignorews.T.Type + 52))(*(_DWORD *)&ignorews.T.Type) )
      {
        if ( Scaleform::GFx::AS2::XmlProto::DefaultOnData )
        {
          if ( (*(unsigned __int8 (__thiscall **)(_DWORD))(**(_DWORD **)&ignorews.T.Type + 52))(*(_DWORD *)&ignorews.T.Type)
            && *(void (__cdecl **)(const Scaleform::GFx::AS2::FnCall *))(*(_DWORD *)&ignorews.T.Type + 52) == Scaleform::GFx::AS2::XmlProto::DefaultOnData )
          {
            goto LABEL_12;
          }
        }
        else if ( *(void (__cdecl **)(const Scaleform::GFx::AS2::FnCall *))&ignorews.T.Type == Scaleform::GFx::AS2::XmlProto::DefaultOnData )
        {
LABEL_12:
          MovieImpl = Scaleform::GFx::AS2::Environment::GetMovieImpl(fn->Env);
          pXMLObjectManager = MovieImpl->pXMLObjectManager;
          if ( pXMLObjectManager )
          {
            v20 = (Scaleform::RefCountNTSImpl *)&pXMLObjectManager[-1];
            if ( v20 )
              ++v20->RefCount;
            bws = (Scaleform::GFx::XML::ObjectManager *)v20;
          }
          else
          {
            pHeap = fn->Env->StringContext.pContext->pHeap;
            v16 = (Scaleform::GFx::XML::ObjectManager *)pHeap->Alloc(pHeap, 64u, 0);
            if ( v16 )
              Scaleform::GFx::XML::ObjectManager::ObjectManager(v16, MovieImpl);
            else
              v17 = 0;
            bws = (Scaleform::GFx::XML::ObjectManager *)v17;
            if ( v17 )
              MovieImpl->pXMLObjectManager = (Scaleform::GFx::ExternalLibPtr *)&v17[1];
            else
              MovieImpl->pXMLObjectManager = 0;
          }
          v21 = (Scaleform::RefCountVImpl *)MovieImpl->GetStateAddRef(
                                              &MovieImpl->Scaleform::GFx::StateBag,
                                              State_XMLSupport);
          v22 = (Scaleform::GFx::Resource *)v21;
          if ( v21 )
            Scaleform::RefCountImpl::Release(v21);
          ignorews.V.FunctionValue.Flags = 0;
          *(double *)&p_pProto[1].RefCount = 0.0;
          v23 = Scaleform::GFx::AS2::GlobalContext::GetStringManager(fn->Env->StringContext.pContext);
          odf.pLocalFrame = (Scaleform::GFx::AS2::LocalFrame *)Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                                                 v23->pStringManager,
                                                                 "ignoreWhite",
                                                                 0xBu,
                                                                 0);
          ++odf.pLocalFrame->RefCount;
          (*(void (__thiscall **)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::AS2::LocalFrame **, Scaleform::GFx::AS2::Value::NumericType *))(*(_DWORD *)v11 + 16))(
            &p_pProto->Scaleform::GFx::AS2::ObjectInterface,
            fn->Env,
            &odf.pLocalFrame,
            &ignorews.NV + 1);
          pLocalFrame = (Scaleform::GFx::ASStringNode *)odf.pLocalFrame;
          --odf.pLocalFrame->RefCount;
          if ( !pLocalFrame->RefCount )
            Scaleform::GFx::ASStringNode::ReleaseNode(pLocalFrame);
          odf.Flags = Scaleform::GFx::AS2::Value::ToBool((Scaleform::GFx::AS2::Value *)(&ignorews.NV + 1), fn->Env);
          v25 = (Scaleform::GFx::AS2::XMLFileLoaderAndParserImpl *)Scaleform::RefCountBaseStatImpl<Scaleform::RefCountVImpl,3>::operator new(0x1Cu);
          if ( v25 )
          {
            Scaleform::GFx::AS2::XMLFileLoaderAndParserImpl::XMLFileLoaderAndParserImpl(v25, v22, bws, odf.Flags);
            v27 = v26;
          }
          else
          {
            v27 = 0;
          }
          v40 = (char *)odf.Function->__vftable;
          AS2Root = Scaleform::GFx::AS2::Environment::GetAS2Root(fn->Env);
          Scaleform::GFx::AS2::MovieRoot::AddXmlLoadQueueEntry(AS2Root, p_pProto, v27, v40, LM_None);
          Scaleform::GFx::AS2::Value::SetBool(fn->Result, 1);
          if ( v27 )
            Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v27);
          Scaleform::GFx::AS2::Value::~Value((Scaleform::GFx::AS2::Value *)(&ignorews.NV + 1));
          if ( bws )
            Scaleform::RefCountNTSImpl::Release(bws);
LABEL_40:
          p_StringContext = &fn->Env->StringContext;
          v45 = 2;
          v49.V.FunctionValue.Flags = 2;
          onDataHandler.T.Type = 0;
          v32 = Scaleform::GFx::AS2::GlobalContext::GetStringManager(p_StringContext->pContext);
          *(_DWORD *)&odf.Flags = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                    v32->pStringManager,
                                    "loaded",
                                    6u,
                                    0);
          ++*(_DWORD *)(*(_DWORD *)&odf.Flags + 12);
          (*(void (__thiscall **)(char *, Scaleform::GFx::AS2::ASStringContext *))(*(_DWORD *)v11 + 40))(
            v11,
            &fn->Env->StringContext);
          v33 = (Scaleform::GFx::ASStringNode *)bws;
          --bws->pOwner;
          if ( !v33->RefCount )
            Scaleform::GFx::ASStringNode::ReleaseNode(v33);
          Scaleform::GFx::AS2::Value::~Value(&v49);
          if ( (odf.Flags & 2) == 0 )
          {
            if ( odf.Function )
            {
              RefCount = odf.Function->RefCount;
              Function = odf.Function;
              if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
              {
                odf.Function->RefCount = RefCount - 1;
                Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
              }
            }
          }
          odf.Function = 0;
          if ( (odf.Flags & 1) == 0 )
          {
            if ( odf.pLocalFrame )
            {
              v36 = odf.pLocalFrame->RefCount;
              v37 = odf.pLocalFrame;
              if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v36) != 0 )
              {
                odf.pLocalFrame->RefCount = v36 - 1;
                Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v37);
              }
            }
          }
          odf.pLocalFrame = 0;
          Scaleform::GFx::AS2::Value::~Value(&onDataHandler);
          pNode = urlStr.pNode;
          --urlStr.pNode->RefCount;
          if ( !pNode->RefCount )
            Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
          return;
        }
      }
      v18 = (Scaleform::GFx::Resource *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 16, 0);
      if ( v18 )
      {
        v18->__vftable = (Scaleform::GFx::Resource_vtbl *)&Scaleform::RefCountImplCore::`vftable';
        v18->RefCount.Value = 1;
        v18->__vftable = (Scaleform::GFx::Resource_vtbl *)&Scaleform::GFx::AS2::XMLFileLoaderImpl::`vftable';
        v18->pLib = 0;
        v18[1].__vftable = 0;
        v19 = v18;
      }
      else
      {
        v19 = 0;
      }
      v41 = (char *)odf.Function->__vftable;
      v29 = Scaleform::GFx::AS2::Environment::GetAS2Root(fn->Env);
      Scaleform::GFx::AS2::MovieRoot::AddXmlLoadQueueEntry(v29, p_pProto, v19, v41, LM_None);
      v30 = fn->Result;
      Scaleform::GFx::AS2::Value::DropRefs(v30);
      v30->T.Type = 2;
      v30->V.BooleanValue = 1;
      if ( v19 )
        Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v19);
      goto LABEL_40;
    }
  }
}
