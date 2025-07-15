char __thiscall Scaleform::Render::DICommand::executeSWHelper(
        Scaleform::Render::DICommand *this,
        Scaleform::Render::DICommandContext *context,
        Scaleform::Render::DrawableImage *di,
        Scaleform::Render::DISourceImages *images,
        unsigned int imageCount)
{
  Scaleform::Render::ImageData *MappedData; // ebp
  Scaleform::Render::DrawableImage *v7; // eax
  void (__thiscall *ExecuteSW)(Scaleform::Render::DICommand *, Scaleform::Render::DICommandContext *, Scaleform::Render::ImageData *, Scaleform::Render::ImageData **); // edx
  Scaleform::Render::ImageData *v10; // [esp+10h] [ebp-58h] BYREF
  Scaleform::Render::ImageData *v11; // [esp+14h] [ebp-54h]
  Scaleform::Render::ImageData v12; // [esp+18h] [ebp-50h] BYREF
  Scaleform::Render::ImageData v13; // [esp+40h] [ebp-28h] BYREF

  MappedData = Scaleform::Render::DrawableImage::getMappedData(di);
  if ( imageCount )
  {
    v12.RawPlaneCount = 1;
    v13.pPlanes = &v13.Plane0;
    v7 = (Scaleform::Render::DrawableImage *)images->pImages[0];
    memset(&v12, 0, 10);
    v12.pPlanes = &v12.Plane0;
    memset(&v12.pPalette, 0, 24);
    memset(&v13, 0, 10);
    v13.RawPlaneCount = 1;
    memset(&v13.pPalette, 0, 24);
    v10 = 0;
    v11 = 0;
    if ( v7 && !Scaleform::Render::DrawableImage::MapImageSource(&v12, v7)
      || (v10 = &v12, images->pImages[1])
      && !Scaleform::Render::DrawableImage::MapImageSource(&v13, (Scaleform::Render::DrawableImage *)images->pImages[1]) )
    {
      `vector destructor iterator'(
        (char *)&v12,
        0x28u,
        2,
        (void (__thiscall *)(void *))Scaleform::Render::ImageData::~ImageData);
      return 0;
    }
    ExecuteSW = this->ExecuteSW;
    v11 = &v13;
    ExecuteSW(this, context, MappedData, &v10);
    `vector destructor iterator'(
      (char *)&v12,
      0x28u,
      2,
      (void (__thiscall *)(void *))Scaleform::Render::ImageData::~ImageData);
  }
  else
  {
    this->ExecuteSW(this, context, MappedData, 0);
  }
  if ( (this->GetRenderCaps(this) & 0x20) == 0 )
    Scaleform::Render::DrawableImage::addToCPUModifiedList(di);
  return 1;
}
