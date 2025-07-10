void __thiscall Scaleform::GFx::AS3::AvmSprite::AdvanceFrame(
        Scaleform::GFx::AS3::AvmSprite *this,
        bool nextFrame,
        float framePos)
{
  Scaleform::GFx::AvmInteractiveObjBase_vtbl *v4; // edi
  Scaleform::GFx::AvmTextFieldBase *(__thiscall *ToAvmTextFieldBase)(Scaleform::GFx::AvmDisplayObjBase *); // ecx
  unsigned int v6; // ebp
  unsigned int v7; // esi
  Scaleform::GFx::InteractiveObject *v8; // ecx
  unsigned int mouseIdx; // [esp+8h] [ebp-4h] BYREF

  v4 = this[-1].Scaleform::GFx::AS3::AvmDisplayObjContainer::Scaleform::GFx::AS3::AvmInteractiveObj::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::__vftable;
  if ( v4 )
    ++v4->ToAvmInteractiveObjBase;
  if ( ((int)v4[1].ToAvmButttonBase & 0xC) == 0
    && (HIWORD(v4->CloneInternalData) & 0x1000) == 0
    && (int)v4->GetAbsolutePath >= -1 )
  {
    ToAvmTextFieldBase = this[-1].ToAvmTextFieldBase;
    if ( *(_DWORD *)(*((_DWORD *)ToAvmTextFieldBase + 2) + 4924)
      && Scaleform::GFx::MovieImpl::IsDraggingCharacter(
           *((Scaleform::GFx::MovieImpl **)ToAvmTextFieldBase + 2),
           (const Scaleform::GFx::InteractiveObject *)v4,
           &mouseIdx) )
    {
      Scaleform::GFx::InteractiveObject::DoMouseDrag((Scaleform::GFx::InteractiveObject *)v4, mouseIdx);
    }
    if ( nextFrame && ((int)this->pDispObj & 2) == 0 )
    {
      v6 = (*((int (__thiscall **)(Scaleform::GFx::AvmInteractiveObjBase_vtbl *))v4->~Scaleform::GFx::AvmDisplayObjBase
            + 105))(v4);
      if ( !(*((int (__thiscall **)(Scaleform::GFx::AvmInteractiveObjBase_vtbl *))v4->~Scaleform::GFx::AvmDisplayObjBase
             + 113))(v4) )
      {
        v7 = v6;
        Scaleform::GFx::Sprite::IncrementFrameAndCheckForLoop((Scaleform::GFx::Sprite *)v4);
        v6 = (*((int (__thiscall **)(Scaleform::GFx::AvmInteractiveObjBase_vtbl *))v4->~Scaleform::GFx::AvmDisplayObjBase
              + 105))(v4);
        if ( v6 != v7 )
        {
          (*((void (__thiscall **)(const char **, unsigned int))this[-1].pClassName + 28))(&this[-1].pClassName, v6);
          Scaleform::GFx::Sprite::ExecuteFrameTags((Scaleform::GFx::Sprite *)v4, v6);
          v8 = (Scaleform::GFx::InteractiveObject *)*((_DWORD *)&this[-1].pClassName + 3);
          *((_BYTE *)&this[-1].pClassName + 52) |= 2u;
          if ( Scaleform::GFx::InteractiveObject::IsInPlayList(v8) )
            Scaleform::GFx::InteractiveObject::AddToOptimizedPlayList(*((Scaleform::GFx::InteractiveObject **)&this[-1].pClassName
                                                                      + 3));
        }
      }
      if ( !v6 )
        Scaleform::GFx::DisplayList::UnloadMarkedObjects(
          (Scaleform::GFx::DisplayList *)&this[-1].Scaleform::GFx::AS3::AvmDisplayObjContainer::Scaleform::GFx::AS3::AvmInteractiveObj::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::__vftable[1].OnEvent,
          (Scaleform::GFx::DisplayObjectBase *)this[-1].Scaleform::GFx::AS3::AvmDisplayObjContainer::Scaleform::GFx::AS3::AvmInteractiveObj::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::__vftable);
    }
  }
  Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)v4);
}
