void __thiscall Scaleform::Render::Renderer2DImpl::EntryDestroy(
        Scaleform::Render::Renderer2DImpl *this,
        Scaleform::Render::ContextImpl::Entry *p)
{
  Scaleform::Render::TreeCacheNode *pRenderer; // ecx

  pRenderer = p->pRenderer;
  if ( pRenderer )
  {
    ((void (__thiscall *)(Scaleform::Render::TreeCacheNode *, int))pRenderer->~Scaleform::Render::TreeCacheNode)(
      pRenderer,
      1);
    p->pRenderer = 0;
  }
}
