void __thiscall Scaleform::GFx::AS3::AvmTextField::OnEventLoad(Scaleform::GFx::AS3::AvmTextField *this)
{
  Scaleform::GFx::InteractiveObject *pDispObj; // esi
  Scaleform::GFx::InteractiveObject *pParent; // eax
  int v4; // eax
  int v5; // ecx
  Scaleform::GFx::InteractiveObject *v6; // eax
  Scaleform::GFx::InteractiveObject *v7; // esi
  unsigned int Flags; // eax
  int v9; // eax
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *pAS3RawPtr; // eax

  pDispObj = (Scaleform::GFx::InteractiveObject *)this->pDispObj;
  pParent = pDispObj->pParent;
  if ( pParent
    && (v4 = (*(int (__thiscall **)(int))(*((_DWORD *)&pParent->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                          + pParent->AvmObjOffset)
                                        + 4))((int)pParent + 4 * pParent->AvmObjOffset)) != 0 )
  {
    v5 = v4 - 28;
  }
  else
  {
    v5 = 0;
  }
  v6 = (Scaleform::GFx::InteractiveObject *)(*(int (__thiscall **)(int, Scaleform::GFx::InteractiveObject *))(*(_DWORD *)v5 + 100))(
                                              v5,
                                              pDispObj);
  if ( v6 )
    Scaleform::GFx::InteractiveObject::InsertToPlayListAfter(pDispObj, v6);
  else
    Scaleform::GFx::InteractiveObject::AddToPlayList(pDispObj);
  v7 = (Scaleform::GFx::InteractiveObject *)this->pDispObj;
  Flags = v7->Flags;
  LOBYTE(Flags) = (Flags & 0x200000) != 0 && (Flags >>= 22, (Flags & 1) == 0);
  v9 = v7->CheckAdvanceStatus(v7, Flags);
  if ( v9 == -1 )
  {
    v7->Flags |= (unsigned int)Scaleform::GFx::AS2::CreateShadow;
  }
  else if ( v9 == 1 )
  {
    Scaleform::GFx::InteractiveObject::AddToOptimizedPlayList(v7);
  }
  pAS3RawPtr = this->pAS3RawPtr;
  if ( !pAS3RawPtr )
    pAS3RawPtr = this->pAS3CollectiblePtr.pObject;
  if ( ((unsigned __int8)pAS3RawPtr & 1) != 0 )
    pAS3RawPtr = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)pAS3RawPtr - 1);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&this->pAS3CollectiblePtr,
    (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)pAS3RawPtr);
  this->pAS3RawPtr = 0;
}


void __thiscall Scaleform::GFx::AS3::AvmTextField::OnEventLoad(char *this)
{
  Scaleform::GFx::AS3::AvmTextField::OnEventLoad((Scaleform::GFx::AS3::AvmTextField *)(this - 28));
}


void __thiscall Scaleform::GFx::AS3::AvmTextField::OnEventLoad(char *this)
{
  Scaleform::GFx::AS3::AvmTextField::OnEventLoad((Scaleform::GFx::AS3::AvmTextField *)(this - 36));
}
