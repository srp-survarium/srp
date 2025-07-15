void __thiscall vostok::resources::managed_resource::on_managed_node_resized(
        vostok::resources::managed_resource *this,
        unsigned int new_size)
{
  this[-1].m_current_quality_level = new_size;
}
