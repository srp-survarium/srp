int __thiscall Scaleform::Render::SKI_Filter::GetRangeTransition(
        Scaleform::Render::SKI_Filter *this,
        void *__formal,
        const Scaleform::Render::SortKey *other)
{
  if ( other->pImpl->Type == SortKey_FilterEnd && this->Type == SortKey_FilterStart )
    return 2;
  else
    return 0;
}
