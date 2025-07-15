char __thiscall Scaleform::Render::ShapeMeshProvider::tessellateStroke(
        Scaleform::Render::ShapeMeshProvider *this,
        const Scaleform::Render::Scale9GridInfo *s9g,
        unsigned int strokeStyleIdx,
        unsigned int drawLayerIdx,
        Scaleform::Render::MeshBase *pmesh,
        Scaleform::Render::VertexOutput *pout,
        unsigned int meshGenFlags)
{
  Scaleform::Render::Renderer2DImpl *pRenderer2D; // ebx
  double v9; // st7
  Scaleform::Render::MeshGenerator *p_MeshGen; // esi
  const Scaleform::Render::ToleranceParams *p_Tolerances; // ebx
  double v12; // st6
  double v13; // st6
  __int16 Flags; // di
  double Scale; // st7
  double v16; // st7
  double v17; // st6
  double v18; // st6
  double v19; // st7
  char v20; // al
  int v21; // ecx
  int v22; // eax
  int v23; // edx
  int v24; // edi
  Scaleform::Render::TessBase *p_mStrokerAA; // edi
  Scaleform::Render::ShapeMeshProvider *v26; // ebx
  char v27; // bl
  const Scaleform::Render::ToleranceParams *v29; // [esp+680h] [ebp-B8h]
  const Scaleform::Render::ToleranceParams *v30; // [esp+680h] [ebp-B8h]
  char v31; // [esp+6A7h] [ebp-91h]
  char v32; // [esp+6A7h] [ebp-91h]
  float v33; // [esp+6A8h] [ebp-90h]
  float v34; // [esp+6A8h] [ebp-90h]
  float v35; // [esp+6A8h] [ebp-90h]
  float v36; // [esp+6A8h] [ebp-90h]
  float v37; // [esp+6A8h] [ebp-90h]
  float v38; // [esp+6A8h] [ebp-90h]
  float v39; // [esp+6A8h] [ebp-90h]
  float v40; // [esp+6A8h] [ebp-90h]
  float v41; // [esp+6A8h] [ebp-90h]
  float v42; // [esp+6A8h] [ebp-90h]
  float v43; // [esp+6ACh] [ebp-8Ch]
  float v44; // [esp+6ACh] [ebp-8Ch]
  float v45; // [esp+6ACh] [ebp-8Ch]
  float v46; // [esp+6ACh] [ebp-8Ch]
  float v47; // [esp+6ACh] [ebp-8Ch]
  float v48; // [esp+6ACh] [ebp-8Ch]
  Scaleform::Render::TransformerBase *v49; // [esp+6ACh] [ebp-8Ch]
  float v50; // [esp+6B0h] [ebp-88h]
  float v51; // [esp+6B0h] [ebp-88h]
  float v52; // [esp+6B4h] [ebp-84h]
  float v53; // [esp+6B4h] [ebp-84h]
  float v54; // [esp+6B4h] [ebp-84h]
  int v55; // [esp+6B4h] [ebp-84h]
  float Units; // [esp+6B8h] [ebp-80h]
  float v57; // [esp+6B8h] [ebp-80h]
  float MorphRatio; // [esp+6BCh] [ebp-7Ch]
  unsigned int StartPos; // [esp+6C4h] [ebp-74h]
  Scaleform::Render::Matrix2x4<float> v61; // [esp+6C8h] [ebp-70h] BYREF
  void **v62; // [esp+6ECh] [ebp-4Ch] BYREF
  Scaleform::Render::Matrix2x4<float> *v63; // [esp+6F0h] [ebp-48h]
  void **v64; // [esp+6F4h] [ebp-44h] BYREF
  const Scaleform::Render::Scale9GridInfo *v65; // [esp+6F8h] [ebp-40h]
  Scaleform::Render::StrokeStyleType s1; // [esp+6FCh] [ebp-3Ch] BYREF
  Scaleform::Render::Matrix2x4<float> v67; // [esp+718h] [ebp-20h] BYREF

  v61.M[0][0] = pmesh->ViewMatrix.M[0][0];
  pRenderer2D = pmesh->pRenderer2D;
  v61.M[0][1] = pmesh->ViewMatrix.M[0][1];
  v61.M[0][2] = pmesh->ViewMatrix.M[0][2];
  v61.M[0][3] = pmesh->ViewMatrix.M[0][3];
  s1.pFill.pObject = 0;
  v9 = pmesh->ViewMatrix.M[1][0];
  s1.pDashes.pObject = 0;
  v61.M[1][0] = v9;
  p_MeshGen = &pRenderer2D->MeshGen;
  v61.M[1][1] = pmesh->ViewMatrix.M[1][1];
  p_Tolerances = &pRenderer2D->Tolerances;
  v61.M[1][2] = pmesh->ViewMatrix.M[1][2];
  v61.M[1][3] = pmesh->ViewMatrix.M[1][3];
  MorphRatio = pmesh->MorphRatio;
  Scaleform::Render::ShapeMeshProvider::GetStrokeStyle(this, strokeStyleIdx, &s1, MorphRatio);
  StartPos = this->DrawLayers.Data.Data[drawLayerIdx].StartPos;
  if ( s1.Miter < 1.0 )
    s1.Miter = 1.0;
  v31 = s1.Flags & 1;
  if ( (s1.Flags & 1) != 0 )
  {
    if ( v61.M[0][3] >= 0.0 )
      v12 = 0.5;
    else
      v12 = -0.5;
    v43 = v12;
    v44 = v61.M[0][3] + v43;
    v45 = floor(v44);
    v61.M[0][3] = v45;
    if ( v61.M[1][3] >= 0.0 )
      v13 = 0.5;
    else
      v13 = -0.5;
    v46 = v13;
    v47 = v61.M[1][3] + v46;
    v48 = floor(v47);
    v61.M[1][3] = v48;
  }
  v67.M[0][0] = v61.M[0][0];
  v62 = &Scaleform::Render::TransformerWrapper<Scaleform::Render::Matrix2x4<float>>::`vftable';
  v67.M[0][1] = v61.M[0][1];
  v63 = 0;
  v64 = &Scaleform::Render::TransformerWrapper<Scaleform::Render::Scale9GridInfo>::`vftable';
  v67.M[0][2] = v61.M[0][2];
  v65 = 0;
  v67.M[0][3] = v61.M[0][3];
  v67.M[1][0] = v61.M[1][0];
  v67.M[1][1] = v61.M[1][1];
  v67.M[1][2] = v61.M[1][2];
  v67.M[1][3] = v61.M[1][3];
  if ( s9g )
  {
    v65 = s9g;
    v49 = (Scaleform::Render::TransformerBase *)&v64;
  }
  else
  {
    v63 = &v67;
    v49 = (Scaleform::Render::TransformerBase *)&v62;
  }
  Scaleform::Render::MeshGenerator::Clear(p_MeshGen);
  Units = s1.Units;
  Flags = s1.Flags;
  if ( !s9g )
  {
    switch ( s1.Flags & 6 )
    {
      case 0:
        Scale = Scaleform::Render::Matrix2x4<float>::GetScale(&v61);
        goto LABEL_21;
      case 2:
        v35 = v61.M[0][0] * v61.M[0][0] + v61.M[1][0] * v61.M[1][0];
        v36 = sqrt(v35);
        Scale = v36;
        goto LABEL_21;
      case 4:
        v33 = v61.M[1][1] * v61.M[1][1] + v61.M[0][1] * v61.M[0][1];
        v34 = sqrt(v33);
        Scale = v34;
LABEL_21:
        Units = Scale;
        break;
    }
  }
  v50 = s1.Width * Units;
  v37 = 0.5;
  if ( (meshGenFlags & 1) == 0 || (meshGenFlags & 2) != 0 )
  {
    v37 = 0.0;
    v52 = floor(v50);
    v50 = v52 + 1.0;
  }
  v16 = v50;
  if ( !v31 )
  {
    v17 = 0.25;
    goto LABEL_32;
  }
  if ( v16 < 1.26 )
  {
LABEL_30:
    v17 = 0.5;
LABEL_32:
    v57 = v17;
    goto LABEL_33;
  }
  v53 = v16 - 0.25;
  v54 = ceil(v53);
  Flags = s1.Flags;
  if ( ((int)v54 & 1) != 0 )
  {
    v16 = v50;
    goto LABEL_30;
  }
  v57 = 0.0;
  v16 = v50;
LABEL_33:
  if ( (s1.Color & 0xFF000000) < 0xF0000000 || (v32 = 1, s1.pFill.pObject) )
    v32 = 0;
  if ( (meshGenFlags & 2) != 0 )
    v32 = 0;
  v18 = v37;
  if ( v16 >= 1.25 || v32 || v18 <= 0.0 )
  {
    v21 = 2;
    v22 = Flags & 0x30;
    v55 = 2;
    v23 = 2;
    if ( v22 == 16 )
    {
      v55 = 3;
    }
    else if ( v22 == 32 )
    {
      v55 = 0;
    }
    if ( (Flags & 0xC0) == 0x40 )
    {
      v23 = 0;
    }
    else if ( (Flags & 0xC0) == 0x80 )
    {
      v23 = 1;
    }
    v24 = Flags & 0x300;
    if ( v24 == 256 )
    {
      v21 = 0;
    }
    else if ( v24 == 512 )
    {
      v21 = 1;
    }
    v51 = v16 - v18 * 2.0;
    if ( v51 < 0.1000000014901161 )
    {
      if ( !v32 )
      {
        v37 = v18 - 0.05000000074505806;
        v51 = 0.1;
        goto LABEL_63;
      }
      v51 = 0.0;
    }
    if ( v32 )
    {
      p_mStrokerAA = &p_MeshGen->mStrokerAA;
      v39 = v51 * 0.5;
      p_MeshGen->mStrokerAA.WidthRight = v39;
      p_MeshGen->mStrokerAA.WidthLeft = v39;
      v40 = v18 * p_Tolerances->EdgeAAScale;
      v41 = 2.0 * v40;
      p_MeshGen->mStrokerAA.AaWidthRight = v41;
      p_MeshGen->mStrokerAA.AaWidthLeft = v41;
      p_MeshGen->mStrokerAA.EndLineCap = v21;
      p_MeshGen->mStrokerAA.LineJoin = v55;
      p_MeshGen->mStrokerAA.StartLineCap = v23;
      p_MeshGen->mStrokerAA.MiterLimit = s1.Miter;
      Scaleform::Render::StrokerAA::SetToleranceParam(&p_MeshGen->mStrokerAA, p_Tolerances);
      v29 = p_Tolerances;
      v26 = this;
      Scaleform::Render::ShapeMeshProvider::addStroke(
        this,
        p_MeshGen,
        &p_MeshGen->mStrokerAA,
        v29,
        v49,
        StartPos,
        strokeStyleIdx,
        v57,
        MorphRatio);
LABEL_64:
      v20 = Scaleform::Render::ShapeMeshProvider::acquireTessMeshes(
              v26,
              p_mStrokerAA,
              &v67,
              pout,
              drawLayerIdx,
              strokeStyleIdx,
              meshGenFlags,
              MorphRatio);
      goto LABEL_65;
    }
LABEL_63:
    p_MeshGen->mStroker.EndLineCap = v21;
    p_MeshGen->mStroker.LineJoin = v55;
    p_MeshGen->mStroker.StartLineCap = v23;
    p_MeshGen->mStroker.Width = v51 * 0.5;
    p_MeshGen->mStroker.MiterLimit = s1.Miter;
    Scaleform::Render::Stroker::SetToleranceParam(&p_MeshGen->mStroker, p_Tolerances);
    p_mStrokerAA = &p_MeshGen->mTess;
    Scaleform::Render::Tessellator::SetFillRule(&p_MeshGen->mTess, FillStroker);
    v42 = p_Tolerances->EdgeAAScale * v37;
    Scaleform::Render::Tessellator::SetEdgeAAWidth(&p_MeshGen->mTess, v42);
    v30 = p_Tolerances;
    v26 = this;
    Scaleform::Render::ShapeMeshProvider::addStroke(
      this,
      p_MeshGen,
      v30,
      v49,
      StartPos,
      strokeStyleIdx,
      v57,
      MorphRatio);
    Scaleform::Render::Tessellator::Tessellate(&p_MeshGen->mTess, 0);
    goto LABEL_64;
  }
  if ( v16 >= 1.0 )
    v19 = v37 + v16 - 1.0;
  else
    v19 = v37;
  v38 = v19;
  p_MeshGen->mHairliner.Width = v38 + v38;
  Scaleform::Render::Hairliner::SetToleranceParam(&p_MeshGen->mHairliner, p_Tolerances);
  Scaleform::Render::ShapeMeshProvider::addStroke(
    this,
    p_MeshGen,
    &p_MeshGen->mHairliner,
    p_Tolerances,
    v49,
    StartPos,
    strokeStyleIdx,
    v57,
    MorphRatio);
  Scaleform::Render::Hairliner::Tessellate(&p_MeshGen->mHairliner);
  v20 = Scaleform::Render::ShapeMeshProvider::acquireTessMeshes(
          this,
          &p_MeshGen->mHairliner,
          &v67,
          pout,
          drawLayerIdx,
          strokeStyleIdx,
          meshGenFlags,
          MorphRatio);
LABEL_65:
  v27 = v20;
  Scaleform::Render::MeshGenerator::Clear(p_MeshGen);
  v64 = &Scaleform::GFx::AS3::ArrayBase::`vftable';
  v62 = &Scaleform::GFx::AS3::ArrayBase::`vftable';
  if ( s1.pDashes.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)s1.pDashes.pObject);
  if ( s1.pFill.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)s1.pFill.pObject);
  return v27;
}
