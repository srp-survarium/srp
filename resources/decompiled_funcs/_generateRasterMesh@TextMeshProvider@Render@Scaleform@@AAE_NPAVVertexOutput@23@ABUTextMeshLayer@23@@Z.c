char __thiscall Scaleform::Render::TextMeshProvider::generateRasterMesh(
        Scaleform::Render::TextMeshProvider *this,
        Scaleform::Render::VertexOutput *verOut,
        const Scaleform::Render::TextMeshLayer *layer)
{
  Scaleform::Render::VertexOutput *v3; // ebx
  unsigned int Count; // edi
  Scaleform::Render::GlyphCache *pCache; // eax
  unsigned int v6; // esi
  bool (__thiscall *BeginOutput)(Scaleform::Render::VertexOutput *, const Scaleform::Render::VertexOutput::Fill *, unsigned int, const Scaleform::Render::Matrix2x4<float> *); // edx
  char result; // al
  int v9; // edi
  Scaleform::Render::TextMeshEntry *v10; // eax
  unsigned __int16 *pGlyph; // ecx
  int v12; // edx
  float v13; // ebx
  double v14; // st7
  int v15; // eax
  double v16; // st7
  int v17; // edx
  int v18; // eax
  int v19; // esi
  double x1; // st7
  int v21; // eax
  double y1; // st6
  double v23; // st5
  double v24; // st4
  double x2; // st3
  double v26; // rtt
  double v27; // st3
  double y2; // st4
  double v29; // rt2
  double v30; // st4
  float *v31; // eax
  unsigned int v33; // [esp+2Ch] [ebp-176Ch]
  int v34; // [esp+30h] [ebp-1768h]
  float v35; // [esp+30h] [ebp-1768h]
  float v36; // [esp+34h] [ebp-1764h]
  int v37; // [esp+38h] [ebp-1760h]
  int v38; // [esp+3Ch] [ebp-175Ch]
  unsigned int v40; // [esp+44h] [ebp-1754h]
  Scaleform::Render::Rect<float> tex; // [esp+48h] [ebp-1750h] BYREF
  Scaleform::Render::Rect<float> chr; // [esp+58h] [ebp-1740h] BYREF
  float ScaleV; // [esp+70h] [ebp-1728h]
  float ScaleU; // [esp+74h] [ebp-1724h]
  unsigned int v45; // [esp+78h] [ebp-1720h]
  _DWORD v46[7]; // [esp+7Ch] [ebp-171Ch] BYREF
  _WORD v47[384]; // [esp+98h] [ebp-1700h] BYREF
  float v48[1280]; // [esp+398h] [ebp-1400h] BYREF

  v3 = verOut;
  Count = layer->Count;
  v46[1] = 6 * Count;
  pCache = this->pCache;
  v6 = 0;
  v46[0] = 4 * Count;
  BeginOutput = verOut->BeginOutput;
  v46[2] = &Scaleform::Render::RasterGlyphVertex::Format;
  memset(&v46[3], 0, 16);
  ScaleU = pCache->ScaleU;
  ScaleV = pCache->ScaleV;
  v45 = Count;
  result = BeginOutput(
             verOut,
             (const Scaleform::Render::VertexOutput::Fill *)v46,
             1u,
             &Scaleform::Render::Matrix2x4<float>::Identity);
  if ( result )
  {
    v33 = 0;
    v37 = 0;
    v38 = 0;
    if ( Count )
    {
      v9 = 0;
      v40 = 0;
      while ( 1 )
      {
        if ( v6 >= 0x40 )
        {
          v3->SetVertices(v3, 0, 4 * v37, v48, 256u);
          v3->SetIndices(v3, 0, v40, v47, 384u);
          v37 += 64;
          v33 = 0;
          v40 += 384;
          v6 = 0;
        }
        v10 = &this->Entries.Data.Data[v38 + layer->Start];
        pGlyph = (unsigned __int16 *)v10->EntryData.RasterData.pGlyph;
        v12 = pGlyph[14];
        chr.x1 = v10->EntryData.RasterData.Coord[0];
        v13 = *(float *)&v10->mColor;
        chr.y1 = v10->EntryData.RasterData.Coord[1];
        pGlyph += 14;
        chr.x2 = v10->EntryData.RasterData.Coord[2];
        v14 = v10->EntryData.RasterData.Coord[3];
        v15 = pGlyph[1];
        chr.y2 = v14;
        v16 = (double)(v12 + 1);
        v17 = pGlyph[2];
        v34 = v15 + 1;
        v36 = v16 * ScaleU;
        v18 = pGlyph[3] - 2;
        v35 = (double)v34 * ScaleV;
        v19 = 6 * v6;
        tex.x1 = v36;
        tex.y1 = v35;
        tex.x2 = v36 + ScaleU * (double)(v17 - 2);
        tex.y2 = v35 + ScaleV * (double)v18;
        Scaleform::Render::TextMeshProvider::clipGlyphRect(this, &chr, &tex);
        x1 = chr.x1;
        v21 = 20 * v33;
        v48[v21] = chr.x1;
        v48[v21 + 2] = v13;
        y1 = chr.y1;
        v48[v21 + 1] = chr.y1;
        v23 = tex.x1;
        v48[v21 + 3] = tex.x1;
        v24 = tex.y1;
        v48[v21 + 4] = tex.y1;
        x2 = chr.x2;
        v48[v21 + 5] = chr.x2;
        v26 = x2;
        v48[v21 + 6] = y1;
        v27 = tex.x2;
        v48[v21 + 8] = tex.x2;
        v48[v21 + 7] = v13;
        ++v33;
        v48[v21 + 9] = v24;
        v48[v21 + 12] = v13;
        v48[v21 + 10] = v26;
        v47[v19] = v9;
        y2 = chr.y2;
        v47[v19 + 5] = v9;
        v48[v21 + 11] = y2;
        v47[v19 + 4] = v9 + 3;
        v29 = y2;
        v48[v21 + 13] = v27;
        v30 = tex.y2;
        v48[v21 + 14] = tex.y2;
        v31 = &v48[v21 + 15];
        v31[2] = v13;
        *v31 = x1;
        v31[1] = v29;
        v31[3] = v23;
        v31[4] = v30;
        v47[v19 + 1] = v9 + 1;
        v47[v19 + 2] = v9 + 2;
        v47[v19 + 3] = v9 + 2;
        v9 += 4;
        if ( ++v38 >= v45 )
          break;
        v3 = verOut;
        v6 = v33;
      }
      if ( v33 )
      {
        verOut->SetVertices(verOut, 0, 4 * v37, v48, 4 * v33);
        verOut->SetIndices(verOut, 0, 6 * v37, v47, 6 * v33);
        verOut->EndOutput(verOut);
        return 1;
      }
      v3 = verOut;
    }
    return Scaleform::Render::TextMeshProvider::generateNullVectorMesh(this, v3);
  }
  return result;
}
