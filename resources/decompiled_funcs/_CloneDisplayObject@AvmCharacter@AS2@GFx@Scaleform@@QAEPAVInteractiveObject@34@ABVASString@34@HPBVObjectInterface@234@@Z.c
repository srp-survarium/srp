Scaleform::GFx::InteractiveObject *__thiscall Scaleform::GFx::AS2::AvmCharacter::CloneDisplayObject(
        Scaleform::GFx::AS2::AvmCharacter *this,
        const Scaleform::GFx::ASString *newname,
        unsigned int depth,
        const Scaleform::GFx::AS2::ObjectInterface *psource)
{
  Scaleform::GFx::InteractiveObject *pDispObj; // eax
  Scaleform::GFx::InteractiveObject *v6; // edi
  const Scaleform::Render::Cxform *Cxform; // eax
  int v8; // eax
  int v9; // esi
  float pos_92; // [esp+5Ch] [ebp-74h]
  const Scaleform::Render::Matrix2x4<float> *pos_92a; // [esp+5Ch] [ebp-74h]
  const char *v13; // [esp+60h] [ebp-70h]
  float v14; // [esp+64h] [ebp-6Ch]
  unsigned __int16 v15; // [esp+68h] [ebp-68h]
  bool v16; // [esp+6Ch] [ebp-64h]
  Scaleform::Render::BlendMode v17; // [esp+70h] [ebp-60h]
  _BYTE v18[44]; // [esp+84h] [ebp-4Ch] BYREF
  Scaleform::RefCountVImpl *v19; // [esp+B0h] [ebp-20h]

  pDispObj = this->pDispObj;
  v6 = (pDispObj->pParent->Flags & 0x400) != 0 ? pDispObj->pParent : 0;
  if ( !v6 || depth > 0x7EFFFFFD )
    return 0;
  pos_92 = ((double (__thiscall *)(Scaleform::GFx::InteractiveObject *, _DWORD, _DWORD, _DWORD))this->pDispObj->GetRatio)(
             this->pDispObj,
             pDispObj->ClipDepth,
             0,
             0);
  pos_92a = (const Scaleform::Render::Matrix2x4<float> *)((int (__thiscall *)(Scaleform::GFx::InteractiveObject *, _DWORD, _DWORD))this->pDispObj->GetMatrix)(
                                                           this->pDispObj,
                                                           0,
                                                           LODWORD(pos_92));
  Cxform = Scaleform::GFx::DisplayObjectBase::GetCxform(this->pDispObj);
  Scaleform::GFx::CharPosInfo::CharPosInfo(
    (Scaleform::GFx::CharPosInfo *)v18,
    this->pDispObj->Id,
    depth,
    1,
    Cxform,
    1,
    pos_92a,
    v13,
    v14,
    v15,
    v16,
    v17);
  v8 = ((int (__thiscall *)(Scaleform::GFx::InteractiveObject *, _BYTE *, const Scaleform::GFx::ASString *, _DWORD))v6->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable[1].~Scaleform::GFx::DisplayObjectBase)(
         v6,
         v18,
         newname,
         0);
  if ( !v8 )
  {
    if ( v19 )
      Scaleform::RefCountImpl::Release(v19);
    return 0;
  }
  v9 = *(_BYTE *)(v8 + 62) >> 7 != 0 ? v8 : 0;
  if ( v19 )
    Scaleform::RefCountImpl::Release(v19);
  return (Scaleform::GFx::InteractiveObject *)v9;
}
