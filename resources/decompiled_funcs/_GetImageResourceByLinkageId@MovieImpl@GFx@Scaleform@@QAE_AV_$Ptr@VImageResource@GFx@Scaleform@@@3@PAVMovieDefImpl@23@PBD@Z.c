Scaleform::Ptr<Scaleform::GFx::ImageResource> *__thiscall Scaleform::GFx::MovieImpl::GetImageResourceByLinkageId(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::Ptr<Scaleform::GFx::ImageResource> *result,
        Scaleform::RefCountVImpl *md,
        char *linkageId)
{
  char *v4; // edi
  const Scaleform::String *v5; // eax
  void *v6; // esi
  Scaleform::GFx::StateBagImpl *pObject; // esi
  Scaleform::GFx::StateBag *v8; // esi
  Scaleform::MemoryHeap *v9; // ebx
  Scaleform::GFx::State *(__thiscall *GetStateAddRef)(Scaleform::GFx::StateBag *, Scaleform::GFx::State::StateType); // eax
  Scaleform::RefCountVImpl *v11; // eax
  Scaleform::RefCountVImpl *v12; // edi
  Scaleform::GFx::StateBag_vtbl *v13; // edx
  Scaleform::GFx::State *(__thiscall *v14)(Scaleform::GFx::StateBag *, Scaleform::GFx::State::StateType); // eax
  Scaleform::GFx::ImageFileHandlerRegistry *v15; // ebx
  Scaleform::GFx::FileOpener *v16; // ebp
  Scaleform::Log *v17; // eax
  Scaleform::Render::Image *v18; // edi
  void *v19; // esi
  Scaleform::GFx::ImageResource *v20; // eax
  Scaleform::GFx::ImageResource *v21; // eax
  void *v22; // esi
  Scaleform::GFx::Resource *v23; // ecx
  Scaleform::Ptr<Scaleform::GFx::ImageResource> *v24; // esi
  __int16 v25; // ax
  Scaleform::GFx::Resource *v26; // ecx
  Scaleform::GFx::Resource *v27; // esi
  bool userImageProtocol; // [esp+23h] [ebp-35h]
  Scaleform::GFx::ImageResource *pimageRes; // [esp+24h] [ebp-34h]
  Scaleform::MemoryHeap *pheap; // [esp+2Ch] [ebp-2Ch] BYREF
  Scaleform::GFx::ResourceBindData resBindData; // [esp+30h] [ebp-28h] BYREF
  Scaleform::GFx::ImageCreateInfo icinfo; // [esp+38h] [ebp-20h] BYREF

  pimageRes = 0;
  if ( md )
  {
    v4 = linkageId;
    Scaleform::String::String((Scaleform::String *)&pheap, linkageId);
    userImageProtocol = Scaleform::GFx::LoaderImpl::IsProtocolImage(v5, 0, 0);
    v6 = (void *)((unsigned int)pheap & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd((volatile LONG *)(((unsigned int)pheap & 0xFFFFFFFC) + 4), -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v6);
    if ( userImageProtocol )
    {
      pObject = this->pStateBag.pObject;
      if ( pObject )
        v8 = &pObject->Scaleform::GFx::StateBag;
      else
        v8 = 0;
      v9 = this->pHeap;
      GetStateAddRef = v8->GetStateAddRef;
      pheap = v9;
      v11 = (Scaleform::RefCountVImpl *)GetStateAddRef(v8, State_ImageCreator);
      v12 = v11;
      if ( !v11 )
        goto LABEL_34;
      Scaleform::RefCountImpl::Release(v11);
      v13 = v8->__vftable;
      icinfo.Use = 1;
      icinfo.RUse = Use_Bitmap;
      v14 = v13->GetStateAddRef;
      icinfo.Type = Create_Protocol;
      icinfo.pHeap = v9;
      memset(&icinfo.pLog, 0, 16);
      v15 = (Scaleform::GFx::ImageFileHandlerRegistry *)v14(v8, State_ImageFileHandlerRegistry);
      v16 = (Scaleform::GFx::FileOpener *)v8->GetStateAddRef(v8, State_FileOpener);
      v17 = Scaleform::GFx::StateBag::GetLog(v8, (Scaleform::Ptr<Scaleform::Log> *)&md)->pObject;
      icinfo.pFileOpener = v16;
      icinfo.pLog = v17;
      icinfo.pIFHRegistry = v15;
      if ( md )
        Scaleform::RefCountImpl::Release(md);
      if ( v16 )
        Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v16);
      if ( v15 )
        Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v15);
      icinfo.pMovie = this;
      Scaleform::String::String((Scaleform::String *)&linkageId, linkageId);
      v18 = (Scaleform::Render::Image *)((int (__thiscall *)(Scaleform::RefCountVImpl *, Scaleform::GFx::ImageCreateInfo *, char **))v12->AddRef)(
                                          v12,
                                          &icinfo,
                                          &linkageId);
      v19 = (void *)((unsigned int)linkageId & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd((volatile LONG *)(((unsigned int)linkageId & 0xFFFFFFFC) + 4), -1) == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v19);
      if ( !v18 )
        goto LABEL_34;
      v20 = (Scaleform::GFx::ImageResource *)pheap->Alloc(pheap, 52, 0);
      if ( v20 )
      {
        Scaleform::GFx::ImageResource::ImageResource(v20, v18, Use_Bitmap);
        pimageRes = v21;
      }
      else
      {
        pimageRes = 0;
      }
      v18->Release(v18);
    }
    else
    {
      resBindData.pResource.pObject = 0;
      resBindData.pBinding = 0;
      Scaleform::String::String((Scaleform::String *)&pheap, v4);
      LOBYTE(linkageId) = Scaleform::GFx::MovieImpl::FindExportedResource(
                            this,
                            (Scaleform::GFx::MovieDefImpl *)md,
                            &resBindData,
                            (const Scaleform::String *)&pheap) == 0;
      v22 = (void *)((unsigned int)pheap & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd((volatile LONG *)(((unsigned int)pheap & 0xFFFFFFFC) + 4), -1) == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v22);
      v23 = resBindData.pResource.pObject;
      if ( (_BYTE)linkageId )
      {
        v24 = result;
        result->pObject = 0;
        goto LABEL_35;
      }
      v25 = resBindData.pResource.pObject->GetResourceTypeCode(resBindData.pResource.pObject);
      v26 = resBindData.pResource.pObject;
      if ( (v25 & 0xFF00) == 0x100 )
      {
        v27 = resBindData.pResource.pObject;
        if ( resBindData.pResource.pObject )
        {
          Scaleform::RefCountImpl::AddRef(resBindData.pResource.pObject);
          v26 = resBindData.pResource.pObject;
        }
        pimageRes = (Scaleform::GFx::ImageResource *)v27;
      }
      if ( v26 )
        Scaleform::GFx::Resource::Release(v26);
    }
    if ( pimageRes )
      Scaleform::RefCountImpl::AddRef(pimageRes);
  }
LABEL_34:
  v24 = result;
  v23 = pimageRes;
  result->pObject = pimageRes;
LABEL_35:
  if ( v23 )
    Scaleform::GFx::Resource::Release(v23);
  return v24;
}
