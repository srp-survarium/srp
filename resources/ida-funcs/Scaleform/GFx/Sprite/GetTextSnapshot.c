void __thiscall Scaleform::GFx::Sprite::GetTextSnapshot(
        Scaleform::GFx::Sprite *this,
        Scaleform::GFx::StaticTextSnapshotData *pdata)
{
  int v3; // edi
  unsigned int Size; // ebx
  Scaleform::GFx::StaticTextCharacter *pCharacter; // esi
  int v6; // eax

  if ( this->mDisplayList.DisplayObjectArray.Data.Size )
  {
    v3 = 0;
    Size = this->mDisplayList.DisplayObjectArray.Data.Size;
    do
    {
      pCharacter = (Scaleform::GFx::StaticTextCharacter *)this->mDisplayList.DisplayObjectArray.Data.Data[v3].pCharacter;
      if ( pCharacter )
      {
        v6 = (int)pCharacter->GetCharacterDef(pCharacter);
        if ( v6 )
        {
          if ( ((*(int (__thiscall **)(int))(*(_DWORD *)v6 + 8))(v6) & 0xFF00) == 0x8200 )
            Scaleform::GFx::StaticTextSnapshotData::Add(pdata, pCharacter);
        }
      }
      ++v3;
      --Size;
    }
    while ( Size );
  }
}
