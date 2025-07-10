void __thiscall SpeedTree::CErrorHandler::SErrorString::SErrorString(_DWORD *this)
{
  *(_BYTE *)this = 0;
  this[1] = &SpeedTree::CBasicFixedString<1024>::`vftable';
  SpeedTree::CBasicFixedString<1024>::operator=((unsigned __int8 *)&buf);
}
