void __thiscall Scaleform::GFx::MovieImpl::ResetFocusForChar(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::GFx::InteractiveObject *ch)
{
  Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject> *p_LastFocused; // edi
  Scaleform::WeakPtrProxy *pObject; // eax
  Scaleform::GFx::InteractiveObject *v5; // esi
  bool v6; // zf
  Scaleform::WeakPtrProxy *v7; // eax
  Scaleform::RefCountNTSImpl *v8; // ebx
  unsigned int ControllerMaskByFocusGroup; // edi
  unsigned int v10; // esi
  Scaleform::WeakPtrProxy *v11; // eax
  unsigned int i; // [esp+4h] [ebp-Ch]
  Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject> *v13; // [esp+8h] [ebp-8h]
  unsigned int cc; // [esp+Ch] [ebp-4h]

  i = 0;
  if ( this->FocusGroupsCnt )
  {
    p_LastFocused = &this->FocusGroups[0].LastFocused;
    v13 = &this->FocusGroups[0].LastFocused;
    do
    {
      pObject = p_LastFocused->pProxy.pObject;
      v5 = 0;
      if ( p_LastFocused->pProxy.pObject )
      {
        if ( pObject->pObject )
        {
          v5 = (Scaleform::GFx::InteractiveObject *)pObject->pObject;
          if ( v5->RefCount )
          {
            ++v5->RefCount;
            ++v5->RefCount;
            Scaleform::RefCountNTSImpl::Release(v5);
          }
          else
          {
            v5 = 0;
          }
        }
        else
        {
          v6 = pObject->RefCount-- == 1;
          if ( v6 )
            Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pObject);
          p_LastFocused->pProxy.pObject = 0;
        }
      }
      if ( v5 )
        Scaleform::RefCountNTSImpl::Release(v5);
      if ( v5 == ch )
      {
        v7 = p_LastFocused->pProxy.pObject;
        v8 = 0;
        if ( p_LastFocused->pProxy.pObject )
        {
          if ( v7->pObject )
          {
            v8 = v7->pObject;
            if ( v8->RefCount )
            {
              ++v8->RefCount;
              ++v8->RefCount;
              Scaleform::RefCountNTSImpl::Release(v8);
              if ( !Scaleform::GFx::MovieImpl::IsShutdowning(this) )
              {
                ControllerMaskByFocusGroup = Scaleform::GFx::MovieImpl::GetControllerMaskByFocusGroup(this, i);
                v10 = 0;
                for ( cc = this->GetControllerCount(this); ControllerMaskByFocusGroup; ControllerMaskByFocusGroup >>= 1 )
                {
                  if ( v10 >= cc )
                    break;
                  Scaleform::GFx::MovieImpl::SetFocusTo(this, 0, v10++, GFx_FocusMovedByKeyboard);
                }
                p_LastFocused = v13;
              }
            }
            else
            {
              v8 = 0;
            }
          }
          else
          {
            v6 = v7->RefCount-- == 1;
            if ( v6 )
              Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v7);
            p_LastFocused->pProxy.pObject = 0;
          }
        }
        v11 = p_LastFocused->pProxy.pObject;
        if ( p_LastFocused->pProxy.pObject )
        {
          v6 = v11->RefCount-- == 1;
          if ( v6 )
            Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v11);
        }
        p_LastFocused->pProxy.pObject = 0;
        if ( v8 )
          Scaleform::RefCountNTSImpl::Release(v8);
      }
      p_LastFocused += 16;
      ++i;
      v13 = p_LastFocused;
    }
    while ( i < this->FocusGroupsCnt );
  }
}
