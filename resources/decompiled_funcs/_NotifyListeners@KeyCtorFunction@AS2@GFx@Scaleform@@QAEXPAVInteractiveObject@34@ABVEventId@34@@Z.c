void __thiscall Scaleform::GFx::AS2::KeyCtorFunction::NotifyListeners(
        Scaleform::GFx::AS2::KeyCtorFunction *this,
        Scaleform::GFx::InteractiveObject *__formal,
        Scaleform::GFx::ASString evt)
{
  const Scaleform::GFx::EventId *pNode; // ebx
  Scaleform::GFx::AS2::KeyCtorFunction *v4; // esi
  char AsciiCode; // al
  unsigned int Id_low; // eax
  Scaleform::GFx::ASMovieRootBase *pObject; // edi
  unsigned int v8; // eax
  int v9; // eax
  Scaleform::GFx::MovieImpl *pMovieRoot; // eax
  Scaleform::GFx::MovieImpl *pMovieImpl; // edx
  unsigned int Size; // ecx
  unsigned int v13; // eax
  Scaleform::GFx::MovieImpl::LevelInfo *Data; // edi
  Scaleform::GFx::MovieImpl::LevelInfo *v15; // edx
  Scaleform::GFx::InteractiveObject *v16; // eax
  int v17; // ecx
  int v18; // eax
  Scaleform::GFx::AS2::Environment *v19; // edi
  unsigned int v20; // ebp
  Scaleform::GFx::AS2::Value *pCurrent; // esi
  int ControllerIndex; // eax
  Scaleform::GFx::ASStringNode *v23; // eax

  pNode = (const Scaleform::GFx::EventId *)evt.pNode;
  v4 = this;
  this->States[SBYTE1(evt.pNode->HashFlags)].LastKeyCode = (int)evt.pNode->pLower;
  AsciiCode = pNode->AsciiCode;
  if ( !AsciiCode )
    AsciiCode = Scaleform::GFx::EventId::ConvertKeyCodeToAscii(pNode);
  v4->States[pNode->ControllerIndex].LastAsciiCode = AsciiCode;
  v4->States[pNode->ControllerIndex].LastWcharCode = pNode->WcharCode;
  Id_low = LOBYTE(pNode->Id);
  pObject = v4->pMovieRoot->pASMovieRoot.pObject;
  if ( Id_low > (unsigned int)&unk_800000 )
    v8 = Id_low - 16777191;
  else
    v8 = (unsigned __int8)Scaleform::Alg::BitCount32(Id_low);
  if ( v8 - 1 > 0x21 )
    v9 = 46;
  else
    v9 = dword_8659E8[v8];
  evt.pNode = (Scaleform::GFx::ASStringNode *)*((_DWORD *)&pObject[8].RefCount + v9);
  ++evt.pNode->RefCount;
  pMovieRoot = v4->pMovieRoot;
  if ( pMovieRoot )
  {
    pMovieImpl = pMovieRoot->pASMovieRoot.pObject->pMovieImpl;
    Size = pMovieImpl->MovieLevels.Data.Size;
    v13 = 0;
    if ( Size )
    {
      Data = pMovieImpl->MovieLevels.Data.Data;
      v15 = Data;
      while ( v15->Level )
      {
        ++v13;
        ++v15;
        if ( v13 >= Size )
          goto LABEL_25;
      }
      v16 = Data[v13].pSprite.pObject;
      if ( v16 )
      {
        v17 = (int)v16 + 4 * v16->AvmObjOffset;
        v18 = (*(int (__thiscall **)(int))(*(_DWORD *)v17 + 124))(v17);
        v19 = (Scaleform::GFx::AS2::Environment *)v18;
        if ( v18 )
        {
          v20 = 0;
          if ( *(_BYTE *)(*(_DWORD *)(v18 + 116) + 52) == 1 )
          {
            *(_DWORD *)(v18 + 4) += 16;
            if ( *(_DWORD *)(v18 + 4) >= *(_DWORD *)(v18 + 12) )
              Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage((Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *)(v18 + 4));
            pCurrent = v19->Stack.pCurrent;
            if ( pCurrent )
            {
              ControllerIndex = pNode->ControllerIndex;
              pCurrent->T.Type = 4;
              pCurrent->NV.Int32Value = ControllerIndex;
            }
            v4 = this;
            v20 = 1;
          }
          Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessage(
            v19,
            &v4->Scaleform::GFx::AS2::ObjectInterface,
            &evt,
            v20,
            v19->Stack.pCurrent - v19->Stack.pPageStart + 32 * v19->Stack.Pages.Data.Size - 32);
          if ( v20 )
            Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Pop(&v19->Stack, v20);
        }
      }
    }
  }
LABEL_25:
  v23 = evt.pNode;
  --evt.pNode->RefCount;
  if ( !v23->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v23);
}
