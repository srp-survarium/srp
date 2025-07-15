Scaleform::Render::Rect<float> *__thiscall Scaleform::GFx::DrawTextImpl::GetRect(
        Scaleform::GFx::DrawTextImpl *this,
        Scaleform::Render::Rect<float> *result)
{
  Scaleform::Render::Rect<float> *Bounds; // eax
  double v3; // st7
  Scaleform::Render::Rect<float> *v4; // eax
  Scaleform::Render::Rect<float> resulta; // [esp+0h] [ebp-10h] BYREF

  Bounds = Scaleform::Render::TreeText::GetBounds(this->pTextNode.pObject, &resulta);
  result->x1 = Bounds->x1 * 0.05000000074505806;
  result->y1 = Bounds->y1 * 0.05000000074505806;
  result->x2 = Bounds->x2 * 0.05000000074505806;
  v3 = 0.05000000074505806 * Bounds->y2;
  v4 = result;
  result->y2 = v3;
  return v4;
}
