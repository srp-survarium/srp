bool __thiscall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::CreateLibraryObject(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this,
        Scaleform::GFx::ImageResource *imgRes,
        Scaleform::RefCountVImpl *defImpl)
{
  Scaleform::GFx::ImageResource *v3; // edi
  Scaleform::GFx::ImageResource *v5; // ecx
  Scaleform::Render::ImageBase *v6; // edi
  Scaleform::Render::ImageBase *v7; // ecx
  Scaleform::GFx::MovieDefImpl *v8; // edi
  Scaleform::GFx::MovieDefImpl *v9; // ecx
  Scaleform::GFx::AS3::ASVM *pVM; // ebp
  Scaleform::GFx::MovieDefImpl *ResourceMovieDef; // edi
  Scaleform::GFx::AS3::Traits *pObject; // ecx
  bool v14; // bl
  void *v15; // edi
  Scaleform::GFx::AS3::MovieRoot *pMovieRoot; // ebp
  Scaleform::Log *v17; // esi
  Scaleform::GFx::ImageResource_vtbl *v18; // esi
  Scaleform::Log *v19; // edi
  Scaleform::GFx::ImageResource *v20; // edi
  Scaleform::GFx::ImageResource *v21; // ecx
  Scaleform::Render::ImageBase *pImage; // edi
  Scaleform::Render::ImageBase *v23; // ecx
  Scaleform::GFx::ResourceBinding *pBinding; // eax
  Scaleform::GFx::MovieDefImpl *pOwnerDefImpl; // edi
  Scaleform::GFx::MovieDefImpl *v26; // ecx
  Scaleform::GFx::ASStringNode *v27; // eax
  Scaleform::GFx::MovieDefImpl *pdefImpl; // [esp+10h] [ebp-Ch]
  Scaleform::GFx::ResourceBindData resBindData; // [esp+14h] [ebp-8h] BYREF

  v3 = imgRes;
  if ( !imgRes )
  {
    pVM = (Scaleform::GFx::AS3::ASVM *)this->pTraits.pObject->pVM;
    ResourceMovieDef = Scaleform::GFx::AS3::ASVM::GetResourceMovieDef(pVM, this);
    pdefImpl = ResourceMovieDef;
    if ( !ResourceMovieDef )
      return 0;
    pObject = this->pTraits.pObject;
    if ( (pObject->Flags & 0x10) == 0 )
      return 0;
    pObject->GetQualifiedName(pObject, (Scaleform::GFx::ASString *)&imgRes, qnfWithDot);
    resBindData.pResource.pObject = 0;
    resBindData.pBinding = 0;
    Scaleform::String::String((Scaleform::String *)&defImpl, (const __m128i *)imgRes->__vftable);
    v14 = Scaleform::GFx::MovieImpl::FindExportedResource(
            pVM->pMovieRoot->pMovieImpl,
            ResourceMovieDef,
            &resBindData,
            (const Scaleform::String *)&defImpl) == 0;
    v15 = (void *)((unsigned int)defImpl & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd((volatile LONG *)(((unsigned int)defImpl & 0xFFFFFFFC) + 4), -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v15);
    if ( v14 )
    {
      pMovieRoot = pVM->pMovieRoot;
      v17 = Scaleform::GFx::StateBag::GetLog(
              &pMovieRoot->pMovieImpl->Scaleform::GFx::StateBag,
              (Scaleform::Ptr<Scaleform::Log> *)&defImpl)->pObject;
      if ( defImpl )
        Scaleform::RefCountImpl::Release(defImpl);
      if ( v17 )
      {
        v18 = imgRes->__vftable;
        v19 = Scaleform::GFx::StateBag::GetLog(
                &pMovieRoot->pMovieImpl->Scaleform::GFx::StateBag,
                (Scaleform::Ptr<Scaleform::Log> *)&defImpl)->pObject;
        if ( defImpl )
          Scaleform::RefCountImpl::Release(defImpl);
        Scaleform::Log::LogWarning(v19, "Attaching a bitmap with class '%s' failed", (const char *)v18);
      }
      goto LABEL_42;
    }
    if ( !resBindData.pResource.pObject )
    {
LABEL_44:
      v27 = (Scaleform::GFx::ASStringNode *)imgRes;
      --imgRes->pImage;
      if ( !v27->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v27);
      return 0;
    }
    if ( (resBindData.pResource.pObject->GetResourceTypeCode(resBindData.pResource.pObject) & 0xFF00) != 0x100 )
    {
LABEL_42:
      if ( resBindData.pResource.pObject )
        Scaleform::GFx::Resource::Release(resBindData.pResource.pObject);
      goto LABEL_44;
    }
    v20 = (Scaleform::GFx::ImageResource *)resBindData.pResource.pObject;
    if ( resBindData.pResource.pObject )
      Scaleform::RefCountImpl::AddRef(resBindData.pResource.pObject);
    v21 = this->pImageResource.pObject;
    if ( v21 )
      Scaleform::GFx::Resource::Release(v21);
    this->pImageResource.pObject = v20;
    pImage = v20->pImage;
    if ( pImage )
      pImage->AddRef(pImage);
    v23 = this->pImage.pObject;
    if ( v23 )
      v23->Release(v23);
    pBinding = resBindData.pBinding;
    this->pImage.pObject = pImage;
    if ( pBinding )
    {
      pOwnerDefImpl = pBinding->pOwnerDefImpl;
      if ( !pOwnerDefImpl )
      {
LABEL_39:
        v26 = this->pDefImpl.pObject;
        if ( v26 )
          Scaleform::GFx::Resource::Release(v26);
        this->pDefImpl.pObject = pOwnerDefImpl;
        goto LABEL_42;
      }
    }
    else
    {
      pOwnerDefImpl = pdefImpl;
    }
    Scaleform::RefCountImpl::AddRef(pOwnerDefImpl);
    goto LABEL_39;
  }
  Scaleform::RefCountImpl::AddRef(imgRes);
  v5 = this->pImageResource.pObject;
  if ( v5 )
    Scaleform::GFx::Resource::Release(v5);
  this->pImageResource.pObject = v3;
  v6 = v3->pImage;
  if ( v6 )
    v6->AddRef(v6);
  v7 = this->pImage.pObject;
  if ( v7 )
    v7->Release(v7);
  this->pImage.pObject = v6;
  v8 = (Scaleform::GFx::MovieDefImpl *)defImpl;
  if ( defImpl )
    Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)defImpl);
  v9 = this->pDefImpl.pObject;
  if ( v9 )
    Scaleform::GFx::Resource::Release(v9);
  this->pDefImpl.pObject = v8;
  return 0;
}
