Scaleform::Ptr<Scaleform::GFx::ImageResource> *__thiscall Scaleform::GFx::MovieImpl::GetImageResourceByLinkageId(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::Ptr<Scaleform::GFx::ImageResource> *result,
        Scaleform::RefCountVImpl *md,
        const __m128i *linkageId)
{
  const __m128i *v4; // edi
  Scaleform::String *v5; // eax
  void *v6; // esi
  Scaleform::GFx::StateBagImpl *pObject; // esi
  Scaleform::GFx::StateBag *v8; // esi
  Scaleform::MemoryHeap *pHeap; // ebx
  Scaleform::GFx::State *(__thiscall *GetStateAddRef)(Scaleform::GFx::StateBag *, Scaleform::GFx::State::StateType); // eax
  Scaleform::RefCountVImpl *v11; // eax
  Scaleform::RefCountVImpl *v12; // edi
  Scaleform::GFx::StateBag_vtbl *v13; // edx
  Scaleform::GFx::State *(__thiscall *v14)(Scaleform::GFx::StateBag *, Scaleform::GFx::State::StateType); // eax
  Scaleform::RefCountVImpl *v15; // ebx
  Scaleform::RefCountVImpl *v16; // ebp
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
  char IsProtocolImage; // [esp+23h] [ebp-35h]
  Scaleform::GFx::ImageResource *v30; // [esp+24h] [ebp-34h]
  Scaleform::String v32; // [esp+2Ch] [ebp-2Ch] BYREF
  Scaleform::GFx::ResourceBindData v33; // [esp+30h] [ebp-28h] BYREF
  _DWORD v34[4]; // [esp+38h] [ebp-20h] BYREF
  Scaleform::Log *v35; // [esp+48h] [ebp-10h]
  Scaleform::RefCountVImpl *v36; // [esp+4Ch] [ebp-Ch]
  Scaleform::RefCountVImpl *v37; // [esp+50h] [ebp-8h]
  Scaleform::GFx::MovieImpl *v38; // [esp+54h] [ebp-4h]

  v30 = 0;
  if ( md )
  {
    v4 = linkageId;
    Scaleform::String::String(&v32, linkageId);
    IsProtocolImage = Scaleform::GFx::LoaderImpl::IsProtocolImage(v5, 0, 0);
    v6 = (void *)(v32.HeapTypeBits & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd((volatile LONG *)((v32.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v6);
    if ( IsProtocolImage )
    {
      pObject = this->pStateBag.pObject;
      if ( pObject )
        v8 = &pObject->Scaleform::GFx::StateBag;
      else
        v8 = 0;
      pHeap = this->pHeap;
      GetStateAddRef = v8->GetStateAddRef;
      v32.pData = (Scaleform::String::DataDesc *)pHeap;
      v11 = (Scaleform::RefCountVImpl *)GetStateAddRef(v8, State_ImageCreator);
      v12 = v11;
      if ( !v11 )
        goto LABEL_34;
      Scaleform::RefCountImpl::Release(v11);
      v13 = v8->__vftable;
      v34[2] = 1;
      v34[3] = 1;
      v14 = v13->GetStateAddRef;
      v34[0] = 0;
      v34[1] = pHeap;
      v35 = 0;
      v36 = 0;
      v37 = 0;
      v38 = 0;
      v15 = (Scaleform::RefCountVImpl *)v14(v8, State_ImageFileHandlerRegistry);
      v16 = (Scaleform::RefCountVImpl *)v8->GetStateAddRef(v8, State_FileOpener);
      v17 = Scaleform::GFx::StateBag::GetLog(v8, (Scaleform::Ptr<Scaleform::Log> *)&md)->pObject;
      v36 = v16;
      v35 = v17;
      v37 = v15;
      if ( md )
        Scaleform::RefCountImpl::Release(md);
      if ( v16 )
        Scaleform::RefCountImpl::Release(v16);
      if ( v15 )
        Scaleform::RefCountImpl::Release(v15);
      v38 = this;
      Scaleform::String::String((Scaleform::String *)&linkageId, linkageId);
      v18 = (Scaleform::Render::Image *)((int (__thiscall *)(Scaleform::RefCountVImpl *, _DWORD *, const __m128i **))v12->AddRef)(
                                          v12,
                                          v34,
                                          &linkageId);
      v19 = (void *)((unsigned int)linkageId & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd((volatile LONG *)(((unsigned int)linkageId & 0xFFFFFFFC) + 4), -1) == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v19);
      if ( !v18 )
        goto LABEL_34;
      v20 = (Scaleform::GFx::ImageResource *)(*(int (__thiscall **)(Scaleform::String::DataDesc *, int, _DWORD))(*(_DWORD *)v32.HeapTypeBits + 40))(
                                               v32.pData,
                                               52,
                                               0);
      if ( v20 )
      {
        Scaleform::GFx::ImageResource::ImageResource(v20, v18, Use_Bitmap);
        v30 = v21;
      }
      else
      {
        v30 = 0;
      }
      v18->Release(v18);
    }
    else
    {
      v33.pResource.pObject = 0;
      v33.pBinding = 0;
      Scaleform::String::String(&v32, v4);
      LOBYTE(linkageId) = Scaleform::GFx::MovieImpl::FindExportedResource(
                            this,
                            (Scaleform::GFx::MovieDefImpl *)md,
                            &v33,
                            &v32) == 0;
      v22 = (void *)(v32.HeapTypeBits & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd((volatile LONG *)((v32.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v22);
      v23 = v33.pResource.pObject;
      if ( (_BYTE)linkageId )
      {
        v24 = result;
        result->pObject = 0;
        goto LABEL_35;
      }
      v25 = v33.pResource.pObject->GetResourceTypeCode(v33.pResource.pObject);
      v26 = v33.pResource.pObject;
      if ( (v25 & 0xFF00) == 0x100 )
      {
        v27 = v33.pResource.pObject;
        if ( v33.pResource.pObject )
        {
          Scaleform::RefCountImpl::AddRef(v33.pResource.pObject);
          v26 = v33.pResource.pObject;
        }
        v30 = (Scaleform::GFx::ImageResource *)v27;
      }
      if ( v26 )
        Scaleform::GFx::Resource::Release(v26);
    }
    if ( v30 )
      Scaleform::RefCountImpl::AddRef(v30);
  }
LABEL_34:
  v24 = result;
  v23 = v30;
  result->pObject = v30;
LABEL_35:
  if ( v23 )
    Scaleform::GFx::Resource::Release(v23);
  return v24;
}
