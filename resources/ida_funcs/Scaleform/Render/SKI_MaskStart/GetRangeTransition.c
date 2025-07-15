BOOL __thiscall Scaleform::Render::SKI_MaskStart::GetRangeTransition(
        Scaleform::Render::SKI_MaskStart *this,
        void *__formal,
        const Scaleform::Render::SortKey *other)
{
  return other->pImpl->Type == SortKey_MaskEnd;
}
