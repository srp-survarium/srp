int __thiscall Scaleform::Render::SubImage::GetBaseImageId(Scaleform::Render::SubImage *this)
{
  Scaleform::Render::Image *pObject; // ecx

  pObject = this->pImage.pObject;
  if ( pObject )
    return pObject->GetImageId(pObject);
  else
    return 0;
}
