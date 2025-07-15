void __thiscall Scaleform::Render::ImageData::~ImageData(Scaleform::Render::ImageData *this)
{
  Scaleform::Render::Palette *pObject; // ecx

  Scaleform::Render::ImageData::freePlanes(this);
  pObject = this->pPalette.pObject;
  if ( pObject )
    Scaleform::Render::Palette::Release(pObject);
}
