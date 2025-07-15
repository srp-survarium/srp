void __thiscall Scaleform::GFx::AS3::MovieRoot::RemoveActionQueueEntriesFor(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::AS3::MovieRoot::ActionLevel lvl,
        Scaleform::GFx::DisplayObject *dobj)
{
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *i; // esi
  Scaleform::RefCountNTSImpl *pObject; // ecx

  for ( i = this->ActionQueue.Entries[lvl].pActionRoot; i; i = i->pNextEntry )
  {
    if ( i->pCharacter.pObject == dobj )
    {
      pObject = i->pCharacter.pObject;
      if ( pObject )
        Scaleform::RefCountNTSImpl::Release(pObject);
      i->pCharacter.pObject = 0;
    }
  }
}
