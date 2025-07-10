survarium::bullet **__cdecl stlp_std::remove_if<survarium::bullet * *,survarium::redundant_bullet_predicate>(
        survarium::bullet **__first,
        survarium::bullet **__last,
        survarium::redundant_bullet_predicate __pred)
{
  survarium::redundant_bullet_predicate v4; // [esp+0h] [ebp-1Ch] BYREF
  survarium::bullet **v5; // [esp+4h] [ebp-18h]
  survarium::bullet **i; // [esp+8h] [ebp-14h]
  survarium::bullet **__next; // [esp+18h] [ebp-4h]
  survarium::bullet **__firsta; // [esp+24h] [ebp+8h]

  __firsta = stlp_std::find_if<survarium::bullet * *,survarium::redundant_bullet_predicate>(__first, __last, __pred);
  if ( __firsta == __last )
    return __firsta;
  __next = __firsta + 1;
  v4.bullet_manager = __pred.bullet_manager;
  v5 = __firsta;
  for ( i = __firsta + 1; i != __last; ++i )
  {
    if ( !survarium::redundant_bullet_predicate::operator()(&v4, *i) )
      *v5++ = *i;
  }
  return v5;
}
