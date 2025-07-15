Scaleform::GFx::DisplayObject *__thiscall Scaleform::GFx::AS3::AvmDisplayObj::GetRoot(
        Scaleform::GFx::AS3::AvmDisplayObj *this)
{
  Scaleform::GFx::AS3::AvmDisplayObj *v1; // esi
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *pAS3RawPtr; // ecx
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *pObject; // eax
  Scaleform::GFx::InteractiveObject *pParent; // eax
  int v5; // eax
  Scaleform::GFx::AS3::AvmDisplayObj *v6; // eax

  v1 = this;
  if ( !this )
    return 0;
  while ( 1 )
  {
    pAS3RawPtr = v1->pAS3RawPtr;
    pObject = pAS3RawPtr;
    if ( !pAS3RawPtr )
      pObject = v1->pAS3CollectiblePtr.pObject;
    if ( ((unsigned __int8)pObject & 1) != 0 )
      pObject = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)pObject - 1);
    if ( pObject )
    {
      if ( !pAS3RawPtr )
        pAS3RawPtr = v1->pAS3CollectiblePtr.pObject;
      if ( ((unsigned __int8)pAS3RawPtr & 1) != 0 )
        pAS3RawPtr = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)pAS3RawPtr - 1);
      if ( Scaleform::GFx::XML::ElementNode::HasAttributes(pAS3RawPtr) )
        break;
    }
    pParent = v1->pDispObj->pParent;
    if ( pParent
      && (v5 = (*(int (__thiscall **)(int))(*((_DWORD *)&pParent->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                            + pParent->AvmObjOffset)
                                          + 4))((int)pParent + 4 * pParent->AvmObjOffset)) != 0 )
    {
      v6 = (Scaleform::GFx::AS3::AvmDisplayObj *)(v5 - 28);
    }
    else
    {
      v6 = 0;
    }
    v1 = v6;
    if ( !v6 )
      return 0;
  }
  return v1->pDispObj;
}
