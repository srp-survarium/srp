Scaleform::Render::Rect<float> *__thiscall Scaleform::GFx::TextField::GetBounds(
        Scaleform::GFx::TextField *this,
        Scaleform::Render::Rect<float> *result,
        Scaleform::Render::Matrix2x4<float> *t)
{
  __m128 *ViewRect; // eax

  ViewRect = (__m128 *)Scaleform::Render::Text::DocView::GetViewRect(this->pDocument.pObject);
  Scaleform::Render::Matrix2x4<float>::EncloseTransform(t, result, ViewRect);
  return result;
}
