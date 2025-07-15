void __thiscall Scaleform::Render::Text::ParagraphFormat::SetAlignment(
        Scaleform::Render::Text::ParagraphFormat *this,
        Scaleform::Render::Text::ParagraphFormat::AlignType align)
{
  this->PresentMask = this->PresentMask ^ (this->PresentMask ^ ((_WORD)align << 9)) & 0x600 | 1;
}
