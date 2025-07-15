int __thiscall Scaleform::Render::SKI_UserData::GetRangeTransition(
        Scaleform::Render::SKI_UserData *this,
        void *__formal,
        const Scaleform::Render::SortKey *other)
{
  if ( other->pImpl->Type == SortKey_UserDataEnd && this->Type == SortKey_UserDataStart )
    return 2;
  else
    return 0;
}
