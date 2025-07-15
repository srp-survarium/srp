void __thiscall Scaleform::GFx::AS2::CSSTextFormatLoader::Visit(
        Scaleform::GFx::AS2::CSSTextFormatLoader *this,
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val,
        unsigned __int8 flags)
{
  __m128i *pData; // ebp
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
  char *v29; // [esp+18h] [ebp-8h] BYREF
  Scaleform::GFx::ASStringNode *v30; // [esp+1Ch] [ebp-4h] BYREF
  float fontSize; // [esp+28h] [ebp+8h]
  float v32; // [esp+28h] [ebp+8h]
  float v33; // [esp+28h] [ebp+8h]
  float v34; // [esp+28h] [ebp+8h]
  float v35; // [esp+28h] [ebp+8h]

  Scaleform::GFx::AS2::Value::ToStringImpl(val, (Scaleform::GFx::ASString *)&v30, this->pEnv, -1, 0);
  pData = (__m128i *)v30->pData;
  pNode = name->pNode;
  v29 = 0;
  v6 = pNode->pData;
  Size = v30->Size;
  if ( !strcmp(pNode->pData, "color") )
  {
    v8 = strtol((int)name, &pData->m128i_i8[1], (const char **)&v29, 16);
    pTFO = this->pTFO;
    ColorV = pTFO->mTextFormat.ColorV;
    pTFO = (Scaleform::GFx::AS2::TextFormatObject *)((char *)pTFO + 52);
    pTFO->Members.mHash.pTable = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *)((int)pTFO->Members.mHash.pTable ^ (v8 ^ ColorV) & 0xFFFFFF);
    HIWORD(pTFO->ResolveHandler.pLocalFrame) |= 1u;
  }
  else if ( strcmp(v6, "display") )
  {
    if ( !strcmp(v6, "fontFamily") )
    {
      Scaleform::Render::Text::TextFormat::SetFontList(&this->pTFO->mTextFormat, pData, v30->Size);
    }
    else if ( Scaleform::GFx::ASString::operator==(name, "fontSize") )
    {
      fontSize = Scaleform::SFstrtod(Size, pData->m128i_i8, &v29);
      Scaleform::Render::Text::TextFormat::SetFontSize(&this->pTFO->mTextFormat, fontSize);
    }
    else if ( Scaleform::GFx::ASString::operator==(name, "fontStyle") )
    {
      v11 = Size;
      if ( Size >= 4 )
        v11 = 4;
      if ( !strncmp("normal", pData->m128i_i8, v11) )
      {
        Scaleform::Render::Text::TextFormat::SetItalic(&this->pTFO->mTextFormat, 0);
      }
      else
      {
        v12 = Size;
        if ( Size >= 9 )
          v12 = 9;
        if ( !strncmp("italic", pData->m128i_i8, v12) )
          Scaleform::Render::Text::TextFormat::SetItalic(&this->pTFO->mTextFormat, 1);
      }
    }
    else if ( Scaleform::GFx::ASString::operator==(name, "fontWeight") )
    {
      v13 = Size;
      if ( Size >= 6 )
        v13 = 6;
      if ( !strncmp("normal", pData->m128i_i8, v13) )
      {
        Scaleform::Render::Text::TextFormat::SetBold(&this->pTFO->mTextFormat, 0);
      }
      else
      {
        v14 = Size;
        if ( Size >= 4 )
          v14 = 4;
        if ( !strncmp("bold", pData->m128i_i8, v14) )
          Scaleform::Render::Text::TextFormat::SetBold(&this->pTFO->mTextFormat, 1);
      }
    }
    else if ( Scaleform::GFx::ASString::operator==(name, "kerning") )
    {
      v15 = Size;
      if ( Size >= 5 )
        v15 = 5;
      if ( !strncmp("false", pData->m128i_i8, v15) )
      {
        Scaleform::Render::Text::TextFormat::SetKerning(&this->pTFO->mTextFormat, 0);
      }
      else
      {
        v16 = Size;
        if ( Size >= 4 )
          v16 = 4;
        if ( !strncmp("true", pData->m128i_i8, v16) )
          Scaleform::Render::Text::TextFormat::SetKerning(&this->pTFO->mTextFormat, 1);
      }
    }
    else if ( Scaleform::GFx::ASString::operator==(name, "letterSpacing") )
    {
      v32 = Scaleform::SFstrtod(Size, pData->m128i_i8, &v29);
      Scaleform::Render::Text::TextFormat::SetLetterSpacing(&this->pTFO->mTextFormat, v32);
    }
    else if ( Scaleform::GFx::ASString::operator==(name, "marginLeft") )
    {
      v33 = Scaleform::SFstrtod(Size, pData->m128i_i8, &v29);
      p_mParagraphFormat = &this->pTFO->mParagraphFormat;
      p_mParagraphFormat->PresentMask |= 0x10u;
      p_mParagraphFormat->LeftMargin = (int)v33;
    }
    else if ( Scaleform::GFx::ASString::operator==(name, "marginRight") )
    {
      v34 = Scaleform::SFstrtod(Size, pData->m128i_i8, &v29);
      v18 = &this->pTFO->mParagraphFormat;
      v18->PresentMask |= 0x20u;
      v18->RightMargin = (int)v34;
    }
    else if ( Scaleform::GFx::ASString::operator==(name, "textAlign") )
    {
      v19 = Size;
      if ( Size >= 4 )
        v19 = 4;
      if ( !strncmp("left", pData->m128i_i8, v19) )
      {
        Scaleform::Render::Text::ParagraphFormat::SetAlignment(&this->pTFO->mParagraphFormat, Align_BaseLine);
      }
      else
      {
        v20 = Size;
        if ( Size >= 6 )
          v20 = 6;
        if ( !strncmp("center", pData->m128i_i8, v20) )
        {
          Scaleform::Render::Text::ParagraphFormat::SetAlignment(&this->pTFO->mParagraphFormat, Align_Left|Align_Right);
        }
        else
        {
          v21 = Size;
          if ( Size >= 5 )
            v21 = 5;
          if ( !strncmp("right", pData->m128i_i8, v21) )
          {
            Scaleform::Render::Text::ParagraphFormat::SetAlignment(&this->pTFO->mParagraphFormat, Align_Right);
          }
          else
          {
            v22 = Size;
            if ( Size >= 7 )
              v22 = 7;
            if ( !strncmp("justify", pData->m128i_i8, v22) )
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
      if ( !strncmp("none", pData->m128i_i8, v23) )
      {
        Scaleform::Render::Text::TextFormat::SetUnderline(&this->pTFO->mTextFormat, 0);
      }
      else
      {
        v24 = Size;
        if ( Size >= 9 )
          v24 = 9;
        if ( !strncmp("underline", pData->m128i_i8, v24) )
          Scaleform::Render::Text::TextFormat::SetUnderline(&this->pTFO->mTextFormat, 1);
      }
    }
    else if ( Scaleform::GFx::ASString::operator==(name, "textIndent") )
    {
      v35 = Scaleform::SFstrtod(Size, pData->m128i_i8, &v29);
      v25 = &this->pTFO->mParagraphFormat;
      v25->PresentMask |= 4u;
      v25->Indent = (int)v35;
    }
  }
  v26 = v30;
  if ( v30->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v26);
}
