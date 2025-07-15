void __thiscall Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer::textSnapshotGet(
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *result)
{
  Scaleform::GFx::AS3::ASVM *pVM; // esi
  Scaleform::GFx::AS3::Class *Class; // eax
  Scaleform::GFx::AS3::Class *v5; // ebx
  unsigned int RefCount; // eax
  unsigned int v7; // edx
  Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot *pObject; // ecx
  Scaleform::GFx::AS3::VMAppDomain *CurrentDomain; // [esp-4h] [ebp-1Ch]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot> ts; // [esp+Ch] [ebp-Ch] BYREF
  Scaleform::StringDataPtr gname; // [esp+10h] [ebp-8h] BYREF

  pVM = (Scaleform::GFx::AS3::ASVM *)this->pTraits.pObject->pVM;
  ts.pObject = 0;
  CurrentDomain = pVM->CurrentDomain;
  gname.pStr = "flash.text.TextSnapshot";
  gname.Size = 23;
  Class = Scaleform::GFx::AS3::VM::GetClass(pVM, &gname, CurrentDomain);
  v5 = Class;
  if ( Class )
    Class->RefCount = (Class->RefCount + 1) & 0x8FBFFFFF;
  Scaleform::GFx::AS3::ASVM::_constructInstance(
    pVM,
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&ts,
    Class,
    0,
    0);
  Scaleform::GFx::Sprite::GetTextSnapshot((Scaleform::GFx::Sprite *)this->pDispObj.pObject, &ts.pObject->SnapshotData);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event>::Set(
    result,
    (const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)&ts);
  if ( v5 )
  {
    if ( ((unsigned __int8)v5 & 1) == 0 )
    {
      RefCount = v5->RefCount;
      if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
      {
        v5->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v5);
      }
    }
  }
  if ( ts.pObject && ((int)ts.pObject & 1) == 0 )
  {
    v7 = ts.pObject->RefCount;
    pObject = ts.pObject;
    if ( ((unsigned int)&byte_3FFFFF & v7) != 0 )
    {
      ts.pObject->RefCount = v7 - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
    }
  }
}
