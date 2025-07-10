const Scaleform::GFx::TextKeyMap::KeyMapEntry *__thiscall Scaleform::GFx::TextKeyMap::Find(
        Scaleform::GFx::TextKeyMap *this,
        unsigned int keyCode,
        const Scaleform::KeyModifiers *specKeys,
        Scaleform::GFx::TextKeyMap::KeyState state)
{
  unsigned int v4; // ebx
  Scaleform::Array<Scaleform::GFx::TextKeyMap::KeyMapEntry,2,Scaleform::ArrayDefaultPolicy> *p_Map; // esi
  unsigned int v7; // eax
  unsigned int Size; // edi
  Scaleform::GFx::TextKeyMap::KeyMapEntry *Data; // esi
  const Scaleform::GFx::TextKeyMap::KeyMapEntry *result; // eax
  int v11; // ecx
  int v12; // ecx
  unsigned int v13; // ebp
  const Scaleform::GFx::TextKeyMap::KeyMapEntry *v14; // ecx

  v4 = keyCode;
  p_Map = &this->Map;
  v7 = Scaleform::Alg::LowerBoundSliced<Scaleform::Array<Scaleform::GFx::TextKeyMap::KeyMapEntry,2,Scaleform::ArrayDefaultPolicy>,unsigned int,int (__cdecl *)(Scaleform::GFx::TextKeyMap::KeyMapEntry const &,unsigned int)>(
         &this->Map,
         0,
         this->Map.Data.Size,
         &keyCode,
         Scaleform::GFx::`anonymous namespace'::KeyCodeComparator::Less);
  Size = this->Map.Data.Size;
  if ( v7 >= Size )
    return 0;
  Data = p_Map->Data.Data;
  result = &Data[v7];
  if ( result->KeyCode != v4 || !result )
    return 0;
  while ( result->mState != state || (result->SpecKeysPressed & specKeys->States) != result->SpecKeysPressed )
  {
    v11 = result - Data;
    if ( v11 + 1 < Size )
    {
      v12 = v11;
      v13 = Data[v12 + 1].KeyCode;
      v14 = &Data[v12];
      if ( v13 == result->KeyCode )
      {
        result = v14 + 1;
        if ( v14 != (const Scaleform::GFx::TextKeyMap::KeyMapEntry *)-16 )
          continue;
      }
    }
    return 0;
  }
  return result;
}
