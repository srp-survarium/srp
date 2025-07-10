void __thiscall Scaleform::GFx::AS3::FrameCounter::QueueFrameActions(Scaleform::GFx::AS3::FrameCounter *this)
{
  Scaleform::GFx::AS3::EventChains *p_AVMVersion; // ebp
  Scaleform::GFx::InteractiveObject *i; // esi
  Scaleform::GFx::AS3::AvmSprite *v4; // edi
  unsigned int v5; // eax
  Scaleform::GFx::InteractiveObject *j; // esi
  Scaleform::GFx::AS3::AvmSprite *v7; // edi
  unsigned int v8; // eax

  p_AVMVersion = (Scaleform::GFx::AS3::EventChains *)&this->pASRoot->pMovieImpl->pASMovieRoot.pObject[8].AVMVersion;
  Scaleform::GFx::AS3::EventChains::QueueEvents(
    p_AVMVersion,
    (Scaleform::GFx::EventId::IdCode)&vostok::memory::s_CRT_arena[5574221]);
  if ( (this->pASRoot->pMovieImpl->Flags & 0x80000) != 0 )
  {
    for ( i = this->pPlayPrev; i; i = i->pPlayPrev )
    {
      *((_BYTE *)&i->Depth + 4 * i->AvmObjOffset) |= 2u;
      if ( (i->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x400) != 0 )
      {
        v4 = (Scaleform::GFx::AS3::AvmSprite *)(&i->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                              + i->AvmObjOffset);
        if ( (v4->Flags & 2) != 0 )
        {
          v5 = ((int (__thiscall *)(Scaleform::GFx::DisplayObject *))v4->pDispObj->Scaleform::GFx::AS3::AvmDisplayObjContainer::Scaleform::GFx::AS3::AvmInteractiveObj::Scaleform::GFx::AS3::AvmDisplayObj::__vftable[1].GetY)(v4->pDispObj);
          Scaleform::GFx::AS3::AvmSprite::QueueFrameScript(v4, v5);
          v4->Flags &= ~2u;
        }
      }
    }
  }
  else
  {
    for ( j = this->pPlayPrevOpt; j; j = j->pPlayPrevOpt )
    {
      *((_BYTE *)&j->Depth + 4 * j->AvmObjOffset) |= 2u;
      if ( (j->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x400) != 0 )
      {
        v7 = (Scaleform::GFx::AS3::AvmSprite *)(&j->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                              + j->AvmObjOffset);
        if ( (v7->Flags & 2) != 0 )
        {
          v8 = ((int (__thiscall *)(Scaleform::GFx::DisplayObject *))v7->pDispObj->Scaleform::GFx::AS3::AvmDisplayObjContainer::Scaleform::GFx::AS3::AvmInteractiveObj::Scaleform::GFx::AS3::AvmDisplayObj::__vftable[1].GetY)(v7->pDispObj);
          Scaleform::GFx::AS3::AvmSprite::QueueFrameScript(v7, v8);
          v7->Flags &= ~2u;
        }
      }
    }
  }
  Scaleform::GFx::AS3::EventChains::QueueEvents(
    p_AVMVersion,
    (Scaleform::GFx::EventId::IdCode)&vostok::memory::s_CRT_arena[5574222]);
}
