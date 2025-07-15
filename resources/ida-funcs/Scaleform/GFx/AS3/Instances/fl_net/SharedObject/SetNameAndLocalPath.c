char __thiscall Scaleform::GFx::AS3::Instances::fl_net::SharedObject::SetNameAndLocalPath(
        Scaleform::GFx::AS3::Instances::fl_net::SharedObject *this,
        const __m128i ***name,
        const Scaleform::GFx::ASString *localPath)
{
  const __m128i ***v3; // esi
  unsigned int FirstCharAt; // eax
  int v6; // edx

  v3 = name;
  FirstCharAt = Scaleform::GFx::ASConstString::GetFirstCharAt((Scaleform::GFx::ASConstString *)name, 0, (char **)&name);
  if ( !FirstCharAt )
  {
LABEL_7:
    Scaleform::String::operator=(&this->Name, **v3);
    Scaleform::String::operator=(&this->LocalPath, (const __m128i *)localPath->pNode->pData);
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
          FirstCharAt = Scaleform::GFx::ASConstString::GetNextChar((Scaleform::GFx::ASConstString *)v3, (char **)&name);
          if ( !FirstCharAt )
            goto LABEL_7;
          continue;
        }
        return 0;
    }
  }
}
