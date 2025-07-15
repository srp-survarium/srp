char __thiscall Scaleform::GFx::AS2::TextFormatObject::SetMember(
        Scaleform::GFx::AS2::TextFormatObject *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val,
        const Scaleform::GFx::AS2::PropFlags *flags)
{
  Scaleform::GFx::ASStringNode *pNode; // edi
  bool v8; // zf
  unsigned __int8 Type; // al
  int v10; // esi
  unsigned __int8 v11; // al
  Scaleform::GFx::ASStringNode *v12; // esi
  __int16 v13; // dx
  int v14; // esi
  int v15; // esi
  int v16; // esi
  int v17; // esi
  int v18; // esi
  unsigned __int8 v19; // bl
  Scaleform::GFx::AS2::Object *v20; // eax
  Scaleform::GFx::AS2::ArrayObject *v21; // edi
  signed int v22; // esi
  long double v23; // st7
  Scaleform::GFx::AS2::Value *v24; // eax
  char v25; // bl
  int v26; // edi
  int v27; // esi
  float val_4; // [esp+4h] [ebp-5Ch]
  float val_4a; // [esp+4h] [ebp-5Ch]
  float val_4b; // [esp+4h] [ebp-5Ch]
  Scaleform::GFx::ASString v32; // [esp+18h] [ebp-48h] BYREF
  Scaleform::GFx::ASString str; // [esp+1Ch] [ebp-44h] BYREF
  Scaleform::GFx::ASString v34; // [esp+20h] [ebp-40h] BYREF
  unsigned int v35[2]; // [esp+24h] [ebp-3Ch]
  int Size; // [esp+2Ch] [ebp-34h]
  Scaleform::GFx::AS2::Value v37; // [esp+30h] [ebp-30h] BYREF
  Scaleform::GFx::AS2::Value v38; // [esp+40h] [ebp-20h] BYREF
  Scaleform::GFx::AS2::Value v39; // [esp+50h] [ebp-10h] BYREF
  bool vb; // [esp+6Ch] [ebp+Ch]
  bool vc; // [esp+6Ch] [ebp+Ch]
  unsigned int vd; // [esp+6Ch] [ebp+Ch]
  bool ve; // [esp+6Ch] [ebp+Ch]
  bool vf; // [esp+6Ch] [ebp+Ch]
  int v; // [esp+6Ch] [ebp+Ch]
  bool vg; // [esp+6Ch] [ebp+Ch]
  int va; // [esp+6Ch] [ebp+Ch]

  Scaleform::GFx::AS2::Value::Value(&v37, val);
  if ( !strcmp(name->pNode->pData, "align") )
  {
    Scaleform::GFx::AS2::Value::ToStringImpl(val, &v32, penv, -1, 0);
    pNode = v32.pNode;
    if ( !strcmp(v32.pNode->pData, "left") )
    {
      HIWORD(this->mParagraphFormat.RefCount) = HIWORD(this->mParagraphFormat.RefCount) & 0xF9FE | 1;
    }
    else if ( !strcmp(v32.pNode->pData, "right") )
    {
      HIWORD(this->mParagraphFormat.RefCount) = HIWORD(this->mParagraphFormat.RefCount) & 0xF9FE | 0x201;
    }
    else if ( Scaleform::GFx::ASString::operator==(&v32, "center") )
    {
      HIWORD(this->mParagraphFormat.RefCount) |= 0x601u;
    }
    else if ( Scaleform::GFx::ASString::operator==(&v32, "justify") )
    {
      Scaleform::Render::Text::ParagraphFormat::SetAlignment(
        (Scaleform::Render::Text::ParagraphFormat *)&this->mTextFormat.pFontHandle,
        Align_Left);
    }
    else
    {
      HIWORD(this->mParagraphFormat.RefCount) &= 0xF9FEu;
      Scaleform::GFx::AS2::Value::DropRefs(&v37);
      v37.T.Type = 1;
    }
    v8 = pNode->RefCount-- == 1;
    if ( v8 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    goto LABEL_147;
  }
  if ( !strcmp(name->pNode->pData, "blockIndent") )
  {
    Type = val->T.Type;
    if ( val->T.Type != 1 && Type && Type != 10 )
    {
      v10 = Scaleform::GFx::AS2::Value::ToInt32(val, penv);
      if ( v37.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v37);
      v37.T.Type = 3;
      v37.NV.NumberValue = (double)v10;
      if ( v10 >= 0 )
      {
        if ( v10 > 720 )
          LOWORD(v10) = 720;
        HIWORD(this->mParagraphFormat.RefCount) |= 2u;
        this->mTextFormat.LetterSpacing = v10;
      }
      else
      {
        HIWORD(this->mParagraphFormat.RefCount) |= 2u;
        this->mTextFormat.LetterSpacing = 0;
      }
      goto LABEL_147;
    }
    HIWORD(this->mParagraphFormat.RefCount) &= ~2u;
    this->mTextFormat.LetterSpacing = 0;
    goto LABEL_146;
  }
  if ( !strcmp(name->pNode->pData, "bold") )
  {
    v11 = val->T.Type;
    if ( val->T.Type != 1 && v11 && v11 != 10 )
    {
      vb = Scaleform::GFx::AS2::Value::ToBool(val, (int)penv, penv);
      Scaleform::GFx::AS2::Value::SetBool(&v37, vb);
      Scaleform::Render::Text::TextFormat::SetBold(
        (Scaleform::Render::Text::TextFormat *)&this->ResolveHandler.pLocalFrame,
        vb);
LABEL_147:
      v25 = Scaleform::GFx::AS2::Object::SetMember(this, penv, name, &v37, flags);
      goto LABEL_148;
    }
    LOBYTE(this->mTextFormat.pImageDesc.pObject) &= ~1u;
    HIWORD(this->mTextFormat.pImageDesc.pObject) &= ~0x10u;
    goto LABEL_146;
  }
  if ( Scaleform::GFx::ASString::operator==(name, "bullet") )
  {
    if ( val->T.Type != 1 && !Scaleform::GFx::AS2::Value::IsUndefined(val) )
    {
      vc = Scaleform::GFx::AS2::Value::ToBool(val, (int)penv, penv);
      Scaleform::GFx::AS2::Value::SetBool(&v37, vc);
      Scaleform::Render::Text::ParagraphFormat::SetBullet(
        (Scaleform::Render::Text::ParagraphFormat *)&this->mTextFormat.pFontHandle,
        vc);
      goto LABEL_147;
    }
    HIWORD(this->mParagraphFormat.RefCount) &= 0x7F7Fu;
LABEL_146:
    Scaleform::GFx::AS2::Value::DropRefs(&v37);
    v37.T.Type = 1;
    goto LABEL_147;
  }
  if ( Scaleform::GFx::ASString::operator==(name, "color") )
  {
    if ( val->T.Type != 1 && !Scaleform::GFx::AS2::Value::IsUndefined(val) )
    {
      vd = Scaleform::GFx::AS2::Value::ToInt32(val, penv);
      Scaleform::GFx::AS2::Value::SetNumber(&v37, (double)vd);
      this->mTextFormat.Url.HeapTypeBits ^= (vd ^ this->mTextFormat.Url.HeapTypeBits) & 0xFFFFFF;
      HIWORD(this->mTextFormat.pImageDesc.pObject) |= 1u;
      goto LABEL_147;
    }
    HIWORD(this->mTextFormat.pImageDesc.pObject) &= ~1u;
    this->mTextFormat.Url.HeapTypeBits = -16777216;
    goto LABEL_146;
  }
  if ( Scaleform::GFx::ASString::operator==(name, "font") )
  {
    if ( val->T.Type != 1 && !Scaleform::GFx::AS2::Value::IsUndefined(val) )
    {
      Scaleform::GFx::AS2::Value::ToStringImpl(val, &str, penv, -1, 0);
      Scaleform::GFx::AS2::Value::SetString(&v37, &str);
      v12 = str.pNode;
      Scaleform::Render::Text::TextFormat::SetFontList(
        (Scaleform::Render::Text::TextFormat *)&this->ResolveHandler.pLocalFrame,
        (const __m128i *)str.pNode->pData,
        0xFFFFFFFF);
      goto LABEL_45;
    }
    v13 = -4101;
LABEL_145:
    HIWORD(this->mTextFormat.pImageDesc.pObject) &= v13;
    goto LABEL_146;
  }
  if ( Scaleform::GFx::ASString::operator==(name, "indent") )
  {
    if ( val->T.Type != 1 && !Scaleform::GFx::AS2::Value::IsUndefined(val) )
    {
      v14 = Scaleform::GFx::AS2::Value::ToInt32(val, penv);
      Scaleform::GFx::AS2::Value::SetNumber(&v37, (double)v14);
      if ( v14 >= -720 )
      {
        if ( v14 > 720 )
          LOWORD(v14) = 720;
        HIWORD(this->mParagraphFormat.RefCount) |= 4u;
        this->mTextFormat.FontSize = v14;
      }
      else
      {
        HIWORD(this->mParagraphFormat.RefCount) |= 4u;
        this->mTextFormat.FontSize = -720;
      }
      goto LABEL_147;
    }
    HIWORD(this->mParagraphFormat.RefCount) &= ~4u;
    this->mTextFormat.FontSize = 0;
    goto LABEL_146;
  }
  if ( Scaleform::GFx::ASString::operator==(name, "italic") )
  {
    if ( val->T.Type != 1 && !Scaleform::GFx::AS2::Value::IsUndefined(val) )
    {
      ve = Scaleform::GFx::AS2::Value::ToBool(val, (int)penv, penv);
      Scaleform::GFx::AS2::Value::SetBool(&v37, ve);
      Scaleform::Render::Text::TextFormat::SetItalic(
        (Scaleform::Render::Text::TextFormat *)&this->ResolveHandler.pLocalFrame,
        ve);
      goto LABEL_147;
    }
    LOBYTE(this->mTextFormat.pImageDesc.pObject) &= ~2u;
    v13 = -33;
    goto LABEL_145;
  }
  if ( Scaleform::GFx::ASString::operator==(name, "leading") )
  {
    if ( val->T.Type != 1 && !Scaleform::GFx::AS2::Value::IsUndefined(val) )
    {
      v15 = Scaleform::GFx::AS2::Value::ToInt32(val, penv);
      Scaleform::GFx::AS2::Value::SetNumber(&v37, (double)v15);
      if ( v15 >= -720 )
      {
        if ( v15 > 720 )
          LOWORD(v15) = 720;
        HIWORD(this->mParagraphFormat.RefCount) |= 8u;
        *(_WORD *)&this->mTextFormat.FormatFlags = v15;
      }
      else
      {
        HIWORD(this->mParagraphFormat.RefCount) |= 8u;
        *(_WORD *)&this->mTextFormat.FormatFlags = -720;
      }
      goto LABEL_147;
    }
    HIWORD(this->mParagraphFormat.RefCount) &= ~8u;
    *(_WORD *)&this->mTextFormat.FormatFlags = 0;
    goto LABEL_146;
  }
  if ( Scaleform::GFx::ASString::operator==(name, "leftMargin") )
  {
    if ( val->T.Type != 1 && !Scaleform::GFx::AS2::Value::IsUndefined(val) )
    {
      v16 = Scaleform::GFx::AS2::Value::ToInt32(val, penv);
      Scaleform::GFx::AS2::Value::SetNumber(&v37, (double)v16);
      if ( v16 >= 0 )
      {
        if ( v16 > 720 )
          LOWORD(v16) = 720;
        HIWORD(this->mParagraphFormat.RefCount) |= 0x10u;
        this->mTextFormat.PresentMask = v16;
      }
      else
      {
        HIWORD(this->mParagraphFormat.RefCount) |= 0x10u;
        this->mTextFormat.PresentMask = 0;
      }
      goto LABEL_147;
    }
    HIWORD(this->mParagraphFormat.RefCount) &= ~0x10u;
    this->mTextFormat.PresentMask = 0;
    goto LABEL_146;
  }
  if ( Scaleform::GFx::ASString::operator==(name, "rightMargin") )
  {
    if ( val->T.Type != 1 && !Scaleform::GFx::AS2::Value::IsUndefined(val) )
    {
      v17 = Scaleform::GFx::AS2::Value::ToInt32(val, penv);
      Scaleform::GFx::AS2::Value::SetNumber(&v37, (double)v17);
      if ( v17 >= 0 )
      {
        if ( v17 > 720 )
          LOWORD(v17) = 720;
        HIWORD(this->mParagraphFormat.RefCount) |= 0x20u;
        LOWORD(this->mParagraphFormat.RefCount) = v17;
      }
      else
      {
        HIWORD(this->mParagraphFormat.RefCount) |= 0x20u;
        LOWORD(this->mParagraphFormat.RefCount) = 0;
      }
      goto LABEL_147;
    }
    HIWORD(this->mParagraphFormat.RefCount) &= ~0x20u;
    LOWORD(this->mParagraphFormat.RefCount) = 0;
    goto LABEL_146;
  }
  if ( Scaleform::GFx::ASString::operator==(name, "size") )
  {
    if ( val->T.Type != 1 && !Scaleform::GFx::AS2::Value::IsUndefined(val) )
    {
      v18 = Scaleform::GFx::AS2::Value::ToInt32(val, penv);
      Scaleform::GFx::AS2::Value::SetNumber(&v37, (double)v18);
      if ( v18 >= 0 )
      {
        if ( v18 >= 128 )
        {
          Scaleform::Render::Text::TextFormat::SetFontSize(
            (Scaleform::Render::Text::TextFormat *)&this->ResolveHandler.pLocalFrame,
            127.0);
        }
        else
        {
          val_4 = (float)(unsigned int)v18;
          Scaleform::Render::Text::TextFormat::SetFontSize(
            (Scaleform::Render::Text::TextFormat *)&this->ResolveHandler.pLocalFrame,
            val_4);
        }
      }
      goto LABEL_147;
    }
    HIWORD(this->mTextFormat.pImageDesc.pObject) &= ~8u;
    HIWORD(this->mTextFormat.Url.pHeap) = 0;
    goto LABEL_146;
  }
  if ( !Scaleform::GFx::ASString::operator==(name, "tabStops") )
  {
    if ( Scaleform::GFx::ASString::operator==(name, "underline") )
    {
      if ( val->T.Type != 1 && !Scaleform::GFx::AS2::Value::IsUndefined(val) )
      {
        vf = Scaleform::GFx::AS2::Value::ToBool(val, (int)penv, penv);
        Scaleform::GFx::AS2::Value::SetBool(&v37, vf);
        Scaleform::Render::Text::TextFormat::SetUnderline(
          (Scaleform::Render::Text::TextFormat *)&this->ResolveHandler.pLocalFrame,
          vf);
        goto LABEL_147;
      }
      LOBYTE(this->mTextFormat.pImageDesc.pObject) &= ~4u;
      v13 = -65;
      goto LABEL_145;
    }
    if ( Scaleform::GFx::ASString::operator==(name, "url") )
    {
      if ( val->T.Type == 1 || Scaleform::GFx::AS2::Value::IsUndefined(val) )
      {
        Scaleform::Render::Text::TextFormat::ClearUrl((Scaleform::Render::Text::TextFormat *)&this->ResolveHandler.pLocalFrame);
        goto LABEL_146;
      }
      Scaleform::GFx::AS2::Value::ToStringImpl(val, &v34, penv, -1, 0);
      Scaleform::GFx::AS2::Value::SetString(&v37, &v34);
      v12 = v34.pNode;
      Scaleform::Render::Text::TextFormat::SetUrl(
        (Scaleform::Render::Text::TextFormat *)&this->ResolveHandler.pLocalFrame,
        (const __m128i *)v34.pNode->pData,
        0xFFFFFFFF);
LABEL_45:
      v8 = v12->RefCount-- == 1;
      if ( v8 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v12);
      goto LABEL_147;
    }
    if ( penv->StringContext.SWFVersion < 8u )
      goto LABEL_135;
    if ( Scaleform::GFx::ASString::operator==(name, "letterSpacing") )
    {
      if ( val->T.Type != 1 && !Scaleform::GFx::AS2::Value::IsUndefined(val) )
      {
        v26 = Scaleform::GFx::AS2::Value::ToInt32(val, penv);
        v = v26;
        Scaleform::GFx::AS2::Value::SetNumber(&v37, (double)v26);
        if ( v26 >= -720 )
        {
          if ( v26 > 720 )
            v = 720;
          val_4b = (float)v;
          Scaleform::Render::Text::TextFormat::SetLetterSpacing(
            (Scaleform::Render::Text::TextFormat *)&this->ResolveHandler.pLocalFrame,
            val_4b);
        }
        else
        {
          val_4a = (float)-720;
          Scaleform::Render::Text::TextFormat::SetLetterSpacing(
            (Scaleform::Render::Text::TextFormat *)&this->ResolveHandler.pLocalFrame,
            val_4a);
        }
        goto LABEL_135;
      }
      HIWORD(this->mTextFormat.pImageDesc.pObject) &= ~2u;
      LOWORD(this->mTextFormat.Url.pHeap) = 0;
    }
    else
    {
      if ( !Scaleform::GFx::ASString::operator==(name, "kerning") )
        goto LABEL_135;
      if ( val->T.Type != 1 && !Scaleform::GFx::AS2::Value::IsUndefined(val) )
      {
        vg = Scaleform::GFx::AS2::Value::ToBool(val, (int)name, penv);
        Scaleform::GFx::AS2::Value::SetBool(&v37, vg);
        Scaleform::Render::Text::TextFormat::SetKerning(
          (Scaleform::Render::Text::TextFormat *)&this->ResolveHandler.pLocalFrame,
          vg);
        goto LABEL_135;
      }
      LOBYTE(this->mTextFormat.pImageDesc.pObject) &= ~8u;
      HIWORD(this->mTextFormat.pImageDesc.pObject) &= ~0x80u;
    }
    Scaleform::GFx::AS2::Value::DropRefs(&v37);
    v37.T.Type = 1;
LABEL_135:
    if ( penv->StringContext.pContext->GFxExtensions.Value != 1 || !Scaleform::GFx::ASString::operator==(name, "alpha") )
      goto LABEL_147;
    if ( val->T.Type != 1 && !Scaleform::GFx::AS2::Value::IsUndefined(val) )
    {
      v27 = Scaleform::GFx::AS2::Value::ToInt32(val, penv);
      va = v27;
      Scaleform::GFx::AS2::Value::SetNumber(&v37, (double)v27);
      if ( v27 >= 0 )
      {
        if ( v27 > 100 )
          va = 100;
      }
      else
      {
        va = 0;
      }
      Size = (int)((double)va * 255.0 / 100.0);
      Scaleform::Render::Text::TextFormat::SetAlpha(
        (Scaleform::Render::Text::TextFormat *)&this->ResolveHandler.pLocalFrame,
        Size);
      goto LABEL_147;
    }
    this->mTextFormat.Url.HeapTypeBits |= 0xFF000000;
    v13 = -1025;
    goto LABEL_145;
  }
  v19 = val->T.Type;
  if ( val->T.Type == 1 || Scaleform::GFx::AS2::Value::IsUndefined(val) )
  {
    Scaleform::Render::Text::ParagraphFormat::ClearTabStops((Scaleform::Render::Text::ParagraphFormat *)&this->mTextFormat.pFontHandle);
    goto LABEL_146;
  }
  if ( v19 != 6 )
    goto LABEL_147;
  v20 = Scaleform::GFx::AS2::Value::ToObject(val, penv);
  if ( v20->GetObjectType(&v20->Scaleform::GFx::AS2::ObjectInterface) != Object_Array )
    goto LABEL_147;
  v21 = (Scaleform::GFx::AS2::ArrayObject *)Scaleform::GFx::AS2::Value::ToObject(val, penv);
  Scaleform::Render::Text::ParagraphFormat::SetTabStopsNum(
    (Scaleform::Render::Text::ParagraphFormat *)&this->mTextFormat.pFontHandle,
    v21->Elements.Data.Size);
  v22 = 0;
  Size = v21->Elements.Data.Size;
  if ( Size > 0 )
  {
    do
    {
      v23 = Scaleform::GFx::AS2::Value::ToNumber(v21->Elements.Data.Data[v22], penv);
      v38.T.Type = 3;
      *(_QWORD *)v35 = (__int64)v23;
      v38.NV.NumberValue = (double)(unsigned int)(__int64)v23;
      Scaleform::GFx::AS2::ArrayObject::SetElement(v21, v22, &v38);
      if ( v38.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v38);
      Scaleform::Render::Text::ParagraphFormat::SetTabStopsElement(
        (Scaleform::Render::Text::ParagraphFormat *)&this->mTextFormat.pFontHandle,
        v22++,
        (__int64)v23);
    }
    while ( v22 < Size );
  }
  Scaleform::GFx::AS2::Value::Value(&v39, v21);
  v25 = Scaleform::GFx::AS2::Object::SetMember(this, penv, name, v24, flags);
  if ( v39.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v39);
LABEL_148:
  if ( v37.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v37);
  return v25;
}
