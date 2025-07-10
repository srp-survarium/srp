boost::date_time::int_adapter<__int64> *__thiscall boost::date_time::int_adapter<__int64>::operator+<unsigned int>(
        boost::date_time::int_adapter<__int64> *this,
        boost::date_time::int_adapter<__int64> *result,
        boost::date_time::int_adapter<unsigned int> *rhs)
{
  int value_high; // edx
  char v6; // [esp+Ch] [ebp-90h]
  bool v7; // [esp+10h] [ebp-8Ch]
  bool v8; // [esp+14h] [ebp-88h]

  if ( !boost::date_time::int_adapter<__int64>::is_special(this)
    && !boost::date_time::int_adapter<unsigned int>::is_special(rhs) )
  {
    goto LABEL_35;
  }
  v8 = LODWORD(this->value_) == -2 && HIDWORD(this->value_) == 0x7FFFFFFF;
  if ( v8 || rhs->value_ == -2 )
  {
    result->value_ = 0x7FFFFFFFFFFFFFFELL;
    return result;
  }
  v7 = LODWORD(this->value_) == -1 && HIDWORD(this->value_) == 0x7FFFFFFF;
  if ( v7 && !rhs->value_
    || (LODWORD(this->value_) || HIDWORD(this->value_) != 0x80000000 ? (v6 = 0) : (v6 = 1), v6 && rhs->value_ == -1) )
  {
    result->value_ = 0x7FFFFFFFFFFFFFFELL;
    return result;
  }
  if ( !LODWORD(this->value_) && HIDWORD(this->value_) == 0x80000000
    || LODWORD(this->value_) == -1 && HIDWORD(this->value_) == 0x7FFFFFFF )
  {
    value_high = HIDWORD(this->value_);
    LODWORD(result->value_) = this->value_;
    HIDWORD(result->value_) = value_high;
    return result;
  }
  if ( rhs->value_ == -1 )
  {
    result->value_ = 0x7FFFFFFFFFFFFFFFLL;
    return result;
  }
  if ( !rhs->value_ )
  {
    result->value_ = 0x8000000000000000uLL;
    return result;
  }
  else
  {
LABEL_35:
    result->value_ = this->value_ + rhs->value_;
    return result;
  }
}
