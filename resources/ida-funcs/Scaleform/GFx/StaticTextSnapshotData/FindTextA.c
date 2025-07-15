int __thiscall Scaleform::GFx::StaticTextSnapshotData::FindTextA(
        Scaleform::GFx::StaticTextSnapshotData *this,
        signed int start,
        char *query,
        char *bcaseSensitive)
{
  unsigned int Char_Advance0; // edi
  char v6; // bl
  signed int v7; // ebp
  int v8; // eax
  int v9; // esi
  int v10; // edi
  int v11; // edi
  int v12; // esi
  int v13; // eax
  bool v14; // zf
  int v15; // edx
  int v16; // ecx
  int v17; // ebp
  char *v19; // [esp+10h] [ebp-Ch] BYREF
  char *v20; // [esp+14h] [ebp-8h] BYREF
  int c; // [esp+18h] [ebp-4h]

  Char_Advance0 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&query);
  c = Char_Advance0;
  if ( !Char_Advance0 )
    --query;
  v6 = (char)bcaseSensitive;
  v20 = (char *)((this->SnapshotString.HeapTypeBits & 0xFFFFFFFC) + 8);
  v7 = 0;
  while ( 1 )
  {
    v8 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&v20);
    v9 = v8;
    if ( !v8 )
      return -1;
    if ( v7 < start )
      goto LABEL_8;
    if ( v6 )
    {
      if ( v8 != Char_Advance0 )
        goto LABEL_8;
LABEL_15:
      v19 = v20;
      bcaseSensitive = query;
      do
      {
        v11 = -1;
        v12 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&bcaseSensitive);
        if ( !v12 )
          --bcaseSensitive;
        do
        {
          v13 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&v19);
          if ( !v13 )
            --v19;
          ++v11;
        }
        while ( v13 == 10 );
        if ( !v13 )
          break;
        if ( !v12 )
          return v7;
        if ( v6 )
        {
          v14 = v13 == v12;
        }
        else
        {
          if ( v13 < 97 || (v15 = v13 - 32, v13 > 122) )
            v15 = v13;
          if ( v12 < 97 || (v16 = v12 - 32, v12 > 122) )
            v16 = v12;
          v14 = v15 == v16;
        }
      }
      while ( v14 );
      if ( !v12 )
        return v7;
      if ( !v13 )
        return -1;
      v17 = v7 - v11;
      Char_Advance0 = c;
      v7 = v17 + 1;
    }
    else
    {
      if ( v8 < 97 || (v10 = v8 - 32, v8 > 122) )
        v10 = v8;
      if ( v10 == Scaleform::SFtoupper(c) )
        goto LABEL_15;
LABEL_8:
      if ( v9 == 10 )
        --v7;
      Char_Advance0 = c;
      ++v7;
    }
  }
}
