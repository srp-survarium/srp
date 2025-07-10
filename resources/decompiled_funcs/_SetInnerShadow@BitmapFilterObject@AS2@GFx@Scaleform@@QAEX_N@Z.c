void __thiscall Scaleform::GFx::AS2::BitmapFilterObject::SetInnerShadow(
        Scaleform::GFx::AS2::BitmapFilterObject *this,
        bool i)
{
  Scaleform::Render::BlurFilterParams *v2; // eax

  v2 = Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams(this);
  if ( i )
    v2->Mode |= 0x20u;
  else
    v2->Mode &= ~0x20u;
}
