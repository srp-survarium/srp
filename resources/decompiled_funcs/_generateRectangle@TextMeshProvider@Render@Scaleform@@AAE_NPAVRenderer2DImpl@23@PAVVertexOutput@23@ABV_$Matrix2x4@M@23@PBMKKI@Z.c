char __thiscall Scaleform::Render::TextMeshProvider::generateRectangle(
        Scaleform::Render::TextMeshProvider *this,
        Scaleform::Render::Renderer2DImpl *ren,
        Scaleform::Render::VertexOutput *verOut,
        const Scaleform::Render::Matrix2x4<float> *mtx,
        const float *coord,
        unsigned int fillColor,
        unsigned int borderColor,
        char meshGenFlags)
{
  Scaleform::Render::Tessellator *p_mTess; // ebx
  double v9; // st7
  const Scaleform::Render::Matrix2x4<float> *v10; // esi
  float w; // [esp+782h] [ebp-BCh] BYREF
  float v13; // [esp+786h] [ebp-B8h] BYREF
  bool v14; // [esp+78Dh] [ebp-B1h]
  Scaleform::Render::CornerVertex v15; // [esp+78Eh] [ebp-B0h] BYREF
  Scaleform::Render::CornerVertex v16; // [esp+796h] [ebp-A8h]
  Scaleform::Render::CornerVertex v0; // [esp+79Eh] [ebp-A0h]
  Scaleform::Render::CornerVertex v18; // [esp+7A6h] [ebp-98h]
  Scaleform::Render::Matrix2x4<float> v19[2]; // [esp+7AEh] [ebp-90h] BYREF
  Scaleform::Render::TextMeshProvider *v20; // [esp+7F2h] [ebp-4Ch]
  Scaleform::Render::MeshGenerator *p_MeshGen; // [esp+7F6h] [ebp-48h]
  unsigned int v22[2]; // [esp+7FAh] [ebp-44h] BYREF
  _DWORD v23[7]; // [esp+802h] [ebp-3Ch] BYREF
  _BYTE v24[32]; // [esp+81Eh] [ebp-20h] BYREF

  v20 = this;
  v22[1] = borderColor;
  v22[0] = fillColor;
  p_MeshGen = &ren->MeshGen;
  Scaleform::Render::MeshGenerator::Clear(&ren->MeshGen);
  p_mTess = &ren->MeshGen.mTess;
  Scaleform::Render::Tessellator::SetFillRule(&ren->MeshGen.mTess, FillNonZero);
  Scaleform::Render::Tessellator::SetToleranceParam(&ren->MeshGen.mTess, &ren->Tolerances);
  qmemcpy(v19, &ren->Tolerances, sizeof(v19));
  if ( (meshGenFlags & 1) == 0 || (meshGenFlags & 2) != 0 )
    v9 = 0.0;
  else
    v9 = v19[1].M[1][2] * 0.5;
  w = v9;
  Scaleform::Render::Tessellator::SetEdgeAAWidth(p_mTess, w);
  v10 = mtx;
  v19[0].M[0][0] = *coord;
  v19[0].M[0][1] = coord[1];
  v19[0].M[0][2] = coord[2];
  v19[0].M[0][3] = coord[1];
  v19[0].M[1][0] = coord[2];
  v19[0].M[1][1] = coord[3];
  v19[0].M[1][2] = *coord;
  v19[0].M[1][3] = coord[3];
  w = v19[0].M[0][0];
  v19[0].M[0][0] = mtx->M[0][1] * v19[0].M[0][1] + v19[0].M[0][0] * mtx->M[0][0] + mtx->M[0][3];
  v19[0].M[0][1] = v19[0].M[0][1] * mtx->M[1][1] + w * mtx->M[1][0] + mtx->M[1][3];
  w = v19[0].M[0][2];
  v19[0].M[0][2] = mtx->M[0][1] * v19[0].M[0][3] + v19[0].M[0][2] * mtx->M[0][0] + mtx->M[0][3];
  v19[0].M[0][3] = v19[0].M[0][3] * mtx->M[1][1] + w * mtx->M[1][0] + mtx->M[1][3];
  w = v19[0].M[1][0];
  v19[0].M[1][0] = mtx->M[0][1] * v19[0].M[1][1] + v19[0].M[1][0] * mtx->M[0][0] + mtx->M[0][3];
  v19[0].M[1][1] = v19[0].M[1][1] * mtx->M[1][1] + w * mtx->M[1][0] + mtx->M[1][3];
  w = v19[0].M[1][2];
  v19[0].M[1][2] = mtx->M[0][1] * v19[0].M[1][3] + v19[0].M[1][2] * mtx->M[0][0] + mtx->M[0][3];
  v19[0].M[1][3] = v19[0].M[1][3] * mtx->M[1][1] + w * mtx->M[1][0] + mtx->M[1][3];
  if ( fillColor )
  {
    ((void (__thiscall *)(Scaleform::Render::Tessellator *, _DWORD, _DWORD))p_mTess->AddVertex)(
      p_mTess,
      LODWORD(v19[0].M[0][0]),
      LODWORD(v19[0].M[0][1]));
    ((void (__thiscall *)(Scaleform::Render::Tessellator *, _DWORD, _DWORD))p_mTess->AddVertex)(
      p_mTess,
      LODWORD(v19[0].M[0][2]),
      LODWORD(v19[0].M[0][3]));
    ((void (__thiscall *)(Scaleform::Render::Tessellator *, _DWORD, _DWORD))p_mTess->AddVertex)(
      p_mTess,
      LODWORD(v19[0].M[1][0]),
      LODWORD(v19[0].M[1][1]));
    ((void (__thiscall *)(Scaleform::Render::Tessellator *, _DWORD, _DWORD))p_mTess->AddVertex)(
      p_mTess,
      LODWORD(v19[0].M[1][2]),
      LODWORD(v19[0].M[1][3]));
    p_mTess->ClosePath(p_mTess);
    p_mTess->FinalizePath(p_mTess, 0, 1u, 0, 0);
  }
  if ( borderColor )
  {
    ((void (__thiscall *)(Scaleform::Render::Tessellator *, _DWORD, _DWORD))p_mTess->AddVertex)(
      p_mTess,
      LODWORD(v19[0].M[0][0]),
      LODWORD(v19[0].M[0][1]));
    ((void (__thiscall *)(Scaleform::Render::Tessellator *, _DWORD, _DWORD))p_mTess->AddVertex)(
      p_mTess,
      LODWORD(v19[0].M[0][2]),
      LODWORD(v19[0].M[0][3]));
    ((void (__thiscall *)(Scaleform::Render::Tessellator *, _DWORD, _DWORD))p_mTess->AddVertex)(
      p_mTess,
      LODWORD(v19[0].M[1][0]),
      LODWORD(v19[0].M[1][1]));
    ((void (__thiscall *)(Scaleform::Render::Tessellator *, _DWORD, _DWORD))p_mTess->AddVertex)(
      p_mTess,
      LODWORD(v19[0].M[1][2]),
      LODWORD(v19[0].M[1][3]));
    p_mTess->ClosePath(p_mTess);
    p_mTess->FinalizePath(p_mTess, 0, 2u, 0, 0);
    v16.x = v19[0].M[0][0];
    v16.y = v19[0].M[0][1];
    v0.x = v19[0].M[0][2];
    v0.y = v19[0].M[0][3];
    v15.x = v19[0].M[1][0];
    v15.y = v19[0].M[1][1];
    v18.x = v19[0].M[1][2];
    v18.y = v19[0].M[1][3];
    Scaleform::Render::calcMiter_Scaleform::Render::CornerVertex_(
      &w,
      &v13,
      *(Scaleform::Render::CornerVertex *)&v19[0].M[0][2],
      *(Scaleform::Render::CornerVertex *)&v19[0].M[0][0],
      *(Scaleform::Render::CornerVertex *)&v19[0].M[1][2],
      1.0);
    ((void (__thiscall *)(Scaleform::Render::Tessellator *, float, _DWORD))p_mTess->AddVertex)(
      p_mTess,
      COERCE_FLOAT(LODWORD(w)),
      LODWORD(v13));
    Scaleform::Render::calcMiter_Scaleform::Render::CornerVertex_(&w, &v13, v16, v18, v15, 1.0);
    ((void (__thiscall *)(Scaleform::Render::Tessellator *, float, _DWORD))p_mTess->AddVertex)(
      p_mTess,
      COERCE_FLOAT(LODWORD(w)),
      LODWORD(v13));
    Scaleform::Render::calcMiter_Scaleform::Render::CornerVertex_(&w, &v13, v18, v15, v0, 1.0);
    ((void (__thiscall *)(Scaleform::Render::Tessellator *, float, _DWORD))p_mTess->AddVertex)(
      p_mTess,
      COERCE_FLOAT(LODWORD(w)),
      LODWORD(v13));
    Scaleform::Render::calcMiter_Scaleform::Render::CornerVertex_(&w, &v13, v15, v0, v16, 1.0);
    ((void (__thiscall *)(Scaleform::Render::Tessellator *, float, _DWORD))p_mTess->AddVertex)(
      p_mTess,
      COERCE_FLOAT(LODWORD(w)),
      LODWORD(v13));
    p_mTess->ClosePath(p_mTess);
    p_mTess->FinalizePath(p_mTess, 0, 2u, 0, 0);
    v10 = mtx;
  }
  Scaleform::Render::Tessellator::Tessellate(p_mTess, 0);
  v19[0].M[0][0] = 1.0;
  v19[0].M[0][1] = 0.0;
  v19[0].M[0][2] = 0.0;
  v19[0].M[0][3] = 0.0;
  v19[0].M[1][0] = 0.0;
  v19[0].M[1][2] = 0.0;
  v19[0].M[1][3] = 0.0;
  v19[0].M[1][1] = 1.0;
  Scaleform::Render::Matrix2x4<float>::SetInverse(v19, v10);
  p_mTess->Transform(p_mTess, v19);
  ((void (__thiscall *)(Scaleform::Render::Tessellator *, _BYTE *, _DWORD, _DWORD, _DWORD, _DWORD))p_mTess->StretchTo)(
    p_mTess,
    v24,
    -32764.0,
    -32764.0,
    32764.0,
    32764.0);
  v23[0] = p_mTess->GetMeshVertexCount(p_mTess, 0);
  v23[1] = 3 * p_mTess->GetMeshTriangleCount(p_mTess, 0);
  v23[2] = &Scaleform::Render::VertexXY16iCF32::Format;
  memset(&v23[3], 0, 16);
  if ( !v23[0] )
    return Scaleform::Render::TextMeshProvider::generateNullVectorMesh(v20, verOut);
  v14 = verOut->BeginOutput(
          verOut,
          (const Scaleform::Render::VertexOutput::Fill *)v23,
          1u,
          (const Scaleform::Render::Matrix2x4<float> *)v24);
  if ( v14 )
  {
    v15.x = 0.0;
    v15.y = 0.0;
    Scaleform::Render::TextMeshProvider::setMeshData(
      v20,
      p_mTess,
      verOut,
      v22,
      (Scaleform::Render::TextMeshProvider::VertexCountType *)&v15);
    verOut->EndOutput(verOut);
  }
  Scaleform::Render::MeshGenerator::Clear(p_MeshGen);
  return v14;
}
