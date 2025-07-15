void __thiscall Scaleform::GFx::DisplayObject::ScrollRectInfo::ScrollRectInfo(
        Scaleform::GFx::DisplayObject::ScrollRectInfo *this)
{
  float *p_OrigTransformMatrix; // edi

  this->Rectangle.x1 = 0.0;
  this->Rectangle.y1 = 0.0;
  this->Rectangle.x2 = 0.0;
  p_OrigTransformMatrix = (float *)&this->OrigTransformMatrix;
  this->Rectangle.y2 = 0.0;
  this->Mask.pObject = 0;
  memset((int)&this->OrigTransformMatrix, 0, sizeof(this->OrigTransformMatrix));
  *p_OrigTransformMatrix = 1.0;
  p_OrigTransformMatrix[5] = 1.0;
  p_OrigTransformMatrix[10] = 1.0;
}
