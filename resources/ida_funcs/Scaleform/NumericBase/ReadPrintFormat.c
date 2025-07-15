void __thiscall Scaleform::NumericBase::ReadPrintFormat(Scaleform::NumericBase *this, Scaleform::StringDataPtr token)
{
  Scaleform::StringDataPtr *v3; // eax
  Scaleform::StringDataPtr *v4; // eax
  int v5; // [esp-8h] [ebp-Ch]

  if ( token.Size && token.pStr )
  {
    switch ( *token.pStr )
    {
      case ' ':
        *((_BYTE *)this + 6) |= 2u;
        goto LABEL_5;
      case '#':
        *((_BYTE *)this + 6) |= 8u;
        goto LABEL_5;
      case '+':
        *((_BYTE *)this + 5) |= 0x80u;
        goto LABEL_5;
      case '-':
        *((_BYTE *)this + 6) |= 4u;
        goto LABEL_5;
      case '.':
        *(_DWORD *)this &= 0xFFFFFFE0;
        v5 = *(_DWORD *)this & 0x1F;
        v4 = Scaleform::StringDataPtr::TrimLeft(&token, 1u);
        *(_DWORD *)this ^= ((unsigned __int8)Scaleform::ReadInteger(v4, v5, 58)
                          ^ (unsigned __int8)*(_DWORD *)this)
                         & 0x1F;
        return;
      case '0':
        *((_BYTE *)this + 4) = *((_BYTE *)this + 4) & 0x80 | 0x30;
LABEL_5:
        v3 = Scaleform::StringDataPtr::TrimLeft(&token, 1u);
        Scaleform::NumericBase::ReadPrintFormat(this, *v3);
        break;
      default:
        Scaleform::NumericBase::ReadWidth(this, token);
        break;
    }
  }
}
