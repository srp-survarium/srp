void __thiscall Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer::swapChildrenAt(
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer *this,
        const Scaleform::GFx::AS3::Value *result,
        int index1,
        int index2)
{
  Scaleform::GFx::DisplayObject *pObject; // eax
  unsigned int v5; // edi
  unsigned int v6; // esi
  int v7; // eax

  pObject = this->pDispObj.pObject;
  v5 = index1;
  if ( index1 < 0 )
    v5 = 0;
  v6 = index2;
  if ( index2 < 0 )
    v6 = 0;
  if ( pObject
    && (v7 = (*(int (__thiscall **)(int))(*((_DWORD *)&pObject->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                          + pObject->AvmObjOffset)
                                        + 20))((int)pObject + 4 * pObject->AvmObjOffset)) != 0 )
  {
    Scaleform::GFx::AS3::AvmDisplayObjContainer::SwapChildrenAt(
      (Scaleform::GFx::AS3::AvmDisplayObjContainer *)(v7 - 36),
      v5,
      v6);
  }
  else
  {
    Scaleform::GFx::AS3::AvmDisplayObjContainer::SwapChildrenAt(0, v5, v6);
  }
}
