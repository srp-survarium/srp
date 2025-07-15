int __thiscall Scaleform::Render::SKI_MaskEnd::GetRangeTransition(
        Scaleform::Render::SKI_MaskEnd *this,
        void *data,
        const Scaleform::Render::SortKey *other)
{
  return other->pImpl->Type != SortKey_MaskEnd ? 0 : 2;
}
