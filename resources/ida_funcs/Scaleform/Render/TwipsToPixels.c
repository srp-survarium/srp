Scaleform::Render::Rect<float> *__cdecl Scaleform::Render::TwipsToPixels(
        Scaleform::Render::Rect<float> *result,
        const Scaleform::Render::Rect<float> *x)
{
  Scaleform::Render::Rect<float> *v2; // eax

  v2 = result;
  result->x1 = x->x1 * 0.05000000074505806;
  result->y1 = x->y1 * 0.05000000074505806;
  result->x2 = x->x2 * 0.05000000074505806;
  result->y2 = 0.05000000074505806 * x->y2;
  return v2;
}
