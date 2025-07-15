void __thiscall Scaleform::GFx::ConstShapeWithStyles::ConstShapeWithStyles(
        Scaleform::GFx::ConstShapeWithStyles *this,
        const Scaleform::GFx::ConstShapeWithStyles *o)
{
  this->__vftable = (Scaleform::GFx::ConstShapeWithStyles_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->__vftable = (Scaleform::GFx::ConstShapeWithStyles_vtbl *)&Scaleform::GFx::ShapeDataBase::`vftable';
  this->RefCount = 1;
  this->Paths = o->Paths;
  this->Flags = o->Flags;
  this->__vftable = (Scaleform::GFx::ConstShapeWithStyles_vtbl *)&Scaleform::GFx::ConstShapeWithStyles::`vftable';
  this->Styles = 0;
  this->Bound.x1 = 0.0;
  this->Bound.y1 = 0.0;
  this->Bound.x2 = 0.0;
  this->Bound.y2 = 0.0;
  this->RectBound.x1 = 0.0;
  this->RectBound.y1 = 0.0;
  this->RectBound.x2 = 0.0;
  this->RectBound.y2 = 0.0;
  Scaleform::GFx::ConstShapeWithStyles::SetStyles(
    this,
    o->FillStylesNum,
    (const Scaleform::Render::FillStyleType *)o->Styles,
    o->StrokeStylesNum,
    (const Scaleform::Render::StrokeStyleType *)&o->Styles[8 * o->FillStylesNum]);
  this->RectBound.x1 = 0.0;
  this->RectBound.y1 = 0.0;
  this->RectBound.x2 = 0.0;
  this->RectBound.y2 = 0.0;
  this->Bound.x1 = 0.0;
  this->Bound.y1 = 0.0;
  this->Bound.x2 = 0.0;
  this->Bound.y2 = 0.0;
}
