void __userpurge vostok::resources::game_resources_manager::add_new_resource_to_increase_quality_tree(
        vostok::resources::quality_increase_functionality *resource@<edi>,
        vostok::resources::resource_base this)
{
  double v2; // st7

  v2 = *(float *)&resource[28].m_data;
  resource[32].m_data = resource[31].m_data;
  *(float *)&resource[29].m_data = v2;
  vostok::resources::quality_increase_functionality::quality_increase_functionality(
    (vostok::resources::quality_increase_functionality *)&this,
    (vostok::resources::game_resources_manager_data *)&this.__vftable[3].unlink_child_resource);
  vostok::resources::quality_increase_functionality::insert_to_increase_quality_tree(resource, &this);
}
