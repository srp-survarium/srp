void __thiscall Scaleform::GFx::Sprite::OnEventXmlsocketOnxml(Scaleform::GFx::Sprite *this)
{
  unsigned __int8 AvmObjOffset; // dl
  int v2; // eax
  int v3; // [esp+0h] [ebp-14h] BYREF
  int v4; // [esp+Ch] [ebp-8h]
  char v5; // [esp+12h] [ebp-2h]
  char v6; // [esp+13h] [ebp-1h]

  AvmObjOffset = this->AvmObjOffset;
  if ( AvmObjOffset )
  {
    LOBYTE(v4) = 0;
    v5 = 0;
    v6 = 0;
    v2 = (*(int (__thiscall **)(char *, int, _DWORD, _DWORD, int, int))(*((_DWORD *)&this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                                                        + AvmObjOffset)
                                                                      + 8))(
           (char *)&this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
         + 4 * AvmObjOffset,
           16777223,
           0,
           0,
           v4,
           65280);
    (*(void (__thiscall **)(int, int *))(*(_DWORD *)v2 + 32))(v2, &v3);
  }
}
