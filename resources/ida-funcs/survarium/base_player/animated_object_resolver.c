survarium::base_player *__thiscall survarium::base_player::animated_object_resolver(
        survarium::base_player *this,
        const unsigned __int8 animated_object_id)
{
  survarium::base_player *result; // eax

  result = this;
  if ( animated_object_id )
    return (survarium::base_player *)this->m_current_active_object;
  return result;
}
