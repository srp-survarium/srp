void __thiscall survarium::timelimit_rule_core::tick(
        survarium::timelimit_rule_core *this,
        const unsigned int __formal,
        unsigned int current_time_ms)
{
  survarium::timelimit_rule_core::logic_tick(this, (int)this, current_time_ms);
  this->m_current_time_in_ms = current_time_ms;
}
