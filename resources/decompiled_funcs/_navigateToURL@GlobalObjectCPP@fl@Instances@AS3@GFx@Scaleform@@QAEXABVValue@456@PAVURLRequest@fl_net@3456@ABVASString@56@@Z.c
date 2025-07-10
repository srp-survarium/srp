void __thiscall Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP::navigateToURL(
        Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_net::URLRequest *request,
        const Scaleform::GFx::ASString *window)
{
  void (__thiscall *v5)(Scaleform::GFx::AS3::VM *); // eax
  Scaleform::RefCountVImpl *v6; // eax
  _DWORD *v7; // edi
  Scaleform::GFx::AS3::Instances::fl_net::URLRequest *v8; // ecx
  void (__thiscall **v9)(_DWORD *, int); // esi
  int v10; // eax
  void *v11; // esi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::LogState *pObject; // esi
  Scaleform::GFx::ASString url; // [esp+Ch] [ebp-4h] BYREF

  v5 = this->pTraits.pObject->pVM[1].__vftable[1].~Scaleform::GFx::AS3::VM;
  v6 = (Scaleform::RefCountVImpl *)(*(int (__thiscall **)(int, int))(*((_DWORD *)v5 + 2) + 12))((int)v5 + 8, 33);
  v7 = &v6->__vftable;
  if ( v6 )
  {
    Scaleform::RefCountImpl::Release(v6);
    v8 = request;
    url.pNode = &request->pTraits.pObject->pVM->StringManagerRef->pStringManager->EmptyStringNode;
    ++url.pNode->RefCount;
    Scaleform::GFx::AS3::Instances::fl_net::URLRequest::urlGet(v8, &url);
    v9 = (void (__thiscall **)(_DWORD *, int))(*v7 + 4);
    Scaleform::String::String((Scaleform::String *)&request, (char *)url.pNode->pData, url.pNode->Size);
    (*v9)(v7, v10);
    v11 = (void *)((unsigned int)request & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd((volatile LONG *)(((unsigned int)request & 0xFFFFFFFC) + 4), -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v11);
    pNode = url.pNode;
    --url.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  else
  {
    pObject = Scaleform::GFx::StateBag::GetLogState(
                (Scaleform::GFx::StateBag *)this->pTraits.pObject->pVM[1].__vftable[1].~Scaleform::GFx::AS3::VM + 2,
                (Scaleform::Ptr<Scaleform::GFx::LogState> *)&request)->pObject;
    if ( request )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)request);
    if ( pObject )
      Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogWarning(
        &pObject->Scaleform::GFx::LogBase<Scaleform::GFx::LogState>,
        "navigateToURL failed! UrlNavigator state is not installed.");
  }
}
