void __thiscall Scaleform::Render::Text::ParagraphFormat::ParagraphFormat(
        Scaleform::Render::Text::ParagraphFormat *this,
        const Scaleform::Render::Text::ParagraphFormat *src)
{
  this->RefCount = 1;
  this->pTabStops = 0;
  this->BlockIndent = src->BlockIndent;
  this->Indent = src->Indent;
  this->Leading = src->Leading;
  this->LeftMargin = src->LeftMargin;
  this->RightMargin = src->RightMargin;
  this->PresentMask = src->PresentMask;
  Scaleform::Render::Text::ParagraphFormat::CopyTabStops(this, src->pTabStops);
}


void __thiscall Scaleform::Render::Text::ParagraphFormat::ParagraphFormat(
        Scaleform::Render::Text::ParagraphFormat *this)
{
  this->RefCount = 1;
  this->pTabStops = 0;
  this->BlockIndent = 0;
  this->Indent = 0;
  this->Leading = 0;
  this->LeftMargin = 0;
  this->RightMargin = 0;
  this->PresentMask = 0;
}
