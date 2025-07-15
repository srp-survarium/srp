_BYTE *__thiscall SpeedTree::CBasicString<1>::`scalar deleting destructor'(_BYTE *this, char a2)
{
  SpeedTree::CBasicString<1>::~CBasicString<1>(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
