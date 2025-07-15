void __thiscall vostok::animation::fingers_to_weapon_corrector::hand::hand(
        vostok::animation::fingers_to_weapon_corrector::hand *this)
{
  this->start_transition_time_in_ms = 0;
  this->locator_set_id = idle_locator_set;
  this->previous_locator_set_id = fingers_locator_set_id_count;
  this->is_active = 1;
}
