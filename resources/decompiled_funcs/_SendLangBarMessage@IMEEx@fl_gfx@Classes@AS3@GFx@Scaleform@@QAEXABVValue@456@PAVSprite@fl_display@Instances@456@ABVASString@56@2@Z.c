void __thiscall Scaleform::GFx::AS3::Classes::fl_gfx::IMEEx::SendLangBarMessage(
        Scaleform::GFx::AS3::Classes::fl_gfx::IMEEx *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_display::Sprite *mc,
        const Scaleform::GFx::ASString *command,
        const Scaleform::GFx::ASString *message)
{
  void (__thiscall *v5)(Scaleform::GFx::AS3::VM *); // eax
  Scaleform::RefCountVImpl *v6; // eax
  Scaleform::RefCountVImpl *v7; // esi

  v5 = this->pTraits.pObject->pVM[1].__vftable[1].~Scaleform::GFx::AS3::VM;
  if ( v5 )
  {
    v6 = (Scaleform::RefCountVImpl *)(*(int (__thiscall **)(int, int))(*((_DWORD *)v5 + 2) + 12))((int)v5 + 8, 24);
    v7 = v6;
    if ( v6 )
    {
      Scaleform::RefCountImpl::Release(v6);
      ((void (__thiscall *)(Scaleform::RefCountVImpl *, Scaleform::GFx::DisplayObject *, const Scaleform::GFx::ASString *, const Scaleform::GFx::ASString *))v7->__vftable[6].Release)(
        v7,
        mc->pDispObj.pObject,
        command,
        message);
    }
  }
}
