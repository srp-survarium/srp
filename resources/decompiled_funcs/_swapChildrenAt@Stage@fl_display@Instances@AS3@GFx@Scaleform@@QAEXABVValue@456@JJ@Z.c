void __thiscall Scaleform::GFx::AS3::Instances::fl_display::Stage::swapChildrenAt(
        Scaleform::GFx::AS3::Instances::fl_display::Stage *this,
        const Scaleform::GFx::AS3::Value *result,
        int index1,
        int index2)
{
  Scaleform::GFx::DisplayObject *pObject; // ecx
  unsigned int v5; // esi
  unsigned int v6; // edi
  int v7; // eax

  pObject = this->pDispObj.pObject;
  v5 = index2;
  v6 = index1;
  if ( index1 < 0 )
    v6 = 0;
  if ( index2 < 0 )
    v5 = 0;
  if ( pObject
    && (v7 = (*(int (__thiscall **)(int))(*((_DWORD *)&pObject->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                          + pObject->AvmObjOffset)
                                        + 20))((int)pObject + 4 * pObject->AvmObjOffset)) != 0 )
  {
    Scaleform::GFx::AS3::AvmDisplayObjContainer::SwapChildrenAt(
      (Scaleform::GFx::AS3::AvmDisplayObjContainer *)(v7 - 36),
      v6,
      v5);
  }
  else
  {
    Scaleform::GFx::AS3::AvmDisplayObjContainer::SwapChildrenAt(0, v6, v5);
  }
}
