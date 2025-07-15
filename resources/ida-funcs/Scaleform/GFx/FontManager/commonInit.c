void __thiscall Scaleform::GFx::FontManager::commonInit(Scaleform::GFx::FontManager *this)
{
  Scaleform::GFx::FontData *v2; // eax
  Scaleform::GFx::Resource *v3; // eax
  Scaleform::GFx::Resource *v4; // edi
  Scaleform::GFx::FontResource *v5; // eax
  Scaleform::GFx::Resource *v6; // eax
  Scaleform::GFx::Resource *v7; // ebx
  Scaleform::GFx::FontHandle *v8; // esi
  Scaleform::GFx::Resource *v9; // edi
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::GFx::Resource *v11; // [esp+20h] [ebp-Ch]
  int v12; // [esp+24h] [ebp-8h] BYREF
  int v13; // [esp+28h] [ebp-4h] BYREF

  v12 = 79;
  v2 = (Scaleform::GFx::FontData *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                     Scaleform::Memory::pGlobalHeap,
                                     this,
                                     76,
                                     &v12);
  if ( v2 )
  {
    Scaleform::GFx::FontData::FontData(v2);
    v4 = v3;
    v11 = v3;
  }
  else
  {
    v11 = 0;
    v4 = 0;
  }
  v13 = 2;
  v5 = (Scaleform::GFx::FontResource *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                         Scaleform::Memory::pGlobalHeap,
                                         this,
                                         32,
                                         &v13);
  if ( v5 )
  {
    Scaleform::GFx::FontResource::FontResource(v5, v4, 0);
    v7 = v6;
  }
  else
  {
    v7 = 0;
  }
  v8 = (Scaleform::GFx::FontHandle *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 32, 0);
  if ( v8 )
  {
    v9 = (Scaleform::GFx::Resource *)v7[1].__vftable;
    v8->__vftable = (Scaleform::GFx::FontHandle_vtbl *)&Scaleform::RefCountImplCore::`vftable';
    v8->RefCount = 1;
    v8->__vftable = (Scaleform::GFx::FontHandle_vtbl *)&Scaleform::Render::Text::FontHandle::`vftable';
    v8->pFontManager = 0;
    v8->OverridenFontFlags = 0;
    Scaleform::StringLH::StringLH(&v8->FontName);
    v8->FontScaleFactor = 1.0;
    if ( v9 )
      Scaleform::RefCountImpl::AddRef(v9);
    v8->pFont.pObject = (Scaleform::Render::Font *)v9;
    v4 = v11;
    v8->__vftable = (Scaleform::GFx::FontHandle_vtbl *)&Scaleform::GFx::FontHandle::`vftable';
    v8->pSourceMovieDef.pObject = 0;
  }
  else
  {
    v8 = 0;
  }
  pObject = (Scaleform::RefCountVImpl *)this->pEmptyFont.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->pEmptyFont.pObject = v8;
  if ( v7 )
    Scaleform::GFx::Resource::Release(v7);
  if ( v4 )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v4);
}
