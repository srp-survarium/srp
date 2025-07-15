Scaleform::Render::Rect<float> *__thiscall Scaleform::GFx::DisplayObjContainer::GetBounds(
        Scaleform::GFx::DisplayObjContainer *this,
        Scaleform::Render::Rect<float> *result,
        const Scaleform::Render::Matrix2x4<float> *t)
{
  Scaleform::GFx::DisplayList::GetBounds(&this->mDisplayList, result, t);
  return result;
}
