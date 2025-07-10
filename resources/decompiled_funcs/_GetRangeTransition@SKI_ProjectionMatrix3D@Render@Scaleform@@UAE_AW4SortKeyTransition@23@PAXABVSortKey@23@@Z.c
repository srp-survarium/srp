int __thiscall Scaleform::Render::SKI_ProjectionMatrix3D::GetRangeTransition(
        Scaleform::Render::SKI_ProjectionMatrix3D *this,
        void *__formal,
        const Scaleform::Render::SortKey *other)
{
  if ( other->pImpl->Type == SortKey_ProjectionMatrix3DEnd && this->Type == SortKey_ProjectionMatrix3DStart )
    return 2;
  else
    return 0;
}
