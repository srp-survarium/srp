void __thiscall Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer::getChildByName(
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject> *result,
        const Scaleform::GFx::ASString *name)
{
  Scaleform::GFx::DisplayObject *pObject; // eax
  int v4; // eax
  Scaleform::GFx::AS3::AvmDisplayObjContainer *v5; // ecx
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v6; // eax
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v7; // ecx
  unsigned int RefCount; // edx
  unsigned int v9; // edx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject> obj; // [esp+0h] [ebp-4h] BYREF

  obj.pObject = this;
  pObject = this->pDispObj.pObject;
  if ( pObject
    && (v4 = (*(int (__thiscall **)(int))(*((_DWORD *)&pObject->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                          + pObject->AvmObjOffset)
                                        + 20))((int)pObject + 4 * pObject->AvmObjOffset)) != 0 )
  {
    v5 = (Scaleform::GFx::AS3::AvmDisplayObjContainer *)(v4 - 36);
  }
  else
  {
    v5 = 0;
  }
  Scaleform::GFx::AS3::AvmDisplayObjContainer::GetAS3ChildByName(v5, &obj, name);
  v6 = obj.pObject;
  if ( obj.pObject )
  {
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event>::Set(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)result,
      (const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)&obj);
    v6 = obj.pObject;
  }
  else
  {
    v7 = result->pObject;
    if ( !result->pObject )
      return;
    if ( ((unsigned __int8)v7 & 1) != 0 )
    {
      result->pObject = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v7 - 1);
      result->pObject = 0;
    }
    else
    {
      RefCount = v7->RefCount;
      if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
      {
        v7->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v7);
        v6 = obj.pObject;
      }
      result->pObject = 0;
    }
  }
  if ( v6 && ((unsigned __int8)v6 & 1) == 0 )
  {
    v9 = v6->RefCount;
    if ( ((unsigned int)&byte_3FFFFF & v9) != 0 )
    {
      v6->RefCount = v9 - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v6);
    }
  }
}
