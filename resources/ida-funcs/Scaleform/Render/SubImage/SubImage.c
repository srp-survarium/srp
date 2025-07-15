void __thiscall Scaleform::Render::SubImage::SubImage(
        Scaleform::Render::SubImage *this,
        Scaleform::Render::Image *pimage,
        const Scaleform::Render::Rect<unsigned long> *rect)
{
  unsigned int y2; // ecx
  unsigned int x2; // edx
  unsigned int y1; // edi

  this->__vftable = (Scaleform::Render::SubImage_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->__vftable = (Scaleform::Render::SubImage_vtbl *)&Scaleform::Render::Image::`vftable';
  InterlockedExchange((volatile LONG *)&this->pTexture, 0);
  this->pUpdateSync = 0;
  this->pInverseMatrix = 0;
  this->__vftable = (Scaleform::Render::SubImage_vtbl *)&Scaleform::Render::SubImage::`vftable';
  if ( pimage )
    pimage->AddRef(pimage);
  this->pImage.pObject = pimage;
  y2 = rect->y2;
  x2 = rect->x2;
  y1 = rect->y1;
  this->SubRect.x1 = rect->x1;
  this->SubRect.y1 = y1;
  this->SubRect.x2 = x2;
  this->SubRect.y2 = y2;
  this->ImageId = Scaleform::Render::ImageBase::GetNextImageId();
}
