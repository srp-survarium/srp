void __cdecl Scaleform::GFx::AS2::Xml_CreateIDMap(
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::XML::ElementNode *elemNode,
        Scaleform::GFx::XML::RootNode *proot,
        Scaleform::GFx::AS2::Object *pobj)
{
  Scaleform::GFx::XML::ElementNode *pObject; // ebp
  Scaleform::GFx::XML::RootNode *v5; // edi
  Scaleform::GFx::XML::Attribute *FirstAttribute; // esi
  Scaleform::GFx::XML::ShadowRefBase *pShadow; // eax
  Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> *v8; // eax
  Scaleform::GFx::AS2::Object *v9; // edi
  unsigned int RefCount; // edx
  Scaleform::GFx::AS2::XmlNodeObject *v11; // ecx
  Scaleform::GFx::AS2::Object *v12; // eax
  Scaleform::GFx::AS2::Object *v13; // esi
  Scaleform::GFx::AS2::Object *Prototype; // eax
  Scaleform::GFx::XML::ShadowRefBase *v15; // eax
  bool v16; // zf
  Scaleform::GFx::AS2::GlobalContext *pContext; // ecx
  Scaleform::GFx::AS2::StringManager *StringManager; // eax
  Scaleform::GFx::ASStringNode *StringNode; // eax
  Scaleform::GFx::AS2::Object *v20; // esi
  Scaleform::GFx::AS2::ObjectInterface_vtbl *v21; // ebp
  const Scaleform::GFx::AS2::Value *v22; // eax
  Scaleform::GFx::ASStringNode *v23; // eax
  unsigned int v24; // eax
  void *v25; // esi
  Scaleform::GFx::XML::ElementNode *v26; // [esp+24h] [ebp-20h]
  Scaleform::GFx::ASStringNode *v27; // [esp+28h] [ebp-1Ch] BYREF
  Scaleform::String v28; // [esp+2Ch] [ebp-18h] BYREF
  Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> result; // [esp+30h] [ebp-14h] BYREF
  Scaleform::GFx::AS2::Value v30; // [esp+34h] [ebp-10h] BYREF

  pObject = (Scaleform::GFx::XML::ElementNode *)elemNode->FirstChild.pObject;
  v26 = pObject;
  if ( pObject )
  {
    while ( 1 )
    {
      if ( pObject->Type == 1 )
      {
        v5 = proot;
        Scaleform::GFx::AS2::Xml_CreateIDMap(penv, pObject, proot, pobj);
        FirstAttribute = pObject->FirstAttribute;
        if ( FirstAttribute )
        {
          while ( strncmp(FirstAttribute->Name.pNode->pData, "id", 2u) )
          {
            FirstAttribute = FirstAttribute->Next;
            if ( !FirstAttribute )
              goto LABEL_35;
          }
          Scaleform::String::String(
            &v28,
            (const __m128i *)FirstAttribute->Value.pNode->pData,
            FirstAttribute->Value.pNode->Size);
          pShadow = pObject->pShadow;
          if ( pShadow )
          {
            v9 = (Scaleform::GFx::AS2::Object *)pShadow[1].__vftable;
            if ( v9 )
            {
              v9->RefCount = (v9->RefCount + 1) & 0x8FFFFFFF;
            }
            else
            {
              v12 = (Scaleform::GFx::AS2::Object *)penv->StringContext.pContext->pHeap->Alloc(
                                                     penv->StringContext.pContext->pHeap,
                                                     60,
                                                     0);
              v13 = v12;
              if ( v12 )
              {
                Scaleform::GFx::AS2::Object::Object(v12, penv);
                v13->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::Object_vtbl *)&Scaleform::GFx::AS2::XmlObject::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
                v13->Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::XmlNodeObject::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
                v13[1].Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = 0;
                v13[1].pRCC = 0;
                Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(
                              penv->StringContext.pContext,
                              ASBuiltin_XMLNode);
                Scaleform::GFx::AS2::Object::Set__proto__(
                  (Scaleform::GFx::AS2::Object *)&v13->Scaleform::GFx::AS2::ObjectInterface,
                  &penv->StringContext,
                  Prototype);
                pObject = v26;
              }
              else
              {
                v13 = 0;
              }
              v9 = v13;
              if ( !pObject->pShadow )
              {
                v15 = (Scaleform::GFx::XML::ShadowRefBase *)pObject->MemoryManager.pObject->pHeap->Alloc(
                                                              pObject->MemoryManager.pObject->pHeap,
                                                              12u,
                                                              0);
                if ( v15 )
                {
                  v15->__vftable = (Scaleform::GFx::XML::ShadowRefBase_vtbl *)&Scaleform::GFx::AS2::XMLShadowRef::`vftable';
                  v15[1].__vftable = 0;
                  v15[2].__vftable = 0;
                }
                else
                {
                  v15 = 0;
                }
                v16 = pObject->Type == 1;
                pObject->pShadow = v15;
                if ( v16 )
                  Scaleform::GFx::AS2::SetupAttributes(penv, pObject);
              }
              pObject->pShadow[1].__vftable = (Scaleform::GFx::XML::ShadowRefBase_vtbl *)v13;
              v13[1].pRCC = (Scaleform::GFx::AS2::RefCountCollector<323> *)pObject;
            }
          }
          else
          {
            v8 = Scaleform::GFx::AS2::CreateShadow(&result, penv, pObject, v5);
            if ( v8->pObject )
              v8->pObject->RefCount = (v8->pObject->RefCount + 1) & 0x8FFFFFFF;
            v9 = v8->pObject;
            if ( result.pObject )
            {
              RefCount = result.pObject->RefCount;
              v11 = result.pObject;
              if ( (RefCount & 0x3FFFFFF) != 0 )
              {
                result.pObject->RefCount = RefCount - 1;
                Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v11);
              }
            }
          }
          pContext = penv->StringContext.pContext;
          LOBYTE(elemNode) = 0;
          StringManager = Scaleform::GFx::AS2::GlobalContext::GetStringManager(pContext);
          StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                         StringManager->pStringManager,
                         (__m128i *)((v28.HeapTypeBits & 0xFFFFFFFC) + 8),
                         *(_DWORD *)(v28.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
          v20 = pobj;
          v27 = StringNode;
          ++StringNode->RefCount;
          v21 = v20->Scaleform::GFx::AS2::ObjectInterface::__vftable;
          Scaleform::GFx::AS2::Value::Value(&v30, v9);
          v21->SetMember(
            &v20->Scaleform::GFx::AS2::ObjectInterface,
            penv,
            (const Scaleform::GFx::ASString *)&v27,
            v22,
            (const Scaleform::GFx::AS2::PropFlags *)&elemNode);
          v23 = v27;
          --v27->RefCount;
          if ( !v23->RefCount )
            Scaleform::GFx::ASStringNode::ReleaseNode(v23);
          Scaleform::GFx::AS2::Value::~Value(&v30);
          if ( v9 )
          {
            v24 = v9->RefCount;
            if ( (v24 & 0x3FFFFFF) != 0 )
            {
              v9->RefCount = v24 - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v9);
            }
          }
          v25 = (void *)(v28.HeapTypeBits & 0xFFFFFFFC);
          if ( InterlockedExchangeAdd((volatile LONG *)((v28.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
            Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v25);
          pObject = v26;
        }
      }
LABEL_35:
      v26 = (Scaleform::GFx::XML::ElementNode *)pObject->NextSibling.pObject;
      if ( !v26 )
        break;
      pObject = (Scaleform::GFx::XML::ElementNode *)pObject->NextSibling.pObject;
    }
  }
}
