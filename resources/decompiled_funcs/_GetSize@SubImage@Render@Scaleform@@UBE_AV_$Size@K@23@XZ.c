Scaleform::Render::Size<unsigned long> *__thiscall Scaleform::Render::SubImage::GetSize(
        Scaleform::Render::SubImage *this,
        Scaleform::Render::Size<unsigned long> *result)
{
  this->pImage.pObject->GetSize(this->pImage.pObject, result);
  return result;
}
