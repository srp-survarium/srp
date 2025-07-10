void __thiscall Scaleform::GFx::AS3::Classes::fl_system::IME::enabledSet(
        Scaleform::GFx::AS3::Classes::fl_system::IME *this,
        const Scaleform::GFx::AS3::Value *result,
        int value)
{
  void (__thiscall *v3)(Scaleform::GFx::AS3::VM *); // ecx
  Scaleform::RefCountVImpl *v4; // esi

  v3 = this->pTraits.pObject->pVM[1].__vftable[1].~Scaleform::GFx::AS3::VM;
  v4 = (Scaleform::RefCountVImpl *)(*(int (__thiscall **)(int, int))(*((_DWORD *)v3 + 2) + 12))((int)v3 + 8, 24);
  if ( v4 )
  {
    ((void (__thiscall *)(Scaleform::RefCountVImpl *, int))v4->__vftable[2].Release)(v4, value);
    Scaleform::RefCountImpl::Release(v4);
  }
}
