void __fastcall __security_check_cookie(unsigned int cookie)
{
  if ( cookie != __security_cookie )
    __report_gsfailure();
}
