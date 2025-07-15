bool __thiscall Scaleform::GFx::AS3::ShapeObject::PointTestLocal(
        Scaleform::GFx::AS3::ShapeObject *this,
        const Scaleform::Render::Point<float> *pt,
        unsigned __int8 hitTestMask)
{
  Scaleform::GFx::DrawingContext *pObject; // ecx

  pObject = this->pDrawing.pObject;
  return pObject && Scaleform::GFx::DrawingContext::DefPointTestLocal(pObject, hitTestMask, pt, hitTestMask & 1, this)
      || this->pDef.pObject->DefPointTestLocal(this->pDef.pObject, pt, hitTestMask & 1, this);
}
