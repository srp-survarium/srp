void __thiscall Scaleform::GFx::TextField::ProcessImageTags(
        Scaleform::GFx::TextField *this,
        Scaleform::ArrayDH<Scaleform::Render::Text::StyledText::HTMLImageTagInfo,2,Scaleform::ArrayDefaultPolicy> *imageInfoArray)
{
  unsigned int Size; // esi
  Scaleform::GFx::TextField *v3; // edi
  Scaleform::Render::TreeText *RenderNode; // eax
  Scaleform::GFx::MovieDefImpl *(__thiscall *GetResourceMovieDef)(Scaleform::GFx::DisplayObjectBase *); // eax
  Scaleform::Render::Text::StyledText::HTMLImageTagInfo *v6; // ebp
  Scaleform::GFx::Resource *v7; // eax
  Scaleform::GFx::MovieDefImpl *v8; // edi
  char IsProtocolImage; // al
  Scaleform::Log *v10; // eax
  Scaleform::GFx::Resource_vtbl *v11; // esi
  Scaleform::RefCountVImpl *v12; // eax
  Scaleform::Log *v13; // eax
  Scaleform::GFx::State *(__thiscall *v14)(Scaleform::GFx::StateBag *, Scaleform::GFx::State::StateType); // eax
  Scaleform::GFx::StateBag *v15; // edi
  Scaleform::RefCountVImpl *v16; // eax
  Scaleform::GFx::State *(__thiscall *v17)(Scaleform::GFx::StateBag *, Scaleform::GFx::State::StateType); // edx
  Scaleform::RefCountVImpl *v18; // edi
  Scaleform::GFx::StateBag *v19; // esi
  Scaleform::GFx::State *(__thiscall *GetStateAddRef)(Scaleform::GFx::StateBag *, Scaleform::GFx::State::StateType); // edx
  Scaleform::RefCountVImpl *v21; // ebx
  Scaleform::RefCountVImpl *v22; // edi
  Scaleform::Log *pObject; // eax
  Scaleform::GFx::StateBag v24; // edx
  Scaleform::RefCountVImpl *v25; // eax
  Scaleform::RefCountVImpl *v26; // esi
  _DWORD *p_pObject; // edi
  int v28; // eax
  int v29; // ecx
  int Width; // edx
  double v31; // st7
  bool v32; // cc
  int Height; // eax
  double v34; // st7
  bool v35; // cc
  double v36; // st7
  Scaleform::Render::Text::ImageDesc *v37; // eax
  float *p_Matrix; // eax
  double v39; // st7
  const char *v40; // [esp-4h] [ebp-9Ch]
  const char *v41; // [esp-4h] [ebp-9Ch]
  const __m128i *v42; // [esp+0h] [ebp-98h]
  char v43; // [esp+17h] [ebp-81h]
  bool v44; // [esp+17h] [ebp-81h]
  float v45; // [esp+18h] [ebp-80h]
  float v46; // [esp+18h] [ebp-80h]
  float v47; // [esp+18h] [ebp-80h]
  float v48; // [esp+18h] [ebp-80h]
  float v49; // [esp+18h] [ebp-80h]
  float v50; // [esp+18h] [ebp-80h]
  Scaleform::GFx::MovieImpl *v52; // [esp+20h] [ebp-78h]
  float v53; // [esp+20h] [ebp-78h]
  unsigned int *p_Url; // [esp+24h] [ebp-74h]
  float v55; // [esp+24h] [ebp-74h]
  Scaleform::GFx::MovieDefImpl *v56; // [esp+28h] [ebp-70h]
  Scaleform::GFx::Resource *v57; // [esp+2Ch] [ebp-6Ch] BYREF
  float v58; // [esp+30h] [ebp-68h]
  Scaleform::GFx::ResourceBindData v59; // [esp+34h] [ebp-64h] BYREF
  unsigned int v60; // [esp+3Ch] [ebp-5Ch]
  unsigned int v61; // [esp+40h] [ebp-58h]
  Scaleform::Ptr<Scaleform::Log> result; // [esp+44h] [ebp-54h] BYREF
  _DWORD v63[4]; // [esp+48h] [ebp-50h] BYREF
  Scaleform::Log *v64; // [esp+58h] [ebp-40h]
  Scaleform::RefCountVImpl *v65; // [esp+5Ch] [ebp-3Ch]
  Scaleform::RefCountVImpl *v66; // [esp+60h] [ebp-38h]
  Scaleform::GFx::MovieImpl *pMovieImpl; // [esp+64h] [ebp-34h]
  int v68; // [esp+68h] [ebp-30h] BYREF
  int v69; // [esp+6Ch] [ebp-2Ch]
  int v70; // [esp+70h] [ebp-28h]
  int v71; // [esp+74h] [ebp-24h]
  _DWORD v72[8]; // [esp+78h] [ebp-20h] BYREF

  Size = imageInfoArray->Data.Size;
  v3 = this;
  if ( Size )
  {
    RenderNode = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
    Scaleform::Render::TreeText::NotifyLayoutChanged(RenderNode);
    v60 = 0;
    v61 = Size;
    while ( 1 )
    {
      GetResourceMovieDef = v3->GetResourceMovieDef;
      v6 = &imageInfoArray->Data.Data[v60 / 0x2C];
      v59.pResource.pObject = 0;
      v59.pBinding = 0;
      v7 = GetResourceMovieDef(v3);
      v8 = (Scaleform::GFx::MovieDefImpl *)v7;
      v56 = (Scaleform::GFx::MovieDefImpl *)v7;
      if ( !v7 )
        goto LABEL_55;
      Scaleform::RefCountImpl::AddRef(v7);
      p_Url = (unsigned int *)&v6->Url;
      IsProtocolImage = Scaleform::GFx::LoaderImpl::IsProtocolImage(&v6->Url, 0, 0);
      v43 = IsProtocolImage;
      if ( IsProtocolImage )
        goto LABEL_13;
      if ( !Scaleform::GFx::MovieImpl::FindExportedResource(this->pASRoot->pMovieImpl, v8, &v59, &v6->Url) )
      {
        if ( this->GetLog(this) )
        {
          v10 = (Scaleform::Log *)((int (__thiscall *)(Scaleform::GFx::TextField *, const char *, unsigned int))this->GetLog)(
                                    this,
                                    "ProcessImageTags: can't find a resource for export name '%s'\n",
                                    (v6->Url.HeapTypeBits & 0xFFFFFFFC) + 8);
          Scaleform::Log::LogWarning(v10, v40);
        }
        goto LABEL_54;
      }
      if ( (v59.pResource.pObject->GetResourceTypeCode(v59.pResource.pObject) & 0xFF00) == 0x100 )
        break;
      v59.pResource.pObject->GetResourceTypeCode(v59.pResource.pObject);
LABEL_54:
      Scaleform::GFx::Resource::Release(v8);
LABEL_55:
      if ( v59.pResource.pObject )
        Scaleform::GFx::Resource::Release(v59.pResource.pObject);
      v60 += 44;
      if ( !--v61 )
        return;
      v3 = this;
    }
    IsProtocolImage = v43;
LABEL_13:
    v11 = 0;
    if ( IsProtocolImage )
    {
      v19 = &v8->Scaleform::GFx::StateBag;
      v63[1] = v8->pLoaderImpl.pObject->pWeakResourceLib.pObject->pImageHeap.pObject;
      GetStateAddRef = v8->GetStateAddRef;
      v63[0] = 1;
      v63[3] = 1;
      v63[2] = 0;
      v64 = 0;
      v65 = 0;
      v66 = 0;
      pMovieImpl = 0;
      v21 = (Scaleform::RefCountVImpl *)GetStateAddRef(&v8->Scaleform::GFx::StateBag, State_ImageFileHandlerRegistry);
      v22 = (Scaleform::RefCountVImpl *)v8->GetStateAddRef(&v8->Scaleform::GFx::StateBag, State_FileOpener);
      pObject = Scaleform::GFx::StateBag::GetLog(v19, &result)->pObject;
      v65 = v22;
      v64 = pObject;
      v66 = v21;
      if ( result.pObject )
        Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)result.pObject);
      if ( v22 )
        Scaleform::RefCountImpl::Release(v22);
      if ( v21 )
        Scaleform::RefCountImpl::Release(v21);
      v24.__vftable = v19->__vftable;
      pMovieImpl = this->pASRoot->pMovieImpl;
      v25 = (Scaleform::RefCountVImpl *)v24.GetStateAddRef(v19, State_ImageCreator);
      v26 = v25;
      if ( !v25 )
      {
        Scaleform::LogDebugMessage(
          (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)&loc_20FFD + 3),
          "Image resource creation failed - ImageCreator not installed");
        v8 = v56;
LABEL_31:
        Scaleform::LogDebugMessage(
          (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)&loc_20FFD + 3),
          "Image '%s' wasn't created in ProcessImageTags",
          (const char *)((*p_Url & 0xFFFFFFFC) + 8));
        goto LABEL_54;
      }
      Scaleform::RefCountImpl::Release(v25);
      v8 = v56;
      v11 = (Scaleform::GFx::Resource_vtbl *)((int (__thiscall *)(Scaleform::RefCountVImpl *, _DWORD *, unsigned int *))v26->AddRef)(
                                               v26,
                                               v63,
                                               p_Url);
    }
    else
    {
      v42 = (const __m128i *)((*p_Url & 0xFFFFFFFC) + 8);
      v52 = this->pASRoot->pMovieImpl;
      v12 = (Scaleform::RefCountVImpl *)this->GetResourceMovieDef(this);
      Scaleform::GFx::MovieImpl::GetImageResourceByLinkageId(
        v52,
        (Scaleform::Ptr<Scaleform::GFx::ImageResource> *)&v57,
        v12,
        v42);
      if ( !v57 )
      {
        if ( this->GetLog(this) )
        {
          v13 = (Scaleform::Log *)((int (__thiscall *)(Scaleform::GFx::TextField *, const char *, unsigned int))this->GetLog)(
                                    this,
                                    "ProcessImageTags: can't load the image '%s'\n",
                                    (*p_Url & 0xFFFFFFFC) + 8);
          Scaleform::Log::LogWarning(v13, v41);
        }
        if ( v57 )
          Scaleform::GFx::Resource::Release(v57);
        goto LABEL_54;
      }
      if ( (*((int (__thiscall **)(Scaleform::GFx::Resource_vtbl *))v57[1].~Scaleform::GFx::Resource + 3))(v57[1].__vftable) )
      {
        v11 = v57[1].__vftable;
        if ( v11 )
          (*((void (__thiscall **)(Scaleform::GFx::Resource_vtbl *))v11->~Scaleform::GFx::Resource + 1))(v57[1].__vftable);
      }
      else
      {
        v14 = v8->GetStateAddRef;
        v15 = &v8->Scaleform::GFx::StateBag;
        v16 = (Scaleform::RefCountVImpl *)v14(v15, State_ImageCreator);
        v44 = v16 == 0;
        if ( v16 )
          Scaleform::RefCountImpl::Release(v16);
        if ( v44 )
        {
          Scaleform::LogDebugMessage(
            (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)&loc_20FFD + 3),
            "ImageCreator is null in ProcessImageTags");
        }
        else
        {
          v72[1] = Scaleform::Memory::pGlobalHeap->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
          v72[2] = 1;
          v72[3] = 1;
          v17 = v15->GetStateAddRef;
          v72[0] = 3;
          memset(&v72[4], 0, 16);
          v18 = (Scaleform::RefCountVImpl *)v17(v15, State_ImageCreator);
          v11 = (Scaleform::GFx::Resource_vtbl *)((int (__thiscall *)(Scaleform::RefCountVImpl *, _DWORD *, Scaleform::GFx::Resource_vtbl *))v18->__vftable[1].AddRef)(
                                                   v18,
                                                   v72,
                                                   v57[1].__vftable);
          Scaleform::RefCountImpl::Release(v18);
        }
        v8 = v56;
      }
      if ( v57 )
        Scaleform::GFx::Resource::Release(v57);
    }
    if ( v11 )
    {
      (*((void (__thiscall **)(Scaleform::GFx::Resource_vtbl *, int *))v11->~Scaleform::GFx::Resource + 6))(v11, &v68);
      p_pObject = &v6->pTextImageDesc.pObject->pImage.pObject;
      (*((void (__thiscall **)(Scaleform::GFx::Resource_vtbl *))v11->~Scaleform::GFx::Resource + 1))(v11);
      if ( *p_pObject )
        (*(void (__thiscall **)(_DWORD))(*(_DWORD *)*p_pObject + 8))(*p_pObject);
      *p_pObject = v11;
      v28 = v70 - v68;
      v58 = (float)(unsigned int)(v70 - v68);
      v29 = v71 - v69;
      Width = v6->Width;
      v45 = (float)(unsigned int)(v71 - v69);
      if ( Width )
      {
        v31 = (double)Width;
        v32 = Width < 0;
      }
      else
      {
        v31 = (double)(20 * v28);
        v32 = 20 * v28 < 0;
      }
      if ( v32 )
        v31 = v31 + 4294967300.0;
      Height = v6->Height;
      v55 = v31;
      if ( Height )
      {
        v34 = (double)Height;
        v35 = Height < 0;
      }
      else
      {
        v34 = (double)(20 * v29);
        v35 = 20 * v29 < 0;
      }
      if ( v35 )
        v34 = v34 + 4294967300.0;
      v53 = v34;
      v36 = v45;
      v46 = 20.0 * v45;
      v47 = v46 + (double)v6->VSpace;
      v6->pTextImageDesc.pObject->ScreenWidth = v55;
      v6->pTextImageDesc.pObject->ScreenHeight = v53;
      v48 = v47 * 0.05000000074505806;
      v6->pTextImageDesc.pObject->BaseLineY = v48;
      v37 = v6->pTextImageDesc.pObject;
      v49 = -v6->pTextImageDesc.pObject->BaseLineY;
      v37->Matrix.M[0][3] = v37->Matrix.M[0][3] + 0.0;
      v37->Matrix.M[1][3] = v37->Matrix.M[1][3] + v49;
      p_Matrix = (float *)&v6->pTextImageDesc.pObject->Matrix;
      v50 = v53 / v36;
      v58 = v55 / v58;
      v39 = v58;
      *p_Matrix = v58 * *p_Matrix;
      p_Matrix[1] = p_Matrix[1] * v39;
      p_Matrix[2] = v39 * p_Matrix[2];
      p_Matrix[3] = v39 * p_Matrix[3];
      p_Matrix[4] = v50 * p_Matrix[4];
      p_Matrix[5] = v50 * p_Matrix[5];
      p_Matrix[6] = p_Matrix[6] * v50;
      p_Matrix[7] = v50 * p_Matrix[7];
      this->pDocument.pObject->RTFlags |= 2u;
      (*((void (__thiscall **)(Scaleform::GFx::Resource_vtbl *))v11->~Scaleform::GFx::Resource + 2))(v11);
      v8 = v56;
      goto LABEL_54;
    }
    goto LABEL_31;
  }
}
