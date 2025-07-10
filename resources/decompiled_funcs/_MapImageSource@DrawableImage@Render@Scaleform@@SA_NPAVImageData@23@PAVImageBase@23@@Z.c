char __cdecl Scaleform::Render::DrawableImage::MapImageSource(
        Scaleform::Render::ImageData *data,
        Scaleform::Render::DrawableImage *i)
{
  const Scaleform::Render::ImageData *MappedData; // eax

  if ( data && i )
  {
    if ( i->GetImageType(i) == Type_DrawableImage )
    {
      if ( (i->DrawableImageState & 3) != 0 || Scaleform::Render::DrawableImage::mapTextureRT(i, 1, 0) )
      {
        MappedData = Scaleform::Render::DrawableImage::getMappedData(i);
        Scaleform::Render::ImageData::operator=(data, MappedData);
        return 1;
      }
    }
    else if ( i->GetImageType(i) == Type_RawImage
           && (i->GetFormat(i) == Image_B8G8R8A8 || i->GetFormat(i) == Image_R8G8B8A8) )
    {
      Scaleform::Render::RawImage::GetImageData((Scaleform::Render::RawImage *)i, data);
      return 1;
    }
  }
  return 0;
}
