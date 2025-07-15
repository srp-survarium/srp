void __thiscall Scaleform::Render::SIF::SIFFileImageSource::SIFFileImageSource(
        Scaleform::Render::SIF::SIFFileImageSource *this,
        Scaleform::GFx::Resource *file,
        Scaleform::Render::ImageFormat format)
{
  Scaleform::Render::FileImageSource::FileImageSource(this, file, format, 0);
  this->__vftable = (Scaleform::Render::SIF::SIFFileImageSource_vtbl *)&Scaleform::Render::SIF::SIFFileImageSource::`vftable';
  this->Data.Format = Image_None;
  this->Data.Use = 0;
  this->Data.Flags = 0;
  this->Data.LevelCount = 0;
  this->Data.pPlanes = &this->Data.Plane0;
  this->Data.RawPlaneCount = 1;
  this->Data.pPalette.pObject = 0;
  this->Data.Plane0.Width = 0;
  this->Data.Plane0.Height = 0;
  this->Data.Plane0.Pitch = 0;
  this->Data.Plane0.DataSize = 0;
  this->Data.Plane0.pData = 0;
}
