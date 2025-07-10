char __thiscall SpeedTree::CParser::ParsePlatform(SpeedTree::CParser *this)
{
  char v3; // [esp+33h] [ebp-1h]

  v3 = 0;
  if ( *((_DWORD *)this + 1) >= (unsigned int)(*((_DWORD *)this + 2) + 8) )
  {
    *((_BYTE *)this + 93) = SpeedTree::CParser::ParseInt(this) != 0;
    *((_BYTE *)this + 92) = *((_BYTE *)this + 93);
    *((_DWORD *)this + 21) = SpeedTree::CParser::ParseInt(this);
    if ( *((_DWORD *)this + 21) != SpeedTree::CCoordSys::GetCoordSysType() )
    {
      SpeedTree::CCore::SetError("Warning: SRT & run-time coordinate systems do not match, will suffer an at-load conversion penalty");
      if ( *((_DWORD *)this + 21) == 4 )
        SpeedTree::CCore::SetError("Warning: SRT file uses a custom coordinate system, can't guarantee match to run-time");
      else
        *((_DWORD *)this + 22) = SpeedTree::CCoordSys::GetBuiltInConverter(*((enum SpeedTree::CCoordSys::ECoordSysType *)this
                                                                           + 21));
    }
    *((_BYTE *)this + 94) = SpeedTree::CParser::ParseInt(this) != 0;
    *((_BYTE *)this + 95) = SpeedTree::CParser::ParseInt(this) != 0;
    *((_BYTE *)this + 96) = SpeedTree::CParser::ParseInt(this) != 0;
    return 1;
  }
  return v3;
}
