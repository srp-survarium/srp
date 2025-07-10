void __thiscall Scaleform::Render::Text::ParagraphFormat::SetTabStopsNum(
        Scaleform::Render::Text::ParagraphFormat *this,
        unsigned int num)
{
  Scaleform::Render::Text::ParagraphFormat::AllocTabStops(this, num);
  this->PresentMask |= 0x40u;
}
