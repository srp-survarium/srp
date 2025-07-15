bool __userpurge Scaleform::Render::ShapeMeshProvider::tessellateFill@<al>(
        Scaleform::Render::ShapeMeshProvider *this@<ecx>,
        const Scaleform::Render::ToleranceParams *a2@<edi>,
        const Scaleform::Render::Scale9GridInfo *s9g,
        unsigned int drawLayerIdx,
        Scaleform::Render::MeshBase *pmesh,
        Scaleform::Render::VertexOutput *pout,
        unsigned int meshGenFlags)
{
  Scaleform::Render::Renderer2DImpl *pRenderer2D; // edx
  Scaleform::Render::Matrix2x4<float> *p_ViewMatrix; // eax
  Scaleform::Render::MeshGenerator *p_MeshGen; // ebx
  double v10; // st7
  int p_mTess; // edi
  double v13; // st7
  float w; // [esp+0h] [ebp-104h]
  const Scaleform::Render::ToleranceParams *v15; // [esp+4h] [ebp-100h]
  bool v16; // [esp+1Fh] [ebp-E5h]
  Scaleform::Render::TransformerBase *v18; // [esp+24h] [ebp-E0h]
  float MorphRatio; // [esp+28h] [ebp-DCh]
  unsigned int v20; // [esp+2Ch] [ebp-D8h]
  unsigned int v21; // [esp+30h] [ebp-D4h]
  Scaleform::Render::Matrix2x4<float> m2; // [esp+34h] [ebp-D0h] BYREF
  float v23; // [esp+5Ch] [ebp-A8h]
  unsigned int v24; // [esp+60h] [ebp-A4h]
  void **v25; // [esp+64h] [ebp-A0h] BYREF
  const Scaleform::Render::Scale9GridInfo *v26; // [esp+68h] [ebp-9Ch]
  void **v27; // [esp+6Ch] [ebp-98h] BYREF
  Scaleform::Render::Matrix2x4<float> *p_m2; // [esp+70h] [ebp-94h]
  Scaleform::Render::ToleranceParams param; // [esp+74h] [ebp-90h] BYREF
  float key[20]; // [esp+B4h] [ebp-50h] BYREF
  int savedregs; // [esp+104h] [ebp+0h] BYREF

  pRenderer2D = pmesh->pRenderer2D;
  MorphRatio = pmesh->MorphRatio;
  p_ViewMatrix = &pmesh->ViewMatrix;
  v15 = a2;
  qmemcpy(&param, &pRenderer2D->Tolerances, sizeof(param));
  m2.M[0][0] = 1.0;
  m2.M[0][1] = 0.0;
  m2.M[0][2] = 0.0;
  m2.M[0][3] = 0.0;
  m2.M[1][0] = 0.0;
  m2.M[1][2] = 0.0;
  m2.M[1][3] = 0.0;
  m2.M[1][1] = 1.0;
  p_MeshGen = &pRenderer2D->MeshGen;
  v27 = &Scaleform::Render::TransformerWrapper<Scaleform::Render::Matrix2x4<float>>::`vftable';
  p_m2 = 0;
  v25 = &Scaleform::Render::TransformerWrapper<Scaleform::Render::Scale9GridInfo>::`vftable';
  v26 = 0;
  if ( s9g )
  {
    v10 = p_ViewMatrix->M[0][0];
    v26 = s9g;
    m2.M[0][0] = v10;
    m2.M[0][1] = pmesh->ViewMatrix.M[0][1];
    m2.M[0][2] = pmesh->ViewMatrix.M[0][2];
    m2.M[0][3] = pmesh->ViewMatrix.M[0][3];
    m2.M[1][0] = pmesh->ViewMatrix.M[1][0];
    m2.M[1][1] = pmesh->ViewMatrix.M[1][1];
    m2.M[1][2] = pmesh->ViewMatrix.M[1][2];
    m2.M[1][3] = pmesh->ViewMatrix.M[1][3];
    v18 = (Scaleform::Render::TransformerBase *)&v25;
  }
  else
  {
    if ( !Scaleform::Render::MeshKey::CalcMatrixKey(p_ViewMatrix, key, &m2) )
      return Scaleform::Render::ShapeMeshProvider::createNullMesh(this, pout, drawLayerIdx, meshGenFlags);
    p_m2 = &m2;
    v18 = (Scaleform::Render::TransformerBase *)&v27;
  }
  v21 = 0;
  v20 = drawLayerIdx;
  p_mTess = (int)&p_MeshGen->mTess;
  while ( 1 )
  {
    Scaleform::Render::MeshGenerator::Clear(p_MeshGen);
    Scaleform::Render::Tessellator::SetFillRule(&p_MeshGen->mTess, FillEvenOdd);
    Scaleform::Render::Tessellator::SetToleranceParam(&p_MeshGen->mTess, &param);
    v24 = meshGenFlags & 1;
    if ( (meshGenFlags & 1) == 0 || (meshGenFlags & 2) != 0 )
    {
      v13 = 0.0;
    }
    else
    {
      v23 = param.EdgeAAScale * 0.5;
      v13 = v23;
    }
    w = v13;
    Scaleform::Render::Tessellator::SetEdgeAAWidth(&p_MeshGen->mTess, w);
    Scaleform::Render::ShapeMeshProvider::addFill(
      this,
      (int)p_MeshGen,
      (int)&savedregs,
      p_mTess,
      (int)this,
      p_MeshGen,
      &param,
      v18,
      this->DrawLayers.Data.Data[v20].StartPos,
      MorphRatio,
      v15);
    if ( v24 )
    {
      if ( p_MeshGen->mTess.SrcVertices.Size >= 0x8000 )
      {
        Scaleform::Render::MeshGenerator::Clear(p_MeshGen);
        Scaleform::Render::Tessellator::SetEdgeAAWidth(&p_MeshGen->mTess, 0.0);
        Scaleform::Render::ShapeMeshProvider::addFill(
          this,
          (int)p_MeshGen,
          (int)&savedregs,
          p_mTess,
          (int)this,
          p_MeshGen,
          &param,
          v18,
          this->DrawLayers.Data.Data[v20].StartPos,
          MorphRatio,
          v15);
        meshGenFlags &= ~1u;
      }
    }
    Scaleform::Render::Tessellator::Tessellate(&p_MeshGen->mTess, 0);
    if ( (unsigned int)(*(int (__thiscall **)(Scaleform::Render::Tessellator *))(*(_DWORD *)p_mTess + 36))(&p_MeshGen->mTess) < 0xFFFF )
      break;
    meshGenFlags &= ~1u;
    ++v21;
    param.CurveTolerance = param.CurveTolerance * 4.0;
    if ( v21 >= 4 )
    {
      Scaleform::Render::MeshGenerator::Clear(p_MeshGen);
      return Scaleform::Render::ShapeMeshProvider::createNullMesh(this, pout, drawLayerIdx, meshGenFlags);
    }
  }
  v16 = Scaleform::Render::ShapeMeshProvider::acquireTessMeshes(
          this,
          &p_MeshGen->mTess,
          &m2,
          pout,
          drawLayerIdx,
          0,
          meshGenFlags,
          MorphRatio);
  Scaleform::Render::MeshGenerator::Clear(p_MeshGen);
  return v16;
}
