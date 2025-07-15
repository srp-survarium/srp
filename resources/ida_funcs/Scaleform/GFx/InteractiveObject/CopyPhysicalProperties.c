void __thiscall Scaleform::GFx::InteractiveObject::CopyPhysicalProperties(
        Scaleform::GFx::InteractiveObject *this,
        const Scaleform::GFx::InteractiveObject *poldChar)
{
  const Scaleform::Render::Cxform *Cxform; // eax
  Scaleform::Render::TreeNode *pObject; // eax
  Scaleform::GFx::InteractiveObject_vtbl *v5; // ebx
  const Scaleform::Render::Matrix3x4<float> *v6; // eax
  Scaleform::GFx::InteractiveObject_vtbl *v7; // ebx
  const Scaleform::Render::Matrix2x4<float> *v8; // eax
  const Scaleform::Render::FilterSet *v9; // eax
  unsigned __int8 AvmObjOffset; // al
  int v11; // eax

  this->Depth = poldChar->Depth;
  Cxform = Scaleform::GFx::DisplayObjectBase::GetCxform(&poldChar->Scaleform::GFx::DisplayObject);
  Scaleform::GFx::DisplayObjectBase::SetCxform(this, Cxform);
  pObject = this->pRenNode.pObject;
  if ( pObject
    && (*(_WORD *)(*(_DWORD *)(*(_DWORD *)(((unsigned int)pObject & 0xFFFFF000) + 0x10)
                             + 4 * ((int)((int)&pObject[-1] - ((unsigned int)pObject & 0xFFFFF000)) / 28)
                             + 20)
                 + 6)
      & 0x200) != 0 )
  {
    v5 = this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable;
    v6 = poldChar->GetMatrix3D(poldChar);
    v5->SetMatrix3D(this, v6);
  }
  else
  {
    v7 = this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable;
    v8 = poldChar->GetMatrix(poldChar);
    v7->SetMatrix(this, v8);
  }
  if ( poldChar->pGeomData )
    Scaleform::GFx::DisplayObjectBase::SetGeomData(this, poldChar->pGeomData);
  v9 = poldChar->GetFilters(poldChar);
  if ( v9 )
    this->SetFilters(this, v9);
  AvmObjOffset = this->AvmObjOffset;
  if ( AvmObjOffset )
  {
    v11 = (*(int (__thiscall **)(char *))(*((_DWORD *)&this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                          + AvmObjOffset)
                                        + 4))(
            (char *)&this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
          + 4 * AvmObjOffset);
    (*(void (__thiscall **)(int, const Scaleform::GFx::InteractiveObject *))(*(_DWORD *)v11 + 64))(v11, poldChar);
  }
}
