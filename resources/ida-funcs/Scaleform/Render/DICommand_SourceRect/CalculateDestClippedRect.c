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
  Scaleform::Render::Size<unsigned long> v13; // [esp+0h] [ebp-10h] BYREF
  Scaleform::Render::Size<unsigned long> v14; // [esp+8h] [ebp-8h] BYREF

  pPlanes = dest->pPlanes;
  Width = pPlanes->Width;
  Height = pPlanes->Height;
  v13.Width = Width;
  v13.Height = Height;
  v9 = src->pPlanes;
  v10 = v9->Width;
  v11 = v9->Height;
  v14.Width = v10;
  v14.Height = v11;
  return Scaleform::Render::DICommand_SourceRect::CalculateDestClippedRect(
           this,
           &v14,
           &v13,
           srcRect,
           dstClippedRect,
           delta);
}


char __thiscall Scaleform::Render::DICommand_SourceRect::CalculateDestClippedRect(
        Scaleform::Render::DICommand_SourceRect *this,
        const Scaleform::Render::Size<unsigned long> *srcSize,
        const Scaleform::Render::Size<unsigned long> *destSize,
        const Scaleform::Render::Rect<long> *srcRect,
        Scaleform::Render::Rect<long> *dstClippedRect,
        Scaleform::Render::Point<long> *delta)
{
  int v6; // esi
  unsigned int Width; // ebx
  unsigned int v8; // ebx
  char result; // al
  int v10; // eax
  Scaleform::Render::Rect<long> v11; // [esp+Ch] [ebp-30h] BYREF
  Scaleform::Render::Rect<long> v12; // [esp+1Ch] [ebp-20h] BYREF
  Scaleform::Render::Rect<long> v13; // [esp+2Ch] [ebp-10h] BYREF

  v6 = this->DestPoint.y - srcRect->y1;
  delta->x = this->DestPoint.x - srcRect->x1;
  delta->y = v6;
  Width = srcSize->Width;
  v12.y2 = srcSize->Height;
  v12.x2 = Width;
  v8 = destSize->Width;
  v13.y2 = destSize->Height;
  v12.x1 = 0;
  v12.y1 = 0;
  v13.x1 = 0;
  v13.y1 = 0;
  v13.x2 = v8;
  memset(&v11, 0, sizeof(v11));
  result = Scaleform::Render::Rect<long>::IntersectRect(&v12, &v11, srcRect);
  if ( result )
  {
    v10 = v11.x2 + delta->x;
    v12.x1 = delta->x + v11.x1;
    v12.x2 = v10;
    v12.y1 = v6 + v11.y1;
    v12.y2 = v6 + v11.y2;
    return Scaleform::Render::Rect<long>::IntersectRect(&v12, dstClippedRect, &v13) != 0;
  }
  return result;
}
