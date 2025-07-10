void __thiscall Scaleform::GFx::LoadQueueEntry::LoadQueueEntry(
        Scaleform::GFx::LoadQueueEntry *this,
        const Scaleform::String *url,
        Scaleform::GFx::LoadQueueEntry::LoadMethod method,
        bool loadingVars,
        bool quietOpen)
{
  Scaleform::String *p_URL; // edi
  Scaleform::GFx::LoadQueueEntry::LoadType v7; // eax

  p_URL = &this->URL;
  this->__vftable = (Scaleform::GFx::LoadQueueEntry_vtbl *)&Scaleform::GFx::LoadQueueEntry::`vftable';
  Scaleform::String::String(&this->URL);
  if ( loadingVars )
    v7 = LT_LoadText;
  else
    v7 = (url->HeapTypeBits & 0xFFFFFFFC) == -8;
  this->Type = v7;
  this->Method = method;
  this->pNext = 0;
  Scaleform::String::operator=(p_URL, url);
  this->EntryTime = -1;
  this->QuietOpen = quietOpen;
  this->Canceled = 0;
}
