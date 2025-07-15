Scaleform::Render::ImageUpdateSync *__thiscall Scaleform::Render::ImageCreateArgs::GetUpdateSync(
        Scaleform::Render::ImageCreateArgs *this)
{
  Scaleform::Render::ImageUpdateSync *result; // eax
  Scaleform::Render::TextureManager *pManager; // ecx

  result = this->pUpdateSync;
  if ( !result )
  {
    pManager = this->pManager;
    if ( pManager )
      return &pManager->Scaleform::Render::ImageUpdateSync;
    else
      return 0;
  }
  return result;
}
