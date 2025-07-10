void __cdecl Scaleform::ConstructorMov<Scaleform::Render::HAL::RenderTargetEntry>::DestructArray(
        Scaleform::Render::HAL::RenderTargetEntry *p,
        unsigned int count)
{
  Scaleform::Render::HAL::RenderTargetEntry *v2; // esi
  unsigned int v3; // edi

  v2 = &p[count - 1];
  if ( count )
  {
    v3 = count;
    do
    {
      Scaleform::RefCountImplCore::~RefCountImplCore(&v2->OldMatrixState);
      if ( v2->pRenderTarget.pObject )
        v2->pRenderTarget.pObject->Release(v2->pRenderTarget.pObject);
      --v2;
      --v3;
    }
    while ( v3 );
  }
}
