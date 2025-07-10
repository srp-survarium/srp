char __thiscall Scaleform::Render::VectorGlyphShape::GetData(
        Scaleform::Render::VectorGlyphShape *this,
        Scaleform::Render::MeshBase *mesh,
        Scaleform::Render::VertexOutput *verOut,
        char meshGenFlags)
{
  Scaleform::Render::Renderer2DImpl *pRenderer2D; // esi
  double v7; // st7
  Scaleform::Render::Tessellator *p_mTess; // edi
  int v9; // eax
  int v10; // ecx
  double v11; // st7
  int i; // eax
  int j; // eax
  Scaleform::Render::Tessellator_vtbl *v14; // ebx
  Scaleform::Render::Matrix2x4<float> *Inverse; // eax
  int v16; // eax
  Scaleform::Render::VertexOutput *v17; // ebx
  bool (__thiscall *BeginOutput)(Scaleform::Render::VertexOutput *, const Scaleform::Render::VertexOutput::Fill *, unsigned int, const Scaleform::Render::Matrix2x4<float> *); // edx
  int v19; // eax
  char *v20; // esi
  float *v21; // ebx
  double v22; // st7
  double v23; // st7
  int v24; // eax
  bool v25; // c0
  bool v26; // c3
  double v27; // st7
  double v28; // st7
  unsigned __int8 v29; // dl
  unsigned __int8 v30; // al
  unsigned int v31; // esi
  unsigned int v32; // eax
  int v33; // ebx
  char v34; // [esp+9Dh] [ebp-1431h]
  char NullVectorMesh; // [esp+9Dh] [ebp-1431h]
  float w; // [esp+9Eh] [ebp-1430h]
  float v37; // [esp+9Eh] [ebp-1430h]
  float v38; // [esp+9Eh] [ebp-1430h]
  float v39; // [esp+9Eh] [ebp-1430h]
  float v40; // [esp+9Eh] [ebp-1430h]
  float v41; // [esp+9Eh] [ebp-1430h]
  float v42; // [esp+9Eh] [ebp-1430h]
  float v43; // [esp+9Eh] [ebp-1430h]
  unsigned int v44; // [esp+9Eh] [ebp-1430h]
  unsigned int v45; // [esp+9Eh] [ebp-1430h]
  Scaleform::Render::Matrix2x4<float> *p_ViewMatrix; // [esp+A2h] [ebp-142Ch]
  unsigned int v47; // [esp+A2h] [ebp-142Ch]
  float x2; // [esp+A6h] [ebp-1428h] BYREF
  float y2; // [esp+AAh] [ebp-1424h]
  float x3; // [esp+AEh] [ebp-1420h]
  float v51; // [esp+B2h] [ebp-141Ch]
  float v52; // [esp+B6h] [ebp-1418h]
  float v53; // [esp+BAh] [ebp-1414h]
  float v54; // [esp+BEh] [ebp-1410h] BYREF
  int v55; // [esp+C2h] [ebp-140Ch]
  Scaleform::Render::VertexFormat *v56; // [esp+C6h] [ebp-1408h]
  float v57; // [esp+CAh] [ebp-1404h]
  float v58; // [esp+CEh] [ebp-1400h]
  float v59; // [esp+D2h] [ebp-13FCh]
  unsigned int v60; // [esp+D6h] [ebp-13F8h]
  float v61; // [esp+DAh] [ebp-13F4h]
  float v62; // [esp+DEh] [ebp-13F0h]
  Scaleform::Render::MeshGenerator *p_MeshGen; // [esp+E2h] [ebp-13ECh]
  int v64; // [esp+E6h] [ebp-13E8h]
  _DWORD v65[13]; // [esp+EAh] [ebp-13E4h] BYREF
  char v66; // [esp+11Eh] [ebp-13B0h]
  _DWORD v67[3]; // [esp+122h] [ebp-13ACh] BYREF
  Scaleform::Render::ToleranceParams param; // [esp+12Eh] [ebp-13A0h] BYREF
  Scaleform::Render::TessMesh v69; // [esp+172h] [ebp-135Ch] BYREF
  Scaleform::Render::Matrix2x4<float> v70; // [esp+18Eh] [ebp-1340h] BYREF
  Scaleform::Render::Matrix2x4<float> result; // [esp+1AEh] [ebp-1320h] BYREF
  unsigned __int16 v72[384]; // [esp+1CEh] [ebp-1300h] BYREF
  char v73[4]; // [esp+4CEh] [ebp-1000h] BYREF
  char v74; // [esp+4D2h] [ebp-FFCh] BYREF
  char v75; // [esp+ACEh] [ebp-A00h] BYREF
  char v76; // [esp+AD2h] [ebp-9FCh] BYREF

  pRenderer2D = mesh->pRenderer2D;
  p_ViewMatrix = &mesh->ViewMatrix;
  if ( (*(unsigned __int8 (__thiscall **)(_DWORD))(**(_DWORD **)&this->Key.GlyphIndex + 4))(*(_DWORD *)&this->Key.GlyphIndex) )
    return Scaleform::Render::TextMeshProvider::generateNullVectorMesh(
             (Scaleform::Render::TextMeshProvider *)(&this[-1].pCache + 2),
             verOut);
  p_MeshGen = &pRenderer2D->MeshGen;
  Scaleform::Render::MeshGenerator::Clear(&pRenderer2D->MeshGen);
  qmemcpy(&param, &pRenderer2D->Tolerances, sizeof(param));
  param.CurveTolerance = param.CurveTolerance * 2.0;
  param.CollinearityTolerance = 2.0 * param.CollinearityTolerance;
  if ( (meshGenFlags & 1) == 0 || (meshGenFlags & 2) != 0 )
    v7 = 0.0;
  else
    v7 = param.EdgeAAScale * 0.5;
  w = v7;
  p_mTess = &p_MeshGen->mTess;
  Scaleform::Render::Tessellator::SetEdgeAAWidth(&p_MeshGen->mTess, w);
  Scaleform::Render::Tessellator::SetFillRule(&p_MeshGen->mTess, FillNonZero);
  v9 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)&this->Key.GlyphIndex + 24))(*(_DWORD *)&this->Key.GlyphIndex);
  *(float *)&v65[12] = 1.0;
  v10 = *(_DWORD *)&this->Key.GlyphIndex;
  v65[0] = v9;
  v11 = p_ViewMatrix->M[0][0];
  memset(&v65[1], 0, 44);
  v54 = v11;
  v55 = SLODWORD(mesh->ViewMatrix.M[0][1]);
  v57 = mesh->ViewMatrix.M[0][3];
  v58 = mesh->ViewMatrix.M[1][0];
  v59 = mesh->ViewMatrix.M[1][1];
  v61 = mesh->ViewMatrix.M[1][3];
  v66 = 0;
  v34 = 1;
  for ( i = (*(int (__thiscall **)(int, _DWORD *, float *, _DWORD *))(*(_DWORD *)v10 + 32))(v10, v65, &x2, v67);
        i;
        i = (*(int (__thiscall **)(_DWORD, _DWORD *, float *, _DWORD *))(**(_DWORD **)&this->Key.GlyphIndex + 32))(
              *(_DWORD *)&this->Key.GlyphIndex,
              v65,
              &x2,
              v67) )
  {
    if ( !v34 && i == 2 )
      break;
    v34 = 0;
    if ( v67[0] == v67[1] )
    {
      (*(void (__thiscall **)(_DWORD, _DWORD *))(**(_DWORD **)&this->Key.GlyphIndex + 40))(
        *(_DWORD *)&this->Key.GlyphIndex,
        v65);
    }
    else
    {
      v37 = x2;
      x2 = x2 * v54 + *(float *)&v55 * y2 + v57;
      y2 = y2 * v59 + v58 * v37 + v61;
      p_mTess->AddVertex(p_mTess, COERCE_FLOAT(LODWORD(x2)), COERCE_FLOAT(LODWORD(y2)));
      for ( j = (*(int (__thiscall **)(_DWORD, _DWORD *, float *))(**(_DWORD **)&this->Key.GlyphIndex + 36))(
                  *(_DWORD *)&this->Key.GlyphIndex,
                  v65,
                  &x2);
            j;
            j = (*(int (__thiscall **)(_DWORD, _DWORD *, float *))(**(_DWORD **)&this->Key.GlyphIndex + 36))(
                  *(_DWORD *)&this->Key.GlyphIndex,
                  v65,
                  &x2) )
      {
        switch ( j )
        {
          case 1:
            v38 = x2;
            x2 = x2 * v54 + *(float *)&v55 * y2 + v57;
            y2 = y2 * v59 + v58 * v38 + v61;
            p_mTess->AddVertex(p_mTess, COERCE_FLOAT(LODWORD(x2)), COERCE_FLOAT(LODWORD(y2)));
            break;
          case 2:
            v39 = x2;
            x2 = x2 * v54 + *(float *)&v55 * y2 + v57;
            y2 = y2 * v59 + v58 * v39 + v61;
            v40 = x3;
            x3 = v57 + x3 * v54 + *(float *)&v55 * v51;
            v51 = v58 * v40 + v51 * v59 + v61;
            Scaleform::Render::TessellateQuadCurve(p_mTess, &param, x2, y2, x3, v51);
            break;
          case 3:
            v41 = x2;
            x2 = x2 * v54 + *(float *)&v55 * y2 + v57;
            y2 = y2 * v59 + v58 * v41 + v61;
            v42 = x3;
            x3 = v54 * x3 + *(float *)&v55 * v51 + v57;
            v51 = v59 * v51 + v58 * v42 + v61;
            v43 = v52;
            v52 = v57 + v52 * v54 + *(float *)&v55 * v53;
            v53 = v61 + v53 * v59 + v58 * v43;
            Scaleform::Render::TessellateCubicCurve(p_mTess, &param, x2, y2, x3, v51, v52, v53);
            break;
        }
      }
      p_mTess->FinalizePath(p_mTess, 1u, 0, 0, 0);
    }
  }
  Scaleform::Render::Tessellator::Tessellate(p_mTess, 0);
  if ( !p_mTess->GetMeshCount(p_mTess) || !p_mTess->GetVertexCount(p_mTess) )
  {
    NullVectorMesh = Scaleform::Render::TextMeshProvider::generateNullVectorMesh(
                       (Scaleform::Render::TextMeshProvider *)(&this[-1].pCache + 2),
                       verOut);
    goto LABEL_46;
  }
  v14 = p_mTess->__vftable;
  Inverse = Scaleform::Render::Matrix2x4<float>::GetInverse(p_ViewMatrix, &result);
  v14->Transform(p_mTess, Inverse);
  ((void (__thiscall *)(Scaleform::Render::Tessellator *, Scaleform::Render::Matrix2x4<float> *, _DWORD, _DWORD, _DWORD, _DWORD))p_mTess->StretchTo)(
    p_mTess,
    &v70,
    -32764.0,
    -32764.0,
    32764.0,
    32764.0);
  v54 = COERCE_FLOAT(p_mTess->GetMeshVertexCount(p_mTess, 0));
  v16 = p_mTess->GetMeshTriangleCount(p_mTess, 0);
  v17 = verOut;
  BeginOutput = verOut->BeginOutput;
  v55 = 3 * v16;
  v56 = &Scaleform::Render::VertexXY16iCF32::Format;
  v57 = 0.0;
  v58 = 0.0;
  v59 = 0.0;
  v60 = 0;
  NullVectorMesh = BeginOutput(verOut, (const Scaleform::Render::VertexOutput::Fill *)&v54, 1u, &v70);
  if ( !NullVectorMesh )
  {
LABEL_46:
    Scaleform::Render::MeshGenerator::Clear(p_MeshGen);
    return NullVectorMesh;
  }
  p_mTess->GetMesh(p_mTess, 0, &v69);
  v44 = 0;
  v19 = p_mTess->GetVertices(p_mTess, &v69, (Scaleform::Render::TessVertex *)&v75, 128u);
  v47 = v19;
  if ( v19 )
  {
    while ( 1 )
    {
      v20 = &v74;
      v21 = (float *)&v76;
      v64 = v19;
      do
      {
        v22 = *(v21 - 1);
        if ( v22 >= 0.0 )
          v23 = v22 + 0.5;
        else
          v23 = v22 - 0.5;
        v62 = v23;
        v24 = (int)floor(v62);
        v25 = *v21 > 0.0;
        v26 = 0.0 == *v21;
        *((_WORD *)v20 - 2) = v24;
        v27 = *v21;
        if ( v25 || v26 )
          v28 = v27 + 0.5;
        else
          v28 = v27 - 0.5;
        v62 = v28;
        *((_WORD *)v20 - 1) = (int)floor(v62);
        v29 = Scaleform::Render::Factors[(_WORD)v21[3] & 3];
        v30 = Scaleform::Render::Factors[(*((unsigned __int16 *)v21 + 6) >> 2) & 3];
        *(_DWORD *)v20 = -1;
        v20[4] = v29;
        v20[5] = v30;
        v21 += 5;
        v20 += 12;
        --v64;
      }
      while ( v64 );
      v17 = verOut;
      verOut->SetVertices(verOut, 0, v44, v73, v47);
      v44 += v47;
      v47 = p_mTess->GetVertices(p_mTess, &v69, (Scaleform::Render::TessVertex *)&v75, 128u);
      if ( !v47 )
        break;
      v19 = v47;
    }
  }
  v31 = 0;
  v32 = p_mTess->GetMeshTriangleCount(p_mTess, v60);
  v45 = v32;
  if ( v32 )
  {
    while ( 1 )
    {
      v33 = 128;
      if ( v31 + 128 > v32 )
      {
        v33 = v32 - v31;
        if ( v32 == v31 )
          break;
      }
      p_mTess->GetTrianglesI16(p_mTess, v60, v72, v31, v33);
      verOut->SetIndices(verOut, 0, 3 * v31, v72, 3 * v33);
      v31 += v33;
      if ( v31 >= v45 )
        break;
      v32 = v45;
    }
    v17 = verOut;
  }
  v17->EndOutput(v17);
  Scaleform::Render::MeshGenerator::Clear(p_MeshGen);
  return NullVectorMesh;
}
