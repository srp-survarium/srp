void __thiscall Scaleform::GFx::DisplayList::PropagateMouseEvent(
        Scaleform::GFx::DisplayList *this,
        const Scaleform::GFx::EventId *id)
{
  signed int i; // esi
  char *pCharacter; // edi

  for ( i = this->DisplayObjectArray.Data.Size - 1; i >= 0; --i )
  {
    pCharacter = (char *)this->DisplayObjectArray.Data.Data[i].pCharacter;
    if ( (*(unsigned __int8 (__thiscall **)(char *))(*(_DWORD *)pCharacter + 228))(pCharacter) )
    {
      if ( pCharacter[62] < 0 )
        (*(void (__thiscall **)(char *, const Scaleform::GFx::EventId *))(*(_DWORD *)pCharacter + 388))(pCharacter, id);
      if ( i >= (signed int)this->DisplayObjectArray.Data.Size )
        i = this->DisplayObjectArray.Data.Size;
    }
  }
}
