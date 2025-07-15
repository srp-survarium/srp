void __thiscall Scaleform::GFx::AS3::Classes::fl_system::IME::conversionModeGet(
        Scaleform::GFx::AS3::Classes::fl_system::IME *this,
        Scaleform::GFx::ASString *result)
{
  void (__thiscall *v2)(Scaleform::GFx::AS3::VM *); // ecx
  Scaleform::RefCountVImpl *v3; // esi
  char *v4; // eax

  v2 = this->pTraits.pObject->pVM[1].__vftable[1].~Scaleform::GFx::AS3::VM;
  v3 = (Scaleform::RefCountVImpl *)(*(int (__thiscall **)(int, int))(*((_DWORD *)v2 + 2) + 12))((int)v2 + 8, 24);
  Scaleform::GFx::ASString::operator=(result, "UNKNOWN");
  if ( v3 )
  {
    v4 = (char *)((int (__thiscall *)(Scaleform::RefCountVImpl *))v3->__vftable[2].AddRef)(v3);
    Scaleform::GFx::ASString::operator=(result, v4);
    Scaleform::RefCountImpl::Release(v3);
  }
}
