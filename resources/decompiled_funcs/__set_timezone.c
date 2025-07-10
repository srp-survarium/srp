void __cdecl _set_timezone(int _Value)
{
  *__timezone() = _Value;
}
