void __thiscall Scaleform::GFx::GFxSystemFontResourceKey::GFxSystemFontResourceKey(
        Scaleform::GFx::GFxSystemFontResourceKey *this,
        const __m128i *pname,
        char fontFlags,
        Scaleform::GFx::Resource *pfontProvider)
{
  Scaleform::String *p_FontName; // edi
  Scaleform::String *v6; // eax
  const Scaleform::String *v7; // eax
  void *v8; // edi
  void *v9; // edi
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::String result; // [esp+Ch] [ebp-8h] BYREF
  Scaleform::String v12; // [esp+10h] [ebp-4h] BYREF

  this->__vftable = (Scaleform::GFx::GFxSystemFontResourceKey_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  p_FontName = &this->FontName;
  this->RefCount = 1;
  this->__vftable = (Scaleform::GFx::GFxSystemFontResourceKey_vtbl *)&Scaleform::GFx::GFxSystemFontResourceKey::`vftable';
  this->pFontProvider.pObject = 0;
  Scaleform::String::String(&this->FontName);
  Scaleform::String::String(&v12, pname);
  v7 = Scaleform::String::ToLower(v6, &result);
  Scaleform::String::operator=(p_FontName, v7);
  v8 = (void *)(result.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((result.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v8);
  v9 = (void *)(v12.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((v12.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v9);
  this->CreateFontFlags = fontFlags & 3;
  if ( pfontProvider )
    Scaleform::RefCountImpl::AddRef(pfontProvider);
  pObject = (Scaleform::RefCountVImpl *)this->pFontProvider.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->pFontProvider.pObject = (Scaleform::GFx::FontProvider *)pfontProvider;
}
