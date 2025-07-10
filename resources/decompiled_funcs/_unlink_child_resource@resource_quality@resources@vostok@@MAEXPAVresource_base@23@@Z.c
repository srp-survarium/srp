void __thiscall vostok::resources::resource_quality::unlink_child_resource(
        vostok::resources::resource_quality *this,
        vostok::resources::resource_base *child)
{
  vostok::resources::resource_quality *v3; // ecx

  vostok::resources::resource_children::unlink_child_resource(this, child);
  this->m_current_quality_level = vostok::resources::resource_quality::calculate_max_child_quality_level(
                                    v3,
                                    (vostok::threading::simple_lock *)this);
}
