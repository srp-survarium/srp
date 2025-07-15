void __thiscall Scaleform::GFx::AS2::BitmapFilterObject::SetBlurY(
        Scaleform::GFx::AS2::BitmapFilterObject *this,
        float b)
{
  float v2; // [esp+4h] [ebp+4h]

  v2 = b * 20.0;
  Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams(this)->BlurY = v2;
}
