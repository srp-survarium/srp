void __thiscall Scaleform::GFx::DrawingContext::ChangeLineStyle(
        Scaleform::GFx::DrawingContext *this,
        float lineWidth,
        unsigned int rgba,
        bool hinting,
        unsigned int scaling,
        unsigned int caps,
        unsigned int joins,
        float miterLimit)
{
  Scaleform::GFx::DrawingContext::PackedShape *pObject; // ecx
  Scaleform::GFx::DrawingContext::PackedShape *v10; // ecx

  if ( (rgba & 0xFF000000) != 0 )
  {
    if ( lineWidth <= 0.0 )
      lineWidth = 0.050000001;
    if ( !Scaleform::GFx::DrawingContext::SameLineStyle(
            this,
            lineWidth,
            rgba,
            hinting,
            scaling,
            caps,
            joins,
            miterLimit) )
    {
      pObject = this->Shapes.pObject;
      if ( pObject && !pObject->IsEmpty(pObject) )
      {
        this->States |= 0x80u;
        if ( (this->States & 8) != 0 )
        {
          Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::EndPath(this->Shapes.pObject);
          this->States &= ~8u;
        }
        this->States &= ~1u;
      }
      Scaleform::GFx::DrawingContext::SetLineStyle(this, lineWidth, rgba, hinting, scaling, caps, joins, miterLimit);
    }
  }
  else if ( this->Shapes.pObject->GetStrokeStyleCount(this->Shapes.pObject) && this->StrokeStyle )
  {
    v10 = this->Shapes.pObject;
    if ( v10 && !v10->IsEmpty(v10) )
    {
      this->States |= 0x80u;
      if ( (this->States & 8) != 0 )
      {
        Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::EndPath(this->Shapes.pObject);
        this->States &= ~8u;
      }
      this->States &= ~1u;
    }
    this->States &= ~2u;
    this->StrokeStyle = 0;
  }
}
