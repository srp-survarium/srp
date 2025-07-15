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
  double v15; // st7
  char *v16; // eax
  int v17; // eax
  int v18; // esi
  int v19; // eax
  _DWORD *v20; // eax
  unsigned int v21; // eax
  char *v22; // eax
  int v23; // eax
  int v24; // eax
  char *v25; // eax
  int v26; // eax
  char *v27; // eax
  Scaleform::Formatter *v28; // eax
  unsigned int v29; // ecx
  int v31; // [esp+1Ch] [ebp-4Ch]
  unsigned int v32; // [esp+20h] [ebp-48h]
  char v33; // [esp+24h] [ebp-44h]
  int v34; // [esp+28h] [ebp-40h]
  unsigned int v35; // [esp+2Ch] [ebp-3Ch]
  double v36; // [esp+30h] [ebp-38h]
  Scaleform::StringDataPtr str; // [esp+38h] [ebp-30h] BYREF
  Scaleform::StringDataPtr v38; // [esp+40h] [ebp-28h] BYREF
  _DWORD v39[2]; // [esp+48h] [ebp-20h] BYREF
  _DWORD v40[2]; // [esp+50h] [ebp-18h] BYREF
  _DWORD v41[2]; // [esp+58h] [ebp-10h] BYREF
  Scaleform::StringDataPtr v42; // [esp+60h] [ebp-8h] BYREF
  char v43; // [esp+6Ch] [ebp+4h]
  char v44; // [esp+70h] [ebp+8h]

  Size = fmt->Size;
  if ( Size )
  {
    pStr = fmt->pStr;
    v5 = fmt->Size;
    str.pStr = fmt->pStr;
    str.Size = Size;
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
      v32 = v9;
      if ( v5 <= v9 + 1 )
      {
        Scaleform::MsgFormat::AddStringRecord(this, &str);
      }
      else
      {
        v32 = v9 + 1;
        if ( pStr[v9 + 1] != 37 )
        {
          v33 = 10;
          v44 = 0;
          v43 = 0;
          v34 = 0;
          v10 = v5 - v9;
          if ( v5 < v9 )
            v10 = v5;
          v38.pStr = pStr;
          v38.Size = v5 - v10;
          Scaleform::MsgFormat::AddStringRecord(this, &v38);
          v11 = v32;
          v12 = v32;
          v = 0;
          v14 = 0;
          v35 = v32;
          LODWORD(v36) = 0;
          v31 = 0;
          if ( v32 < str.Size )
          {
            while ( 2 )
            {
              switch ( str.pStr[v12] )
              {
                case 'E':
                  v44 = 1;
                  goto $LN20_38;
                case 'G':
                  v44 = 1;
                  goto $LN18_42;
                case 'I':
                  v14 = 3;
                  goto LABEL_21;
                case 'X':
                  v44 = 1;
                  goto $LN23_26;
                case 'd':
                case 'i':
                  v8 += 4;
                  v7 += 4;
                  if ( v14 == 2 )
                  {
                    v6 = 2;
                    v = *(const char **)v8;
                    *(_QWORD *)&v36 = *(int *)v8;
                  }
                  else
                  {
                    v = *(const char **)v8;
                    v6 = 1;
                    LODWORD(v36) = *(_DWORD *)v8;
                  }
                  break;
                case 'e':
$LN20_38:
                  v34 = 1;
                  goto LABEL_43;
                case 'f':
                  v34 = 0;
                  goto LABEL_43;
                case 'g':
$LN18_42:
                  v34 = 2;
LABEL_43:
                  v15 = *((double *)v7 + 1);
                  v8 += 8;
                  v7 += 8;
                  v36 = v15;
                  v = (const char *)LODWORD(v36);
                  v6 = 3;
                  break;
                case 'h':
                  v14 = 1;
                  goto LABEL_21;
                case 'l':
                  v14 = 2;
LABEL_21:
                  ++v31;
                  goto LABEL_22;
                case 'n':
                  v = (const char *)**((_DWORD **)v8 + 1);
                  v8 += 4;
                  v6 = 1;
                  v7 += 4;
                  LODWORD(v36) = v;
                  break;
                case 'o':
                  v = (const char *)*((_DWORD *)v8 + 1);
                  v8 += 4;
                  v6 = 1;
                  v33 = 8;
                  v43 = 1;
                  v7 += 4;
                  LODWORD(v36) = v;
                  break;
                case 'p':
                  v = (const char *)**((_DWORD **)v8 + 1);
                  v8 += 4;
                  v6 = 1;
                  v43 = 1;
                  v7 += 4;
                  LODWORD(v36) = v;
                  v33 = 16;
                  break;
                case 's':
                  v6 = 4;
                  v = (const char *)*((_DWORD *)v8 + 1);
                  v8 += 4;
                  v7 += 4;
                  LODWORD(v36) = v;
                  break;
                case 'u':
                  v = (const char *)*((_DWORD *)v8 + 1);
                  v8 += 4;
                  v7 += 4;
                  LODWORD(v36) = v;
                  if ( v14 == 2 )
                    v6 = 2;
                  else
                    v6 = 1;
                  v43 = 1;
                  break;
                case 'x':
$LN23_26:
                  v = (const char *)*((_DWORD *)v8 + 1);
                  v8 += 4;
                  v6 = 1;
                  v43 = 1;
                  v7 += 4;
                  LODWORD(v36) = v;
                  v33 = 16;
                  break;
                default:
LABEL_22:
                  if ( v6 )
                    break;
                  v32 = ++v12;
                  if ( v12 >= str.Size )
                    break;
                  continue;
              }
              break;
            }
          }
          switch ( v6 )
          {
            case 1:
              v39[0] = &str.pStr[v11];
              v39[1] = v32 - v31 - v11;
              v16 = Scaleform::StackMemPool<512,4,Scaleform::MemPoolImmediateFree>::Alloc(&this->MemPool, 0x50u);
              if ( v43 )
              {
                if ( v16 )
                {
                  Scaleform::LongFormatter::LongFormatter((Scaleform::LongFormatter *)v16, (unsigned int)v);
                  v18 = v17;
LABEL_51:
                  *(_DWORD *)(v18 + 28) ^= ((unsigned __int8)v33 ^ (unsigned __int8)*(_DWORD *)(v18 + 28)) & 0x1F;
                  v20 = v39;
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
              v40[0] = &str.pStr[v11];
              v40[1] = v32 - v31 - v11;
              v22 = Scaleform::StackMemPool<512,4,Scaleform::MemPoolImmediateFree>::Alloc(&this->MemPool, 0x50u);
              if ( v43 )
              {
                if ( v22 )
                {
                  Scaleform::LongFormatter::LongFormatter(
                    (Scaleform::LongFormatter *)v22,
                    __SPAIR64__(HIDWORD(v36), (unsigned int)v));
                  v18 = v23;
                  *(_DWORD *)(v23 + 28) ^= ((unsigned __int8)v33 ^ (unsigned __int8)*(_DWORD *)(v23 + 28)) & 0x1F;
                  v20 = v40;
                  goto LABEL_52;
                }
              }
              else if ( v22 )
              {
                Scaleform::LongFormatter::LongFormatter(
                  (Scaleform::LongFormatter *)v22,
                  __SPAIR64__(HIDWORD(v36), (unsigned int)v));
                v18 = v24;
                *(_DWORD *)(v24 + 28) ^= ((unsigned __int8)v33 ^ (unsigned __int8)*(_DWORD *)(v24 + 28)) & 0x1F;
                v20 = v40;
                goto LABEL_52;
              }
              v18 = 0;
              MEMORY[0x1C] ^= ((unsigned __int8)v33 ^ MEMORY[0x1C]) & 0x1F;
              v20 = v40;
LABEL_52:
              *(_BYTE *)(v18 + 22) ^= (v44 ^ *(_BYTE *)(v18 + 22)) & 1;
LABEL_53:
              (*(void (__thiscall **)(int, _DWORD *))(*(_DWORD *)v18 + 8))(v18, v20);
              Scaleform::MsgFormat::AddFormatterRecord(this, (Scaleform::Formatter *)v18, 1);
LABEL_54:
              v5 = str.Size;
              goto LABEL_55;
            case 3:
              v25 = Scaleform::StackMemPool<512,4,Scaleform::MemPoolImmediateFree>::Alloc(&this->MemPool, 0x188u);
              if ( v25 )
              {
                Scaleform::DoubleFormatter::DoubleFormatter((Scaleform::DoubleFormatter *)v25, v36);
                v18 = v26;
              }
              else
              {
                v18 = 0;
              }
              v41[0] = &str.pStr[v35];
              v41[1] = v32 - v35;
              *(_BYTE *)(v18 + 22) ^= (v44 ^ *(_BYTE *)(v18 + 22)) & 1;
              *(_DWORD *)(v18 + 28) = v34;
              v20 = v41;
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
      v21 = v32 + 1;
      if ( v5 < v32 + 1 )
        v21 = v5;
      str.pStr += v21;
      v5 -= v21;
      str.Size = v5;
      if ( !v5 )
        goto LABEL_7;
      pStr = str.pStr;
    }
LABEL_6:
    Scaleform::MsgFormat::AddStringRecord(this, &str);
LABEL_7:
    Scaleform::MsgFormat::MakeString(this);
  }
}
