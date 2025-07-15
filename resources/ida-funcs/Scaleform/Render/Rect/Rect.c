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


void __thiscall Scaleform::Render::Rect<double>::Rect<double>(
        Scaleform::Render::Rect<double> *this,
        const Scaleform::Render::Rect<double> *rc)
{
  long double y1; // st7
  long double x2; // st6
  long double y2; // st5

  y1 = rc->y1;
  x2 = rc->x2;
  y2 = rc->y2;
  this->x1 = rc->x1;
  this->y1 = y1;
  this->x2 = x2;
  this->y2 = y2;
}


void __thiscall Scaleform::Render::Rect<double>::Rect<double>(
        Scaleform::Render::Rect<double> *this,
        long double x,
        long double y,
        const Scaleform::Render::Size<double> *sz)
{
  long double v4; // st7
  long double v5; // st5

  v4 = sz->Width + x;
  v5 = sz->Height + y;
  this->x1 = x;
  this->y1 = y;
  this->x2 = v4;
  this->y2 = v5;
}
