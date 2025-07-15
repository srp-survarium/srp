double __cdecl survarium::get_booster_value(
        survarium::boosters_enum booster_id,
        const survarium::player_profile *profile)
{
  unsigned __int8 i; // [esp+3h] [ebp-1h]

  for ( i = 0; i < 0xBu; ++i )
  {
    if ( profile->boosters[i].id == booster_id )
      return profile->boosters[i].value;
  }
  return 0.0;
}
