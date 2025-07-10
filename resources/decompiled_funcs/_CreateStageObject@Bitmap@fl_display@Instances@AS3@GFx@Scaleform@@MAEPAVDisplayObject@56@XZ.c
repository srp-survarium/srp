Scaleform::GFx::DisplayObject *__thiscall Scaleform::GFx::AS3::Instances::fl_display::Bitmap::CreateStageObject(
        Scaleform::GFx::AS3::Instances::fl_display::Bitmap *this)
{
  Scaleform::GFx::DisplayObject *pObject; // eax
  Scaleform::GFx::AS3::ASVM *pVM; // ebp
  Scaleform::GFx::AS3::MovieRoot *pMovieRoot; // edi
  Scaleform::GFx::MovieDefImpl *ResourceMovieDef; // eax
  int v6; // eax
  Scaleform::GFx::DisplayObject *v7; // ecx
  Scaleform::GFx::DisplayObject *v8; // edi
  Scaleform::GFx::AS3::AvmDisplayObj *v9; // edi
  Scaleform::GFx::AS3::VMAppDomain *v10; // eax
  Scaleform::GFx::AS3::CheckResult result[4]; // [esp+12h] [ebp-34h] BYREF
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::BitmapData> bmpData; // [esp+16h] [ebp-30h] BYREF
  Scaleform::GFx::CharacterCreateInfo ccinfo; // [esp+1Ah] [ebp-2Ch] BYREF
  Scaleform::GFx::AS3::Value params[2]; // [esp+26h] [ebp-20h] BYREF

  pObject = this->pDispObj.pObject;
  if ( !pObject )
  {
    pVM = (Scaleform::GFx::AS3::ASVM *)this->pTraits.pObject->pVM;
    pMovieRoot = pVM->pMovieRoot;
    ResourceMovieDef = Scaleform::GFx::AS3::ASVM::GetResourceMovieDef(pVM, this);
    if ( ResourceMovieDef )
    {
      memset(&ccinfo, 0, sizeof(ccinfo));
      if ( !Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::FindLibarySymbol(this, &ccinfo, ResourceMovieDef)
        && !Scaleform::GFx::AS3::MovieRoot::FindLibrarySymbolInAllABCs(pMovieRoot, this, &ccinfo) )
      {
        ccinfo.pCharDef = 0;
        ccinfo.pResource = 0;
      }
      v6 = ((int (__thiscall *)(Scaleform::GFx::ASSupport *, Scaleform::GFx::MovieImpl *, Scaleform::GFx::CharacterCreateInfo *, _DWORD, int, int))pMovieRoot->pASSupport.pObject->CreateCharacterInstance)(
             pMovieRoot->pASSupport.pObject,
             pMovieRoot->pMovieImpl,
             &ccinfo,
             0,
             0x40000,
             8);
      v7 = this->pDispObj.pObject;
      v8 = (Scaleform::GFx::DisplayObject *)v6;
      if ( v7 )
        Scaleform::RefCountNTSImpl::Release(v7);
      this->pDispObj.pObject = v8;
      if ( v8 )
        v9 = (Scaleform::GFx::AS3::AvmDisplayObj *)(&v8->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                                  + v8->AvmObjOffset);
      else
        v9 = 0;
      Scaleform::GFx::AS3::AvmDisplayObj::AssignAS3Obj(v9, this);
      v10 = this->pTraits.pObject->GetAppDomain(this->pTraits.pObject);
      Scaleform::GFx::AS3::AvmDisplayObj::SetAppDomain(v9, v10);
      if ( ccinfo.pResource && (ccinfo.pResource->GetResourceTypeCode(ccinfo.pResource) & 0xFF00) == 0x100 )
      {
        params[0].value.VNumber = 0.0;
        params[1].value.VNumber = 0.0;
        params[0].Flags = 4;
        params[1].Flags = 4;
        params[0].Bonus.pWeakProxy = 0;
        params[1].Bonus.pWeakProxy = 0;
        bmpData.pObject = 0;
        Scaleform::GFx::AS3::VM::constructBuiltinObject(
          pVM,
          &result[3],
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&bmpData,
          "flash.display.BitmapData",
          2u,
          params);
        if ( result[3].Result
          && Scaleform::GFx::AS3::Instances::fl_display::BitmapData::CreateLibraryObject(
               bmpData.pObject,
               (Scaleform::GFx::ImageResource *)ccinfo.pResource,
               (Scaleform::RefCountVImpl *)ccinfo.pBindDefImpl) )
        {
          Scaleform::GFx::AS3::Instances::fl_display::Bitmap::SetBitmapData(this, bmpData.pObject);
        }
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>::~SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>((Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *)&bmpData);
        `vector destructor iterator'(
          (char *)params,
          0x10u,
          2,
          (void (__thiscall *)(void *))Scaleform::GFx::AS3::Value::~Value);
      }
    }
    return this->pDispObj.pObject;
  }
  return pObject;
}
