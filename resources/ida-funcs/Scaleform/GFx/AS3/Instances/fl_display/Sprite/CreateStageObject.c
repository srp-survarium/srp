Scaleform::GFx::DisplayObject *__thiscall Scaleform::GFx::AS3::Instances::fl_display::Sprite::CreateStageObject(
        Scaleform::GFx::AS3::Instances::fl_display::Sprite *this)
{
  Scaleform::GFx::DisplayObject *result; // eax
  Scaleform::GFx::AS3::ASVM *pVM; // ecx
  Scaleform::GFx::AS3::MovieRoot *pMovieRoot; // ebx
  Scaleform::GFx::MovieDefImpl *ResourceMovieDef; // eax
  Scaleform::GFx::MovieDefImpl *v6; // edi
  Scaleform::GFx::ResourceBinding *Info; // eax
  Scaleform::GFx::AS3::VM *v8; // ecx
  int v9; // eax
  Scaleform::GFx::DisplayObject *pObject; // ecx
  Scaleform::GFx::DisplayObject *v11; // edi
  Scaleform::GFx::AS3::VMAppDomain *v12; // eax
  Scaleform::GFx::CharacterCreateInfo ccinfo; // [esp+Ch] [ebp-18h] BYREF
  char v14; // [esp+18h] [ebp-Ch] BYREF

  result = this->pDispObj.pObject;
  if ( !result )
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
        Info = Scaleform::GFx::MovieDefImpl::GetCharacterCreateInfo(
                 v6,
                 (Scaleform::GFx::ResourceBinding *)&v14,
                 (Scaleform::GFx::ResourceId)65537);
        ccinfo.pCharDef = (Scaleform::GFx::CharacterDef *)Info->pHeap;
        ccinfo.pBindDefImpl = (Scaleform::GFx::MovieDefImpl *)Info->ResourceCount;
        ccinfo.pResource = (Scaleform::GFx::Resource *)Info->pResources;
        v8 = this->pTraits.pObject->pVM;
        if ( v8->CallStack.Size )
          ccinfo.pBindDefImpl = (Scaleform::GFx::MovieDefImpl *)Scaleform::GFx::AS3::VM::GetCurrCallFrame(v8)->pFile->File.pObject[1].__vftable;
        else
          ccinfo.pBindDefImpl = v6;
      }
      v9 = ((int (__thiscall *)(Scaleform::GFx::ASSupport *, Scaleform::GFx::MovieImpl *, Scaleform::GFx::CharacterCreateInfo *, _DWORD, int, int))pMovieRoot->pASSupport.pObject->CreateCharacterInstance)(
             pMovieRoot->pASSupport.pObject,
             pMovieRoot->pMovieImpl,
             &ccinfo,
             0,
             0x40000,
             3);
      pObject = this->pDispObj.pObject;
      v11 = (Scaleform::GFx::DisplayObject *)v9;
      if ( pObject )
        Scaleform::RefCountNTSImpl::Release(pObject);
      this->pDispObj.pObject = v11;
      if ( v11 )
        v11 = (Scaleform::GFx::DisplayObject *)((char *)v11 + 4 * v11->AvmObjOffset);
      Scaleform::GFx::AS3::AvmDisplayObj::AssignAS3Obj((Scaleform::GFx::AS3::AvmDisplayObj *)v11, this);
      v12 = this->pTraits.pObject->GetAppDomain(this->pTraits.pObject);
      Scaleform::GFx::AS3::AvmDisplayObj::SetAppDomain((Scaleform::GFx::AS3::AvmDisplayObj *)v11, v12);
    }
    return this->pDispObj.pObject;
  }
  return result;
}
