void __thiscall Scaleform::Render::Text::LineBuffer::SetFirstVisibleLine(
        Scaleform::Render::Text::LineBuffer *this,
        unsigned int line)
{
  this->Geom.FirstVisibleLinePos = line;
  this->Geom.Flags |= 1u;
}
