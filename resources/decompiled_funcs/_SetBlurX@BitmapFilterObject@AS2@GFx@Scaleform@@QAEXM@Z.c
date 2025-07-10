void __thiscall Scaleform::GFx::AS2::BitmapFilterObject::SetBlurX(
        Scaleform::GFx::AS2::BitmapFilterObject *this,
        float b)
{
  float ba; // [esp+4h] [ebp+4h]

  ba = b * 20.0;
  Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams(this)->BlurX = ba;
}
