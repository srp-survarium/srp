void __thiscall Scaleform::Render::Image::CreateSubImage(
        Scaleform::Render::Image *this,
        const Scaleform::Render::Rect<unsigned long> *rect,
        Scaleform::MemoryHeap *pheap)
{
  Scaleform::Render::SubImage *v4; // eax

  v4 = (Scaleform::Render::SubImage *)pheap->Alloc(pheap, 40, 0);
  if ( v4 )
    Scaleform::Render::SubImage::SubImage(v4, this, rect);
}
