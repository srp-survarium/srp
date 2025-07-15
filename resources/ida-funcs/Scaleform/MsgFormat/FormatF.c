void __thiscall Scaleform::MsgFormat::FormatF(
        Scaleform::MsgFormat *this,
        const Scaleform::StringDataPtr *fmt,
        char *argList)
{
  unsigned int Size; // eax
  const char *pStr; // edx
  unsigned int v5; // esi
  int v6; // ebx
  char *v7; // ebp
  char *v8; // edi
  int v9; // eax
  unsigned int v10; // ecx
  unsigned int v11; // ecx
  unsigned int v12; // edx
  const char *v; // esi
  int v14; // eax
  long double v15; // st7
  char *v16; // eax
  int v17; // eax
  int v18; // esi
  int v19; // eax
  Scaleform::StringDataPtr *p_attr; // eax
  unsigned int v21; // eax
  char *v22; // eax
  int v23; // eax
  int v24; // eax
  char *v25; // eax
  int v26; // eax
  char *v27; // eax
  Scaleform::Formatter *v28; // eax
  unsigned int v29; // ecx
  unsigned int prefix_size; // [esp+1Ch] [ebp-4Ch]
  unsigned int upos; // [esp+20h] [ebp-48h]
  char base; // [esp+24h] [ebp-44h]
  Scaleform::DoubleFormatter::PresentationType dpType; // [esp+28h] [ebp-40h]
  unsigned int startPos; // [esp+2Ch] [ebp-3Ch]
  Scaleform::MsgFormat::FormatF::__l17::DataType data; // [esp+30h] [ebp-38h]
  Scaleform::StringDataPtr cur_fmt; // [esp+38h] [ebp-30h] BYREF
  Scaleform::StringDataPtr str; // [esp+40h] [ebp-28h] BYREF
  Scaleform::StringDataPtr attr; // [esp+48h] [ebp-20h] BYREF
  _DWORD v40[2]; // [esp+50h] [ebp-18h] BYREF
  _DWORD v41[2]; // [esp+58h] [ebp-10h] BYREF
  Scaleform::StringDataPtr v42; // [esp+60h] [ebp-8h] BYREF
  char unsigned_type; // [esp+6Ch] [ebp+4h]
  char bigLetters; // [esp+70h] [ebp+8h]

  Size = fmt->Size;
  if ( Size )
  {
    pStr = fmt->pStr;
    v5 = fmt->Size;
    cur_fmt.pStr = fmt->pStr;
    cur_fmt.Size = Size;
    v6 = 0;
    v7 = argList - 8;
    v8 = argList - 4;
    while ( 1 )
    {
      v9 = 0;
      while ( pStr[v9] != 37 )
      {
        if ( ++v9 >= v5 )
          goto LABEL_6;
      }
      if ( v9 < 0 )
        break;
      upos = v9;
      if ( v5 <= v9 + 1 )
      {
        Scaleform::MsgFormat::AddStringRecord(this, &cur_fmt);
      }
      else
      {
        upos = v9 + 1;
        if ( pStr[v9 + 1] != 37 )
        {
          base = 10;
          bigLetters = 0;
          unsigned_type = 0;
          dpType = FmtDecimal;
          v10 = v5 - v9;
          if ( v5 < v9 )
            v10 = v5;
          str.pStr = pStr;
          str.Size = v5 - v10;
          Scaleform::MsgFormat::AddStringRecord(this, &str);
          v11 = upos;
          v12 = upos;
          v = 0;
          v14 = 0;
          startPos = upos;
          data.v_sint = 0;
          prefix_size = 0;
          if ( upos < cur_fmt.Size )
          {
            while ( 2 )
            {
              switch ( cur_fmt.pStr[v12] )
              {
                case 'E':
                  bigLetters = 1;
                  goto $LN20_33;
                case 'G':
                  bigLetters = 1;
                  goto $LN18_36;
                case 'I':
                  v14 = 3;
                  goto LABEL_21;
                case 'X':
                  bigLetters = 1;
                  goto $LN23_21;
                case 'd':
                case 'i':
                  v8 += 4;
                  v7 += 4;
                  if ( v14 == 2 )
                  {
                    v6 = 2;
                    v = *(const char **)v8;
                    data.v_sint64 = *(int *)v8;
                  }
                  else
                  {
                    v = *(const char **)v8;
                    v6 = 1;
                    data.v_sint = *(_DWORD *)v8;
                  }
                  break;
                case 'e':
$LN20_33:
                  dpType = FmtScientific;
                  goto LABEL_43;
                case 'f':
                  dpType = FmtDecimal;
                  goto LABEL_43;
                case 'g':
$LN18_36:
                  dpType = FmtSignificant;
LABEL_43:
                  v15 = *((double *)v7 + 1);
                  v8 += 8;
                  v7 += 8;
                  data.v_double = v15;
                  v = (const char *)data.v_sint;
                  v6 = 3;
                  break;
                case 'h':
                  v14 = 1;
                  goto LABEL_21;
                case 'l':
                  v14 = 2;
LABEL_21:
                  ++prefix_size;
                  goto LABEL_22;
                case 'n':
                  v = (const char *)**((_DWORD **)v8 + 1);
                  v8 += 4;
                  v6 = 1;
                  v7 += 4;
                  data.v_sint = (int)v;
                  break;
                case 'o':
                  v = (const char *)*((_DWORD *)v8 + 1);
                  v8 += 4;
                  v6 = 1;
                  base = 8;
                  unsigned_type = 1;
                  v7 += 4;
                  data.v_sint = (int)v;
                  break;
                case 'p':
                  v = (const char *)**((_DWORD **)v8 + 1);
                  v8 += 4;
                  v6 = 1;
                  unsigned_type = 1;
                  v7 += 4;
                  data.v_sint = (int)v;
                  base = 16;
                  break;
                case 's':
                  v6 = 4;
                  v = (const char *)*((_DWORD *)v8 + 1);
                  v8 += 4;
                  v7 += 4;
                  data.v_sint = (int)v;
                  break;
                case 'u':
                  v = (const char *)*((_DWORD *)v8 + 1);
                  v8 += 4;
                  v7 += 4;
                  data.v_sint = (int)v;
                  if ( v14 == 2 )
                    v6 = 2;
                  else
                    v6 = 1;
                  unsigned_type = 1;
                  break;
                case 'x':
$LN23_21:
                  v = (const char *)*((_DWORD *)v8 + 1);
                  v8 += 4;
                  v6 = 1;
                  unsigned_type = 1;
                  v7 += 4;
                  data.v_sint = (int)v;
                  base = 16;
                  break;
                default:
LABEL_22:
                  if ( v6 )
                    break;
                  upos = ++v12;
                  if ( v12 >= cur_fmt.Size )
                    break;
                  continue;
              }
              break;
            }
          }
          switch ( v6 )
          {
            case 1:
              attr.pStr = &cur_fmt.pStr[v11];
              attr.Size = upos - prefix_size - v11;
              v16 = Scaleform::StackMemPool<512,4,Scaleform::MemPoolImmediateFree>::Alloc(&this->MemPool, 0x50u);
              if ( unsigned_type )
              {
                if ( v16 )
                {
                  Scaleform::LongFormatter::LongFormatter((Scaleform::LongFormatter *)v16, (unsigned int)v);
                  v18 = v17;
LABEL_51:
                  *(_DWORD *)(v18 + 28) ^= ((unsigned __int8)base ^ (unsigned __int8)*(_DWORD *)(v18 + 28)) & 0x1F;
                  p_attr = &attr;
                  goto LABEL_52;
                }
              }
              else if ( v16 )
              {
                Scaleform::LongFormatter::LongFormatter((Scaleform::LongFormatter *)v16, (int)v);
                v18 = v19;
                goto LABEL_51;
              }
              v18 = 0;
              goto LABEL_51;
            case 2:
              v40[0] = &cur_fmt.pStr[v11];
              v40[1] = upos - prefix_size - v11;
              v22 = Scaleform::StackMemPool<512,4,Scaleform::MemPoolImmediateFree>::Alloc(&this->MemPool, 0x50u);
              if ( unsigned_type )
              {
                if ( v22 )
                {
                  Scaleform::LongFormatter::LongFormatter(
                    (Scaleform::LongFormatter *)v22,
                    __SPAIR64__(HIDWORD(data.v_uint64), (unsigned int)v));
                  v18 = v23;
                  *(_DWORD *)(v23 + 28) ^= ((unsigned __int8)base ^ (unsigned __int8)*(_DWORD *)(v23 + 28)) & 0x1F;
                  p_attr = (Scaleform::StringDataPtr *)v40;
                  goto LABEL_52;
                }
              }
              else if ( v22 )
              {
                Scaleform::LongFormatter::LongFormatter(
                  (Scaleform::LongFormatter *)v22,
                  __SPAIR64__(HIDWORD(data.v_uint64), (unsigned int)v));
                v18 = v24;
                *(_DWORD *)(v24 + 28) ^= ((unsigned __int8)base ^ (unsigned __int8)*(_DWORD *)(v24 + 28)) & 0x1F;
                p_attr = (Scaleform::StringDataPtr *)v40;
                goto LABEL_52;
              }
              v18 = 0;
              MEMORY[0x1C] ^= ((unsigned __int8)base ^ MEMORY[0x1C]) & 0x1F;
              p_attr = (Scaleform::StringDataPtr *)v40;
LABEL_52:
              *(_BYTE *)(v18 + 22) ^= (bigLetters ^ *(_BYTE *)(v18 + 22)) & 1;
LABEL_53:
              (*(void (__thiscall **)(int, Scaleform::StringDataPtr *))(*(_DWORD *)v18 + 8))(v18, p_attr);
              Scaleform::MsgFormat::AddFormatterRecord(this, (Scaleform::Formatter *)v18, 1);
LABEL_54:
              v5 = cur_fmt.Size;
              goto LABEL_55;
            case 3:
              v25 = Scaleform::StackMemPool<512,4,Scaleform::MemPoolImmediateFree>::Alloc(&this->MemPool, 0x188u);
              if ( v25 )
              {
                Scaleform::DoubleFormatter::DoubleFormatter((Scaleform::DoubleFormatter *)v25, data.v_double);
                v18 = v26;
              }
              else
              {
                v18 = 0;
              }
              v41[0] = &cur_fmt.pStr[startPos];
              v41[1] = upos - startPos;
              *(_BYTE *)(v18 + 22) ^= (bigLetters ^ *(_BYTE *)(v18 + 22)) & 1;
              *(_DWORD *)(v18 + 28) = dpType;
              p_attr = (Scaleform::StringDataPtr *)v41;
              goto LABEL_53;
            case 4:
              v27 = Scaleform::StackMemPool<512,4,Scaleform::MemPoolImmediateFree>::Alloc(&this->MemPool, 0x14u);
              if ( v27 )
              {
                Scaleform::StrFormatter::StrFormatter((Scaleform::StrFormatter *)v27, v);
                Scaleform::MsgFormat::AddFormatterRecord(this, v28, 1);
              }
              else
              {
                Scaleform::MsgFormat::AddFormatterRecord(this, 0, 1);
              }
              goto LABEL_54;
            default:
              goto LABEL_54;
          }
        }
        v29 = v5 - v9 - 1;
        if ( v5 < v29 )
          v29 = v5;
        v42.pStr = pStr;
        v42.Size = v5 - v29;
        Scaleform::MsgFormat::AddStringRecord(this, &v42);
      }
LABEL_55:
      v21 = upos + 1;
      if ( v5 < upos + 1 )
        v21 = v5;
      cur_fmt.pStr += v21;
      v5 -= v21;
      cur_fmt.Size = v5;
      if ( !v5 )
        goto LABEL_7;
      pStr = cur_fmt.pStr;
    }
LABEL_6:
    Scaleform::MsgFormat::AddStringRecord(this, &cur_fmt);
LABEL_7:
    Scaleform::MsgFormat::MakeString(this);
  }
}
