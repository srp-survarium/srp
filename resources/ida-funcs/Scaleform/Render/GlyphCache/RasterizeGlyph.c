Scaleform::Render::GlyphNode *__userpurge Scaleform::Render::GlyphCache::RasterizeGlyph@<eax>(
        Scaleform::Render::GlyphCache *this@<ecx>,
        float a2@<ebx>,
        float a3@<ebp>,
        Scaleform::Render::GlyphRunData *data,
        Scaleform::Render::TextMeshProvider *tm,
        const Scaleform::Render::GlyphParam *gp)
{
  Scaleform::AmpServer *Instance; // eax
  Scaleform::AmpStats *v8; // eax
  Scaleform::AmpStats *v9; // edi
  void (__thiscall **v10)(_DWORD, _DWORD, _DWORD); // esi
  unsigned __int64 v11; // rax
  Scaleform::Render::GlyphNode *PrerasterizedGlyph; // eax
  Scaleform::AmpStats *Stats; // esi
  Scaleform::Render::GlyphNode *v16; // ebx
  void (__thiscall **p_NativePopCallstack)(Scaleform::AmpStats *, unsigned __int64); // edi
  unsigned __int64 ProfileTicks; // rax
  Scaleform::AmpStats *v19; // edi
  void (__thiscall **v20)(_DWORD, _DWORD, _DWORD); // esi
  unsigned __int64 v21; // rax
  int LowerCaseTop; // ebx
  double v23; // st7
  unsigned __int16 UpperCaseTop; // ax
  unsigned int HintedNomHeight; // eax
  unsigned int v26; // ebx
  unsigned int v27; // ebp
  unsigned int v28; // edi
  unsigned int v29; // eax
  Scaleform::Render::GlyphNode *v30; // ecx
  unsigned int v31; // edi
  Scaleform::Render::GlyphNode *Glyph; // eax
  double v33; // st7
  unsigned int v34; // ebp
  unsigned __int8 *v35; // edi
  void (__thiscall *Clear)(struct Scaleform::Render::Rasterizer *); // eax
  Scaleform::AmpStats *v37; // esi
  void (__thiscall **v38)(Scaleform::AmpStats *, unsigned __int64); // edi
  unsigned __int64 v39; // rax
  unsigned __int8 *v40; // [esp-4h] [ebp-48h]
  float v42; // [esp+18h] [ebp-2Ch]
  float v43; // [esp+18h] [ebp-2Ch]
  Scaleform::Render::Rasterizer *p_Ras; // [esp+18h] [ebp-2Ch]
  float v45; // [esp+1Ch] [ebp-28h]
  float v46; // [esp+20h] [ebp-24h]
  float v47; // [esp+20h] [ebp-24h]
  float v48; // [esp+20h] [ebp-24h]
  unsigned int MaxSlotHeight; // [esp+20h] [ebp-24h]
  float NomHeight; // [esp+28h] [ebp-1Ch]
  float v51; // [esp+28h] [ebp-1Ch]
  __int16 v52; // [esp+28h] [ebp-1Ch]
  int v53; // [esp+2Ch] [ebp-18h]
  unsigned int SlotPadding; // [esp+2Ch] [ebp-18h]
  Scaleform::AmpFunctionTimer v55; // [esp+34h] [ebp-10h] BYREF
  char dataa; // [esp+48h] [ebp+4h]
  float datac; // [esp+48h] [ebp+4h]
  float datad; // [esp+48h] [ebp+4h]
  unsigned int datab; // [esp+48h] [ebp+4h]
  Scaleform::Render::TextMeshProvider *tma; // [esp+4Ch] [ebp+8h]
  bool gpa; // [esp+50h] [ebp+Ch]

  Instance = Scaleform::AmpServer::GetInstance();
  v8 = Instance->GetDisplayStats(Instance);
  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &v55,
    v8,
    "GlyphCache::RasterizeGlyph",
    Amp_Profile_Level_Low,
    Amp_Native_Function_Id_GlyphCache_RasterizeGlyph);
  if ( this->MaxNumTextures )
  {
    if ( data->RasterSize )
    {
      PrerasterizedGlyph = Scaleform::Render::GlyphCache::getPrerasterizedGlyph(this, data, tm, gp);
      Stats = v55.Stats;
      v16 = PrerasterizedGlyph;
      if ( v55.Stats )
      {
        p_NativePopCallstack = &v55.Stats->NativePopCallstack;
        ProfileTicks = Scaleform::Timer::GetProfileTicks();
        ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))*p_NativePopCallstack)(
          Stats,
          ProfileTicks - LODWORD(v55.StartTicks),
          (ProfileTicks - v55.StartTicks) >> 32);
      }
      return v16;
    }
    else if ( data->pShape )
    {
      LowerCaseTop = 0;
      v53 = 0;
      if ( !this->Param.UseAutoFit || (dataa = 1, (gp->Flags & 2) == 0) )
        dataa = 0;
      if ( (gp->Flags & 4) != 0 )
        v23 = 2.5;
      else
        v23 = 1.0;
      v45 = v23;
      if ( dataa )
      {
        LowerCaseTop = (unsigned __int16)Scaleform::Render::Font::GetLowerCaseTop(gp->pFont->pFont, this);
        UpperCaseTop = Scaleform::Render::Font::GetUpperCaseTop(gp->pFont->pFont, this);
        v53 = UpperCaseTop;
        if ( !LowerCaseTop || !UpperCaseTop )
          dataa = 0;
      }
      HintedNomHeight = data->HintedNomHeight;
      NomHeight = data->NomHeight;
      if ( HintedNomHeight )
      {
        NomHeight = (float)HintedNomHeight;
        dataa = 0;
      }
      v46 = (double)gp->FontSize * 0.0625;
      v51 = v46 / NomHeight;
      v47 = data->GlyphBounds.y1 * v51;
      v48 = floor(v47);
      v42 = data->GlyphBounds.y2 * v51;
      v43 = ceil(v42);
      if ( v43 <= (double)v48 )
      {
        v43 = 0.0;
        v48 = 0.0;
      }
      if ( (unsigned int)(__int64)(v43 - v48) + 2 * this->SlotPadding < this->MaxSlotHeight )
      {
        p_Ras = &this->Ras;
        ((void (*)(void))this->Ras.Clear)();
        if ( dataa )
        {
          datac = (double)gp->FontSize * 0.0625;
          Scaleform::Render::GlyphCache::addShapeAutoFit(
            this,
            (int *)LowerCaseTop,
            data->pShape,
            (__int64)data->NomHeight,
            LowerCaseTop,
            v53,
            datac,
            v45);
        }
        else
        {
          datad = v51 * v45;
          Scaleform::Render::GlyphCache::addShapeToRasterizer(
            this,
            (char *)LowerCaseTop,
            (float *)data,
            data->pShape,
            datad,
            v51,
            a3,
            a2);
        }
        v26 = 0;
        SlotPadding = this->SlotPadding;
        v27 = 0;
        v28 = 0;
        v52 = 0;
        if ( Scaleform::Render::Rasterizer::SortCells(p_Ras) )
        {
          v29 = this->Ras.MinY - SlotPadding;
          v27 = this->Ras.MinX - SlotPadding;
          v28 = SlotPadding + this->Ras.MaxX;
          v52 = v29;
          v26 = SlotPadding + this->Ras.MaxY;
        }
        else
        {
          v29 = 0;
        }
        v30 = (Scaleform::Render::GlyphNode *)(v28 - v27 + 1);
        v31 = v26 - v29 + 1;
        datab = (unsigned int)v30;
        MaxSlotHeight = v31;
        if ( v31 > this->MaxSlotHeight )
        {
          MaxSlotHeight = this->MaxSlotHeight;
          v31 = MaxSlotHeight;
        }
        Glyph = Scaleform::Render::GlyphCache::allocateGlyph(this, tm, gp, v30, (Scaleform::Render::GlyphNode *)v31);
        tma = (Scaleform::Render::TextMeshProvider *)Glyph;
        if ( Glyph )
        {
          Glyph->Scale = 1.0;
          Glyph->Origin.x = 16 * v27;
          Glyph->Origin.y = 16 * v52;
          Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::Resize(
            &this->RasterData,
            datab * v31);
          v40 = this->RasterData.Data.Data;
          this->RasterPitch = datab;
          memset((int)v40, 0, datab * v31);
          v33 = 1.0;
          if ( 1.0 != this->Ras.Gamma1 )
          {
            Scaleform::Render::Rasterizer::SetGamma1(p_Ras, 1.0);
            v33 = 1.0;
          }
          gpa = datab >= 5 && v33 < v45;
          v34 = 0;
          if ( this->Ras.SortedYs.Size )
          {
            while ( SlotPadding + v34 < v31 )
            {
              v35 = &this->RasterData.Data.Data[(SlotPadding + v34) * this->RasterPitch];
              Scaleform::Render::Rasterizer::SweepScanline(p_Ras, v34, &v35[SlotPadding], 1u, 0);
              if ( gpa )
                Scaleform::Render::GlyphCache::filterScanline(this, v35, datab);
              if ( ++v34 >= this->Ras.SortedYs.Size )
                break;
              v31 = MaxSlotHeight;
            }
          }
          Scaleform::Render::GlyphCache::updateTextureGlyph(this, (const Scaleform::Render::GlyphNode *)tma);
          Clear = p_Ras->Clear;
          ++this->RasterizationCount;
          Clear(p_Ras);
          v37 = v55.Stats;
          if ( v55.Stats )
          {
            v38 = &v55.Stats->NativePopCallstack;
            v39 = Scaleform::Timer::GetProfileTicks();
            ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))*v38)(
              v37,
              v39 - LODWORD(v55.StartTicks),
              (v39 - v55.StartTicks) >> 32);
          }
          return (Scaleform::Render::GlyphNode *)tma;
        }
        else
        {
          this->Result = Res_CacheFull;
          Scaleform::Render::GlyphCache::cacheFullWarning(this);
          Scaleform::AmpFunctionTimer::~AmpFunctionTimer(&v55);
          return 0;
        }
      }
      else
      {
        this->Result = Res_ShapeIsTooBig;
        Scaleform::AmpFunctionTimer::~AmpFunctionTimer(&v55);
        return 0;
      }
    }
    else
    {
      v19 = v55.Stats;
      this->Result = Res_ShapeNotFound;
      if ( v19 )
      {
        v20 = (void (__thiscall **)(_DWORD, _DWORD, _DWORD))&v19->NativePopCallstack;
        v21 = Scaleform::Timer::GetProfileTicks();
        (*v20)(v19, v21 - LODWORD(v55.StartTicks), (v21 - v55.StartTicks) >> 32);
      }
      return 0;
    }
  }
  else
  {
    v9 = v55.Stats;
    this->Result = Res_NoRasterCache;
    if ( v9 )
    {
      v10 = (void (__thiscall **)(_DWORD, _DWORD, _DWORD))&v9->NativePopCallstack;
      v11 = Scaleform::Timer::GetProfileTicks();
      (*v10)(v9, v11 - LODWORD(v55.StartTicks), (v11 - v55.StartTicks) >> 32);
    }
    return 0;
  }
}
