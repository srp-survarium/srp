void __thiscall Scaleform::GFx::AS2::DoInitActionTag::Execute(
        Scaleform::GFx::AS2::DoInitActionTag *this,
        Scaleform::GFx::DisplayObjContainer *m)
{
  Scaleform::GFx::AS2::ActionBufferData *pObject; // eax
  Scaleform::GFx::AS2::AvmSprite *v4; // esi
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // edi
  Scaleform::GFx::AS2::ActionBuffer *v6; // eax
  Scaleform::GFx::AS2::ActionBuffer *v7; // eax
  Scaleform::GFx::AS2::ActionBuffer *v8; // edi

  pObject = this->pBuf.pObject;
  if ( pObject && pObject->BufferLen && *pObject->pBuffer )
  {
    v4 = (Scaleform::GFx::AS2::AvmSprite *)(&m->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                          + m->AvmObjOffset);
    p_StringContext = &v4->GetASEnvironment(v4)->StringContext;
    v6 = (Scaleform::GFx::AS2::ActionBuffer *)p_StringContext->pContext->pHeap->Alloc(
                                                p_StringContext->pContext->pHeap,
                                                32u,
                                                0);
    if ( v6 )
    {
      Scaleform::GFx::AS2::ActionBuffer::ActionBuffer(
        v6,
        p_StringContext,
        (Scaleform::GFx::Resource *)this->pBuf.pObject);
      v8 = v7;
    }
    else
    {
      v8 = 0;
    }
    Scaleform::GFx::AS2::AvmSprite::AddActionBuffer(v4, v8, AP_InitClip);
    if ( v8 )
      Scaleform::RefCountNTSImpl::Release(v8);
  }
}
