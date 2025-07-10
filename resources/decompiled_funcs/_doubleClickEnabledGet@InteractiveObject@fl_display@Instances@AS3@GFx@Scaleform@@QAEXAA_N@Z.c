void __thiscall Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject::doubleClickEnabledGet(
        Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *this,
        bool *result)
{
  Scaleform::GFx::DisplayObject *pObject; // ecx
  Scaleform::GFx::DisplayObject *v3; // eax
  int v4; // ecx
  int v5; // eax

  pObject = this->pDispObj.pObject;
  v3 = LOBYTE(pObject->Scaleform::GFx::DisplayObjectBase::Flags) >> 7 != 0 ? pObject : 0;
  if ( v3
    && (v4 = *(LOBYTE(pObject->Scaleform::GFx::DisplayObjectBase::Flags) >> 7 != 0
             ? &pObject->AvmObjOffset
             : (unsigned __int8 *)65),
        (v5 = (*(int (__thiscall **)(int))(*((_DWORD *)&v3->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                           + v4)
                                         + 4))((int)v3 + 4 * v4)) != 0) )
  {
    *result = (*(_BYTE *)(v5 + 5) & 2) != 0;
  }
  else
  {
    *result = (MEMORY[0x21] & 2) != 0;
  }
}
