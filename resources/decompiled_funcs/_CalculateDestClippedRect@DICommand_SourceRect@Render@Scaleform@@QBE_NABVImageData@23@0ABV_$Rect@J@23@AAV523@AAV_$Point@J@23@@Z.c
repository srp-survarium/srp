char __thiscall Scaleform::Render::DICommand_SourceRect::CalculateDestClippedRect(
        Scaleform::Render::DICommand_SourceRect *this,
        const Scaleform::Render::ImageData *src,
        const Scaleform::Render::ImageData *dest,
        const Scaleform::Render::Rect<long> *srcRect,
        Scaleform::Render::Rect<long> *dstClippedRect,
        Scaleform::Render::Point<long> *delta)
{
  Scaleform::Render::ImagePlane *pPlanes; // eax
  unsigned int Width; // edx
  unsigned int Height; // eax
  Scaleform::Render::ImagePlane *v9; // eax
  unsigned int v10; // edx
  unsigned int v11; // eax
  Scaleform::Render::Size<unsigned long> destSize; // [esp+0h] [ebp-10h] BYREF
  Scaleform::Render::Size<unsigned long> srcSize; // [esp+8h] [ebp-8h] BYREF

  pPlanes = dest->pPlanes;
  Width = pPlanes->Width;
  Height = pPlanes->Height;
  destSize.Width = Width;
  destSize.Height = Height;
  v9 = src->pPlanes;
  v10 = v9->Width;
  v11 = v9->Height;
  srcSize.Width = v10;
  srcSize.Height = v11;
  return Scaleform::Render::DICommand_SourceRect::CalculateDestClippedRect(
           this,
           &srcSize,
           &destSize,
           srcRect,
           dstClippedRect,
           delta);
}
