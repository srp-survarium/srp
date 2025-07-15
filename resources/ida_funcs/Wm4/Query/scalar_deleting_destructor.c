Wm4::Query *__thiscall Wm4::Query::`scalar deleting destructor'(Wm4::Query *this, char a2)
{
  this->__vftable = (Wm4::Query_vtbl *)&Wm4::Query::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
