unsigned int __thiscall Scaleform::GFx::StaticTextSnapshotData::GetCharCount(
        Scaleform::GFx::StaticTextSnapshotData *this)
{
  signed int Size; // ebx
  unsigned int CharCount; // edx
  int v3; // esi
  int v4; // edi
  unsigned int v5; // ebp
  unsigned int *p_CharCount; // eax
  unsigned int v7; // edx

  Size = this->StaticTextCharRefs.Data.Size;
  CharCount = 0;
  v3 = 0;
  v4 = 0;
  v5 = 0;
  if ( Size >= 2 )
  {
    p_CharCount = &this->StaticTextCharRefs.Data.Data[1].CharCount;
    v7 = ((unsigned int)(Size - 2) >> 1) + 1;
    v5 = 2 * v7;
    do
    {
      v3 += *(p_CharCount - 2);
      v4 += *p_CharCount;
      p_CharCount += 4;
      --v7;
    }
    while ( v7 );
    CharCount = 0;
  }
  if ( v5 < Size )
    CharCount = this->StaticTextCharRefs.Data.Data[v5].CharCount;
  return CharCount + v4 + v3;
}
