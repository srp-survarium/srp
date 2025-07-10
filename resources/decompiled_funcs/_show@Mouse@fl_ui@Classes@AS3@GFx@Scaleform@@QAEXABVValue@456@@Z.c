void __thiscall Scaleform::GFx::AS3::Classes::fl_ui::Mouse::show(
        Scaleform::GFx::AS3::Classes::fl_ui::Mouse *this,
        const Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::StateBag *v2; // eax
  Scaleform::GFx::StateBag_vtbl *v3; // ecx
  Scaleform::GFx::StateBag *v4; // esi
  Scaleform::GFx::LogState *pObject; // edi
  Scaleform::GFx::LogBase<Scaleform::GFx::LogState> **LogState; // eax
  Scaleform::Ptr<Scaleform::GFx::LogState> v7; // [esp+4h] [ebp-14h] BYREF
  int v8; // [esp+8h] [ebp-10h] BYREF
  char v9; // [esp+Ch] [ebp-Ch]
  int v10; // [esp+10h] [ebp-8h]
  int v11; // [esp+14h] [ebp-4h]

  v2 = (Scaleform::GFx::StateBag *)this->pTraits.pObject->pVM[1].__vftable[1].~Scaleform::GFx::AS3::VM;
  v3 = v2[118].__vftable;
  if ( v3 )
  {
    v9 = 0;
    v8 = 21;
    v10 = 0;
    v11 = 0;
    (*((void (__thiscall **)(Scaleform::GFx::StateBag_vtbl *, Scaleform::GFx::StateBag *, int *))v3->GetStateBagImpl + 1))(
      v3,
      v2,
      &v8);
  }
  else
  {
    v4 = v2 + 2;
    pObject = Scaleform::GFx::StateBag::GetLogState(v2 + 2, &v7)->pObject;
    if ( v7.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v7.pObject);
    if ( pObject )
    {
      LogState = (Scaleform::GFx::LogBase<Scaleform::GFx::LogState> **)Scaleform::GFx::StateBag::GetLogState(v4, &v7);
      Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogScriptWarning(
        *LogState + 3,
        "No user event handler interface is installed; Mouse.hide failed.");
      if ( v7.pObject )
        Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v7.pObject);
    }
  }
}
