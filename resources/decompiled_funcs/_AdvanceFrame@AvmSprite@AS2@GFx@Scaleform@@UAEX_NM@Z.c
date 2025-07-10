void __userpurge Scaleform::GFx::AS2::AvmSprite::AdvanceFrame(
        Scaleform::GFx::AS2::AvmSprite *this@<ecx>,
        int a2@<ebp>,
        bool nextFrame,
        float framePos)
{
  unsigned int Capacity; // esi
  unsigned int v6; // ebp
  unsigned int v7; // ebx
  void (__thiscall *v8)(int *, unsigned int *); // edx
  Scaleform::GFx::EventId v9; // [esp+Ch] [ebp-14h] BYREF
  _UNKNOWN *retaddr; // [esp+20h] [ebp+0h]

  Capacity = this[-1].InitActionsExecuted.Data.Policy.Capacity;
  if ( Capacity )
    ++*(_DWORD *)(Capacity + 4);
  if ( (*(_BYTE *)(Capacity + 104) & 0xC) == 0
    && (*(_WORD *)(Capacity + 62) & 0x1000) == 0
    && *(int *)(Capacity + 24) >= -1 )
  {
    if ( *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this[-1].InitActionsExecuted.Data.Policy.Capacity + 16) + 8) + 4924) )
      Scaleform::GFx::InteractiveObject::DoMouseDrag((Scaleform::GFx::InteractiveObject *)Capacity, 0);
    if ( nextFrame )
    {
      v6 = (*(int (__thiscall **)(unsigned int, int))(*(_DWORD *)Capacity + 420))(Capacity, a2);
      if ( (*(int (__thiscall **)(unsigned int))(*(_DWORD *)Capacity + 452))(Capacity) )
      {
        v8 = *(void (__thiscall **)(int *, unsigned int *))(this[-1].Level + 32);
        memset(&v9.KeyCode, 0, 9);
        LOBYTE(retaddr) = 0;
        HIBYTE(retaddr) = 0;
        v9.WcharCode = 2;
        *(_WORD *)((char *)&retaddr + 1) = 255;
        v8(&this[-1].Level, &v9.WcharCode);
      }
      else
      {
        v7 = v6;
        Scaleform::GFx::Sprite::IncrementFrameAndCheckForLoop((Scaleform::GFx::Sprite *)Capacity);
        v6 = (*(int (__thiscall **)(unsigned int))(*(_DWORD *)Capacity + 420))(Capacity);
        if ( v6 == v7 )
        {
          Scaleform::GFx::EventId::EventId((Scaleform::GFx::EventId *)&v9.WcharCode, 2u);
          (*(void (__thiscall **)(int *, unsigned int *))(this[-1].Level + 32))(&this[-1].Level, &v9.WcharCode);
        }
        else
        {
          ((void (__thiscall *)(Scaleform::GFx::AS2::AvmSprite *))this->ReplaceChildCharacterOnLoad)(this);
          Scaleform::GFx::EventId::EventId(&v9, 2u);
          (*(void (__thiscall **)(int *, Scaleform::GFx::EventId *))(this[-1].Level + 32))(&this[-1].Level, &v9);
          Scaleform::GFx::Sprite::ExecuteFrameTags((Scaleform::GFx::Sprite *)Capacity, v6);
        }
      }
      if ( !v6 )
        Scaleform::GFx::DisplayList::UnloadMarkedObjects(
          (Scaleform::GFx::DisplayList *)(this[-1].InitActionsExecuted.Data.Policy.Capacity + 124),
          (Scaleform::GFx::DisplayObjectBase *)this[-1].InitActionsExecuted.Data.Policy.Capacity);
    }
  }
  Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)Capacity);
}
