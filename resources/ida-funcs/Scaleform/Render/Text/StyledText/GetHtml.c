Scaleform::StringBuffer *__thiscall Scaleform::Render::Text::StyledText::GetHtml(
        Scaleform::Render::Text::StyledText *this,
        Scaleform::StringBuffer *strBuf)
{
  unsigned int v3; // edi
  Scaleform::ArrayLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2,Scaleform::ArrayDefaultPolicy> *p_Paragraphs; // ecx
  unsigned int Size; // ebx
  int v6; // eax
  int v7; // edx
  int pPara; // ebp
  unsigned int v9; // eax
  bool v10; // zf
  unsigned int v11; // edx
  _WORD *v12; // ecx
  int v13; // ebx
  char v14; // dl
  unsigned int *TabStops; // eax
  unsigned int *v16; // ebp
  Scaleform::Render::Text::Paragraph::FormatRunIterator *v17; // ebx
  Scaleform::Render::Text::TextFormat *pObject; // eax
  Scaleform::RefCountNTSImpl *v19; // ecx
  Scaleform::RefCountNTSImpl **p_pObject; // eax
  Scaleform::RefCountNTSImpl *v21; // edi
  Scaleform::Render::Text::TextFormat *v22; // eax
  const Scaleform::StringLH *v23; // ebp
  Scaleform::RefCountNTSImpl_vtbl *v24; // ecx
  int RefCount; // ecx
  Scaleform::Render::Text::TextFormat *v26; // eax
  Scaleform::Render::Text::TextFormat *v27; // ebp
  Scaleform::Render::Text::TextFormat *v28; // ecx
  Scaleform::StringDH *FontList; // edi
  Scaleform::Render::Text::TextFormat *v30; // eax
  Scaleform::Render::Text::TextFormat *v31; // eax
  Scaleform::Render::Text::TextFormat *v32; // eax
  double v33; // st7
  Scaleform::Render::Text::TextFormat *v34; // eax
  Scaleform::Render::Text::TextFormat *v35; // eax
  const Scaleform::StringLH *v36; // edi
  Scaleform::Render::Text::TextFormat *v37; // eax
  unsigned int v38; // edi
  Scaleform::Render::Text::StyledText *v39; // ebp
  wchar_t v40; // ax
  Scaleform::Render::Text::TextFormat *v41; // eax
  Scaleform::Render::Text::TextFormat *v42; // eax
  Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> > *v43; // edx
  unsigned int Index; // ecx
  Scaleform::Render::Text::TextFormat *v45; // ebx
  Scaleform::RefCountVImpl *v46; // ecx
  Scaleform::RefCountNTSImpl *v47; // ecx
  volatile LONG *v48; // edi
  volatile LONG *v49; // edi
  Scaleform::Render::Text::TextFormat *v50; // ebp
  Scaleform::RefCountVImpl *v51; // ecx
  Scaleform::RefCountNTSImpl *v52; // ecx
  volatile LONG *v53; // edi
  volatile LONG *v54; // edi
  __int16 v56; // [esp+12h] [ebp-43Ah] BYREF
  __int64 v; // [esp+14h] [ebp-438h] BYREF
  Scaleform::Render::Text::TextFormat *v58; // [esp+1Ch] [ebp-430h] BYREF
  int v59; // [esp+20h] [ebp-42Ch]
  Scaleform::Render::Text::StyledText *v60; // [esp+24h] [ebp-428h]
  unsigned int v61; // [esp+28h] [ebp-424h] BYREF
  Scaleform::RefCountNTSImpl *v62; // [esp+2Ch] [ebp-420h] BYREF
  Scaleform::Render::Text::Paragraph::FormatRunIterator v63; // [esp+30h] [ebp-41Ch] BYREF
  int v64; // [esp+54h] [ebp-3F8h]
  unsigned int v65; // [esp+58h] [ebp-3F4h]
  int v66; // [esp+5Ch] [ebp-3F0h]
  int v67; // [esp+64h] [ebp-3E8h]
  Scaleform::MsgFormat::Sink v68; // [esp+68h] [ebp-3E4h] BYREF
  Scaleform::MsgFormat::Sink v69; // [esp+74h] [ebp-3D8h] BYREF
  Scaleform::MsgFormat::Sink v70; // [esp+80h] [ebp-3CCh] BYREF
  Scaleform::MsgFormat::Sink v71; // [esp+8Ch] [ebp-3C0h] BYREF
  Scaleform::MsgFormat::Sink r; // [esp+98h] [ebp-3B4h] BYREF
  Scaleform::MsgFormat::Sink v73; // [esp+A4h] [ebp-3A8h] BYREF
  Scaleform::MsgFormat::Sink v74; // [esp+B0h] [ebp-39Ch] BYREF
  Scaleform::MsgFormat::Sink v75; // [esp+BCh] [ebp-390h] BYREF
  Scaleform::MsgFormat::Sink v76; // [esp+C8h] [ebp-384h] BYREF
  Scaleform::MsgFormat::Sink v77; // [esp+D4h] [ebp-378h] BYREF
  Scaleform::MsgFormat::Sink v78; // [esp+E0h] [ebp-36Ch] BYREF
  Scaleform::MsgFormat::Sink v79; // [esp+ECh] [ebp-360h] BYREF
  Scaleform::MsgFormat::Sink v80; // [esp+F8h] [ebp-354h] BYREF
  Scaleform::MsgFormat::Sink v81; // [esp+104h] [ebp-348h] BYREF
  Scaleform::MsgFormat::Sink v82; // [esp+110h] [ebp-33Ch] BYREF
  Scaleform::MsgFormat::Sink v83; // [esp+11Ch] [ebp-330h] BYREF
  Scaleform::MsgFormat::Sink v84; // [esp+128h] [ebp-324h] BYREF
  Scaleform::MsgFormat::Sink v85; // [esp+134h] [ebp-318h] BYREF
  Scaleform::MsgFormat::Sink v86; // [esp+140h] [ebp-30Ch] BYREF
  Scaleform::MsgFormat v87; // [esp+14Ch] [ebp-300h] BYREF

  v3 = 0;
  v60 = this;
  v59 = 0;
  Scaleform::StringBuffer::operator=(strBuf, (const __m128i *)uri);
  p_Paragraphs = &this->Paragraphs;
  Size = this->Paragraphs.Data.Size;
  v6 = 0;
  v67 = 0;
  v7 = 0;
  v65 = Size;
  while ( p_Paragraphs && v6 >= 0 && v6 < (signed int)p_Paragraphs->Data.Size )
  {
    pPara = (int)p_Paragraphs->Data.Data[v6].pPara;
    LODWORD(v) = pPara;
    v66 = v7 + 1;
    if ( v7 + 1 != v65 )
      goto LABEL_15;
    v9 = *(_DWORD *)(pPara + 4);
    v10 = v9 == 0;
    if ( v9 )
    {
      v11 = v9 - 1;
      if ( *(_DWORD *)pPara && v11 < v9 )
        v12 = (_WORD *)(*(_DWORD *)pPara + 2 * v11);
      else
        v12 = 0;
      if ( !*v12 )
        --v9;
      v10 = v9 == 0;
    }
    if ( !v10 )
    {
LABEL_15:
      Scaleform::StringBuffer::AppendString(strBuf, (const __m128i *)"<TEXTFORMAT", 0xFFFFFFFF);
      v13 = *(_DWORD *)(pPara + 12);
      v14 = *(_BYTE *)(v13 + 18) >> 2;
      v64 = v13;
      if ( (v14 & 1) != 0 )
      {
        v58 = (Scaleform::Render::Text::TextFormat *)*(__int16 *)(v13 + 10);
        r.Type = tStrBuffer;
        r.SinkData.pStr = (Scaleform::String *)strBuf;
        Scaleform::MsgFormat::MsgFormat(&v87, &r);
        Scaleform::MsgFormat::Parse(&v87, " INDENT=\"{0}\"");
        Scaleform::MsgFormat::FormatD1<int>(&v87, (int *)&v58);
        Scaleform::MsgFormat::FinishFormatD(&v87);
        Scaleform::MsgFormat::~MsgFormat(&v87);
      }
      if ( (*(_BYTE *)(v13 + 18) & 2) != 0 )
      {
        v58 = (Scaleform::Render::Text::TextFormat *)*(unsigned __int16 *)(v13 + 8);
        v85.Type = tStrBuffer;
        v85.SinkData.pStr = (Scaleform::String *)strBuf;
        Scaleform::MsgFormat::MsgFormat(&v87, &v85);
        Scaleform::MsgFormat::Parse(&v87, " BLOCKINDENT=\"{0}\"");
        Scaleform::MsgFormat::FormatD1<unsigned int>(&v87, (unsigned int *)&v58);
        Scaleform::MsgFormat::FinishFormatD(&v87);
        Scaleform::MsgFormat::~MsgFormat(&v87);
      }
      if ( (*(_BYTE *)(v13 + 18) & 0x10) != 0 )
      {
        v58 = (Scaleform::Render::Text::TextFormat *)*(unsigned __int16 *)(v13 + 14);
        v70.Type = tStrBuffer;
        v70.SinkData.pStr = (Scaleform::String *)strBuf;
        Scaleform::MsgFormat::MsgFormat(&v87, &v70);
        Scaleform::MsgFormat::Parse(&v87, " LEFTMARGIN=\"{0}\"");
        Scaleform::MsgFormat::FormatD1<unsigned int>(&v87, (unsigned int *)&v58);
        Scaleform::MsgFormat::FinishFormatD(&v87);
        Scaleform::MsgFormat::~MsgFormat(&v87);
      }
      if ( (*(_BYTE *)(v13 + 18) & 0x20) != 0 )
      {
        v58 = (Scaleform::Render::Text::TextFormat *)*(unsigned __int16 *)(v13 + 16);
        v86.Type = tStrBuffer;
        v86.SinkData.pStr = (Scaleform::String *)strBuf;
        Scaleform::MsgFormat::MsgFormat(&v87, &v86);
        Scaleform::MsgFormat::Parse(&v87, " RIGHTMARGIN=\"{0}\"");
        Scaleform::MsgFormat::FormatD1<unsigned int>(&v87, (unsigned int *)&v58);
        Scaleform::MsgFormat::FinishFormatD(&v87);
        Scaleform::MsgFormat::~MsgFormat(&v87);
      }
      if ( (*(_BYTE *)(v13 + 18) & 8) != 0 )
      {
        v58 = (Scaleform::Render::Text::TextFormat *)*(__int16 *)(v13 + 12);
        v68.Type = tStrBuffer;
        v68.SinkData.pStr = (Scaleform::String *)strBuf;
        Scaleform::MsgFormat::MsgFormat(&v87, &v68);
        Scaleform::MsgFormat::Parse(&v87, " LEADING=\"{0}\"");
        Scaleform::MsgFormat::FormatD1<int>(&v87, (int *)&v58);
        Scaleform::MsgFormat::FinishFormatD(&v87);
        Scaleform::MsgFormat::~MsgFormat(&v87);
      }
      if ( (*(_BYTE *)(v13 + 18) & 0x40) != 0 )
      {
        Scaleform::StringBuffer::AppendString(strBuf, (const __m128i *)" TABSTOPS=\"", 0xFFFFFFFF);
        TabStops = Scaleform::Render::Text::ParagraphFormat::GetTabStops(
                     (Scaleform::Render::Text::ParagraphFormat *)v13,
                     &v61);
        if ( v61 )
        {
          v16 = TabStops;
          do
          {
            LOBYTE(v56) = v3 != 0;
            v80.Type = tStrBuffer;
            v80.SinkData.pStr = (Scaleform::String *)strBuf;
            Scaleform::MsgFormat::MsgFormat(&v87, &v80);
            Scaleform::MsgFormat::Parse(&v87, "{0:sw:,:}{1}");
            Scaleform::MsgFormat::FormatD1<bool>(&v87, (bool *)&v56);
            Scaleform::MsgFormat::FormatD1<unsigned int>(&v87, v16);
            Scaleform::MsgFormat::FinishFormatD(&v87);
            Scaleform::MsgFormat::~MsgFormat(&v87);
            ++v3;
            ++v16;
          }
          while ( v3 < v61 );
        }
        Scaleform::StringBuffer::AppendString(strBuf, (const __m128i *)"\"", 0xFFFFFFFF);
        pPara = v;
      }
      Scaleform::StringBuffer::AppendString(strBuf, (const __m128i *)"><", 0xFFFFFFFF);
      if ( (*(_WORD *)(v13 + 18) & 0x80u) != 0 && (*(_WORD *)(v13 + 18) & 0x8000) != 0 )
        Scaleform::StringBuffer::AppendString(strBuf, (const __m128i *)"LI", 0xFFFFFFFF);
      else
        Scaleform::StringBuffer::AppendString(strBuf, (const __m128i *)"P", 0xFFFFFFFF);
      Scaleform::StringBuffer::AppendString(strBuf, (const __m128i *)" ALIGN=\"", 0xFFFFFFFF);
      switch ( (*(unsigned __int16 *)(v13 + 18) >> 9) & 3 )
      {
        case 0:
          Scaleform::StringBuffer::AppendString(strBuf, (const __m128i *)"LEFT", 0xFFFFFFFF);
          break;
        case 1:
          Scaleform::StringBuffer::AppendString(strBuf, (const __m128i *)"RIGHT", 0xFFFFFFFF);
          break;
        case 2:
          Scaleform::StringBuffer::AppendString(strBuf, (const __m128i *)"JUSTIFY", 0xFFFFFFFF);
          break;
        case 3:
          Scaleform::StringBuffer::AppendString(strBuf, (const __m128i *)"CENTER", 0xFFFFFFFF);
          break;
        default:
          break;
      }
      Scaleform::StringBuffer::AppendString(strBuf, (const __m128i *)"\">", 0xFFFFFFFF);
      memset(&v63, 0, 16);
      v63.pFormatInfo = (const Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> >,2,Scaleform::ArrayDefaultPolicy> > *)(pPara + 16);
      v63.FormatIterator.pArray = (const Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> >,2,Scaleform::ArrayDefaultPolicy> > *)(pPara + 16);
      v63.FormatIterator.Index = 0;
      v63.pText = (const Scaleform::Render::Text::Paragraph::TextBuffer *)pPara;
      v63.CurTextIndex = 0;
      v58 = 0;
      LOBYTE(v56) = 0;
      if ( *(_DWORD *)(pPara + 4) )
      {
        while ( 1 )
        {
          v17 = Scaleform::Render::Text::Paragraph::FormatRunIterator::operator*(&v63);
          pObject = v17->PlaceHolder.pFormat.pObject;
          if ( pObject )
            break;
LABEL_101:
          v38 = 0;
          if ( v17->PlaceHolder.Length )
          {
            v39 = v60;
            do
            {
              v40 = v17->PlaceHolder.pText[v38];
              if ( v40 != (unsigned __int8)((v39->RTFlags & 2) != 0 ? 13 : 10) && v40 )
              {
                switch ( v40 )
                {
                  case 0x22u:
                    Scaleform::StringBuffer::AppendString(strBuf, (const __m128i *)aQuo, 0xFFFFFFFF);
                    break;
                  case 0x26u:
                    Scaleform::StringBuffer::AppendString(strBuf, (const __m128i *)aAmp_3, 0xFFFFFFFF);
                    break;
                  case 0x27u:
                    Scaleform::StringBuffer::AppendString(strBuf, (const __m128i *)aApo, 0xFFFFFFFF);
                    break;
                  case 0x3Cu:
                    Scaleform::StringBuffer::AppendString(strBuf, (const __m128i *)"&lt;", 0xFFFFFFFF);
                    break;
                  case 0x3Eu:
                    Scaleform::StringBuffer::AppendString(strBuf, (const __m128i *)"&gt;", 0xFFFFFFFF);
                    break;
                  case 0xA0u:
                    Scaleform::StringBuffer::AppendString(strBuf, (const __m128i *)"&nbsp;", 0xFFFFFFFF);
                    break;
                  default:
                    Scaleform::StringBuffer::AppendChar(strBuf, v40);
                    break;
                }
              }
              ++v38;
            }
            while ( v38 < v17->PlaceHolder.Length );
          }
          v41 = v17->PlaceHolder.pFormat.pObject;
          if ( v41 )
          {
            if ( (v41->FormatFlags & 4) != 0 )
              Scaleform::StringBuffer::AppendString(strBuf, (const __m128i *)"</U>", 0xFFFFFFFF);
            if ( (v17->PlaceHolder.pFormat.pObject->FormatFlags & 2) != 0 )
              Scaleform::StringBuffer::AppendString(strBuf, (const __m128i *)"</I>", 0xFFFFFFFF);
            if ( (v17->PlaceHolder.pFormat.pObject->FormatFlags & 1) != 0 )
              Scaleform::StringBuffer::AppendString(strBuf, (const __m128i *)"</B>", 0xFFFFFFFF);
            v42 = v17->PlaceHolder.pFormat.pObject;
            if ( (v42->PresentMask & 0x100) != 0 && Scaleform::String::GetLength(&v42->Url) )
              Scaleform::StringBuffer::AppendString(strBuf, (const __m128i *)"</A>", 0xFFFFFFFF);
          }
LABEL_124:
          if ( v63.FormatIterator.Index < 0 || v63.FormatIterator.Index >= v63.FormatIterator.pArray->Ranges.Data.Size )
          {
            Index = v63.pText->Size;
          }
          else
          {
            v43 = &v63.FormatIterator.pArray->Ranges.Data.Data[v63.FormatIterator.Index];
            if ( v63.CurTextIndex >= v43->Index )
            {
              Index = v43->Length + v63.CurTextIndex;
              v63.CurTextIndex = Index;
              if ( v63.FormatIterator.Index < (signed int)v63.FormatIterator.pArray->Ranges.Data.Size )
                ++v63.FormatIterator.Index;
              goto LABEL_132;
            }
            Index = v63.FormatIterator.pArray->Ranges.Data.Data[v63.FormatIterator.Index].Index;
          }
          v63.CurTextIndex = Index;
LABEL_132:
          if ( Index >= v63.pText->Size )
          {
            if ( (_BYTE)v56 )
              Scaleform::StringBuffer::AppendString(strBuf, (const __m128i *)"</FONT>", 0xFFFFFFFF);
            goto LABEL_135;
          }
        }
        if ( (pObject->PresentMask & 0x200) != 0 )
        {
          v19 = v62;
          p_pObject = &pObject->pImageDesc.pObject;
        }
        else
        {
          v59 |= 1u;
          v19 = 0;
          v62 = 0;
          p_pObject = &v62;
        }
        v21 = *p_pObject;
        if ( (v59 & 1) != 0 )
        {
          v59 &= ~1u;
          if ( v19 )
            Scaleform::RefCountNTSImpl::Release(v19);
        }
        if ( v21 )
        {
          ++v21->RefCount;
          v22 = v17->PlaceHolder.pFormat.pObject;
          if ( (v22->PresentMask & 0x100) != 0 && Scaleform::String::GetLength(&v22->Url) )
          {
            v23 = (const Scaleform::StringLH *)v17->PlaceHolder.pFormat.pObject;
            v74.Type = tStrBuffer;
            v74.SinkData.pStr = (Scaleform::String *)strBuf;
            Scaleform::MsgFormat::MsgFormat(&v87, &v74);
            Scaleform::MsgFormat::Parse(&v87, "<A HREF=\"{0}\">");
            Scaleform::MsgFormat::FormatD1<Scaleform::StringLH>(&v87, v23 + 3);
            Scaleform::MsgFormat::FinishFormatD(&v87);
            Scaleform::MsgFormat::~MsgFormat(&v87);
          }
          Scaleform::StringBuffer::AppendString(strBuf, (const __m128i *)"<IMG SRC=\"", 0xFFFFFFFF);
          Scaleform::StringBuffer::AppendString(
            strBuf,
            (const __m128i *)(((int)v21[8].__vftable & 0xFFFFFFFC) + 8),
            *(_DWORD *)((int)v21[8].__vftable & 0xFFFFFFFC) & 0x7FFFFFFF);
          Scaleform::StringBuffer::AppendString(strBuf, (const __m128i *)"\"", 0xFFFFFFFF);
          if ( *(float *)&v21[2].RefCount > 0.0 )
          {
            *(float *)&v = *(float *)&v21[2].RefCount * 0.05000000074505806;
            LODWORD(v) = (int)*(float *)&v;
            v84.Type = tStrBuffer;
            v84.SinkData.pStr = (Scaleform::String *)strBuf;
            Scaleform::MsgFormat::MsgFormat(&v87, &v84);
            Scaleform::MsgFormat::Parse(&v87, " WIDTH=\"{0}\"");
            Scaleform::MsgFormat::FormatD1<int>(&v87, (int *)&v);
            Scaleform::MsgFormat::FinishFormatD(&v87);
            Scaleform::MsgFormat::~MsgFormat(&v87);
          }
          if ( *(float *)&v21[3].__vftable > 0.0 )
          {
            *(float *)&v = *(float *)&v21[3].__vftable * 0.05000000074505806;
            LODWORD(v) = (int)*(float *)&v;
            v76.Type = tStrBuffer;
            v76.SinkData.pStr = (Scaleform::String *)strBuf;
            Scaleform::MsgFormat::MsgFormat(&v87, &v76);
            Scaleform::MsgFormat::Parse(&v87, " HEIGHT=\"{0}\"");
            Scaleform::MsgFormat::FormatD1<int>(&v87, (int *)&v);
            Scaleform::MsgFormat::FinishFormatD(&v87);
            Scaleform::MsgFormat::~MsgFormat(&v87);
          }
          v24 = v21[9].__vftable;
          if ( v24 )
          {
            LODWORD(v) = (int)v24 / 20;
            v82.Type = tStrBuffer;
            v82.SinkData.pStr = (Scaleform::String *)strBuf;
            Scaleform::MsgFormat::MsgFormat(&v87, &v82);
            Scaleform::MsgFormat::Parse(&v87, " VSPACE=\"{0}\"");
            Scaleform::MsgFormat::FormatD1<int>(&v87, (int *)&v);
            Scaleform::MsgFormat::FinishFormatD(&v87);
            Scaleform::MsgFormat::~MsgFormat(&v87);
          }
          RefCount = v21[9].RefCount;
          if ( RefCount )
          {
            LODWORD(v) = RefCount / 20;
            v78.Type = tStrBuffer;
            v78.SinkData.pStr = (Scaleform::String *)strBuf;
            Scaleform::MsgFormat::MsgFormat(&v87, &v78);
            Scaleform::MsgFormat::Parse(&v87, " HSPACE=\"{0}\"");
            Scaleform::MsgFormat::FormatD1<int>(&v87, (int *)&v);
            Scaleform::MsgFormat::FinishFormatD(&v87);
            Scaleform::MsgFormat::~MsgFormat(&v87);
          }
          if ( (*(_DWORD *)(v21[8].RefCount & 0xFFFFFFFC) & 0x7FFFFFFF) != 0 )
          {
            v69.Type = tStrBuffer;
            v69.SinkData.pStr = (Scaleform::String *)strBuf;
            Scaleform::MsgFormat::MsgFormat(&v87, &v69);
            Scaleform::MsgFormat::Parse(&v87, " ID=\"{0}\"");
            Scaleform::MsgFormat::FormatD1<Scaleform::StringLH>(&v87, (const Scaleform::StringLH *)&v21[8].RefCount);
            Scaleform::MsgFormat::FinishFormatD(&v87);
            Scaleform::MsgFormat::~MsgFormat(&v87);
          }
          Scaleform::StringBuffer::AppendString(strBuf, (const __m128i *)" ALIGN=\"", 0xFFFFFFFF);
          if ( LOBYTE(v21[10].RefCount) )
          {
            if ( LOBYTE(v21[10].RefCount) == 1 )
            {
              Scaleform::StringBuffer::AppendString(strBuf, (const __m128i *)"right", 0xFFFFFFFF);
            }
            else if ( LOBYTE(v21[10].RefCount) == 2 )
            {
              Scaleform::StringBuffer::AppendString(strBuf, (const __m128i *)"left", 0xFFFFFFFF);
            }
          }
          else
          {
            Scaleform::StringBuffer::AppendString(strBuf, (const __m128i *)"baseline", 0xFFFFFFFF);
          }
          Scaleform::StringBuffer::AppendString(strBuf, (const __m128i *)"\">", 0xFFFFFFFF);
          v26 = v17->PlaceHolder.pFormat.pObject;
          if ( (v26->PresentMask & 0x100) != 0 && Scaleform::String::GetLength(&v26->Url) )
            Scaleform::StringBuffer::AppendString(strBuf, (const __m128i *)"</A>", 0xFFFFFFFF);
          Scaleform::RefCountNTSImpl::Release(v21);
          goto LABEL_124;
        }
        v27 = v58;
        if ( (_BYTE)v56 )
        {
          if ( v58 && !Scaleform::Render::Text::TextFormat::IsHTMLFontTagSame(v58, v17->PlaceHolder.pFormat.pObject) )
          {
            Scaleform::StringBuffer::AppendString(strBuf, (const __m128i *)"</FONT>", 0xFFFFFFFF);
            goto LABEL_75;
          }
        }
        else
        {
LABEL_75:
          Scaleform::StringBuffer::AppendString(strBuf, (const __m128i *)"<FONT", 0xFFFFFFFF);
          v28 = v17->PlaceHolder.pFormat.pObject;
          if ( (v28->PresentMask & 4) != 0 )
          {
            v71.Type = tStrBuffer;
            v71.SinkData.pStr = (Scaleform::String *)strBuf;
            FontList = Scaleform::Render::Text::TextFormat::GetFontList(v28);
            Scaleform::MsgFormat::MsgFormat(&v87, &v71);
            Scaleform::MsgFormat::Parse(&v87, " FACE=\"{0}\"");
            Scaleform::MsgFormat::FormatD1<Scaleform::StringLH>(&v87, (const Scaleform::StringLH *)FontList);
            Scaleform::MsgFormat::FinishFormatD(&v87);
            Scaleform::MsgFormat::~MsgFormat(&v87);
          }
          v30 = v17->PlaceHolder.pFormat.pObject;
          if ( (v30->PresentMask & 8) != 0 )
          {
            LODWORD(v) = v30->FontSize;
            v73.Type = tStrBuffer;
            *(float *)&v = (double)(int)v * 0.05000000074505806;
            v73.SinkData.pStr = (Scaleform::String *)strBuf;
            v = (__int64)*(float *)&v;
            Scaleform::MsgFormat::MsgFormat(&v87, &v73);
            Scaleform::MsgFormat::Parse(&v87, " SIZE=\"{0}\"");
            Scaleform::MsgFormat::FormatD1<unsigned int>(&v87, (unsigned int *)&v);
            Scaleform::MsgFormat::FinishFormatD(&v87);
            Scaleform::MsgFormat::~MsgFormat(&v87);
          }
          v31 = v17->PlaceHolder.pFormat.pObject;
          if ( (v31->PresentMask & 1) != 0 )
          {
            LODWORD(v) = v31->ColorV & 0xFFFFFF;
            v75.Type = tStrBuffer;
            v75.SinkData.pStr = (Scaleform::String *)strBuf;
            Scaleform::MsgFormat::MsgFormat(&v87, &v75);
            Scaleform::MsgFormat::Parse(&v87, " COLOR=\"#{0:X:.6}\"");
            Scaleform::MsgFormat::FormatD1<unsigned int>(&v87, (unsigned int *)&v);
            Scaleform::MsgFormat::FinishFormatD(&v87);
            Scaleform::MsgFormat::~MsgFormat(&v87);
          }
          v32 = v17->PlaceHolder.pFormat.pObject;
          if ( (v32->PresentMask & 2) != 0 )
          {
            v33 = (double)(v32->LetterSpacing / 20);
            v77.Type = tStrBuffer;
            *(float *)&v = v33;
            v77.SinkData.pStr = (Scaleform::String *)strBuf;
            Scaleform::MsgFormat::MsgFormat(&v87, &v77);
            Scaleform::MsgFormat::Parse(&v87, " LETTERSPACING=\"{0}\"");
            Scaleform::MsgFormat::FormatD1<float>(&v87, (const float *)&v);
            Scaleform::MsgFormat::FinishFormatD(&v87);
            Scaleform::MsgFormat::~MsgFormat(&v87);
          }
          v34 = v17->PlaceHolder.pFormat.pObject;
          if ( (v34->PresentMask & 0x400) != 0 )
          {
            LODWORD(v) = HIBYTE(v34->ColorV);
            v79.Type = tStrBuffer;
            v79.SinkData.pStr = (Scaleform::String *)strBuf;
            Scaleform::MsgFormat::MsgFormat(&v87, &v79);
            Scaleform::MsgFormat::Parse(&v87, " ALPHA=\"#{0:X:.2}\"");
            Scaleform::MsgFormat::FormatD1<unsigned int>(&v87, (unsigned int *)&v);
            Scaleform::MsgFormat::FinishFormatD(&v87);
            Scaleform::MsgFormat::~MsgFormat(&v87);
          }
          LOBYTE(v56) = (v17->PlaceHolder.pFormat.pObject->FormatFlags & 8) != 0;
          v81.Type = tStrBuffer;
          v81.SinkData.pStr = (Scaleform::String *)strBuf;
          Scaleform::MsgFormat::MsgFormat(&v87, &v81);
          Scaleform::MsgFormat::Parse(&v87, " KERNING=\"{0:sw:1:0}\"");
          Scaleform::MsgFormat::FormatD1<bool>(&v87, (bool *)&v56);
          Scaleform::MsgFormat::FinishFormatD(&v87);
          Scaleform::MsgFormat::~MsgFormat(&v87);
          Scaleform::StringBuffer::AppendString(strBuf, (const __m128i *)">", 0xFFFFFFFF);
          LOBYTE(v56) = 1;
        }
        v35 = v17->PlaceHolder.pFormat.pObject;
        if ( (v35->PresentMask & 0x100) != 0 && Scaleform::String::GetLength(&v35->Url) )
        {
          v36 = (const Scaleform::StringLH *)v17->PlaceHolder.pFormat.pObject;
          v83.Type = tStrBuffer;
          v83.SinkData.pStr = (Scaleform::String *)strBuf;
          Scaleform::MsgFormat::MsgFormat(&v87, &v83);
          Scaleform::MsgFormat::Parse(&v87, "<A HREF=\"{0}\">");
          Scaleform::MsgFormat::FormatD1<Scaleform::StringLH>(&v87, v36 + 3);
          Scaleform::MsgFormat::FinishFormatD(&v87);
          Scaleform::MsgFormat::~MsgFormat(&v87);
        }
        if ( (v17->PlaceHolder.pFormat.pObject->FormatFlags & 1) != 0 )
          Scaleform::StringBuffer::AppendString(strBuf, (const __m128i *)"<B>", 0xFFFFFFFF);
        if ( (v17->PlaceHolder.pFormat.pObject->FormatFlags & 2) != 0 )
          Scaleform::StringBuffer::AppendString(strBuf, (const __m128i *)"<I>", 0xFFFFFFFF);
        if ( (v17->PlaceHolder.pFormat.pObject->FormatFlags & 4) != 0 )
          Scaleform::StringBuffer::AppendString(strBuf, (const __m128i *)"<U>", 0xFFFFFFFF);
        v37 = v17->PlaceHolder.pFormat.pObject;
        if ( v37 )
          ++v37->RefCount;
        if ( v27 )
        {
          v10 = v27->RefCount-- == 1;
          if ( v10 )
          {
            Scaleform::Render::Text::TextFormat::~TextFormat(v27);
            Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v27);
          }
        }
        v58 = v17->PlaceHolder.pFormat.pObject;
        goto LABEL_101;
      }
LABEL_135:
      Scaleform::StringBuffer::AppendString(strBuf, (const __m128i *)"</", 0xFFFFFFFF);
      if ( (*(_WORD *)(v64 + 18) & 0x80u) != 0 && (*(_WORD *)(v64 + 18) & 0x8000) != 0 )
        Scaleform::StringBuffer::AppendString(strBuf, (const __m128i *)"LI", 0xFFFFFFFF);
      else
        Scaleform::StringBuffer::AppendString(strBuf, (const __m128i *)"P", 0xFFFFFFFF);
      Scaleform::StringBuffer::AppendString(strBuf, (const __m128i *)"></TEXTFORMAT>", 0xFFFFFFFF);
      v45 = v58;
      if ( v58 )
      {
        v10 = v58->RefCount-- == 1;
        if ( v10 )
        {
          v46 = (Scaleform::RefCountVImpl *)v45->pFontHandle.pObject;
          if ( v46 )
            Scaleform::RefCountImpl::Release(v46);
          v47 = v45->pImageDesc.pObject;
          if ( v47 )
            Scaleform::RefCountNTSImpl::Release(v47);
          v48 = (volatile LONG *)(v45->Url.HeapTypeBits & 0xFFFFFFFC);
          if ( InterlockedExchangeAdd(v48 + 1, -1) == 1 )
            Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v48);
          v49 = (volatile LONG *)(v45->FontList.HeapTypeBits & 0xFFFFFFFC);
          if ( InterlockedExchangeAdd(v49 + 1, -1) == 1 )
            Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v49);
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v45);
        }
      }
      v50 = v63.PlaceHolder.pFormat.pObject;
      if ( v63.PlaceHolder.pFormat.pObject )
      {
        --v63.PlaceHolder.pFormat.pObject->RefCount;
        if ( !v50->RefCount )
        {
          v51 = (Scaleform::RefCountVImpl *)v50->pFontHandle.pObject;
          if ( v51 )
            Scaleform::RefCountImpl::Release(v51);
          v52 = v50->pImageDesc.pObject;
          if ( v52 )
            Scaleform::RefCountNTSImpl::Release(v52);
          v53 = (volatile LONG *)(v50->Url.HeapTypeBits & 0xFFFFFFFC);
          if ( InterlockedExchangeAdd(v53 + 1, -1) == 1 )
            Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v53);
          v54 = (volatile LONG *)(v50->FontList.HeapTypeBits & 0xFFFFFFFC);
          if ( InterlockedExchangeAdd(v54 + 1, -1) == 1 )
            Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v54);
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v50);
        }
      }
    }
    v6 = v67;
    p_Paragraphs = &v60->Paragraphs;
    if ( v67 < (signed int)v60->Paragraphs.Data.Size )
      v6 = ++v67;
    v7 = v66;
    v3 = 0;
  }
  return strBuf;
}


Scaleform::String *__thiscall Scaleform::Render::Text::StyledText::GetHtml(
        Scaleform::Render::Text::StyledText *this,
        Scaleform::String *result)
{
  const Scaleform::StringBuffer *Html; // eax
  Scaleform::StringBuffer strBuf; // [esp+4h] [ebp-18h] BYREF

  Scaleform::StringBuffer::StringBuffer(&strBuf, Scaleform::Memory::pGlobalHeap);
  Html = Scaleform::Render::Text::StyledText::GetHtml(this, &strBuf);
  Scaleform::String::String(result, Html);
  Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>::~Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>((Scaleform::Array<char,2,Scaleform::ArrayDefaultPolicy> *)&strBuf);
  return result;
}
