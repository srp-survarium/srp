void __cdecl Scaleform::ConstructorMov<Scaleform::Render::Text::DocView::ImageSubstitutor::Element>::DestructArray(
        Scaleform::Render::Text::DocView::ImageSubstitutor::Element *p,
        unsigned int count)
{
  Scaleform::Ptr<Scaleform::Render::Text::ImageDesc> *p_pImageDesc; // esi
  unsigned int v3; // edi

  if ( count )
  {
    p_pImageDesc = &p[count - 1].pImageDesc;
    v3 = count;
    do
    {
      if ( p_pImageDesc->pObject )
        Scaleform::RefCountNTSImpl::Release(p_pImageDesc->pObject);
      p_pImageDesc -= 12;
      --v3;
    }
    while ( v3 );
  }
}
