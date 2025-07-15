void __thiscall Scaleform::GFx::AS2::DoActionTag::Execute(
        Scaleform::GFx::AS2::DoActionTag *this,
        Scaleform::GFx::DisplayObjContainer *m)
{
  Scaleform::GFx::AS2::AvmSprite *v2; // edi
  int v4; // eax
  Scaleform::GFx::AS2::ActionBufferData *pObject; // ecx
  Scaleform::GFx::AS2::ASStringContext *v6; // esi
  Scaleform::GFx::AS2::ActionBuffer *v7; // eax
  Scaleform::GFx::AS2::ActionBuffer *v8; // eax
  Scaleform::GFx::AS2::ActionBuffer *v9; // esi

  v2 = (Scaleform::GFx::AS2::AvmSprite *)(&m->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                        + m->AvmObjOffset);
  v4 = (int)v2->GetASEnvironment(v2);
  pObject = this->pBuf.pObject;
  if ( pObject && pObject->BufferLen && *pObject->pBuffer )
  {
    v6 = (Scaleform::GFx::AS2::ASStringContext *)(v4 + 116);
    v7 = (Scaleform::GFx::AS2::ActionBuffer *)(*(int (__thiscall **)(_DWORD, int, _DWORD))(**(_DWORD **)(*(_DWORD *)(v4 + 116) + 24)
                                                                                         + 40))(
                                                *(_DWORD *)(*(_DWORD *)(v4 + 116) + 24),
                                                32,
                                                0);
    if ( v7 )
    {
      Scaleform::GFx::AS2::ActionBuffer::ActionBuffer(v7, v6, this->pBuf.pObject);
      v9 = v8;
    }
    else
    {
      v9 = 0;
    }
    Scaleform::GFx::AS2::AvmSprite::AddActionBuffer(v2, v9, AP_Frame);
    if ( v9 )
      Scaleform::RefCountNTSImpl::Release(v9);
  }
}
