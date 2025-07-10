void __thiscall Scaleform::GFx::AS2::GFxAS2LoadQueueEntry::GFxAS2LoadQueueEntry(
        Scaleform::GFx::AS2::GFxAS2LoadQueueEntry *this,
        int level,
        const Scaleform::String *url,
        Scaleform::GFx::LoadQueueEntry::LoadMethod method,
        bool loadingVars,
        bool quietOpen)
{
  Scaleform::GFx::CharacterHandle *pObject; // edi

  Scaleform::GFx::LoadQueueEntry::LoadQueueEntry(this, url, method, loadingVars, quietOpen);
  this->__vftable = (Scaleform::GFx::AS2::GFxAS2LoadQueueEntry_vtbl *)&Scaleform::GFx::AS2::GFxAS2LoadQueueEntry::`vftable';
  this->pCharacter.pObject = 0;
  this->MovieClipLoaderHolder.T.Type = 0;
  this->LoadVarsHolder.T.Type = 0;
  this->XMLHolder.ASObj.T.Type = 0;
  this->XMLHolder.Loader.pObject = 0;
  this->CSSHolder.ASObj.T.Type = 0;
  this->CSSHolder.Loader.pObject = 0;
  pObject = this->pCharacter.pObject;
  if ( pObject )
  {
    if ( --pObject->RefCount <= 0 )
    {
      Scaleform::GFx::CharacterHandle::~CharacterHandle(pObject);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pObject);
    }
  }
  this->pCharacter.pObject = 0;
  this->Level = level;
  if ( loadingVars )
    this->Type = LT_LoadText|LT_LoadLevel;
  else
    this->Type = ((url->HeapTypeBits & 0xFFFFFFFC) == -8) | 2;
}
