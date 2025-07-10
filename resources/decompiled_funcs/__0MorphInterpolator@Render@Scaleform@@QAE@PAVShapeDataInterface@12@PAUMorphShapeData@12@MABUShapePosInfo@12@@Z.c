void __thiscall Scaleform::Render::MorphInterpolator::MorphInterpolator(
        Scaleform::Render::MorphInterpolator *this,
        Scaleform::GFx::Resource *shape,
        Scaleform::GFx::Resource *morph,
        float ratio,
        const Scaleform::Render::ShapePosInfo *pos2)
{
  this->__vftable = (Scaleform::Render::MorphInterpolator_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->__vftable = (Scaleform::Render::MorphInterpolator_vtbl *)&Scaleform::Render::MorphInterpolator::`vftable';
  if ( shape )
    Scaleform::RefCountImpl::AddRef(shape);
  this->pShapeData.pObject = (Scaleform::Render::ShapeDataInterface *)shape;
  if ( morph )
    Scaleform::RefCountImpl::AddRef(morph);
  this->pMorphData.pObject = (Scaleform::Render::MorphShapeData *)morph;
  this->MorphRatio = ratio;
  qmemcpy(&this->Pos2, pos2, sizeof(this->Pos2));
  qmemcpy(&this->Pos2s, pos2, sizeof(this->Pos2s));
}
