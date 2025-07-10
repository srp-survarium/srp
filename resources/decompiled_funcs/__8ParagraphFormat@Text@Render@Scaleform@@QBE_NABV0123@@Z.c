BOOL __thiscall Scaleform::Render::Text::ParagraphFormat::operator==(
        Scaleform::Render::Text::ParagraphFormat *this,
        const Scaleform::Render::Text::ParagraphFormat *f)
{
  return this->PresentMask == f->PresentMask
      && this->BlockIndent == f->BlockIndent
      && this->Indent == f->Indent
      && this->Leading == f->Leading
      && this->LeftMargin == f->LeftMargin
      && this->RightMargin == f->RightMargin
      && Scaleform::Render::Text::ParagraphFormat::TabStopsEqual(this, f->pTabStops);
}
