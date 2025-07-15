void __thiscall Scaleform::GFx::AS2::CSSTextFormatLoader::Visit(
        Scaleform::GFx::AS2::CSSTextFormatLoader *this,
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val,
        unsigned __int8 flags)
{
  char *pData; // ebp
  Scaleform::GFx::ASStringNode *pNode; // edx
  const char *v6; // esi
  unsigned int Size; // edi
  unsigned int v8; // eax
  Scaleform::GFx::AS2::TextFormatObject *pTFO; // ecx
  unsigned int ColorV; // edx
  unsigned int v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // eax
  unsigned int v14; // eax
  unsigned int v15; // eax
  unsigned int v16; // eax
  Scaleform::Render::Text::ParagraphFormat *p_mParagraphFormat; // ecx
  Scaleform::Render::Text::ParagraphFormat *v18; // ecx
  unsigned int v19; // eax
  unsigned int v20; // eax
  unsigned int v21; // eax
  unsigned int v22; // eax
  unsigned int v23; // eax
  unsigned int v24; // eax
  Scaleform::Render::Text::ParagraphFormat *v25; // esi
  Scaleform::GFx::ASStringNode *v26; // ecx
  char *temp; // [esp+18h] [ebp-8h] BYREF
  Scaleform::GFx::ASString valstr; // [esp+1Ch] [ebp-4h] BYREF
  float num; // [esp+28h] [ebp+8h]
  float numa; // [esp+28h] [ebp+8h]
  float numb; // [esp+28h] [ebp+8h]
  float numc; // [esp+28h] [ebp+8h]
  float numd; // [esp+28h] [ebp+8h]

  Scaleform::GFx::AS2::Value::ToStringImpl(val, &valstr, this->pEnv, -1, 0);
  pData = (char *)valstr.pNode->pData;
  pNode = name->pNode;
  temp = 0;
  v6 = pNode->pData;
  Size = valstr.pNode->Size;
  if ( !strcmp(pNode->pData, (const char *)&stru_9555EC) )
  {
    v8 = strtol((unsigned int)name, pData + 1, &temp, 0x10u);
    pTFO = this->pTFO;
    ColorV = pTFO->mTextFormat.ColorV;
    pTFO = (Scaleform::GFx::AS2::TextFormatObject *)((char *)pTFO + 52);
    pTFO->Members.mHash.pTable = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *)((int)pTFO->Members.mHash.pTable ^ (unsigned int)&vostok::memory::s_CRT_arena[5574199] & (v8 ^ ColorV));
    HIWORD(pTFO->ResolveHandler.pLocalFrame) |= 1u;
  }
  else if ( strcmp(v6, "display") )
  {
    if ( !strcmp(v6, "fontFamily") )
    {
      Scaleform::Render::Text::TextFormat::SetFontList(&this->pTFO->mTextFormat, pData, valstr.pNode->Size);
    }
    else if ( Scaleform::GFx::ASString::operator==(name, "fontSize") )
    {
      num = Scaleform::SFstrtod(pData, &temp);
      Scaleform::Render::Text::TextFormat::SetFontSize(&this->pTFO->mTextFormat, num);
    }
    else if ( Scaleform::GFx::ASString::operator==(name, "fontStyle") )
    {
      v11 = Size;
      if ( Size >= 4 )
        v11 = 4;
      if ( !strncmp("normal", pData, v11) )
      {
        Scaleform::Render::Text::TextFormat::SetItalic(&this->pTFO->mTextFormat, 0);
      }
      else
      {
        v12 = Size;
        if ( Size >= 9 )
          v12 = 9;
        if ( !strncmp("italic", pData, v12) )
          Scaleform::Render::Text::TextFormat::SetItalic(&this->pTFO->mTextFormat, 1);
      }
    }
    else if ( Scaleform::GFx::ASString::operator==(name, "fontWeight") )
    {
      v13 = Size;
      if ( Size >= 6 )
        v13 = 6;
      if ( !strncmp("normal", pData, v13) )
      {
        Scaleform::Render::Text::TextFormat::SetBold(&this->pTFO->mTextFormat, 0);
      }
      else
      {
        v14 = Size;
        if ( Size >= 4 )
          v14 = 4;
        if ( !strncmp("bold", pData, v14) )
          Scaleform::Render::Text::TextFormat::SetBold(&this->pTFO->mTextFormat, 1);
      }
    }
    else if ( Scaleform::GFx::ASString::operator==(name, "kerning") )
    {
      v15 = Size;
      if ( Size >= 5 )
        v15 = 5;
      if ( !strncmp((const char *)&stru_95AF78.m_key_bindings[6], pData, v15) )
      {
        Scaleform::Render::Text::TextFormat::SetKerning(&this->pTFO->mTextFormat, 0);
      }
      else
      {
        v16 = Size;
        if ( Size >= 4 )
          v16 = 4;
        if ( !strncmp((const char *)&stru_95AF78.m_key_bindings[4].m_keyboard[1], pData, v16) )
          Scaleform::Render::Text::TextFormat::SetKerning(&this->pTFO->mTextFormat, 1);
      }
    }
    else if ( Scaleform::GFx::ASString::operator==(name, "letterSpacing") )
    {
      numa = Scaleform::SFstrtod(pData, &temp);
      Scaleform::Render::Text::TextFormat::SetLetterSpacing(&this->pTFO->mTextFormat, numa);
    }
    else if ( Scaleform::GFx::ASString::operator==(name, "marginLeft") )
    {
      numb = Scaleform::SFstrtod(pData, &temp);
      p_mParagraphFormat = &this->pTFO->mParagraphFormat;
      p_mParagraphFormat->PresentMask |= 0x10u;
      p_mParagraphFormat->LeftMargin = (int)numb;
    }
    else if ( Scaleform::GFx::ASString::operator==(name, "marginRight") )
    {
      numc = Scaleform::SFstrtod(pData, &temp);
      v18 = &this->pTFO->mParagraphFormat;
      v18->PresentMask |= 0x20u;
      v18->RightMargin = (int)numc;
    }
    else if ( Scaleform::GFx::ASString::operator==(name, "textAlign") )
    {
      v19 = Size;
      if ( Size >= 4 )
        v19 = 4;
      if ( !strncmp("left", pData, v19) )
      {
        Scaleform::Render::Text::ParagraphFormat::SetAlignment(&this->pTFO->mParagraphFormat, Align_BaseLine);
      }
      else
      {
        v20 = Size;
        if ( Size >= 6 )
          v20 = 6;
        if ( !strncmp("center", pData, v20) )
        {
          Scaleform::Render::Text::ParagraphFormat::SetAlignment(&this->pTFO->mParagraphFormat, Align_Left|Align_Right);
        }
        else
        {
          v21 = Size;
          if ( Size >= 5 )
            v21 = 5;
          if ( !strncmp("right", pData, v21) )
          {
            Scaleform::Render::Text::ParagraphFormat::SetAlignment(&this->pTFO->mParagraphFormat, Align_Right);
          }
          else
          {
            v22 = Size;
            if ( Size >= 7 )
              v22 = 7;
            if ( !strncmp("justify", pData, v22) )
              Scaleform::Render::Text::ParagraphFormat::SetAlignment(&this->pTFO->mParagraphFormat, Align_Left);
          }
        }
      }
    }
    else if ( Scaleform::GFx::ASString::operator==(name, "textDecoration") )
    {
      v23 = Size;
      if ( Size >= 4 )
        v23 = 4;
      if ( !strncmp("none", pData, v23) )
      {
        Scaleform::Render::Text::TextFormat::SetUnderline(&this->pTFO->mTextFormat, 0);
      }
      else
      {
        v24 = Size;
        if ( Size >= 9 )
          v24 = 9;
        if ( !strncmp("underline", pData, v24) )
          Scaleform::Render::Text::TextFormat::SetUnderline(&this->pTFO->mTextFormat, 1);
      }
    }
    else if ( Scaleform::GFx::ASString::operator==(name, "textIndent") )
    {
      numd = Scaleform::SFstrtod(pData, &temp);
      v25 = &this->pTFO->mParagraphFormat;
      v25->PresentMask |= 4u;
      v25->Indent = (int)numd;
    }
  }
  v26 = valstr.pNode;
  if ( valstr.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v26);
}
