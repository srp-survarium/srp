void __thiscall Scaleform::GFx::SubImageResource::SubImageResource(
        Scaleform::GFx::SubImageResource *this,
        int pbase,
        Scaleform::GFx::ResourceId baseid,
        const Scaleform::Render::Rect<unsigned long> *rect,
        Scaleform::MemoryHeap *pheap)
{
  Scaleform::GFx::ImageResource *v5; // ebx
  Scaleform::Render::ImageBase *v6; // eax
  Scaleform::Render::SubImage *v8; // eax
  const Scaleform::Render::Rect<unsigned long> *v9; // edi
  Scaleform::Render::Image *v10; // eax
  Scaleform::Render::Image *v11; // ebx
  unsigned int y2; // eax
  unsigned int x2; // ecx
  unsigned int y1; // edx
  unsigned int x1; // edi
  unsigned int Id; // ecx

  v5 = (Scaleform::GFx::ImageResource *)pbase;
  v6 = *(Scaleform::Render::ImageBase **)(pbase + 12);
  pbase = 3;
  v8 = (Scaleform::Render::SubImage *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                        Scaleform::Memory::pGlobalHeap,
                                        v6,
                                        40,
                                        &pbase);
  v9 = rect;
  if ( v8 )
  {
    Scaleform::Render::SubImage::SubImage(v8, (Scaleform::Render::Image *)v5->pImage, rect);
    v11 = v10;
  }
  else
  {
    v11 = 0;
  }
  Scaleform::GFx::ImageResource::ImageResource(this, v11, Use_Bitmap);
  if ( v11 )
    v11->Release(v11);
  this->__vftable = (Scaleform::GFx::SubImageResource_vtbl *)&Scaleform::GFx::SubImageResource::`vftable';
  y2 = v9->y2;
  x2 = v9->x2;
  y1 = v9->y1;
  x1 = v9->x1;
  this->Rect.x2 = x2;
  Id = baseid.Id;
  this->Rect.x1 = x1;
  this->Rect.y2 = y2;
  this->Rect.y1 = y1;
  this->BaseImageId.Id = Id;
}
