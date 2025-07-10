void __thiscall Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject::doubleClickEnabledSet(
        Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *this,
        const Scaleform::GFx::AS3::Value *result,
        bool value)
{
  Scaleform::GFx::DisplayObject *pObject; // ecx
  Scaleform::GFx::DisplayObject *v4; // eax
  int v5; // ecx
  int v6; // eax
  int v7; // eax

  pObject = this->pDispObj.pObject;
  v4 = LOBYTE(pObject->Scaleform::GFx::DisplayObjectBase::Flags) >> 7 != 0 ? pObject : 0;
  if ( v4
    && (v5 = *(LOBYTE(pObject->Scaleform::GFx::DisplayObjectBase::Flags) >> 7 != 0
             ? &pObject->AvmObjOffset
             : (unsigned __int8 *)65),
        (v6 = (*(int (__thiscall **)(int))(*((_DWORD *)&v4->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                           + v5)
                                         + 4))((int)v4 + 4 * v5)) != 0) )
  {
    v7 = v6 - 28;
  }
  else
  {
    v7 = 0;
  }
  if ( value )
    *(_BYTE *)(v7 + 33) |= 2u;
  else
    *(_BYTE *)(v7 + 33) &= ~2u;
}
