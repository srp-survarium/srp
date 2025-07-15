char __thiscall Scaleform::Render::GlyphCache::updateTextureGlyph(
        Scaleform::Render::GlyphCache *this,
        const Scaleform::Render::GlyphNode *node)
{
  Scaleform::AmpServer *Instance; // eax
  Scaleform::AmpStats *v4; // eax
  unsigned __int16 TextureId; // di
  unsigned int RasterPitch; // ecx
  unsigned int w; // ebp
  unsigned int x; // edx
  unsigned int v9; // edi
  unsigned int y; // ecx
  unsigned int h; // edx
  Scaleform::Render::GlyphTextureMapper *v12; // ecx
  unsigned int TextureHeight; // eax
  Scaleform::Render::TextureManager *pTexMan; // edx
  Scaleform::AmpStats *Stats; // edi
  void (__thiscall **p_NativePopCallstack)(Scaleform::AmpStats *, unsigned __int64); // esi
  unsigned __int64 ProfileTicks; // rax
  Scaleform::Render::RawImage *pObject; // ecx
  Scaleform::ArrayPagedLH_POD<Scaleform::Render::GlyphCache::UpdateRect,6,16,2> *p_GlyphsToUpdate; // ebp
  unsigned int v21; // esi
  unsigned int v22; // esi
  Scaleform::Render::Palette *v23; // esi
  Scaleform::AmpStats *v24; // edi
  void (__thiscall **v25)(Scaleform::AmpStats *, unsigned __int64); // esi
  unsigned __int64 v26; // rax
  Scaleform::Render::ImagePlane *v27; // eax
  Scaleform::AmpStats *v28; // esi
  void (__thiscall **v29)(Scaleform::AmpStats *, unsigned __int64); // edi
  unsigned __int64 v30; // rax
  Scaleform::AmpStats *v31; // edi
  void (__thiscall **v32)(Scaleform::AmpStats *, unsigned __int64); // esi
  unsigned __int64 v33; // rax
  unsigned int v34; // [esp+10h] [ebp-78h]
  Scaleform::Render::Size<unsigned long> size; // [esp+14h] [ebp-74h] BYREF
  Scaleform::Render::GlyphTextureMapper *v36; // [esp+1Ch] [ebp-6Ch] BYREF
  unsigned int v37; // [esp+20h] [ebp-68h]
  unsigned int v38; // [esp+24h] [ebp-64h]
  unsigned int v39; // [esp+28h] [ebp-60h]
  const __m128i *Data; // [esp+2Ch] [ebp-5Ch]
  char *v41; // [esp+30h] [ebp-58h]
  Scaleform::AmpFunctionTimer v42; // [esp+34h] [ebp-54h] BYREF
  _DWORD v43[7]; // [esp+44h] [ebp-44h] BYREF
  Scaleform::Render::ImageData v44; // [esp+60h] [ebp-28h] BYREF

  Instance = Scaleform::AmpServer::GetInstance();
  v4 = Instance->GetDisplayStats(Instance);
  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &v42,
    v4,
    "GlyphCache::UpdateTextureGlyph",
    Amp_Profile_Level_Medium,
    Amp_Native_Function_Id_Invalid);
  TextureId = node->pSlot->TextureId;
  RasterPitch = this->RasterPitch;
  w = node->mRect.w;
  Data = (const __m128i *)this->RasterData.Data.Data;
  x = node->mRect.x;
  v9 = TextureId & 0x7FFF;
  v39 = RasterPitch;
  y = node->mRect.y;
  v38 = x;
  h = node->mRect.h;
  v37 = y;
  v12 = &this->Textures[v9];
  v34 = h;
  v41 = (char *)this + 80 * v9;
  v36 = v12;
  if ( !v12->Valid )
  {
    TextureHeight = this->TextureHeight;
    size.Width = this->TextureWidth;
    pTexMan = this->pTexMan;
    size.Height = TextureHeight;
    Scaleform::Render::GlyphTextureMapper::Create(
      v12,
      this->Method,
      this->pHeap,
      pTexMan,
      this->pFillMan,
      this,
      v9,
      &size);
    v12 = v36;
  }
  this->pRQCaches->LockFlags |= 2u;
  if ( this->Method == TU_MultipleUpdate )
  {
    if ( !Scaleform::Render::TextureUpdatePacker::Allocate(
            &this->UpdatePacker,
            w,
            v34,
            &size.Width,
            (unsigned int *)&v36) )
    {
      Scaleform::Render::GlyphCache::partialUpdateTextures(this);
      if ( !Scaleform::Render::TextureUpdatePacker::Allocate(
              &this->UpdatePacker,
              w,
              v34,
              &size.Width,
              (unsigned int *)&v36) )
      {
        Stats = v42.Stats;
        if ( v42.Stats )
        {
          p_NativePopCallstack = &v42.Stats->NativePopCallstack;
          ProfileTicks = Scaleform::Timer::GetProfileTicks();
          ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))*p_NativePopCallstack)(
            Stats,
            ProfileTicks - LODWORD(v42.StartTicks),
            (ProfileTicks - v42.StartTicks) >> 32);
          return 0;
        }
        return 0;
      }
    }
    v44.pPlanes = &v44.Plane0;
    pObject = this->UpdateBuffer.pObject;
    memset(&v44, 0, 10);
    v44.RawPlaneCount = 1;
    memset(&v44.pPalette, 0, 24);
    Scaleform::Render::RawImage::GetImageData(pObject, &v44);
    Scaleform::Render::GlyphCache::copyImageData(this, v44.pPlanes, Data, v39, size.Width, (unsigned int)v36, w, v34);
    ++*((_DWORD *)v41 + 49);
    v43[4] = w;
    p_GlyphsToUpdate = &this->GlyphsToUpdate;
    v21 = this->GlyphsToUpdate.Size;
    v43[0] = size.Width;
    v43[1] = v36;
    v22 = v21 >> 6;
    v43[2] = v38;
    v43[3] = v37;
    v43[5] = v34;
    v43[6] = v9;
    if ( v22 >= p_GlyphsToUpdate->NumPages )
      Scaleform::ArrayPagedBase<Scaleform::Render::GlyphCache::UpdateRect,6,16,Scaleform::AllocatorPagedLH_POD<Scaleform::Render::GlyphCache::UpdateRect,2>>::allocatePage(
        p_GlyphsToUpdate,
        v22);
    qmemcpy(
      &p_GlyphsToUpdate->Pages[v22][p_GlyphsToUpdate->Size++ & 0x3F],
      v43,
      sizeof(p_GlyphsToUpdate->Pages[v22][p_GlyphsToUpdate->Size++ & 0x3F]));
    Scaleform::Render::ImageData::freePlanes(&v44);
    if ( v44.pPalette.pObject )
    {
      v23 = v44.pPalette.pObject;
      if ( InterlockedExchangeAdd(&v44.pPalette.pObject->RefCount.Value, -1) == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v23);
    }
    v24 = v42.Stats;
    if ( v42.Stats )
    {
      v25 = &v42.Stats->NativePopCallstack;
      v26 = Scaleform::Timer::GetProfileTicks();
      ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))*v25)(
        v24,
        v26 - LODWORD(v42.StartTicks),
        (v26 - v42.StartTicks) >> 32);
    }
    return 1;
  }
  else
  {
    v27 = Scaleform::Render::GlyphTextureMapper::Map(v12);
    if ( !v27 )
    {
      v31 = v42.Stats;
      if ( v42.Stats )
      {
        v32 = &v42.Stats->NativePopCallstack;
        v33 = Scaleform::Timer::GetProfileTicks();
        ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))*v32)(
          v31,
          v33 - LODWORD(v42.StartTicks),
          (v33 - v42.StartTicks) >> 32);
      }
      return 0;
    }
    Scaleform::Render::GlyphCache::copyImageData(this, v27, Data, v39, v38, v37, w, v34);
    v28 = v42.Stats;
    if ( v42.Stats )
    {
      v29 = &v42.Stats->NativePopCallstack;
      v30 = Scaleform::Timer::GetProfileTicks();
      ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))*v29)(
        v28,
        v30 - LODWORD(v42.StartTicks),
        (v30 - v42.StartTicks) >> 32);
    }
    return 1;
  }
}
