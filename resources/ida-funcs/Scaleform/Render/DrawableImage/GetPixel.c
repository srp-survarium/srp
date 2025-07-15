Scaleform::Render::Color *__thiscall Scaleform::Render::DrawableImage::GetPixel(
        Scaleform::Render::DrawableImage *this,
        Scaleform::Render::Color *result,
        int x,
        int y)
{
  Scaleform::Render::DrawableImage::GetPixel32(this, result, x, y);
  result->Channels.Alpha = 0;
  return result;
}
