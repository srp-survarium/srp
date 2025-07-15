void __userpurge Scaleform::Render::ShapeMeshProvider::addFill(
        Scaleform::Render::ShapeMeshProvider *this@<ecx>,
        unsigned int a2@<ebx>,
        int a3@<ebp>,
        int a4@<edi>,
        int a5@<esi>,
        Scaleform::Render::MeshGenerator *gen,
        const Scaleform::Render::ToleranceParams *param,
        Scaleform::Render::TransformerBase *tr,
        unsigned int startPos,
        float morphRatio,
        const Scaleform::Render::ToleranceParams *a11)
{
  Scaleform::GFx::Resource *pObject; // edx
  Scaleform::GFx::Resource *v12; // eax
  Scaleform::Render::ShapePathType i; // eax
  Scaleform::Render::TessBase *v15; // edi
  Scaleform::Render::PathEdgeType j; // eax
  int v17; // ecx
  void (__thiscall *v18)(int, int, Scaleform::Render::ShapePosInfo *); // edx
  int v19; // eax
  int v20; // ecx
  void (__thiscall *v21)(int, int, int *); // eax
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *p_ShapeData2; // ecx
  Scaleform::Render::ShapePosInfo *p_Pos2; // edx
  bool first; // [esp+53h] [ebp-135h]
  float coord[6]; // [esp+54h] [ebp-134h] BYREF
  float v30; // [esp+6Ch] [ebp-11Ch] BYREF
  Scaleform::Render::ShapeMeshProvider *v31; // [esp+70h] [ebp-118h] BYREF
  float v32; // [esp+74h] [ebp-114h] BYREF
  unsigned int styles[3]; // [esp+78h] [ebp-110h] BYREF
  int v34; // [esp+84h] [ebp-104h]
  int v35; // [esp+88h] [ebp-100h]
  int v36; // [esp+8Ch] [ebp-FCh]
  Scaleform::Render::ShapePosInfo pos1; // [esp+94h] [ebp-F4h] BYREF
  Scaleform::Render::ShapePosInfo pos2; // [esp+CCh] [ebp-BCh] BYREF
  Scaleform::Render::MorphInterpolator shape; // [esp+104h] [ebp-84h] BYREF

  pObject = (Scaleform::GFx::Resource *)this->pMorphData.pObject;
  pos1.Sfactor = 1.0;
  pos2.Sfactor = 1.0;
  pos1.Pos = startPos;
  pos2.Pos = startPos;
  v12 = (Scaleform::GFx::Resource *)this->pShapeData.pObject;
  v31 = this;
  memset(&pos1.StartX, 0, 44);
  pos1.Initialized = 0;
  memset(&pos2.StartX, 0, 44);
  pos2.Initialized = 0;
  first = 1;
  Scaleform::Render::MorphInterpolator::MorphInterpolator(&shape, v12, pObject, morphRatio, &pos2);
  for ( i = Scaleform::Render::MorphInterpolator::ReadPathInfo(&shape, &pos1, coord, styles);
        i;
        i = Scaleform::Render::MorphInterpolator::ReadPathInfo(&shape, &pos1, coord, styles) )
  {
    if ( !first && i == Shape_NewLayer )
      break;
    first = 0;
    if ( styles[0] == styles[1] )
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
    else
    {
      ((void (__thiscall *)(Scaleform::Render::TransformerBase *, float *, float *, int, int, int, unsigned int))tr->Transform)(
        tr,
        coord,
        &coord[1],
        a4,
        a5,
        a3,
        a2);
      v15 = (Scaleform::Render::TessBase *)(LODWORD(morphRatio) + 80);
      (*(void (__thiscall **)(int, _DWORD, _DWORD))(*(_DWORD *)(LODWORD(morphRatio) + 80) + 16))(
        LODWORD(morphRatio) + 80,
        LODWORD(coord[4]),
        LODWORD(coord[5]));
      for ( j = Scaleform::Render::MorphInterpolator::ReadEdge(
                  (Scaleform::Render::MorphInterpolator *)&shape.MorphRatio,
                  (Scaleform::Render::ShapePosInfo *)&pos1.LastY,
                  &coord[4]);
            j;
            j = Scaleform::Render::MorphInterpolator::ReadEdge(
                  (Scaleform::Render::MorphInterpolator *)&shape.MorphRatio,
                  (Scaleform::Render::ShapePosInfo *)&pos1.LastY,
                  &coord[4]) )
      {
        switch ( j )
        {
          case Edge_LineTo:
            tr->Transform(tr, &coord[4], &coord[5]);
            ((void (__thiscall *)(Scaleform::Render::TessBase *, _DWORD, _DWORD))v15->AddVertex)(
              v15,
              LODWORD(coord[4]),
              LODWORD(coord[5]));
            break;
          case Edge_QuadTo:
            tr->Transform(tr, &coord[4], &coord[5]);
            tr->Transform(tr, &v30, (float *)&v31);
            Scaleform::Render::TessellateQuadCurve(v15, param, coord[4], coord[5], v30, *(float *)&v31);
            break;
          case Edge_CubicTo:
            tr->Transform(tr, &coord[4], &coord[5]);
            tr->Transform(tr, &v30, (float *)&v31);
            tr->Transform(tr, &v32, (float *)styles);
            Scaleform::Render::TessellateCubicCurve(
              v15,
              param,
              coord[4],
              coord[5],
              v30,
              *(float *)&v31,
              v32,
              *(float *)styles);
            break;
        }
      }
      v17 = *(_DWORD *)(styles[2] + 44);
      if ( v36 )
      {
        v18 = *(void (__thiscall **)(int, int, Scaleform::Render::ShapePosInfo *))(*(_DWORD *)v17 + 16);
        pos1.StartX = 0;
        v18(v17, v36, &pos1);
        BYTE2(coord[3]) = pos1.StartX != 0;
        if ( pos1.StartX )
          Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)pos1.StartX);
        LOBYTE(styles[1]) = BYTE2(coord[3]);
      }
      else
      {
        LOBYTE(styles[1]) = 0;
      }
      v19 = v35;
      v20 = *(_DWORD *)(styles[2] + 44);
      if ( v35 )
      {
        v21 = *(void (__thiscall **)(int, int, int *))(*(_DWORD *)v20 + 16);
        pos1.LastX = 0;
        v21(v20, v35, &pos1.StartY);
        BYTE2(coord[3]) = pos1.LastX != 0;
        if ( pos1.LastX )
          Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)pos1.LastX);
        v19 = v35;
        param = a11;
        LOBYTE(v34) = BYTE2(coord[3]);
      }
      else
      {
        LOBYTE(v34) = 0;
      }
      a2 = styles[1];
      a3 = v34;
      a5 = v36;
      a4 = v19;
      ((void (__thiscall *)(Scaleform::Render::TessBase *))v15->FinalizePath)(v15);
    }
  }
  if ( shape.pMorphData.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)shape.pMorphData.pObject);
  if ( shape.pShapeData.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)shape.pShapeData.pObject);
  Scaleform::RefCountImplCore::~RefCountImplCore(&shape);
}
