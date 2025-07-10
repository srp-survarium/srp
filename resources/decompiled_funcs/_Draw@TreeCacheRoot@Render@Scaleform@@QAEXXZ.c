void __thiscall Scaleform::Render::TreeCacheRoot::Draw(Scaleform::Render::TreeCacheRoot *this)
{
  unsigned int v2; // eax
  _DWORD *v3; // edi

  if ( (this->Flags & 3) == 1 )
  {
    v2 = *(_DWORD *)(*(_DWORD *)(((int)this->pNode & 0xFFFFF000) + 0x14)
                   + 4 * ((int)((int)&this->pNode[-1] - ((int)this->pNode & 0xFFFFF000)) / 28)
                   + 20)
       & 0xFFFFFFFE;
    v3 = (_DWORD *)(v2 + 160);
    if ( *(_DWORD *)(v2 + 160) && *(_DWORD *)(v2 + 164) )
      Scaleform::Render::HAL::BeginDisplay(
        this->pRenderer2D->pHal.pObject,
        *(Scaleform::Render::Color *)(v2 + 204),
        (const Scaleform::Render::Viewport *)(v2 + 160));
    ((void (__thiscall *)(Scaleform::Render::HAL *, Scaleform::Render::BundleEntry *, Scaleform::Render::BundleEntry *, Scaleform::Render::Renderer2DImpl *))this->pRenderer2D->pHal.pObject->DrawBundleEntries)(
      this->pRenderer2D->pHal.pObject,
      this->CachedChildPattern.pFirst,
      this->CachedChildPattern.pLast,
      this->pRenderer2D);
    if ( *v3 )
    {
      if ( v3[1] )
        Scaleform::Render::HAL::EndDisplay(this->pRenderer2D->pHal.pObject);
    }
  }
}
