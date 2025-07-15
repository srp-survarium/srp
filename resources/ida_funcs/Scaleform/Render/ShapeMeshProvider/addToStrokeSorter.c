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
  float y3; // [esp+14h] [ebp-14Ch]
  bool first; // [esp+2Bh] [ebp-135h]
  float coord[6]; // [esp+2Ch] [ebp-134h] BYREF
  Scaleform::Render::ShapePosInfo pos1; // [esp+44h] [ebp-11Ch] BYREF
  Scaleform::Render::StrokeStyleType style; // [esp+7Ch] [ebp-E4h] BYREF
  Scaleform::Render::ShapePosInfo pos2; // [esp+98h] [ebp-C8h] BYREF
  unsigned int styles[3]; // [esp+D0h] [ebp-90h] BYREF
  Scaleform::Render::MorphInterpolator shape; // [esp+DCh] [ebp-84h] BYREF

  pos1.Sfactor = 1.0;
  pos2.Sfactor = 1.0;
  pos1.Pos = startPos;
  pos2.Pos = startPos;
  memset(&pos1.StartX, 0, 44);
  pos1.Initialized = 0;
  memset(&pos2.StartX, 0, 44);
  pos2.Initialized = 0;
  style.pFill.pObject = 0;
  style.pDashes.pObject = 0;
  Scaleform::Render::ShapeMeshProvider::GetStrokeStyle(this, strokeStyleIdx, &style, morphRatio);
  Scaleform::Render::MorphInterpolator::MorphInterpolator(
    &shape,
    (Scaleform::GFx::Resource *)this->pShapeData.pObject,
    (Scaleform::GFx::Resource *)this->pMorphData.pObject,
    morphRatio,
    &pos2);
  first = 1;
  for ( i = Scaleform::Render::MorphInterpolator::ReadPathInfo(&shape, &pos1, coord, styles);
        i;
        i = Scaleform::Render::MorphInterpolator::ReadPathInfo(&shape, &pos1, coord, styles) )
  {
    if ( !first && i == Shape_NewLayer )
      break;
    first = 0;
    if ( styles[2] == strokeStyleIdx )
    {
      Scaleform::Render::StrokeSorter::AddVertexNV(&gen->mStrokeSorter, coord[0], coord[1], 1u);
      for ( j = Scaleform::Render::MorphInterpolator::ReadEdge(&shape, &pos1, coord);
            j;
            j = Scaleform::Render::MorphInterpolator::ReadEdge(&shape, &pos1, coord) )
      {
        switch ( j )
        {
          case Edge_LineTo:
            Scaleform::Render::StrokeSorter::AddVertexNV(&gen->mStrokeSorter, coord[0], coord[1], 1u);
            break;
          case Edge_QuadTo:
            Scaleform::Render::StrokeSorter::AddQuad(&gen->mStrokeSorter, coord[0], coord[1], coord[2], coord[3]);
            break;
          case Edge_CubicTo:
            Scaleform::Render::StrokeSorter::AddCubic(
              &gen->mStrokeSorter,
              coord[0],
              coord[1],
              coord[2],
              coord[3],
              coord[4],
              coord[5]);
            break;
        }
      }
      gen->mStrokeSorter.FinalizePath(&gen->mStrokeSorter, 0, 0, 0, 0);
    }
    else
    {
      if ( shape.pMorphData.pObject )
      {
        shape.pMorphData.pObject->ShapeData1.SkipPathData(&shape.pMorphData.pObject->ShapeData1, &pos1);
        p_ShapeData2 = &shape.pMorphData.pObject->ShapeData2;
        p_Pos2 = &shape.Pos2;
      }
      else
      {
        p_ShapeData2 = (Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *)shape.pShapeData.pObject;
        p_Pos2 = &pos1;
      }
      p_ShapeData2->SkipPathData(p_ShapeData2, p_Pos2);
    }
  }
  p_mStrokeSorter = &gen->mStrokeSorter;
  Scaleform::Render::StrokeSorter::Sort(&gen->mStrokeSorter);
  if ( style.pDashes.pObject )
  {
    pObject = style.pDashes.pObject;
    y3 = tr->GetScale(tr);
    Scaleform::Render::StrokeSorter::GenerateDashes(p_mStrokeSorter, pObject, param, y3);
  }
  Scaleform::Render::StrokeSorter::Transform(p_mStrokeSorter, tr);
  if ( (style.Flags & 1) != 0 )
  {
    if ( !style.pDashes.pObject )
      Scaleform::Render::StrokeSorter::Snap(p_mStrokeSorter, snapOffset, snapOffset);
  }
  else if ( snapOffset > 0.0 )
  {
    Scaleform::Render::StrokeSorter::AddOffset(p_mStrokeSorter, snapOffset, snapOffset);
  }
  if ( shape.pMorphData.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)shape.pMorphData.pObject);
  if ( shape.pShapeData.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)shape.pShapeData.pObject);
  Scaleform::RefCountImplCore::~RefCountImplCore(&shape);
  if ( style.pDashes.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)style.pDashes.pObject);
  if ( style.pFill.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)style.pFill.pObject);
}
