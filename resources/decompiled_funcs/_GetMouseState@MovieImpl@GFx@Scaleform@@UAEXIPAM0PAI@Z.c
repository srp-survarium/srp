void __thiscall Scaleform::GFx::MovieImpl::GetMouseState(
        Scaleform::GFx::MovieImpl *this,
        unsigned int mouseIndex,
        float *x,
        float *y,
        unsigned int *buttons)
{
  float *v5; // eax
  float p; // [esp+0h] [ebp-8h]
  float p_4; // [esp+4h] [ebp-4h]
  float mouseIndexa; // [esp+Ch] [ebp+4h]
  float mouseIndexb; // [esp+Ch] [ebp+4h]

  if ( mouseIndex < this->MouseCursorCount )
  {
    v5 = (float *)((char *)this + 56 * mouseIndex);
    mouseIndexa = v5[1155] * 0.05000000074505806;
    p = (mouseIndexa - this->ViewOffsetX) / this->ViewScaleX;
    mouseIndexb = 0.05000000074505806 * v5[1156];
    p_4 = (mouseIndexb - this->ViewOffsetY) / this->ViewScaleY;
    if ( x )
      *x = p;
    if ( y )
      *y = p_4;
    if ( buttons )
      *buttons = *((_DWORD *)v5 + 1153);
  }
}
