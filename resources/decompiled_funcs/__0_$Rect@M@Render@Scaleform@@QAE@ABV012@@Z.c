void __thiscall Scaleform::Render::Rect<float>::Rect<float>(
        Scaleform::Render::Rect<float> *this,
        const Scaleform::Render::Rect<float> *rc)
{
  float y1; // xmm0_4
  float x2; // xmm1_4
  float y2; // xmm2_4

  y1 = rc->y1;
  x2 = rc->x2;
  y2 = rc->y2;
  this->x1 = rc->x1;
  this->y1 = y1;
  this->x2 = x2;
  this->y2 = y2;
}
