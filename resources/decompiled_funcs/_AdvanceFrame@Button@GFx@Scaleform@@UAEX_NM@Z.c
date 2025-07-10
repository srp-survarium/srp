void __thiscall Scaleform::GFx::Button::AdvanceFrame(Scaleform::GFx::Button *this, bool nextFrame, float __formal)
{
  unsigned __int8 AvmObjOffset; // dl
  int v4; // eax
  int v5; // [esp+0h] [ebp-14h] BYREF
  int v6; // [esp+Ch] [ebp-8h]
  char v7; // [esp+12h] [ebp-2h]
  char v8; // [esp+13h] [ebp-1h]

  if ( nextFrame )
  {
    AvmObjOffset = this->AvmObjOffset;
    if ( AvmObjOffset )
    {
      LOBYTE(v6) = 0;
      v7 = 0;
      v8 = 0;
      v4 = (*(int (__thiscall **)(char *, int, _DWORD, _DWORD, int, int))(*((_DWORD *)&this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                                                          + AvmObjOffset)
                                                                        + 12))(
             (char *)&this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
           + 4 * AvmObjOffset,
             2,
             0,
             0,
             v6,
             65280);
      (*(void (__thiscall **)(int, int *))(*(_DWORD *)v4 + 32))(v4, &v5);
    }
  }
}
