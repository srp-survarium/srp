char __thiscall Scaleform::Render::ShapeMeshProvider::HitTestShape(
        Scaleform::Render::ShapeMeshProvider *this,
        const Scaleform::Render::Matrix2x4<float> *m,
        float x,
        float y,
        float morphRatio,
        Scaleform::Render::StrokeGenerator *gen,
        const Scaleform::Render::ToleranceParams *tol,
        Scaleform::Render::Scale9GridInfo *s9g)
{
  unsigned int v9; // eax
  Scaleform::GFx::Resource *pObject; // edx
  Scaleform::GFx::Resource *v11; // ecx
  Scaleform::Render::TransformerBase *p_trScale9; // eax
  char v13; // al
  char v15; // [esp+1Bh] [ebp-CDh]
  Scaleform::Render::TransformerWrapper<Scaleform::Render::Matrix2x4<float> > trAffine; // [esp+1Ch] [ebp-CCh] BYREF
  Scaleform::Render::TransformerWrapper<Scaleform::Render::Scale9GridInfo> trScale9; // [esp+24h] [ebp-C4h] BYREF
  Scaleform::Render::ShapePosInfo pos2; // [esp+2Ch] [ebp-BCh] BYREF
  Scaleform::Render::MorphInterpolator shape; // [esp+64h] [ebp-84h] BYREF

  v9 = this->pShapeData.pObject->GetStartingPos(this->pShapeData.pObject);
  pObject = (Scaleform::GFx::Resource *)this->pShapeData.pObject;
  pos2.Sfactor = 1.0;
  pos2.Pos = v9;
  v11 = (Scaleform::GFx::Resource *)this->pMorphData.pObject;
  memset(&pos2.StartX, 0, 44);
  pos2.Initialized = 0;
  Scaleform::Render::MorphInterpolator::MorphInterpolator(&shape, pObject, v11, morphRatio, &pos2);
  trAffine.__vftable = (Scaleform::Render::TransformerWrapper<Scaleform::Render::Matrix2x4<float> >_vtbl *)&Scaleform::Render::TransformerWrapper<Scaleform::Render::Matrix2x4<float>>::`vftable';
  trAffine.Tr = 0;
  trScale9.__vftable = (Scaleform::Render::TransformerWrapper<Scaleform::Render::Scale9GridInfo>_vtbl *)&Scaleform::Render::TransformerWrapper<Scaleform::Render::Scale9GridInfo>::`vftable';
  trScale9.Tr = 0;
  if ( s9g )
  {
    trScale9.Tr = s9g;
    p_trScale9 = &trScale9;
  }
  else
  {
    trAffine.Tr = m;
    p_trScale9 = &trAffine;
  }
  if ( gen )
    v13 = Scaleform::Render::HitTestFillAndStrokes<Scaleform::Render::TransformerBase>(
            &shape,
            p_trScale9,
            x,
            y,
            gen,
            tol);
  else
    v13 = Scaleform::Render::HitTestFill<Scaleform::Render::Matrix2x4<float>>(&shape, m, x, y);
  v15 = v13;
  trAffine.__vftable = (Scaleform::Render::TransformerWrapper<Scaleform::Render::Matrix2x4<float> >_vtbl *)&Scaleform::GFx::AS3::ArrayBase::`vftable';
  trScale9.__vftable = (Scaleform::Render::TransformerWrapper<Scaleform::Render::Scale9GridInfo>_vtbl *)&Scaleform::GFx::AS3::ArrayBase::`vftable';
  if ( shape.pMorphData.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)shape.pMorphData.pObject);
  if ( shape.pShapeData.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)shape.pShapeData.pObject);
  Scaleform::RefCountImplCore::~RefCountImplCore(&shape);
  return v15;
}
