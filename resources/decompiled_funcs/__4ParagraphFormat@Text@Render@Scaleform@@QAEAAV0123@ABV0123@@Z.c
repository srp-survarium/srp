Scaleform::Render::Text::ParagraphFormat *__thiscall Scaleform::Render::Text::ParagraphFormat::operator=(
        Scaleform::Render::Text::ParagraphFormat *this,
        const Scaleform::Render::Text::ParagraphFormat *src)
{
  this->BlockIndent = src->BlockIndent;
  this->Indent = src->Indent;
  this->Leading = src->Leading;
  this->LeftMargin = src->LeftMargin;
  this->RightMargin = src->RightMargin;
  this->PresentMask = src->PresentMask;
  Scaleform::Render::Text::ParagraphFormat::CopyTabStops(this, src->pTabStops);
  return this;
}
