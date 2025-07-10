Scaleform::Render::Rect<unsigned long> *__thiscall Scaleform::Render::ImageDelegate::GetRect(
        Scaleform::Render::ImageDelegate *this,
        Scaleform::Render::Rect<unsigned long> *result)
{
  this->pImage.pObject->GetRect(this->pImage.pObject, result);
  return result;
}
