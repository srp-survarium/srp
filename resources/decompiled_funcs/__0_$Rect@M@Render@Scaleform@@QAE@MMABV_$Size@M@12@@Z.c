void __thiscall Scaleform::Render::Rect<float>::Rect<float>(
        Scaleform::Render::Rect<float> *this,
        float x,
        float y,
        const Scaleform::Render::Size<float> *sz)
{
  float v4; // xmm0_4
  float v5; // xmm1_4

  v4 = sz->Width + x;
  v5 = sz->Height + y;
  this->x1 = x;
  this->y1 = y;
  this->x2 = v4;
  this->y2 = v5;
}
