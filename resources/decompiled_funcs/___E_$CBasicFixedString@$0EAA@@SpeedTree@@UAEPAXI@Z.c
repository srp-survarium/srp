_DWORD *__thiscall SpeedTree::CBasicFixedString<1024>::`vector deleting destructor'(_DWORD *this, char a2)
{
  *this = &SpeedTree::CBasicFixedString<1024>::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
