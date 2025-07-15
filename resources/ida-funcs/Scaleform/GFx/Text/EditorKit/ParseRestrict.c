char __thiscall Scaleform::GFx::Text::EditorKit::ParseRestrict(
        Scaleform::GFx::Text::EditorKit *this,
        char *restrStr,
        unsigned int restrStrLen)
{
  Scaleform::StringLH *v4; // eax
  Scaleform::GFx::Text::EditorKit::RestrictParams *v5; // esi
  unsigned int v6; // ebp
  Scaleform::GFx::Text::EditorKit::RestrictParams *pObject; // ecx
  char *v9; // ecx
  unsigned int v10; // esi
  unsigned int Char_Advance0; // eax
  unsigned int v12; // edi
  unsigned int v13; // eax
  Scaleform::GFx::Text::EditorKit::RestrictParams *v14; // ecx
  Scaleform::GFx::Text::EditorKit::RestrictParams *v15; // ecx
  char *putf8Buffer; // [esp+Ch] [ebp-20h] BYREF
  int v17; // [esp+10h] [ebp-1Ch] BYREF
  Scaleform::RangeData<void *> range; // [esp+14h] [ebp-18h] BYREF
  Scaleform::RangeData<void *> v19; // [esp+20h] [ebp-Ch] BYREF
  bool v20; // [esp+30h] [ebp+4h]
  unsigned int v21; // [esp+34h] [ebp+8h]

  v17 = 325;
  v4 = (Scaleform::StringLH *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                Scaleform::Memory::pGlobalHeap,
                                this,
                                16,
                                &v17);
  v5 = (Scaleform::GFx::Text::EditorKit::RestrictParams *)v4;
  v6 = 0;
  if ( v4 )
  {
    v4->HeapTypeBits = 0;
    v4[1].HeapTypeBits = 0;
    v4[2].HeapTypeBits = 0;
    Scaleform::StringLH::StringLH(v4 + 3);
  }
  else
  {
    v5 = 0;
  }
  pObject = this->pRestrict.pObject;
  if ( pObject != v5 )
  {
    if ( pObject && this->pRestrict.Owner )
    {
      this->pRestrict.Owner = 0;
      Scaleform::GFx::Text::EditorKit::RestrictParams::`scalar deleting destructor'(pObject, 1);
    }
    this->pRestrict.pObject = v5;
  }
  this->pRestrict.Owner = v5 != 0;
  if ( !this->pRestrict.pObject )
    return 0;
  v9 = &restrStr[restrStrLen];
  v10 = 0;
  putf8Buffer = restrStr;
  v20 = 0;
  v21 = (unsigned int)v9;
  if ( putf8Buffer < v9 )
  {
    do
    {
      Char_Advance0 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8Buffer);
      if ( !Char_Advance0 )
        --putf8Buffer;
      v12 = Char_Advance0;
      switch ( Char_Advance0 )
      {
        case '^':
          v20 = !v20;
          break;
        case '\\':
          if ( (unsigned int)putf8Buffer >= v21 )
            return 1;
          v13 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8Buffer);
          if ( !v13 )
            --putf8Buffer;
          v12 = v13;
LABEL_23:
          if ( v10 )
          {
            if ( v12 < v10 )
              v12 = v10;
          }
          else
          {
            v10 = v12;
          }
          if ( v20 )
          {
            v15 = this->pRestrict.pObject;
            if ( !v15->RestrictRanges.Ranges.Data.Size )
            {
              v19.Index = 0;
              v19.Data = 0;
              v19.Length = (unsigned int)&_sbh_sizeHeaderList;
              Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy>>::SetRange(
                &v15->RestrictRanges,
                &v19);
            }
            Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy>>::ClearRange(
              &this->pRestrict.pObject->RestrictRanges,
              v10,
              v12 - v10 + 1);
          }
          else
          {
            v14 = this->pRestrict.pObject;
            range.Index = v10;
            range.Length = v12 - v10 + 1;
            range.Data = 0;
            Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy>>::SetRange(
              &v14->RestrictRanges,
              &range);
          }
          v6 = v12;
          v10 = 0;
          break;
        case '-':
          v10 = v6;
          break;
        default:
          goto LABEL_23;
      }
    }
    while ( (unsigned int)putf8Buffer < v21 );
  }
  return 1;
}
