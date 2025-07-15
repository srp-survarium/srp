void __thiscall Scaleform::Render::TGA::TGAFileImageSource::TGAFileImageSource(
        Scaleform::Render::TGA::TGAFileImageSource *this,
        Scaleform::GFx::Resource *file,
        Scaleform::Render::ImageFormat format)
{
  Scaleform::Render::FileImageSource::FileImageSource(this, file, format, 0);
  this->__vftable = (Scaleform::Render::TGA::TGAFileImageSource_vtbl *)&Scaleform::Render::TGA::TGAFileImageSource::`vftable';
  this->SourceFormat = Image_None;
  this->ImageDesc = 0;
  this->pColorMap.pObject = 0;
}
