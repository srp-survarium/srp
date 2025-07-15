Scaleform::GFx::DisplayObject *__thiscall Scaleform::GFx::AS3::Instances::fl_text::TextField::CreateStageObject(
        Scaleform::GFx::AS3::Instances::fl_text::TextField *this)
{
  Scaleform::GFx::DisplayObject *result; // eax
  Scaleform::GFx::AS3::VM_vtbl *v3; // edi
  Scaleform::GFx::AS3::VM *pVM; // ecx
  int v5; // eax
  Scaleform::GFx::DisplayObject *pObject; // ecx
  Scaleform::GFx::DisplayObject *v7; // edi
  Scaleform::GFx::AS3::VMAppDomain *v8; // eax
  Scaleform::GFx::CharacterCreateInfo ccinfo; // [esp+8h] [ebp-Ch] BYREF

  result = this->pDispObj.pObject;
  if ( !result )
  {
    v3 = this->pTraits.pObject->pVM[1].__vftable;
    Scaleform::GFx::MovieDefImpl::GetCharacterCreateInfo(
      *((Scaleform::GFx::MovieDefImpl **)v3[1].~Scaleform::GFx::AS3::VM + 9),
      (Scaleform::GFx::ResourceBinding *)&ccinfo,
      (Scaleform::GFx::ResourceId)((char *)&_sbh_sizeHeaderList.unused + 2));
    pVM = this->pTraits.pObject->pVM;
    if ( pVM->CallStack.Size )
      ccinfo.pBindDefImpl = (Scaleform::GFx::MovieDefImpl *)pVM->CallStack.Pages[(pVM->CallStack.Size - 1) >> 6][(pVM->CallStack.Size - 1) & 0x3F].pFile->File.pObject[1].__vftable;
    v5 = (*(int (__thiscall **)(Scaleform::GFx::AMP::ViewStats *(__thiscall *)(Scaleform::GFx::AS3::VM *), void (__thiscall *)(Scaleform::GFx::AS3::VM *), Scaleform::GFx::CharacterCreateInfo *, _DWORD, char *, _DWORD))(*(_DWORD *)v3[1].GetAdvanceStats + 16))(
           v3[1].GetAdvanceStats,
           v3[1].~Scaleform::GFx::AS3::VM,
           &ccinfo,
           0,
           (char *)&_sbh_sizeHeaderList.unused + 2,
           0);
    pObject = this->pDispObj.pObject;
    v7 = (Scaleform::GFx::DisplayObject *)v5;
    if ( pObject )
      Scaleform::RefCountNTSImpl::Release(pObject);
    this->pDispObj.pObject = v7;
    if ( v7 )
      v7 = (Scaleform::GFx::DisplayObject *)((char *)v7 + 4 * v7->AvmObjOffset);
    Scaleform::GFx::AS3::AvmDisplayObj::AssignAS3Obj((Scaleform::GFx::AS3::AvmDisplayObj *)v7, this);
    v8 = this->pTraits.pObject->GetAppDomain(this->pTraits.pObject);
    Scaleform::GFx::AS3::AvmDisplayObj::SetAppDomain((Scaleform::GFx::AS3::AvmDisplayObj *)v7, v8);
    return this->pDispObj.pObject;
  }
  return result;
}
