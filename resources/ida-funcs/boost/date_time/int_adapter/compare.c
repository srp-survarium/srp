int __usercall boost::date_time::int_adapter<__int64>::compare@<eax>(
        boost::date_time::int_adapter<__int64> *this@<ecx>,
        boost::date_time::int_adapter<__int64> *rhs@<eax>)
{
  boost::date_time::int_adapter<__int64> *v4; // ecx
  boost::date_time::int_adapter<__int64> *v5; // ecx
  int v6; // ebx
  unsigned int value; // eax
  unsigned int v9; // ecx
  signed int value_high; // edi
  signed int v11; // esi
  boost::date_time::int_adapter<__int64> *v12; // ecx
  __int64 v13; // [esp-8h] [ebp-18h]
  __int64 v14; // [esp-8h] [ebp-18h]
  bool is_neg_inf; // [esp+Eh] [ebp-2h]
  bool is_pos_inf; // [esp+Fh] [ebp-1h]

  if ( !boost::date_time::int_adapter<__int64>::is_special(this, (int)this)
    && !boost::date_time::int_adapter<__int64>::is_special(v4, (int)rhs) )
  {
LABEL_15:
    value = this->value_;
    v9 = rhs->value_;
    value_high = HIDWORD(this->value_);
    v11 = HIDWORD(rhs->value_);
    if ( value_high > v11 )
      return 1;
    if ( value_high < v11 || value < v9 )
      return -1;
    return __SPAIR64__(value_high, value) > __SPAIR64__(v11, v9);
  }
  if ( !boost::date_time::int_adapter<__int64>::is_nan(v4, this)
    && !boost::date_time::int_adapter<__int64>::is_nan(v5, rhs) )
  {
    v6 = this->value_;
    is_neg_inf = boost::date_time::int_adapter<__int64>::is_neg_inf(this->value_);
    if ( is_neg_inf && !boost::date_time::int_adapter<__int64>::is_neg_inf(rhs->value_) )
      return -1;
    is_pos_inf = boost::date_time::int_adapter<__int64>::is_pos_inf(rhs->value_);
    if ( is_pos_inf )
    {
      HIDWORD(v13) = HIDWORD(this->value_);
      LODWORD(v13) = v6;
      if ( !boost::date_time::int_adapter<__int64>::is_pos_inf(v13) )
        return -1;
    }
    HIDWORD(v14) = HIDWORD(this->value_);
    LODWORD(v14) = v6;
    if ( boost::date_time::int_adapter<__int64>::is_pos_inf(v14) && !is_pos_inf
      || boost::date_time::int_adapter<__int64>::is_neg_inf(rhs->value_) && !is_neg_inf )
    {
      return 1;
    }
    goto LABEL_15;
  }
  if ( boost::date_time::int_adapter<__int64>::is_nan(v5, this)
    && boost::date_time::int_adapter<__int64>::is_nan(v12, rhs) )
  {
    return 0;
  }
  return 2;
}
