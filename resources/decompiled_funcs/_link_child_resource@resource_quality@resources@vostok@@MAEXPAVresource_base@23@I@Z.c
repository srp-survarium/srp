void __thiscall vostok::resources::resource_quality::link_child_resource(
        vostok::resources::resource_quality *this,
        vostok::resources::resource_base *child,
        unsigned int quality)
{
  vostok::resources::resource_children::link_child_resource(this, child, quality);
  if ( quality != -1 )
    this->m_current_quality_level = quality
                                  + (this->m_current_quality_level < quality
                                   ? this->m_current_quality_level - quality
                                   : 0);
}
