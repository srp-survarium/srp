int __thiscall SpeedTree::CParser::ParseInt(SpeedTree::CParser *this)
{
  int v2; // [esp+4h] [ebp-8h]
  int v3; // [esp+8h] [ebp-4h]

  if ( *((_BYTE *)this + 92) )
  {
    HIBYTE(v3) = *(_BYTE *)(*(_DWORD *)this + (*((_DWORD *)this + 2))++);
    BYTE2(v3) = *(_BYTE *)(*(_DWORD *)this + (*((_DWORD *)this + 2))++);
    BYTE1(v3) = *(_BYTE *)(*(_DWORD *)this + (*((_DWORD *)this + 2))++);
    LOBYTE(v3) = *(_BYTE *)(*(_DWORD *)this + (*((_DWORD *)this + 2))++);
    return v3;
  }
  else
  {
    v2 = *((_DWORD *)this + 2) + *(_DWORD *)this;
    *((_DWORD *)this + 2) += 4;
    return *(_DWORD *)v2;
  }
}
