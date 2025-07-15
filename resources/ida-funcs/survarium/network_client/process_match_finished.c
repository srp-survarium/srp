void __thiscall survarium::network_client::process_match_finished(survarium::network_client *this)
{
  this->close_current_match(this, 0);
}
