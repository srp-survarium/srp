const survarium::ai_sound_player::sounds_collection_type *__fastcall survarium::ai_sound_player::find(
        survarium::ai_sound_player *this,
        vostok::ai::sound_collection_types sound_type)
{
  const survarium::ai_sound_player::sounds_collection_type *result; // eax
  const survarium::ai_sound_player::sounds_collection_type *v3; // ecx

  result = (const survarium::ai_sound_player::sounds_collection_type *)&this[1];
  v3 = (const survarium::ai_sound_player::sounds_collection_type *)((char *)&this[1] + 16 * this->m_sounds_count);
  if ( result == v3 )
    return 0;
  while ( result->type != sound_type )
  {
    if ( ++result == v3 )
      return 0;
  }
  return result;
}
