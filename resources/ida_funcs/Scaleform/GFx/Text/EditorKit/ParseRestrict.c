char __thiscall Scaleform::GFx::Text::EditorKit::ParseRestrict(
        Scaleform::GFx::Text::EditorKit *this,
        const char *restrStr,
        const char *restrStrLen)
{
  Scaleform::StringLH *v4; // eax
  Scaleform::GFx::Text::EditorKit::RestrictParams *v5; // esi
  unsigned int v6; // ebp
  Scaleform::GFx::Text::EditorKit::RestrictParams *pObject; // ecx
  const char *v9; // ecx
  unsigned int v10; // esi
  unsigned int v11; // eax
  unsigned int v12; // edi
  unsigned int v13; // eax
  Scaleform::GFx::Text::EditorKit::RestrictParams *v14; // ecx
  Scaleform::GFx::Text::EditorKit::RestrictParams *v15; // ecx
  const char *pstr; // [esp+Ch] [ebp-20h] BYREF
  int v17; // [esp+10h] [ebp-1Ch] BYREF
  Scaleform::RangeData<void *> range; // [esp+14h] [ebp-18h] BYREF
  Scaleform::RangeData<void *> v19; // [esp+20h] [ebp-Ch] BYREF
  bool negative; // [esp+30h] [ebp+4h]
  const char *pestr; // [esp+34h] [ebp+8h]

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
  v9 = &restrStrLen[(_DWORD)restrStr];
  v10 = 0;
  pstr = restrStr;
  negative = 0;
  pestr = v9;
  while ( pstr < pestr )
  {
    v11 = Scaleform::UTF8Util::DecodeNextChar_Advance0(&pstr);
    if ( !v11 )
      --pstr;
    v12 = v11;
    switch ( v11 )
    {
      case '^':
        negative = !negative;
        break;
      case '\\':
        if ( pstr >= pestr )
          return 1;
        v13 = Scaleform::UTF8Util::DecodeNextChar_Advance0(&pstr);
        if ( !v13 )
          --pstr;
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
        if ( negative )
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
  return 1;
}
