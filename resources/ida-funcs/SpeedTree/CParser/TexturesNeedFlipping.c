bool __thiscall SpeedTree::CParser::TexturesNeedFlipping(SpeedTree::CParser *this)
{
  return SpeedTree::CCore::GetTextureFlip() != *((_BYTE *)this + 94);
}
