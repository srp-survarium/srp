void __thiscall Scaleform::GFx::AS2::DoActionTag::ExecuteWithPriority(
        Scaleform::GFx::AS2::DoActionTag *this,
        Scaleform::GFx::DisplayObjContainer *m,
        Scaleform::GFx::ActionPriority::Priority prio)
{
  Scaleform::GFx::AS2::AvmSprite *v4; // edi
  Scaleform::GFx::AS2::ActionBufferData *pObject; // eax
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // esi
  Scaleform::GFx::AS2::ActionBuffer *v7; // eax
  Scaleform::GFx::AS2::ActionBuffer *v8; // eax
  Scaleform::GFx::AS2::ActionBuffer *v9; // esi

  v4 = (Scaleform::GFx::AS2::AvmSprite *)(&m->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                        + m->AvmObjOffset);
  pObject = this->pBuf.pObject;
  if ( pObject && pObject->BufferLen && *pObject->pBuffer )
  {
    p_StringContext = &v4->GetASEnvironment(v4)->StringContext;
    v7 = (Scaleform::GFx::AS2::ActionBuffer *)p_StringContext->pContext->pHeap->Alloc(
                                                p_StringContext->pContext->pHeap,
                                                32u,
                                                0);
    if ( v7 )
    {
      Scaleform::GFx::AS2::ActionBuffer::ActionBuffer(v7, p_StringContext, this->pBuf.pObject);
      v9 = v8;
    }
    else
    {
      v9 = 0;
    }
    Scaleform::GFx::AS2::AvmSprite::AddActionBuffer(v4, v9, prio);
    if ( v9 )
      Scaleform::RefCountNTSImpl::Release(v9);
  }
}
