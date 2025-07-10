void __thiscall Scaleform::Render::DDS::DDSFileImageSource::DDSFileImageSource(
        Scaleform::Render::DDS::DDSFileImageSource *this,
        Scaleform::File *file,
        Scaleform::Render::ImageFormat format)
{
  unsigned __int8 ShiftA; // al

  Scaleform::Render::FileImageSource::FileImageSource(this, file, format, 0);
  this->ImageDesc = 0;
  this->__vftable = (Scaleform::Render::DDS::DDSFileImageSource_vtbl *)&Scaleform::Render::DDS::DDSFileImageSource::`vftable';
  this->HeaderInfo.Width = 0;
  this->HeaderInfo.Height = 0;
  this->HeaderInfo.Pitch = 0;
  this->HeaderInfo.Format = Image_None;
  this->HeaderInfo.MipmapCount = 1;
  ShiftA = this->HeaderInfo.DDSFmt.ShiftA;
  this->HeaderInfo.DDSFmt.ABitMask = 0;
  this->HeaderInfo.DDSFmt.BBitMask = 0;
  this->HeaderInfo.DDSFmt.GBitMask = 0;
  this->HeaderInfo.DDSFmt.RBitMask = 0;
  this->HeaderInfo.DDSFmt.RGBBitCount = 0;
  this->HeaderInfo.DDSFmt.ShiftB = ShiftA;
  this->HeaderInfo.DDSFmt.ShiftG = ShiftA;
  this->HeaderInfo.DDSFmt.ShiftR = ShiftA;
  this->HeaderInfo.DDSFmt.HasAlpha = 0;
  this->HeaderInfo.OppositeEndian = 0;
}
