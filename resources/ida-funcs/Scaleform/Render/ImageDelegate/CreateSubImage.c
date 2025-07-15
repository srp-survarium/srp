Scaleform::Render::Image *__thiscall Scaleform::Render::ImageDelegate::CreateSubImage(
        Scaleform::Render::ImageDelegate *this,
        const Scaleform::Render::Rect<unsigned long> *rect,
        Scaleform::MemoryHeap *pheap)
{
  return this->pImage.pObject->CreateSubImage(this->pImage.pObject, rect, pheap);
}
