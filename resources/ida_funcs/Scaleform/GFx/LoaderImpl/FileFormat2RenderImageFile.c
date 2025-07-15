Scaleform::Render::ImageFileFormat __cdecl Scaleform::GFx::LoaderImpl::FileFormat2RenderImageFile(
        Scaleform::GFx::FileTypeConstants::FileFormatType format)
{
  Scaleform::Render::ImageFileFormat result; // eax

  switch ( format )
  {
    case File_JPEG:
      result = ImageFile_JPEG;
      break;
    case File_PNG:
      result = ImageFile_PNG;
      break;
    case File_TGA:
      result = ImageFile_TGA;
      break;
    case File_DDS:
      result = ImageFile_DDS;
      break;
    case File_PVR:
      result = ImageFile_PVR;
      break;
    case File_SIF:
      result = ImageFile_SIF;
      break;
    case File_GXT:
      result = ImageFile_GXT;
      break;
    default:
      result = ImageFile_Unknown;
      break;
  }
  return result;
}
