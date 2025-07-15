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
  Scaleform::Render::ShapeDataInterface *pObject; // edx
  Scaleform::GFx::Resource *v11; // ecx
  Scaleform::Render::TransformerBase *v12; // eax
  char v13; // al
  char v15; // [esp+1Bh] [ebp-CDh]
  void **v16; // [esp+1Ch] [ebp-CCh] BYREF
  const Scaleform::Render::Matrix2x4<float> *v17; // [esp+20h] [ebp-C8h]
  void **v18; // [esp+24h] [ebp-C4h] BYREF
  Scaleform::Render::Scale9GridInfo *v19; // [esp+28h] [ebp-C0h]
  Scaleform::Render::ShapePosInfo v20; // [esp+2Ch] [ebp-BCh] BYREF
  Scaleform::Render::MorphInterpolator v21; // [esp+64h] [ebp-84h] BYREF

  v9 = this->pShapeData.pObject->GetStartingPos(this->pShapeData.pObject);
  pObject = this->pShapeData.pObject;
  v20.Sfactor = 1.0;
  v20.Pos = v9;
  v11 = (Scaleform::GFx::Resource *)this->pMorphData.pObject;
  memset(&v20.StartX, 0, 44);
  v20.Initialized = 0;
  Scaleform::Render::MorphInterpolator::MorphInterpolator(
    &v21,
    (Scaleform::GFx::Resource *)pObject,
    v11,
    morphRatio,
    &v20);
  v16 = &Scaleform::Render::TransformerWrapper<Scaleform::Render::Matrix2x4<float>>::`vftable';
  v17 = 0;
  v18 = &Scaleform::Render::TransformerWrapper<Scaleform::Render::Scale9GridInfo>::`vftable';
  v19 = 0;
  if ( s9g )
  {
    v19 = s9g;
    v12 = (Scaleform::Render::TransformerBase *)&v18;
  }
  else
  {
    v17 = m;
    v12 = (Scaleform::Render::TransformerBase *)&v16;
  }
  if ( gen )
    v13 = Scaleform::Render::HitTestFillAndStrokes<Scaleform::Render::TransformerBase>(&v21, v12, x, y, gen, tol);
  else
    v13 = Scaleform::Render::HitTestFill<Scaleform::Render::Matrix2x4<float>>(&v21, m, x, y);
  v15 = v13;
  v16 = &Scaleform::GFx::AS3::ArrayBase::`vftable';
  v18 = &Scaleform::GFx::AS3::ArrayBase::`vftable';
  if ( v21.pMorphData.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v21.pMorphData.pObject);
  if ( v21.pShapeData.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v21.pShapeData.pObject);
  Scaleform::RefCountImplCore::~RefCountImplCore(&v21);
  return v15;
}


char __thiscall Scaleform::Render::ShapeMeshProvider::HitTestShape(
        Scaleform::Render::ShapeMeshProvider *this,
        const Scaleform::Render::Matrix2x4<float> *m,
        float x,
        float y,
        float morphRatio,
        Scaleform::Render::StrokeGenerator *gen,
        const Scaleform::Render::ToleranceParams *tol)
{
  return Scaleform::Render::ShapeMeshProvider::HitTestShape(
           (Scaleform::Render::ShapeMeshProvider *)((char *)this - 8),
           m,
           x,
           y,
           morphRatio,
           gen,
           tol,
           0);
}
