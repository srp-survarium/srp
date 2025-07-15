stlp_std::collate<char> *__thiscall stlp_std::collate<char>::`vector deleting destructor'(
        stlp_std::collate<char> *this,
        char a2)
{
  stlp_std::collate<char>::~collate<char>(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}


stlp_std::collate<wchar_t> *__thiscall stlp_std::collate<wchar_t>::`vector deleting destructor'(
        stlp_std::collate<wchar_t> *this,
        char a2)
{
  stlp_std::collate<wchar_t>::~collate<wchar_t>(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
