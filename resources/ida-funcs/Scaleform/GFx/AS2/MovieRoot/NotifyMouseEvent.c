void __thiscall Scaleform::GFx::AS2::MovieRoot::NotifyMouseEvent(
        Scaleform::GFx::AS2::MovieRoot *this,
        const Scaleform::GFx::InputEventsQueueEntry *qe,
        const Scaleform::GFx::MouseState *ms,
        float mi)
{
  Scaleform::GFx::MovieImpl *pMovieImpl; // edx
  unsigned int Size; // ecx
  unsigned int v7; // eax
  Scaleform::GFx::MovieImpl::LevelInfo *Data; // esi
  Scaleform::GFx::MovieImpl::LevelInfo *v9; // edx
  Scaleform::GFx::InteractiveObject *pObject; // eax
  Scaleform::GFx::AS2::Environment *v11; // esi
  bool v12; // al
  Scaleform::GFx::MovieImpl *v14; // ecx
  Scaleform::GFx::InteractiveObject *TopMostEntity; // eax
  Scaleform::GFx::InteractiveObject *v16; // esi
  Scaleform::GFx::ASMovieRootBase *pASRoot; // ecx
  __int16 v18; // cx
  unsigned int v19; // edi
  Scaleform::GFx::AS2::Environment *v20; // [esp+18h] [ebp-Ch]
  Scaleform::Render::Point<float> v21; // [esp+1Ch] [ebp-8h] BYREF
  bool v22; // [esp+2Ch] [ebp+8h]
  __int16 v23; // [esp+30h] [ebp+Ch]

  pMovieImpl = this->pMovieImpl;
  Size = pMovieImpl->MovieLevels.Data.Size;
  v7 = 0;
  if ( Size )
  {
    Data = pMovieImpl->MovieLevels.Data.Data;
    v9 = Data;
    while ( v9->Level )
    {
      ++v7;
      ++v9;
      if ( v7 >= Size )
        goto LABEL_5;
    }
    pObject = Data[v7].pSprite.pObject;
  }
  else
  {
LABEL_5:
    pObject = 0;
  }
  v11 = (Scaleform::GFx::AS2::Environment *)(*(int (__thiscall **)(int))(*((_DWORD *)&pObject->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                                                         + pObject->AvmObjOffset)
                                                                       + 124))((int)pObject + 4 * pObject->AvmObjOffset);
  v20 = v11;
  if ( this->pASMouseListener )
  {
    if ( !this->pASMouseListener->IsEmpty((Scaleform::GFx::AS2::MouseListener *)this->pASMouseListener) )
    {
      v12 = (*((_BYTE *)ms + 52) & 8) != 0;
      if ( (*((_BYTE *)ms + 52) & 8) != 0 || qe->u.mouseEntry.ButtonsState || (qe->u.mouseEntry.Flags & 0x20) != 0 )
      {
        v22 = v11->StringContext.pContext->GFxExtensions.Value == 1;
        if ( v12 )
          this->pASMouseListener->OnMouseMove(
            (Scaleform::GFx::AS2::MouseListener *)this->pASMouseListener,
            v11,
            LODWORD(mi));
        if ( (qe->u.mouseEntry.Flags & 0x20) != 0 || qe->u.mouseEntry.ButtonsState )
        {
          v14 = this->pMovieImpl;
          v21.x = qe->u.mouseEntry.PosX;
          v21.y = qe->u.mouseEntry.PosY;
          TopMostEntity = Scaleform::GFx::MovieImpl::GetTopMostEntity(v14, &v21, mi, 1, 0);
          v16 = TopMostEntity;
          if ( TopMostEntity )
          {
            pASRoot = TopMostEntity->pASRoot;
            ++TopMostEntity->RefCount;
            if ( pASRoot->AVMVersion != 1 )
              goto LABEL_30;
          }
          if ( (qe->u.mouseEntry.Flags & 0x20) != 0 )
            this->pASMouseListener->OnMouseWheel(
              (Scaleform::GFx::AS2::MouseListener *)this->pASMouseListener,
              v20,
              LODWORD(mi),
              qe->u.mouseEntry.WheelScrollDelta,
              TopMostEntity);
          if ( qe->u.mouseEntry.ButtonsState )
          {
            v18 = 1;
            v23 = 1;
            v19 = 1;
            do
            {
              if ( (qe->u.mouseEntry.ButtonsState & (unsigned __int16)v18) != 0 )
              {
                if ( (qe->u.mouseEntry.Flags & 0xC0) != 0 || !qe->u.mouseEntry.ButtonsState )
                  this->pASMouseListener->OnMouseUp(
                    (Scaleform::GFx::AS2::MouseListener *)this->pASMouseListener,
                    v20,
                    LODWORD(mi),
                    v19,
                    v16);
                else
                  this->pASMouseListener->OnMouseDown(
                    (Scaleform::GFx::AS2::MouseListener *)this->pASMouseListener,
                    v20,
                    LODWORD(mi),
                    v19,
                    v16);
              }
              if ( !v22 )
                break;
              v18 = 2 * v23;
              ++v19;
              v23 *= 2;
            }
            while ( v23 );
          }
          if ( v16 )
LABEL_30:
            Scaleform::RefCountNTSImpl::Release(v16);
        }
      }
    }
  }
}
