void __thiscall SpeedTree::CSharedHeapBlock::CSharedHeapBlock(_DWORD *this)
{
  *this = 0;
  this[1] = 0;
  this[2] = &SpeedTree::CBasicFixedString<1024>::`vftable';
  SpeedTree::CBasicFixedString<1024>::operator=((unsigned __int8 *)&buf);
  *((_BYTE *)this + 272) = 0;
}
