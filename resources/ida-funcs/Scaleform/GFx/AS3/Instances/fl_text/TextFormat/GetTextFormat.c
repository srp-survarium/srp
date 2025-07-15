void __thiscall Scaleform::GFx::AS3::Instances::fl_text::TextFormat::GetTextFormat(
        Scaleform::GFx::AS3::Instances::fl_text::TextFormat *this,
        signed int parafmt,
        Scaleform::Render::Text::TextFormat *fmt)
{
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // edx
  unsigned int v5; // eax
  Scaleform::Render::Text::ParagraphFormat *v6; // ebp
  Scaleform::GFx::AS3::Value *p_mAlign; // ecx
  Scaleform::GFx::ASStringManager *pStringManager; // eax
  Scaleform::GFx::ASStringNode *v9; // edi
  __int16 v10; // ax
  bool v11; // al
  Scaleform::Render::Text::TextFormat *v12; // esi
  bool v13; // al
  bool v14; // al
  Scaleform::GFx::ASStringNode *v15; // eax
  __int16 v16; // ax
  __int16 v17; // ax
  __int16 v18; // ax
  __int16 v19; // ax
  Scaleform::GFx::ASStringNode *v20; // eax
  double v21; // st7
  int v22; // eax
  bool v23; // al
  Scaleform::GFx::AS3::Instances::fl::Array *pObject; // eax
  unsigned int Length; // edi
  unsigned int i; // esi
  Scaleform::GFx::AS3::Value *v27; // eax
  float fontSize; // [esp+0h] [ebp-24h]
  long double v; // [esp+14h] [ebp-10h] BYREF
  double sm; // [esp+1Ch] [ebp-8h] BYREF

  StringManagerRef = this->pTraits.pObject->pVM->StringManagerRef;
  v5 = this->mAlign.Flags & 0x1F;
  v6 = (Scaleform::Render::Text::ParagraphFormat *)parafmt;
  p_mAlign = &this->mAlign;
  LODWORD(sm) = StringManagerRef;
  if ( v5 && (v5 - 12 > 3 || p_mAlign->value.VS._1.VInt) )
  {
    pStringManager = StringManagerRef->pStringManager;
    LODWORD(v) = &pStringManager->EmptyStringNode;
    ++pStringManager->EmptyStringNode.RefCount;
    Scaleform::GFx::AS3::Value::Convert2String(
      p_mAlign,
      (Scaleform::GFx::AS3::CheckResult *)&parafmt,
      (Scaleform::GFx::ASString *)&v);
    v9 = (Scaleform::GFx::ASStringNode *)LODWORD(v);
    if ( !strcmp(*(const char **)LODWORD(v), "left") )
    {
      v6->PresentMask = v6->PresentMask & 0xF9FE | 1;
    }
    else if ( !strcmp(*(const char **)LODWORD(v), "right") )
    {
      v6->PresentMask = v6->PresentMask & 0xF9FE | 0x201;
    }
    else if ( Scaleform::GFx::ASString::operator==((Scaleform::GFx::ASString *)&v, "center") )
    {
      v6->PresentMask |= 0x601u;
    }
    else if ( Scaleform::GFx::ASString::operator==((Scaleform::GFx::ASString *)&v, "justify") )
    {
      Scaleform::Render::Text::ParagraphFormat::SetAlignment(v6, Align_Left);
    }
    else
    {
      v6->PresentMask &= 0xF9FEu;
    }
    if ( !--v9->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v9);
  }
  if ( (this->mBlockIndent.Flags & 0x1F) != 0
    && ((this->mBlockIndent.Flags & 0x1F) - 12 > 3 || this->mBlockIndent.value.VS._1.VInt) )
  {
    Scaleform::GFx::AS3::Value::Convert2Int32(
      &this->mBlockIndent,
      (Scaleform::GFx::AS3::CheckResult *)&parafmt,
      (int *)&v);
    v10 = LOWORD(v);
    if ( SLODWORD(v) >= 0 )
    {
      if ( SLODWORD(v) > 720 )
        v10 = 720;
      v6->PresentMask |= 2u;
      v6->BlockIndent = v10;
    }
    else
    {
      v6->PresentMask |= 2u;
      v6->BlockIndent = 0;
    }
  }
  else
  {
    v6->PresentMask &= ~2u;
    v6->BlockIndent = 0;
  }
  if ( (this->mBold.Flags & 0x1F) != 0 && ((this->mBold.Flags & 0x1F) - 12 > 3 || this->mBold.value.VS._1.VInt) )
  {
    v11 = Scaleform::GFx::AS3::Value::Convert2Boolean(&this->mBold);
    v12 = fmt;
    Scaleform::Render::Text::TextFormat::SetBold(fmt, v11);
  }
  else
  {
    v12 = fmt;
    fmt->FormatFlags &= ~1u;
    v12->PresentMask &= ~0x10u;
  }
  if ( (this->mItalic.Flags & 0x1F) != 0 && ((this->mItalic.Flags & 0x1F) - 12 > 3 || this->mItalic.value.VS._1.VInt) )
  {
    v13 = Scaleform::GFx::AS3::Value::Convert2Boolean(&this->mItalic);
    Scaleform::Render::Text::TextFormat::SetItalic(v12, v13);
  }
  else
  {
    v12->FormatFlags &= ~2u;
    v12->PresentMask &= ~0x20u;
  }
  if ( (this->mUnderline.Flags & 0x1F) != 0
    && ((this->mUnderline.Flags & 0x1F) - 12 > 3 || this->mUnderline.value.VS._1.VInt) )
  {
    v14 = Scaleform::GFx::AS3::Value::Convert2Boolean(&this->mUnderline);
    Scaleform::Render::Text::TextFormat::SetUnderline(v12, v14);
  }
  else
  {
    v12->FormatFlags &= ~4u;
    v12->PresentMask &= ~0x40u;
  }
  if ( (this->mBullet.Flags & 0x1F) != 0 && ((this->mBullet.Flags & 0x1F) - 12 > 3 || this->mBullet.value.VS._1.VInt) )
  {
    if ( Scaleform::GFx::AS3::Value::Convert2Boolean(&this->mBullet) )
      v6->PresentMask |= 0x8000u;
    else
      v6->PresentMask &= ~0x8000u;
    v6->PresentMask |= 0x80u;
  }
  else
  {
    v6->PresentMask &= 0x7F7Fu;
  }
  if ( (this->mColor.Flags & 0x1F) != 0 && ((this->mColor.Flags & 0x1F) - 12 > 3 || this->mColor.value.VS._1.VInt) )
  {
    Scaleform::GFx::AS3::Value::Convert2UInt32(
      &this->mColor,
      (Scaleform::GFx::AS3::CheckResult *)&fmt,
      (unsigned int *)&parafmt);
    v12->ColorV ^= (parafmt ^ v12->ColorV) & 0xFFFFFF;
    v12->PresentMask |= 1u;
  }
  else
  {
    v12->PresentMask &= ~1u;
    v12->ColorV = -16777216;
  }
  if ( (this->mFont.Flags & 0x1F) != 0 && ((this->mFont.Flags & 0x1F) - 12 > 3 || this->mFont.value.VS._1.VInt) )
  {
    parafmt = *(_DWORD *)(LODWORD(sm) + 248) + 32;
    ++*(_DWORD *)(parafmt + 12);
    Scaleform::GFx::AS3::Value::Convert2String(
      &this->mFont,
      (Scaleform::GFx::AS3::CheckResult *)&fmt,
      (Scaleform::GFx::ASString *)&parafmt);
    Scaleform::Render::Text::TextFormat::SetFontList(v12, *(const __m128i **)parafmt, 0xFFFFFFFF);
    v15 = (Scaleform::GFx::ASStringNode *)parafmt;
    --*(_DWORD *)(parafmt + 12);
    if ( !v15->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v15);
  }
  else
  {
    v12->PresentMask &= 0xEFFBu;
  }
  if ( (this->mIndent.Flags & 0x1F) != 0 && ((this->mIndent.Flags & 0x1F) - 12 > 3 || this->mIndent.value.VS._1.VInt) )
  {
    Scaleform::GFx::AS3::Value::Convert2Int32(&this->mIndent, (Scaleform::GFx::AS3::CheckResult *)&fmt, &parafmt);
    v16 = parafmt;
    if ( parafmt >= -720 )
    {
      if ( parafmt > 720 )
        v16 = 720;
      v6->PresentMask |= 4u;
      v6->Indent = v16;
    }
    else
    {
      v6->PresentMask |= 4u;
      v6->Indent = -720;
    }
  }
  else
  {
    v6->PresentMask &= ~4u;
    v6->Indent = 0;
  }
  if ( (this->mLeading.Flags & 0x1F) != 0 && ((this->mLeading.Flags & 0x1F) - 12 > 3 || this->mLeading.value.VS._1.VInt) )
  {
    Scaleform::GFx::AS3::Value::Convert2Int32(&this->mLeading, (Scaleform::GFx::AS3::CheckResult *)&fmt, &parafmt);
    v17 = parafmt;
    if ( parafmt >= -720 )
    {
      if ( parafmt > 720 )
        v17 = 720;
      v6->PresentMask |= 8u;
    }
    else
    {
      v6->PresentMask |= 8u;
      v17 = -720;
    }
  }
  else
  {
    v17 = 0;
    v6->PresentMask &= ~8u;
  }
  v6->Leading = v17;
  if ( (this->mLeftMargin.Flags & 0x1F) != 0
    && ((this->mLeftMargin.Flags & 0x1F) - 12 > 3 || this->mLeftMargin.value.VS._1.VInt) )
  {
    Scaleform::GFx::AS3::Value::Convert2Int32(&this->mLeftMargin, (Scaleform::GFx::AS3::CheckResult *)&fmt, &parafmt);
    v18 = parafmt;
    if ( parafmt >= 0 )
    {
      if ( parafmt > 720 )
        v18 = 720;
      v6->PresentMask |= 0x10u;
      v6->LeftMargin = v18;
    }
    else
    {
      v6->PresentMask |= 0x10u;
      v6->LeftMargin = 0;
    }
  }
  else
  {
    v6->PresentMask &= ~0x10u;
    v6->LeftMargin = 0;
  }
  if ( (this->mRightMargin.Flags & 0x1F) != 0
    && ((this->mRightMargin.Flags & 0x1F) - 12 > 3 || this->mRightMargin.value.VS._1.VInt) )
  {
    Scaleform::GFx::AS3::Value::Convert2Int32(&this->mRightMargin, (Scaleform::GFx::AS3::CheckResult *)&fmt, &parafmt);
    v19 = parafmt;
    if ( parafmt >= 0 )
    {
      if ( parafmt > 720 )
        v19 = 720;
      v6->PresentMask |= 0x20u;
    }
    else
    {
      v19 = 0;
      v6->PresentMask |= 0x20u;
    }
  }
  else
  {
    v19 = 0;
    v6->PresentMask &= ~0x20u;
  }
  v6->RightMargin = v19;
  if ( (this->mSize.Flags & 0x1F) != 0 && ((this->mSize.Flags & 0x1F) - 12 > 3 || this->mSize.value.VS._1.VInt) )
  {
    Scaleform::GFx::AS3::Value::Convert2Int32(&this->mSize, (Scaleform::GFx::AS3::CheckResult *)&fmt, &parafmt);
    if ( parafmt >= 0 )
    {
      if ( parafmt >= 128 )
      {
        Scaleform::Render::Text::TextFormat::SetFontSize(v12, 127.0);
      }
      else
      {
        fmt = (Scaleform::Render::Text::TextFormat *)parafmt;
        fontSize = (float)(unsigned int)parafmt;
        Scaleform::Render::Text::TextFormat::SetFontSize(v12, fontSize);
      }
    }
  }
  else
  {
    v12->PresentMask &= ~8u;
    v12->FontSize = 0;
  }
  if ( (this->mUrl.Flags & 0x1F) != 0 && ((this->mUrl.Flags & 0x1F) - 12 > 3 || this->mUrl.value.VS._1.VInt) )
  {
    parafmt = *(_DWORD *)(LODWORD(sm) + 248) + 32;
    ++*(_DWORD *)(parafmt + 12);
    Scaleform::GFx::AS3::Value::Convert2String(
      &this->mUrl,
      (Scaleform::GFx::AS3::CheckResult *)&fmt,
      (Scaleform::GFx::ASString *)&parafmt);
    Scaleform::Render::Text::TextFormat::SetUrl(v12, *(const __m128i **)parafmt, 0xFFFFFFFF);
    v20 = (Scaleform::GFx::ASStringNode *)parafmt;
    --*(_DWORD *)(parafmt + 12);
    if ( !v20->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v20);
  }
  else
  {
    Scaleform::String::Clear(&v12->Url);
    v12->PresentMask &= ~0x100u;
  }
  if ( (this->mLetterSpacing.Flags & 0x1F) != 0
    && ((this->mLetterSpacing.Flags & 0x1F) - 12 > 3 || this->mLetterSpacing.value.VS._1.VInt) )
  {
    Scaleform::GFx::AS3::Value::Convert2Number(&this->mLetterSpacing, (Scaleform::GFx::AS3::CheckResult *)&fmt, &sm);
    v21 = -720.0;
    if ( sm >= -720.0 )
    {
      v21 = sm;
      if ( sm > 720.0 )
        v21 = 720.0;
    }
    *(float *)&fmt = v21;
    v22 = (int)(*(float *)&fmt * 20.0);
    v12->PresentMask |= 2u;
    v12->LetterSpacing = v22;
  }
  else
  {
    v12->PresentMask &= ~2u;
    v12->LetterSpacing = 0;
  }
  if ( (this->mKerning.Flags & 0x1F) != 0 && ((this->mKerning.Flags & 0x1F) - 12 > 3 || this->mKerning.value.VS._1.VInt) )
  {
    v23 = Scaleform::GFx::AS3::Value::Convert2Boolean(&this->mKerning);
    Scaleform::Render::Text::TextFormat::SetKerning(v12, v23);
  }
  else
  {
    v12->FormatFlags &= ~8u;
    v12->PresentMask &= ~0x80u;
  }
  pObject = this->mTabStops.pObject;
  if ( pObject )
  {
    Length = pObject->SA.Length;
    Scaleform::Render::Text::ParagraphFormat::AllocTabStops(v6, Length);
    v6->PresentMask |= 0x40u;
    for ( i = 0; i < Length; ++i )
    {
      v27 = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Impl::SparseArray::At(&this->mTabStops.pObject->SA, i);
      Scaleform::GFx::AS3::Value::Convert2Number(v27, (Scaleform::GFx::AS3::CheckResult *)&fmt, &v);
      *(_QWORD *)&sm = (__int64)v;
      Scaleform::Render::Text::ParagraphFormat::SetTabStopsElement(v6, i, (__int64)v);
    }
  }
  else
  {
    Scaleform::Render::Text::ParagraphFormat::FreeTabStops(v6);
    v6->PresentMask &= ~0x40u;
  }
}
