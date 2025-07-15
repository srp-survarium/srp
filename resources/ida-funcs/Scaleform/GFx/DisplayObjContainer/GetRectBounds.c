Scaleform::Render::Rect<float> *__thiscall Scaleform::GFx::DisplayObjContainer::GetRectBounds(
        Scaleform::GFx::Sprite *this,
        Scaleform::Render::Rect<float> *result,
        const Scaleform::Render::Matrix2x4<float> *transform)
{
  Scaleform::GFx::DisplayList::GetRectBounds(&this->mDisplayList, result, transform);
  return result;
}
