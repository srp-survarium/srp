void __thiscall Scaleform::GFx::AS2::AvmSprite::SetLineStyle(
        Scaleform::GFx::AS2::AvmSprite *this,
        float lineWidth,
        unsigned int rgba,
        bool hinting,
        unsigned int scaling,
        unsigned int caps,
        unsigned int joins,
        float miterLimit)
{
  Scaleform::GFx::DrawingContext *v8; // eax
  float v10; // [esp+38h] [ebp+1Ch]

  v8 = this->pDispObj->GetDrawingContext(this->pDispObj);
  v10 = lineWidth * 20.0;
  Scaleform::GFx::DrawingContext::ChangeLineStyle(v8, v10, rgba, hinting, scaling, caps, joins, miterLimit);
}
