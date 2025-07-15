void __thiscall Scaleform::Render::PNG::PNGFileImageSource::PNGFileImageSource(
        Scaleform::Render::PNG::PNGFileImageSource *this,
        Scaleform::File *file,
        Scaleform::Render::ImageFormat format)
{
  Scaleform::Render::FileImageSource::FileImageSource(this, file, format, 0);
  this->__vftable = (Scaleform::Render::PNG::PNGFileImageSource_vtbl *)&Scaleform::Render::PNG::PNGFileImageSource::`vftable';
  this->SourceFormat = Image_None;
  this->pOriginalInput = 0;
}
