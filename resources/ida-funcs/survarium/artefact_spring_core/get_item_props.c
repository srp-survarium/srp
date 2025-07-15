void __thiscall survarium::artefact_spring_core::get_item_props(
        survarium::artefact_spring_core *this,
        survarium::inventory_item_props *props)
{
  survarium::artefact_base::get_item_props(this, props);
  props->timer = (unsigned __int64)ceil((double)this->m_time_left_to_deactivate * 0.001);
}
