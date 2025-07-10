void __cdecl Scaleform::ConstructorMov<Scaleform::Render::HAL::FilterStackEntry>::DestructArray(
        Scaleform::Render::HAL::FilterStackEntry *p,
        unsigned int count)
{
  Scaleform::Render::HAL::FilterStackEntry *v2; // esi
  unsigned int v3; // edi
  Scaleform::Render::RenderTarget *pObject; // ecx

  v2 = &p[count - 1];
  if ( count )
  {
    v3 = count;
    do
    {
      pObject = v2->pRenderTarget.pObject;
      if ( pObject )
        pObject->Release(pObject);
      if ( v2->pPrimitive.pObject )
        Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v2->pPrimitive.pObject);
      --v2;
      --v3;
    }
    while ( v3 );
  }
}
