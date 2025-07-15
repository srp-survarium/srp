char __thiscall Scaleform::GFx::AS2::SharedObject::SetNameAndLocalPath(
        Scaleform::GFx::AS2::SharedObject *this,
        Scaleform::String *name,
        const Scaleform::String *localPath)
{
  Scaleform::String *v3; // esi
  unsigned int FirstCharAt; // eax
  int v6; // edx

  v3 = name;
  FirstCharAt = Scaleform::String::GetFirstCharAt(name, 0, (const char **)&name);
  if ( !FirstCharAt )
  {
LABEL_7:
    Scaleform::String::operator=(&this->Name, v3);
    Scaleform::String::operator=(&this->LocalPath, localPath);
    return 1;
  }
  while ( 2 )
  {
    switch ( FirstCharAt )
    {
      case '"':
      case '#':
      case '%':
      case '&':
      case '\'':
      case ',':
      case ':':
      case ';':
      case '<':
      case '>':
      case '?':
      case '\\':
      case '~':
        return 0;
      default:
        v6 = Scaleform::UnicodeSpaceBits[BYTE1(FirstCharAt)];
        if ( !Scaleform::UnicodeSpaceBits[BYTE1(FirstCharAt)]
          || v6 != 1
          && (Scaleform::UnicodeSpaceBits[v6 + ((unsigned __int8)FirstCharAt >> 4)] & (1 << (FirstCharAt & 0xF))) == 0 )
        {
          FirstCharAt = Scaleform::String::GetNextChar(v3, (const char **)&name);
          if ( !FirstCharAt )
            goto LABEL_7;
          continue;
        }
        return 0;
    }
  }
}
