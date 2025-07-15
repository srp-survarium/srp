void __thiscall Scaleform::Render::ShapeMeshProvider::addToStrokeSorter(
        Scaleform::Render::ShapeMeshProvider *this,
        Scaleform::Render::MeshGenerator *gen,
        const Scaleform::Render::ToleranceParams *param,
        Scaleform::Render::TransformerBase *tr,
        unsigned int startPos,
        unsigned int strokeStyleIdx,
        float snapOffset,
        float morphRatio)
{
  Scaleform::Render::ShapePathType i; // eax
  Scaleform::Render::PathEdgeType j; // eax
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *p_ShapeData2; // ecx
  Scaleform::Render::ShapePosInfo *p_Pos2; // eax
  Scaleform::Render::StrokeSorter *p_mStrokeSorter; // esi
  Scaleform::Render::DashArray *pObject; // ebp
  float morphRatioa; // [esp+14h] [ebp-14Ch]
  char v16; // [esp+2Bh] [ebp-135h]
  float coord1; // [esp+2Ch] [ebp-134h] BYREF
  float y; // [esp+30h] [ebp-130h]
  float v19; // [esp+34h] [ebp-12Ch]
  float v20; // [esp+38h] [ebp-128h]
  float v21; // [esp+3Ch] [ebp-124h]
  float v22; // [esp+40h] [ebp-120h]
  Scaleform::Render::ShapePosInfo pos1; // [esp+44h] [ebp-11Ch] BYREF
  Scaleform::Render::StrokeStyleType s1; // [esp+7Ch] [ebp-E4h] BYREF
  Scaleform::Render::ShapePosInfo v25; // [esp+98h] [ebp-C8h] BYREF
  unsigned int styles1[3]; // [esp+D0h] [ebp-90h] BYREF
  Scaleform::Render::MorphInterpolator v27; // [esp+DCh] [ebp-84h] BYREF

  pos1.Sfactor = 1.0;
  v25.Sfactor = 1.0;
  pos1.Pos = startPos;
  v25.Pos = startPos;
  memset(&pos1.StartX, 0, 44);
  pos1.Initialized = 0;
  memset(&v25.StartX, 0, 44);
  v25.Initialized = 0;
  s1.pFill.pObject = 0;
  s1.pDashes.pObject = 0;
  Scaleform::Render::ShapeMeshProvider::GetStrokeStyle(this, strokeStyleIdx, &s1, morphRatio);
  Scaleform::Render::MorphInterpolator::MorphInterpolator(
    &v27,
    (Scaleform::GFx::Resource *)this->pShapeData.pObject,
    (Scaleform::GFx::Resource *)this->pMorphData.pObject,
    morphRatio,
    &v25);
  v16 = 1;
  for ( i = Scaleform::Render::MorphInterpolator::ReadPathInfo(&v27, &pos1, &coord1, styles1);
        i;
        i = Scaleform::Render::MorphInterpolator::ReadPathInfo(&v27, &pos1, &coord1, styles1) )
  {
    if ( !v16 && i == Shape_NewLayer )
      break;
    v16 = 0;
    if ( styles1[2] == strokeStyleIdx )
    {
      Scaleform::Render::StrokeSorter::AddVertexNV(&gen->mStrokeSorter, coord1, y, 1u);
      for ( j = Scaleform::Render::MorphInterpolator::ReadEdge(&v27, &pos1, &coord1);
            j;
            j = Scaleform::Render::MorphInterpolator::ReadEdge(&v27, &pos1, &coord1) )
      {
        switch ( j )
        {
          case Edge_LineTo:
            Scaleform::Render::StrokeSorter::AddVertexNV(&gen->mStrokeSorter, coord1, y, 1u);
            break;
          case Edge_QuadTo:
            Scaleform::Render::StrokeSorter::AddQuad(&gen->mStrokeSorter, coord1, y, v19, v20);
            break;
          case Edge_CubicTo:
            Scaleform::Render::StrokeSorter::AddCubic(&gen->mStrokeSorter, coord1, y, v19, v20, v21, v22);
            break;
        }
      }
      gen->mStrokeSorter.FinalizePath(&gen->mStrokeSorter, 0, 0, 0, 0);
    }
    else
    {
      if ( v27.pMorphData.pObject )
      {
        v27.pMorphData.pObject->ShapeData1.SkipPathData(&v27.pMorphData.pObject->ShapeData1, &pos1);
        p_ShapeData2 = &v27.pMorphData.pObject->ShapeData2;
        p_Pos2 = &v27.Pos2;
      }
      else
      {
        p_ShapeData2 = (Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *)v27.pShapeData.pObject;
        p_Pos2 = &pos1;
      }
      p_ShapeData2->SkipPathData(p_ShapeData2, p_Pos2);
    }
  }
  p_mStrokeSorter = &gen->mStrokeSorter;
  Scaleform::Render::StrokeSorter::Sort(&gen->mStrokeSorter);
  if ( s1.pDashes.pObject )
  {
    pObject = s1.pDashes.pObject;
    morphRatioa = tr->GetScale(tr);
    Scaleform::Render::StrokeSorter::GenerateDashes(p_mStrokeSorter, pObject, param, morphRatioa);
  }
  Scaleform::Render::StrokeSorter::Transform(p_mStrokeSorter, tr);
  if ( (s1.Flags & 1) != 0 )
  {
    if ( !s1.pDashes.pObject )
      Scaleform::Render::StrokeSorter::Snap(p_mStrokeSorter, snapOffset, snapOffset);
  }
  else if ( snapOffset > 0.0 )
  {
    Scaleform::Render::StrokeSorter::AddOffset(p_mStrokeSorter, snapOffset, snapOffset);
  }
  if ( v27.pMorphData.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v27.pMorphData.pObject);
  if ( v27.pShapeData.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v27.pShapeData.pObject);
  Scaleform::RefCountImplCore::~RefCountImplCore(&v27);
  if ( s1.pDashes.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)s1.pDashes.pObject);
  if ( s1.pFill.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)s1.pFill.pObject);
}
