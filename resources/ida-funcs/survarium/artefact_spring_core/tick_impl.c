void __thiscall survarium::artefact_spring_core::tick_impl(
        survarium::artefact_spring_core *this,
        unsigned int time_delta_ms,
        const unsigned int current_time_ms)
{
  this->m_time_left_to_deactivate = this->m_time_left_to_deactivate
                                  - (this->m_time_left_to_deactivate < time_delta_ms
                                   ? this->m_time_left_to_deactivate - time_delta_ms
                                   : 0)
                                  - time_delta_ms;
}
