stlp_std::ios_base *__thiscall stlp_std::ios_base::`scalar deleting destructor'(stlp_std::ios_base *this, char a2)
{
  stlp_std::ios_base::~ios_base(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
