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
  Scaleform::Render::ImageData *ipdata[2]; // [esp+10h] [ebp-58h] BYREF
  Scaleform::Render::ImageData idata[2]; // [esp+18h] [ebp-50h] BYREF

  MappedData = Scaleform::Render::DrawableImage::getMappedData(di);
  if ( imageCount )
  {
    idata[0].RawPlaneCount = 1;
    idata[1].pPlanes = &idata[1].Plane0;
    v7 = (Scaleform::Render::DrawableImage *)images->pImages[0];
    memset(idata, 0, 10);
    idata[0].pPlanes = &idata[0].Plane0;
    idata[0].pPalette.pObject = 0;
    idata[0].Plane0.Width = 0;
    idata[0].Plane0.Height = 0;
    idata[0].Plane0.Pitch = 0;
    idata[0].Plane0.DataSize = 0;
    idata[0].Plane0.pData = 0;
    memset(&idata[1], 0, 10);
    idata[1].RawPlaneCount = 1;
    idata[1].pPalette.pObject = 0;
    idata[1].Plane0.Width = 0;
    idata[1].Plane0.Height = 0;
    idata[1].Plane0.Pitch = 0;
    idata[1].Plane0.DataSize = 0;
    idata[1].Plane0.pData = 0;
    ipdata[0] = 0;
    ipdata[1] = 0;
    if ( v7 && !Scaleform::Render::DrawableImage::MapImageSource(idata, v7)
      || (ipdata[0] = idata, images->pImages[1])
      && !Scaleform::Render::DrawableImage::MapImageSource(
            &idata[1],
            (Scaleform::Render::DrawableImage *)images->pImages[1]) )
    {
      `vector destructor iterator'(
        (char *)idata,
        0x28u,
        2,
        (void (__thiscall *)(void *))Scaleform::Render::ImageData::~ImageData);
      return 0;
    }
    ExecuteSW = this->ExecuteSW;
    ipdata[1] = &idata[1];
    ExecuteSW(this, context, MappedData, ipdata);
    `vector destructor iterator'(
      (char *)idata,
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
