void __thiscall Scaleform::GFx::AS3::Classes::fl_gfx::IMEEx::GetOSVersion(
        Scaleform::GFx::AS3::Classes::fl_gfx::IMEEx *this,
        Scaleform::GFx::ASString *result)
{
  void (__thiscall *v2)(Scaleform::GFx::AS3::VM *); // eax
  Scaleform::RefCountVImpl *v3; // eax
  Scaleform::RefCountVImpl *v4; // esi
  void *v5; // esi
  Scaleform::String version; // [esp+8h] [ebp-4h] BYREF

  version.pData = (Scaleform::String::DataDesc *)this;
  v2 = this->pTraits.pObject->pVM[1].__vftable[1].~Scaleform::GFx::AS3::VM;
  if ( v2 )
  {
    v3 = (Scaleform::RefCountVImpl *)(*(int (__thiscall **)(int, int))(*((_DWORD *)v2 + 2) + 12))((int)v2 + 8, 24);
    v4 = v3;
    if ( v3 )
    {
      Scaleform::RefCountImpl::Release(v3);
      ((void (__thiscall *)(Scaleform::RefCountVImpl *, Scaleform::String *))v4->__vftable[11].~Scaleform::RefCountVImpl)(
        v4,
        &version);
      Scaleform::GFx::ASString::operator=<Scaleform::String>(result, &version);
      v5 = (void *)(version.HeapTypeBits & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd((volatile LONG *)((version.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v5);
    }
  }
}
