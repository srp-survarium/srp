Scaleform::Render::Rect<float> *__thiscall Scaleform::GFx::MovieImpl::GetVisibleFrameRect(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::Render::Rect<float> *result)
{
  Scaleform::Render::Rect<float> *v2; // eax

  v2 = result;
  result->x1 = this->VisibleFrameRect.x1 * 0.05000000074505806;
  result->y1 = this->VisibleFrameRect.y1 * 0.05000000074505806;
  result->x2 = this->VisibleFrameRect.x2 * 0.05000000074505806;
  result->y2 = 0.05000000074505806 * this->VisibleFrameRect.y2;
  return v2;
}
