char __thiscall Scaleform::Render::DrawableImage::ensureRenderableRT(Scaleform::Render::DrawableImage *this)
{
  Scaleform::Render::Texture *v2; // edi
  Scaleform::Render::DrawableImageContext *pObject; // ebx
  void *RenderThreadID; // ebx
  unsigned int Height; // edx
  Scaleform::Render::ImageBase *v6; // ecx
  float v7; // ebx
  unsigned int v8; // eax
  Scaleform::Render::RenderTarget *v9; // ecx
  unsigned int Width; // ecx
  Scaleform::Render::ImageBase *v12; // ecx
  unsigned int *v13; // eax
  unsigned int v14; // edx
  Scaleform::Render::ImageBase *v15; // ecx
  Scaleform::Render::ImageBase_vtbl *v16; // eax
  int v17; // eax
  int v18; // eax
  Scaleform::Render::ImageBase *v19; // ecx
  Scaleform::Render::TextureManager *v20; // ecx
  Scaleform::Render::ImageFormat v21; // eax
  _DWORD *v22; // ecx
  bool v23; // bl
  Scaleform::Render::RenderTarget *v24; // eax
  unsigned int v25; // edx
  Scaleform::Render::RenderTarget *v26; // eax
  int v27; // edx
  double v28; // st7
  int x2; // ecx
  int v30; // edx
  void (__thiscall **v31)(float, Scaleform::Render::ImageData *, void (__stdcall *)(unsigned __int8 *, const __m128i *, unsigned int, Scaleform::Render::Palette *, void *), _DWORD); // edi
  Scaleform::Render::ImageData *MappedData; // eax
  Scaleform::Render::DrawableImageContext *v33; // [esp+12h] [ebp-D4h]
  Scaleform::Render::Size<float> v34; // [esp+1Ah] [ebp-CCh]
  bool v35; // [esp+29h] [ebp-BDh]
  Scaleform::Render::Size<unsigned long> v36; // [esp+2Ah] [ebp-BCh] BYREF
  Scaleform::Render::TextureManager *pTextureManager; // [esp+32h] [ebp-B4h] BYREF
  _DWORD *v38; // [esp+36h] [ebp-B0h]
  Scaleform::Render::Renderer2D *pRenderer2D; // [esp+3Ah] [ebp-ACh]
  void *v40; // [esp+3Eh] [ebp-A8h]
  float v41; // [esp+42h] [ebp-A4h]
  float v42; // [esp+46h] [ebp-A0h]
  float v43; // [esp+4Ah] [ebp-9Ch]
  float v44; // [esp+4Eh] [ebp-98h] BYREF
  float v45; // [esp+52h] [ebp-94h]
  float v46; // [esp+56h] [ebp-90h] BYREF
  float v47; // [esp+5Ah] [ebp-8Ch]
  float v48; // [esp+5Eh] [ebp-88h]
  float v49; // [esp+62h] [ebp-84h]
  Scaleform::Render::Matrix2x4<float> v50; // [esp+72h] [ebp-74h] BYREF
  Scaleform::Render::Matrix2x4<float> m2; // [esp+92h] [ebp-54h] BYREF
  Scaleform::Render::Matrix2x4<float> m1; // [esp+B2h] [ebp-34h] BYREF
  _BYTE v53[20]; // [esp+D2h] [ebp-14h] BYREF

  v2 = 0;
  if ( this->pRT.pObject )
    return 1;
  pObject = this->pContext.pObject;
  pTextureManager = 0;
  v38 = 0;
  pRenderer2D = 0;
  v40 = 0;
  pObject->pRTCommandQueue->GetRenderInterfaces(
    pObject->pRTCommandQueue,
    (Scaleform::Render::Interfaces *)&pTextureManager);
  if ( pObject->IDefaults.pTextureManager )
    pTextureManager = pObject->IDefaults.pTextureManager;
  if ( pObject->IDefaults.pHAL )
    v38 = &pObject->IDefaults.pHAL->__vftable;
  if ( pObject->IDefaults.pRenderer2D )
    pRenderer2D = pObject->IDefaults.pRenderer2D;
  RenderThreadID = pObject->IDefaults.RenderThreadID;
  if ( RenderThreadID )
    v40 = RenderThreadID;
  Height = this->ISize.Height;
  v36.Width = this->ISize.Width;
  v6 = this->pDelegateImage.pObject;
  v36.Height = Height;
  if ( v6 )
    v6->AddRef(v6);
  v7 = *(float *)&this->pDelegateImage.pObject;
  v43 = v7;
  if ( this->pTexture.Value )
  {
    v8 = (*(int (__thiscall **)(_DWORD *, Scaleform::Render::Texture *volatile, _DWORD))(*v38 + 76))(
           v38,
           this->pTexture.Value,
           0);
    v9 = this->pRT.pObject;
    v36.Width = v8;
    if ( v9 )
      v9->Release(v9);
    Width = v36.Width;
    this->pRT.pObject = (Scaleform::Render::RenderTarget *)v36.Width;
    if ( !Width )
      goto LABEL_16;
  }
  else
  {
    v12 = this->pDelegateImage.pObject;
    if ( v12 )
    {
      v13 = (unsigned int *)v12->GetSize(v12, (Scaleform::Render::Size<unsigned long> *)&v44);
      v14 = v13[1];
      v36.Width = *v13;
      v15 = this->pDelegateImage.pObject;
      v16 = v15->__vftable;
      v36.Height = v14;
      v17 = (int)v16->GetAsImage(v15);
      v18 = (*(int (__thiscall **)(int, Scaleform::Render::TextureManager *))(*(_DWORD *)v17 + 96))(
              v17,
              pTextureManager);
      v19 = this->pDelegateImage.pObject;
      v2 = (Scaleform::Render::Texture *)v18;
      if ( v19 )
        v19->Release(v19);
      v20 = pTextureManager;
      this->pDelegateImage.pObject = 0;
      v33 = this->pContext.pObject;
      v21 = v20->GetDrawableImageFormat(v20);
      Scaleform::Render::DrawableImage::initialize(this, v21, &v36, (Scaleform::GFx::Resource *)v33);
    }
  }
  if ( this->pRT.pObject )
  {
    if ( v2 )
    {
      v22 = v38;
      v23 = (v38[2] & 4) == 0;
      v35 = (v38[2] & 2) == 0;
      if ( (v38[2] & 2) == 0 )
      {
        (*(void (__thiscall **)(_DWORD *))(*v38 + 16))(v38);
        v22 = v38;
      }
      if ( !v23 )
      {
        (*(void (__thiscall **)(_DWORD *))(*v22 + 36))(v22);
        v22 = v38;
      }
      (*(void (__thiscall **)(_DWORD *))(*v22 + 32))(v22);
      v24 = this->pRT.pObject;
      v25 = v24->ViewRect.y2 - v24->ViewRect.y1;
      v36.Width = v24->ViewRect.x2 - v24->ViewRect.x1;
      v41 = (float)v36.Width;
      v36.Width = v25;
      v42 = (float)v25;
      v46 = 0.0;
      v47 = 0.0;
      v48 = v41;
      v49 = v42;
      (*(void (__thiscall **)(_DWORD *, float *, Scaleform::Render::RenderTarget *, int))(*v38 + 88))(v38, &v46, v24, 2);
      m2.M[0][0] = 1.0;
      m2.M[0][1] = 0.0;
      m2.M[0][2] = 0.0;
      m2.M[0][3] = -0.5;
      m2.M[1][3] = -0.5;
      m2.M[1][0] = 0.0;
      m2.M[1][2] = 0.0;
      m2.M[1][1] = 1.0;
      m1.M[0][0] = 2.0;
      m1.M[0][1] = 0.0;
      m1.M[0][2] = 0.0;
      m1.M[0][3] = 0.0;
      m1.M[1][0] = 0.0;
      m1.M[1][1] = -2.0;
      m1.M[1][2] = 0.0;
      m1.M[1][3] = 0.0;
      Scaleform::Render::operator*((Scaleform::Render::Matrix2x4<float> *)v53, &m1, &m2);
      v26 = this->pRT.pObject;
      v50.M[0][0] = 1.0;
      v50.M[0][1] = 0.0;
      v50.M[0][2] = 0.0;
      v50.M[0][3] = 0.0;
      v50.M[1][0] = 0.0;
      v50.M[1][2] = 0.0;
      v50.M[1][3] = 0.0;
      v50.M[1][1] = 1.0;
      v27 = v26->BufferSize.Height;
      v47 = (float)v26->BufferSize.Width;
      v28 = (double)(int)v26->BufferSize.Height;
      if ( v27 < 0 )
        v28 = v28 + 4294967300.0;
      x2 = v26->ViewRect.x2;
      v48 = v28;
      v30 = v26->ViewRect.y2 - v26->ViewRect.y1;
      v38 = (_DWORD *)(x2 - v26->ViewRect.x1);
      v44 = (float)(unsigned int)v38;
      v38 = (_DWORD *)v30;
      v45 = (float)(unsigned int)v30;
      v34.Width = v44 / v47;
      v34.Height = v45 / v48;
      Scaleform::Render::Matrix2x4<float>::AppendScaling(&v50, v34);
      Scaleform::Render::HAL::applyBlendMode(
        (Scaleform::Render::HAL *)LODWORD(v41),
        Blend_OverwriteAll,
        1,
        (Scaleform::String::DataDesc *)1);
      (*(void (__thiscall **)(_DWORD, Scaleform::Render::Texture *, _BYTE *, Scaleform::Render::Matrix2x4<float> *))(*(_DWORD *)LODWORD(v41) + 208))(
        LODWORD(v41),
        v2,
        v53,
        &v50);
      (*(void (__thiscall **)(_DWORD *, int))(*v38 + 92))(v38, 2);
      Scaleform::Render::DrawableImage::updateStagingTargetRT(this, (int)v2);
      (*(void (__thiscall **)(_DWORD *))(*v38 + 36))(v38);
      if ( !v23 )
        (*(void (__thiscall **)(_DWORD *))(*v38 + 32))(v38);
      if ( v35 )
        (*(void (__thiscall **)(_DWORD *))(*v38 + 20))(v38);
      v7 = v43;
LABEL_36:
      if ( v7 != 0.0 )
        (*(void (__thiscall **)(float))(*(_DWORD *)LODWORD(v7) + 8))(COERCE_FLOAT(LODWORD(v7)));
      return 1;
    }
    if ( v7 != 0.0 )
    {
      if ( Scaleform::Render::DrawableImage::mapTextureRT(this, 0, 0) )
      {
        v31 = (void (__thiscall **)(float, Scaleform::Render::ImageData *, void (__stdcall *)(unsigned __int8 *, const __m128i *, unsigned int, Scaleform::Render::Palette *, void *), _DWORD))(*(_DWORD *)LODWORD(v7) + 32);
        MappedData = Scaleform::Render::DrawableImage::getMappedData(this);
        (*v31)(COERCE_FLOAT(LODWORD(v7)), MappedData, Scaleform::Render::ImageBase::CopyScanlineDefault, 0);
        Scaleform::Render::DrawableImage::unmapTextureRT(this);
      }
      goto LABEL_36;
    }
    return 1;
  }
LABEL_16:
  if ( v7 != 0.0 )
    (*(void (__thiscall **)(float))(*(_DWORD *)LODWORD(v7) + 8))(COERCE_FLOAT(LODWORD(v7)));
  return 0;
}
