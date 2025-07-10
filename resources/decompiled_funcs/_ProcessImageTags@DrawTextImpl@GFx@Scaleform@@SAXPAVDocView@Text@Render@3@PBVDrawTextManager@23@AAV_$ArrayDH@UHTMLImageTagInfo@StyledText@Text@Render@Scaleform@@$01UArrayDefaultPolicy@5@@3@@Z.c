void __cdecl Scaleform::GFx::DrawTextImpl::ProcessImageTags(
        Scaleform::Render::Text::DocView *ptextDocView,
        const Scaleform::GFx::DrawTextManager *pmgr,
        Scaleform::ArrayDH<Scaleform::Render::Text::StyledText::HTMLImageTagInfo,2,Scaleform::ArrayDefaultPolicy> *imageInfoArray)
{
  unsigned int Size; // ebp
  Scaleform::GFx::MovieDefImpl *pObject; // eax
  Scaleform::GFx::StateBag *v5; // esi
  Scaleform::RefCountVImpl *v6; // eax
  Scaleform::GFx::Resource *v7; // eax
  Scaleform::GFx::ImageCreator *v8; // edi
  Scaleform::Render::Text::StyledText::HTMLImageTagInfo *v9; // ebp
  unsigned int *p_Url; // edi
  bool IsProtocolImage; // al
  Scaleform::Log *v12; // edi
  Scaleform::Ptr<Scaleform::Log> *Log; // eax
  Scaleform::Log *v14; // ecx
  Scaleform::Log *v15; // ebp
  unsigned int v16; // edi
  Scaleform::Ptr<Scaleform::Log> *v17; // eax
  Scaleform::GFx::Resource *v18; // edi
  Scaleform::Render::Image *v19; // edi
  Scaleform::Log *v20; // edi
  unsigned int v21; // edi
  Scaleform::Ptr<Scaleform::Log> *v22; // eax
  Scaleform::Render::Image *(__thiscall *CreateImage)(Scaleform::GFx::ImageCreator *, const Scaleform::GFx::ImageCreateInfo *, Scaleform::Render::ImageSource *); // edx
  Scaleform::MemoryHeap *v24; // eax
  Scaleform::GFx::StateBag_vtbl *v25; // edx
  Scaleform::GFx::StateBag *(__thiscall *GetStateBagImpl)(Scaleform::GFx::StateBag *); // eax
  int v27; // eax
  int v28; // eax
  Scaleform::RefCountVImpl *v29; // edi
  Scaleform::Log *v30; // eax
  unsigned int v31; // eax
  unsigned int v32; // ecx
  int Width; // edx
  double v34; // st7
  bool v35; // cc
  int Height; // eax
  double v37; // st7
  bool v38; // cc
  double v39; // st7
  Scaleform::Render::Text::ImageDesc *v40; // eax
  float *p_Matrix; // eax
  double v42; // st7
  Scaleform::GFx::Resource_vtbl *v43; // [esp+8h] [ebp-ACh]
  Scaleform::GFx::Resource *screenWidth; // [esp+1Ch] [ebp-98h]
  Scaleform::RefCountVImpl *screenWidtha; // [esp+1Ch] [ebp-98h]
  Scaleform::Ptr<Scaleform::Render::Image> *screenWidthb; // [esp+1Ch] [ebp-98h]
  float screenWidthc; // [esp+1Ch] [ebp-98h]
  float origHeight; // [esp+20h] [ebp-94h]
  float origHeighta; // [esp+20h] [ebp-94h]
  float origHeightb; // [esp+20h] [ebp-94h]
  float origHeightc; // [esp+20h] [ebp-94h]
  float origHeightd; // [esp+20h] [ebp-94h]
  float origHeighte; // [esp+20h] [ebp-94h]
  const Scaleform::String *screenHeight; // [esp+24h] [ebp-90h]
  float screenHeighta; // [esp+24h] [ebp-90h]
  Scaleform::GFx::ResourceBindData resBindData; // [esp+28h] [ebp-8Ch] BYREF
  Scaleform::Ptr<Scaleform::GFx::ImageCreator> pimageCreator; // [esp+30h] [ebp-84h]
  float origWidth; // [esp+34h] [ebp-80h]
  unsigned int v59; // [esp+38h] [ebp-7Ch]
  Scaleform::GFx::MovieDefImpl *pmdImpl; // [esp+3Ch] [ebp-78h]
  unsigned int i; // [esp+40h] [ebp-74h]
  Scaleform::Ptr<Scaleform::Log> v62; // [esp+44h] [ebp-70h] BYREF
  Scaleform::Ptr<Scaleform::Log> v63; // [esp+48h] [ebp-6Ch] BYREF
  unsigned int numTags; // [esp+4Ch] [ebp-68h]
  Scaleform::Ptr<Scaleform::Log> v65; // [esp+50h] [ebp-64h] BYREF
  Scaleform::Ptr<Scaleform::Log> result; // [esp+54h] [ebp-60h] BYREF
  Scaleform::Ptr<Scaleform::Log> v67; // [esp+58h] [ebp-5Ch] BYREF
  Scaleform::Ptr<Scaleform::Log> v68; // [esp+5Ch] [ebp-58h] BYREF
  Scaleform::Ptr<Scaleform::Log> v69; // [esp+60h] [ebp-54h] BYREF
  _DWORD v70[4]; // [esp+64h] [ebp-50h] BYREF
  Scaleform::Log *v71; // [esp+74h] [ebp-40h]
  Scaleform::RefCountVImpl *v72; // [esp+78h] [ebp-3Ch]
  Scaleform::RefCountVImpl *v73; // [esp+7Ch] [ebp-38h]
  int v74; // [esp+80h] [ebp-34h]
  Scaleform::Render::Rect<unsigned long> dimr; // [esp+84h] [ebp-30h] BYREF
  Scaleform::GFx::ImageCreateInfo cinfo; // [esp+94h] [ebp-20h] BYREF

  Size = imageInfoArray->Data.Size;
  pObject = (Scaleform::GFx::MovieDefImpl *)pmgr->pImpl->pMovieDef.pObject;
  numTags = Size;
  pmdImpl = 0;
  pimageCreator.pObject = 0;
  if ( pObject )
    pmdImpl = pObject;
  v5 = &pmgr->Scaleform::GFx::StateBag;
  v6 = (Scaleform::RefCountVImpl *)pmgr->GetStateAddRef(&pmgr->Scaleform::GFx::StateBag, 11);
  if ( v6 )
  {
    Scaleform::RefCountImpl::Release(v6);
    v7 = (Scaleform::GFx::Resource *)v5->GetStateAddRef(v5, State_ImageCreator);
    v8 = (Scaleform::GFx::ImageCreator *)v7;
    if ( v7 )
      Scaleform::RefCountImpl::AddRef(v7);
    pimageCreator.pObject = v8;
    if ( v8 )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v8);
  }
  i = 0;
  if ( !Size )
  {
LABEL_62:
    if ( pimageCreator.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)pimageCreator.pObject);
    return;
  }
  v59 = 0;
  while ( 1 )
  {
    v9 = &imageInfoArray->Data.Data[v59 / 0x2C];
    p_Url = (unsigned int *)&v9->Url;
    screenHeight = &v9->Url;
    IsProtocolImage = Scaleform::GFx::LoaderImpl::IsProtocolImage(&v9->Url, 0, 0);
    resBindData.pResource.pObject = 0;
    resBindData.pBinding = 0;
    if ( IsProtocolImage )
      break;
    if ( !pmdImpl )
    {
      v12 = Scaleform::GFx::StateBag::GetLog(v5, &result)->pObject;
      if ( result.pObject )
        Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)result.pObject);
      if ( !v12 )
        goto LABEL_59;
      Log = Scaleform::GFx::StateBag::GetLog(v5, &v67);
      Scaleform::Log::LogWarning(
        Log->pObject,
        "DrawText::ProcessImageTags: can't find a resource since there is no moviedef\n");
      v14 = v67.pObject;
      if ( !v67.pObject )
        goto LABEL_59;
      goto LABEL_32;
    }
    if ( !Scaleform::GFx::MovieDefImpl::GetExportedResource(pmdImpl, &resBindData, &v9->Url, 0) )
    {
      v15 = Scaleform::GFx::StateBag::GetLog(v5, &v63)->pObject;
      if ( v63.pObject )
        Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v63.pObject);
      if ( !v15 )
        goto LABEL_59;
      v16 = *p_Url & 0xFFFFFFFC;
      v17 = Scaleform::GFx::StateBag::GetLog(v5, &v62);
      Scaleform::Log::LogWarning(
        v17->pObject,
        "DrawText::ProcessImageTags: can't find a resource for export name '%s'\n",
        (const char *)(v16 + 8));
      v14 = v62.pObject;
      if ( !v62.pObject )
        goto LABEL_59;
      goto LABEL_32;
    }
    if ( (resBindData.pResource.pObject->GetResourceTypeCode(resBindData.pResource.pObject) & 0xFF00) == 0x100 )
    {
      v18 = resBindData.pResource.pObject;
      screenWidth = resBindData.pResource.pObject;
      if ( resBindData.pResource.pObject )
      {
        Scaleform::RefCountImpl::AddRef(resBindData.pResource.pObject);
        if ( (*((int (__thiscall **)(Scaleform::GFx::Resource_vtbl *))v18[1].~Scaleform::GFx::Resource + 3))(v18[1].__vftable) )
        {
          v19 = (Scaleform::Render::Image *)v18[1].__vftable;
          if ( v19 )
          {
            v19->AddRef(v19);
            Scaleform::GFx::Resource::Release(screenWidth);
            goto LABEL_44;
          }
        }
        else
        {
          if ( !pimageCreator.pObject )
          {
            Scaleform::LogDebugMessage(
              (Scaleform::LogMessageId)135168,
              "ImageCreator is null in DrawText::ProcessImageTags");
            Scaleform::GFx::Resource::Release(v18);
            goto LABEL_65;
          }
          CreateImage = pimageCreator.pObject->CreateImage;
          cinfo.pHeap = pmgr->pHeap;
          cinfo.Use = 1;
          cinfo.RUse = Use_Bitmap;
          v43 = v18[1].__vftable;
          cinfo.Type = Create_SourceImage;
          memset(&cinfo.pLog, 0, 16);
          v19 = CreateImage(pimageCreator.pObject, &cinfo, (Scaleform::Render::ImageSource *)v43);
        }
        Scaleform::GFx::Resource::Release(screenWidth);
LABEL_44:
        if ( v19 )
        {
          v19->GetRect(v19, &dimr);
          screenWidthb = &v9->pTextImageDesc.pObject->pImage;
          v19->AddRef(v19);
          if ( screenWidthb->pObject )
            screenWidthb->pObject->Release(screenWidthb->pObject);
          screenWidthb->pObject = v19;
          v31 = dimr.x2 - dimr.x1;
          origWidth = (float)(dimr.x2 - dimr.x1);
          v32 = dimr.y2 - dimr.y1;
          Width = v9->Width;
          origHeight = (float)(dimr.y2 - dimr.y1);
          if ( Width )
          {
            v34 = (double)Width;
            v35 = Width < 0;
          }
          else
          {
            v34 = (double)(int)(20 * v31);
            v35 = ((20 * v31) & 0x80000000) != 0;
          }
          if ( v35 )
            v34 = v34 + 4294967300.0;
          Height = v9->Height;
          screenWidthc = v34;
          if ( Height )
          {
            v37 = (double)Height;
            v38 = Height < 0;
          }
          else
          {
            v37 = (double)(int)(20 * v32);
            v38 = ((20 * v32) & 0x80000000) != 0;
          }
          if ( v38 )
            v37 = v37 + 4294967300.0;
          screenHeighta = v37;
          v39 = origHeight;
          origHeighta = 20.0 * origHeight;
          origHeightb = origHeighta + (double)v9->VSpace;
          v9->pTextImageDesc.pObject->ScreenWidth = screenWidthc;
          v9->pTextImageDesc.pObject->ScreenHeight = screenHeighta;
          origHeightc = origHeightb * 0.05000000074505806;
          v9->pTextImageDesc.pObject->BaseLineY = origHeightc;
          v40 = v9->pTextImageDesc.pObject;
          origHeightd = -v9->pTextImageDesc.pObject->BaseLineY;
          v40->Matrix.M[0][3] = v40->Matrix.M[0][3] + 0.0;
          v40->Matrix.M[1][3] = origHeightd + v40->Matrix.M[1][3];
          p_Matrix = (float *)&v9->pTextImageDesc.pObject->Matrix;
          origHeighte = screenHeighta / v39;
          origWidth = screenWidthc / origWidth;
          v42 = origWidth;
          *p_Matrix = *p_Matrix * origWidth;
          p_Matrix[1] = v42 * p_Matrix[1];
          p_Matrix[2] = p_Matrix[2] * v42;
          p_Matrix[3] = v42 * p_Matrix[3];
          p_Matrix[4] = p_Matrix[4] * origHeighte;
          p_Matrix[5] = p_Matrix[5] * origHeighte;
          p_Matrix[6] = origHeighte * p_Matrix[6];
          p_Matrix[7] = origHeighte * p_Matrix[7];
          ptextDocView->RTFlags |= 2u;
          v19->Release(v19);
        }
        else
        {
          Scaleform::LogDebugMessage(
            (Scaleform::LogMessageId)135168,
            "Image '%s' wasn't created in ProcessImageTags",
            (const char *)((screenHeight->HeapTypeBits & 0xFFFFFFFC) + 8));
        }
        goto LABEL_59;
      }
      v20 = Scaleform::GFx::StateBag::GetLog(v5, &v68)->pObject;
      if ( v68.pObject )
        Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v68.pObject);
      if ( !v20 )
        goto LABEL_59;
      v21 = screenHeight->HeapTypeBits & 0xFFFFFFFC;
      v22 = Scaleform::GFx::StateBag::GetLog(v5, &v65);
      Scaleform::Log::LogWarning(
        v22->pObject,
        "DrawText::ProcessImageTags: can't load the image '%s'\n",
        (const char *)(v21 + 8));
      v14 = v65.pObject;
      if ( !v65.pObject )
        goto LABEL_59;
LABEL_32:
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v14);
    }
LABEL_59:
    if ( resBindData.pResource.pObject )
      Scaleform::GFx::Resource::Release(resBindData.pResource.pObject);
    v59 += 44;
    if ( ++i >= numTags )
      goto LABEL_62;
  }
  v24 = pmgr->pImpl->pWeakLib.pObject->pImageHeap.pObject;
  v25 = v5->__vftable;
  v70[0] = 1;
  v70[1] = v24;
  GetStateBagImpl = v25->GetStateBagImpl;
  v70[3] = 1;
  v70[2] = 0;
  v71 = 0;
  v72 = 0;
  v73 = 0;
  v74 = 0;
  v27 = (int)GetStateBagImpl(v5);
  screenWidtha = (Scaleform::RefCountVImpl *)(*(int (__thiscall **)(int, int))(*(_DWORD *)v27 + 12))(v27, 12);
  v28 = v5->GetStateBagImpl(v5);
  v29 = (Scaleform::RefCountVImpl *)(*(int (__thiscall **)(int, int))(*(_DWORD *)v28 + 12))(v28, 9);
  v30 = Scaleform::GFx::StateBag::GetLog(v5, &v69)->pObject;
  v72 = v29;
  v71 = v30;
  v73 = screenWidtha;
  if ( v69.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v69.pObject);
  if ( v29 )
    Scaleform::RefCountImpl::Release(v29);
  if ( screenWidtha )
    Scaleform::RefCountImpl::Release(screenWidtha);
  if ( pimageCreator.pObject )
  {
    v19 = pimageCreator.pObject->LoadProtocolImage(pimageCreator.pObject, v70, screenHeight);
    goto LABEL_44;
  }
  Scaleform::LogDebugMessage(
    (Scaleform::LogMessageId)135168,
    "Image resource creation failed - ImageCreator not installed");
LABEL_65:
  if ( resBindData.pResource.pObject )
    Scaleform::GFx::Resource::Release(resBindData.pResource.pObject);
}
