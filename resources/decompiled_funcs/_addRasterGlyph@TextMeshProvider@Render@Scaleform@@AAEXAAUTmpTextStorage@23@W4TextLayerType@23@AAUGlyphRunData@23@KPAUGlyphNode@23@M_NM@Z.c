void __thiscall Scaleform::Render::TextMeshProvider::addRasterGlyph(
        Scaleform::Render::TextMeshProvider *this,
        Scaleform::Render::TmpTextStorage *storage,
        Scaleform::Render::TextLayerType type,
        Scaleform::Render::GlyphRunData *data,
        unsigned int color,
        Scaleform::Render::GlyphNode *node,
        float screenSize,
        bool snap,
        float stretch)
{
  unsigned __int16 w; // ax
  unsigned __int16 v10; // cx
  unsigned __int16 h; // dx
  double v12; // st7
  double v13; // st6
  Scaleform::Render::PrimitiveFill *Fill; // eax
  float v15; // [esp+1F0h] [ebp-50h]
  float ShadowOffsetX; // [esp+1F0h] [ebp-50h]
  float NewLineX; // [esp+1F4h] [ebp-4Ch]
  float v18; // [esp+1F8h] [ebp-48h]
  float ShadowOffsetY; // [esp+1F8h] [ebp-48h]
  float v21; // [esp+200h] [ebp-40h]
  float v22; // [esp+200h] [ebp-40h]
  float v23; // [esp+200h] [ebp-40h]
  float v24; // [esp+204h] [ebp-3Ch]
  float v25; // [esp+204h] [ebp-3Ch]
  float v26; // [esp+204h] [ebp-3Ch]
  float v27; // [esp+208h] [ebp-38h]
  float v28; // [esp+208h] [ebp-38h]
  float v29; // [esp+208h] [ebp-38h]
  float v30; // [esp+20Ch] [ebp-34h]
  float v31; // [esp+20Ch] [ebp-34h]
  float v32; // [esp+20Ch] [ebp-34h]
  Scaleform::Render::TmpTextMeshEntry val; // [esp+21Ch] [ebp-24h] BYREF

  NewLineX = data->NewLineX;
  if ( snap && ((data->pFont->Flags & 0x80) != 0 || (node->Param.Flags & 1) != 0 && (node->Param.Flags & 4) == 0) )
    NewLineX = Scaleform::Render::TextMeshProvider::snapX(this, data);
  w = node->mRect.w;
  v10 = node->pSlot->TextureId & 0x7FFF;
  if ( w > 1u )
  {
    h = node->mRect.h;
    if ( h > 1u )
    {
      v21 = (double)node->Origin.x * 0.0625 + 1.0;
      v24 = (double)node->Origin.y * 0.0625 + 1.0;
      v27 = (double)w + v21 - 2.0;
      v30 = (double)h + v24 - 2.0;
      v15 = 0.0625 * (double)node->Param.FontSize;
      if ( v15 < 0.0000099999997 )
        v15 = 0.0000099999997;
      v18 = node->Scale * screenSize / v15 / data->HeightRatio;
      v22 = v21 * (v18 / stretch);
      v25 = v24 * v18;
      v28 = v18 / stretch * v27;
      v31 = v18 * v30;
      ShadowOffsetX = 0.0;
      ShadowOffsetY = 0.0;
      if ( type == TextLayer_Shadow )
      {
        ShadowOffsetX = data->Param.ShadowOffsetX;
        ShadowOffsetY = data->Param.ShadowOffsetY;
      }
      val.TextureId = node->pSlot->TextureId & 0x7FFF;
      v12 = ShadowOffsetX + NewLineX;
      val.LayerType = type;
      v23 = v22 + v12;
      v13 = data->NewLineY + ShadowOffsetY;
      val.EntryIdx = storage->Entries.Size;
      val.mColor = color;
      v26 = v25 + v13;
      v29 = v12 + v28;
      v32 = v13 + v31;
      Fill = Scaleform::Render::GlyphCache::GetFill(this->pCache, type, v10);
      ++Fill->RefCount;
      val.EntryData.RasterData.Coord[0] = v23;
      val.pFill = Fill;
      val.EntryData.RasterData.Coord[1] = v26;
      val.EntryData.RasterData.Coord[2] = v29;
      val.EntryData.BackgroundData.BorderColor = (unsigned int)node;
      val.EntryData.RasterData.Coord[3] = v32;
      Scaleform::Render::ArrayPaged<Scaleform::Render::TmpTextMeshEntry,6,4>::PushBack(&storage->Entries, &val);
    }
  }
}
