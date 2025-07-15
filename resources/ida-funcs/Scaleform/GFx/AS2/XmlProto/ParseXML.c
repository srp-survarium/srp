void __usercall Scaleform::GFx::AS2::XmlProto::ParseXML(
        int a1@<ebx>,
        int a2@<ebp>,
        const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // ebp
  Scaleform::GFx::AS2::XmlObject *p_pProto; // ebp
  Scaleform::GFx::AS2::Environment *Env; // esi
  Scaleform::GFx::AS2::Object *v6; // eax
  Scaleform::GFx::AS2::Object *v7; // eax
  Scaleform::GFx::AS2::Object *v8; // ebx
  Scaleform::GFx::XML::ElementNode *i; // edi
  Scaleform::GFx::AS2::GlobalContext *pContext; // ecx
  Scaleform::GFx::AS2::StringManager *StringManager; // eax
  Scaleform::GFx::AS2::ObjectInterface *v12; // edi
  Scaleform::GFx::AS2::ObjectInterface_vtbl *v13; // ebp
  unsigned int RefCount; // eax
  Scaleform::GFx::ASStringNode *v16; // [esp+18h] [ebp-14h]
  Scaleform::GFx::AS2::Value v17; // [esp+1Ch] [ebp-10h] BYREF

  if ( Scaleform::GFx::AS2::FnCall::CheckThisPtr(fn, 0x1Cu) )
  {
    ThisPtr = fn->ThisPtr;
    if ( ThisPtr )
    {
      p_pProto = (Scaleform::GFx::AS2::XmlObject *)&ThisPtr[-2].pProto;
      if ( p_pProto )
      {
        Scaleform::GFx::AS2::XML_LoadString(fn, p_pProto);
        Env = fn->Env;
        v6 = (Scaleform::GFx::AS2::Object *)((int (__thiscall *)(Scaleform::MemoryHeap *, int, _DWORD, int, int))Env->StringContext.pContext->pHeap->Alloc)(
                                              Env->StringContext.pContext->pHeap,
                                              52,
                                              0,
                                              a1,
                                              a2);
        if ( v6 )
        {
          Scaleform::GFx::AS2::Object::Object(v6, Env);
          v8 = v7;
        }
        else
        {
          v8 = 0;
        }
        for ( i = p_pProto->pRealNode[1].Parent; i; i = (Scaleform::GFx::XML::ElementNode *)i->NextSibling.pObject )
        {
          if ( i->Type == 1 )
            Scaleform::GFx::AS2::Xml_CreateIDMap(Env, i, p_pProto->pRootNode.pObject, v8);
        }
        pContext = Env->StringContext.pContext;
        *((_BYTE *)&v17.NV.Scaleform::GFx::AS2::Value::TypeDesc + 3) = 2;
        StringManager = Scaleform::GFx::AS2::GlobalContext::GetStringManager(pContext);
        v17.NV.Int32Value = (int)Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                   StringManager->pStringManager,
                                   "idMap",
                                   5u,
                                   0);
        ++*(_DWORD *)(v17.NV.Int32Value + 12);
        v12 = &p_pProto->Scaleform::GFx::AS2::ObjectInterface;
        v13 = p_pProto->Scaleform::GFx::AS2::XmlNodeObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable;
        Scaleform::GFx::AS2::Value::Value((Scaleform::GFx::AS2::Value *)((char *)&v17.NV.NumberValue + 4), v8);
        ((void (__thiscall *)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::Environment *, $B8BD913BABC9324639AA48504BEFB2FC *))v13->SetMember)(
          v12,
          Env,
          &v17.NV.4);
        if ( !--v16->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v16);
        Scaleform::GFx::AS2::Value::~Value(&v17);
        if ( v8 )
        {
          RefCount = v8->RefCount;
          if ( (RefCount & 0x3FFFFFF) != 0 )
          {
            v8->RefCount = RefCount - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v8);
          }
        }
      }
    }
  }
  else
  {
    Scaleform::GFx::AS2::FnCall::ThisPtrError(fn, "XML", 0, 0);
  }
}
