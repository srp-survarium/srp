Scaleform::String *__thiscall Scaleform::GFx::AS3::AvmBitmap::GetASClassName(
        Scaleform::GFx::AS3::AvmBitmap *this,
        Scaleform::String *className)
{
  Scaleform::String::operator=(className, "flash.display.Bitmap");
  return className;
}
