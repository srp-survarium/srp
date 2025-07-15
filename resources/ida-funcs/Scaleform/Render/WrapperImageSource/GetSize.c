Scaleform::Render::Size<unsigned long> *__thiscall Scaleform::Render::WrapperImageSource::GetSize(
        Scaleform::Render::WrapperImageSource *this,
        Scaleform::Render::Size<unsigned long> *result)
{
  this->pDelegate.pObject->GetSize(this->pDelegate.pObject, result);
  return result;
}
