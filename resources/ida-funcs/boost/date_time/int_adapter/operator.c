boost::date_time::int_adapter<__int64> *__userpurge boost::date_time::int_adapter<__int64>::operator-<__int64>@<eax>(
        boost::date_time::int_adapter<__int64> *this@<ecx>,
        int *a2@<edi>,
        int *a3@<esi>,
        boost::date_time::int_adapter<__int64> *result,
        const boost::date_time::int_adapter<__int64> *rhs)
{
  boost::date_time::int_adapter<__int64> *v5; // ecx
  boost::date_time::int_adapter<__int64> *v6; // ecx
  bool is_neg_inf; // al
  boost::date_time::int_adapter<__int64> *v8; // ecx
  bool v9; // al
  boost::date_time::int_adapter<__int64> *v11; // [esp-4h] [ebp-Ch]
  boost::date_time::int_adapter<__int64> *v12; // [esp-4h] [ebp-Ch]

  if ( !boost::date_time::int_adapter<__int64>::is_special(this, (int)a2)
    && !boost::date_time::int_adapter<__int64>::is_special(v5, (int)result) )
  {
    goto LABEL_15;
  }
  if ( boost::date_time::int_adapter<__int64>::is_nan(v5, a2)
    || boost::date_time::int_adapter<__int64>::is_nan(v6, result)
    || boost::date_time::int_adapter<__int64>::is_pos_inf(*(_QWORD *)a2)
    && boost::date_time::int_adapter<__int64>::is_pos_inf(result->value_)
    || (is_neg_inf = boost::date_time::int_adapter<__int64>::is_neg_inf(*(_QWORD *)a2), v8 = v11, is_neg_inf)
    && (v9 = boost::date_time::int_adapter<__int64>::is_neg_inf(result->value_), v8 = v12, v9) )
  {
    *a3 = -2;
    goto LABEL_17;
  }
  if ( !boost::date_time::int_adapter<__int64>::is_infinity(v8, a2) )
  {
    if ( boost::date_time::int_adapter<__int64>::is_pos_inf(result->value_) )
    {
      *a3 = 0;
      a3[1] = 0x80000000;
      return (boost::date_time::int_adapter<__int64> *)a3;
    }
    if ( boost::date_time::int_adapter<__int64>::is_neg_inf(result->value_) )
    {
      *a3 = -1;
LABEL_17:
      a3[1] = 0x7FFFFFFF;
      return (boost::date_time::int_adapter<__int64> *)a3;
    }
LABEL_15:
    *(_QWORD *)a3 = *(_QWORD *)a2 - result->value_;
    return (boost::date_time::int_adapter<__int64> *)a3;
  }
  *a3 = *a2;
  a3[1] = a2[1];
  return (boost::date_time::int_adapter<__int64> *)a3;
}


boost::date_time::int_adapter<__int64> *__userpurge boost::date_time::int_adapter<__int64>::operator+<unsigned int>@<eax>(
        boost::date_time::int_adapter<__int64> *this@<ecx>,
        _DWORD *a2@<esi>,
        boost::date_time::int_adapter<__int64> *result,
        const boost::date_time::int_adapter<unsigned int> *rhs)
{
  boost::date_time::int_adapter<__int64> *v4; // ecx
  unsigned int value; // edi
  int value_high; // eax
  boost::date_time::int_adapter<__int64> *v8; // [esp-4h] [ebp-10h]

  if ( !boost::date_time::int_adapter<__int64>::is_special(this, (int)result) )
  {
    value = rhs->value_;
    if ( rhs->value_ )
    {
      if ( value < 0xFFFFFFFE )
        goto LABEL_17;
    }
  }
  if ( boost::date_time::int_adapter<__int64>::is_nan(v4, result)
    || (value = rhs->value_, rhs->value_ == -2)
    || boost::date_time::int_adapter<__int64>::is_pos_inf(result->value_) && !value
    || boost::date_time::int_adapter<__int64>::is_neg_inf(result->value_) && value == -1 )
  {
    *a2 = -2;
    goto LABEL_19;
  }
  if ( !boost::date_time::int_adapter<__int64>::is_infinity(v8, (int *)result) )
  {
    if ( value == -1 )
    {
      *a2 = -1;
LABEL_19:
      a2[1] = 0x7FFFFFFF;
      return (boost::date_time::int_adapter<__int64> *)a2;
    }
    if ( !value )
    {
      *a2 = 0;
      a2[1] = 0x80000000;
      return (boost::date_time::int_adapter<__int64> *)a2;
    }
LABEL_17:
    value_high = (result->value_ + (unsigned __int64)value) >> 32;
    *a2 = LODWORD(result->value_) + value;
    goto LABEL_12;
  }
  *a2 = result->value_;
  value_high = HIDWORD(result->value_);
LABEL_12:
  a2[1] = value_high;
  return (boost::date_time::int_adapter<__int64> *)a2;
}


boost::date_time::int_adapter<__int64> *__userpurge boost::date_time::int_adapter<__int64>::operator+<__int64>@<eax>(
        boost::date_time::int_adapter<__int64> *this@<ecx>,
        int *a2@<edi>,
        int *a3@<esi>,
        boost::date_time::int_adapter<__int64> *result,
        const boost::date_time::int_adapter<__int64> *rhs)
{
  boost::date_time::int_adapter<__int64> *v5; // ecx
  boost::date_time::int_adapter<__int64> *v6; // ecx
  bool is_neg_inf; // al
  boost::date_time::int_adapter<__int64> *v8; // ecx
  bool is_pos_inf; // al
  boost::date_time::int_adapter<__int64> *v11; // [esp-4h] [ebp-Ch]
  boost::date_time::int_adapter<__int64> *v12; // [esp-4h] [ebp-Ch]

  if ( !boost::date_time::int_adapter<__int64>::is_special(this, (int)a2)
    && !boost::date_time::int_adapter<__int64>::is_special(v5, (int)result) )
  {
    goto LABEL_15;
  }
  if ( boost::date_time::int_adapter<__int64>::is_nan(v5, a2)
    || boost::date_time::int_adapter<__int64>::is_nan(v6, result)
    || boost::date_time::int_adapter<__int64>::is_pos_inf(*(_QWORD *)a2)
    && boost::date_time::int_adapter<__int64>::is_neg_inf(result->value_)
    || (is_neg_inf = boost::date_time::int_adapter<__int64>::is_neg_inf(*(_QWORD *)a2), v8 = v11, is_neg_inf)
    && (is_pos_inf = boost::date_time::int_adapter<__int64>::is_pos_inf(result->value_), v8 = v12, is_pos_inf) )
  {
    *a3 = -2;
    goto LABEL_17;
  }
  if ( !boost::date_time::int_adapter<__int64>::is_infinity(v8, a2) )
  {
    if ( boost::date_time::int_adapter<__int64>::is_pos_inf(result->value_) )
    {
      *a3 = -1;
LABEL_17:
      a3[1] = 0x7FFFFFFF;
      return (boost::date_time::int_adapter<__int64> *)a3;
    }
    if ( boost::date_time::int_adapter<__int64>::is_neg_inf(result->value_) )
    {
      *a3 = 0;
      a3[1] = 0x80000000;
      return (boost::date_time::int_adapter<__int64> *)a3;
    }
LABEL_15:
    *(_QWORD *)a3 = *(_QWORD *)a2 + result->value_;
    return (boost::date_time::int_adapter<__int64> *)a3;
  }
  *a3 = *a2;
  a3[1] = a2[1];
  return (boost::date_time::int_adapter<__int64> *)a3;
}
