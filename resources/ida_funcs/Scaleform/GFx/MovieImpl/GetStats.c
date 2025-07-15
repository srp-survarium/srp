void __thiscall Scaleform::GFx::MovieImpl::GetStats(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::StatBag *pbag,
        bool reset)
{
  Scaleform::GFx::AMP::ViewStats *pObject; // ecx

  pObject = this->AdvanceStats.pObject;
  if ( pObject )
    Scaleform::GFx::AMP::ViewStats::GetStats(pObject, pbag, reset);
}
