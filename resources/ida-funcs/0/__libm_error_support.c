void __cdecl __libm_error_support(double *arg1, double *arg2, double *retval, int input_tag)
{
  int (__cdecl *v4)(int *); // eax
  double v5; // st7
  double v6; // st7
  double v7; // st7
  int v8; // [esp+Ch] [ebp-28h] BYREF
  const char *v9; // [esp+10h] [ebp-24h]
  double v10; // [esp+14h] [ebp-20h]
  double v11; // [esp+1Ch] [ebp-18h]
  double v12; // [esp+24h] [ebp-10h]
  double v13; // [esp+2Ch] [ebp-8h]

  v13 = 0.0;
  if ( pmatherr_set )
    v4 = (int (__cdecl *)(int *))_decode_pointer(_pmatherr);
  else
    v4 = (int (__cdecl *)(int *))__init_collate;
  if ( input_tag > 166 )
  {
    switch ( input_tag )
    {
      case 1000:
        v9 = "log";
        goto LABEL_37;
      case 1001:
        v9 = "log10";
        goto LABEL_37;
      case 1002:
        v9 = "exp";
        goto LABEL_37;
      case 1003:
        v9 = "atan";
        goto LABEL_37;
      case 1004:
        v9 = "ceil";
        goto LABEL_37;
      case 1005:
        v9 = "floor";
        goto LABEL_37;
      case 1006:
        goto $LN36_6;
      case 1007:
        v9 = "modf";
        goto LABEL_37;
      case 1008:
        goto $LN30_6;
      case 1009:
        goto $LN8_36;
      case 1010:
        v9 = "sin";
        goto LABEL_53;
      case 1011:
        v9 = "cos";
        goto LABEL_53;
      case 1012:
        v9 = "tan";
LABEL_53:
        v6 = *arg1 * v13;
        *retval = v6;
        v10 = *arg1;
        v11 = *arg2;
        goto LABEL_54;
      default:
        return;
    }
  }
  if ( input_tag == 166 )
  {
    v8 = 3;
    v9 = "exp10";
    goto LABEL_17;
  }
  if ( input_tag <= 25 )
  {
    switch ( input_tag )
    {
      case 25:
        v9 = "pow";
        goto LABEL_20;
      case 2:
        v8 = 2;
        v9 = "log";
        goto LABEL_17;
      case 3:
        v9 = "log";
        break;
      case 8:
        v8 = 2;
        v9 = "log10";
        goto LABEL_17;
      case 9:
        v9 = "log10";
        break;
      case 14:
        v8 = 3;
        v9 = "exp";
LABEL_17:
        v10 = *arg1;
        v11 = *arg2;
        v12 = *retval;
        if ( !v4(&v8) )
          *_errno() = 34;
        goto LABEL_56;
      case 15:
        v9 = "exp";
LABEL_20:
        v10 = *arg1;
        v5 = *arg2;
        v8 = 4;
        v11 = v5;
        v12 = *retval;
        v4(&v8);
LABEL_56:
        v7 = v12;
        goto LABEL_57;
      case 24:
        v8 = 3;
        goto LABEL_16;
      default:
        return;
    }
LABEL_23:
    v10 = *arg1;
    v11 = *arg2;
    v6 = *retval;
LABEL_54:
    v12 = v6;
    v8 = 1;
    if ( !v4(&v8) )
      *_errno() = 33;
    goto LABEL_56;
  }
  if ( input_tag != 26 )
  {
    switch ( input_tag )
    {
      case 27:
        v8 = 2;
LABEL_16:
        v9 = "pow";
        goto LABEL_17;
      case 28:
$LN36_6:
        v9 = "pow";
        break;
      case 29:
        v9 = "pow";
LABEL_37:
        *retval = *arg1;
        break;
      case 58:
$LN30_6:
        v9 = "acos";
        break;
      case 61:
$LN8_36:
        v9 = "asin";
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
