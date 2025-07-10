void __thiscall Scaleform::GFx::AS3::Classes::fl_gfx::IMEEx::GetCompositionString(
        Scaleform::GFx::AS3::Classes::fl_gfx::IMEEx *this,
        Scaleform::GFx::ASString *result)
{
  void (__thiscall *v2)(Scaleform::GFx::AS3::VM *); // eax
  Scaleform::RefCountVImpl *v3; // eax
  Scaleform::RefCountVImpl *v4; // esi
  const wchar_t *v5; // eax
  void *v6; // esi
  Scaleform::String compString; // [esp+4h] [ebp-4h] BYREF

  compString.pData = (Scaleform::String::DataDesc *)this;
  v2 = this->pTraits.pObject->pVM[1].__vftable[1].~Scaleform::GFx::AS3::VM;
  if ( v2 )
  {
    v3 = (Scaleform::RefCountVImpl *)(*(int (__thiscall **)(int, int))(*((_DWORD *)v2 + 2) + 12))((int)v2 + 8, 24);
    v4 = v3;
    if ( v3 )
    {
      Scaleform::RefCountImpl::Release(v3);
      v5 = (const wchar_t *)((int (__thiscall *)(Scaleform::RefCountVImpl *))v4->__vftable[7].AddRef)(v4);
      Scaleform::String::String(&compString, v5);
      Scaleform::GFx::ASString::operator=<Scaleform::String>(result, &compString);
      v6 = (void *)(compString.HeapTypeBits & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd((volatile LONG *)((compString.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v6);
    }
  }
}
