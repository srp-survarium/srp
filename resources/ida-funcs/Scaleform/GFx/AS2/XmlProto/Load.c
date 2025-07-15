void __usercall Scaleform::GFx::AS2::XmlProto::Load(
        int a1@<ebx>,
        int a2@<ebp>,
        int a3@<edi>,
        const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // ebp
  Scaleform::GFx::AS2::Object *p_pProto; // ebp
  Scaleform::GFx::AS2::Value *v6; // esi
  Scaleform::GFx::AS2::Environment *Env; // edi
  Scaleform::GFx::AS2::Value *v8; // eax
  Scaleform::GFx::AS2::Environment *v9; // edx
  Scaleform::GFx::AS2::StringManager *StringManager; // eax
  int v11; // edi
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::MovieImpl *MovieImpl; // ebx
  Scaleform::GFx::ExternalLibPtr *pXMLObjectManager; // eax
  Scaleform::MemoryHeap *pHeap; // ecx
  Scaleform::GFx::XML::ObjectManager *v16; // eax
  Scaleform::GFx::ASStringNode *v17; // eax
  Scaleform::GFx::Resource *v18; // eax
  Scaleform::GFx::Resource *v19; // ebx
  Scaleform::GFx::ASStringNode *v20; // eax
  Scaleform::RefCountVImpl *v21; // eax
  Scaleform::GFx::Resource *v22; // ebx
  Scaleform::GFx::AS2::StringManager *v23; // eax
  Scaleform::GFx::ASStringNode *v24; // eax
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
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v35; // ecx
  unsigned int v36; // edx
  Scaleform::GFx::ASStringNode *v37; // ecx
  Scaleform::GFx::ASStringNode *v38; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323>_vtbl *v40; // [esp+10h] [ebp-5Ch]
  Scaleform::GFx::AS2::RefCountBaseGC<323>_vtbl *v41; // [esp+10h] [ebp-5Ch]
  Scaleform::GFx::ASStringNode *ConstStringNode; // [esp+20h] [ebp-4Ch] BYREF
  Scaleform::GFx::ASStringNode *v44; // [esp+24h] [ebp-48h] BYREF
  char v45; // [esp+2Bh] [ebp-41h]
  Scaleform::GFx::ASStringNode *v46; // [esp+2Ch] [ebp-40h]
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v47; // [esp+30h] [ebp-3Ch]
  Scaleform::GFx::ASStringNode *v48; // [esp+34h] [ebp-38h] BYREF
  Scaleform::GFx::ASStringNode *v49; // [esp+38h] [ebp-34h]
  Scaleform::GFx::AS2::FunctionRef result; // [esp+3Ch] [ebp-30h] BYREF
  Scaleform::GFx::AS2::Value v51; // [esp+48h] [ebp-24h] BYREF
  char v52; // [esp+58h] [ebp-14h]
  Scaleform::GFx::AS2::Value v53; // [esp+5Ch] [ebp-10h] BYREF

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
        v6 = fn->Result;
        Scaleform::GFx::AS2::Value::DropRefs(v6);
        v6->T.Type = 2;
        v6->V.BooleanValue = 0;
        return;
      }
      Env = fn->Env;
      v8 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
      Scaleform::GFx::AS2::Value::ToStringImpl(v8, (Scaleform::GFx::ASString *)&v44, Env, -1, 0);
      v9 = fn->Env;
      v53.T.Type = 0;
      StringManager = Scaleform::GFx::AS2::GlobalContext::GetStringManager(v9->StringContext.pContext);
      ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                          StringManager->pStringManager,
                          "onData",
                          6u,
                          0);
      ++ConstStringNode->RefCount;
      v11 = (int)&p_pProto->Scaleform::GFx::AS2::ObjectInterface;
      ((void (__thiscall *)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::ASStringNode **, Scaleform::GFx::AS2::Value *, int, int, int))p_pProto->GetMember)(
        &p_pProto->Scaleform::GFx::AS2::ObjectInterface,
        fn->Env,
        &ConstStringNode,
        &v53,
        a3,
        a1,
        a2);
      v12 = v46;
      --v46->RefCount;
      if ( !v12->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v12);
      Scaleform::GFx::AS2::Value::ToFunction((Scaleform::GFx::AS2::Value *)(&v53.NV + 1), &result, fn->Env);
      if ( result.Function->IsCFunction(result.Function) )
      {
        if ( Scaleform::GFx::AS2::XmlProto::DefaultOnData )
        {
          if ( result.Function->IsCFunction(result.Function)
            && (void (__cdecl *)(const Scaleform::GFx::AS2::FnCall *))result.Function[1].Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable == Scaleform::GFx::AS2::XmlProto::DefaultOnData )
          {
            goto LABEL_12;
          }
        }
        else if ( (void (__cdecl *)(const Scaleform::GFx::AS2::FnCall *))result.Function == Scaleform::GFx::AS2::XmlProto::DefaultOnData )
        {
LABEL_12:
          MovieImpl = Scaleform::GFx::AS2::Environment::GetMovieImpl(fn->Env);
          pXMLObjectManager = MovieImpl->pXMLObjectManager;
          if ( pXMLObjectManager )
          {
            v20 = (Scaleform::GFx::ASStringNode *)&pXMLObjectManager[-1];
            if ( v20 )
              ++v20->pManager;
            v46 = v20;
          }
          else
          {
            pHeap = fn->Env->StringContext.pContext->pHeap;
            v16 = (Scaleform::GFx::XML::ObjectManager *)pHeap->Alloc(pHeap, 64u, 0);
            if ( v16 )
              Scaleform::GFx::XML::ObjectManager::ObjectManager(v16, MovieImpl);
            else
              v17 = 0;
            v46 = v17;
            if ( v17 )
              MovieImpl->pXMLObjectManager = (Scaleform::GFx::ExternalLibPtr *)&v17->8;
            else
              MovieImpl->pXMLObjectManager = 0;
          }
          v21 = (Scaleform::RefCountVImpl *)MovieImpl->GetStateAddRef(
                                              &MovieImpl->Scaleform::GFx::StateBag,
                                              State_XMLSupport);
          v22 = (Scaleform::GFx::Resource *)v21;
          if ( v21 )
            Scaleform::RefCountImpl::Release(v21);
          v51.T.Type = 0;
          *(double *)&p_pProto[1].RefCount = 0.0;
          v23 = Scaleform::GFx::AS2::GlobalContext::GetStringManager(fn->Env->StringContext.pContext);
          v48 = Scaleform::GFx::ASStringManager::CreateConstStringNode(v23->pStringManager, "ignoreWhite", 0xBu, 0);
          ++v48->RefCount;
          (*(void (__thiscall **)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::ASStringNode **, Scaleform::GFx::AS2::Value *))(*(_DWORD *)v11 + 16))(
            &p_pProto->Scaleform::GFx::AS2::ObjectInterface,
            fn->Env,
            &v48,
            &v51);
          v24 = v48;
          --v48->RefCount;
          if ( !v24->RefCount )
            Scaleform::GFx::ASStringNode::ReleaseNode(v24);
          LOBYTE(v49) = Scaleform::GFx::AS2::Value::ToBool(&v51, v11, fn->Env);
          v25 = (Scaleform::GFx::AS2::XMLFileLoaderAndParserImpl *)Scaleform::RefCountBaseStatImpl<Scaleform::RefCountVImpl,3>::operator new(0x1Cu);
          if ( v25 )
          {
            Scaleform::GFx::AS2::XMLFileLoaderAndParserImpl::XMLFileLoaderAndParserImpl(
              v25,
              v22,
              (Scaleform::GFx::XML::ObjectManager *)v46,
              (bool)v49);
            v27 = v26;
          }
          else
          {
            v27 = 0;
          }
          v40 = v47->__vftable;
          AS2Root = Scaleform::GFx::AS2::Environment::GetAS2Root(fn->Env);
          Scaleform::GFx::AS2::MovieRoot::AddXmlLoadQueueEntry(AS2Root, p_pProto, v27, (const __m128i *)v40, LM_None);
          Scaleform::GFx::AS2::Value::SetBool(fn->Result, 1);
          if ( v27 )
            Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v27);
          Scaleform::GFx::AS2::Value::~Value(&v51);
          if ( v46 )
            Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)v46);
LABEL_40:
          p_StringContext = &fn->Env->StringContext;
          v45 = 2;
          v52 = 2;
          v53.T.Type = 0;
          v32 = Scaleform::GFx::AS2::GlobalContext::GetStringManager(p_StringContext->pContext);
          v49 = Scaleform::GFx::ASStringManager::CreateConstStringNode(v32->pStringManager, "loaded", 6u, 0);
          ++v49->RefCount;
          (*(void (__thiscall **)(int, Scaleform::GFx::AS2::ASStringContext *))(*(_DWORD *)v11 + 40))(
            v11,
            &fn->Env->StringContext);
          v33 = v46;
          --v46->RefCount;
          if ( !v33->RefCount )
            Scaleform::GFx::ASStringNode::ReleaseNode(v33);
          Scaleform::GFx::AS2::Value::~Value((Scaleform::GFx::AS2::Value *)&v51.NV.4);
          if ( ((unsigned __int8)v49 & 2) == 0 )
          {
            if ( v47 )
            {
              RefCount = v47->RefCount;
              v35 = v47;
              if ( (RefCount & 0x3FFFFFF) != 0 )
              {
                v47->RefCount = RefCount - 1;
                Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v35);
              }
            }
          }
          v47 = 0;
          if ( ((unsigned __int8)v49 & 1) == 0 )
          {
            if ( v48 )
            {
              v36 = v48->RefCount;
              v37 = v48;
              if ( (v36 & 0x3FFFFFF) != 0 )
              {
                v48->RefCount = v36 - 1;
                Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v37);
              }
            }
          }
          v48 = 0;
          Scaleform::GFx::AS2::Value::~Value(&v53);
          v38 = v44;
          --v44->RefCount;
          if ( !v38->RefCount )
            Scaleform::GFx::ASStringNode::ReleaseNode(v38);
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
      v41 = v47->__vftable;
      v29 = Scaleform::GFx::AS2::Environment::GetAS2Root(fn->Env);
      Scaleform::GFx::AS2::MovieRoot::AddXmlLoadQueueEntry(v29, p_pProto, v19, (const __m128i *)v41, LM_None);
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
