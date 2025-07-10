void __thiscall Scaleform::GFx::FontProviderWin32::FontProviderWin32(
        Scaleform::GFx::FontProviderWin32 *this,
        HDC__ *dc)
{
  Scaleform::Render::FontProviderWinAPI *v3; // eax
  Scaleform::GFx::Resource *v4; // eax
  Scaleform::GFx::Resource *v5; // edi

  v3 = (Scaleform::Render::FontProviderWinAPI *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                  Scaleform::Memory::pGlobalHeap,
                                                  60,
                                                  0);
  if ( v3 )
  {
    Scaleform::Render::FontProviderWinAPI::FontProviderWinAPI(v3, dc);
    v5 = v4;
  }
  else
  {
    v5 = 0;
  }
  this->__vftable = (Scaleform::GFx::FontProviderWin32_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->SType = State_FontProvider;
  this->__vftable = (Scaleform::GFx::FontProviderWin32_vtbl *)&Scaleform::GFx::FontProvider::`vftable';
  if ( v5 )
    Scaleform::RefCountImpl::AddRef(v5);
  this->pFontProvider.pObject = (Scaleform::Render::FontProvider *)v5;
  if ( v5 )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v5);
  this->__vftable = (Scaleform::GFx::FontProviderWin32_vtbl *)&Scaleform::GFx::FontProvider::`vftable';
}
