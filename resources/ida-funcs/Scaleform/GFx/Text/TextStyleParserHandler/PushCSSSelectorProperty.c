void __thiscall Scaleform::GFx::Text::TextStyleParserHandler<wchar_t>::PushCSSSelectorProperty(
        Scaleform::GFx::Text::TextStyleParserHandler<wchar_t> *this,
        const Scaleform::GFx::Text::CSSToken<wchar_t> *name,
        const Scaleform::Array<Scaleform::GFx::Text::CSSToken<wchar_t>,2,Scaleform::ArrayDefaultPolicy> *value,
        const Scaleform::Array<Scaleform::Render::Text::Style *,2,Scaleform::ArrayDefaultPolicy> *pdata)
{
  void *v5; // esi
  Scaleform::String sname; // [esp+8h] [ebp-4h] BYREF

  Scaleform::String::String(&sname);
  Scaleform::String::AppendString(&sname, name->pBase, name->Length);
  if ( value->Data.Size )
  {
    if ( !strcmp((const char *)((sname.HeapTypeBits & 0xFFFFFFFC) + 8), (const char *)&stru_9555EC) )
    {
      Scaleform::GFx::Text::TextStyleParserHandler<wchar_t>::HandleColor(this, pdata, (unsigned int)value);
    }
    else if ( Scaleform::String::operator==(&sname, "display") )
    {
      Scaleform::GFx::Text::TextStyleParserHandler<wchar_t>::HandleDisplay(this, pdata, value);
    }
    else if ( Scaleform::String::operator==(&sname, "font-family") )
    {
      Scaleform::GFx::Text::TextStyleParserHandler<wchar_t>::HandleFontFamily(this, pdata, value);
    }
    else if ( Scaleform::String::operator==(&sname, "font-size") )
    {
      Scaleform::GFx::Text::TextStyleParserHandler<wchar_t>::HandleFontSize(this, pdata, *(float *)&value);
    }
    else if ( Scaleform::String::operator==(&sname, "font-style") )
    {
      Scaleform::GFx::Text::TextStyleParserHandler<wchar_t>::HandleFontStyle(this, pdata, value);
    }
    else if ( Scaleform::String::operator==(&sname, "font-weight") )
    {
      Scaleform::GFx::Text::TextStyleParserHandler<wchar_t>::HandleFontWeight(this, pdata, value);
    }
    else if ( Scaleform::String::operator==(&sname, "kerning") )
    {
      Scaleform::GFx::Text::TextStyleParserHandler<wchar_t>::HandleKerning(this, pdata, value);
    }
    else if ( Scaleform::String::operator==(&sname, "leading") )
    {
      Scaleform::GFx::Text::TextStyleParserHandler<wchar_t>::HandleLeading(this, pdata, *(float *)&value);
    }
    else if ( Scaleform::String::operator==(&sname, "letter-spacing") )
    {
      Scaleform::GFx::Text::TextStyleParserHandler<wchar_t>::HandleLetterSpacing(this, pdata, *(float *)&value);
    }
    else if ( Scaleform::String::operator==(&sname, "margin-left") )
    {
      Scaleform::GFx::Text::TextStyleParserHandler<wchar_t>::HandleMarginLeft(this, pdata, value);
    }
    else if ( Scaleform::String::operator==(&sname, "margin-right") )
    {
      Scaleform::GFx::Text::TextStyleParserHandler<wchar_t>::HandleMarginRight(this, pdata, value);
    }
    else if ( Scaleform::String::operator==(&sname, "text-align") )
    {
      Scaleform::GFx::Text::TextStyleParserHandler<wchar_t>::HandleTextAlign(this, pdata, value);
    }
    else if ( Scaleform::String::operator==(&sname, "text-decoration") )
    {
      Scaleform::GFx::Text::TextStyleParserHandler<wchar_t>::HandleTextDecoration(this, pdata, value);
    }
    else if ( Scaleform::String::operator==(&sname, "text-indent") )
    {
      Scaleform::GFx::Text::TextStyleParserHandler<wchar_t>::HandleTextIndent(this, pdata, *(float *)&value);
    }
  }
  v5 = (void *)(sname.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((sname.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v5);
}
