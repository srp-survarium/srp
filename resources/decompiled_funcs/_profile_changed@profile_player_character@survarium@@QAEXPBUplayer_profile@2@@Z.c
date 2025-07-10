// local variable allocation has failed, the output may be wrong!
void __usercall survarium::profile_player_character::profile_changed(
        survarium::profile_player_character *this@<edi>,
        survarium::player_profile *profile@<eax>,
        survarium::profile_player_character *a3@<ecx>)
{
  survarium::profile_player_character::query_profile_contents(a3, *(__int64 *)&this, profile);
}
