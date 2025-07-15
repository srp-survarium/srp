Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject> *__thiscall Scaleform::GFx::AS3::AvmDisplayObjContainer::GetAS3ChildAt(
        Scaleform::GFx::AS3::AvmDisplayObjContainer *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject> *result,
        unsigned int index)
{
  Scaleform::GFx::DisplayObjectBase *ChildAt; // eax
  Scaleform::GFx::DisplayObjectBase_vtbl **v4; // esi
  Scaleform::GFx::DisplayObjectBase_vtbl *v5; // eax
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v6; // ecx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject> *v7; // eax

  ChildAt = Scaleform::GFx::DisplayObjContainer::GetChildAt(
              (Scaleform::GFx::DisplayObjContainer *)this->pDispObj,
              index);
  if ( ChildAt )
  {
    v4 = &ChildAt->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
       + ChildAt->AvmObjOffset;
    ((void (__thiscall *)(Scaleform::GFx::DisplayObjectBase_vtbl **, int))(*v4)->GetRatio)(v4, 1);
    v5 = v4[2];
    if ( !v5 )
      v5 = v4[1];
    v6 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)v5;
    if ( ((unsigned __int8)v5 & 1) != 0 )
      v6 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)&v5[-1].GetType + 3);
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
