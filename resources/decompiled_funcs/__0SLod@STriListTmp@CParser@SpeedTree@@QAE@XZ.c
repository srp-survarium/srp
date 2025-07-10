SpeedTree::CParser::STriListTmp::SLod *__thiscall SpeedTree::CParser::STriListTmp::SLod::SLod(
        SpeedTree::CParser::STriListTmp::SLod *this)
{
  *(_DWORD *)this = 0;
  *((_DWORD *)this + 1) = 0;
  *((_BYTE *)this + 8) = 0;
  *((float *)this + 3) = 1.0;
  memset((int)this + 16, 0, 0x50u);
  memset((int)this + 96, 0, 0x50u);
  return this;
}
