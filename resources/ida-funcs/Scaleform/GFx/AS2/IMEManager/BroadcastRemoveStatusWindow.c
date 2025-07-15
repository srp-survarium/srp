void __thiscall Scaleform::GFx::AS2::IMEManager::BroadcastRemoveStatusWindow(
        Scaleform::GFx::AS2::IMEManager *this,
        const char *pString)
{
  Scaleform::GFx::Movie *pMovie; // eax
  Scaleform::GFx::ASMovieRootBase *pObject; // eax
  Scaleform::GFx::InteractiveObject *pMainMovie; // edi
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *inserted; // eax
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v6; // esi
  Scaleform::RefCountNTSImpl *v7; // ecx
  Scaleform::RefCountNTSImpl *v8; // ecx

  pMovie = this->pMovie;
  if ( pMovie )
  {
    pObject = pMovie->pASMovieRoot.pObject;
    pMainMovie = pObject->pMovieImpl->pMainMovie;
    inserted = Scaleform::GFx::AS2::MovieRoot::ActionQueueType::InsertEntry(
                 (Scaleform::GFx::AS2::MovieRoot::ActionQueueType *)&pObject[3].pMovieImpl,
                 AP_Frame);
    v6 = inserted;
    inserted->Type = Entry_CFunction;
    if ( pMainMovie )
      ++pMainMovie->RefCount;
    v7 = inserted->pCharacter.pObject;
    if ( v7 )
      Scaleform::RefCountNTSImpl::Release(v7);
    v6->pCharacter.pObject = pMainMovie;
    v8 = v6->pActionBuffer.pObject;
    if ( v8 )
      Scaleform::RefCountNTSImpl::Release(v8);
    v6->pActionBuffer.pObject = 0;
    v6->CFunction = Scaleform::GFx::AS2::IMEManager::OnBroadcastRemoveStatusWindow;
  }
}
