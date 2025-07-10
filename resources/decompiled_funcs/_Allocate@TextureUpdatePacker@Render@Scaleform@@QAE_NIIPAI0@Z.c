char __thiscall Scaleform::Render::TextureUpdatePacker::Allocate(
        Scaleform::Render::TextureUpdatePacker *this,
        unsigned int w,
        unsigned int h,
        unsigned int *x,
        unsigned int *y)
{
  unsigned int LastX; // edx

  LastX = this->LastX;
  if ( LastX + w > this->Width || h + this->LastY > this->Height )
  {
    this->LastY += this->LastMaxHeight;
    if ( h + this->LastY > this->Height )
    {
      return 0;
    }
    else
    {
      *x = 0;
      *y = this->LastY;
      this->LastX = w;
      this->LastMaxHeight = h;
      return 1;
    }
  }
  else
  {
    *x = LastX;
    *y = this->LastY;
    this->LastX += w;
    if ( h > this->LastMaxHeight )
      this->LastMaxHeight = h;
    return 1;
  }
}
