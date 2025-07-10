BOOL __thiscall Scaleform::Render::SortKey::MatchSingleItemOverlap(
        Scaleform::Render::SortKey *this,
        const Scaleform::Render::SortKey *other)
{
  return this->Data == other->Data && this->pImpl == other->pImpl && (this->pImpl->Flags & 0x4000) != 0;
}
