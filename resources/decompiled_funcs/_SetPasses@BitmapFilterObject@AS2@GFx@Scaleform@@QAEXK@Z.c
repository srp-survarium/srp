void __thiscall Scaleform::GFx::AS2::BitmapFilterObject::SetPasses(
        Scaleform::GFx::AS2::BitmapFilterObject *this,
        unsigned int d)
{
  unsigned int v2; // esi

  v2 = d;
  if ( d >= 0xF )
    v2 = 15;
  Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams(this)->Passes = v2;
}
