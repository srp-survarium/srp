unsigned int __thiscall Scaleform::GFx::FontGlyphPacker::packGlyphRects(
        Scaleform::GFx::FontGlyphPacker *this,
        Scaleform::Array<Scaleform::GFx::FontGlyphPacker::GlyphInfo,2,Scaleform::ArrayDefaultPolicy> *glyphs)
{
  unsigned int v3; // eax
  unsigned int v5; // edi
  unsigned int v6; // ecx
  int v7; // edx
  int glyphsa; // [esp+8h] [ebp+4h]

  v3 = 0;
  if ( !this->pFontPackParams->SeparateTextures )
    return Scaleform::GFx::FontGlyphPacker::packGlyphRects(this, glyphs, 0, glyphs->Data.Size, 0);
  v5 = 1;
  v6 = 0;
  if ( glyphs->Data.Size > 1 )
  {
    v7 = 48;
    glyphsa = 48;
    do
    {
      if ( *(Scaleform::GFx::FontResource **)((char *)&glyphs->Data.Data[-1].pFont + v7) != *(Scaleform::GFx::FontResource **)((char *)&glyphs->Data.Data->pFont + v7) )
      {
        v3 = Scaleform::GFx::FontGlyphPacker::packGlyphRects(this, glyphs, v6, v5, v3);
        v6 = v5;
      }
      ++v5;
      v7 = glyphsa + 48;
      glyphsa += 48;
    }
    while ( v5 < glyphs->Data.Size );
  }
  return Scaleform::GFx::FontGlyphPacker::packGlyphRects(this, glyphs, v6, glyphs->Data.Size, v3);
}


unsigned int __thiscall Scaleform::GFx::FontGlyphPacker::packGlyphRects(
        Scaleform::GFx::FontGlyphPacker *this,
        Scaleform::Array<Scaleform::GFx::FontGlyphPacker::GlyphInfo,2,Scaleform::ArrayDefaultPolicy> *glyphs,
        unsigned int start,
        unsigned int end,
        unsigned int texIdx)
{
  Scaleform::GFx::FontGlyphPacker *v5; // edi
  Scaleform::Render::RectPacker *p_Packer; // ebx
  unsigned int v7; // eax
  float *v8; // esi
  unsigned int v9; // ecx
  Scaleform::Render::RectPacker::PackType *v10; // eax
  unsigned int *p_x; // edi
  Scaleform::GFx::FontGlyphPacker::GlyphInfo *v12; // esi
  float x1; // [esp+54h] [ebp-3Ch]
  unsigned int id; // [esp+58h] [ebp-38h]
  unsigned int ida; // [esp+58h] [ebp-38h]
  unsigned int v17; // [esp+5Ch] [ebp-34h]
  int v18; // [esp+5Ch] [ebp-34h]
  float v19; // [esp+60h] [ebp-30h]
  float v20; // [esp+60h] [ebp-30h]
  float v21; // [esp+60h] [ebp-30h]
  Scaleform::Render::RectPacker::PackType *v22; // [esp+60h] [ebp-30h]
  float v24; // [esp+68h] [ebp-28h]
  float v25; // [esp+68h] [ebp-28h]
  float v26; // [esp+70h] [ebp-20h]
  float v27; // [esp+70h] [ebp-20h]
  float v28; // [esp+70h] [ebp-20h]
  float v29; // [esp+70h] [ebp-20h]
  float v30; // [esp+70h] [ebp-20h]
  float v31; // [esp+78h] [ebp-18h]
  float y1; // [esp+80h] [ebp-10h]
  float v33; // [esp+80h] [ebp-10h]
  double wa; // [esp+88h] [ebp-8h]
  unsigned int w; // [esp+88h] [ebp-8h]

  v5 = this;
  p_Packer = &this->Packer;
  this->Packer.SrcRects.Size = 0;
  this->Packer.PackedRects.Size = 0;
  this->Packer.Packs.Size = 0;
  this->Packer.PackTree.Size = 0;
  this->Packer.Failed.Size = 0;
  id = start;
  if ( start < end )
  {
    v7 = 48 * start;
    v17 = 48 * start;
    do
    {
      v8 = (float *)((char *)glyphs->Data.Data + v7);
      if ( *((_DWORD *)v8 + 2) == -1 )
      {
        v19 = ceil(v8[6]);
        v24 = v19;
        v26 = v8[4];
        v20 = ceil(v8[7]);
        wa = v20;
        v21 = floor(v8[5]);
        v27 = floor(v26);
        Scaleform::Render::RectPacker::AddRect(p_Packer, (__int64)(v24 - v27), (__int64)(wa - v21), id);
        v7 = v17;
      }
      v7 += 48;
      ++id;
      v17 = v7;
    }
    while ( id < end );
  }
  Scaleform::Render::RectPacker::Pack(p_Packer);
  v9 = 0;
  for ( ida = 0; v9 < v5->Packer.Packs.Size; ida = v9 )
  {
    v10 = &v5->Packer.Packs.Pages[v9 >> 4][v9 & 0xF];
    v22 = v10;
    v18 = 0;
    if ( v10->NumRects )
    {
      w = texIdx + v9;
      while ( 1 )
      {
        p_x = &v5->Packer.PackedRects.Pages[(v18 + v10->StartRect) >> 8][(unsigned __int8)(v18 + LOBYTE(v10->StartRect))].x;
        v12 = &glyphs->Data.Data[p_x[2]];
        v28 = ceil(v12->Bounds.x2);
        v25 = v28;
        x1 = v12->Bounds.x1;
        v29 = ceil(v12->Bounds.y2);
        v31 = v29;
        y1 = v12->Bounds.y1;
        v12->Origin.x = (double)*p_x - v12->Bounds.x1;
        v12->Origin.y = (double)p_x[1] - v12->Bounds.y1;
        v12->Bounds.x1 = (float)*p_x;
        v12->Bounds.y1 = (float)p_x[1];
        v30 = floor(x1);
        v12->Bounds.x2 = (float)(*p_x + (unsigned int)(__int64)(v25 - v30));
        v33 = floor(y1);
        v12->Bounds.y2 = (float)(p_x[1] + (unsigned int)(__int64)(v31 - v33));
        v5 = this;
        v12->TextureIdx = w;
        if ( ++v18 >= v22->NumRects )
          break;
        v10 = v22;
      }
      v9 = ida;
    }
    ++v9;
  }
  return texIdx + v5->Packer.Packs.Size;
}
