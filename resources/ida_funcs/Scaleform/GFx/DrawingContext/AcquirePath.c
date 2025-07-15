bool __thiscall Scaleform::GFx::DrawingContext::AcquirePath(Scaleform::GFx::DrawingContext *this, bool newShapeFlag)
{
  Scaleform::GFx::DrawingContext::PackedShape *pObject; // ecx
  bool result; // al

  pObject = this->Shapes.pObject;
  if ( !pObject || pObject->IsEmpty(pObject) )
    return 0;
  this->States |= 0x80u;
  if ( newShapeFlag && (this->States & 0x10) != 0 )
    Scaleform::GFx::DrawingContext::FinishPath(this);
  if ( (this->States & 8) != 0 )
  {
    Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::EndPath(this->Shapes.pObject);
    this->States &= ~8u;
  }
  result = 1;
  if ( newShapeFlag )
    this->States |= 1u;
  else
    this->States &= ~1u;
  return result;
}
