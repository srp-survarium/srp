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
  unsigned int *p_Color; // esi
  float *p_y; // edi
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
  unsigned int retVer; // [esp+38h] [ebp-9A4h]
  unsigned int v26; // [esp+3Ch] [ebp-9A0h]
  Scaleform::Render::TessMesh tessMesh; // [esp+40h] [ebp-99Ch] BYREF
  unsigned __int16 tri[192]; // [esp+5Ch] [ebp-980h] BYREF
  Scaleform::Render::VertexXY16iCF32 vertices[64]; // [esp+1DCh] [ebp-800h] BYREF
  Scaleform::Render::TessVertex tessVer[64]; // [esp+4DCh] [ebp-500h] BYREF

  v5 = tess;
  tess->GetMesh(tess, 0, &tessMesh);
  v6 = v5->GetVertices(v5, &tessMesh, tessVer, 64u);
  for ( retVer = v6; v6; retVer = v6 )
  {
    v7 = 0.5;
    p_Color = &vertices[0].Color;
    p_y = &tessVer[0].y;
    v26 = v6;
    while ( 1 )
    {
      v10 = *(p_y - 1) >= 0.0 ? v7 + *(p_y - 1) : *(p_y - 1) - v7;
      v23 = v10;
      v11 = (int)floor(v23);
      v12 = *p_y > 0.0;
      v13 = 0.0 == *p_y;
      *((_WORD *)p_Color - 2) = v11;
      v14 = *p_y;
      v15 = v12 | (unsigned __int8)v13 ? v14 + 0.5 : v14 - 0.5;
      v24 = v15;
      *((_WORD *)p_Color - 1) = (int)floor(v24);
      v16 = *((unsigned __int16 *)p_y + 6);
      if ( (v16 & 0x10) != 0 )
      {
        v6 = retVer;
        v17 = ((colors[*((unsigned __int16 *)p_y + 4) - 1] | colors[*((unsigned __int16 *)p_y + 5) - 1]) >> 1)
            & 0x7F7F7F7F;
      }
      else
      {
        v17 = colors[*((unsigned __int16 *)p_y + ((v16 >> 5) & 1) + 4) - 1];
      }
      v18 = v16 & 3;
      v19 = Scaleform::Render::Factors[((unsigned __int16)v16 >> 2) & 3];
      *p_Color = v17;
      *((_BYTE *)p_Color + 4) = Scaleform::Render::Factors[v18];
      *((_BYTE *)p_Color + 5) = v19;
      p_y += 5;
      p_Color += 3;
      if ( !--v26 )
        break;
      v7 = 0.5;
    }
    v5 = tess;
    verOut->SetVertices(verOut, 0, verCount->VStart, vertices, v6);
    verCount->VStart += v6;
    v6 = tess->GetVertices(tess, &tessMesh, tessVer, 64u);
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
      tess->GetTrianglesI16(tess, 0, tri, v20, v22);
      verOut->SetIndices(verOut, 0, 3 * verCount->IStart, tri, 3 * v22);
      verCount->IStart += v22;
      v20 += v22;
    }
    while ( v20 < v21 );
  }
}
