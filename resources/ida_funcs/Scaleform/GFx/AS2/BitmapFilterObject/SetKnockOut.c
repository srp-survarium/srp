void __thiscall Scaleform::GFx::AS2::BitmapFilterObject::SetKnockOut(
        Scaleform::GFx::AS2::BitmapFilterObject *this,
        bool k)
{
  Scaleform::Render::BlurFilterParams *v2; // eax

  v2 = Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams(this);
  if ( k )
    v2->Mode |= 0x10u;
  else
    v2->Mode &= ~0x10u;
}
