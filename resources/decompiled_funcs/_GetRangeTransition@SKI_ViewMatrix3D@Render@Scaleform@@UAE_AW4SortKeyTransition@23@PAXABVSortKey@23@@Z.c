int __thiscall Scaleform::Render::SKI_ViewMatrix3D::GetRangeTransition(
        Scaleform::Render::SKI_ViewMatrix3D *this,
        void *__formal,
        const Scaleform::Render::SortKey *other)
{
  if ( other->pImpl->Type == SortKey_ViewMatrix3DEnd && this->Type == SortKey_ViewMatrix3DStart )
    return 2;
  else
    return 0;
}
