void __thiscall Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer::setChildIndex(
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *child,
        int index)
{
  Scaleform::GFx::DisplayObject *pObject; // eax
  unsigned int v5; // esi
  int v6; // eax

  pObject = this->pDispObj.pObject;
  if ( child->pDispObj.pObject )
  {
    v5 = index;
    if ( index < 0 )
      v5 = 0;
    if ( pObject
      && (v6 = (*(int (__thiscall **)(int))(*((_DWORD *)&pObject->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                            + pObject->AvmObjOffset)
                                          + 20))((int)pObject + 4 * pObject->AvmObjOffset)) != 0 )
    {
      Scaleform::GFx::AS3::AvmDisplayObjContainer::SetChildIndex(
        (Scaleform::GFx::AS3::AvmDisplayObjContainer *)(v6 - 36),
        child->pDispObj.pObject,
        v5);
    }
    else
    {
      Scaleform::GFx::AS3::AvmDisplayObjContainer::SetChildIndex(0, child->pDispObj.pObject, v5);
    }
  }
}
