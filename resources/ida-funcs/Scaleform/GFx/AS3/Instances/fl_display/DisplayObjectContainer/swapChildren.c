void __thiscall Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer::swapChildren(
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *child1,
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *child2)
{
  Scaleform::GFx::DisplayObject *pObject; // eax
  int v5; // eax

  pObject = this->pDispObj.pObject;
  if ( child1->pDispObj.pObject && child2->pDispObj.pObject )
  {
    if ( pObject
      && (v5 = (*(int (__thiscall **)(int))(*((_DWORD *)&pObject->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                            + pObject->AvmObjOffset)
                                          + 20))((int)pObject + 4 * pObject->AvmObjOffset)) != 0 )
    {
      Scaleform::GFx::AS3::AvmDisplayObjContainer::SwapChildren(
        (Scaleform::GFx::AS3::AvmDisplayObjContainer *)(v5 - 36),
        child1->pDispObj.pObject,
        child2->pDispObj.pObject);
    }
    else
    {
      Scaleform::GFx::AS3::AvmDisplayObjContainer::SwapChildren(0, child1->pDispObj.pObject, child2->pDispObj.pObject);
    }
  }
}
