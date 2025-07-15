void __userpurge Scaleform::Render::ShapeMeshProvider::addFill(
        Scaleform::Render::ShapeMeshProvider *this@<ecx>,
        int a2@<ebx>,
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
  Scaleform::Render::ShapeDataInterface *v12; // eax
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
  char v28; // [esp+53h] [ebp-135h]
  float coord1; // [esp+54h] [ebp-134h] BYREF
  int v30; // [esp+58h] [ebp-130h] BYREF
  int v31; // [esp+60h] [ebp-128h]
  float v32; // [esp+64h] [ebp-124h] BYREF
  float v33; // [esp+68h] [ebp-120h] BYREF
  float v34; // [esp+6Ch] [ebp-11Ch] BYREF
  Scaleform::Render::ShapeMeshProvider *v35; // [esp+70h] [ebp-118h] BYREF
  float v36; // [esp+74h] [ebp-114h] BYREF
  unsigned int styles1; // [esp+78h] [ebp-110h] BYREF
  int v38; // [esp+7Ch] [ebp-10Ch]
  int v39; // [esp+80h] [ebp-108h]
  int v40; // [esp+84h] [ebp-104h]
  int v41; // [esp+88h] [ebp-100h]
  int v42; // [esp+8Ch] [ebp-FCh]
  Scaleform::Render::ShapePosInfo pos1; // [esp+94h] [ebp-F4h] BYREF
  Scaleform::Render::ShapePosInfo v44; // [esp+CCh] [ebp-BCh] BYREF
  Scaleform::Render::MorphInterpolator v45; // [esp+104h] [ebp-84h] BYREF

  pObject = (Scaleform::GFx::Resource *)this->pMorphData.pObject;
  pos1.Sfactor = 1.0;
  v44.Sfactor = 1.0;
  pos1.Pos = startPos;
  v44.Pos = startPos;
  v12 = this->pShapeData.pObject;
  v35 = this;
  memset(&pos1.StartX, 0, 44);
  pos1.Initialized = 0;
  memset(&v44.StartX, 0, 44);
  v44.Initialized = 0;
  v28 = 1;
  Scaleform::Render::MorphInterpolator::MorphInterpolator(
    &v45,
    (Scaleform::GFx::Resource *)v12,
    pObject,
    morphRatio,
    &v44);
  for ( i = Scaleform::Render::MorphInterpolator::ReadPathInfo(&v45, &pos1, &coord1, &styles1);
        i;
        i = Scaleform::Render::MorphInterpolator::ReadPathInfo(&v45, &pos1, &coord1, &styles1) )
  {
    if ( !v28 && i == Shape_NewLayer )
      break;
    v28 = 0;
    if ( styles1 == v38 )
    {
      if ( v45.pMorphData.pObject )
      {
        v45.pMorphData.pObject->ShapeData1.SkipPathData(&v45.pMorphData.pObject->ShapeData1, &pos1);
        p_ShapeData2 = &v45.pMorphData.pObject->ShapeData2;
        p_Pos2 = &v45.Pos2;
      }
      else
      {
        p_ShapeData2 = (Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *)v45.pShapeData.pObject;
        p_Pos2 = &pos1;
      }
      p_ShapeData2->SkipPathData(p_ShapeData2, p_Pos2);
    }
    else
    {
      ((void (__thiscall *)(Scaleform::Render::TransformerBase *, float *, int *, int, int, int, int))tr->Transform)(
        tr,
        &coord1,
        &v30,
        a4,
        a5,
        a3,
        a2);
      v15 = (Scaleform::Render::TessBase *)(LODWORD(morphRatio) + 80);
      (*(void (__thiscall **)(int, float, float))(*(_DWORD *)(LODWORD(morphRatio) + 80) + 16))(
        LODWORD(morphRatio) + 80,
        COERCE_FLOAT(LODWORD(v32)),
        COERCE_FLOAT(LODWORD(v33)));
      for ( j = Scaleform::Render::MorphInterpolator::ReadEdge(
                  (Scaleform::Render::MorphInterpolator *)&v45.MorphRatio,
                  (Scaleform::Render::ShapePosInfo *)&pos1.LastY,
                  &v32);
            j;
            j = Scaleform::Render::MorphInterpolator::ReadEdge(
                  (Scaleform::Render::MorphInterpolator *)&v45.MorphRatio,
                  (Scaleform::Render::ShapePosInfo *)&pos1.LastY,
                  &v32) )
      {
        switch ( j )
        {
          case Edge_LineTo:
            tr->Transform(tr, &v32, &v33);
            v15->AddVertex(v15, COERCE_FLOAT(LODWORD(v32)), COERCE_FLOAT(LODWORD(v33)));
            break;
          case Edge_QuadTo:
            tr->Transform(tr, &v32, &v33);
            tr->Transform(tr, &v34, (float *)&v35);
            Scaleform::Render::TessellateQuadCurve(v15, param, v32, v33, v34, *(float *)&v35);
            break;
          case Edge_CubicTo:
            tr->Transform(tr, &v32, &v33);
            tr->Transform(tr, &v34, (float *)&v35);
            tr->Transform(tr, &v36, (float *)&styles1);
            Scaleform::Render::TessellateCubicCurve(v15, param, v32, v33, v34, *(float *)&v35, v36, *(float *)&styles1);
            break;
        }
      }
      v17 = *(_DWORD *)(v39 + 44);
      if ( v42 )
      {
        v18 = *(void (__thiscall **)(int, int, Scaleform::Render::ShapePosInfo *))(*(_DWORD *)v17 + 16);
        pos1.StartX = 0;
        v18(v17, v42, &pos1);
        BYTE2(v31) = pos1.StartX != 0;
        if ( pos1.StartX )
          Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)pos1.StartX);
        LOBYTE(v38) = BYTE2(v31);
      }
      else
      {
        LOBYTE(v38) = 0;
      }
      v19 = v41;
      v20 = *(_DWORD *)(v39 + 44);
      if ( v41 )
      {
        v21 = *(void (__thiscall **)(int, int, int *))(*(_DWORD *)v20 + 16);
        pos1.LastX = 0;
        v21(v20, v41, &pos1.StartY);
        BYTE2(v31) = pos1.LastX != 0;
        if ( pos1.LastX )
          Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)pos1.LastX);
        v19 = v41;
        param = a11;
        LOBYTE(v40) = BYTE2(v31);
      }
      else
      {
        LOBYTE(v40) = 0;
      }
      a2 = v38;
      a3 = v40;
      a5 = v42;
      a4 = v19;
      ((void (__thiscall *)(Scaleform::Render::TessBase *))v15->FinalizePath)(v15);
    }
  }
  if ( v45.pMorphData.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v45.pMorphData.pObject);
  if ( v45.pShapeData.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v45.pShapeData.pObject);
  Scaleform::RefCountImplCore::~RefCountImplCore(&v45);
}
