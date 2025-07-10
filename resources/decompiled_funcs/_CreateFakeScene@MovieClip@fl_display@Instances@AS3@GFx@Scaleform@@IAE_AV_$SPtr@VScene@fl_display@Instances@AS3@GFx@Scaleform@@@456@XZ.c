Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *__thiscall Scaleform::GFx::AS3::Instances::fl_display::MovieClip::CreateFakeScene(
        Scaleform::GFx::AS3::Instances::fl_display::MovieClip *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *result)
{
  Scaleform::GFx::AS3::Traits *pObject; // eax
  Scaleform::GFx::AS3::ASVM *pVM; // ebx
  Scaleform::GFx::AS3::Class *Class; // eax
  Scaleform::GFx::DisplayObject *v6; // esi
  Scaleform::GFx::AS3::Instances::fl_display::Scene *v7; // ebx
  Scaleform::RefCountNTSImpl *v8; // ecx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *v9; // eax
  Scaleform::StringDataPtr gname; // [esp+Ch] [ebp-8h] BYREF

  pObject = this->pTraits.pObject;
  pVM = (Scaleform::GFx::AS3::ASVM *)pObject->pVM;
  gname.pStr = "flash.display.Scene";
  gname.Size = 19;
  Class = Scaleform::GFx::AS3::VM::GetClass(pObject->pVM, &gname, pObject->pVM->CurrentDomain);
  result->pObject = 0;
  Scaleform::GFx::AS3::ASVM::_constructInstance(pVM, result, Class, 0, 0);
  v6 = this->pDispObj.pObject;
  v7 = (Scaleform::GFx::AS3::Instances::fl_display::Scene *)result->pObject;
  if ( v6 )
    ++v6->RefCount;
  v8 = v7->SpriteObj.pObject;
  if ( v8 )
    Scaleform::RefCountNTSImpl::Release(v8);
  v9 = result;
  v7->SpriteObj.pObject = (Scaleform::GFx::Sprite *)v6;
  return v9;
}
