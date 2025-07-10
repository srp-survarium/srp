int __thiscall Scaleform::Render::SKI_BlendMode::GetRangeTransition(
        Scaleform::Render::SKI_BlendMode *this,
        void *__formal,
        const Scaleform::Render::SortKey *other)
{
  if ( other->pImpl->Type == SortKey_BlendModeEnd && this->Type == SortKey_BlendModeStart )
    return 2;
  else
    return 0;
}
