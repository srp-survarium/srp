Scaleform::GFx::DisplayObject *__thiscall Scaleform::GFx::AS3::Instances::fl_display::Sprite::CreateStageObject(
        Scaleform::GFx::AS3::Instances::fl_display::Sprite *this)
{
  Scaleform::GFx::DisplayObject *pObject; // eax
  Scaleform::GFx::AS3::ASVM *pVM; // ecx
  Scaleform::GFx::AS3::MovieRoot *pMovieRoot; // ebx
  Scaleform::GFx::MovieDefImpl *ResourceMovieDef; // eax
  Scaleform::GFx::MovieDefImpl *v6; // edi
  Scaleform::GFx::AS3::VM *v7; // ecx
  int v8; // eax
  Scaleform::GFx::DisplayObject *v9; // ecx
  Scaleform::GFx::DisplayObject *v10; // edi
  Scaleform::GFx::AS3::VMAppDomain *v11; // eax
  Scaleform::GFx::CharacterCreateInfo ccinfo; // [esp+Ch] [ebp-18h] BYREF
  Scaleform::GFx::CharacterCreateInfo result; // [esp+18h] [ebp-Ch] BYREF

  pObject = this->pDispObj.pObject;
  if ( !pObject )
  {
    pVM = (Scaleform::GFx::AS3::ASVM *)this->pTraits.pObject->pVM;
    pMovieRoot = pVM->pMovieRoot;
    ResourceMovieDef = Scaleform::GFx::AS3::ASVM::GetResourceMovieDef(pVM, this);
    v6 = ResourceMovieDef;
    if ( ResourceMovieDef )
    {
      memset(&ccinfo, 0, sizeof(ccinfo));
      Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::FindLibarySymbol(this, &ccinfo, ResourceMovieDef);
      if ( !ccinfo.pCharDef && !Scaleform::GFx::AS3::MovieRoot::FindLibrarySymbolInAllABCs(pMovieRoot, this, &ccinfo) )
      {
        ccinfo = *Scaleform::GFx::MovieDefImpl::GetCharacterCreateInfo(
                    v6,
                    (Scaleform::GFx::ResourceBinding *)&result,
                    (Scaleform::GFx::ResourceId)65537);
        v7 = this->pTraits.pObject->pVM;
        if ( v7->CallStack.Size )
          ccinfo.pBindDefImpl = (Scaleform::GFx::MovieDefImpl *)Scaleform::GFx::AS3::VM::GetCurrCallFrame(v7)->pFile->File.pObject[1].__vftable;
        else
          ccinfo.pBindDefImpl = v6;
      }
      v8 = ((int (__thiscall *)(Scaleform::GFx::ASSupport *, Scaleform::GFx::MovieImpl *, Scaleform::GFx::CharacterCreateInfo *, _DWORD, int, int))pMovieRoot->pASSupport.pObject->CreateCharacterInstance)(
             pMovieRoot->pASSupport.pObject,
             pMovieRoot->pMovieImpl,
             &ccinfo,
             0,
             0x40000,
             3);
      v9 = this->pDispObj.pObject;
      v10 = (Scaleform::GFx::DisplayObject *)v8;
      if ( v9 )
        Scaleform::RefCountNTSImpl::Release(v9);
      this->pDispObj.pObject = v10;
      if ( v10 )
        v10 = (Scaleform::GFx::DisplayObject *)((char *)v10 + 4 * v10->AvmObjOffset);
      Scaleform::GFx::AS3::AvmDisplayObj::AssignAS3Obj((Scaleform::GFx::AS3::AvmDisplayObj *)v10, this);
      v11 = this->pTraits.pObject->GetAppDomain(this->pTraits.pObject);
      Scaleform::GFx::AS3::AvmDisplayObj::SetAppDomain((Scaleform::GFx::AS3::AvmDisplayObj *)v10, v11);
    }
    return this->pDispObj.pObject;
  }
  return pObject;
}
