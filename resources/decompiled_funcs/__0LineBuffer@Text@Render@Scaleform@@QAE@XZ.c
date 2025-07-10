void __thiscall Scaleform::Render::Text::LineBuffer::LineBuffer(Scaleform::Render::Text::LineBuffer *this)
{
  float v1; // [esp+0h] [ebp-4h]

  this->Lines.Data.Data = 0;
  this->Lines.Data.Size = 0;
  this->Lines.Data.Policy.Capacity = 0;
  this->Geom.FirstVisibleLinePos = 0;
  this->Geom.VisibleRect.x1 = 0.0;
  this->Geom.VisibleRect.y1 = 0.0;
  this->Geom.VisibleRect.x2 = 0.0;
  this->Geom.VisibleRect.y2 = 0.0;
  this->Geom.HScrollOffset = 0;
  this->Geom.Flags = 0;
  this->Geom.VisibleRect.x1 = 0.0;
  this->Geom.VisibleRect.y1 = 0.0;
  v1 = 0.0 + 0.0;
  this->Geom.VisibleRect.x2 = v1;
  this->Geom.VisibleRect.y2 = v1;
  this->LastHScrollOffset = -1;
}
