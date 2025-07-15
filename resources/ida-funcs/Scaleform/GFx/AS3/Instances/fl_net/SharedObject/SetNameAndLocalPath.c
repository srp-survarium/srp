char __thiscall Scaleform::GFx::AS3::Instances::fl_net::SharedObject::SetNameAndLocalPath(
        Scaleform::GFx::AS3::Instances::fl_net::SharedObject *this,
        Scaleform::GFx::ASString *name,
        const Scaleform::GFx::ASString *localPath)
{
  Scaleform::GFx::ASString *v3; // esi
  unsigned int FirstCharAt; // eax
  int v6; // edx

  v3 = name;
  FirstCharAt = Scaleform::GFx::ASConstString::GetFirstCharAt(name, 0, (const char **)&name);
  if ( !FirstCharAt )
  {
LABEL_7:
    Scaleform::String::operator=(&this->Name, (char *)v3->pNode->pData);
    Scaleform::String::operator=(&this->LocalPath, (char *)localPath->pNode->pData);
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
          FirstCharAt = Scaleform::GFx::ASConstString::GetNextChar(v3, (const char **)&name);
          if ( !FirstCharAt )
            goto LABEL_7;
          continue;
        }
        return 0;
    }
  }
}
