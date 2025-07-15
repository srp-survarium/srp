char __thiscall Scaleform::Render::TextMeshProvider::generateSelection(
        Scaleform::Render::TextMeshProvider *this,
        Scaleform::Render::Renderer2DImpl *ren,
        Scaleform::Render::VertexOutput *verOut,
        const Scaleform::Render::TextMeshLayer *layer,
        const Scaleform::Render::Matrix2x4<float> *mtx,
        char meshGenFlags)
{
  Scaleform::Render::Tessellator *p_mTess; // ebx
  double v7; // st7
  Scaleform::Render::TextMeshEntry *v8; // esi
  bool v9; // zf
  double x1; // st7
  double y1; // st6
  void (__thiscall *AddVertex)(struct Scaleform::Render::Tessellator *, float, float); // eax
  void (__thiscall *v13)(struct Scaleform::Render::Tessellator *, float, float); // eax
  void (__thiscall *v14)(struct Scaleform::Render::Tessellator *, float, float); // eax
  void (__thiscall *v15)(struct Scaleform::Render::Tessellator *, float, float); // eax
  int v16; // eax
  bool (__thiscall *BeginOutput)(Scaleform::Render::VertexOutput *, const Scaleform::Render::VertexOutput::Fill *, unsigned int, const Scaleform::Render::Matrix2x4<float> *); // edx
  unsigned int param_60; // [esp+64Ah] [ebp-104h]
  unsigned int param_60a; // [esp+64Ah] [ebp-104h]
  unsigned int param_60b; // [esp+64Ah] [ebp-104h]
  unsigned int param_60c; // [esp+64Ah] [ebp-104h]
  char NullVectorMesh; // [esp+65Dh] [ebp-F1h]
  Scaleform::Render::TextMeshProvider::VertexCountType v24; // [esp+65Eh] [ebp-F0h] BYREF
  float v25; // [esp+666h] [ebp-E8h]
  Scaleform::Render::TextMeshProvider *v26; // [esp+66Ah] [ebp-E4h]
  Scaleform::Render::Rect<float> v27; // [esp+66Eh] [ebp-E0h] BYREF
  int v28; // [esp+67Eh] [ebp-D0h]
  int v29; // [esp+682h] [ebp-CCh]
  int v30; // [esp+686h] [ebp-C8h]
  Scaleform::Render::MeshGenerator *p_MeshGen; // [esp+69Ah] [ebp-B4h]
  Scaleform::Render::Matrix2x4<float> v32; // [esp+69Eh] [ebp-B0h] BYREF
  Scaleform::ArrayStaticBuffPOD<unsigned long,16,2> v33; // [esp+6BEh] [ebp-90h] BYREF
  float v34[16]; // [esp+70Eh] [ebp-40h] BYREF

  v26 = this;
  p_MeshGen = &ren->MeshGen;
  Scaleform::Render::MeshGenerator::Clear(&ren->MeshGen);
  p_mTess = &ren->MeshGen.mTess;
  Scaleform::Render::Tessellator::SetFillRule(&ren->MeshGen.mTess, FillNonZero);
  Scaleform::Render::Tessellator::SetToleranceParam(&ren->MeshGen.mTess, &ren->Tolerances);
  v33.pHeap = Scaleform::Memory::pGlobalHeap;
  v33.Reserved = 16;
  v33.Size = 0;
  v33.Data = v33.Static;
  qmemcpy(v34, &ren->Tolerances, sizeof(v34));
  if ( (meshGenFlags & 1) == 0 || (meshGenFlags & 2) != 0 )
    v7 = 0.0;
  else
    v7 = v34[14] * 0.5;
  v25 = v7;
  Scaleform::Render::Tessellator::SetEdgeAAWidth(p_mTess, v25);
  v25 = 0.0;
  if ( layer->Count )
  {
    do
    {
      v8 = &v26->Entries.Data.Data[LODWORD(v25) + layer->Start];
      v9 = (v26->Flags & 8) == 0;
      v27.x1 = v8->EntryData.RasterData.Coord[0];
      v27.y1 = v8->EntryData.RasterData.Coord[1];
      v27.x2 = v8->EntryData.RasterData.Coord[2];
      v27.y2 = v8->EntryData.RasterData.Coord[3];
      if ( !v9 )
        Scaleform::Render::Rect<float>::Intersect(
          &v27,
          v26->ClipBox.x1,
          v26->ClipBox.y1,
          v26->ClipBox.x2,
          v26->ClipBox.y2);
      x1 = v27.x1;
      if ( v27.x2 > (double)v27.x1 )
      {
        y1 = v27.y1;
        if ( v27.y2 > (double)v27.y1 )
        {
          AddVertex = p_mTess->AddVertex;
          *(float *)&v24.VStart = mtx->M[1][1] * y1 + mtx->M[1][0] * x1 + mtx->M[1][3];
          param_60 = v24.VStart;
          *(float *)&v24.VStart = x1 * mtx->M[0][0] + y1 * mtx->M[0][1] + mtx->M[0][3];
          ((void (__thiscall *)(Scaleform::Render::Tessellator *, unsigned int, unsigned int))AddVertex)(
            p_mTess,
            v24.VStart,
            param_60);
          v13 = p_mTess->AddVertex;
          *(float *)&v24.VStart = mtx->M[1][0] * v27.x2 + mtx->M[1][1] * v27.y1 + mtx->M[1][3];
          param_60a = v24.VStart;
          *(float *)&v24.VStart = v27.x2 * mtx->M[0][0] + v27.y1 * mtx->M[0][1] + mtx->M[0][3];
          ((void (__thiscall *)(Scaleform::Render::Tessellator *, unsigned int, unsigned int))v13)(
            p_mTess,
            v24.VStart,
            param_60a);
          v14 = p_mTess->AddVertex;
          *(float *)&v24.VStart = mtx->M[1][0] * v27.x2 + mtx->M[1][1] * v27.y2 + mtx->M[1][3];
          param_60b = v24.VStart;
          *(float *)&v24.VStart = v27.x2 * mtx->M[0][0] + v27.y2 * mtx->M[0][1] + mtx->M[0][3];
          ((void (__thiscall *)(Scaleform::Render::Tessellator *, unsigned int, unsigned int))v14)(
            p_mTess,
            v24.VStart,
            param_60b);
          v15 = p_mTess->AddVertex;
          *(float *)&v24.VStart = mtx->M[1][0] * v27.x1 + mtx->M[1][1] * v27.y2 + mtx->M[1][3];
          param_60c = v24.VStart;
          *(float *)&v24.VStart = v27.x1 * mtx->M[0][0] + v27.y2 * mtx->M[0][1] + mtx->M[0][3];
          ((void (__thiscall *)(Scaleform::Render::Tessellator *, unsigned int, unsigned int))v15)(
            p_mTess,
            v24.VStart,
            param_60c);
        }
      }
      Scaleform::ArrayStaticBuffPOD<unsigned int,16,2>::PushBack(&v33, &v8->mColor);
      p_mTess->ClosePath(p_mTess);
      p_mTess->FinalizePath(p_mTess, 0, LODWORD(v25) + 1, 0, 0);
      ++LODWORD(v25);
    }
    while ( LODWORD(v25) < layer->Count );
  }
  Scaleform::Render::Tessellator::Tessellate(p_mTess, 0);
  if ( p_mTess->GetMeshCount(p_mTess) && p_mTess->GetVertexCount(p_mTess) )
  {
    v32.M[0][0] = 1.0;
    v32.M[0][1] = 0.0;
    v32.M[0][2] = 0.0;
    v32.M[0][3] = 0.0;
    v32.M[1][0] = 0.0;
    v32.M[1][2] = 0.0;
    v32.M[1][3] = 0.0;
    v32.M[1][1] = 1.0;
    Scaleform::Render::Matrix2x4<float>::SetInverse(&v32, mtx);
    p_mTess->Transform(p_mTess, &v32);
    ((void (__thiscall *)(Scaleform::Render::Tessellator *, float *, _DWORD, _DWORD, _DWORD, _DWORD))p_mTess->StretchTo)(
      p_mTess,
      v34,
      -32764.0,
      -32764.0,
      32764.0,
      32764.0);
    LODWORD(v27.x1) = p_mTess->GetMeshVertexCount(p_mTess, 0);
    v16 = p_mTess->GetMeshTriangleCount(p_mTess, 0);
    BeginOutput = verOut->BeginOutput;
    LODWORD(v27.y1) = 3 * v16;
    LODWORD(v27.x2) = &Scaleform::Render::VertexXY16iCF32::Format;
    v27.y2 = 0.0;
    v28 = 0;
    v29 = 0;
    v30 = 0;
    NullVectorMesh = BeginOutput(
                       verOut,
                       (const Scaleform::Render::VertexOutput::Fill *)&v27,
                       1u,
                       (const Scaleform::Render::Matrix2x4<float> *)v34);
    if ( NullVectorMesh )
    {
      v24.VStart = 0;
      v24.IStart = 0;
      Scaleform::Render::TextMeshProvider::setMeshData(v26, p_mTess, verOut, v33.Data, &v24);
      verOut->EndOutput(verOut);
    }
  }
  else
  {
    NullVectorMesh = Scaleform::Render::TextMeshProvider::generateNullVectorMesh(v26, verOut);
  }
  Scaleform::Render::MeshGenerator::Clear(p_MeshGen);
  if ( v33.Data != v33.Static )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v33.Data);
  return NullVectorMesh;
}
