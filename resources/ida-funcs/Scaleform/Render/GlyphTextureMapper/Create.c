bool __thiscall Scaleform::Render::GlyphTextureMapper::Create(
        Scaleform::Render::GlyphTextureMapper *this,
        unsigned int method,
        Scaleform::MemoryHeap *heap,
        Scaleform::Render::TextureManager *texMan,
        Scaleform::Render::PrimitiveFillManager *fillMan,
        Scaleform::Render::GlyphCache *cache,
        unsigned int textureId,
        const Scaleform::Render::Size<unsigned long> *size)
{
  Scaleform::AmpServer *Instance; // eax
  Scaleform::AmpStats *v10; // eax
  Scaleform::Render::GlyphTextureImage *pObject; // ecx
  Scaleform::Render::RawImage *v12; // eax
  Scaleform::Render::RawImage *v13; // ecx
  Scaleform::Render::RawImage *v14; // edi
  void *v15; // ecx
  bool v16; // bl
  Scaleform::Render::RawImage *v17; // ecx
  Scaleform::Render::GlyphTextureImage *v18; // eax
  Scaleform::Render::GlyphTextureImage *v19; // ecx
  Scaleform::Render::GlyphTextureImage *v20; // edi
  Scaleform::GFx::Resource *v21; // eax
  Scaleform::Render::PrimitiveFill *v22; // eax
  Scaleform::Render::PrimitiveFill *v23; // ecx
  Scaleform::Render::PrimitiveFill *v24; // edi
  Scaleform::AmpStats *Stats; // esi
  Scaleform::AmpStats_vtbl *v26; // edi
  unsigned __int64 ProfileTicks; // rax
  Scaleform::AmpFunctionTimer v29; // [esp+10h] [ebp-28h] BYREF
  Scaleform::Render::PrimitiveFillData initdata; // [esp+20h] [ebp-18h] BYREF

  Instance = Scaleform::AmpServer::GetInstance();
  v10 = Instance->GetDisplayStats(Instance);
  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &v29,
    v10,
    "GlyphTextureMapper::Create",
    Amp_Profile_Level_Low,
    Amp_Native_Function_Id_GlyphTextureMapper_Create);
  this->pTexMan = texMan;
  this->Method = method;
  if ( method == 2 )
  {
    pObject = this->pTexImg.pObject;
    if ( pObject )
      pObject->Release(pObject);
    this->pTexImg.pObject = 0;
    v12 = Scaleform::Render::RawImage::Create(Image_A8, 1u, size, 0x10u, heap, 0);
    v13 = this->pRawImg.pObject;
    v14 = v12;
    if ( v13 )
      v13->Release(v13);
    v15 = v14;
    v16 = v14 != 0;
    this->pRawImg.pObject = v14;
    if ( v14 )
    {
LABEL_13:
      v21 = (Scaleform::GFx::Resource *)(*(int (__thiscall **)(void *, Scaleform::Render::TextureManager *))(*(_DWORD *)v15 + 96))(
                                          v15,
                                          texMan);
      Scaleform::Render::PrimitiveFillData::PrimitiveFillData(
        &initdata,
        PrimFill_UVTextureAlpha_VColor,
        &Scaleform::Render::RasterGlyphVertex::Format,
        v21,
        (Scaleform::Render::ImageFillMode)3,
        0,
        0);
      v22 = Scaleform::Render::PrimitiveFillManager::CreateFill(fillMan, &initdata);
      v23 = this->pFill.pObject;
      v24 = v22;
      if ( v23 )
        Scaleform::RefCountNTSImpl::Release(v23);
      this->pFill.pObject = v24;
      Scaleform::Render::PrimitiveFillData::~PrimitiveFillData(&initdata);
    }
  }
  else
  {
    v17 = this->pRawImg.pObject;
    if ( v17 )
      v17->Release(v17);
    this->pRawImg.pObject = 0;
    v18 = Scaleform::Render::GlyphTextureImage::Create(heap, texMan, cache, textureId, size, method != 1 ? 192 : 32);
    v19 = this->pTexImg.pObject;
    v20 = v18;
    if ( v19 )
      v19->Release(v19);
    v15 = v20;
    v16 = v20 != 0;
    this->pTexImg.pObject = v20;
    if ( v20 )
      goto LABEL_13;
  }
  this->Valid = v16;
  Stats = v29.Stats;
  if ( v29.Stats )
  {
    v26 = v29.Stats->__vftable;
    ProfileTicks = Scaleform::Timer::GetProfileTicks();
    ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v26->NativePopCallstack)(
      Stats,
      ProfileTicks - LODWORD(v29.StartTicks),
      (ProfileTicks - v29.StartTicks) >> 32);
  }
  return v16;
}
