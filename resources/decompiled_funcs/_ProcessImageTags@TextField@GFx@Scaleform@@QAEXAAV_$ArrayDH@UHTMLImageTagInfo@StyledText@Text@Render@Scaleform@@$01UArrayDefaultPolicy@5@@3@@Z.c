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
  Scaleform::Render::ImageBase *pImage; // esi
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
  Scaleform::Ptr<Scaleform::Render::Image> *p_pImage; // edi
  unsigned int v28; // eax
  unsigned int v29; // ecx
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
  char *v42; // [esp+0h] [ebp-98h]
  bool userImageProtocol; // [esp+17h] [ebp-81h]
  bool userImageProtocola; // [esp+17h] [ebp-81h]
  float origHeight; // [esp+18h] [ebp-80h]
  float origHeighta; // [esp+18h] [ebp-80h]
  float origHeightb; // [esp+18h] [ebp-80h]
  float origHeightc; // [esp+18h] [ebp-80h]
  float origHeightd; // [esp+18h] [ebp-80h]
  float origHeighte; // [esp+18h] [ebp-80h]
  Scaleform::GFx::MovieImpl *screenHeight; // [esp+20h] [ebp-78h]
  float screenHeighta; // [esp+20h] [ebp-78h]
  unsigned int *screenWidth; // [esp+24h] [ebp-74h]
  float screenWidtha; // [esp+24h] [ebp-74h]
  Scaleform::GFx::MovieDefImpl *v56; // [esp+28h] [ebp-70h]
  Scaleform::Ptr<Scaleform::GFx::ImageResource> pimgRes; // [esp+2Ch] [ebp-6Ch] BYREF
  float origWidth; // [esp+30h] [ebp-68h]
  Scaleform::GFx::ResourceBindData resBindData; // [esp+34h] [ebp-64h] BYREF
  unsigned int v60; // [esp+3Ch] [ebp-5Ch]
  unsigned int v61; // [esp+40h] [ebp-58h]
  Scaleform::Ptr<Scaleform::Log> result; // [esp+44h] [ebp-54h] BYREF
  _DWORD v63[4]; // [esp+48h] [ebp-50h] BYREF
  Scaleform::Log *v64; // [esp+58h] [ebp-40h]
  Scaleform::RefCountVImpl *v65; // [esp+5Ch] [ebp-3Ch]
  Scaleform::RefCountVImpl *v66; // [esp+60h] [ebp-38h]
  Scaleform::GFx::MovieImpl *pMovieImpl; // [esp+64h] [ebp-34h]
  Scaleform::Render::Rect<unsigned long> dimr; // [esp+68h] [ebp-30h] BYREF
  Scaleform::GFx::ImageCreateInfo cinfo; // [esp+78h] [ebp-20h] BYREF

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
      resBindData.pResource.pObject = 0;
      resBindData.pBinding = 0;
      v7 = GetResourceMovieDef(v3);
      v8 = (Scaleform::GFx::MovieDefImpl *)v7;
      v56 = (Scaleform::GFx::MovieDefImpl *)v7;
      if ( !v7 )
        goto LABEL_55;
      Scaleform::RefCountImpl::AddRef(v7);
      screenWidth = (unsigned int *)&v6->Url;
      IsProtocolImage = Scaleform::GFx::LoaderImpl::IsProtocolImage(&v6->Url, 0, 0);
      userImageProtocol = IsProtocolImage;
      if ( IsProtocolImage )
        goto LABEL_13;
      if ( !Scaleform::GFx::MovieImpl::FindExportedResource(this->pASRoot->pMovieImpl, v8, &resBindData, &v6->Url) )
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
      if ( (resBindData.pResource.pObject->GetResourceTypeCode(resBindData.pResource.pObject) & 0xFF00) == 0x100 )
        break;
      resBindData.pResource.pObject->GetResourceTypeCode(resBindData.pResource.pObject);
LABEL_54:
      Scaleform::GFx::Resource::Release(v8);
LABEL_55:
      if ( resBindData.pResource.pObject )
        Scaleform::GFx::Resource::Release(resBindData.pResource.pObject);
      v60 += 44;
      if ( !--v61 )
        return;
      v3 = this;
    }
    IsProtocolImage = userImageProtocol;
LABEL_13:
    pImage = 0;
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
          (Scaleform::LogMessageId)135168,
          "Image resource creation failed - ImageCreator not installed");
        v8 = v56;
LABEL_31:
        Scaleform::LogDebugMessage(
          (Scaleform::LogMessageId)135168,
          "Image '%s' wasn't created in ProcessImageTags",
          (const char *)((*screenWidth & 0xFFFFFFFC) + 8));
        goto LABEL_54;
      }
      Scaleform::RefCountImpl::Release(v25);
      v8 = v56;
      pImage = (Scaleform::Render::ImageBase *)((int (__thiscall *)(Scaleform::RefCountVImpl *, _DWORD *, unsigned int *))v26->AddRef)(
                                                 v26,
                                                 v63,
                                                 screenWidth);
    }
    else
    {
      v42 = (char *)((*screenWidth & 0xFFFFFFFC) + 8);
      screenHeight = this->pASRoot->pMovieImpl;
      v12 = (Scaleform::RefCountVImpl *)this->GetResourceMovieDef(this);
      Scaleform::GFx::MovieImpl::GetImageResourceByLinkageId(screenHeight, &pimgRes, v12, v42);
      if ( !pimgRes.pObject )
      {
        if ( this->GetLog(this) )
        {
          v13 = (Scaleform::Log *)((int (__thiscall *)(Scaleform::GFx::TextField *, const char *, unsigned int))this->GetLog)(
                                    this,
                                    "ProcessImageTags: can't load the image '%s'\n",
                                    (*screenWidth & 0xFFFFFFFC) + 8);
          Scaleform::Log::LogWarning(v13, v41);
        }
        if ( pimgRes.pObject )
          Scaleform::GFx::Resource::Release(pimgRes.pObject);
        goto LABEL_54;
      }
      if ( pimgRes.pObject->pImage->GetImageType(pimgRes.pObject->pImage) )
      {
        pImage = pimgRes.pObject->pImage;
        if ( pImage )
          pImage->AddRef(pimgRes.pObject->pImage);
      }
      else
      {
        v14 = v8->GetStateAddRef;
        v15 = &v8->Scaleform::GFx::StateBag;
        v16 = (Scaleform::RefCountVImpl *)v14(v15, State_ImageCreator);
        userImageProtocola = v16 == 0;
        if ( v16 )
          Scaleform::RefCountImpl::Release(v16);
        if ( userImageProtocola )
        {
          Scaleform::LogDebugMessage((Scaleform::LogMessageId)135168, "ImageCreator is null in ProcessImageTags");
        }
        else
        {
          cinfo.pHeap = Scaleform::Memory::pGlobalHeap->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
          cinfo.Use = 1;
          cinfo.RUse = Use_Bitmap;
          v17 = v15->GetStateAddRef;
          cinfo.Type = Create_SourceImage;
          memset(&cinfo.pLog, 0, 16);
          v18 = (Scaleform::RefCountVImpl *)v17(v15, State_ImageCreator);
          pImage = (Scaleform::Render::ImageBase *)((int (__thiscall *)(Scaleform::RefCountVImpl *, Scaleform::GFx::ImageCreateInfo *, Scaleform::Render::ImageBase *))v18->__vftable[1].AddRef)(
                                                     v18,
                                                     &cinfo,
                                                     pimgRes.pObject->pImage);
          Scaleform::RefCountImpl::Release(v18);
        }
        v8 = v56;
      }
      if ( pimgRes.pObject )
        Scaleform::GFx::Resource::Release(pimgRes.pObject);
    }
    if ( pImage )
    {
      pImage->GetRect(pImage, &dimr);
      p_pImage = &v6->pTextImageDesc.pObject->pImage;
      pImage->AddRef(pImage);
      if ( p_pImage->pObject )
        p_pImage->pObject->Release(p_pImage->pObject);
      p_pImage->pObject = (Scaleform::Render::Image *)pImage;
      v28 = dimr.x2 - dimr.x1;
      origWidth = (float)(dimr.x2 - dimr.x1);
      v29 = dimr.y2 - dimr.y1;
      Width = v6->Width;
      origHeight = (float)(dimr.y2 - dimr.y1);
      if ( Width )
      {
        v31 = (double)Width;
        v32 = Width < 0;
      }
      else
      {
        v31 = (double)(int)(20 * v28);
        v32 = ((20 * v28) & 0x80000000) != 0;
      }
      if ( v32 )
        v31 = v31 + 4294967300.0;
      Height = v6->Height;
      screenWidtha = v31;
      if ( Height )
      {
        v34 = (double)Height;
        v35 = Height < 0;
      }
      else
      {
        v34 = (double)(int)(20 * v29);
        v35 = ((20 * v29) & 0x80000000) != 0;
      }
      if ( v35 )
        v34 = v34 + 4294967300.0;
      screenHeighta = v34;
      v36 = origHeight;
      origHeighta = 20.0 * origHeight;
      origHeightb = origHeighta + (double)v6->VSpace;
      v6->pTextImageDesc.pObject->ScreenWidth = screenWidtha;
      v6->pTextImageDesc.pObject->ScreenHeight = screenHeighta;
      origHeightc = origHeightb * 0.05000000074505806;
      v6->pTextImageDesc.pObject->BaseLineY = origHeightc;
      v37 = v6->pTextImageDesc.pObject;
      origHeightd = -v6->pTextImageDesc.pObject->BaseLineY;
      v37->Matrix.M[0][3] = v37->Matrix.M[0][3] + 0.0;
      v37->Matrix.M[1][3] = v37->Matrix.M[1][3] + origHeightd;
      p_Matrix = (float *)&v6->pTextImageDesc.pObject->Matrix;
      origHeighte = screenHeighta / v36;
      origWidth = screenWidtha / origWidth;
      v39 = origWidth;
      *p_Matrix = origWidth * *p_Matrix;
      p_Matrix[1] = p_Matrix[1] * v39;
      p_Matrix[2] = v39 * p_Matrix[2];
      p_Matrix[3] = v39 * p_Matrix[3];
      p_Matrix[4] = origHeighte * p_Matrix[4];
      p_Matrix[5] = origHeighte * p_Matrix[5];
      p_Matrix[6] = p_Matrix[6] * origHeighte;
      p_Matrix[7] = origHeighte * p_Matrix[7];
      this->pDocument.pObject->RTFlags |= 2u;
      pImage->Release(pImage);
      v8 = v56;
      goto LABEL_54;
    }
    goto LABEL_31;
  }
}
