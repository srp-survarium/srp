void __thiscall Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy>>::ClearRange(
        Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> > *this,
        int startPos,
        signed int length)
{
  unsigned int Size; // edi
  int NearestRangeIndex; // eax
  int v6; // edi
  int v7; // ebx
  Scaleform::RangeData<void *> *v8; // ecx
  signed int v9; // eax
  signed int v10; // edx
  int Index; // edx
  unsigned int v12; // eax
  signed int v13; // eax
  signed int v14; // eax
  bool v15; // cc
  unsigned int v16; // edx
  int v17; // ebx
  int v18; // ecx
  signed int v19; // edx
  unsigned int v20; // eax
  Scaleform::RangeData<void *> *v21; // eax
  int v22; // ecx
  signed int v23; // edi
  signed int v24; // ebp
  Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> >,2,Scaleform::ArrayDefaultPolicy> >::Iterator v25; // [esp+8h] [ebp-14h] BYREF
  Scaleform::RangeData<void *> val; // [esp+10h] [ebp-Ch] BYREF

  Size = this->Ranges.Data.Size;
  if ( !Size )
    return;
  NearestRangeIndex = Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2,Scaleform::ArrayDefaultPolicy>>::FindNearestRangeIndex(
                        (Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> >,2,Scaleform::ArrayDefaultPolicy> > *)this,
                        startPos);
  v25.pArray = (Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> >,2,Scaleform::ArrayDefaultPolicy> > *)this;
  if ( NearestRangeIndex >= 0 )
  {
    if ( NearestRangeIndex < Size )
      v6 = NearestRangeIndex;
    else
      v6 = Size - 1;
  }
  else
  {
    v6 = 0;
  }
  v25.Index = v6;
  if ( length == -1 )
    length = 0x7FFFFFFF - startPos;
  v7 = v6;
  v8 = &this->Ranges.Data.Data[v6];
  if ( startPos < v8->Index || startPos + length - 1 > (signed int)(v8->Length + v8->Index - 1) )
  {
    if ( startPos < v8->Index || (v16 = v8->Length, startPos > (int)(v16 + v8->Index - 1)) )
    {
      Scaleform::Range::CompareTo(v8, startPos);
LABEL_33:
      v15 = v6 < (signed int)this->Ranges.Data.Size;
LABEL_34:
      if ( v15 )
        v25.Index = ++v6;
      goto LABEL_36;
    }
    if ( v8->Index + v16 - startPos <= v16 )
      v8->Length = startPos - v8->Index;
    else
      v8->Length = 0;
  }
  else
  {
    if ( v8->Index == startPos )
    {
      v9 = v8->Length;
      v10 = v9;
      if ( length <= v9 )
        v10 = length;
      v8->Index += v10;
      v8->Length = v9 - v10;
      if ( !this->Ranges.Data.Data[v7].Length )
      {
        if ( v6 >= 0 && v6 < this->Ranges.Data.Size )
          Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::RangeData<void *>,Scaleform::AllocatorLH<Scaleform::RangeData<void *>,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
            &this->Ranges,
            v6);
        goto LABEL_36;
      }
      goto LABEL_33;
    }
    if ( (signed int)(v8->Index + v8->Length) > startPos + length )
    {
      Index = v8->Index;
      val.Length = v8->Length;
      v12 = v8->Index + val.Length - startPos;
      val.Index = Index;
      val.Data = v8->Data;
      Scaleform::Range::ShrinkRange(v8, v12);
      v13 = length + this->Ranges.Data.Data[v7].Length;
      if ( v13 > (int)val.Length )
        v13 = val.Length;
      val.Index += v13;
      v15 = v6 < (signed int)this->Ranges.Data.Size;
      val.Length -= v13;
      if ( v15 )
        v25.Index = ++v6;
      Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::RangeData<void *>,Scaleform::AllocatorLH<Scaleform::RangeData<void *>,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
        &this->Ranges,
        v6,
        &val);
      goto LABEL_33;
    }
    Scaleform::Range::ShrinkRange(v8, length);
  }
  v14 = this->Ranges.Data.Size;
  if ( v6 < v14 )
  {
    v25.Index = ++v6;
    v15 = v6 < v14;
    goto LABEL_34;
  }
LABEL_36:
  if ( !Scaleform::RangeDataArray<Scaleform::GFx::TextField::CSSHolderBase::UrlZone,Scaleform::Array<Scaleform::RangeData<Scaleform::GFx::TextField::CSSHolderBase::UrlZone>,2,Scaleform::ArrayDefaultPolicy>>::Iterator::IsFinished(&v25) )
  {
    v17 = v6;
    do
    {
      v18 = this->Ranges.Data.Data[v6].Index;
      if ( v18 < startPos )
        break;
      v19 = length;
      if ( (signed int)(this->Ranges.Data.Data[v17].Length + v18 - 1) > length + startPos - 1 )
        goto LABEL_47;
      if ( v6 >= 0 && v6 < this->Ranges.Data.Size )
      {
        v20 = this->Ranges.Data.Size;
        if ( v20 == 1 )
        {
          Scaleform::ArrayData<Scaleform::RangeData<void *>,Scaleform::AllocatorLH<Scaleform::RangeData<void *>,2>,Scaleform::ArrayDefaultPolicy>::Resize(
            &this->Ranges.Data,
            0);
        }
        else
        {
          memmove(
            (int)&this->Ranges.Data.Data[v17],
            (const __m128i *)&this->Ranges.Data.Data[v17 + 1],
            12 * (v20 - v6 - 1));
          --this->Ranges.Data.Size;
        }
      }
    }
    while ( !Scaleform::RangeDataArray<Scaleform::GFx::TextField::CSSHolderBase::UrlZone,Scaleform::Array<Scaleform::RangeData<Scaleform::GFx::TextField::CSSHolderBase::UrlZone>,2,Scaleform::ArrayDefaultPolicy>>::Iterator::IsFinished(&v25) );
  }
  v19 = length;
LABEL_47:
  if ( v6 >= 0 && v6 < this->Ranges.Data.Size )
  {
    v21 = &this->Ranges.Data.Data[v6];
    v22 = v19 + startPos - 1;
    if ( v22 >= v21->Index )
    {
      v23 = v21->Length;
      if ( v22 <= v23 + v21->Index - 1 )
      {
        v24 = v19 + startPos - v21->Index;
        if ( v24 > v23 )
          v24 = v21->Length;
        v21->Index += v24;
        v21->Length = v23 - v24;
      }
    }
  }
}
