Scaleform::Render::GlyphNode *__userpurge Scaleform::Render::GlyphCache::RasterizeShadow@<eax>(
        Scaleform::Render::GlyphCache *this@<ecx>,
        float a2@<ebx>,
        float a3@<ebp>,
        Scaleform::Render::GlyphRunData *data,
        Scaleform::Render::TextMeshProvider *tm,
        const Scaleform::Render::GlyphParam *gp,
        float screenSize,
        const Scaleform::Render::GlyphRaster *ras)
{
  Scaleform::AmpServer *Instance; // eax
  Scaleform::AmpStats *v10; // eax
  Scaleform::AmpStats *Stats; // edi
  void (__thiscall **p_NativePopCallstack)(_DWORD, _DWORD, _DWORD); // esi
  unsigned __int64 ProfileTicks; // rax
  Scaleform::Render::GlyphNode *ShadowFromRaster; // ebp
  Scaleform::AmpStats *v17; // edi
  void (__thiscall **v18)(Scaleform::AmpStats *, unsigned __int64); // esi
  unsigned __int64 v19; // rax
  Scaleform::AmpStats *v20; // edi
  void (__thiscall **v21)(_DWORD, _DWORD, _DWORD); // esi
  unsigned __int64 v22; // rax
  double v23; // st6
  double v24; // st4
  double v25; // st7
  unsigned int HintedNomHeight; // eax
  double NomHeight; // st6
  double v28; // st7
  double v29; // st5
  double v30; // st6
  double v31; // st7
  char *v32; // ebx
  unsigned int SlotPadding; // eax
  int v34; // edi
  char *v35; // ebp
  unsigned int v36; // ebx
  unsigned int v37; // eax
  Scaleform::Render::GlyphNode *v38; // ecx
  unsigned int MaxSlotHeight; // ebp
  Scaleform::Render::GlyphNode *Glyph; // eax
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *p_RasterData; // ebx
  unsigned int i; // edi
  int v43; // edi
  double v44; // st7
  int v45; // eax
  void (__thiscall *Clear)(struct Scaleform::Render::Rasterizer *); // edx
  Scaleform::AmpStats *v47; // edi
  void (__thiscall **v48)(Scaleform::AmpStats *, unsigned __int64); // esi
  unsigned __int64 v49; // rax
  unsigned __int8 *v50; // [esp-4h] [ebp-40h]
  float screenSizea; // [esp+0h] [ebp-3Ch]
  float y1; // [esp+18h] [ebp-24h]
  Scaleform::Render::Rasterizer *p_Ras; // [esp+18h] [ebp-24h]
  float v56; // [esp+1Ch] [ebp-20h]
  unsigned int v57; // [esp+1Ch] [ebp-20h]
  float v58; // [esp+20h] [ebp-1Ch]
  float v59; // [esp+24h] [ebp-18h]
  char *v60; // [esp+24h] [ebp-18h]
  const Scaleform::Render::GlyphNode *v61; // [esp+28h] [ebp-14h]
  Scaleform::AmpFunctionTimer v62; // [esp+2Ch] [ebp-10h] BYREF
  float dataa; // [esp+40h] [ebp+4h]
  float tma; // [esp+44h] [ebp+8h]
  float v65; // [esp+4Ch] [ebp+10h]
  float v66; // [esp+4Ch] [ebp+10h]
  float v67; // [esp+4Ch] [ebp+10h]
  float v68; // [esp+4Ch] [ebp+10h]
  float v69; // [esp+4Ch] [ebp+10h]
  float rasd; // [esp+50h] [ebp+14h]
  float rase; // [esp+50h] [ebp+14h]
  float rasf; // [esp+50h] [ebp+14h]
  float rasa; // [esp+50h] [ebp+14h]
  float rasg; // [esp+50h] [ebp+14h]
  float rash; // [esp+50h] [ebp+14h]
  float rasb; // [esp+50h] [ebp+14h]
  float rasi; // [esp+50h] [ebp+14h]
  float rasj; // [esp+50h] [ebp+14h]
  unsigned int rasc; // [esp+50h] [ebp+14h]

  Instance = Scaleform::AmpServer::GetInstance();
  v10 = Instance->GetDisplayStats(Instance);
  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &v62,
    v10,
    "GlyphCache::RasterizeShadow",
    Amp_Profile_Level_Low,
    Amp_Native_Function_Id_GlyphCache_RasterizeShadow);
  if ( !this->MaxNumTextures )
  {
    Stats = v62.Stats;
    this->Result = Res_NoRasterCache;
    if ( Stats )
    {
      p_NativePopCallstack = (void (__thiscall **)(_DWORD, _DWORD, _DWORD))&Stats->NativePopCallstack;
      ProfileTicks = Scaleform::Timer::GetProfileTicks();
      (*p_NativePopCallstack)(Stats, ProfileTicks - LODWORD(v62.StartTicks), (ProfileTicks - v62.StartTicks) >> 32);
    }
    return 0;
  }
  if ( ras )
  {
    ShadowFromRaster = Scaleform::Render::GlyphCache::createShadowFromRaster(this, data, tm, gp, screenSize, ras);
    if ( ShadowFromRaster )
    {
      v17 = v62.Stats;
      if ( v62.Stats )
      {
        v18 = &v62.Stats->NativePopCallstack;
        v19 = Scaleform::Timer::GetProfileTicks();
        ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))*v18)(
          v17,
          v19 - LODWORD(v62.StartTicks),
          (v19 - v62.StartTicks) >> 32);
      }
      return ShadowFromRaster;
    }
  }
  if ( !data->pShape )
  {
    v20 = v62.Stats;
    this->Result = Res_ShapeNotFound;
    if ( v20 )
    {
      v21 = (void (__thiscall **)(_DWORD, _DWORD, _DWORD))&v20->NativePopCallstack;
      v22 = Scaleform::Timer::GetProfileTicks();
      (*v21)(v20, v22 - LODWORD(v62.StartTicks), (v22 - v62.StartTicks) >> 32);
    }
    return 0;
  }
  rasd = (double)gp->FontSize * 0.0625;
  v23 = rasd;
  v65 = rasd / screenSize;
  rase = (double)gp->BlurX * 0.0625;
  v24 = v65;
  dataa = rase * v65 * data->HeightRatio;
  v66 = 0.0625 * (double)gp->BlurY;
  v25 = v23;
  v67 = v24 * v66 * data->HeightRatio;
  HintedNomHeight = data->HintedNomHeight;
  v59 = this->ShadowQuality * (double)this->MaxSlotHeight - (double)(2 * this->SlotPadding);
  v58 = 1.0;
  if ( HintedNomHeight )
    NomHeight = (double)HintedNomHeight;
  else
    NomHeight = data->NomHeight;
  rasf = NomHeight;
  v56 = v25 / rasf;
  y1 = data->GlyphBounds.y1;
  rasa = data->GlyphBounds.y2;
  if ( rasa <= (double)y1 )
  {
    rasa = 0.0;
    y1 = 0.0;
  }
  v28 = v67;
  rasg = rasa * v56 + v67;
  v29 = rasg;
  rash = y1 * v56 - v67;
  rasb = v29 - rash;
  if ( v59 <= (double)rasb )
  {
    v68 = v59 / rasb;
    v56 = v56 * v68;
    dataa = dataa * v68;
    v30 = v28 * v68;
    v31 = v68;
    v67 = v30;
    v58 = 1.0 / v31;
  }
  rasi = ceil(dataa);
  v32 = (char *)(int)rasi;
  rasj = ceil(v67);
  p_Ras = &this->Ras;
  ((void (*)(void))this->Ras.Clear)();
  Scaleform::Render::GlyphCache::addShapeToRasterizer(this, v32, (float *)data, data->pShape, v56, v56, a3, a2);
  SlotPadding = this->SlotPadding;
  v60 = &v32[SlotPadding];
  v57 = (int)rasj + SlotPadding;
  v34 = 0;
  v35 = 0;
  v36 = 0;
  if ( Scaleform::Render::Rasterizer::SortCells(&this->Ras) )
  {
    v34 = this->Ras.MinX - (_DWORD)v60;
    v35 = &v60[this->Ras.MaxX];
    v36 = this->Ras.MinY - v57;
    v37 = v57 + this->Ras.MaxY;
  }
  else
  {
    v37 = 0;
  }
  v38 = (Scaleform::Render::GlyphNode *)&v35[-v34 + 1];
  MaxSlotHeight = v37 - v36 + 1;
  rasc = (unsigned int)v38;
  if ( MaxSlotHeight > this->MaxSlotHeight )
    MaxSlotHeight = this->MaxSlotHeight;
  Glyph = Scaleform::Render::GlyphCache::allocateGlyph(this, tm, gp, v38, (Scaleform::Render::GlyphNode *)MaxSlotHeight);
  v61 = Glyph;
  if ( !Glyph )
  {
    this->Result = Res_CacheFull;
    Scaleform::Render::GlyphCache::cacheFullWarning(this);
    Scaleform::AmpFunctionTimer::~AmpFunctionTimer(&v62);
    return 0;
  }
  Glyph->Origin.x = 16 * v34;
  Glyph->Scale = v58;
  Glyph->Origin.y = 16 * v36;
  p_RasterData = &this->RasterData;
  Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::Resize(
    &this->RasterData,
    rasc * MaxSlotHeight);
  v50 = this->RasterData.Data.Data;
  this->RasterPitch = rasc;
  memset((int)v50, 0, rasc * MaxSlotHeight);
  if ( rasc > 1 && MaxSlotHeight > 1 )
  {
    tma = 1.0;
    if ( gp->BlurX || gp->BlurY )
      tma = 0.40000001;
    if ( this->Ras.Gamma2 != tma )
      Scaleform::Render::Rasterizer::SetGamma2(p_Ras, tma);
    for ( i = 0; i < this->Ras.SortedYs.Size; ++i )
    {
      if ( i + v57 >= MaxSlotHeight )
        break;
      Scaleform::Render::Rasterizer::SweepScanline(
        p_Ras,
        i,
        &p_RasterData->Data.Data[(unsigned int)&v60[(i + v57) * this->RasterPitch]],
        1u,
        1);
    }
    v43 = 0;
    if ( (gp->Flags & 0x20) != 0 )
      Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::operator=(
        &this->KnockOutCopy,
        &this->RasterData);
    if ( dataa > 0.0 )
    {
      v44 = dataa;
    }
    else
    {
      v44 = dataa;
      if ( v67 <= 0.0 )
        goto LABEL_42;
    }
    screenSizea = v44;
    Scaleform::Render::GlyphCache::recursiveBlur(
      this,
      p_RasterData->Data.Data,
      this->RasterPitch,
      0,
      0,
      rasc,
      MaxSlotHeight,
      screenSizea,
      v67);
    v43 = 8;
LABEL_42:
    v69 = (double)gp->BlurStrength * 0.0625;
    if ( v69 > 1.0 )
      v45 = v43;
    else
      v45 = 0;
    Scaleform::Render::GlyphCache::strengthenImage(
      this,
      p_RasterData->Data.Data,
      this->RasterPitch,
      0,
      0,
      rasc,
      MaxSlotHeight,
      v69,
      v45);
    if ( (gp->Flags & 0x20) != 0 )
      Scaleform::Render::GlyphCache::knockOut(this, p_RasterData->Data.Data);
  }
  Scaleform::Render::GlyphCache::updateTextureGlyph(this, v61);
  Clear = p_Ras->Clear;
  ++this->RasterizationCount;
  Clear(p_Ras);
  v47 = v62.Stats;
  if ( v62.Stats )
  {
    v48 = &v62.Stats->NativePopCallstack;
    v49 = Scaleform::Timer::GetProfileTicks();
    ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))*v48)(
      v47,
      v49 - LODWORD(v62.StartTicks),
      (v49 - v62.StartTicks) >> 32);
  }
  return (Scaleform::Render::GlyphNode *)v61;
}
