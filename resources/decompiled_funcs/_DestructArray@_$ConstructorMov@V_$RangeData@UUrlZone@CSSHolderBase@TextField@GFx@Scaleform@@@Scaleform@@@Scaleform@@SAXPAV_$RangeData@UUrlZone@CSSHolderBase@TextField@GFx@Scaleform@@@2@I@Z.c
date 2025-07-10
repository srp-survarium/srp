void __cdecl Scaleform::ConstructorMov<Scaleform::RangeData<Scaleform::GFx::TextField::CSSHolderBase::UrlZone>>::DestructArray(
        Scaleform::RangeData<Scaleform::GFx::TextField::CSSHolderBase::UrlZone> *p,
        unsigned int count)
{
  Scaleform::GFx::TextField::CSSHolderBase::UrlZone *p_Data; // esi
  unsigned int v3; // edi

  if ( count )
  {
    p_Data = &p[count - 1].Data;
    v3 = count;
    do
    {
      if ( p_Data->SavedFmt.pObject )
        Scaleform::RefCountNTSImpl::Release(p_Data->SavedFmt.pObject);
      p_Data = (Scaleform::GFx::TextField::CSSHolderBase::UrlZone *)((char *)p_Data - 20);
      --v3;
    }
    while ( v3 );
  }
}
