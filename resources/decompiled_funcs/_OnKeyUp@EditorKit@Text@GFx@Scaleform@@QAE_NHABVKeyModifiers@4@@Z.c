char __thiscall Scaleform::GFx::Text::EditorKit::OnKeyUp(
        Scaleform::GFx::Text::EditorKit *this,
        unsigned int keyCode,
        const Scaleform::KeyModifiers *specKeysState)
{
  Scaleform::GFx::TextKeyMap *pObject; // ecx
  const Scaleform::GFx::TextKeyMap::KeyMapEntry *v5; // eax
  unsigned __int16 Flags; // ax

  pObject = this->pKeyMap.pObject;
  if ( pObject )
  {
    v5 = Scaleform::GFx::TextKeyMap::Find(pObject, keyCode, specKeysState, State_Up);
    if ( v5 )
    {
      if ( v5->Action == KeyAct_LeaveSelectionMode )
      {
        Flags = this->Flags;
        if ( (Flags & 2) != 0 && (Flags & 0x40) != 0 )
          this->Flags = Flags & 0xFFBF;
      }
    }
  }
  return 1;
}
