void __cdecl Scaleform::ConstructorMov<Scaleform::Render::StrokeStyleType>::DestructArray(
        Scaleform::Render::StrokeStyleType *p,
        unsigned int count)
{
  Scaleform::Ptr<Scaleform::Render::ComplexFill> *p_pFill; // esi
  unsigned int v3; // edi
  Scaleform::RefCountVImpl *pObject; // ecx

  if ( count )
  {
    p_pFill = &p[count - 1].pFill;
    v3 = count;
    do
    {
      pObject = (Scaleform::RefCountVImpl *)p_pFill[1].pObject;
      if ( pObject )
        Scaleform::RefCountImpl::Release(pObject);
      if ( p_pFill->pObject )
        Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)p_pFill->pObject);
      p_pFill -= 7;
      --v3;
    }
    while ( v3 );
  }
}
