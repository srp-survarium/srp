void __thiscall Scaleform::Render::Text::TextFormat::SetAlpha(
        Scaleform::Render::Text::TextFormat *this,
        unsigned __int8 alpha)
{
  this->ColorV = (unsigned int)&vostok::memory::s_CRT_arena[5574199] & this->ColorV | (alpha << 24);
  this->PresentMask |= 0x400u;
}
