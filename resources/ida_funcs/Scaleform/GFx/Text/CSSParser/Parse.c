bool __thiscall Scaleform::GFx::Text::CSSParser<wchar_t>::Parse(
        Scaleform::GFx::Text::CSSParser<wchar_t> *this,
        const wchar_t *buffer,
        unsigned int len,
        Scaleform::GFx::Text::CSSHandler<wchar_t> *handler,
        void *pdata)
{
  int v6; // ebp
  Scaleform::GFx::Text::CSSToken<wchar_t> *NextToken; // eax
  Scaleform::GFx::Text::CSSToken<wchar_t>::TokenType Type; // edi
  const wchar_t *pBase; // edx
  unsigned int Length; // eax
  Scaleform::GFx::Text::CSSToken<wchar_t> *v11; // eax
  const wchar_t *v12; // ecx
  unsigned int v13; // edx
  unsigned int ColNo; // ecx
  Scaleform::GFx::Text::CSSToken<wchar_t> *v15; // eax
  Scaleform::GFx::Text::CSSToken<wchar_t>::TokenType v16; // ecx
  const wchar_t *v17; // edx
  unsigned int v18; // eax
  Scaleform::GFx::Text::CSSToken<wchar_t> *v19; // eax
  const wchar_t *v20; // edx
  unsigned int v21; // eax
  Scaleform::GFx::Text::CSSToken<wchar_t> *v22; // eax
  const wchar_t *v23; // ecx
  unsigned int v24; // eax
  Scaleform::GFx::Text::CSSToken<wchar_t> *v25; // eax
  unsigned int v26; // edx
  Scaleform::GFx::Text::CSSToken<wchar_t> *v27; // eax
  unsigned int v28; // edx
  __int32 v29; // edi
  bool preserveToken; // [esp+13h] [ebp-85h]
  Scaleform::GFx::Text::CSSToken<wchar_t> token; // [esp+14h] [ebp-84h] BYREF
  Scaleform::GFx::Text::CSSTokenizer<wchar_t> tokens; // [esp+20h] [ebp-78h] BYREF
  Scaleform::GFx::Text::CSSToken<wchar_t> v34; // [esp+44h] [ebp-54h] BYREF
  Scaleform::GFx::Text::CSSToken<wchar_t> v35; // [esp+50h] [ebp-48h] BYREF
  Scaleform::GFx::Text::CSSToken<wchar_t> v36; // [esp+5Ch] [ebp-3Ch] BYREF
  Scaleform::GFx::Text::CSSToken<wchar_t> v37; // [esp+68h] [ebp-30h] BYREF
  Scaleform::GFx::Text::CSSToken<wchar_t> v38; // [esp+74h] [ebp-24h] BYREF
  Scaleform::GFx::Text::CSSToken<wchar_t> result; // [esp+80h] [ebp-18h] BYREF
  Scaleform::GFx::Text::CSSToken<wchar_t> v40; // [esp+8Ch] [ebp-Ch] BYREF

  v6 = 0;
  tokens.pCurr = buffer;
  tokens.pEnd = &buffer[len];
  tokens.CurrentToken.Type = TT_Unknown;
  tokens.CurrentToken.pBase = 0;
  tokens.CurrentToken.Length = 0;
  tokens.LineNo = 1;
  tokens.ColNo = 1;
  tokens.LineDev = 0;
  tokens.ColDev = 0;
  preserveToken = 0;
  while ( v6 != 4 )
  {
    NextToken = Scaleform::GFx::Text::CSSTokenizer<wchar_t>::GetNextToken(&tokens, &result);
    Type = NextToken->Type;
    pBase = NextToken->pBase;
    Length = NextToken->Length;
    token.Type = Type;
    token.pBase = pBase;
    token.Length = Length;
    if ( Type == TT_EOF )
      v6 = 3;
    if ( v6 )
    {
      if ( v6 == 1 )
      {
        if ( Type )
        {
          if ( Type != TT_WhiteSpace )
          {
            if ( Type == TT_CloseBrace )
            {
              handler->CloseCSSSelectorBlock(handler, pdata);
              v6 = 0;
            }
            else
            {
              v6 = 4;
            }
          }
        }
        else
        {
          this->PropertyName.Type = TT_Name;
          this->PropertyName.pBase = pBase;
          this->PropertyName.Length = Length;
          v15 = Scaleform::GFx::Text::CSSTokenizer<wchar_t>::GetNextToken(&tokens, &v34);
          v16 = v15->Type;
          v17 = v15->pBase;
          v18 = v15->Length;
          token.pBase = v17;
          token.Length = v18;
          if ( v16 == TT_WhiteSpace )
          {
            v19 = Scaleform::GFx::Text::CSSTokenizer<wchar_t>::GetNextToken(&tokens, &v37);
            v20 = v19->pBase;
            v16 = v19->Type;
            v21 = v19->Length;
            token.pBase = v20;
            token.Length = v21;
          }
          v6 = 2 * (v16 != TT_Colon) + 2;
        }
      }
      else
      {
        if ( v6 != 2 )
          return v6 == 3;
        if ( Type == TT_CloseBrace )
        {
          handler->PushCSSSelectorProperty(handler, &this->PropertyName, &this->PropertyValue, pdata);
          handler->CloseCSSSelectorBlock(handler, pdata);
          this->bPropValSpool = 0;
          v6 = 0;
        }
        else if ( Type == TT_SemiColon )
        {
          handler->PushCSSSelectorProperty(handler, &this->PropertyName, &this->PropertyValue, pdata);
          this->bPropValSpool = 0;
          v6 = 1;
        }
        else
        {
          if ( !this->bPropValSpool )
          {
            Scaleform::ArrayData<Scaleform::GFx::Text::CSSToken<wchar_t>,Scaleform::AllocatorGH<Scaleform::GFx::Text::CSSToken<wchar_t>,2>,Scaleform::ArrayDefaultPolicy>::Resize(
              &this->PropertyValue.Data,
              0);
            this->bPropValSpool = 1;
            if ( Type == TT_WhiteSpace )
            {
              v11 = Scaleform::GFx::Text::CSSTokenizer<wchar_t>::GetNextToken(&tokens, &v40);
              v12 = v11->pBase;
              token.Type = v11->Type;
              v13 = v11->Length;
              token.pBase = v12;
              token.Length = v13;
            }
            ColNo = tokens.ColNo;
            this->PropValLinePos = tokens.LineNo;
            this->PropValColPos = ColNo;
          }
          Scaleform::ArrayData<Scaleform::GFx::Text::CSSToken<wchar_t>,Scaleform::AllocatorGH<Scaleform::GFx::Text::CSSToken<wchar_t>,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
            &this->PropertyValue.Data,
            &token);
        }
      }
    }
    else if ( Type )
    {
      if ( Type == TT_WhiteSpace )
      {
        if ( this->bPseudoClass )
          v6 = 4;
      }
      else
      {
        v6 = 4;
      }
    }
    else if ( this->bPseudoClass )
    {
      this->SelectorName.Length += Length;
LABEL_35:
      handler->OpenCSSSelectorBlock(handler, (const Scaleform::GFx::Text::CSSToken<wchar_t> *)this, pdata);
      if ( preserveToken )
      {
        preserveToken = 0;
      }
      else
      {
        v25 = Scaleform::GFx::Text::CSSTokenizer<wchar_t>::GetNextToken(&tokens, &v36);
        v26 = v25->Length;
        Type = v25->Type;
        token.pBase = v25->pBase;
        token.Length = v26;
      }
      if ( Type == TT_WhiteSpace )
      {
        v27 = Scaleform::GFx::Text::CSSTokenizer<wchar_t>::GetNextToken(&tokens, &v38);
        v28 = v27->Length;
        Type = v27->Type;
        token.pBase = v27->pBase;
        token.Length = v28;
      }
      v29 = Type - 5;
      if ( v29 )
      {
        if ( v29 == 1 )
        {
          v6 = 1;
          this->bPseudoClass = 0;
        }
        else
        {
          v6 = 4;
        }
      }
      else
      {
        v6 = 0;
        this->bPseudoClass = 0;
      }
    }
    else
    {
      this->SelectorName.Type = TT_Name;
      this->SelectorName.pBase = pBase;
      this->SelectorName.Length = Length;
      v22 = Scaleform::GFx::Text::CSSTokenizer<wchar_t>::GetNextToken(&tokens, &v35);
      Type = v22->Type;
      v23 = v22->pBase;
      v24 = v22->Length;
      token.pBase = v23;
      if ( Type != TT_Colon )
      {
        preserveToken = 1;
        goto LABEL_35;
      }
      this->SelectorName.Length += v24;
      this->bPseudoClass = 1;
    }
  }
  return v6 == 3;
}
