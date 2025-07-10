int sub_7DFE60()
{
  dword_AA1390 = (int)&SpeedTree::CBasicFixedString<1024>::`vftable';
  SpeedTree::CBasicFixedString<1024>::operator=((int)&dword_AA1390, (unsigned __int8 *)&buf);
  return atexit(sub_7F3590);
}
