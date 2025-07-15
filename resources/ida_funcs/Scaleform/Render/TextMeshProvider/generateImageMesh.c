char __thiscall Scaleform::Render::TextMeshProvider::generateImageMesh(
        Scaleform::Render::TextMeshProvider *this,
        Scaleform::Render::VertexOutput *verOut,
        const Scaleform::Render::TextMeshLayer *layer)
{
  Scaleform::Render::TextEntryUnion *p_EntryData; // esi
  Scaleform::Render::GlyphCache *pCache; // edx
  double v6; // st7
  double v7; // st6
  Scaleform::Render::VertexOutput_vtbl *v8; // eax
  char result; // al
  Scaleform::Render::Rect<float> v10; // [esp+4ACh] [ebp-D0h] BYREF
  float v11; // [esp+4C8h] [ebp-B4h]
  float v12; // [esp+4CCh] [ebp-B0h]
  _WORD v13[2]; // [esp+4D0h] [ebp-ACh] BYREF
  int v14; // [esp+4D4h] [ebp-A8h]
  int v15; // [esp+4D8h] [ebp-A4h]
  Scaleform::Render::Rect<float> v16; // [esp+4DCh] [ebp-A0h] BYREF
  float x2; // [esp+4F8h] [ebp-84h]
  float v18; // [esp+4FCh] [ebp-80h] BYREF
  float v19; // [esp+500h] [ebp-7Ch]
  float v20; // [esp+508h] [ebp-74h]
  float v21; // [esp+50Ch] [ebp-70h]
  float v22; // [esp+510h] [ebp-6Ch]
  float v23[2]; // [esp+518h] [ebp-64h]
  _DWORD v24[7]; // [esp+520h] [ebp-5Ch] BYREF
  float v25[16]; // [esp+53Ch] [ebp-40h] BYREF

  v13[0] = 0;
  v13[1] = 1;
  v14 = 2;
  v15 = 196610;
  p_EntryData = &this->Entries.Data.Data[layer->Start].EntryData;
  pCache = this->pCache;
  v24[0] = 4;
  v24[1] = 6;
  v24[2] = &Scaleform::Render::ImageGlyphVertex::Format;
  memset(&v24[3], 0, 16);
  ((void (__thiscall *)(unsigned int, float *, Scaleform::Render::TextureManager *))p_EntryData->RasterData.pGlyph->Param.pFont[5].pFont)(
    p_EntryData->BackgroundData.BorderColor,
    &v18,
    pCache->pTexMan);
  v12 = p_EntryData->RasterData.Coord[0];
  v11 = p_EntryData->RasterData.Coord[1];
  v6 = v12;
  v10.x2 = p_EntryData->RasterData.Coord[2] - v12;
  v7 = v11;
  v10.y2 = p_EntryData->RasterData.Coord[3] - v11;
  v11 = v19 * 0.0 + v18 * 0.0 + v20;
  v12 = 0.0 * v21 + v22 * 0.0 + v23[0];
  x2 = v10.x2;
  v10.x2 = v10.x2 * v18 + v19 * v10.y2 + v20;
  v10.y2 = v21 * x2 + v22 * v10.y2 + v23[0];
  v10.x1 = v11 + v6;
  v10.x2 = v6 + v10.x2;
  v10.y1 = v12 + v7;
  v10.y2 = v7 + v10.y2;
  v16.x1 = v11;
  v16.y1 = v12;
  v16.x2 = v18 + v19 + v20;
  v16.y2 = v23[0] + v22 + v21;
  Scaleform::Render::TextMeshProvider::clipGlyphRect(this, &v10, &v16);
  v25[0] = v10.x1;
  v8 = verOut->__vftable;
  v25[1] = v10.y1;
  v25[2] = v16.x1;
  v25[3] = v16.y1;
  v25[4] = v10.x2;
  v25[5] = v10.y1;
  v25[6] = v16.x2;
  v25[7] = v16.y1;
  v25[8] = v10.x2;
  v25[9] = v10.y2;
  v25[10] = v16.x2;
  v25[11] = v16.y2;
  v25[15] = v16.y2;
  v25[12] = v10.x1;
  v25[13] = v10.y2;
  v25[14] = v16.x1;
  result = v8->BeginOutput(
             verOut,
             (const Scaleform::Render::VertexOutput::Fill *)v24,
             1u,
             &Scaleform::Render::Matrix2x4<float>::Identity);
  if ( result )
  {
    verOut->SetVertices(verOut, 0, 0, v25, 4u);
    verOut->SetIndices(verOut, 0, 0, v13, 6u);
    verOut->EndOutput(verOut);
    return 1;
  }
  return result;
}
