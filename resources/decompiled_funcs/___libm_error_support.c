void __cdecl __libm_error_support(long double *arg1, long double *arg2, long double *retval, error_types input_tag)
{
  int (__cdecl *v4)(_exception *); // eax
  long double v5; // st7
  long double v6; // st7
  long double v7; // st7
  _exception exc; // [esp+Ch] [ebp-28h] BYREF
  char double_zero[8]; // [esp+2Ch] [ebp-8h]

  double_zero[0] = 0;
  double_zero[1] = 0;
  double_zero[2] = 0;
  double_zero[3] = 0;
  double_zero[4] = 0;
  double_zero[5] = 0;
  double_zero[6] = 0;
  double_zero[7] = 0;
  if ( pmatherr_set )
    v4 = (int (__cdecl *)(_exception *))_decode_pointer(_pmatherr);
  else
    v4 = (int (__cdecl *)(_exception *))__init_collate;
  if ( input_tag > exp10_overflow )
  {
    switch ( input_tag )
    {
      case log_nan:
        exc.name = "log";
        goto LABEL_37;
      case log10_nan:
        exc.name = "log10";
        goto LABEL_37;
      case exp_nan:
        exc.name = "exp";
        goto LABEL_37;
      case atan_nan:
        exc.name = "atan";
        goto LABEL_37;
      case ceil_nan:
        exc.name = "ceil";
        goto LABEL_37;
      case floor_nan:
        exc.name = "floor";
        goto LABEL_37;
      case pow_nan:
        goto $LN36_2;
      case modf_nan:
        exc.name = "modf";
        goto LABEL_37;
      case acos_nan:
        goto $LN30_2;
      case asin_nan:
        goto $LN8_30;
      case sin_naninf:
        exc.name = "sin";
        goto LABEL_53;
      case cos_naninf:
        exc.name = "cos";
        goto LABEL_53;
      case tan_naninf:
        exc.name = "tan";
LABEL_53:
        v6 = *arg1 * *(double *)double_zero;
        *retval = v6;
        exc.arg1 = *arg1;
        exc.arg2 = *arg2;
        goto LABEL_54;
      default:
        return;
    }
  }
  if ( input_tag == exp10_overflow )
  {
    exc.type = 3;
    exc.name = "exp10";
    goto LABEL_17;
  }
  if ( input_tag <= pow_underflow )
  {
    switch ( input_tag )
    {
      case pow_underflow:
        exc.name = "pow";
        goto LABEL_20;
      case log_zero:
        exc.type = 2;
        exc.name = "log";
        goto LABEL_17;
      case log_negative:
        exc.name = "log";
        break;
      case log10_zero:
        exc.type = 2;
        exc.name = "log10";
        goto LABEL_17;
      case log10_negative:
        exc.name = "log10";
        break;
      case exp_overflow:
        exc.type = 3;
        exc.name = "exp";
LABEL_17:
        exc.arg1 = *arg1;
        exc.arg2 = *arg2;
        exc.retval = *retval;
        if ( !v4(&exc) )
          *_errno() = 34;
        goto LABEL_56;
      case exp_underflow:
        exc.name = "exp";
LABEL_20:
        exc.arg1 = *arg1;
        v5 = *arg2;
        exc.type = 4;
        exc.arg2 = v5;
        exc.retval = *retval;
        v4(&exc);
LABEL_56:
        v7 = exc.retval;
        goto LABEL_57;
      case pow_overflow:
        exc.type = 3;
        goto LABEL_16;
      default:
        return;
    }
LABEL_23:
    exc.arg1 = *arg1;
    exc.arg2 = *arg2;
    v6 = *retval;
LABEL_54:
    exc.retval = v6;
    exc.type = 1;
    if ( !v4(&exc) )
      *_errno() = 33;
    goto LABEL_56;
  }
  if ( input_tag != pow_zero_to_zero )
  {
    switch ( input_tag )
    {
      case pow_zero_to_negative:
        exc.type = 2;
LABEL_16:
        exc.name = "pow";
        goto LABEL_17;
      case pow_neg_to_non_integer:
$LN36_2:
        exc.name = "pow";
        break;
      case pow_nan_to_zero:
        exc.name = "pow";
LABEL_37:
        *retval = *arg1;
        break;
      case acos_gt_one:
$LN30_2:
        exc.name = "acos";
        break;
      case asin_gt_one:
$LN8_30:
        exc.name = "asin";
        break;
      default:
        return;
    }
    goto LABEL_23;
  }
  v7 = 1.0;
LABEL_57:
  *retval = v7;
}
