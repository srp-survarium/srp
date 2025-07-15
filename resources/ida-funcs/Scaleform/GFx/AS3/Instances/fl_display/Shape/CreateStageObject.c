Scaleform::GFx::DisplayObject *__thiscall Scaleform::GFx::AS3::Instances::fl_display::Shape::CreateStageObject(
        Scaleform::GFx::AS3::Instances::fl_display::Shape *this)
{
  Scaleform::GFx::DisplayObject *result; // eax
  Scaleform::GFx::AS3::VM_vtbl *v3; // esi
  int v4; // eax
  Scaleform::GFx::DisplayObject *pObject; // ecx
  Scaleform::GFx::DisplayObject *v6; // esi
  Scaleform::GFx::AS3::VMAppDomain *v7; // eax
  Scaleform::GFx::CharacterCreateInfo ccinfo; // [esp+8h] [ebp-Ch] BYREF

  result = this->pDispObj.pObject;
  if ( !result )
  {
    v3 = this->pTraits.pObject->pVM[1].__vftable;
    Scaleform::GFx::MovieDefImpl::GetCharacterCreateInfo(
      *((Scaleform::GFx::MovieDefImpl **)v3[1].~Scaleform::GFx::AS3::VM + 9),
      (Scaleform::GFx::ResourceBinding *)&ccinfo,
      (Scaleform::GFx::ResourceId)&unk_10004);
    v4 = (*(int (__thiscall **)(Scaleform::GFx::AMP::ViewStats *(__thiscall *)(Scaleform::GFx::AS3::VM *), void (__thiscall *)(Scaleform::GFx::AS3::VM *), Scaleform::GFx::CharacterCreateInfo *, _DWORD, int, int))(*(_DWORD *)v3[1].GetAdvanceStats + 16))(
           v3[1].GetAdvanceStats,
           v3[1].~Scaleform::GFx::AS3::VM,
           &ccinfo,
           0,
           65537,
           1);
    pObject = this->pDispObj.pObject;
    v6 = (Scaleform::GFx::DisplayObject *)v4;
    if ( pObject )
      Scaleform::RefCountNTSImpl::Release(pObject);
    this->pDispObj.pObject = v6;
    if ( v6 )
      v6 = (Scaleform::GFx::DisplayObject *)((char *)v6 + 4 * v6->AvmObjOffset);
    Scaleform::GFx::AS3::AvmDisplayObj::AssignAS3Obj((Scaleform::GFx::AS3::AvmDisplayObj *)v6, this);
    v7 = this->pTraits.pObject->GetAppDomain(this->pTraits.pObject);
    Scaleform::GFx::AS3::AvmDisplayObj::SetAppDomain((Scaleform::GFx::AS3::AvmDisplayObj *)v6, v7);
    return this->pDispObj.pObject;
  }
  return result;
}
