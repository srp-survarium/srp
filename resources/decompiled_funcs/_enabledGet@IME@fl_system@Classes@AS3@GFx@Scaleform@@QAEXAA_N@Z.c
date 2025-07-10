void __thiscall Scaleform::GFx::AS3::Classes::fl_system::IME::enabledGet(
        Scaleform::GFx::AS3::Classes::fl_system::IME *this,
        bool *result)
{
  void (__thiscall *v2)(Scaleform::GFx::AS3::VM *); // ecx
  Scaleform::RefCountVImpl *v3; // esi

  v2 = this->pTraits.pObject->pVM[1].__vftable[1].~Scaleform::GFx::AS3::VM;
  v3 = (Scaleform::RefCountVImpl *)(*(int (__thiscall **)(int, int))(*((_DWORD *)v2 + 2) + 12))((int)v2 + 8, 24);
  if ( v3 )
  {
    *result = ((int (__thiscall *)(Scaleform::RefCountVImpl *))v3->__vftable[3].~Scaleform::RefCountVImpl)(v3);
    Scaleform::RefCountImpl::Release(v3);
  }
}
