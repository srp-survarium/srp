void __thiscall Scaleform::GFx::AS3::MovieRoot::OnKeyDown(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::InteractiveObject *pmovie,
        const Scaleform::GFx::EventId *evt,
        int keyMask)
{
  const Scaleform::GFx::EventId *v4; // ebx
  Scaleform::GFx::DisplayObject *v6; // edi
  int v7; // eax
  int v8; // eax
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *pActionRoot; // esi
  int v10; // eax
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *v11; // eax

  v4 = evt;
  Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject>::operator Scaleform::Ptr<Scaleform::GFx::InteractiveObject>(
    (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)&this[-1].LoadedMovieDefs.mHash.pTable[8
                                                                                       * *((unsigned __int8 *)&this[-1].LoadedMovieDefs.mHash.pTable[2026].SizeMask
                                                                                         + evt->ControllerIndex)
                                                                                       + 1900].SizeMask,
    (Scaleform::Ptr<Scaleform::GFx::Sprite> *)&evt);
  v6 = (Scaleform::GFx::DisplayObject *)evt;
  if ( evt )
  {
    ++evt->WcharCode;
    Scaleform::RefCountNTSImpl::Release(v6);
  }
  if ( ((1 << *((_BYTE *)&this[-1].LoadedMovieDefs.mHash.pTable[2026].SizeMask + v4->ControllerIndex)) & keyMask) == 0 )
  {
    if ( v6 )
    {
      v7 = (*(int (__thiscall **)(int))(*((_DWORD *)&v6->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                        + v6->AvmObjOffset)
                                      + 4))((int)v6 + 4 * v6->AvmObjOffset);
      if ( v7 )
      {
        v8 = v7 - 28;
LABEL_11:
        if ( *(_DWORD *)(v8 + 8) )
          v11 = *(Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher **)(v8 + 8);
        else
          v11 = *(Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher **)(v8 + 4);
        if ( ((unsigned __int8)v11 & 1) != 0 )
          v11 = (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)((char *)v11 - 1);
        if ( v11 )
          Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Dispatch(v11, v4, v6);
        goto LABEL_18;
      }
    }
    else
    {
      pActionRoot = this->ActionQueue.Entries[6].pActionRoot;
      if ( pActionRoot )
      {
        v10 = (*(int (__thiscall **)(int))(*((_DWORD *)&pActionRoot->pNextEntry + BYTE1(pActionRoot[1].pNextEntry)) + 20))((int)pActionRoot + 4 * BYTE1(pActionRoot[1].pNextEntry));
        if ( v10 )
        {
          v8 = v10 - 36;
          goto LABEL_11;
        }
      }
    }
    v8 = 0;
    goto LABEL_11;
  }
LABEL_18:
  if ( v6 )
    Scaleform::RefCountNTSImpl::Release(v6);
}
