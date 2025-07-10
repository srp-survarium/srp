bool __thiscall boost::date_time::int_adapter<unsigned int>::is_special(
        boost::date_time::int_adapter<unsigned int> *this)
{
  bool v3; // [esp+4h] [ebp-14h]

  v3 = !this->value_ || this->value_ == -1;
  return v3 || this->value_ == -2;
}
