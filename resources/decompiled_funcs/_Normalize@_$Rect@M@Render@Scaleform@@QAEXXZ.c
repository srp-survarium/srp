void __thiscall Scaleform::Render::Rect<float>::Normalize(Scaleform::Render::Rect<float> *this)
{
  float x1; // [esp+0h] [ebp-4h]
  float y1; // [esp+0h] [ebp-4h]

  if ( this->x2 < (double)this->x1 )
  {
    x1 = this->x1;
    this->x1 = this->x2;
    this->x2 = x1;
  }
  if ( this->y2 < (double)this->y1 )
  {
    y1 = this->y1;
    this->y1 = this->y2;
    this->y2 = y1;
  }
}
