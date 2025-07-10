void __thiscall survarium::usable_object_user_data::usable_object_user_data(survarium::usable_object_user_data *this)
{
  this->owner = 0;
  this->current_object = 0;
  this->start_using_time_ms = 0;
  this->current_time_ms = 0;
  this->current_progress = -1;
  LODWORD(this->booster_artcont_time_factor) = clear_value;
  LODWORD(this->booster_engineer_use_time_factor) = clear_value;
  this->next = 0;
}
