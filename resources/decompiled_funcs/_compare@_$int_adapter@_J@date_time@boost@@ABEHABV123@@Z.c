int __thiscall boost::date_time::int_adapter<__int64>::compare(
        boost::date_time::int_adapter<__int64> *this,
        boost::date_time::int_adapter<__int64> *rhs)
{
  char v11; // [esp+30h] [ebp-F4h]
  bool v12; // [esp+38h] [ebp-ECh]

  if ( !boost::date_time::int_adapter<__int64>::is_special(this)
    && !boost::date_time::int_adapter<__int64>::is_special(rhs) )
  {
LABEL_67:
    if ( this->value_ >= rhs->value_ )
      return this->value_ > rhs->value_;
    else
      return -1;
  }
  if ( (LODWORD(this->value_) != -2 || HIDWORD(this->value_) != 0x7FFFFFFF)
    && (LODWORD(rhs->value_) != -2 || HIDWORD(rhs->value_) != 0x7FFFFFFF) )
  {
    if ( !LODWORD(this->value_)
      && HIDWORD(this->value_) == 0x80000000
      && (LODWORD(rhs->value_) || HIDWORD(rhs->value_) != 0x80000000) )
    {
      return -1;
    }
    if ( LODWORD(rhs->value_) == -1
      && HIDWORD(rhs->value_) == 0x7FFFFFFF
      && (LODWORD(this->value_) != -1 || HIDWORD(this->value_) != 0x7FFFFFFF) )
    {
      return -1;
    }
    if ( LODWORD(this->value_) == -1
      && HIDWORD(this->value_) == 0x7FFFFFFF
      && (LODWORD(rhs->value_) != -1 || HIDWORD(rhs->value_) != 0x7FFFFFFF) )
    {
      return 1;
    }
    if ( !LODWORD(rhs->value_)
      && HIDWORD(rhs->value_) == 0x80000000
      && (LODWORD(this->value_) || HIDWORD(this->value_) != 0x80000000) )
    {
      return 1;
    }
    goto LABEL_67;
  }
  v12 = LODWORD(this->value_) == -2 && HIDWORD(this->value_) == 0x7FFFFFFF;
  if ( v12 && (LODWORD(rhs->value_) != -2 || HIDWORD(rhs->value_) != 0x7FFFFFFF ? (v11 = 0) : (v11 = 1), v11) )
    return 0;
  else
    return 2;
}
