void __thiscall Scaleform::GFx::AS3::Instances::fl_text::TextFormat::SetTextFormat(
        Scaleform::GFx::AS3::Instances::fl_text::TextFormat *this,
        Scaleform::Render::Text::ParagraphFormat *parafmt,
        signed int fmt)
{
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // ebp
  __int16 v5; // bx
  Scaleform::GFx::AS3::Value *Null; // eax
  Scaleform::Render::Text::ParagraphFormat *v7; // esi
  bool v8; // zf
  __m128i *v9; // edx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::Value::V1U v11; // edx
  Scaleform::GFx::AS3::Value *p_other; // eax
  Scaleform::Render::Text::TextFormat *v13; // esi
  Scaleform::GFx::AS3::Value *p_n; // eax
  Scaleform::GFx::AS3::Value *v15; // eax
  Scaleform::GFx::AS3::Value *v16; // eax
  Scaleform::GFx::AS3::Value *v17; // eax
  Scaleform::GFx::AS3::Value *v18; // eax
  Scaleform::StringDH *FontList; // eax
  Scaleform::GFx::ASString *p_fmt; // eax
  Scaleform::GFx::ASStringNode *v21; // eax
  Scaleform::GFx::AS3::Value *v22; // eax
  Scaleform::GFx::AS3::Value *v23; // eax
  Scaleform::GFx::AS3::Value *v24; // eax
  Scaleform::GFx::AS3::Value *v25; // eax
  Scaleform::GFx::AS3::Value *v26; // eax
  Scaleform::GFx::AS3::Value *v27; // eax
  Scaleform::GFx::AS3::Value *v28; // eax
  Scaleform::String *p_Url; // esi
  Scaleform::GFx::ASString *p_NullString; // eax
  Scaleform::GFx::ASStringNode *v31; // eax
  unsigned int v32; // esi
  unsigned int *TabStops; // ebp
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> *Array; // eax
  Scaleform::GFx::AS3::Instances::fl::Array *pV; // ebx
  long double v36; // st7
  Scaleform::GFx::AS3::Instances::fl_text::TextFormat *v37; // edx
  Scaleform::GFx::AS3::Instances::fl::Array *pObject; // ecx
  unsigned int RefCount; // eax
  unsigned int v40; // eax
  Scaleform::GFx::AS3::Instances::fl::Array *v41; // ecx
  unsigned int v42; // eax
  Scaleform::GFx::ASStringNode *v43; // eax
  Scaleform::GFx::ASString NullString; // [esp+10h] [ebp-40h] BYREF
  Scaleform::GFx::AS3::Instances::fl_text::TextFormat *v45; // [esp+14h] [ebp-3Ch]
  Scaleform::GFx::ASString v; // [esp+18h] [ebp-38h] BYREF
  Scaleform::GFx::AS3::StringManager *sm; // [esp+1Ch] [ebp-34h]
  Scaleform::GFx::AS3::Value n; // [esp+20h] [ebp-30h] BYREF
  Scaleform::GFx::AS3::Value other; // [esp+30h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::Value r; // [esp+40h] [ebp-10h] BYREF

  StringManagerRef = this->pTraits.pObject->pVM->StringManagerRef;
  v5 = 0;
  NullString.pNode = &StringManagerRef->pStringManager->NullStringNode;
  ++NullString.pNode->RefCount;
  v45 = this;
  sm = StringManagerRef;
  Null = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Value::GetNull();
  n = *Null;
  if ( (Null->Flags & 0x1F) > 9 )
  {
    if ( (Null->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(Null);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(Null);
  }
  v7 = parafmt;
  v8 = (parafmt->PresentMask & 1) == 0;
  r.Flags = 0;
  r.Bonus.pWeakProxy = 0;
  if ( v8 )
  {
    Scaleform::GFx::AS3::Value::Assign(&this->mAlign, &NullString);
  }
  else
  {
    v9 = (__m128i *)"left";
    switch ( (parafmt->PresentMask >> 9) & 3 )
    {
      case 1:
        v9 = (__m128i *)"right";
        break;
      case 2:
        v9 = (__m128i *)"justify";
        break;
      case 3:
        v9 = (__m128i *)"center";
        break;
    }
    v.pNode = Scaleform::GFx::ASStringManager::CreateStringNode(StringManagerRef->pStringManager, v9);
    ++v.pNode->RefCount;
    Scaleform::GFx::AS3::Value::Assign(&this->mAlign, &v);
    pNode = v.pNode;
    --v.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  if ( (v7->PresentMask & 2) != 0 )
  {
    v11.VInt = v7->BlockIndent;
    v5 = 1;
    other.Flags = 3;
    other.Bonus.pWeakProxy = 0;
    other.value.VS._1 = v11;
    p_other = &other;
  }
  else
  {
    p_other = &n;
  }
  Scaleform::GFx::AS3::Value::Assign(&this->mBlockIndent, p_other);
  if ( (v5 & 1) != 0 )
  {
    v5 &= ~1u;
    if ( (other.Flags & 0x1F) > 9 )
    {
      if ( (other.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&other);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
    }
  }
  v13 = (Scaleform::Render::Text::TextFormat *)fmt;
  if ( (*(_BYTE *)(fmt + 38) & 0x10) != 0 )
  {
    v5 |= 2u;
    other.value.VS._1.VBool = *(_BYTE *)(fmt + 36) & 1;
    other.Flags = 1;
    other.Bonus.pWeakProxy = 0;
    p_n = &other;
  }
  else
  {
    p_n = &n;
  }
  Scaleform::GFx::AS3::Value::Assign(&this->mBold, p_n);
  if ( (v5 & 2) != 0 )
  {
    v5 &= ~2u;
    if ( (other.Flags & 0x1F) > 9 )
    {
      if ( (other.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&other);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
    }
  }
  if ( (v13->PresentMask & 0x20) != 0 )
  {
    v5 |= 4u;
    other.value.VS._1.VBool = (v13->FormatFlags & 2) != 0;
    other.Flags = 1;
    other.Bonus.pWeakProxy = 0;
    v15 = &other;
  }
  else
  {
    v15 = &n;
  }
  Scaleform::GFx::AS3::Value::Assign(&this->mItalic, v15);
  if ( (v5 & 4) != 0 )
  {
    v5 &= ~4u;
    if ( (other.Flags & 0x1F) > 9 )
    {
      if ( (other.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&other);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
    }
  }
  if ( (v13->PresentMask & 0x40) != 0 )
  {
    v5 |= 8u;
    other.value.VS._1.VBool = (v13->FormatFlags & 4) != 0;
    other.Flags = 1;
    other.Bonus.pWeakProxy = 0;
    v16 = &other;
  }
  else
  {
    v16 = &n;
  }
  Scaleform::GFx::AS3::Value::Assign(&this->mUnderline, v16);
  if ( (v5 & 8) != 0 )
  {
    v5 &= ~8u;
    if ( (other.Flags & 0x1F) > 9 )
    {
      if ( (other.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&other);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
    }
  }
  if ( (parafmt->PresentMask & 0x80u) == 0 )
  {
    v17 = &n;
  }
  else
  {
    v5 |= 0x10u;
    other.value.VS._1.VBool = (parafmt->PresentMask & 0x8000) != 0;
    other.Flags = 1;
    other.Bonus.pWeakProxy = 0;
    v17 = &other;
  }
  Scaleform::GFx::AS3::Value::Assign(&this->mBullet, v17);
  if ( (v5 & 0x10) != 0 )
  {
    v5 &= ~0x10u;
    if ( (other.Flags & 0x1F) > 9 )
    {
      if ( (other.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&other);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
    }
  }
  if ( (v13->PresentMask & 1) != 0 )
  {
    v5 |= 0x20u;
    fmt = v13->ColorV & 0xFFFFFF;
    other.Flags = 4;
    other.Bonus.pWeakProxy = 0;
    other.value.VNumber = (double)fmt;
    v18 = &other;
  }
  else
  {
    v18 = &n;
  }
  Scaleform::GFx::AS3::Value::Assign(&this->mColor, v18);
  if ( (v5 & 0x20) != 0 )
  {
    v5 &= ~0x20u;
    if ( (other.Flags & 0x1F) > 9 )
    {
      if ( (other.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&other);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
    }
  }
  if ( (v13->PresentMask & 4) != 0 )
  {
    v5 |= 0x40u;
    FontList = Scaleform::Render::Text::TextFormat::GetFontList(v13);
    *(float *)&fmt = COERCE_FLOAT(
                       Scaleform::GFx::ASStringManager::CreateStringNode(
                         sm->pStringManager,
                         (__m128i *)((FontList->HeapTypeBits & 0xFFFFFFFC) + 8),
                         *(_DWORD *)(FontList->HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF));
    ++*(_DWORD *)(fmt + 12);
    p_fmt = (Scaleform::GFx::ASString *)&fmt;
  }
  else
  {
    p_fmt = &NullString;
  }
  Scaleform::GFx::AS3::Value::Assign(&this->mFont, p_fmt);
  if ( (v5 & 0x40) != 0 )
  {
    v21 = (Scaleform::GFx::ASStringNode *)fmt;
    --*(_DWORD *)(fmt + 12);
    v5 &= ~0x40u;
    if ( !v21->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v21);
  }
  if ( (parafmt->PresentMask & 4) != 0 )
  {
    fmt = parafmt->Indent;
    v5 |= 0x80u;
    other.Flags = 4;
    other.Bonus.pWeakProxy = 0;
    v22 = &other;
    other.value.VNumber = (double)fmt;
  }
  else
  {
    v22 = &n;
  }
  Scaleform::GFx::AS3::Value::Assign(&this->mIndent, v22);
  if ( (v5 & 0x80u) != 0 )
  {
    v5 &= ~0x80u;
    if ( (other.Flags & 0x1F) > 9 )
    {
      if ( (other.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&other);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
    }
  }
  if ( SLOBYTE(v13->PresentMask) >= 0 )
  {
    v23 = &n;
  }
  else
  {
    v5 |= 0x100u;
    other.value.VS._1.VBool = (v13->FormatFlags & 8) != 0;
    other.Flags = 1;
    other.Bonus.pWeakProxy = 0;
    v23 = &other;
  }
  Scaleform::GFx::AS3::Value::Assign(&this->mKerning, v23);
  if ( (v5 & 0x100) != 0 )
  {
    v5 &= ~0x100u;
    if ( (other.Flags & 0x1F) > 9 )
    {
      if ( (other.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&other);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
    }
  }
  if ( (parafmt->PresentMask & 8) != 0 )
  {
    fmt = parafmt->Leading;
    v5 |= 0x200u;
    other.Flags = 4;
    other.Bonus.pWeakProxy = 0;
    v24 = &other;
    other.value.VNumber = (double)fmt;
  }
  else
  {
    v24 = &n;
  }
  Scaleform::GFx::AS3::Value::Assign(&this->mLeading, v24);
  if ( (v5 & 0x200) != 0 )
  {
    v5 &= ~0x200u;
    if ( (other.Flags & 0x1F) > 9 )
    {
      if ( (other.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&other);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
    }
  }
  if ( (parafmt->PresentMask & 0x10) != 0 )
  {
    fmt = parafmt->LeftMargin;
    v5 |= 0x400u;
    other.Flags = 4;
    other.Bonus.pWeakProxy = 0;
    v25 = &other;
    other.value.VNumber = (double)fmt;
  }
  else
  {
    v25 = &n;
  }
  Scaleform::GFx::AS3::Value::Assign(&this->mLeftMargin, v25);
  if ( (v5 & 0x400) != 0 )
  {
    v5 &= ~0x400u;
    if ( (other.Flags & 0x1F) > 9 )
    {
      if ( (other.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&other);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
    }
  }
  if ( (v13->PresentMask & 2) != 0 )
  {
    v5 |= 0x800u;
    fmt = v13->LetterSpacing / 20;
    other.Flags = 4;
    other.Bonus.pWeakProxy = 0;
    v26 = &other;
    other.value.VNumber = (double)fmt;
  }
  else
  {
    v26 = &n;
  }
  Scaleform::GFx::AS3::Value::Assign(&this->mLetterSpacing, v26);
  if ( (v5 & 0x800) != 0 )
  {
    v5 &= ~0x800u;
    if ( (other.Flags & 0x1F) > 9 )
    {
      if ( (other.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&other);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
    }
  }
  if ( (parafmt->PresentMask & 0x20) != 0 )
  {
    fmt = parafmt->RightMargin;
    v5 |= 0x1000u;
    other.Flags = 4;
    other.Bonus.pWeakProxy = 0;
    v27 = &other;
    other.value.VNumber = (double)fmt;
  }
  else
  {
    v27 = &n;
  }
  Scaleform::GFx::AS3::Value::Assign(&this->mRightMargin, v27);
  if ( (v5 & 0x1000) != 0 )
  {
    v5 &= ~0x1000u;
    if ( (other.Flags & 0x1F) > 9 )
    {
      if ( (other.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&other);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
    }
  }
  if ( (v13->PresentMask & 8) != 0 )
  {
    fmt = v13->FontSize;
    v5 |= 0x2000u;
    other.Flags = 4;
    other.Bonus.pWeakProxy = 0;
    v28 = &other;
    *(float *)&fmt = (double)fmt * 0.05000000074505806;
    other.value.VNumber = *(float *)&fmt;
  }
  else
  {
    v28 = &n;
  }
  Scaleform::GFx::AS3::Value::Assign(&this->mSize, v28);
  if ( (v5 & 0x2000) != 0 )
  {
    v5 &= ~0x2000u;
    if ( (other.Flags & 0x1F) > 9 )
    {
      if ( (other.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&other);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
    }
  }
  Scaleform::GFx::AS3::Value::Assign(&this->mTarget, &NullString);
  if ( (v13->PresentMask & 0x100) != 0 && (p_Url = &v13->Url, Scaleform::String::GetLength(p_Url)) )
  {
    v5 |= 0x4000u;
    *(float *)&fmt = COERCE_FLOAT(
                       Scaleform::GFx::ASStringManager::CreateStringNode(
                         sm->pStringManager,
                         (__m128i *)((p_Url->HeapTypeBits & 0xFFFFFFFC) + 8),
                         *(_DWORD *)(p_Url->HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF));
    ++*(_DWORD *)(fmt + 12);
    p_NullString = (Scaleform::GFx::ASString *)&fmt;
  }
  else
  {
    p_NullString = &NullString;
  }
  Scaleform::GFx::AS3::Value::Assign(&this->mUrl, p_NullString);
  if ( (v5 & 0x4000) != 0 )
  {
    v31 = (Scaleform::GFx::ASStringNode *)fmt;
    --*(_DWORD *)(fmt + 12);
    if ( !v31->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v31);
  }
  if ( (parafmt->PresentMask & 0x40) != 0 )
  {
    v32 = 0;
    *(float *)&fmt = 0.0;
    TabStops = Scaleform::Render::Text::ParagraphFormat::GetTabStops(parafmt, (unsigned int *)&fmt);
    Array = Scaleform::GFx::AS3::VM::MakeArray(
              this->pTraits.pObject->pVM,
              (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> *)&parafmt);
    pV = Array->pV;
    Scaleform::GFx::AS3::Impl::SparseArray::Resize(&Array->pV->SA, fmt);
    if ( *(float *)&fmt != 0.0 )
    {
      do
      {
        v36 = (double)TabStops[v32];
        other.Flags = 4;
        other.Bonus.pWeakProxy = 0;
        other.value.VNumber = v36;
        Scaleform::GFx::AS3::Impl::SparseArray::Set(&pV->SA, v32, &other);
        if ( (other.Flags & 0x1F) > 9 )
        {
          if ( (other.Flags & 0x200) != 0 )
            Scaleform::GFx::AS3::Value::ReleaseWeakRef(&other);
          else
            Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
        }
        ++v32;
      }
      while ( v32 < fmt );
    }
    v37 = v45;
    if ( pV != v45->mTabStops.pObject )
    {
      if ( pV )
        pV->RefCount = (pV->RefCount + 1) & 0x8FBFFFFF;
      pObject = v37->mTabStops.pObject;
      if ( pObject )
      {
        if ( ((unsigned __int8)pObject & 1) != 0 )
        {
          v37->mTabStops.pObject = (Scaleform::GFx::AS3::Instances::fl::Array *)((char *)pObject - 1);
        }
        else
        {
          RefCount = pObject->RefCount;
          if ( (RefCount & 0x3FFFFF) != 0 )
          {
            pObject->RefCount = RefCount - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
            v37 = v45;
          }
        }
      }
      v37->mTabStops.pObject = pV;
    }
    if ( pV )
    {
      if ( ((unsigned __int8)pV & 1) == 0 )
      {
        v40 = pV->RefCount;
        if ( (v40 & 0x3FFFFF) != 0 )
        {
          pV->RefCount = v40 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pV);
        }
      }
    }
  }
  else
  {
    v41 = this->mTabStops.pObject;
    if ( v41 )
    {
      if ( ((unsigned __int8)v41 & 1) != 0 )
      {
        this->mTabStops.pObject = (Scaleform::GFx::AS3::Instances::fl::Array *)((char *)v41 - 1);
      }
      else
      {
        v42 = v41->RefCount;
        if ( (v42 & 0x3FFFFF) != 0 )
        {
          v41->RefCount = v42 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v41);
        }
      }
      this->mTabStops.pObject = 0;
    }
  }
  if ( (r.Flags & 0x1F) > 9 )
  {
    if ( (r.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&r);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&r);
  }
  if ( (n.Flags & 0x1F) > 9 )
  {
    if ( (n.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&n);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&n);
  }
  v43 = NullString.pNode;
  --NullString.pNode->RefCount;
  if ( !v43->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v43);
}
