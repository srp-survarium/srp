void __thiscall Scaleform::Render::TextMeshProvider::setMeshData(
        Scaleform::Render::TextMeshProvider *this,
        Scaleform::Render::TessBase *tess,
        Scaleform::Render::VertexOutput *verOut,
        const unsigned int *colors,
        Scaleform::Render::TextMeshProvider::VertexCountType *verCount)
{
  Scaleform::Render::TessBase *v5; // esi
  unsigned int v6; // ebx
  double v7; // st7
  char *v8; // esi
  float *v9; // edi
  double v10; // st7
  int v11; // eax
  bool v12; // c0
  bool v13; // c3
  double v14; // st7
  double v15; // st7
  unsigned int v16; // eax
  unsigned int v17; // edx
  int v18; // ecx
  unsigned __int8 v19; // al
  unsigned int v20; // edi
  unsigned int v21; // ebx
  unsigned int v22; // esi
  float v23; // [esp+34h] [ebp-9A8h]
  float v24; // [esp+34h] [ebp-9A8h]
  unsigned int i; // [esp+38h] [ebp-9A4h]
  unsigned int v26; // [esp+3Ch] [ebp-9A0h]
  Scaleform::Render::TessMesh v27; // [esp+40h] [ebp-99Ch] BYREF
  _BYTE v28[384]; // [esp+5Ch] [ebp-980h] BYREF
  _BYTE v29[4]; // [esp+1DCh] [ebp-800h] BYREF
  char v30; // [esp+1E0h] [ebp-7FCh] BYREF
  char v31; // [esp+4DCh] [ebp-500h] BYREF
  char v32; // [esp+4E0h] [ebp-4FCh] BYREF

  v5 = tess;
  tess->GetMesh(tess, 0, &v27);
  v6 = v5->GetVertices(v5, &v27, (Scaleform::Render::TessVertex *)&v31, 64u);
  for ( i = v6; v6; i = v6 )
  {
    v7 = 0.5;
    v8 = &v30;
    v9 = (float *)&v32;
    v26 = v6;
    while ( 1 )
    {
      v10 = *(v9 - 1) >= 0.0 ? v7 + *(v9 - 1) : *(v9 - 1) - v7;
      v23 = v10;
      v11 = (int)floor(v23);
      v12 = *v9 > 0.0;
      v13 = 0.0 == *v9;
      *((_WORD *)v8 - 2) = v11;
      v14 = *v9;
      v15 = v12 | (unsigned __int8)v13 ? v14 + 0.5 : v14 - 0.5;
      v24 = v15;
      *((_WORD *)v8 - 1) = (int)floor(v24);
      v16 = *((unsigned __int16 *)v9 + 6);
      if ( (v16 & 0x10) != 0 )
      {
        v6 = i;
        v17 = ((colors[*((unsigned __int16 *)v9 + 4) - 1] | colors[*((unsigned __int16 *)v9 + 5) - 1]) >> 1)
            & 0x7F7F7F7F;
      }
      else
      {
        v17 = colors[*((unsigned __int16 *)v9 + ((v16 >> 5) & 1) + 4) - 1];
      }
      v18 = v16 & 3;
      v19 = Scaleform::Render::Factors[((unsigned __int16)v16 >> 2) & 3];
      *(_DWORD *)v8 = v17;
      v8[4] = Scaleform::Render::Factors[v18];
      v8[5] = v19;
      v9 += 5;
      v8 += 12;
      if ( !--v26 )
        break;
      v7 = 0.5;
    }
    v5 = tess;
    verOut->SetVertices(verOut, 0, verCount->VStart, v29, v6);
    verCount->VStart += v6;
    v6 = tess->GetVertices(tess, &v27, (Scaleform::Render::TessVertex *)&v31, 64u);
  }
  v20 = 0;
  v21 = v5->GetMeshTriangleCount(v5, 0);
  if ( v21 )
  {
    do
    {
      v22 = 64;
      if ( v20 + 64 > v21 )
      {
        v22 = v21 - v20;
        if ( v21 == v20 )
          break;
      }
      tess->GetTrianglesI16(tess, 0, (unsigned __int16 *)v28, v20, v22);
      verOut->SetIndices(verOut, 0, 3 * verCount->IStart, (unsigned __int16 *)v28, 3 * v22);
      verCount->IStart += v22;
      v20 += v22;
    }
    while ( v20 < v21 );
  }
}
