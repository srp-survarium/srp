Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *__thiscall Scaleform::GFx::AS3::AvmDisplayObj::GetAS3Parent(
        Scaleform::GFx::AS3::AvmDisplayObj *this)
{
  Scaleform::GFx::InteractiveObject *pParent; // eax
  int v3; // eax
  Scaleform::GFx::InteractiveObject *v4; // eax
  Scaleform::GFx::InteractiveObject_vtbl **v5; // ecx
  int v6; // eax
  int v7; // eax
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *result; // eax

  pParent = this->pDispObj->pParent;
  if ( !pParent )
    return 0;
  v3 = (*(int (__thiscall **)(int))(*((_DWORD *)&pParent->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                    + pParent->AvmObjOffset)
                                  + 4))((int)pParent + 4 * pParent->AvmObjOffset);
  if ( !v3 || v3 == 28 )
    return 0;
  v4 = this->pDispObj->pParent;
  if ( v4
    && (v5 = &v4->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
           + v4->AvmObjOffset,
        (v6 = ((int (__thiscall *)(Scaleform::GFx::InteractiveObject_vtbl **))(*v5)->CreateRenderNode)(v5)) != 0) )
  {
    v7 = v6 - 28;
  }
  else
  {
    v7 = 0;
  }
  if ( *(_DWORD *)(v7 + 8) )
    result = *(Scaleform::GFx::AS3::Instances::fl_display::DisplayObject **)(v7 + 8);
  else
    result = *(Scaleform::GFx::AS3::Instances::fl_display::DisplayObject **)(v7 + 4);
  if ( ((unsigned __int8)result & 1) != 0 )
    return (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)result - 1);
  return result;
}
