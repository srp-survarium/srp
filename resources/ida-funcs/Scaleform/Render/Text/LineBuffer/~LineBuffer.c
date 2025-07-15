void __thiscall Scaleform::Render::Text::LineBuffer::~LineBuffer(Scaleform::Render::Text::LineBuffer *this)
{
  this->Geom.Flags |= 1u;
  Scaleform::Render::Text::LineBuffer::RemoveLines(this, 0, this->Lines.Data.Size);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Lines.Data.Data);
}
