BOOL __thiscall Scaleform::RangeData<Scaleform::GFx::TextField::CSSHolderBase::UrlZone>::IsDataEqual(
        Scaleform::RangeData<Scaleform::GFx::TextField::CSSHolderBase::UrlZone> *this,
        const Scaleform::GFx::TextField::CSSHolderBase::UrlZone *data)
{
  return this->Data.SavedFmt.pObject == data->SavedFmt.pObject
      && this->Data.HitCount == data->HitCount
      && this->Data.OverCount == data->OverCount;
}
