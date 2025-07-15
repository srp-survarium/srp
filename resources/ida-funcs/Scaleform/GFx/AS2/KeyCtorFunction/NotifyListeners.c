void __thiscall Scaleform::GFx::AS2::KeyCtorFunction::NotifyListeners(
        Scaleform::GFx::AS2::KeyCtorFunction *this,
        Scaleform::GFx::InteractiveObject *__formal,
        Scaleform::GFx::ASStringNode *evt)
{
  Scaleform::GFx::EventId *v3; // ebx
  Scaleform::GFx::AS2::KeyCtorFunction *v4; // esi
  char AsciiCode; // al
  Scaleform::GFx::ASMovieRootBase *pObject; // edi
  int v7; // eax
  int v8; // eax
  Scaleform::GFx::MovieImpl *pMovieRoot; // eax
  Scaleform::GFx::MovieImpl *pMovieImpl; // edx
  unsigned int Size; // ecx
  unsigned int v12; // eax
  Scaleform::GFx::MovieImpl::LevelInfo *Data; // edi
  Scaleform::GFx::MovieImpl::LevelInfo *v14; // edx
  Scaleform::GFx::InteractiveObject *v15; // eax
  int v16; // ecx
  int v17; // eax
  Scaleform::GFx::AS2::Environment *v18; // edi
  unsigned int v19; // ebp
  Scaleform::GFx::AS2::Value *pCurrent; // esi
  int ControllerIndex; // eax
  Scaleform::GFx::ASStringNode *v22; // eax

  v3 = (Scaleform::GFx::EventId *)evt;
  v4 = this;
  this->States[SBYTE1(evt->HashFlags)].LastKeyCode = (int)evt->pLower;
  AsciiCode = v3->AsciiCode;
  if ( !AsciiCode )
    AsciiCode = Scaleform::GFx::EventId::ConvertKeyCodeToAscii(v3);
  v4->States[v3->ControllerIndex].LastAsciiCode = AsciiCode;
  v4->States[v3->ControllerIndex].LastWcharCode = v3->WcharCode;
  pObject = v4->pMovieRoot->pASMovieRoot.pObject;
  v7 = (unsigned __int8)Scaleform::Alg::BitCount32(LOBYTE(v3->Id));
  if ( (unsigned int)(v7 - 1) > 0x21 )
    v8 = 46;
  else
    v8 = dword_6F9848[v7];
  evt = (Scaleform::GFx::ASStringNode *)*((_DWORD *)&pObject[8].RefCount + v8);
  ++evt->RefCount;
  pMovieRoot = v4->pMovieRoot;
  if ( pMovieRoot )
  {
    pMovieImpl = pMovieRoot->pASMovieRoot.pObject->pMovieImpl;
    Size = pMovieImpl->MovieLevels.Data.Size;
    v12 = 0;
    if ( Size )
    {
      Data = pMovieImpl->MovieLevels.Data.Data;
      v14 = Data;
      while ( v14->Level )
      {
        ++v12;
        ++v14;
        if ( v12 >= Size )
          goto LABEL_22;
      }
      v15 = Data[v12].pSprite.pObject;
      if ( v15 )
      {
        v16 = (int)v15 + 4 * v15->AvmObjOffset;
        v17 = (*(int (__thiscall **)(int))(*(_DWORD *)v16 + 124))(v16);
        v18 = (Scaleform::GFx::AS2::Environment *)v17;
        if ( v17 )
        {
          v19 = 0;
          if ( *(_BYTE *)(*(_DWORD *)(v17 + 116) + 52) == 1 )
          {
            *(_DWORD *)(v17 + 4) += 16;
            if ( *(_DWORD *)(v17 + 4) >= *(_DWORD *)(v17 + 12) )
              Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage((Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *)(v17 + 4));
            pCurrent = v18->Stack.pCurrent;
            if ( pCurrent )
            {
              ControllerIndex = v3->ControllerIndex;
              pCurrent->T.Type = 4;
              pCurrent->NV.Int32Value = ControllerIndex;
            }
            v4 = this;
            v19 = 1;
          }
          Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessage(
            v18,
            &v4->Scaleform::GFx::AS2::ObjectInterface,
            (const Scaleform::GFx::ASString *)&evt,
            (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback_vtbl *)v19,
            (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback_vtbl *)(v18->Stack.pCurrent
                                                                      - v18->Stack.pPageStart
                                                                      + 32 * v18->Stack.Pages.Data.Size
                                                                      - 32));
          if ( v19 )
            Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Pop(&v18->Stack, v19);
        }
      }
    }
  }
LABEL_22:
  v22 = evt;
  --evt->RefCount;
  if ( !v22->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v22);
}
