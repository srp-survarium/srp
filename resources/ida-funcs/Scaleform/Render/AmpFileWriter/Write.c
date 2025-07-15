char __thiscall Scaleform::Render::AmpFileWriter::Write(
        Scaleform::Render::AmpFileWriter *this,
        Scaleform::File *file,
        Scaleform::Render::ImageData *imageData,
        const Scaleform::Render::ImageWriteArgs *args)
{
  Scaleform::Render::ImageData::Write(imageData, (unsigned int)file, this->Version);
  return 1;
}
