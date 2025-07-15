void __thiscall Scaleform::GFx::AS2::BitmapFilterObject::SetHideObject(
        Scaleform::GFx::AS2::BitmapFilterObject *this,
        bool h)
{
  Scaleform::Render::BlurFilterParams *v2; // eax

  v2 = Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams(this);
  if ( h )
    v2->Mode |= 0x40u;
  else
    v2->Mode &= ~0x40u;
}
