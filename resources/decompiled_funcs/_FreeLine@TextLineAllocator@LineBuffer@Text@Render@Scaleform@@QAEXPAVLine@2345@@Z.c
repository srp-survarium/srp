void __thiscall Scaleform::Render::Text::LineBuffer::TextLineAllocator::FreeLine(
        Scaleform::Render::Text::LineBuffer::TextLineAllocator *this,
        Scaleform::Render::Text::LineBuffer::Line *ptr)
{
  if ( ptr )
  {
    Scaleform::Render::Text::LineBuffer::Line::Release(ptr);
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, ptr);
  }
}
