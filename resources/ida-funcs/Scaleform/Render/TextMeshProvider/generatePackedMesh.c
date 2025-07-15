bool __thiscall Scaleform::Render::TextMeshProvider::generatePackedMesh(
        Scaleform::Render::TextMeshProvider *this,
        Scaleform::Render::VertexOutput *verOut,
        const Scaleform::Render::TextMeshLayer *layer)
{
  unsigned int Count; // ebx
  unsigned int Start; // eax
  unsigned int v5; // edi
  Scaleform::Render::TextMeshEntry *Data; // ecx
  int v7; // ecx
  int (__thiscall *v8)(int); // edx
  int v9; // eax
  bool v10; // zf
  const Scaleform::Render::VertexOutput::Fill *v11; // eax
  Scaleform::Render::VertexOutput *v12; // esi
  bool result; // al
  float *v14; // eax
  unsigned int v15; // ebx
  Scaleform::Render::TextMeshEntry *v16; // eax
  float *pGlyph; // ecx
  unsigned int mColor; // edx
  double v19; // st7
  int v20; // esi
  double x1; // st7
  float v22; // ecx
  int v23; // eax
  double y1; // st6
  double v25; // st5
  double v26; // st4
  double x2; // st3
  double v28; // rt0
  double v29; // st3
  double y2; // st4
  double v31; // rtt
  double v32; // st4
  float *v33; // eax
  unsigned int v34; // ebx
  float *v35; // eax
  double v36; // st6
  double v37; // st5
  double v38; // st4
  double v39; // st3
  double v40; // rt2
  double v41; // st3
  double v42; // st4
  double v43; // rt1
  double v44; // st4
  int v45; // eax
  __int16 v46; // cx
  float *v47; // eax
  bool v49; // [esp+2Dh] [ebp-277Dh]
  int v50; // [esp+2Eh] [ebp-277Ch]
  unsigned int v52; // [esp+36h] [ebp-2774h]
  Scaleform::Render::Rect<float> v53; // [esp+3Ah] [ebp-2770h] BYREF
  Scaleform::Render::Rect<float> v54; // [esp+4Ah] [ebp-2760h] BYREF
  int v55; // [esp+62h] [ebp-2748h]
  unsigned int v56; // [esp+66h] [ebp-2744h]
  unsigned int v57; // [esp+6Ah] [ebp-2740h]
  float v58; // [esp+6Eh] [ebp-273Ch]
  _DWORD v59[7]; // [esp+72h] [ebp-2738h] BYREF
  _DWORD v60[7]; // [esp+8Eh] [ebp-271Ch] BYREF
  _WORD v61[384]; // [esp+AAh] [ebp-2700h] BYREF
  float v62[1024]; // [esp+3AAh] [ebp-2400h] BYREF
  float v63[1280]; // [esp+13AAh] [ebp-1400h] BYREF

  Count = layer->Count;
  v60[1] = 6 * Count;
  v59[1] = 6 * Count;
  Start = layer->Start;
  v5 = 0;
  Data = this->Entries.Data.Data;
  v60[0] = 4 * Count;
  v59[0] = 4 * Count;
  v60[2] = &Scaleform::Render::RasterGlyphVertex::Format;
  memset(&v60[3], 0, 16);
  v59[2] = &Scaleform::Render::ImageGlyphVertex::Format;
  memset(&v59[3], 0, 16);
  v7 = *(_DWORD *)(Data[Start].EntryData.BackgroundData.BorderColor + 8);
  v8 = *(int (__thiscall **)(int))(*(_DWORD *)v7 + 16);
  v57 = Count;
  v9 = v8(v7);
  v49 = v9 == 9;
  v10 = v9 != 9;
  v11 = (const Scaleform::Render::VertexOutput::Fill *)v60;
  if ( v10 )
    v11 = (const Scaleform::Render::VertexOutput::Fill *)v59;
  v12 = verOut;
  result = verOut->BeginOutput(verOut, v11, 1u, &Scaleform::Render::Matrix2x4<float>::Identity);
  if ( result )
  {
    v50 = 0;
    v52 = 0;
    if ( Count )
    {
      v55 = 0;
      v56 = 0;
      while ( 1 )
      {
        if ( v5 >= 0x40 )
        {
          v14 = v63;
          if ( !v49 )
            v14 = v62;
          v12->SetVertices(v12, 0, 4 * v50, v14, 256u);
          v15 = v56;
          v12->SetIndices(v12, 0, v56, v61, 384u);
          v50 += 64;
          v5 = 0;
          v56 = v15 + 384;
        }
        v16 = &this->Entries.Data.Data[v52 + layer->Start];
        pGlyph = (float *)v16->EntryData.RasterData.pGlyph;
        mColor = v16->mColor;
        v53.x1 = pGlyph[4];
        pGlyph += 4;
        v19 = pGlyph[1];
        v58 = *(float *)&mColor;
        v53.y1 = v19;
        v20 = 6 * v5;
        v53.x2 = pGlyph[2];
        v53.y2 = pGlyph[3];
        v54.x1 = v16->EntryData.RasterData.Coord[0];
        v54.y1 = v16->EntryData.RasterData.Coord[1];
        v54.x2 = v16->EntryData.RasterData.Coord[2];
        v54.y2 = v16->EntryData.RasterData.Coord[3];
        Scaleform::Render::TextMeshProvider::clipGlyphRect(this, &v54, &v53);
        x1 = v54.x1;
        if ( v49 )
        {
          v22 = v58;
          v23 = 20 * v5;
          v63[v23] = v54.x1;
          v63[v23 + 2] = v22;
          y1 = v54.y1;
          v63[v23 + 1] = v54.y1;
          v25 = v53.x1;
          v63[v23 + 3] = v53.x1;
          v26 = v53.y1;
          v63[v23 + 4] = v53.y1;
          v63[v23 + 7] = v22;
          x2 = v54.x2;
          v63[v23 + 5] = v54.x2;
          v28 = x2;
          v63[v23 + 6] = y1;
          v29 = v53.x2;
          v63[v23 + 8] = v53.x2;
          v63[v23 + 9] = v26;
          v63[v23 + 12] = v22;
          v63[v23 + 10] = v28;
          y2 = v54.y2;
          v63[v23 + 11] = v54.y2;
          v31 = y2;
          v63[v23 + 13] = v29;
          v32 = v53.y2;
          v63[v23 + 14] = v53.y2;
          v33 = &v63[20 * v5 + 15];
          v33[2] = v22;
          *v33 = x1;
          v33[1] = v31;
          v33[3] = v25;
          v33[4] = v32;
        }
        else
        {
          v34 = v5 << 6;
          *(float *)((char *)v62 + v34) = v54.x1;
          v35 = &v62[16 * v5 + 12];
          v36 = v54.y1;
          *(float *)((char *)&v62[1] + v34) = v54.y1;
          v37 = v53.x1;
          *(float *)((char *)&v62[2] + v34) = v53.x1;
          v38 = v53.y1;
          *(float *)((char *)&v62[3] + v34) = v53.y1;
          v39 = v54.x2;
          *(float *)((char *)&v62[4] + v34) = v54.x2;
          v40 = v39;
          *(float *)((char *)&v62[5] + v34) = v36;
          v41 = v53.x2;
          *(float *)((char *)&v62[6] + v34) = v53.x2;
          *(float *)((char *)&v62[7] + v34) = v38;
          *(float *)((char *)&v62[8] + v34) = v40;
          v42 = v54.y2;
          *(float *)((char *)&v62[9] + v34) = v54.y2;
          v43 = v42;
          *(float *)((char *)&v62[10] + v34) = v41;
          v44 = v53.y2;
          *(float *)((char *)&v62[11] + v34) = v53.y2;
          *v35 = x1;
          v35[1] = v43;
          v35[2] = v37;
          v35[3] = v44;
        }
        v45 = v55;
        v46 = v55 + 2;
        v61[6 * v5 + 2] = v55 + 2;
        v61[6 * v5 + 3] = v46;
        v61[6 * v5 + 4] = v45 + 3;
        v61[6 * v5] = v45;
        v61[6 * v5++ + 5] = v45;
        v61[v20 + 1] = v45 + 1;
        ++v52;
        v55 = v45 + 4;
        if ( v52 >= v57 )
          break;
        v12 = verOut;
      }
      if ( v5 )
      {
        v47 = v63;
        if ( !v49 )
          v47 = v62;
        verOut->SetVertices(verOut, 0, 4 * v50, v47, 4 * v5);
        verOut->SetIndices(verOut, 0, 6 * v50, v61, 6 * v5);
        verOut->EndOutput(verOut);
        return 1;
      }
      v12 = verOut;
    }
    Scaleform::Render::TextMeshProvider::generateNullVectorMesh(this, v12);
    v12->EndOutput(v12);
    return 1;
  }
  return result;
}
