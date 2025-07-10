boost::date_time::int_adapter<__int64> *__thiscall boost::date_time::int_adapter<__int64>::operator+<__int64>(
        boost::date_time::int_adapter<__int64> *this,
        boost::date_time::int_adapter<__int64> *result,
        boost::date_time::int_adapter<__int64> *rhs)
{
  int value_high; // ecx
  char v8; // [esp+14h] [ebp-D4h]
  char v9; // [esp+18h] [ebp-D0h]
  char v10; // [esp+1Ch] [ebp-CCh]
  bool v11; // [esp+20h] [ebp-C8h]
  char v12; // [esp+24h] [ebp-C4h]
  bool v13; // [esp+2Ch] [ebp-BCh]

  if ( !boost::date_time::int_adapter<__int64>::is_special(this)
    && !boost::date_time::int_adapter<__int64>::is_special(rhs) )
  {
    goto LABEL_55;
  }
  v13 = LODWORD(this->value_) == -2 && HIDWORD(this->value_) == 0x7FFFFFFF;
  if ( v13 || (LODWORD(rhs->value_) != -2 || HIDWORD(rhs->value_) != 0x7FFFFFFF ? (v12 = 0) : (v12 = 1), v12) )
  {
    result->value_ = 0x7FFFFFFFFFFFFFFELL;
    return result;
  }
  v11 = LODWORD(this->value_) == -1 && HIDWORD(this->value_) == 0x7FFFFFFF;
  if ( v11 && (LODWORD(rhs->value_) || HIDWORD(rhs->value_) != 0x80000000 ? (v10 = 0) : (v10 = 1), v10)
    || (LODWORD(this->value_) || HIDWORD(this->value_) != 0x80000000 ? (v9 = 0) : (v9 = 1),
        v9 && (LODWORD(rhs->value_) != -1 || HIDWORD(rhs->value_) != 0x7FFFFFFF ? (v8 = 0) : (v8 = 1), v8)) )
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
  if ( LODWORD(rhs->value_) == -1 && HIDWORD(rhs->value_) == 0x7FFFFFFF )
  {
    result->value_ = 0x7FFFFFFFFFFFFFFFLL;
    return result;
  }
  if ( !LODWORD(rhs->value_) && HIDWORD(rhs->value_) == 0x80000000 )
  {
    result->value_ = 0x8000000000000000uLL;
    return result;
  }
  else
  {
LABEL_55:
    result->value_ = rhs->value_ + this->value_;
    return result;
  }
}
