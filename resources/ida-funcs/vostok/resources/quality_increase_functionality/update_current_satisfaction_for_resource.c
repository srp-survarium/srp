void __usercall vostok::resources::quality_increase_functionality::update_current_satisfaction_for_resource(
        vostok::resources::quality_increase_functionality *this@<edi>,
        vostok::resources::resource_base *resource@<esi>,
        vostok::resources::quality_increase_functionality *a3@<ecx>,
        vostok::resources::compare_by_target_satisfaction *a4@<ebx>)
{
  char v4; // al
  unsigned int m_current_quality_level; // eax

  v4 = resource->m_flags.m_flags & 0x80;
  LOBYTE(a4) = v4 == (char)0x80;
  if ( resource->m_quality_levels_count != 1 && v4 == (char)0x80 )
    vostok::resources::quality_increase_functionality::erase_from_increase_quality_tree(
      a3,
      (vostok::resources::resource_base_vtbl **)this,
      a4,
      resource);
  vostok::resources::resource_quality::update_satisfaction(resource, this->m_data->current_increase_quality_tick);
  if ( resource->m_quality_levels_count != 1 )
  {
    m_current_quality_level = resource->m_current_quality_level;
    resource->m_target_satisfaction = resource->m_current_satisfaction;
    resource->m_target_quality_level = m_current_quality_level;
    if ( (_BYTE)a4 )
      vostok::resources::quality_increase_functionality::insert_to_increase_quality_tree(
        (vostok::resources::quality_increase_functionality *)resource,
        (vostok::resources::resource_base *)this);
  }
}
