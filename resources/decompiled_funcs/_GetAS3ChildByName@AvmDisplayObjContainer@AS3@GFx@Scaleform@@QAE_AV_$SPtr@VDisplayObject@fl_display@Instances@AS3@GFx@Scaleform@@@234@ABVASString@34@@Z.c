Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject> *__thiscall Scaleform::GFx::AS3::AvmDisplayObjContainer::GetAS3ChildByName(
        Scaleform::GFx::AS3::AvmDisplayObjContainer *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject> *result,
        Scaleform::GFx::ASString *name)
{
  Scaleform::GFx::DisplayObject *DisplayObjectByName; // eax
  Scaleform::GFx::DisplayObject_vtbl **v4; // esi
  Scaleform::GFx::DisplayObject_vtbl *v5; // eax
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v6; // ecx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject> *v7; // eax

  DisplayObjectByName = Scaleform::GFx::DisplayList::GetDisplayObjectByName(
                          (Scaleform::GFx::DisplayList *)&this->pDispObj[1].LastHitTestY,
                          name,
                          1);
  if ( DisplayObjectByName )
  {
    v4 = &DisplayObjectByName->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
       + DisplayObjectByName->AvmObjOffset;
    ((void (__thiscall *)(Scaleform::GFx::DisplayObject_vtbl **, int))(*v4)->GetRatio)(v4, 1);
    v5 = v4[2];
    if ( !v5 )
      v5 = v4[1];
    v6 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)v5;
    if ( ((unsigned __int8)v5 & 1) != 0 )
      v6 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)&v5[-1].DoDisplayCallback + 3);
    v7 = result;
    result->pObject = v6;
    if ( v6 )
      v6->RefCount = (v6->RefCount + 1) & 0x8FBFFFFF;
  }
  else
  {
    v7 = result;
    result->pObject = 0;
  }
  return v7;
}
