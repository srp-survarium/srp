Scaleform::GFx::DisplayObject *__thiscall Scaleform::GFx::AS3::Instances::fl_display::SimpleButton::CreateStageObject(
        Scaleform::GFx::AS3::Instances::fl_display::SimpleButton *this)
{
  Scaleform::GFx::DisplayObject *pObject; // eax
  Scaleform::GFx::AS3::VM_vtbl *v3; // ebx
  Scaleform::GFx::MovieDefImpl *ResourceMovieDef; // eax
  Scaleform::GFx::MovieDefImpl *v5; // edi
  Scaleform::GFx::CharacterCreateInfo *Info; // eax
  Scaleform::GFx::Resource *pResource; // edx
  Scaleform::GFx::AS3::Traits *v8; // eax
  Scaleform::GFx::AS3::VM *pVM; // ecx
  int v10; // eax
  Scaleform::GFx::DisplayObject *v11; // ecx
  Scaleform::GFx::DisplayObject *v12; // edi
  Scaleform::GFx::AS3::VMAppDomain *v13; // eax
  Scaleform::GFx::CharacterCreateInfo ccinfo; // [esp+Ch] [ebp-18h] BYREF
  Scaleform::GFx::CharacterCreateInfo result; // [esp+18h] [ebp-Ch] BYREF

  pObject = this->pDispObj.pObject;
  if ( !pObject )
  {
    v3 = this->pTraits.pObject->pVM[1].__vftable;
    ResourceMovieDef = Scaleform::GFx::AS3::ASVM::GetResourceMovieDef(
                         (Scaleform::GFx::AS3::ASVM *)this->pTraits.pObject->pVM,
                         this);
    v5 = ResourceMovieDef;
    if ( ResourceMovieDef )
    {
      memset(&ccinfo, 0, sizeof(ccinfo));
      Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::FindLibarySymbol(this, &ccinfo, ResourceMovieDef);
      if ( !ccinfo.pCharDef )
      {
        Info = Scaleform::GFx::MovieDefImpl::GetCharacterCreateInfo(
                 v5,
                 (Scaleform::GFx::ResourceBinding *)&result,
                 (Scaleform::GFx::ResourceId)65539);
        ccinfo.pCharDef = Info->pCharDef;
        ccinfo.pBindDefImpl = Info->pBindDefImpl;
        pResource = Info->pResource;
        v8 = this->pTraits.pObject;
        ccinfo.pResource = pResource;
        pVM = v8->pVM;
        if ( pVM->CallStack.Size )
          ccinfo.pBindDefImpl = (Scaleform::GFx::MovieDefImpl *)pVM->CallStack.Pages[(pVM->CallStack.Size - 1) >> 6][(pVM->CallStack.Size - 1) & 0x3F].pFile->File.pObject[1].__vftable;
        else
          ccinfo.pBindDefImpl = v5;
      }
      v10 = (*(int (__thiscall **)(Scaleform::GFx::AMP::ViewStats *(__thiscall *)(Scaleform::GFx::AS3::VM *), void (__thiscall *)(Scaleform::GFx::AS3::VM *), Scaleform::GFx::CharacterCreateInfo *, _DWORD, int, int))(*(_DWORD *)v3[1].GetAdvanceStats + 16))(
              v3[1].GetAdvanceStats,
              v3[1].~Scaleform::GFx::AS3::VM,
              &ccinfo,
              0,
              0x40000,
              6);
      v11 = this->pDispObj.pObject;
      v12 = (Scaleform::GFx::DisplayObject *)v10;
      if ( v11 )
        Scaleform::RefCountNTSImpl::Release(v11);
      this->pDispObj.pObject = v12;
      if ( v12 )
        v12 = (Scaleform::GFx::DisplayObject *)((char *)v12 + 4 * v12->AvmObjOffset);
      Scaleform::GFx::AS3::AvmDisplayObj::AssignAS3Obj((Scaleform::GFx::AS3::AvmDisplayObj *)v12, this);
      v13 = this->pTraits.pObject->GetAppDomain(this->pTraits.pObject);
      Scaleform::GFx::AS3::AvmDisplayObj::SetAppDomain((Scaleform::GFx::AS3::AvmDisplayObj *)v12, v13);
      Scaleform::GFx::Button::CreateCharacters((Scaleform::GFx::Button *)this->pDispObj.pObject);
    }
    return this->pDispObj.pObject;
  }
  return pObject;
}
