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
  Scaleform::Render::Rect<long> srcClippedRect; // [esp+Ch] [ebp-30h] BYREF
  Scaleform::Render::Rect<long> srcImageRect; // [esp+1Ch] [ebp-20h] BYREF
  Scaleform::Render::Rect<long> dstImageRect; // [esp+2Ch] [ebp-10h] BYREF

  v6 = this->DestPoint.y - srcRect->y1;
  delta->x = this->DestPoint.x - srcRect->x1;
  delta->y = v6;
  Width = srcSize->Width;
  srcImageRect.y2 = srcSize->Height;
  srcImageRect.x2 = Width;
  v8 = destSize->Width;
  dstImageRect.y2 = destSize->Height;
  srcImageRect.x1 = 0;
  srcImageRect.y1 = 0;
  dstImageRect.x1 = 0;
  dstImageRect.y1 = 0;
  dstImageRect.x2 = v8;
  memset(&srcClippedRect, 0, sizeof(srcClippedRect));
  result = Scaleform::Render::Rect<long>::IntersectRect(&srcImageRect, &srcClippedRect, srcRect);
  if ( result )
  {
    v10 = srcClippedRect.x2 + delta->x;
    srcImageRect.x1 = delta->x + srcClippedRect.x1;
    srcImageRect.x2 = v10;
    srcImageRect.y1 = v6 + srcClippedRect.y1;
    srcImageRect.y2 = v6 + srcClippedRect.y2;
    return Scaleform::Render::Rect<long>::IntersectRect(&srcImageRect, dstClippedRect, &dstImageRect) != 0;
  }
  return result;
}
