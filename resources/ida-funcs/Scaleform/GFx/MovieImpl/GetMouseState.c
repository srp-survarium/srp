Scaleform::GFx::MouseState *__thiscall Scaleform::GFx::MovieImpl::GetMouseState(
        Scaleform::GFx::MovieImpl *this,
        unsigned int mouseIndex)
{
  if ( mouseIndex < 6 )
    return &this->mMouseState[mouseIndex];
  else
    return 0;
}


void __thiscall Scaleform::GFx::MovieImpl::GetMouseState(
        Scaleform::GFx::MovieImpl *this,
        unsigned int mouseIndex,
        float *x,
        float *y,
        unsigned int *buttons)
{
  float *v5; // eax
  float v6; // [esp+0h] [ebp-8h]
  float v7; // [esp+4h] [ebp-4h]
  float v8; // [esp+Ch] [ebp+4h]
  float v9; // [esp+Ch] [ebp+4h]

  if ( mouseIndex < this->MouseCursorCount )
  {
    v5 = (float *)((char *)this + 56 * mouseIndex);
    v8 = v5[1155] * 0.05000000074505806;
    v6 = (v8 - this->ViewOffsetX) / this->ViewScaleX;
    v9 = 0.05000000074505806 * v5[1156];
    v7 = (v9 - this->ViewOffsetY) / this->ViewScaleY;
    if ( x )
      *x = v6;
    if ( y )
      *y = v7;
    if ( buttons )
      *buttons = *((_DWORD *)v5 + 1153);
  }
}
