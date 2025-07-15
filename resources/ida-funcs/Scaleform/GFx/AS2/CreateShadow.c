Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> *__cdecl Scaleform::GFx::AS2::CreateShadow(
        Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> *result,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::XML::ElementNode *preal,
        Scaleform::GFx::XML::RootNode *proot)
{
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // ebx
  Scaleform::GFx::AS2::Object *v5; // eax
  Scaleform::GFx::AS2::Object *v6; // edi
  Scaleform::GFx::AS2::Object *Prototype; // eax
  Scaleform::GFx::AS2::XmlNodeObject *pObject; // esi
  Scaleform::RefCountNTSImpl *v9; // ecx
  Scaleform::GFx::AS2::XmlNodeObject *v11; // edi
  Scaleform::GFx::XML::RootNode *RootNode; // eax
  Scaleform::RefCountNTSImpl *v13; // ecx
  Scaleform::GFx::XML::RootNode *v14; // esi

  p_StringContext = &penv->StringContext;
  v5 = (Scaleform::GFx::AS2::Object *)penv->StringContext.pContext->pHeap->Alloc(
                                        penv->StringContext.pContext->pHeap,
                                        60,
                                        0);
  v6 = v5;
  if ( v5 )
  {
    Scaleform::GFx::AS2::Object::Object(v5, penv);
    v6->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::Object_vtbl *)&Scaleform::GFx::AS2::XmlObject::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
    v6->Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::XmlNodeObject::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
    v6[1].Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = 0;
    v6[1].pRCC = 0;
    Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(p_StringContext->pContext, ASBuiltin_XMLNode);
    Scaleform::GFx::AS2::Object::Set__proto__(
      (Scaleform::GFx::AS2::Object *)&v6->Scaleform::GFx::AS2::ObjectInterface,
      p_StringContext,
      Prototype);
  }
  else
  {
    v6 = 0;
  }
  result->pObject = (Scaleform::GFx::AS2::XmlNodeObject *)v6;
  Scaleform::GFx::AS2::SetupShadow(preal, penv, (Scaleform::GFx::ASUserData *)v6);
  if ( proot )
  {
    pObject = result->pObject;
    ++proot->RefCount;
    v9 = pObject->pRootNode.pObject;
    if ( v9 )
      Scaleform::RefCountNTSImpl::Release(v9);
    pObject->pRootNode.pObject = proot;
    return result;
  }
  else
  {
    v11 = result->pObject;
    RootNode = Scaleform::GFx::XML::ObjectManager::CreateRootNode(preal->MemoryManager.pObject, preal);
    v13 = v11->pRootNode.pObject;
    v14 = RootNode;
    if ( v13 )
      Scaleform::RefCountNTSImpl::Release(v13);
    v11->pRootNode.pObject = v14;
    return result;
  }
}
