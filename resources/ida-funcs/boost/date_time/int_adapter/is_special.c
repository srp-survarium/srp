bool __thiscall boost::date_time::int_adapter<unsigned int>::is_special(
        boost::date_time::int_adapter<unsigned int> *this)
{
  bool v3; // [esp+4h] [ebp-14h]

  v3 = !this->value_ || this->value_ == -1;
  return v3 || this->value_ == -2;
}


bool __thiscall boost::date_time::int_adapter<__int64>::is_special(boost::date_time::int_adapter<__int64> *this)
{
  bool v2; // [esp+0h] [ebp-34h]
  bool v4; // [esp+Ch] [ebp-28h]

  v4 = !LODWORD(this->value_) && HIDWORD(this->value_) == 0x80000000
    || LODWORD(this->value_) == -1 && HIDWORD(this->value_) == 0x7FFFFFFF;
  v2 = 1;
  if ( !v4 && (LODWORD(this->value_) != -2 || HIDWORD(this->value_) != 0x7FFFFFFF) )
    return 0;
  return v2;
}
